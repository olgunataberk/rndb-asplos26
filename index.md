---
layout: default
---

<!-- Navigation Bar -->
<nav class="nav-bar">
  <a href="#" class="nav-brand">Ramulator & DRAM Bender Tutorial @ ASPLOS26</a>
  <div class="nav-links">
    <a href="#about">About</a>
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
  <h2 class="hero-subtitle">Cutting-Edge Infrastructures for Real and Future Memory System Evaluation</h2>
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

### DRAM Bender

<span class="emph-nobreak">DRAM Bender</span> (based on SoftMC), is <span class="emph-nobreak">an FPGA-based DRAM testing infrastructure</span>. DRAM Bender provides <span class="emph-nobreak">simple and intuitive high-level programming interfaces</span> in C++ and Python. A user of DRAM Bender writes DRAM test programs in a high-level language. DRAM Bender's programmer interface automatically translates these programs into low-level DRAM Bender instructions (e.g., DRAM commands, arithmetic, memory, control-flow instructions) on the FPGA. Thereby, DRAM Bender enables users with diverse technical backgrounds to <span class="emph-nobreak">rapidly characterize DRAM without requiring logic design expertise</span>.

---

## Agenda & Workshop Materials {#agenda}

<div class="agenda-placeholder">
  <p><strong>Program Schedule Coming Soon</strong></p>
  <p>The detailed agenda will be announced closer to the tutorial date.</p>
</div>

### Invited Speakers {#speakers}

<div class="speakers-placeholder">
  <p><strong>Speakers To Be Announced</strong></p>
</div>

---

## Livestream {#livestream}

<div class="livestream-section">
  <h3>🔴 Can't attend in person? Join us live!</h3>
  <p>The tutorial will be livestreamed on YouTube. A replay will also be available afterwards.</p>
  
  <div class="youtube-embed">
    <iframe src="https://www.youtube.com/embed" title="Ramulator & DRAM Bender Tutorial Livestream" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  </div>
  
  <a href="https://youtube.com/live" class="livestream-link" target="_blank">▶️ Watch on YouTube</a>
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
