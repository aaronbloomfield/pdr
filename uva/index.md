Program and Data Representation: CS 2150 Specific Content
=========================================================

## Spring 2020

[Go up to the main README file][111] ([md][112])

Much of the rest of this git repo is meant to be generic to anybody who has a class such as this one.  But this page contains details specific to the CS 2150 version of the course at the University of Virginia.

------------------------------------------------------------

Links
-----

There are a number of links and other parts of this course that are **NOT** included in this repository.  They are:

- The set of online tools, which can be accessed through Collab or [here][160].
    - These tools are: [support requests][161], [lab submission][162], [regrades][163], [gradebook][164], and the [office hours queue][166]
- The announcements, which are posted to the CS 2150 twitter feed: [\@UVaCS2150][151]
- Grading guidelines, which are available in the Collab wiki ([here][171] is the direct link, although Collab login is required)
- Email list archive, which is a Collab tool ([here][170] is the direct link, although Collab login is required)
- [Piazza][152], and our specific class is [here][175]; Collab can (maybe?) log you in directly; the Collab tool link is [here][173] (again, Collab login required)
- [Anonymous feedback][174]

The parts of this course that are in this repo are:

- [Daily announcements slide set][102]
- [Course introduction slide set][80]
- [Course syllabus][103] ([md][104]): the course syllabus
- [Teaching assistants][117]: get to know your TAs
- [Lab due dates][105] ([md][106]): When the various lab parts are due
- [UNIX honor pledge][172], which needs to be signed by all the students in the course (it is created from a [.tex][114] file)
- [Generic review session slide set][113], which is really just a blank set of slides
- [Frivolous regrade policy][109] ([md][110]) for exams
- The [final course grading metrics][116] ([md][115])

The [Documents page](../docs/index.html) ([md](../docs/index.md)) has a number of useful parts:

- [Useful compiler flags](../docs/compiler_flags.html) ([md](../docs/compiler_flags.md))
- [GDB command summary](../docs/gdb_summary.html) ([md](../docs/gdb_summary.md))
- [LLDB command summary](../docs/lldb_summary.html) ([md](../docs/lldb_summary.md))
- [GDB vs LLDB](../docs/gdb_vs_lldb.html) ([md](../docs/gdb_vs_lldb.md))
- [Compilation issues](../docs/compilation.html) ([md](../docs/compilation.md))
- [Readings](../docs/readings.html) ([md](../docs/readings.md)) in lieu of a textbook

------------------------------------------------------------

Labs and Tutorials
------------------

This is a series of links to the labs and tutorials that are elsewhere in this repository.  A bunch of notes:

- The lab parts are all due on specific times throughout the week, as detailed on the [lab due dates][105] ([md][106]) page
    - Each lab is for a given week, which (for sake of argument) we claim starts on a Monday
    - Which lab is done on which week is listed below in the semester schedule
- The lab is released the week before, typically on a Wednesday or Thursday
    - While a version of the lab will be in this github repo for some time prior, there **WILL** be modifications to that lab up until the "official" release, which is when it is announced as released on the twitter feed: [\@UVaCS2150][151]
- All the labs and tutorials can be found on the [labs page][107] ([md][108]) and the [tutorials page][100] ([md][101]).
    - In particular, these pages have additional details and links not described here


Semester Schedule
-----------------

------------------------------------------------------------

The links in the right-most column link directly to the lecture recording on Collab, and you have to be logged into Collab first before the link will work. Some plugins (such as NoScript) will block that link from working.


