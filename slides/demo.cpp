#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

#include "instruction.h"
#include "platform.h"
#include "prog.h"

using namespace std;
namespace po = boost::program_options;

#define all_nops() SMC_NOP(), SMC_NOP(), SMC_NOP(), SMC_NOP()

class DataPattern
{
private:
  uint8_t m_byte;

public:
  DataPattern(const uint8_t byte) : m_byte(byte) {}
  DataPattern(const DataPattern& dp) : m_byte(dp.m_byte) {}

  uint8_t get_byte() const { 
    return m_byte; 
  }

  uint16_t get_sword() const {
    return (m_byte << 8) | m_byte;
  }

  uint32_t get_word() const {
    return (m_byte << 24) | (m_byte << 16) | (m_byte << 8) | m_byte;
  }

  uint64_t get_dword() const {
    uint64_t word_value = get_word();
    return ((word_value << 32) | word_value);
  }

  void invert() {
    m_byte = ~m_byte;
  }

};

const int NUM_COLS = 128;
const int NUM_BYTES_PER_READ = 64;
const int ROW_SIZE_IN_BYTES = NUM_COLS * NUM_BYTES_PER_READ; 
const uint64_t DDR_PERIOD_PS = 1500;

unsigned int (*map_row) (unsigned int row);

unsigned int map_row_linear (unsigned int row) {
  return row;
}

unsigned int map_row_sams (unsigned int row) {
  if(row & 0x8) 
  {
    uint p_row = row & 0xFFFFFFF9;
    p_row |= (~row & 0x00000006); // set bit pos 3 and 2
    return p_row;
  } 
  else
    return row;
}

unsigned int map_row_mi0 (unsigned int row) {
  if (row & 0x8)
  {
    uint mask = 0x6;
    return row ^ mask;
  }
  else
    return row;
}

unsigned int map_row_mi2 (unsigned int row) {
  int bit3 = (row & 8) >> 3;
  int bit10 = (row & 1024) >> 10;
  int bit12 = (row & 4096) >> 12;
  int bit14 = (row & 16384) >> 14;
  if (bit3 ^ bit10 ^ bit12 ^ bit14) {
      uint mask = 0x6;
      return row ^ mask;
  } else
    return row;
}

