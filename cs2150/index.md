Program and Data Representation: CS 2150 Specific Content
=========================================================

## Fall 2015

[Go up to the main README file][111] ([md][112])

Much of the rest of this git repo is meant to be generic to anybody who has a class such as this one.  But this page contains details specific to the CS 2150 version of the course at the University of Virginia.

------------------------------------------------------------

Links
-----

There are a number of links and other parts of this course that are **NOT** included in this repository.  They are:

- The set of online tools, which can be accessed through Collab or [here][160].
    - These tools are: [support requests][161], [lab submission][162], [regrades][163], [gradebook][164], [lab extensions][165], and the [office hours queue][166]
- The announcements, which are posted to the CS 2150 twitter feed: [\@UVaCS2150][151]
- The [CS 2150 Google calendar][150]
- Grading guidelines, which are available in the Collab wiki ([here][171] is the direct link, although Collab login is required)
- Email list archive, which is a Collab tool ([here][170] is the direct link, although Collab login is required)
- [Piazza][152]; Collab can log you in directly; the Collab tool link is [here][173] (again, Collab login required)

The parts of this course that are in this repo are:

- [Daily announcements slide set][102]
- [Course introduction slide set][80]
- [Course syllabus][103] ([md][104]): the course syllabus
- [Lab due dates][105] ([md][106]): When the various lab parts are due
- [UNIX honor pledge][172], which needs to be signed by all the students in the course (it is created from a [.tex][114] file)
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