| Num | Date | Day of week | Lab & Tutorial (on Tue) | Planned topic | Lecture progress |
|-----|------|-------------|-------------------------|---------------|------------------|
| 1 | Jan 13 | Monday | no lab this week | [Course introduction][80] | course intro to slide 4.6 |
| 2 | Jan 15 | Wednesday | | [Course introduction][80], [01: C++][81] | finished course intro; C++ to slide 5.5 |
| 3 | Jan 17 | Friday | | [01: C++][81] | C++ to slide 7.9 |
| | Jan 20 | Monday | [Lab 1: Intro to C++][1] ([md][21]) / [Tutorial 1: Intro to UNIX][41] ([md][61]) | No class due to MLK day | No class due to MLK day |
| 4 | Jan 22 | Wednesday | | [01: C++][81] | C++ to slide 9.19 |
| 5 | Jan 24 | Friday | | [01: C++][81] | C++ to slide 10.17 |
| 6 | Jan 27 | Monday | [Lab 2: Linked lists][2] ([md][22]) / [Tutorial 2: LLDB][42] ([md][62]) *OR* [Tutorial 2: GDB][52] ([md][72]) (see [lab 2][2] for which one to pick) | [01: C++][81] | C++ to slide 12.10 |
| 7 | Jan 29 | Wednesday | | [01: C++][81], [02: Lists][82] | finished C++; lists to slide 4.6 |
| 8 | Jan 31 | Friday | | [02: Lists][82] | lists to slide 6.16 |
| 9 | Feb 3 | Monday | [Lab 3: Stacks][3] ([md][23]) / [Tutorial 3: More UNIX, part 1][63], introduction and sections 1-4 | [02: Lists][82], [03: Numbers][83] | |
| 10 | Feb 5 | Wednesday | | [03: Numbers][83] | |
| 11 | Feb 7 | Friday | | [03: Numbers][83] | |
| 12 | Feb 10 | Monday | [Lab 4: Numbers][4] ([md][24]) / [Tutorial 4: More UNIX, part 2][64], sections 5-8 | [03: Numbers][83] | |
| 13 | Feb 12 | Wednesday | | [04: Arrays &amp; big-Oh][84] | |
| 14 | Feb 14 | Friday | | [04: Arrays &amp; big-Oh][84] | |
| | Feb 16 | Sunday | | Exam 1 review session | |
| 15 | Feb 17 | Monday | Exam 1 instead during Tuesday's lab | [04: Arrays &amp; big-Oh][84], [05: Trees][85] | |
| 16 | Feb 19 | Wednesday | | [05: Trees][85] | |
| 17 | Feb 21 | Friday | | [05: Trees][85] | |
| 18 | Feb 24 | Monday | [Lab 5: Trees][5] ([md][25]) / [Tutorial 5: make][45] ([md][65]) | [05: Trees][85] | |
| 19 | Feb 26 | Wednesday | | [05: Trees][85] | |
| 20 | Feb 28 | Friday | | [05: Trees][85], [06: Hashes][86] | |
| 21 | Mar 2 | Monday | [Lab 6: Hashes][6] ([md][26]) / Tutorial 6: Shell scripting, part 1 (part of [this link][46]; the specific sections are mentioned on the [tutorials page][40]) | [06: Hashes][86] | |
| 22 | Mar 4 | Wednesday | | [06: Hashes][86] | |
| 23 | Mar 6 | Friday | | [06: Hashes][86] | |
| | Mar 9 | Monday | no lab this week due to spring break | No class due to spring break | No class due to spring break |
| | Mar 11 | Wednesday | | No class due to spring break | No class due to spring break |
| | Mar 13 | Friday | | No class due to spring break | No class due to spring break |
| 24 | Mar 16 | Monday | [Lab 7: IBCM][7] ([md][27]) / Tutorial 7: Shell scripting, part 2 (remainder of [here][47], as described on the [tutorials page][40]) | [07: IBCM][87] (machine language) | |
| 25 | Mar 18 | Wednesday | | [07: IBCM][87] (machine language) | |
| 26 | Mar 20 | Friday | | [07: IBCM][87] (machine language), [08: Assembly][88] | |
| 27 | Mar 23 | Monday | [Lab 8: assembly, part 1][8] ([md][28]) / Tutorial 8: see the information on the [tutorials page](../tutorials/index.html) ([md](../tutorials.md)) | [08: Assembly][88] | |
| 28 | Mar 25 | Wednesday | | [08: Assembly][88] | |
| 29 | Mar 27 | Friday | | [08: Assembly][88] | |
| | Mar 29 | Sunday | | Exam 2 review session | |
| 30 | Mar 30 | Monday | Exam 2 instead during Tuesday's lab | [08: Assembly][88], [09: Advanced C++][89] | |
| 31 | Apr 1 | Wednesday | | [09: Advanced C++][89] | |
| 32 | Apr 3 | Friday | | [09: Advanced C++][89], [10: Heaps and Huffman coding][90] | |
| 33 | Apr 6 | Monday | [Lab 9: assembly, part 2][9] ([md][29]) / [Tutorial 9: C][49] ([md][69]) | [10: Heaps and Huffman coding][90] | |
| 34 | Apr 8 | Wednesday | | [10: Heaps and Huffman coding][90] | |
| 35 | Apr 10 | Friday | | [10: Heaps and Huffman coding][90] | |
| 36 | Apr 13 | Monday | [Lab 10: Huffman coding][10] ([md][30]) / (no tutorial) | [10: Heaps and Huffman coding][90], [11: Graphs][91] | |
| 37 | Apr 15 | Wednesday | | [11: Graphs][91] | |
| 38 | Apr 17 | Friday | | [11: Graphs][91] | |
| 39 | Apr 20 | Monday | [Lab 11: Graphs][11] ([md][31]) | [11: Graphs][91] | |
| 40 | Apr 22 | Wednesday | | [11: Graphs][91], [12: Memory][92] | |
| 41 | Apr 24 | Friday | | [12: Memory][92] | |
| 42 | Apr 27 | Monday | | [13: Esoteric PLs][93], [Course conclusion][94] | |
| | Apr 28? | Tuesday? | | Final exam review session | |
| | Apr 30 | Thursday | Final exam from 7:00 p.m. - 10:00 p.m. | Final exam from 7:00 p.m. - 10:00 p.m. | |


#### Recording notes

None, yet

------------------------------------------------------------

Grading Concerns
----------------

- None yet!