void test_hcn (const int bank, 
    const vector<int> init_rows, 
    const DataPattern init_dp,
    const int aggr1_row, const int victim_row, const int aggr2_row, 
    const DataPattern aggr_dp, const DataPattern vict_dp, const int hc, 
    const int taggon_ns,
    SoftMCPlatform& platform)
{
    const int CASR = 0;
    const int BASR = 1;
    const int RASR = 2;

    const int CAR = 3;
    const int BAR = 4;
    const int RAR_V = 5;
    const int RAR_A1 = 6;
    const int RAR_A2 = 7;

    const int AGGR_PATTERN_REG = 9;
    const int VICTIM_PATTERN_REG = 10;

    const int HAMMER_COUNT_REG = 11;
    const int HAMMER_COUNT_LIMIT_REG = 12;

    const int RAR = 5;
    const int PATTERN_REG = 6;

    const int COLUMN_ITER_REG = 7;
    const int COLUMN_ITER_LIM_REG = 8;

    Program program;
    // load wdata reg with the data pattern
    program.add_inst(SMC_LI(init_dp.get_word(), PATTERN_REG));
    for(int i = 0 ; i < 16 ; i++)
        program.add_inst(SMC_LDWD(PATTERN_REG,i));

    // set stride register values
    program.add_inst(SMC_LI(8, CASR));
    program.add_inst(SMC_LI(0, BASR)); 
    program.add_inst(SMC_LI(1, RASR)); 

    program.add_inst(SMC_LI(0, CAR)); // Initialize CAR with 0
    program.add_inst(SMC_LI(bank, BAR)); // Initialize BAR (bank address register) with 0

    program.add_inst(SMC_LI(NUM_COLS, COLUMN_ITER_LIM_REG));

    for (int r = 0 ; r < init_rows.size() ; r++)
    {
        program.add_inst(SMC_LI(0, COLUMN_ITER_REG));
        program.add_inst(SMC_LI(init_rows[r], RAR)); // Initialize RAR with 0

        // PREcharge bank BAR and wait for tRP (11 NOPs, 11 SoftMC cycles) 
        program.add_inst(
        SMC_PRE(BAR, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );

        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(all_nops());

        // ACT & wait for tRCD
        program.add_inst(
        SMC_ACT(BAR, 0, RAR, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );
        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(all_nops());

        program.add_label("LOOP" + to_string(init_rows[r]));
        for (int i = 0 ; i < 8 ; i++)
        {
            program.add_inst(
            SMC_WRITE(BAR, 0, CAR, 1, 0, 0),
            SMC_NOP(), SMC_NOP(), SMC_NOP()
            );
            program.add_inst(SMC_ADDI(COLUMN_ITER_REG, 1, COLUMN_ITER_REG));
        }
        program.add_branch(program.BR_TYPE::BL, COLUMN_ITER_REG, COLUMN_ITER_LIM_REG, "LOOP" + to_string(init_rows[r]));

        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(
        SMC_PRE(BAR, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );

    }
    // ============================================================================
    // ===========================      INIT END   ================================
    // ============================================================================

    // set stride register values
    program.add_inst(SMC_LI(8, CASR));
    program.add_inst(SMC_LI(0, BASR)); 
    program.add_inst(SMC_LI(1, RASR)); 

    program.add_inst(SMC_LI(hc, HAMMER_COUNT_LIMIT_REG)); 
    program.add_inst(SMC_LI(0, HAMMER_COUNT_REG)); 

    program.add_inst(SMC_LI(0, CAR)); // Initialize CAR with 0
    program.add_inst(SMC_LI(bank, BAR)); // Initialize BAR (bank address register) with bank
    program.add_inst(SMC_LI(victim_row, RAR_V)); 
    program.add_inst(SMC_LI(aggr1_row, RAR_A1)); 
    program.add_inst(SMC_LI(aggr2_row, RAR_A2)); 

    // initialize the aggressor row

    // load wdata reg with the data pattern
    program.add_inst(SMC_LI(aggr_dp.get_word(), AGGR_PATTERN_REG));
    for(int i = 0 ; i < 16 ; i++)
        program.add_inst(SMC_LDWD(AGGR_PATTERN_REG,i));

    // ============================================================================
    // ===========================      AGGR1      ================================
    // ============================================================================

    program.add_inst(SMC_LI(0, CAR)); // Initialize CAR with 0
    // PREcharge bank BAR and wait for tRP (11 NOPs, 11 SoftMC cycles) 
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    // ACT & wait for tRCD
    program.add_inst(
    SMC_ACT(BAR, 0, RAR_A1, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    for (int i = 0 ; i < NUM_COLS ; i++)
    {
        program.add_inst(
        SMC_WRITE(BAR, 0, CAR, 1, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );
        program.add_inst(all_nops());
    }

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    // ============================================================================
    // ===========================      AGGR2      ================================
    // ============================================================================

    program.add_inst(SMC_LI(0, CAR)); // Initialize CAR with 0
    // PREcharge bank BAR and wait for tRP (11 NOPs, 11 SoftMC cycles) 
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    // ACT & wait for tRCD
    program.add_inst(
    SMC_ACT(BAR, 0, RAR_A2, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    for (int i = 0 ; i < NUM_COLS ; i++)
    {
        program.add_inst(
        SMC_WRITE(BAR, 0, CAR, 1, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );
        program.add_inst(all_nops());
    }

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    // ============================================================================
    // ===========================      VICTIM     ================================
    // ============================================================================

    // load wdata reg with the data pattern
    program.add_inst(SMC_LI(vict_dp.get_word(), VICTIM_PATTERN_REG));
    for(int i = 0 ; i < 16 ; i++)
        program.add_inst(SMC_LDWD(VICTIM_PATTERN_REG,i));

    program.add_inst(SMC_LI(0, CAR)); // Initialize CAR with 0
    // PREcharge bank BAR and wait for tRP (11 NOPs, 11 SoftMC cycles) 
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    // ACT & wait for tRCD
    program.add_inst(
    SMC_ACT(BAR, 0, RAR_V, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    for (int i = 0 ; i < NUM_COLS ; i++)
    {
        program.add_inst(
        SMC_WRITE(BAR, 0, CAR, 1, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );
        program.add_inst(all_nops());
    }

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    // ============================================================================
    // ===========================      HAMMER     ================================
    // ============================================================================

    program.add_label("HAMMER");

    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    program.add_inst(
    SMC_ACT(BAR, 0, RAR_A1, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    if(taggon_ns > 35)
    {
        program.add_inst(SMC_SLEEP(int(taggon_ns/6)));
    }
    else
    {
        program.add_inst(all_nops()); // 1.666 * 4
        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(all_nops());
        program.add_inst(all_nops()); // 33.32 ns (by precharge)
    }

    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops()); // 1.666 * 4
    program.add_inst(all_nops()); 
    program.add_inst(SMC_ADDI(HAMMER_COUNT_REG, 1, HAMMER_COUNT_REG));
    program.add_inst(
    SMC_ACT(BAR, 0, RAR_A2, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    if(taggon_ns > 35)
    {
        program.add_inst(SMC_SLEEP(int((taggon_ns-30)/6)));
    }

    program.add_branch(program.BR_TYPE::BL, HAMMER_COUNT_REG, HAMMER_COUNT_LIMIT_REG, "HAMMER");

    // ============================================================================
    // ===========================   READ VICTIM   ================================
    // ============================================================================

    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    program.add_inst(
    SMC_ACT(BAR, 0, RAR_V, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    for (int i = 0 ; i < NUM_COLS ; i++)
    {
        program.add_inst(
        SMC_READ(BAR, 0, CAR, 1, 0, 0),
        SMC_NOP(), SMC_NOP(), SMC_NOP()
        );
        program.add_inst(all_nops());
    }

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(
    SMC_PRE(BAR, 0, 0),
    SMC_NOP(), SMC_NOP(), SMC_NOP()
    );

    program.add_inst(all_nops());
    program.add_inst(all_nops());
    program.add_inst(all_nops());

    program.add_inst(SMC_END());

    platform.execute(program);

}

// Initialize 8 rows surrounding victim, hammer victim and read victim to @param buf
void initialize_hammer_read (int bank, 
    int victim_row, DataPattern dp_aggr, DataPattern dp_victim, int hc, 
    uint64_t* buf, const int taggon_ns, const int max_rows,
    SoftMCPlatform& platform)
{
    // initialize the rows first
    int init_start = max(victim_row - 8, 0);
    int init_end = min(victim_row + 8, max_rows);

    vector<int> init_rows;
    for (int i = init_start ; i < init_end ; i++)
        init_rows.push_back(map_row(i));

    // hammer
    test_hcn(bank, init_rows, dp_victim, map_row(victim_row-1), 
        map_row(victim_row), map_row(victim_row+1), dp_aggr, 
        dp_victim, hc, taggon_ns, platform);

    platform.receiveData(buf, ROW_SIZE_IN_BYTES); // read one row each iteration
}

bool check_bitflip(uint64_t* buf, DataPattern dp_victim)
{
  int buf_index = 0;
  int column = 0;

  for (;buf_index < ROW_SIZE_IN_BYTES/sizeof(uint64_t);)
  {
    int dword = 0;
    bool bitflipped = false;
    for (int j = 0 ; j < NUM_BYTES_PER_READ/sizeof(uint64_t) ; j++, buf_index++)
    {
      uint64_t curr_word = buf[buf_index];
      if (curr_word ^ dp_victim.get_dword())
        return true;
    }
    column += 1;
  }
  return false;
}

vector<int> find_bitflip_positions(uint64_t* buf, DataPattern dp_victim)
{
  vector<int> indices;
  int buf_index = 0;
  int column = 0;

  for (;buf_index < ROW_SIZE_IN_BYTES/sizeof(uint64_t);)
  {
    int dword = 0;
    bool bitflipped = false;
    for (int j = 0 ; j < NUM_BYTES_PER_READ/sizeof(uint64_t) ; j++, buf_index++)
    {
      uint64_t curr_word = buf[buf_index];
      if (curr_word ^ dp_victim.get_dword())
      {
        for (int b = 0 ; b < 64 ; b++)
        {
          uint64_t mask = 1ULL << b;
          if ((curr_word & mask) != (dp_victim.get_dword() & mask))
          { 
            indices.push_back(column * 512 + dword * 64 + b);
          }
        }
      }
      dword++;
    }
    column += 1;
  }

  return indices;
}

int main(int argc, char *argv[])
{
    int bank, num_iterations;
    int taggon_ns;
    int max_rows;
    int temperature_celsius;
    int test_hammer_count;
    int test_victim_row;
    int dimm_slot;
    string data_pattern_hex;
    string map_string;
  
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "produce help message")
    ("bank,b", po::value<int>(&bank)->required(), "DRAM bank to test")
    ("datapattern,d", po::value<string>(&data_pattern_hex)->required(), 
          "Aggressor data pattern (byte) in hex format: e.g., 0x55")
    ("taggon", po::value<int>(&taggon_ns)->required(), 
            "Aggressor row on time in nanoseconds")
    ("victim_row", po::value<int>(&test_victim_row)->required(), 
            "Row id to use as victim")
    ("hammer_count", po::value<int>(&test_hammer_count)->required(), 
            "Number of hammers")
    ("temperature", po::value<int>(&temperature_celsius)->required(), 
            "Testing temperature in celsius")
    ("maxrows", po::value<int>(&max_rows)->required(), 
            "The total number of rows in this module")
    ("map", po::value<string>(&map_string)->default_value("linear"), 
            "Row mapping function: linear, sams, mi0, mi2")
    ("slot", po::value<int>(&dimm_slot)->default_value(0), 
            "Slot number to use for the test")
    ;

    // Parse the command line arguments
    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);

        // Handle required options explicitly
        if (vm.count("help"))
        {
            cout << desc << endl;
            return 1;
        }

        po::notify(vm);
    }
    catch (po::required_option &e)
    {
        cerr << "Error: " << e.what() << endl;
        cerr << desc << endl;
        return 1;
    }

    ofstream csv_file;

    csv_file.open("rdt_bank-" + to_string(bank) + "_dp-" + 
        data_pattern_hex + "_taggon-" + to_string(taggon_ns) + 
        "_victim_row-" + to_string(test_victim_row) + 
        "_hammer_count-" + to_string(test_hammer_count) + 
        "_temperature-" + to_string(temperature_celsius) + "_slot-" + 
        to_string(dimm_slot) + ".csv");

    SoftMCPlatform platform((int) dimm_slot);

    if(platform.init() != SOFTMC_SUCCESS){
      cerr << "Could not initialize SoftMC Platform" << endl;
      exit(0);
    }

    platform.reset_fpga();
        
    csv_file << "row,rdt,bit" << endl;

    cout << map_string << endl;

    // Set the row mapping function
    if (map_string == "Linear")
        map_row = map_row_linear;
    else if (map_string == "SA0")
        map_row = map_row_sams;
    else if (map_string == "MI0")
        map_row = map_row_mi0;
    else if (map_string == "MI1")
        map_row = map_row_mi2;
    else
    {
        cerr << "Error: Invalid row mapping function" << endl;
        return 1;
    }

    // convert data_pattern_hex into a byte
    uint8_t data_pattern_byte = static_cast<uint8_t>(stoi(data_pattern_hex, nullptr, 16));
    
    // Create a data pattern object
    DataPattern dp_aggr(data_pattern_byte);
    DataPattern dp_victim(~data_pattern_byte);

    uint64_t buf[ROW_SIZE_IN_BYTES/sizeof(uint64_t)];
    initialize_hammer_read(bank, test_victim_row , dp_aggr, dp_victim, test_hammer_count, buf, taggon_ns, max_rows, platform);
    if (check_bitflip(buf, dp_victim))
    {
        vector<int> bitflip_positions = find_bitflip_positions(buf, dp_victim);
        for (int i = 0 ; i < bitflip_positions.size() ; i++)
            csv_file << test_victim_row << "," << test_hammer_count << "," << bitflip_positions[i] << endl;
    }

    csv_file.flush();
    csv_file.close();

    return 0;
}
