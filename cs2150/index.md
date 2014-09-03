Program and Data Representation: CS 2150 Specific Content
=========================================================

[Go up to the main README file][111] ([md][112])

Much of the rest of this git repo is meant to be generic to anybody who has a class such as this one.  But this page contains details specific to the CS 2150 version of the course at the University of Virginia.

------------------------------------------------------------

Links
-----

There are a number of links and other parts of this course that are **NOT** included in this repository.  They are:

- The set of online tools, which can be accessed through Collab or [here][160].
    - These tools are: [support requests][161], [lab submission][162], [regrades][163], [gradebook][164], and [lab extensions][165]
- The announcements, which are posted to the CS 2150 twitter feed: [\@UVaCS2150][151]
- The [CS 2150 Google calendar][150]
- Grading explanations, including the grading guidelines; this is available in the Collab wiki ([here][171] is the direct link, although Collab login is required)
- Email list archive, which is a Collab tool ([here][170] is the direct link, although Collab login is required)
- [Piazza][152]; Collab can log you in directly.

The parts of this course that are in this repo are:

- [Daily announcements slide set][102]
- [Course introduction slide set][80]
- [Course syllabus][103] ([md][104]): the course syllabus
- [Lab due dates][105] ([md][106]): When the various lab parts are due
- [UNIX honor pledge][172], which needs to be signed by all the students in the course; it is created from a [.tex][114] file
- [Generic review session slide set][113], which is really just a blank set of slides
- [Frivolous regrade policy][109] ([md][110]) for exams

------------------------------------------------------------

Labs and Tutorials
------------------

This is a series of links to the labs and tutorials that are elsewhere in this repository.  A bunch of notes:

- The lab parts are all due on specific times throughout the week, as detailed on the [lab due dates][105] ([md][106]) page
    - Each lab is for a given week, which (for sake of argument) we claim starts on a Monday
    - Which lab is done on which week is listed below in the semester schedule