| Num | Date | Day of week | Lab & Tutorial (on Tue) | Planned topic | Actual lecture progress (and recording) | 
|-----|--------|-------------|----------------------------------------------------------|--------------------------|--------------------------| 
|1 | Aug&nbsp;26 | Wednesday | no lab this week | [Course introduction][80] | [Course introduction][80], slides [1][80] to [42][1000303] ([recording][201]) |
|2 | Aug&nbsp;28 | Friday    | | [Course introduction][80], [01: C++][81] | [Course introduction][80], slides [43][10004] to [58][1000601] (end); [01-cpp][81], slides [1][81] to [14][1010310] ([recording][202]) |
|3 | Aug&nbsp;31 | Monday    | [Lab 1: Intro to C++][1] ([md][21]) / [Tutorial 1: Intro to UNIX][41] ([md][61]) | [01: C++][81] | [01-cpp][81], slides [15][1010311] to [42][1010608] ([recording][203]) |
|4 | Sep&nbsp;2  | Wednesday | | [01: C++][81] | [01-cpp][81], slides [43][10107] to [63][1010815] ([recording][204]) |
|5 | Sep&nbsp;4  | Friday    | | [01: C++][81] | [01-cpp][81], slides [64][1010816] to [79][1010912] ([recording][205]) |
|6 | Sep&nbsp;7  | Monday    | [Lab 2: Linked lists][2] ([md][22]) / [Tutorial 2: LLDB][42] ([md][62]) *OR* [Tutorial 2: GDB][52] ([md][72]) (see [lab 2][2] for which one to pick) | [01: C++][81] | [01-cpp][81], slides [80][1010913] to [87][10110] ([recording][206]) |
|7 | Sep&nbsp;9  | Wednesday | | [01: C++][81], [02: Lists][82] | [01-cpp][81], slides [87][10110] to [121][1011213] (end) ([recording][207]) |
|8 | Sep&nbsp;11 | Friday    | | [02: Lists][82] | [02-lists][82], slides [1][82] to [27][1020507] ([recording][208]) |
|9 | Sep&nbsp;14 | Monday    | [Lab 3: Stacks][3] ([md][23]) / [Tutorial 3: More UNIX, part 1][63], introduction and sections 1-4 | [02: Lists][82], [03: Numbers][83] | [02-lists][82], slides [28][1020508] to [56][1020803] ([recording][209]) |
|10| Sep&nbsp;16 | Wednesday | | [03: Numbers][83] | [03: Numbers][83], slides [1][83] to [30][1030608] ([recording][210]) |
|11| Sep&nbsp;18 | Friday    | | [03: Numbers][83] | [03: Numbers][83], slides [31][10307] to [49][1030809] ([recording][211]) |
|12| Sep&nbsp;21 | Monday    | [Lab 4: Numbers][4] ([md][24]) / [Tutorial 4: More UNIX, part 2][64], sections 5-8 | [03: Numbers][83] | [03: Numbers][83], slides [50][1030810] to [65][1030825] ([recording][212]) |
|13| Sep&nbsp;23 | Wednesday | | [04: Arrays & big-Oh][84] | [03: Numbers][83], slides [65][1030825] to [73][1030833] (end); [04: Arrays & Big-Oh][84], slides [1][84] to [15][1040311] ([recording][214]) |
|14| Sep&nbsp;25 | Friday    | | [04: Arrays & big-Oh][84] | [04: Arrays & Big-Oh][84], slides [16][10404] to [25][1040409] ([recording][215]) |
|  | Sep&nbsp;27 | Sunday    | | Exam 1 review session | ([recording][217]) |
|15| Sep&nbsp;28 | Monday    | Exam 1 instead during Tuesday's lab | [04: Arrays & big-Oh][84], [05: Trees][85] | [04: Arrays & Big-Oh][84], slides [26][1040410] to [58][1040507] ([recording][216]) |
|16| Sep&nbsp;30 | Wednesday | | [05: Trees][85] | [05: Trees][85], slides [1][85] to [30][1050410] ([recording][218]) |
|17| Oct&nbsp;2  | Friday    | | [05: Trees][85] | [05: Trees][85], slides [30][1050410] to [64][1050609] ([recording][219]) |
|  | Oct&nbsp;5  | Monday    | no lab this week due to fall break | no class (fall break) | No lecture today (fall break) |
|18| Oct&nbsp;7  | Wednesday | | [05: Trees][85] | [05: Trees][85], slides [65][1050610] to [85][1050630] (see below this table for details about the recording) |
|19| Oct&nbsp;9  | Friday    | | [05: Trees][85] | [05: Trees][85], slides [86][10507] to [99][1050801] ([recording][221]) |
|20| Oct&nbsp;12 | Monday    | [Lab 5: Trees][5] ([md][25]) / [Tutorial 5: make][45] ([md][65]) | [06: Hashes][86] | [05: Trees][85], slides [100][1050802] to [116][1050909] (end); [06: Hashes][86], slides [1][86] to [18][1060404] ([recording][223]) |
|21| Oct&nbsp;14 | Wednesday | | [06: Hashes][86] | [06: Hashes][86], slides [19][1060405] to [36][1060507] ([recording][224]) |
|22| Oct&nbsp;16 | Friday    | | [06: Hashes][86], [07: IBCM][87] (machine language) | [06: Hashes][86], slides [37][10606] to [48][1060611] ([recording][225]) |
|23| Oct&nbsp;19 | Monday    | [Lab 6: Hashes][6] ([md][26]) / Tutorial 6: Shell scripting, part 1 (part of [this link][46]; the specific sections are mentioned on the [tutorials page][40]) | [07: IBCM][87] (machine language) | [06: Hashes][86], slides [49][10607] to [55][1060706] (end); [07: IBCM][87], slides [1][87] to [18][1070407] ([recording][226]) |
|24| Oct&nbsp;21 | Wednesday | | [07: IBCM][87] (machine language) | [07: IBCM][87], slides [15][1070404] to [30][1070503] ([recording][227]) |
|25| Oct&nbsp;23 | Friday    | | [07: IBCM][87] (machine language) | [07: IBCM][87], slides [30][1070503] to [40][1070601] ([recording][228]) |
|26| Oct&nbsp;26 | Monday    | [Lab 7: IBCM][7] ([md][27]) / Tutorial 7: Shell scripting, part 2 (remainder of [here][47], as described on the [tutorials page][40]) | [08: x86][88] (assembly language) | [07: IBCM][87], slides [40][1070601] to [48][1070609] (end); [08: x86][88], slides [1][88] to [10][1080306] ([recording][230]) |
|27| Oct&nbsp;28 | Wednesday | | [08: x86][88] (assembly language) | [08: x86][88], slides [10][1080306] to [31][1080502] ([recording][231]) |
|28| Oct&nbsp;30 | Friday    | | [08: x86][88] (assembly language) | [08: x86][88], slides [31][1080502] to [51][1080609] ([recording][232]) |
|29| Nov&nbsp;2  | Monday    | [Lab 8: x86, part 1][8] ([md][28]) / Tutorial 8: nasm, which is two book chapters: [1][53] and [2][54] | [08: x86][88] (assembly language) | [08: x86][88], slides [52][10807] to [65][1080713] ([recording][233]) |
|30| Nov&nbsp;4  | Wednesday | | [08: x86][88], [09: Advanced C++][89] | [08: x86][88], slides [66][10808] to [86][1080914] ([recording][234]) |
|31| Nov&nbsp;6  | Friday    | | [09: Advanced C++][89] | [08: x86][88], slides [87][1080915] to [106][1080934] ([recording][235]) |
|  | Nov&nbsp;8  | Sunday    | | Exam 2 review session | ([recording][238]) |
|32| Nov&nbsp;9  | Monday    | Exam 2 instead during Tuesday's lab | [09: Advanced C++][89] | [09: Advanced C++][89], slides [25][10905] to [46][1090521] ([recording][236]) |
|33| Nov&nbsp;11 | Wednesday | | [09: Advanced C++][89], [10: Heaps and Huffman coding][90]| [09: Advanced C++][89], slides [47][10906] to [65][1090711] (end) ([recording][237]) |
|34| Nov&nbsp;13 | Friday    | | [10: Heaps and Huffman coding][90] | [10: Heaps and Huffman coding][90], slides [1][90] to [15][1100407] ([recording][240]) |
|35| Nov&nbsp;16 | Monday    | [Lab 9: x86, part 2][9] ([md][29]) / [Tutorial 9: C][49] ([md][69]) | [10: Heaps and Huffman coding][90] | [10: Heaps and Huffman coding][90], slides [14][1100406] to [29][1100512] ([recording][241]) |
|36| Nov&nbsp;18 | Wednesday | | [10: Heaps and Huffman coding][90], [11: Graphs][91] | [10: Heaps and Huffman coding][90], slides [29][1100512] to [46][1100705] ([recording][242]) |
|37| Nov&nbsp;20 | Friday    | | [11: Graphs][91] | [10: Heaps and Huffman coding][90], slides [47][1100706] to [80][1100808] (end) ([recording][243]) |
|38| Nov&nbsp;23 | Monday    | [Lab 10: Huffman coding][10] ([md][30]) / (no tutorial) | [11: Graphs][91] | |
|  | Nov&nbsp;25 | Wednesday | | no class (Thanksgiving break) | No lecture today (Thanksgiving break) |
|  | Nov&nbsp;27 | Friday    | | no class (Thanksgiving break) | No lecture today (Thanksgiving break) |
|39| Nov&nbsp;30 | Monday    | [Lab 11: Graphs][11] ([md][31]) / [Tutorial 11: doxygen][51] ([md][71]) | [11: Graphs][91] | [11: Graphs][91], slides [1][91] to [26][1110408] ([recording][244]) |
|40| Dec&nbsp;2  | Wednesday | | [11: Graphs][91], [12: Memory][92] | [11: Graphs][91], slides [27][11105] to [40][1110513] and [47][11107] to [55][1110708] ([recording][245]) |
|41| Dec&nbsp;4  | Friday    | | [12: Memory][92] | [11: Graphs][91], slides [41][11106] to [46][1110605] and [56][11108] to [70][1110814] (end); [12: Memory][92], slides [1][92] to [8][1120304] ([recording][248]) |
|42| Dec&nbsp;7  | Monday    | [Lab 12: Objective C][12] ([md][32])| [12: Memory][92], [13: Esoteric PLs][93], [Course conclusion][94] | [12: Memory][92], slides [8][1120304] to [29][1120325] ([recording][249]) |
|  | Dec&nbsp;9  | Wednesday | | Final exam review session | |
|  | Dec&nbsp;11 | Friday    | Final exam from 9:00-noon in Gilmer 130| Final exam from 9:00-noon in Gilmer 130 | |