[1]: ../labs/lab01/index.html
[2]: ../labs/lab02/index.html
[3]: ../labs/lab03/index.html
[4]: ../labs/lab04/index.html
[5]: ../labs/lab05/index.html
[6]: ../labs/lab06/index.html
[7]: ../labs/lab07/index.html
[8]: ../labs/lab08-64bit/index.html
[9]: ../labs/lab09-64bit/index.html
[10]: ../labs/lab10/index.html
[11]: ../labs/lab11/index.html
[12]: ../labs/lab12/index.html

[21]: ../labs/lab01/index.md
[22]: ../labs/lab02/index.md
[23]: ../labs/lab03/index.md
[24]: ../labs/lab04/index.md
[25]: ../labs/lab05/index.md
[26]: ../labs/lab06/index.md
[27]: ../labs/lab07/index.md
[28]: ../labs/lab08-64bit/index.md
[29]: ../labs/lab09/index.md
[30]: ../labs/lab10/index.md
[31]: ../labs/lab11/index.md
[32]: ../labs/lab12/index.md

[40]: ../tutorials/index.html
[41]: ../tutorials/01-intro-unix/index.html
[42]: ../tutorials/02-lldb/index.html
[43]: ../tutorials/03-04-more-unix/index.html
[44]: ../tutorials/03-04-more-unix/index.html
[45]: ../tutorials/05-make/index.html
[46]: http://en.wikibooks.org/wiki/Bash_Shell_Scripting
[47]: http://en.wikibooks.org/wiki/Bash_Shell_Scripting
[48]: http://cs.lmu.edu/~ray/notes/nasmexamples/
[49]: ../tutorials/09-c/index.html
[50]: ../tutorials/10-objc/index.html
[51]: ../tutorials/11-doxygen/index.html
[52]: ../tutorials/02-gdb/index.html
[53]: ../book/x86-32bit-asm-chapter.pdf
[54]: ../book/x86-32bit-ccc-chapter.pdf
[55]: ../book/x86-64bit-asm-chapter.pdf
[56]: ../book/x86-64bit-ccc-chapter.pdf

[61]: ../tutorials/01-intro-unix/index.md
[62]: ../tutorials/02-lldb/index.md
[63]: ../tutorials/03-04-more-unix/index.html
[64]: ../tutorials/03-04-more-unix/index.html
[65]: ../tutorials/05-make/index.md
[69]: ../tutorials/09-c/index.md
[70]: ../tutorials/10-objc/index.md
[71]: ../tutorials/11-doxygen/index.md
[72]: ../tutorials/02-gdb/index.md

[80]: course-introduction.html#/
[81]: ../slides/01-cpp.html#/
[82]: ../slides/02-lists.html#/
[83]: ../slides/03-numbers.html#/
[84]: ../slides/04-arrays-bigoh.html#/
[85]: ../slides/05-trees.html#/
[86]: ../slides/06-hashes.html#/
[87]: ../slides/07-ibcm.html#/
[88]: ../slides/08-assembly-64bit.html#/
[89]: ../slides/09-advanced-cpp.html#/
[90]: ../slides/10-heaps-huffman.html#/
[91]: ../slides/11-graphs.html#/
[92]: ../slides/12-memory.html#/
[93]: ../slides/13-esoteric-pls.html#/
[94]: course-conclusion.html#/

[100]: ../tutorials/index.html
[101]: ../tutorials/index.md
[102]: daily-announcements.html#/
[103]: syllabus.html
[104]: syllabus.md
[105]: labduedates.html
[106]: labduedates.md
[107]: ../labs/index.html
[108]: ../labs/index.md
[109]: frivolous-regrades.html
[110]: frivolous-regrades.md
[111]: ../readme.html
[112]: ../readme.md
[113]: exam-review.html#/
[114]: unix-honor-pledge.tex
[115]: grades.md
[116]: grades.html
[117]: tas.html

[150]: https://calendar.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&ctz=America%2FNew_York
[151]: http://twitter.com/UVaCS2150
[152]: https://piazza.com/

[160]: https://libra.cs.virginia.edu/~pedagogy/
[161]: https://libra.cs.virginia.edu/~pedagogy/support.php
[162]: https://libra.cs.virginia.edu/~pedagogy/submit.php
[163]: https://libra.cs.virginia.edu/~pedagogy/regrades.php
[164]: https://libra.cs.virginia.edu/~pedagogy/gradebook.php
[165]: https://libra.cs.virginia.edu/~pedagogy/labextension.php
[166]: https://libra.cs.virginia.edu/~pedagogy/queue.php

[170]: https://collab.its.virginia.edu/portal/site/c7acc486-f2bd-418a-ad92-c91ae5e03503/tool/173f8c93-fe5c-4418-a7f5-48aebe888647
[171]: https://collab.its.virginia.edu/portal/site/c7acc486-f2bd-418a-ad92-c91ae5e03503/tool/5463997f-35c8-4a6b-b3a4-53770055154d
[172]: unix-honor-pledge-s20.pdf
[173]: https://collab.its.virginia.edu/portal/site/c7acc486-f2bd-418a-ad92-c91ae5e03503/page/53d60f3e-dc1e-45b0-b132-8c660541e4ea
[174]: https://collab.its.virginia.edu/portal/site/c7acc486-f2bd-418a-ad92-c91ae5e03503/tool/3756aebf-1299-4343-809a-7cf9e58a8d48/main
[175]: https://piazza.com/class/k5bqcfbzltk49c

