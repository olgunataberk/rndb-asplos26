---
layout: default
---

<!-- Navigation Bar -->
<nav class="nav-bar">
  <a href="#" class="nav-brand">Ramulator & DRAM Bender Tutorial @ ASPLOS26</a>
  <div class="nav-links">
    <a href="#about">About</a>
    <a href="#cfp">Call for Presentations</a>
    <a href="#agenda">Agenda</a>
    <a href="#speakers">Speakers</a>
    <a href="#livestream">Livestream</a>
    <a href="#organizers">Organizers</a>
    <a href="#venue">Venue</a>
  </div>
</nav>

<!-- Hero Section -->
<div class="hero-section">
  <div class="hero-date">MARCH 22<sup>nd</sup>, 2026</div>
  <h1 class="hero-title">Ramulator & DRAM Bender Tutorial</h1>
  <h2 class="hero-subtitle">Cutting-Edge Infrastructures for<br/>Real and Future Memory System Evaluation</h2>
  <p class="hero-conference">In conjunction with the ACM International Conference on Architectural Support for Programming Languages<br>and Operating Systems (ASPLOS 2026)</p>
  <p class="hero-location">Pittsburgh, USA</p>
  <div class="hero-buttons">
    <a href="https://www.asplos-conference.org/asplos2026/" class="btn btn-primary" target="_blank">Register Now</a>
  </div>
</div>

---

## About {#about}

DRAM is predominantly used to build the main memory systems of modern computing
devices. To improve performance, reliability, and security, it is critical to
conduct both system-level simulation studies and experimental characterization
of cutting-edge DRAM chips. Simulation enables understanding of the complex
interactions between DRAM, emerging memory technologies, and modern
applications, while real-chip characterization provides concrete insights into
DRAM performance, robustness, latency, and power under different conditions
(e.g., temperature and voltage).

This tutorial+workshop will introduce simulation-based DRAM research together
with experimental DRAM characterization using real DRAM chips. We will provide an extensive overview of: <a href="https://github.com/CMU-SAFARI/ramulator2">Ramulator</a>, a cycle-accurate and extensible main memory simulator,
and <a href="https://github.com/CMU-SAFARI/DRAM-Bender">DRAM Bender</a>, an FPGA-based DRAM testing infrastructure.

### Ramulator

<span class="emph-nobreak">Ramulator</span> is an extensible main memory simulator that provides <span class="emph-nobreak">cycle-level performance models for a variety of commercial DRAM standards</span> (e.g., DDR3/4, LPDDR3/4, GDDR5, HBM), <span class="emph-nobreak">emerging memory technologies</span>, and <span class="emph-nobreak">academic proposals</span>. Its modular design enables easy integration of additional standards, technologies, and mechanisms. Ramulator is written in C++ and can be easily integrated into both full-system simulators, such as <span class="emph-nobreak">gem5</span>, as well as other microarchitectural simulators, <span class="emph-nobreak">zsim</span>, and <span class="emph-nobreak">Virtuoso</span>.

<div class="papers-section">

<div class="paper-card">
  <div class="paper-icon">📄</div>
  <div class="paper-authors">Haocong Luo, Yahya Can Tugrul, F. Nisa Bostanci, Ataberk Olgun, A. Giray Yaglikci, and Onur Mutlu</div>
  <div class="paper-title">Ramulator 2.0: A Modern, Modular, and Extensible DRAM Simulator</div>
  <span class="paper-venue">IEEE CAL, 2024</span>
  <div class="paper-links">
    <a href="https://github.com/CMU-SAFARI/ramulator2" class="paper-link" target="_blank">🔗 GitHub</a>
    <a href="https://people.inf.ethz.ch/omutlu/pub/Ramulator2_arxiv23.pdf" class="paper-link" target="_blank">📖 Paper</a>
  </div>
</div>

<div class="paper-card">
  <div class="paper-icon">📄</div>
  <div class="paper-authors">Yoongu Kim, Weikun Yang, and Onur Mutlu</div>
  <div class="paper-title">Ramulator: A Fast and Extensible DRAM Simulator</div>
  <span class="paper-venue">IEEE CAL, 2015</span>
  <div class="paper-links">
    <a href="https://github.com/CMU-SAFARI/ramulator" class="paper-link" target="_blank">🔗 GitHub</a>
    <a href="https://users.ece.cmu.edu/~omutlu/pub/ramulator_dram_simulator-ieee-cal15.pdf" class="paper-link" target="_blank">📖 Paper</a>
  </div>