- The lab is released the week before, typically on a Wednesday or Thursday
    - While a version of the lab will be in this github repo for some time prior, there **WILL** be modifications to that lab up until the "official" release, which is when it is announced as released on the twitter feed: [\@UVaCS2150](http://twitter.com/UVaCS2150)
- All the labs and tutorials can be found on the [labs page][107] ([md][108]) and the [tutorials page][100] ([md][101]).
    - In particular, these pages have additional details and links not described here

------------------------------------------------------------

Semester Schedule
-----------------

The links in the right-most column link directly to the lecture recording on Collab, and you have to be logged into Collab first before the link will work. Some plugins (such as NoScript) will block that link from working.  Unless otherwise indicated, both lectures stopped at the same point.

| Num | Date | Day of week | Lab & Tutorial | Planned topic | Actual lecture progress (and recording) |
|-----|--------|-------------|----------------------------------------------------------|--------------------------|--------------------------|
| 1 | Aug&nbsp;27 | Wednesday | no lab this week | [Course introduction][80] | [course-introduction][80], slides 0 to 5-9 ([recording][201]) |
| 2 | Aug&nbsp;29 | Friday | | [Course introduction][80], [01: C++][81] |  [course-introduction][80], slides 5-9 to 6-1 (end); [01-cpp][81], slides 0 to 3-14 ([recording][202]) |
| 3 | Sep&nbsp;1 | Monday | | [01: C++][81] | [01-cpp][81], slides 4 to 6-7 ([recording][203]) |
| 4 | Sep&nbsp;3 | Wednesday | [Lab 1: Intro to C++][1] ([md][21]) / [Tutorial 1: Intro to UNIX][41] ([md][61]) | [01: C++][81] | [01-cpp][81], slides 6-8 to 8-13 ([recording][204]) |
| 5 | Sep&nbsp;5 | Friday | | [01: C++][81] |  |
| 6 | Sep&nbsp;8 | Monday | | [01: C++][81] |  |
| 7 | Sep&nbsp;10 | Wednesday | [Lab 2: Linked lists][2] ([md][22]) / [Tutorial 2: GDB][42] ([md][62]) | [02: Lists][82] |  |
| 8 | Sep&nbsp;12 | Friday | | [02: Lists][82] |  |
| 9 | Sep&nbsp;15 | Monday | | [02: Lists][82], [03: Numbers][83] |  |
| 10 | Sep&nbsp;17 | Wednesday | [Lab 3: Stacks][3] ([md][23]) / [Tutorial 3: More UNIX, part 1][63], sections 1-4 | [03: Numbers][83] |  |
| 11 | Sep&nbsp;19 | Friday | | [03: Numbers][83] |  |
| 12 | Sep&nbsp;22 | Monday | | [03: Numbers][83] |  |
| 13 | Sep&nbsp;24 | Wednesday | [Lab 4: Numbers][4] ([md][24]) / [Tutorial 4: More UNIX, part 2][64], sections 5-8 | [04: Arrays & big-Oh][84] |  |
| 14 | Sep&nbsp;26 | Friday | | [04: Arrays & big-Oh][84] |  |
|    | Sep&nbsp;28 | Sunday | Exam 1 review session | Exam 1 review session |  |
| 15 | Sep&nbsp;29 | Monday | | [05: Trees][85] |  |
| 16 | Oct&nbsp;1 | Wednesday | Exam 1 instead during Tuesday's lab | [05: Trees][85] |  |
| 17 | Oct&nbsp;3 | Friday | | [05: Trees][85] |  |
| 18 | Oct&nbsp;6 | Monday | | [05: Trees][85] |  |
| 19 | Oct&nbsp;8 | Wednesday | [Lab 5: Trees][5] ([md][25]) / [Tutorial 5: make][45] ([md][65]) | [06: Hashes][86] |  |
| 20 | Oct&nbsp;10 | Friday | | [06: Hashes][86] |  |
|    | Oct&nbsp;13 | Monday | | no class (reading day) |  |
| 21 | Oct&nbsp;15 | Wednesday | no labs (reading day) | [06: Hashes][86] |  |
| 22 | Oct&nbsp;17 | Friday | | [07: IBCM][87] (machine language) |  |
| 23 | Oct&nbsp;20 | Monday | | [07: IBCM][87] (machine language) |  |
| 24 | Oct&nbsp;22 | Wednesday | [Lab 6: Hashes][6] ([md][26]) / Tutorial 6: Shell scripting, part 1 (first half of [here][46], through 'exit status') | [07: IBCM][87] (machine language) |  |
| 25 | Oct&nbsp;24 | Friday | | [08: x86][88] (assembly language) |  |
| 26 | Oct&nbsp;27 | Monday | | [08: x86][88] (assembly language) |  |
| 27 | Oct&nbsp;29 | Wednesday | [Lab 7: IBCM][7] ([md][27]) / Tutorial 7: Shell scripting, part 2 (remainder of [here][47]) | [08: x86][88] (assembly language) |  |
| 28 | Oct&nbsp;31 | Friday | | [08: x86][88] (assembly language) |  |
|    | Nov&nbsp;2 | Sunday | Exam 2 review session | Exam 2 review session |  |
| 29 | Nov&nbsp;3 | Monday | | [08: x86][88] (assembly language) |  |
| 30 | Nov&nbsp;5 | Wednesday | [Lab 8: x86, part 1][8] ([md][28]) / [Tutorial 8: nasm][48], but you can skip some parts; see [here][100]) ([md][101]) for details | [08: x86][88], [09: Advanced C++][89] |  |
| 31 | Nov&nbsp;7 | Friday | | [09: Advanced C++][89] |  |
| 32 | Nov&nbsp;10 | Monday | | [10: Heaps and Huffman coding][90]|  |
| 33 | Nov&nbsp;12 | Wednesday | [Lab 9: x86, part 2][9] ([md][29]) / [Tutorial 9: C][49] ([md][69]) | [10: Heaps and Huffman coding][90] |  |
| 34 | Nov&nbsp;14 | Friday | | [10: Heaps and Huffman coding][90] |  |
| 35 | Nov&nbsp;17 | Monday | | [10: Heaps and Huffman coding][90] |  |
| 36 | Nov&nbsp;19 | Wednesday | [Lab 10: Huffman coding][10] ([md][30]) / [Tutorial 10: Objective C][50] ([md][70]) | [11: Graphs][91] |  |
| 37 | Nov&nbsp;21 | Friday | | [11: Graphs][91] |  |
| 38 | Nov&nbsp;24 | Monday | | [11: Graphs][91] |  |
|    | Nov&nbsp;26 | Wednesday | | no class (Thanksgiving) |  |
|    | Nov&nbsp;28 | Friday | | no class (Thanksgiving) |  |
| 39 | Dec&nbsp;1 | Monday | [Lab 11: Graphs][11] ([md][31]) / [Tutorial 11: doxygen][51] ([md][71]) | [11: Graphs][91] |  |
| 40 | Dec&nbsp;3 | Wednesday | | [12: Memory][92] |  |
| 41 | Dec&nbsp;5 | Friday |  | [12: Memory][92], [Course conclusion][93] |  |
|    | ??? | ??? | Final exam review session | Final exam review session |  |