On Wednesday, Ocrober 7th, Mark Floryan covered class, and the lecture was not recorded.  What is posted instead are the lectures from last semester (spring 2015) that covered the same material.  Because the two semesters were slightly out of sync with each other, the material was covered across two lectures: [05-trees-3-spring-2015](https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-3-spring-2015/05-trees-3.htm), starting at 33:37, and [05-trees-4-spring-2015](https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-4-spring-2015/05-trees-4.htm), ending at 30:57.  Because of a difference in the verions of the slide software, the slide numbers won't match up.

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
[53]: ../book/x86-asm-chapter.pdf
[54]: ../book/x86-ccc-chapter.pdf

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
[88]: ../slides/08-x86.html#/
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
[111]: ../README.html
[112]: ../README.md
[113]: exam-review.html#/
[114]: unix-honor-pledge.tex
[115]: grades.md
[116]: grades.html

[150]: https://www.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&amp;amp;ctz=America/New_York
[151]: http://twitter.com/UVaCS2150
[152]: https://piazza.com/

[160]: https://libra.cs.virginia.edu/~pedagogy/
[161]: https://libra.cs.virginia.edu/~pedagogy/support.php
[162]: https://libra.cs.virginia.edu/~pedagogy/submit.php
[163]: https://libra.cs.virginia.edu/~pedagogy/regrades.php
[164]: https://libra.cs.virginia.edu/~pedagogy/gradebook.php
[165]: https://libra.cs.virginia.edu/~pedagogy/labextension.php
[166]: https://libra.cs.virginia.edu/~pedagogy/queue.php