</div>

</div>

### DRAM Bender

<span class="emph-nobreak">DRAM Bender</span> (based on SoftMC), is <span class="emph-nobreak">an FPGA-based DRAM testing infrastructure</span>. DRAM Bender provides <span class="emph-nobreak">simple and intuitive high-level programming interfaces</span> in C++ and Python. A user of DRAM Bender writes DRAM test programs in a high-level language. DRAM Bender's programmer interface automatically translates these programs into low-level DRAM Bender instructions (e.g., DRAM commands, arithmetic, memory, control-flow instructions) on the FPGA. Thereby, DRAM Bender enables users with diverse technical backgrounds to <span class="emph-nobreak">rapidly characterize DRAM without requiring logic design expertise</span>.

<div class="papers-section">

<div class="paper-card">
  <div class="paper-icon">📄</div>
  <div class="paper-authors">Ataberk Olgun, Hasan Hassan, A. Giray Yaglikci, Yahya Can Tugrul, Lois Orosa, Haocong Luo, Minesh Patel, Oguz Ergin, Onur Mutlu</div>
  <div class="paper-title"> "DRAM Bender: An Extensible and Versatile FPGA-based Infrastructure to Easily Test State-of-the-art DRAM Chips"</div>
  <span class="paper-venue">IEEE TCAD, 2023</span>
  <div class="paper-links">
    <a href="https://github.com/CMU-SAFARI/DRAM-Bender" class="paper-link" target="_blank">🔗 GitHub</a>
    <a href="https://arxiv.org/pdf/2211.05838.pdf" class="paper-link" target="_blank">📖 Paper</a>
  </div>
</div>

<div class="paper-card">
  <div class="paper-icon">📄</div>
  <div class="paper-authors">Hasan Hassan, Nandita Vijaykumar, Samira Khan, Saugata Ghose, Kevin Chang, Gennady Pekhimenko, Donghyuk Lee, Oguz Ergin, and Onur Mutlu</div>
  <div class="paper-title">SoftMC: A Flexible and Practical Open-Source Infrastructure for Enabling Experimental DRAM Studies</div>
  <span class="paper-venue">HPCA, 2017</span>
  <div class="paper-links">
    <a href="https://github.com/CMU-SAFARI/SoftMC" class="paper-link" target="_blank">🔗 GitHub</a>
    <a href="https://people.inf.ethz.ch/omutlu/pub/softMC_hpca17.pdf" class="paper-link" target="_blank">📖 Paper</a>
  </div>
</div>

</div>

---

## Call for Presentations {#cfp}
This workshop includes invited talks on DRAM characterization and memory system simulation using Ramulator and DRAM Bender. A limited number of slots are available for invited presentations.
If you are interested in delivering a talk on related topics please submit a brief proposal with an extended abstract of your work (along with a brief bio) by filling out <a href="https://forms.gle/nzEKRA32B3UM2z4T8">this form</a>. We invite abstract submissions related to (but not limited to) the following topics:

<ul>
<li>New features, extensions, or enhancements to Ramulator</li>
<li>Use of Ramulator for evaluating memory performance, emerging memory technologies, or architectural mechanisms</li>
<li>DRAM characterization studies conducted using DRAM Bender</li>
<li>Reliability, failure analysis, or security studies using DRAM Bender</li>
<li>Cross-layer research that combines memory system simulation (Ramulator) with real-chip DRAM characterization (DRAM Bender)</li>
<li>Benchmarks, workloads, or methodologies for DRAM studies using Ramulator or DRAM Bender</li>
<li>Open-source tools, software extensions, datasets, or reusable components built on top of Ramulator or DRAM Bender</li>
<li>Case studies demonstrating how Ramulator or DRAM Bender enabled new research insights or the validation of ideas</li>
</ul>

We especially encourage early-stage research, work-in-progress results, experimental methodologies, and community contributions that will benefit researchers working with Ramulator or DRAM Bender.

---

## Tentative Agenda {#agenda}