[201]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/course-introduction-1/course-introduction-1.htm
[202]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-1/01-cpp-1.htm
[203]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-2/01-cpp-2.htm
[204]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-3/01-cpp-3.htm
[205]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-4/01-cpp-4.htm
[206]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-5/01-cpp-5.htm
[207]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/01-cpp-6/01-cpp-6.htm
[208]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/02-lists-1/02-lists-1.htm
[209]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/02-lists-2/02-lists-2.htm
[210]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/02-lists-3/02-lists-3.htm
[211]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/03-numbers-1/03-numbers-1.htm
[212]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/03-numbers-2/03-numbers-2.htm
[213]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/03-numbers-3/03-numbers-3.htm
[214]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/03-numbers-4/03-numbers-4.htm
[215]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/04-arrays-bigoh-1/04-arrays-bigoh-1.htm
[216]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/04-arrays-bigoh-2/04-arrays-bigoh-2.htm
[217]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/04-arrays-bigoh-3/04-arrays-bigoh-3.htm
[218]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/exam1-review/exam1-review.htm
[219]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/05-trees-1/05-trees-1.htm
[220]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/05-trees-2/05-trees-2.htm
[221]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/05-trees-3/05-trees-3.htm
[222]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/05-trees-4/05-trees-4.htm
[223]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/05-trees-5/05-trees-5.htm
[224]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/06-hashes-1/06-hashes-1.htm
[225]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/06-hashes-2/06-hashes-2.htm
[226]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/06-hashes-3/06-hashes-3.htm
[227]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/07-ibcm-1/07-ibcm-1.htm
[228]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/07-ibcm-2/07-ibcm-2.htm
[229]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/07-ibcm-3/07-ibcm-3.htm
[230]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/07-ibcm-4/07-ibcm-4.htm
[231]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-1/08-assembly-1.htm
[232]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-2/08-assembly-2.htm
[233]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-3/08-assembly-3.htm
[234]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-4/08-assembly-4.htm
[235]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-5/08-assembly-5.htm
[236]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/08-assembly-6/08-assembly-6.htm
[237]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/09-advanced-cpp-1/09-advanced-cpp-1.htm
[238]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/09-advanced-cpp-2/09-advanced-cpp-2.htm
[239]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/exam2-review/exam2-review.htm
[240]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/09-advanced-cpp-3/09-advanced-cpp-3.htm
[241]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/10-heaps-huffman-1/10-heaps-huffman-1.htm
[242]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/10-heaps-huffman-2/10-heaps-huffman-2.htm
[243]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/10-heaps-huffman-3/10-heaps-huffman-3.htm
[244]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/10-heaps-huffman-4/10-heaps-huffman-4.htm
[245]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/11-graphs-1/11-graphs-1.htm
[246]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/11-graphs-2/11-graphs-2.htm
[247]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/11-graphs-3/11-graphs-3.htm
[248]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/11-graphs-4/11-graphs-4.htm
[249]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/12-memory-1/12-memory-1.htm
[250]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/12-memory-2/12-memory-2.htm
[251]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/12-memory-3/12-memory-3.htm
[252]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/course-conclusion/course-conclusion.htm
[253]: https://collab.itc.virginia.edu/access/content/group/41174582-53b0-472a-a22c-f466f2aa653a/lectures/final-review/final-review.htm