[170]: https://collab.itc.virginia.edu/portal/site/415219f8-1a72-4ade-a753-b37ec6aecb61/page/5bb93f34-d7a2-4171-b177-e4a2608999c3
[171]: https://collab.itc.virginia.edu/portal/site/415219f8-1a72-4ade-a753-b37ec6aecb61/page/cf081a8e-49ca-4fd5-8f6b-5399dafb7268
[172]: unix-honor-pledge-f15.pdf
[173]: https://collab.itc.virginia.edu/portal/directtool/15f4bf06-5c89-49a4-a76c-db52df940b31/

[201]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/course-introduction-1/course-introduction-1.htm
[202]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-1/01-cpp-1.htm
[203]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-2/01-cpp-2.htm
[204]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-3/01-cpp-3.htm
[205]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-4/01-cpp-4.htm
[206]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-5/01-cpp-5.htm
[207]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/01-cpp-6/01-cpp-6.htm
[208]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/02-lists-1/02-lists-1.htm
[209]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/02-lists-2/02-lists-2.htm
[210]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/03-numbers-1/03-numbers-1.htm
[211]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/03-numbers-2/03-numbers-2.htm
[212]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/03-numbers-3/03-numbers-3.htm
[213]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/03-numbers-4/03-numbers-4.htm
[214]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/04-arrays-bigoh-1/04-arrays-bigoh-1.htm
[215]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/04-arrays-bigoh-2/04-arrays-bigoh-2.htm
[216]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/04-arrays-bigoh-3/04-arrays-bigoh-3.htm
[217]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/exam1-review/exam1-review.htm
[218]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-1/05-trees-1.htm
[219]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-2/05-trees-2.htm
[220]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-3/05-trees-3.htm
[221]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-4/05-trees-4.htm
[222]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/05-trees-5/05-trees-5.htm
[223]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/06-hashes-1/06-hashes-1.htm
[224]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/06-hashes-2/06-hashes-2.htm
[225]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/06-hashes-3/06-hashes-3.htm
[226]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/07-ibcm-1/07-ibcm-1.htm
[227]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/07-ibcm-2/07-ibcm-2.htm
[228]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/07-ibcm-3/07-ibcm-3.htm
[229]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/07-ibcm-4/07-ibcm-4.htm
[230]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-1/08-x86-1.htm
[231]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-2/08-x86-2.htm
[232]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-3/08-x86-3.htm
[233]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-4/08-x86-4.htm
[234]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-5/08-x86-5.htm
[235]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/08-x86-6/08-x86-6.htm
[236]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/09-advanced-cpp-1/09-advanced-cpp-1.htm
[237]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/09-advanced-cpp-2/09-advanced-cpp-2.htm
[238]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/exam2-review/exam2-review.htm
[239]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/09-advanced-cpp-3/09-advanced-cpp-3.htm
[240]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/10-heaps-huffman-1/10-heaps-huffman-1.htm
[241]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/10-heaps-huffman-2/10-heaps-huffman-2.htm
[242]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/10-heaps-huffman-3/10-heaps-huffman-3.htm
[243]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/10-heaps-huffman-4/10-heaps-huffman-4.htm
[244]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/11-graphs-1/11-graphs-1.htm
[245]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/11-graphs-2/11-graphs-2.htm
[246]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/11-graphs-3/11-graphs-3.htm
[247]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/11-graphs-4/11-graphs-4.htm
[248]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/12-memory-1/12-memory-1.htm
[249]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/12-memory-2/12-memory-2.htm
[250]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/12-memory-3/12-memory-3.htm
[251]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/course-conclusion/course-conclusion.htm
[252]: https://collab.itc.virginia.edu/access/content/group/415219f8-1a72-4ade-a753-b37ec6aecb61/lectures/final-review/final-review.htm