<div class="schedule-section">

  <div class="session-block">
    <div class="session-header">Afternoon Session &nbsp;·&nbsp; 13:30–15:30</div>
    <table class="schedule-table">
      <thead>
        <tr>
          <th>Time</th>
          <th>Duration</th>
          <th>Speaker</th>
          <th>Title</th>
          <th>Slides</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td class="time-cell">13:30</td>
          <td class="duration-cell">20 min + Q&amp;A</td>
          <td class="speaker-cell">Onur Mutlu / Ataberk Olgun</td>
          <td>Introduction to DRAM Bender and FPGA-Based Infrastructures for Memory Systems Research</td>
          <td><a href="slides/onur-R&DB-Tutorial-ToolsForEvaluatingMemory-22-March-2026.pptx" download="onur-R&DB-Tutorial-ToolsForEvaluatingMemory-22-March-2026.pptx">Download</a></td>
        </tr>
        <tr>
          <td class="time-cell">14:00</td>
          <td class="duration-cell">20 min + Q&amp;A</td>
          <td class="speaker-cell">Ataberk Olgun</td>
          <td>DRAM-Bender-Enabled Research Highlights</td>
          <td><a href="slides/asplos26_rndb_workshop_ataberk.pptx" download="asplos26_rndb_workshop_ataberk.pptx">Download</a></td>
        </tr>
        <tr>
          <td class="time-cell">14:30</td>
          <td class="duration-cell">10 min + Q&amp;A</td>
          <td class="speaker-cell">Ataberk Olgun</td>
          <td>DRAM Bender Hardware &amp; Software Overview</td>
          <td><a href="slides/asplos26_rndb_workshop_ataberk.pptx" download="asplos26_rndb_workshop_ataberk.pptx">Download</a></td>
        </tr>
        <tr>
          <td class="time-cell">14:40</td>
          <td class="duration-cell">15 min + Q&amp;A</td>
          <td class="speaker-cell">Ataberk Olgun</td>
          <td>DRAM Bender Example Use Demo</td>
          <td><a href="slides/asplos26_rndb_workshop_ataberk.pptx" download="asplos26_rndb_workshop_ataberk.pptx">Download</a>
          || <a href="slides/demo.cpp" download="demo.cpp">Demo Code</a>
          </td>
        </tr>
        <tr>
          <td class="time-cell">15:00</td>
          <td class="duration-cell">25 min + Q&amp;A</td>
          <td class="speaker-cell">Ranyang Zhou</td>
          <td><em>Attacking DNN Intelligence via Memory-Based Fault Injection</em></td>
          <td><a href="slides/DNN_Workshop_Final2.pptx" download="DNN_Workshop_Final2.pptx">Download</a></td>
        </tr>
      </tbody>
    </table>
  </div>

  <div class="schedule-break">☕&nbsp;&nbsp;Coffee Break &nbsp;·&nbsp; 15:30–16:00</div>

  <div class="session-block">
    <div class="session-header">Afternoon Session Continued &nbsp;·&nbsp; 16:00–18:00</div>
    <table class="schedule-table">
      <thead>
        <tr>
          <th>Time</th>
          <th>Duration</th>
          <th>Speaker</th>
          <th>Title</th>
          <th>Slides</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td class="time-cell">16:00</td>
          <td class="duration-cell">20 min + Q&amp;A</td>
          <td class="speaker-cell">F. Nisa Bostanci</td>
          <td>Introduction to Ramulator and Memory System Simulation</td>
          <td><a href="slides/Ramulator-intro.pptx" download="Ramulator-intro.pptx">Download</a></td>
        </tr>
        <tr>
          <td class="time-cell">16:30</td>
          <td class="duration-cell">20 min + Q&amp;A</td>
          <td class="speaker-cell">F. Nisa Bostanci</td>
          <td>Ramulator-Enabled Research Highlights</td>
          <td><a href="slides/Ramulator-Researchhighlights.pptx" download="Ramulator-Researchhighlights.pptx">Download</a></td>
        </tr>
        <tr>
          <td class="time-cell">17:00</td>
          <td class="duration-cell">25 min + Q&amp;A</td>
          <td class="speaker-cell">Hwayong Nam</td>
          <td><em>Our Experience with Ramulator and DRAM-Bender: Case Studies from DRAMScope and RoMe</em></td>
          <td>-</td>
        </tr>
        <tr>
          <td class="time-cell">17:30</td>
          <td class="duration-cell">&lt;10 min</td>
          <td class="speaker-cell">Onur Mutlu / Ataberk Olgun</td>
          <td>Closing Remarks</td>
          <td>-</td>
        </tr>
      </tbody>
    </table>
  </div>