------------------------------------------------------------

Grading Concerns
----------------

None yet!


[1]: ../labs/lab01/index.html
[2]: ../labs/lab02/index.html
[3]: ../labs/lab03/index.html
[4]: ../labs/lab04/index.html
[5]: ../labs/lab05/index.html
[6]: ../labs/lab06/index.html
[7]: ../labs/lab07/index.html
[8]: ../labs/lab08/index.html
[9]: ../labs/lab09/index.html
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
[28]: ../labs/lab08/index.md
[29]: ../labs/lab09/index.md
[30]: ../labs/lab10/index.md
[31]: ../labs/lab11/index.md
[32]: ../labs/lab12/index.md

[41]: ../tutorials/01-intro-unix/index.html
[42]: ../tutorials/02-gdb/index.html
[43]: ../tutorials/03-04-more-unix/index.html
[44]: ../tutorials/03-04-more-unix/index.html
[45]: ../tutorials/05-make/index.html
[46]: http://en.wikibooks.org/wiki/Bash_Shell_Scripting
[47]: http://en.wikibooks.org/wiki/Bash_Shell_Scripting
[48]: http://cs.lmu.edu/~ray/notes/nasmexamples/
[49]: ../tutorials/09-c/index.html
[50]: ../tutorials/10-objc/index.html
[51]: ../tutorials/11-doxygen/index.html

[61]: ../tutorials/01-intro-unix/index.md
[62]: ../tutorials/02-gdb/index.md
[65]: ../tutorials/05-make/index.md
[69]: ../tutorials/09-c/index.md
[70]: ../tutorials/10-objc/index.md
[71]: ../tutorials/11-doxygen/index.md

[80]: course-introduction.html
[81]: ../slides/01-cpp.html
[82]: ../slides/02-lists.html
[83]: ../slides/03-numbers.html
[84]: ../slides/04-arrays-bigoh.html
[85]: ../slides/05-trees.html
[86]: ../slides/06-hashes.html
[87]: ../slides/07-ibcm.html
[88]: ../slides/08-x86.html
[89]: ../slides/09-advanced-cpp.html
[90]: ../slides/10-heaps-huffman.html
[91]: ../slides/11-graphs.html
[92]: ../slides/12-memory.html
[93]: course-conclusion.html

[100]: ../tutorials/index.html
[101]: ../tutorials/index.md
[102]: daily-announcements.html
[103]: syllabus.html
[104]: syllabus.md
[105]: labduedates.html
[106]: labduedates.md
[107]: ../labs/index.html
[108]: ../labs/index.md
[109]: frivolous-regrades.html
[110]: frivolous-regrades.md
[111]: ../README.html
[112]: ../README.md
[113]: exam-review.html
[114]: unix-honor-pledge.tex

[150]: https://www.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&amp;amp;ctz=America/New_York
[151]: http://twitter.com/UVaCS2150
[152]: https://piazza.com/

[160]: https://libra.cs.virginia.edu/~pedagogy/
[161]: https://libra.cs.virginia.edu/~pedagogy/support.php
[162]: https://libra.cs.virginia.edu/~pedagogy/submit.php
[163]: https://libra.cs.virginia.edu/~pedagogy/regrades.php
[164]: https://libra.cs.virginia.edu/~pedagogy/gradebook.php
[165]: https://libra.cs.virginia.edu/~pedagogy/labextension.php

[170]: https://collab.itc.virginia.edu/portal/site/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/page/25c10fb2-1f3c-451a-a614-931012320919
[171]: https://collab.itc.virginia.edu/portal/site/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/page/25e168d5-b7fc-4d8d-a021-4d39eda4e0aa
[172]: unix-honor-pledge-f14.pdf

[201]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/course-introduction-1/course-introduction-1.htm
[202]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/01-cpp-1/01-cpp-1.htm
[203]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/01-cpp-2/01-cpp-2.htm
[204]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/01-cpp-3/01-cpp-3.htm
[205]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/01-cpp-4/01-cpp-4.htm
[206]: https://collab.itc.virginia.edu/access/content/group/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/lectures/01-cpp-5/01-cpp-5.htm
