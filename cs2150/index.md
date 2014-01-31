CS 2150: Program and Data Representation
========================================

[Go up to the main README file](../README.html)

Much of the rest of this git repo is meant to be generic to anybody
who has a class such as this one.  But this page contains details
specific to the spring 2014 version of CS 2150 at the University of
Virginia.

Links
-----

There are a number of links and other parts of this course that are
**NOT** included in this repository.  They are:

- The set of online tools, which can be accesed through Collab or [here](https://libra.cs.virginia.edu/~pedagogy/).
  - These tools are:
    [support requests](https://libra.cs.virginia.edu/~pedagogy/support.php), 
    [lab submission](https://libra.cs.virginia.edu/~pedagogy/submit.php), 
    [regrades](https://libra.cs.virginia.edu/~pedagogy/regrades.php), 
    [gradebook](https://libra.cs.virginia.edu/~pedagogy/gradebook.php), and 
    [lab extensions](https://libra.cs.virginia.edu/~pedagogy/labextension.php)
- The announcements, which are posted to the CS 2150 twitter feed:
  [@UVaCS2150](http://twitter.com/UVaCS2150)
- The [CS 2150 Google 
  calendar](https://www.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&amp;amp;ctz=America/New_York)
- Grading explanations, including the grading guidelines; this is
  availabe in the Collab wiki
 ([here](https://collab.itc.virginia.edu/portal/site/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/page/618f97d9-06f2-4da8-8197-5ddadbbc9f51)
  is the direct link, although Collab login is required)
- Email list archive, which is a Collab tool
  ([here](https://collab.itc.virginia.edu/portal/site/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/page/770a28a5-0679-405a-913a-49301c5c9a60)
  is the direct link, although Collab login is required)
- [Piazza](https://piazza.com/); Collab can log you in directly.

The parts of this course that are in this repo are:

- [Daily announcements slide set](daily-announcements.html)
- [Course syllabus](syllabus.html): the course syllabus
- [Lab due dates](labduedates.html): When the various lab parts
  are due
- [UNIX honor pledge](unix-honor-pledge-s14.pdf), which needs to be
  signed by all the students in the course; it is created from a
  [.tex](unix-honor-pledge.tex) file

Labs and Tutorials
------------------

This is a series of links to the labs and tutorials that are elsewhere
in this repository.  A bunch of notes:

- The lab parts are all due on specific times throughout the week, as
  detailed on the [lab due dates](labduedates.html) page
  - Each lab is for a given week, which (for sake of argument) we
    claim starts on a Monday
  - Which lab is done on which week is listed below in the semester
    schedule
- The lab is released the week before, typically on a Wednesday or
  Thursday
  - While a version of the lab will be in this github repo for
    some time prior, there **WILL** be modifications to that lab up
    until the "official" release, which is when it is announced as
    released on the twitter feed:
    [@UVaCS2150](http://twitter.com/UVaCS2150)
- All the labs and tutorials can be found on the [labs
  page](../labs/index.html) and the [tutorials
  page](../tutorials/index.html).  
  - In particular, these pages have additional details and links not
    described here
- Note that as this repository is being filled out throughout the spring
  2014 semester, many of these links will not work until later in the
  semester
  - And many of the links that do work may be incomplete or only
    partially formed

------------------------------------------------------------

Semester Schedule
-----------------

The links in the right-most column link directly to the lecture
recording on Collab, and you have to be logged into Collab first
before the link will work. Some plugins (such as NoScript) will block
that link from working.  Unless otherwise indicated, both lectures
stopped at the same point.

| Num |&nbsp;| Date |&nbsp;| Day of week |&nbsp;| Lab & Tutorial |&nbsp;| Planned topic |&nbsp;| Actual lecture progress (and recording) |
|-----||--------||-------------||----------------------------------------------------------||--------------------------||--------------------------|
| 1 || Jan&nbsp;13 || Monday || no lab this week || [01: Course introduction](../slides/01-intro.html) || [01: course introduction, slide 1 to slide 5-6](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/01-intro-1b/01-intro-1b.htm) (sorry, the problem with the recording cannot be fixed) |
| 2 || Jan&nbsp;15 || Wednesday || || [01: Course introduction](../slides/01-intro.html), [02: C++](../slides/02-cpp.html) || [01: course introduction, slides 5-7 to 6-1 (end); 02: C++, slides 1 to 3-4](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/02-cpp-1b/02-cpp-1b.htm) |
| 3 || Jan&nbsp;17 || Friday || || [02: C++](../slides/02-cpp.html) || [02: C++, slides 4 to 6-4](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/02-cpp-2b/02-cpp-2b.htm) |
| || Jan&nbsp;20 || Monday || [Lab 1: Intro to C++](../labs/lab01/index.html) / [Tutorial 1: Intro to UNIX](../tutorials/01-intro-unix/index.html) || (no class: MLK day) || (no class: MLK day) |
| 4 || Jan&nbsp;22 || Wednesday || || [02: C++](../slides/02-cpp.html) || [02: C++, slides 7 to 8-6](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/02-cpp-3b/02-cpp-3b.htm) (the sound for the [Youtube video](http://www.youtube.com/watch?v=UvoHwFvAvQE) is not synchronized with the lecture recording) |
| 5 || Jan&nbsp;24 || Friday || || [02: C++](../slides/02-cpp.html) || [02: C++, slides 8-6 to 9-1](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/02-cpp-4b/02-cpp-4b.htm) |
| 6 || Jan&nbsp;27 || Monday || [Lab 2: Linked lists](../labs/lab02/index.html) / [Tutorial 2: GDB](../tutorials/02-gdb/index.html) || [02: C++](../slides/02-cpp.html) || [02: C++, slides 9-1 to  10-11](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/02-cpp-5b/02-cpp-5b.htm) (we aren't going over the remainder of the slides in lecture) |
| 7 || Jan&nbsp;29 || Wednesday || || [03: Lists](../slides/03-lists.html) || [03: Lists, slides 1 to 5-8](https://collab.itc.virginia.edu/access/content/group/7d8b39e0-ac9d-48c1-ab42-c3ca20dfb23c/lectures/03-lists-1b/03-lists-1b.htm) |
| 8 || Jan&nbsp;31 || Friday || || [03: Lists](../slides/03-lists.html) || |
| 9 || Feb&nbsp;3 || Monday || [Lab 3: Stacks](../labs/lab03/index.html) / [Tutorial 3: More UNIX, part 1](../tutorials/03-04-more-unix/index.html), sections 1-4 || [03: Lists](../slides/03-lists.html), [04: Numbers](../slides/04-numbers.html) || |
| 10 || Feb&nbsp;5 || Wednesday || || [04: Numbers](../slides/04-numbers.html) || |
| 11 || Feb&nbsp;7 || Friday || || [04: Numbers](../slides/04-numbers.html) || |
| 12 || Feb&nbsp;10 || Monday || [Lab 4: Numbers](../labs/lab04/index.html) / [Tutorial 4: More UNIX, part 2](../tutorials/03-04-more-unix/index.html), sections 5-8 || [04: Numbers](../slides/04-numbers.html) || |
| 13 || Feb&nbsp;12 || Wednesday || || [05: Arrays & big-Oh](../slides/05-arrays-big-oh.html) || |
| 14 || Feb&nbsp;14 || Friday || || [05: Arrays & big-Oh](../slides/05-arrays-big-oh.html) || |
| 15 || Feb&nbsp;17 || Monday || Midterm 1 instead during Tuesday's lab || [06: Trees](../slides/06-trees.html) || |
| 16 || Feb&nbsp;19 || Wednesday || || [06: Trees](../slides/06-trees.html) || |
| 17 || Feb&nbsp;21 || Friday || || [06: Trees](../slides/06-trees.html) || |
| 18 || Feb&nbsp;24 || Monday || [Lab 5: Trees](../labs/lab05/index.html) / [Tutorial 5: make](../tutorials/05-make/index.html) || [06: Trees](../slides/06-trees.html) || |
| 19 || Feb&nbsp;26 || Wednesday || || [07: Hashes](../slides/07-hashes.html) || |
| 20 || Feb&nbsp;28 || Friday || || [07: Hashes](../slides/07-hashes.html) || |
| 21 || Mar&nbsp;3 || Monday || [Lab 6: Hashes](../labs/lab06/index.html) / [Tutorial 6: Shell scripting, part 1](../tutorials/06-shell-scripts-pt1/index.html) || [07: Hashes](../slides/07-hashes.html) || |
| 22 || Mar&nbsp;5 || Wednesday || || [08: IBCM](../slides/08-ibcm.html) (machine language) || |
| 23 || Mar&nbsp;7 || Friday || || [08: IBCM](../slides/08-ibcm.html) (machine language) || |
| || Mar&nbsp;10 || Monday || no labs (spring break) || (no class: spring break) || (no class: spring break) |
| || Mar&nbsp;12 || Wednesday || || (no class: spring break) || (no class: spring break) |
| || Mar&nbsp;14 || Friday || || (no class: spring break) || (no class: spring break) |
| 24 || Mar&nbsp;17 || Monday || [Lab 7: IBCM](../labs/lab07/index.html) / [Tutorial 7: Shell scripting, part 2](../tutorials/07-shell-scripts-pt2/index.html) || [08: IBCM](../slides/08-ibcm.html) (machine language) || |
| 25 || Mar&nbsp;19 || Wednesday || || [09: x86](../slides/09-x86.html) (assembly language) || |
| 26 || Mar&nbsp;21 || Friday || || [09: x86](../slides/09-x86.html) (assembly language) || |
| 27 || Mar&nbsp;24 || Monday || [Lab 8: x86, part 1](../labs/lab08/index.html) / [Tutorial 8: nasm](../tutorials/08-nasm/index.html) || [09: x86](../slides/09-x86.html) (assembly language) || |
| 28 || Mar&nbsp;26 || Wednesday || || [09: x86](../slides/09-x86.html) (assembly language) || |
| 29 || Mar&nbsp;28 || Friday || || [09: x86](../slides/09-x86.html) (assembly language) || |
| 30 || Mar&nbsp;31 || Monday || Midterm 2 instead during Tuesday's lab || [09: x86](../slides/09-x86.html), [10: Advanced C++](../slides/10-advanced-cpp.html) || |
| 31 || Apr&nbsp;2 || Wednesday || || [10: Advanced C++](../slides/10-advanced-cpp.html) || |
| 32 || Apr&nbsp;4 || Friday || || [11: Heaps](../slides/11-heaps.html) || |
| 33 || Apr&nbsp;7 || Monday || [Lab 9: x86, part 2](../labs/lab09/index.html) / [Tutorial 9: C](../tutorials/09-c/index.html) || [12: Huffman coding](../slides/12-huffman.html) || |
| 34 || Apr&nbsp;9 || Wednesday || || [12: Huffman coding](../slides/12-huffman.html) || |
| 35 || Apr&nbsp;11 || Friday || || [13: Graphs](../slides/13-graphs.html) || |
| 36 || Apr&nbsp;14 || Monday || [Lab 10: Huffman coding](../labs/lab10/index.html) / [Tutorial 10: Objective C](../tutorials/10-objc/index.html) || [13: Graphs](../slides/13-graphs.html) || |
| 37 || Apr&nbsp;16 || Wednesday || || [13: Graphs](../slides/13-graphs.html) || |
| 38 || Apr&nbsp;18 || Friday || || [13: Graphs](../slides/13-graphs.html) || |
| 39 || Apr&nbsp;21 || Monday || [Lab 11: Graphs](../labs/lab11/index.html) / [Tutorial 11: doxygen](../tutorials/11-doxygen/index.html) || [13: Graphs](../slides/13-graphs.html) || |
| 40 || Apr&nbsp;23 || Wednesday || || [13: Graphs](../slides/13-graphs.html), [14: Memory](../slides/14-memory.html) || |
| 41 || Apr&nbsp;25 || Friday || || [14: Memory](../slides/14-memory.html) || |
| 42 || Apr&nbsp;28 || Monday || [Lab 12: Conclusion](../labs/lab12/index.html) / (no tutorial for this lab) || [15: AOP](../slides/15-aop.html), [16: Course conclusion](../slides/16-conclusion.html) || |