</div>

### Invited Speakers {#speakers}

<div class="speakers-section">

  <div class="speaker-card">
    <div class="speaker-header">
      <div class="speaker-meta">
        <div class="speaker-name">Ranyang Zhou</div>
        <div class="speaker-affiliation">Ph.D. Candidate &nbsp;&middot;&nbsp; New Jersey Institute of Technology (NJIT)</div>
        <div class="speaker-advisor">Advised by Prof. Shaahin Angizi</div>
      </div>
    </div>
    <div class="speaker-talk-title">Attacking DNN Intelligence via Memory-Based Fault Injection</div>
    <div class="speaker-abstract-label">Abstract</div>
    <p class="speaker-abstract">This talk presents recent research on DRAM fault injection and its implications for deep neural network (DNN) reliability and security. Using experimental DRAM characterization frameworks such as DRAM Bender, we analyze disturbance-based attacks including RowHammer and RowPress and their ability to induce targeted bit flips in memory. We further demonstrate how such faults can be exploited to manipulate DNN behavior, highlighting new security challenges at the intersection of memory systems and machine learning workloads.</p>
    <div class="speaker-bio-label">Bio</div>
    <p class="speaker-bio">Ranyang Zhou is a Ph.D. candidate in Electrical and Computer Engineering at the New Jersey Institute of Technology (NJIT), working with Prof. Shaahin Angizi. His research focuses on processing-in-memory (PIM) and DRAM-based attack and defense mechanisms for machine learning systems. His work has appeared in leading venues including CVPR, DAC, ICCAD, DATE, ISLPED, and IEEE CAL. His recent research investigates DRAM fault injection attacks, including RowHammer and RowPress, and their implications for the reliability and security of AI systems, aiming to enable robust and secure next-generation computing platforms.</p>
  </div>

  <div class="speaker-card">
    <div class="speaker-header">
      <div class="speaker-meta">
        <div class="speaker-name">Hwayong Nam</div>
        <div class="speaker-affiliation">Ph.D. Candidate &nbsp;&middot;&nbsp; Seoul National University</div>
        <div class="speaker-advisor">Advised by Prof. Jung Ho Ahn</div>
      </div>
    </div>
    <div class="speaker-talk-title">Our Experience with Ramulator and DRAM-Bender: Case Studies from DRAMScope and RoMe</div>
    <div class="speaker-abstract-label">Abstract</div>
    <p class="speaker-abstract">This talk presents SCALE Lab's experience using two widely adopted research infrastructures for memory systems research: DRAM-Bender and Ramulator. It focuses on two representative case studies from our recent work. First, it covers DRAMScope, which uses DRAM-Bender and SoftMC to uncover DRAM microarchitectural behaviors and characteristics that are not visible from public specifications alone. Second, it covers RoMe, which uses Ramulator to explore a memory system with row-granularity access for large language model inference and to evaluate its system-level benefits. Through these two case studies, the talk highlights what kinds of research each infrastructure enables, what kinds of ideas each can evaluate effectively, and how both have been impactful in memory systems research.</p>
    <div class="speaker-bio-label">Bio</div>
    <p class="speaker-bio">Hwayong Nam is a Ph.D. candidate at Seoul National University, advised by Prof. Jung Ho Ahn. His research interests include memory systems, DRAM microarchitecture, memory reliability and security, and LLMs.</p>
  </div>

</div>

---

## Livestream {#livestream}

<div class="livestream-section">
  <h3>🔴 Can't attend in person? Join us live!</h3>
  <p>The tutorial will be livestreamed on YouTube. A replay will also be available afterwards.</p>
  
  <div class="youtube-embed">
    <iframe src="https://www.youtube.com/embed/6uAfgKs1JKI" title="Ramulator & DRAM Bender Tutorial Livestream" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  </div>
  
  <a href="https://www.youtube.com/live/6uAfgKs1JKI" class="livestream-link" target="_blank">▶️ Watch on YouTube</a>