[1000303]: ../cs2150/course-introduction.html#/3/3
[10004]: ../cs2150/course-introduction.html#/4
[1000402]: ../cs2150/course-introduction.html#/4/2
[10005]: ../cs2150/course-introduction.html#/5
[1000601]: ../cs2150/course-introduction.html#/6/1
[1010310]: ../slides/01-cpp.html#/3/10
[1010311]: ../slides/01-cpp.html#/3/11
[1010404]: ../slides/01-cpp.html#/4/4
[10105]: ../slides/01-cpp.html#/5
[1010608]: ../slides/01-cpp.html#/6/8
[10107]: ../slides/01-cpp.html#/7
[1010809]: ../slides/01-cpp.html#/8/9
[1010815]: ../slides/01-cpp.html#/8/15
[1010816]: ../slides/01-cpp.html#/8/16
[1010912]: ../slides/01-cpp.html#/9/12
[1010913]: ../slides/01-cpp.html#/9/13
[1010914]: ../slides/01-cpp.html#/9/14
[1010915]: ../slides/01-cpp.html#/9/15
[10110]: ../slides/01-cpp.html#/10
[1011001]: ../slides/01-cpp.html#/10/1
[1011105]: ../slides/01-cpp.html#/11/5
[1011106]: ../slides/01-cpp.html#/11/6
[1011213]: ../slides/01-cpp.html#/12/13
[1020304]: ../slides/02-lists.html#/3/4
[10204]: ../slides/02-lists.html#/4
[1020507]: ../slides/02-lists.html#/5/7
[1020508]: ../slides/02-lists.html#/5/8
[1020606]: ../slides/02-lists.html#/6/6
[1020607]: ../slides/02-lists.html#/6/7
[1020803]: ../slides/02-lists.html#/8/3
[1030403]: ../slides/03-numbers.html#/4/3
[1030404]: ../slides/03-numbers.html#/4/4
[10307]: ../slides/03-numbers.html#/7
[1030608]: ../slides/03-numbers.html#/6/8
[1030801]: ../slides/03-numbers.html#/8/1
[1030809]: ../slides/03-numbers.html#/8/9
[1030810]: ../slides/03-numbers.html#/8/10
[1030816]: ../slides/03-numbers.html#/8/16
[1030825]: ../slides/03-numbers.html#/8/25
[1030832]: ../slides/03-numbers.html#/8/32
[1030833]: ../slides/03-numbers.html#/8/33
[1040311]: ../slides/04-arrays-bigoh.html#/3/11
[10404]: ../slides/04-arrays-bigoh.html#/4
[1040402]: ../slides/04-arrays-bigoh.html#/4/2
[1040403]: ../slides/04-arrays-bigoh.html#/4/3
[1040409]: ../slides/04-arrays-bigoh.html#/4/9
[1040410]: ../slides/04-arrays-bigoh.html#/4/10
[1040419]: ../slides/04-arrays-bigoh.html#/4/19
[1040420]: ../slides/04-arrays-bigoh.html#/4/20
[1040507]: ../slides/04-arrays-bigoh.html#/5/7
[1050305]: ../slides/05-trees.html#/3/5
[1050306]: ../slides/05-trees.html#/3/6
[1050311]: ../slides/05-trees.html#/3/11
[1050410]: ../slides/05-trees.html#/4/10
[1050415]: ../slides/05-trees.html#/4/15
[1050416]: ../slides/05-trees.html#/4/16
[1050417]: ../slides/05-trees.html#/4/17
[1050609]: ../slides/05-trees.html#/6/9
[1050610]: ../slides/05-trees.html#/6/10
[1050612]: ../slides/05-trees.html#/6/12
[1050617]: ../slides/05-trees.html#/6/17
[1050630]: ../slides/05-trees.html#/6/30
[10507]: ../slides/05-trees.html#/7
[1050703]: ../slides/05-trees.html#/7/3
[1050709]: ../slides/05-trees.html#/7/9
[1050711]: ../slides/05-trees.html#/7/11
[10508]: ../slides/05-trees.html#/8
[1050801]: ../slides/05-trees.html#/8/1
[1050802]: ../slides/05-trees.html#/8/2
[1050909]: ../slides/05-trees.html#/9/9
[1060413]: ../slides/06-hashes.html#/4/13
[1060401]: ../slides/06-hashes.html#/4/1
[1060404]: ../slides/06-hashes.html#/4/4
[1060405]: ../slides/06-hashes.html#/4/5
[10605]: ../slides/06-hashes.html#/5
[1060502]: ../slides/06-hashes.html#/5/2
[1060507]: ../slides/06-hashes.html#/5/7
[10606]: ../slides/06-hashes.html#/6
[1060608]: ../slides/06-hashes.html#/6/8
[1060609]: ../slides/06-hashes.html#/6/9
[1060611]: ../slides/06-hashes.html#/6/11
[10607]: ../slides/06-hashes.html#/7
[1060702]: ../slides/06-hashes.html#/7/2
[1060706]: ../slides/06-hashes.html#/7/6
[1070302]: ../slides/07-ibcm.html#/3/2
[1070303]: ../slides/07-ibcm.html#/3/3
[1070401]: ../slides/07-ibcm.html#/4/1
[1070402]: ../slides/07-ibcm.html#/4/2
[1070404]: ../slides/07-ibcm.html#/4/4
[1070407]: ../slides/07-ibcm.html#/4/7
[1070415]: ../slides/07-ibcm.html#/4/15
[10705]: ../slides/07-ibcm.html#/5
[1070503]: ../slides/07-ibcm.html#/5/3
[1070505]: ../slides/07-ibcm.html#/5/5
[1070506]: ../slides/07-ibcm.html#/5/6
[1070511]: ../slides/07-ibcm.html#/5/11
[1070601]: ../slides/07-ibcm.html#/6/1
[1070604]: ../slides/07-ibcm.html#/6/4
[1070609]: ../slides/07-ibcm.html#/6/9
[1080306]: ../slides/08-x86.html#/3/6
[1080410]: ../slides/08-x86.html#/4/10
[1080304]: ../slides/08-x86.html#/3/4
[1080305]: ../slides/08-x86.html#/3/5
[10805]: ../slides/08-x86.html#/5
[1080502]: ../slides/08-x86.html#/5/2
[1080504]: ../slides/08-x86.html#/5/4
[1080505]: ../slides/08-x86.html#/5/5
[1080607]: ../slides/08-x86.html#/6/7
[1080608]: ../slides/08-x86.html#/6/8
[1080609]: ../slides/08-x86.html#/6/9
[10807]: ../slides/08-x86.html#/7
[1080713]: ../slides/08-x86.html#/7/13
[10808]: ../slides/08-x86.html#/8
[1080804]: ../slides/08-x86.html#/8/4
[1080805]: ../slides/08-x86.html#/8/5
[10809]: ../slides/08-x86.html#/9
[1080914]: ../slides/08-x86.html#/9/14
[1080915]: ../slides/08-x86.html#/9/15
[1080929]: ../slides/08-x86.html#/9/29
[1080930]: ../slides/08-x86.html#/9/30
[1080932]: ../slides/08-x86.html#/9/32
[1080934]: ../slides/08-x86.html#/9/34
[1090308]: ../slides/09-advanced-cpp.html#/3/8
[10905]: ../slides/09-advanced-cpp.html#/5
[1090508]: ../slides/09-advanced-cpp.html#/5/8
[1090509]: ../slides/09-advanced-cpp.html#/5/9
[1090518]: ../slides/09-advanced-cpp.html#/5/18
[1090519]: ../slides/09-advanced-cpp.html#/5/19
[1090520]: ../slides/09-advanced-cpp.html#/5/20
[1090521]: ../slides/09-advanced-cpp.html#/5/21
[10906]: ../slides/09-advanced-cpp.html#/6
[1090708]: ../slides/09-advanced-cpp.html#/7/8
[1090710]: ../slides/09-advanced-cpp.html#/7/10
[1090711]: ../slides/09-advanced-cpp.html#/7/11
[1100406]: ../slides/10-heaps-huffman.html#/4/6
[1100407]: ../slides/10-heaps-huffman.html#/4/7
[1100408]: ../slides/10-heaps-huffman.html#/4/8
[11005]: ../slides/10-heaps-huffman.html#/5
[1100503]: ../slides/10-heaps-huffman.html#/5/3
[1100508]: ../slides/10-heaps-huffman.html#/5/8
[1100512]: ../slides/10-heaps-huffman.html#/5/12
[1100605]: ../slides/10-heaps-huffman.html#/6/5
[1100606]: ../slides/10-heaps-huffman.html#/6/6
[1100705]: ../slides/10-heaps-huffman.html#/7/5
[1100706]: ../slides/10-heaps-huffman.html#/7/6
[1100730]: ../slides/10-heaps-huffman.html#/7/30
[11008]: ../slides/10-heaps-huffman.html#/8
[1100808]: ../slides/10-heaps-huffman.html#/8/8
[1110304]: ../slides/11-graphs.html#/3/4
[1110305]: ../slides/11-graphs.html#/3/5
[1110402]: ../slides/11-graphs.html#/4/2
[11104]: ../slides/11-graphs.html#/4
[1110408]: ../slides/11-graphs.html#/4/8
[11105]: ../slides/11-graphs.html#/5
[1110508]: ../slides/11-graphs.html#/5/8
[1110509]: ../slides/11-graphs.html#/5/9
[1110513]: ../slides/11-graphs.html#/5/13
[11106]: ../slides/11-graphs.html#/6
[1110605]: ../slides/11-graphs.html#/6/5
[11107]: ../slides/11-graphs.html#/7
[1110708]: ../slides/11-graphs.html#/7/8
[11108]: ../slides/11-graphs.html#/8
[1110806]: ../slides/11-graphs.html#/8/6
[1110814]: ../slides/11-graphs.html#/8/14
[1120303]: ../slides/12-memory.html#/3/3
[1120304]: ../slides/12-memory.html#/3/4
[1120308]: ../slides/12-memory.html#/3/8
[1120311]: ../slides/12-memory.html#/3/11
[1120325]: ../slides/12-memory.html#/3/25
[1120407]: ../slides/12-memory.html#/4/7
[1120418]: ../slides/12-memory.html#/4/18
[1130325]: ../slides/13-esoteric-pls.html#/3/25
[1130512]: ../slides/13-esoteric-pls.html#/5/12
[12009]: course-conclusion.html#/9
[12010]: course-conclusion.html#/10