[1000228]: ../uva/course-introduction.html#/2/28
[1000240]: ../uva/course-introduction.html#/2/40
[1000241]: ../uva/course-introduction.html#/2/41
[1000303]: ../uva/course-introduction.html#/3/3
[1000341]: ../uva/course-introduction.html#/3/41
[10004]: ../uva/course-introduction.html#/4
[1000402]: ../uva/course-introduction.html#/4/2
[1000403]: ../uva/course-introduction.html#/4/3
[10005]: ../uva/course-introduction.html#/5
[1000601]: ../uva/course-introduction.html#/6/1
[1000602]: ../uva/course-introduction.html#/6/2
[1010308]: ../slides/01-cpp.html#/3/8
[1010309]: ../slides/01-cpp.html#/3/9
[1010310]: ../slides/01-cpp.html#/3/10
[1010311]: ../slides/01-cpp.html#/3/11
[1010312]: ../slides/01-cpp.html#/3/12
[1010313]: ../slides/01-cpp.html#/3/13
[1010314]: ../slides/01-cpp.html#/3/14
[1010318]: ../slides/01-cpp.html#/3/18
[10104]: ../slides/01-cpp.html#/4
[1010404]: ../slides/01-cpp.html#/4/4
[1000406]: ../slides/01-cpp.html#/4/6
[1010415]: ../slides/01-cpp.html#/4/15
[10105]: ../slides/01-cpp.html#/5
[1010503]: ../slides/01-cpp.html#/5/3
[1010505]: ../slides/01-cpp.html#/5/5
[1010508]: ../slides/01-cpp.html#/5/8
[1010608]: ../slides/01-cpp.html#/6/8
[10107]: ../slides/01-cpp.html#/7
[1000703]: ../slides/01-cpp.html#/7/3
[1010704]: ../slides/01-cpp.html#/7/4
[10108]: ../slides/01-cpp.html#/8
[1010806]: ../slides/01-cpp.html#/8/6
[1010809]: ../slides/01-cpp.html#/8/9
[1010815]: ../slides/01-cpp.html#/8/15
[1010816]: ../slides/01-cpp.html#/8/16
[1010817]: ../slides/01-cpp.html#/8/17
[1010818]: ../slides/01-cpp.html#/8/18
[10109]: ../slides/01-cpp.html#/9
[1010905]: ../slides/01-cpp.html#/9/5
[1010911]: ../slides/01-cpp.html#/9/11
[1010912]: ../slides/01-cpp.html#/9/12
[1010913]: ../slides/01-cpp.html#/9/13
[1010914]: ../slides/01-cpp.html#/9/14
[1010915]: ../slides/01-cpp.html#/9/15
[1010916]: ../slides/01-cpp.html#/9/16
[1010919]: ../slides/01-cpp.html#/9/19
[1010920]: ../slides/01-cpp.html#/9/20
[10110]: ../slides/01-cpp.html#/10
[1011001]: ../slides/01-cpp.html#/10/1
[1011002]: ../slides/01-cpp.html#/10/2
[1011103]: ../slides/01-cpp.html#/11/3
[1011104]: ../slides/01-cpp.html#/11/4
[1011105]: ../slides/01-cpp.html#/11/5
[1011106]: ../slides/01-cpp.html#/11/6
[1011107]: ../slides/01-cpp.html#/11/7
[1011109]: ../slides/01-cpp.html#/11/9
[1011110]: ../slides/01-cpp.html#/11/10
[1011205]: ../slides/01-cpp.html#/12/5
[1011213]: ../slides/01-cpp.html#/12/13
[10200]: ../slides/02-lists.html
[1020303]: ../slides/02-lists.html#/3/3
[1020304]: ../slides/02-lists.html#/3/4
[1020305]: ../slides/02-lists.html#/3/5
[10204]: ../slides/02-lists.html#/4
[1020409]: ../slides/02-lists.html#/4/9
[10205]: ../slides/02-lists.html#/5
[1020505]: ../slides/02-lists.html#/5/5
[1020506]: ../slides/02-lists.html#/5/6
[1020507]: ../slides/02-lists.html#/5/7
[1020508]: ../slides/02-lists.html#/5/8
[1020512]: ../slides/02-lists.html#/5/12
[1020515]: ../slides/02-lists.html#/5/15
[10206]: ../slides/02-lists.html#/6
[1020601]: ../slides/02-lists.html#/6/1
[1020602]: ../slides/02-lists.html#/6/2
[1020603]: ../slides/02-lists.html#/6/3
[1020606]: ../slides/02-lists.html#/6/6
[1020607]: ../slides/02-lists.html#/6/7
[10207]: ../slides/02-lists.html#/7
[1020706]: ../slides/02-lists.html#/7/6
[1020708]: ../slides/02-lists.html#/7/8
[10208]: ../slides/02-lists.html#/8
[1020803]: ../slides/02-lists.html#/8/3
[1030303]: ../slides/03-numbers.html#/3/3
[10304]: ../slides/03-numbers.html#/4
[1030403]: ../slides/03-numbers.html#/4/3
[1030404]: ../slides/03-numbers.html#/4/4
[1030406]: ../slides/03-numbers.html#/4/6
[1030506]: ../slides/03-numbers.html#/5/6
[10306]: ../slides/03-numbers.html#/6
[10307]: ../slides/03-numbers.html#/7
[1030701]: ../slides/03-numbers.html#/7/1
[1030703]: ../slides/03-numbers.html#/7/3
[1030708]: ../slides/03-numbers.html#/7/8
[1030603]: ../slides/03-numbers.html#/6/3
[1030608]: ../slides/03-numbers.html#/6/8
[1030705]: ../slides/03-numbers.html#/7/5
[1030711]: ../slides/03-numbers.html#/7/11
[10308]: ../slides/03-numbers.html#/8
[1030801]: ../slides/03-numbers.html#/8/1
[1030803]: ../slides/03-numbers.html#/8/3
[1030809]: ../slides/03-numbers.html#/8/9
[1030810]: ../slides/03-numbers.html#/8/10
[1030812]: ../slides/03-numbers.html#/8/12
[1030813]: ../slides/03-numbers.html#/8/13
[1030814]: ../slides/03-numbers.html#/8/14
[1030815]: ../slides/03-numbers.html#/8/15
[1030816]: ../slides/03-numbers.html#/8/16
[1030817]: ../slides/03-numbers.html#/8/17
[1030818]: ../slides/03-numbers.html#/8/18
[1030825]: ../slides/03-numbers.html#/8/25
[1030831]: ../slides/03-numbers.html#/8/31
[1030832]: ../slides/03-numbers.html#/8/32
[1030833]: ../slides/03-numbers.html#/8/33
[1030834]: ../slides/03-numbers.html#/8/34
[10309]: ../slides/03-numbers.html#/9
[1040304]: ../slides/04-arrays-bigoh.html#/3/4
[1040306]: ../slides/04-arrays-bigoh.html#/3/6
[1040307]: ../slides/04-arrays-bigoh.html#/3/7
[1040311]: ../slides/04-arrays-bigoh.html#/3/11
[10404]: ../slides/04-arrays-bigoh.html#/4
[1040401]: ../slides/04-arrays-bigoh.html#/4/1
[1040402]: ../slides/04-arrays-bigoh.html#/4/2
[1040403]: ../slides/04-arrays-bigoh.html#/4/3
[1040405]: ../slides/04-arrays-bigoh.html#/4/5
[1040407]: ../slides/04-arrays-bigoh.html#/4/7
[1040409]: ../slides/04-arrays-bigoh.html#/4/9
[1040410]: ../slides/04-arrays-bigoh.html#/4/10
[1040415]: ../slides/04-arrays-bigoh.html#/4/15
[1040417]: ../slides/04-arrays-bigoh.html#/4/17
[1040419]: ../slides/04-arrays-bigoh.html#/4/19
[1040420]: ../slides/04-arrays-bigoh.html#/4/20
[1040421]: ../slides/04-arrays-bigoh.html#/4/21
[1040422]: ../slides/04-arrays-bigoh.html#/4/22
[1040425]: ../slides/04-arrays-bigoh.html#/4/25
[1040507]: ../slides/04-arrays-bigoh.html#/5/7
[1050305]: ../slides/05-trees.html#/3/5
[1050306]: ../slides/05-trees.html#/3/6
[1050310]: ../slides/05-trees.html#/3/10
[1050311]: ../slides/05-trees.html#/3/11
[1050315]: ../slides/05-trees.html#/3/15
[10504]: ../slides/05-trees.html#/4
[1050410]: ../slides/05-trees.html#/4/10
[1050411]: ../slides/05-trees.html#/4/11
[1050412]: ../slides/05-trees.html#/4/12
[1050415]: ../slides/05-trees.html#/4/15
[1050416]: ../slides/05-trees.html#/4/16
[1050417]: ../slides/05-trees.html#/4/17
[1050418]: ../slides/05-trees.html#/4/18
[1050419]: ../slides/05-trees.html#/4/19
[10505]: ../slides/05-trees.html#/5
[1050514]: ../slides/05-trees.html#/5/14
[10506]: ../slides/05-trees.html#/6
[1050604]: ../slides/05-trees.html#/6/4
[1050605]: ../slides/05-trees.html#/6/5
[1050609]: ../slides/05-trees.html#/6/9
[1050610]: ../slides/05-trees.html#/6/10
[1050612]: ../slides/05-trees.html#/6/12
[1050617]: ../slides/05-trees.html#/6/17
[1050630]: ../slides/05-trees.html#/6/30
[1050629]: ../slides/05-trees.html#/6/29
[10507]: ../slides/05-trees.html#/7
[1050701]: ../slides/05-trees.html#/7/1
[1050702]: ../slides/05-trees.html#/7/2
[1050703]: ../slides/05-trees.html#/7/3
[1050704]: ../slides/05-trees.html#/7/4
[1050709]: ../slides/05-trees.html#/7/9
[1050711]: ../slides/05-trees.html#/7/11
[10508]: ../slides/05-trees.html#/8
[1050801]: ../slides/05-trees.html#/8/1
[1050802]: ../slides/05-trees.html#/8/2
[1050808]: ../slides/05-trees.html#/8/8
[1050811]: ../slides/05-trees.html#/8/11
[10509]: ../slides/05-trees.html#/9
[1050901]: ../slides/05-trees.html#/9/1
[1050902]: ../slides/05-trees.html#/9/2
[1050909]: ../slides/05-trees.html#/9/9
[10604]: ../slides/06-hashes.html#/4
[1060406]: ../slides/06-hashes.html#/4/6
[1060407]: ../slides/06-hashes.html#/4/7
[1060411]: ../slides/06-hashes.html#/4/11
[1060412]: ../slides/06-hashes.html#/4/12
[1060413]: ../slides/06-hashes.html#/4/13
[1060401]: ../slides/06-hashes.html#/4/1
[1060404]: ../slides/06-hashes.html#/4/4
[1060405]: ../slides/06-hashes.html#/4/5
[1060410]: ../slides/06-hashes.html#/4/10
[1060414]: ../slides/06-hashes.html#/4/14
[10605]: ../slides/06-hashes.html#/5
[1060502]: ../slides/06-hashes.html#/5/2
[1060505]: ../slides/06-hashes.html#/5/5
[1060506]: ../slides/06-hashes.html#/5/6
[1060507]: ../slides/06-hashes.html#/5/7
[10606]: ../slides/06-hashes.html#/6
[1060603]: ../slides/06-hashes.html#/6/3
[1060604]: ../slides/06-hashes.html#/6/4
[1060608]: ../slides/06-hashes.html#/6/8
[1060609]: ../slides/06-hashes.html#/6/9
[1060611]: ../slides/06-hashes.html#/6/11
[10607]: ../slides/06-hashes.html#/7
[1060702]: ../slides/06-hashes.html#/7/2
[1060703]: ../slides/06-hashes.html#/7/3
[1060704]: ../slides/06-hashes.html#/7/4
[1060706]: ../slides/06-hashes.html#/7/6
[1070302]: ../slides/07-ibcm.html#/3/2
[1070303]: ../slides/07-ibcm.html#/3/3
[1070401]: ../slides/07-ibcm.html#/4/1
[1070402]: ../slides/07-ibcm.html#/4/2
[1070404]: ../slides/07-ibcm.html#/4/4
[1070405]: ../slides/07-ibcm.html#/4/5
[1070407]: ../slides/07-ibcm.html#/4/7
[1070410]: ../slides/07-ibcm.html#/4/10
[1070415]: ../slides/07-ibcm.html#/4/15
[10705]: ../slides/07-ibcm.html#/5
[1070503]: ../slides/07-ibcm.html#/5/3
[1070505]: ../slides/07-ibcm.html#/5/5
[1070506]: ../slides/07-ibcm.html#/5/6
[1070507]: ../slides/07-ibcm.html#/5/7
[1070508]: ../slides/07-ibcm.html#/5/8
[1070511]: ../slides/07-ibcm.html#/5/11
[10706]: ../slides/07-ibcm.html#/6
[1070601]: ../slides/07-ibcm.html#/6/1
[1070604]: ../slides/07-ibcm.html#/6/4
[1070609]: ../slides/07-ibcm.html#/6/9
[1080301]: ../slides/08-assembly-64bit.html#/3/1
[1080302]: ../slides/08-assembly-64bit.html#/3/2
[1080306]: ../slides/08-assembly-64bit.html#/3/6
[1080410]: ../slides/08-assembly-64bit.html#/4/10
[1080304]: ../slides/08-assembly-64bit.html#/3/4
[1080305]: ../slides/08-assembly-64bit.html#/3/5
[1080309]: ../slides/08-assembly-64bit.html#/3/9
[1080402]: ../slides/08-assembly-64bit.html#/4/2
[1080405]: ../slides/08-assembly-64bit.html#/4/5
[1080406]: ../slides/08-assembly-64bit.html#/4/6
[10805]: ../slides/08-assembly-64bit.html#/5
[1080502]: ../slides/08-assembly-64bit.html#/5/2
[1080504]: ../slides/08-assembly-64bit.html#/5/4
[1080505]: ../slides/08-assembly-64bit.html#/5/5
[1080607]: ../slides/08-assembly-64bit.html#/6/7
[1080608]: ../slides/08-assembly-64bit.html#/6/8
[1080609]: ../slides/08-assembly-64bit.html#/6/9
[10807]: ../slides/08-assembly-64bit.html#/7
[1080710]: ../slides/08-assembly-64bit.html#/7/10
[1080713]: ../slides/08-assembly-64bit.html#/7/13
[1080714]: ../slides/08-assembly-64bit.html#/7/14
[10808]: ../slides/08-assembly-64bit.html#/8
[1080804]: ../slides/08-assembly-64bit.html#/8/4
[1080805]: ../slides/08-assembly-64bit.html#/8/5
[10809]: ../slides/08-assembly-64bit.html#/9
[1080904]: ../slides/08-assembly-64bit.html#/9/4
[1080906]: ../slides/08-assembly-64bit.html#/9/6
[1080908]: ../slides/08-assembly-64bit.html#/9/8
[1080914]: ../slides/08-assembly-64bit.html#/9/14
[1080912]: ../slides/08-assembly-64bit.html#/9/12
[1080915]: ../slides/08-assembly-64bit.html#/9/15
[1080916]: ../slides/08-assembly-64bit.html#/9/16
[1080918]: ../slides/08-assembly-64bit.html#/9/18
[1080929]: ../slides/08-assembly-64bit.html#/9/29
[1080930]: ../slides/08-assembly-64bit.html#/9/30
[1080932]: ../slides/08-assembly-64bit.html#/9/32
[1080934]: ../slides/08-assembly-64bit.html#/9/34
[1090308]: ../slides/09-advanced-cpp.html#/3/8
[1090408]: ../slides/09-advanced-cpp.html#/4/8
[10905]: ../slides/09-advanced-cpp.html#/5
[1090502]: ../slides/09-advanced-cpp.html#/5/2
[1090503]: ../slides/09-advanced-cpp.html#/5/3
[1090508]: ../slides/09-advanced-cpp.html#/5/8
[1090509]: ../slides/09-advanced-cpp.html#/5/9
[1090518]: ../slides/09-advanced-cpp.html#/5/18
[1090519]: ../slides/09-advanced-cpp.html#/5/19
[1090520]: ../slides/09-advanced-cpp.html#/5/20
[1090521]: ../slides/09-advanced-cpp.html#/5/21
[10906]: ../slides/09-advanced-cpp.html#/6
[1090602]: ../slides/09-advanced-cpp.html#/6/2
[1090708]: ../slides/09-advanced-cpp.html#/7/8
[1090710]: ../slides/09-advanced-cpp.html#/7/10
[1090711]: ../slides/09-advanced-cpp.html#/7/11
[1100303]: ../slides/10-heaps-huffman.html#/3/3
[11004]: ../slides/10-heaps-huffman.html#/4
[1100404]: ../slides/10-heaps-huffman.html#/4/4
[1100406]: ../slides/10-heaps-huffman.html#/4/6
[1100407]: ../slides/10-heaps-huffman.html#/4/7
[1100408]: ../slides/10-heaps-huffman.html#/4/8
[11005]: ../slides/10-heaps-huffman.html#/5
[1100501]: ../slides/10-heaps-huffman.html#/5/1
[1100503]: ../slides/10-heaps-huffman.html#/5/3
[1100506]: ../slides/10-heaps-huffman.html#/5/6
[1100507]: ../slides/10-heaps-huffman.html#/5/7
[1100508]: ../slides/10-heaps-huffman.html#/5/8
[1100510]: ../slides/10-heaps-huffman.html#/5/10
[1100512]: ../slides/10-heaps-huffman.html#/5/12
[1100515]: ../slides/10-heaps-huffman.html#/5/15
[1100603]: ../slides/10-heaps-huffman.html#/6/3
[1100605]: ../slides/10-heaps-huffman.html#/6/5
[11006]: ../slides/10-heaps-huffman.html#/6
[1100606]: ../slides/10-heaps-huffman.html#/6/6
[11007]: ../slides/10-heaps-huffman.html#/7
[1100701]: ../slides/10-heaps-huffman.html#/7/1
[1100703]: ../slides/10-heaps-huffman.html#/7/3
[1100705]: ../slides/10-heaps-huffman.html#/7/5
[1100706]: ../slides/10-heaps-huffman.html#/7/6
[1100718]: ../slides/10-heaps-huffman.html#/7/18
[1100720]: ../slides/10-heaps-huffman.html#/7/20
[1100723]: ../slides/10-heaps-huffman.html#/7/23
[1100726]: ../slides/10-heaps-huffman.html#/7/26
[1100728]: ../slides/10-heaps-huffman.html#/7/28
[1100729]: ../slides/10-heaps-huffman.html#/7/29
[1100730]: ../slides/10-heaps-huffman.html#/7/30
[11008]: ../slides/10-heaps-huffman.html#/8
[1100808]: ../slides/10-heaps-huffman.html#/8/8
[1100830]: ../slides/10-heaps-huffman.html#/8/30
[1110304]: ../slides/11-graphs.html#/3/4
[1110305]: ../slides/11-graphs.html#/3/5
[1110306]: ../slides/11-graphs.html#/3/6
[1110312]: ../slides/11-graphs.html#/3/12
[1110310]: ../slides/11-graphs.html#/3/10
[1110402]: ../slides/11-graphs.html#/4/2
[11104]: ../slides/11-graphs.html#/4
[1110406]: ../slides/11-graphs.html#/4/6
[1110408]: ../slides/11-graphs.html#/4/8
[11105]: ../slides/11-graphs.html#/5
[1110506]: ../slides/11-graphs.html#/5/6
[1110507]: ../slides/11-graphs.html#/5/7
[1110508]: ../slides/11-graphs.html#/5/8
[1110509]: ../slides/11-graphs.html#/5/9
[1110513]: ../slides/11-graphs.html#/5/13
[11106]: ../slides/11-graphs.html#/6
[1110605]: ../slides/11-graphs.html#/6/5
[11107]: ../slides/11-graphs.html#/7
[1110708]: ../slides/11-graphs.html#/7/8
[11108]: ../slides/11-graphs.html#/8
[1110806]: ../slides/11-graphs.html#/8/6
[1110809]: ../slides/11-graphs.html#/8/9
[1110810]: ../slides/11-graphs.html#/8/10
[1110814]: ../slides/11-graphs.html#/8/14
[1120303]: ../slides/12-memory.html#/3/3
[1120304]: ../slides/12-memory.html#/3/4
[1120308]: ../slides/12-memory.html#/3/8
[1120311]: ../slides/12-memory.html#/3/11
[1120312]: ../slides/12-memory.html#/3/12
[1120325]: ../slides/12-memory.html#/3/25
[11204]: ../slides/12-memory.html#/4
[1120403]: ../slides/12-memory.html#/4/3
[1120407]: ../slides/12-memory.html#/4/7
[1120414]: ../slides/12-memory.html#/4/14
[1120415]: ../slides/12-memory.html#/4/15
[1120418]: ../slides/12-memory.html#/4/18
[1130325]: ../slides/13-esoteric-pls.html#/3/25
[1130512]: ../slides/13-esoteric-pls.html#/5/12
[12009]: course-conclusion.html#/9
[12010]: course-conclusion.html#/10
[12011]: course-conclusion.html#/11