</div>

---

## Organizers {#organizers}

<div class="organizers-section">

<div class="organizer-item">
  <div class="organizer-photo">
    <img src="https://safari.ethz.ch/wp-content/uploads/nisa-linkedIN.jpeg" alt="F. Nisa Bostanci">
  </div>
  <div class="organizer-info">
    <h4><a href="https://nisabostanci.github.io/" target="_blank">F. Nisa Bostanci</a></h4>
    <div class="organizer-affiliation">ETH Zürich</div>
    <p class="organizer-bio">F. Nisa Bostanci is a 4th-year PhD student in the SAFARI Research Group at ETH Zurich, under the supervision of Prof. Onur Mutlu. She is broadly interested in computer architecture and, more specifically, in security, reliability, and safety (robustness) of memory systems, emerging memory and computation paradigms, including Processing-In-Memory architectures (PIM), and designing effective and efficient solutions to address robustness issues in modern and future systems. Her recent works uncover and mitigate new security vulnerabilities that emerge with the adoption of read disturbance solutions and PIM architectures to aid in designing robust future systems.
</p>
    <div class="organizer-email">📧 <a href="mailto:nisa.bostanci@safari.ethz.ch">nisa.bostanci@safari.ethz.ch</a></div>
  </div>
</div>

<div class="organizer-item">
  <div class="organizer-photo">
    <img src="https://kratos4.ethz.ch/wp-content/uploads/ataberj.png" alt="Ataberk Olgun">
  </div>
  <div class="organizer-info">
    <h4><a href="https://ataberkolgun.com/" target="_blank">Ataberk Olgun</a></h4>
    <div class="organizer-affiliation">ETH Zürich</div>
    <p class="organizer-bio">Ataberk Olgun is a senior PhD student at ETH Zurich, working with Prof. Onur Mutlu. His broad research interests include designing secure, high-performance, and energy-efficient DRAM architectures. Especially with the worsening RowHammer vulnerability, it is increasingly difficult to design new DRAM architectures that satisfy all three characteristics. His current research focuses on i) deeply understanding and ii) efficiently mitigating the RowHammer vulnerability in modern systems. </p>
    <div class="organizer-email">📧 <a href="mailto:ataberk.olgun@safari.ethz.ch">ataberk.olgun@safari.ethz.ch</a></div>
  </div>
</div>

<div class="organizer-item">
  <div class="organizer-photo">
    <img src="https://safari.ethz.ch/wp-content/uploads/2020/06/Haocong_crop.jpg" alt="Haocong Luo">
  </div>
  <div class="organizer-info">
    <h4><a href="#" target="_blank">Haocong Luo</a></h4>
    <div class="organizer-affiliation">ETH Zürich</div>
    <p class="organizer-bio">Haocong Luo is a PhD student in the SAFARI Research Group at ETH Zurich under the supervision of Prof.Onur Mutlu. His current broader research interests are 1) understanding and improving the performance and reliability of DRAM-based memory systems, 2) accelerating BVH traversals to enable high-performance path-traced rendering algorithms, and 3) designing efficient memory architectures and systems for Large Language Models. </p>
    <div class="organizer-email">📧 <a href="mailto:haocong.luo@safari.ethz.ch">haocong.luo@safari.ethz.ch</a></div>
  </div>
</div>


<div class="organizer-item">
  <div class="organizer-photo">
    <img src="https://kratos4.ethz.ch/wp-content/uploads/photo_ismail.png" alt="Ismail Emir Yuksel">
  </div>
  <div class="organizer-info">
    <h4><a href="https://www.linkedin.com/in/ismail-emir-yuksel/" target="_blank">Ismail Emir Yuksel</a></h4>
    <div class="organizer-affiliation">ETH Zürich</div>
    <p class="organizer-bio">Ismail Emir Yuksel is a 2nd-year PhD student in the SAFARI Research Group at ETH Zurich under the supervision of Prof. Onur Mutlu. His current broader research interests are in computer architecture, processing-in-memory, and hardware security, focusing on understanding, enhancing, and exploiting fundamental computational capabilities of modern DRAM architectures. His recent publications show that commodity DRAM chips, without any modification to the chip itself (only with modifications to the memory controller), are able to execute bulk-bitwise computation and data movement operations (including NAND, NOR, NOT, AND, OR, MAJority, multi-row copy, and initialization functions) in a reasonably robust manner. </p>
    <div class="organizer-email">📧 <a href="mailto:ismail.yuksel@safari.ethz.ch">ismail.yuksel@safari.ethz.ch</a></div>
  </div>
</div>


<div class="organizer-item">
  <div class="organizer-photo">
    <img src="https://people.inf.ethz.ch/omutlu/img/OnurMutlu_eth.jpg" alt="Prof. Onur Mutlu">
  </div>
  <div class="organizer-info">
    <h4><a href="https://people.inf.ethz.ch/omutlu/" target="_blank">Professor Onur Mutlu</a></h4>
    <div class="organizer-affiliation">ETH Zürich</div>
    <p class="organizer-bio">Onur Mutlu is a Professor of Computer Science at ETH Zurich. He previously held the William D. and Nancy W. Strecker Early Career Professorship at Carnegie Mellon University. His research interests are in computer architecture, computing systems, hardware security, memory & storage systems, and bioinformatics, with a major focus on designing fundamentally energy-efficient, high-performance, and robust computing systems. He started the Computer Architecture Group at Microsoft Research (2006-2009), and held product, research and visiting positions at Intel Corporation, Advanced Micro Devices, VMware, Google, and Stanford University. He received various honors for his research, including the 2025 IEEE Computer Society Harry H. Goode Memorial Award “for seminal contributions to computer architecture research and practice, especially in memory systems.” He is an ACM Fellow, IEEE Fellow, and an elected member of the Academy of Europe. He enjoys teaching, mentoring, and enabling & democratizing access to high-quality research and education. He has supervised 25 PhD graduates, many of whom received major dissertation awards, 18 postdoctoral trainees, and more than 70 Master’s and Bachelor’s students. His computer architecture and digital logic design course lectures and materials are freely available on YouTube and his research group makes a wide variety of artifacts freely available online. For more information, please see his webpage at https://people.inf.ethz.ch/omutlu/.  
</p>
    <div class="organizer-email">📧 <a href="mailto:onur.mutlu@safari.ethz.ch">onur.mutlu@safari.ethz.ch</a></div>
  </div>
</div>

</div>

## Event Location {#venue}

<div class="event-grid">
  <div class="event-info">
    <h3>Venue</h3>
    <p><strong>The Landing Hotel</strong></p>
    <p>757 Casino Dr. Pittsburgh<br>PA 15212<br>Pittsburgh<br>USA</p>
    <p>The tutorial will be held in conjunction with <a href="https://www.asplos-conference.org/asplos2026/" target="_blank">ASPLOS 2026</a>.</p>
    <p>For registration and accommodation information, please visit the <a href="https://www.asplos-conference.org/asplos2026/" target="_blank">ASPLOS 2026 website</a>.</p>
  </div>
  <div class="event-map">
<iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3036.2984707778737!2d-80.0236945236356!3d40.44653045382461!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x8834f56293b33075%3A0x815461caafb7b1fd!2sThe%20Landing%20Hotel%20Pittsburgh!5e0!3m2!1sen!2sch!4v1767631980292!5m2!1sen!2sch" width="600" height="450" style="border:0;" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>
  </div>
</div>

---

## Contact {#contact}

<div class="contact-section">
  <p>For questions about the tutorial, please contact the organizers:</p>
  <p><strong>General Inquiries:</strong> <a href="mailto:nisa.bostanci@safari.ethz.ch">nisa.bostanci@safari.ethz.ch</a> and <a href="mailto:ataberk.olgun@safari.ethz.ch">ataberk.olgun@safari.ethz.ch</a></p>
  <p><strong>SAFARI Research Group:</strong> <a href="https://safari.ethz.ch/" target="_blank">safari.ethz.ch</a></p>
</div>

---

<div class="footer-section">
  <p><b>Ramulator & DRAM Bender Tutorial@ASPLOS'26</b> | Cutting-Edge Infrastructures<br>for Real and Future Memory System Evaluation Tutorial</p>
  <p>In conjunction with <a href="https://www.asplos-conference.org/asplos2026/" target="_blank">ASPLOS 2026</a> | Pittsburgh, USA</p>
</div>
