Program and Data Representation: CS 2150 Specific Content
=========================================================

[Go up to the main README file](../README.html) ([md](../README.md))

Much of the rest of this git repo is meant to be generic to anybody who has a class such as this one.  But this page contains details specific to the spring 2014 version of CS 2150 at the University of Virginia.

------------------------------------------------------------

Links
-----

There are a number of links and other parts of this course that are **NOT** included in this repository.  They are:

- The set of online tools, which can be accessed through Collab or [here](https://libra.cs.virginia.edu/~pedagogy/).
    - These tools are: [support requests](https://libra.cs.virginia.edu/~pedagogy/support.php), [lab submission](https://libra.cs.virginia.edu/~pedagogy/submit.php), [regrades](https://libra.cs.virginia.edu/~pedagogy/regrades.php), [gradebook](https://libra.cs.virginia.edu/~pedagogy/gradebook.php), and [lab extensions](https://libra.cs.virginia.edu/~pedagogy/labextension.php)
    - Note that Netbadge login is not yet working on these yet -- you will have to authenticate through Collab
- The announcements, which are posted to the CS 2150 twitter feed: [\@UVaCS2150](http://twitter.com/UVaCS2150)
- The [CS 2150 Google calendar](https://www.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&amp;amp;ctz=America/New_York)
- Grading explanations, including the grading guidelines; this is available in the Collab wiki ([here](https://collab.itc.virginia.edu/portal/site/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/page/25e168d5-b7fc-4d8d-a021-4d39eda4e0aa) is the direct link, although Collab login is required)
- Email list archive, which is a Collab tool ([here](https://collab.itc.virginia.edu/portal/site/e41b1a2b-7c8d-4efc-b0eb-7875133f9d3a/page/25c10fb2-1f3c-451a-a614-931012320919) is the direct link, although Collab login is required)
- [Piazza](https://piazza.com/); Collab can log you in directly.

The parts of this course that are in this repo are:

- [Daily announcements slide set](daily-announcements.html)
- [Course introduction slide set](course-introduction.html)
- [Course syllabus](syllabus.html) ([md](syllabus.md)): the course syllabus
- [Lab due dates](labduedates.html) ([md](labduedates.md)): When the various lab parts are due
- [UNIX honor pledge](unix-honor-pledge-f14.pdf), which needs to be signed by all the students in the course; it is created from a [.tex](unix-honor-pledge.tex) file
- [Generic review session slide set](exam-review.html), which is really just a blank set of slides
- [Frivolous regrade policy](frivolous-regrades.html) ([md](frivolous-regrades.html)) for exams

------------------------------------------------------------

Labs and Tutorials
------------------

This is a series of links to the labs and tutorials that are elsewhere in this repository.  A bunch of notes:

- The lab parts are all due on specific times throughout the week, as detailed on the [lab due dates](labduedates.html) ([md](labduedates.md)) page
    - Each lab is for a given week, which (for sake of argument) we claim starts on a Monday
    - Which lab is done on which week is listed below in the semester schedule
- The lab is released the week before, typically on a Wednesday or Thursday
    - While a version of the lab will be in this github repo for some time prior, there **WILL** be modifications to that lab up until the "official" release, which is when it is announced as released on the twitter feed: [\@UVaCS2150](http://twitter.com/UVaCS2150)
- All the labs and tutorials can be found on the [labs page](../labs/index.html) ([md](../tutorials/index.md)) and the [tutorials page](../tutorials/index.html) ([md](../tutorials/index.md)).
    - In particular, these pages have additional details and links not described here
- Note that as this repository is being filled out throughout the spring 2014 semester, many of these links will not work until later in the semester
    - And many of the links that do work may be incomplete or only partially formed

------------------------------------------------------------

Semester Schedule
-----------------

The links in the right-most column link directly to the lecture recording on Collab, and you have to be logged into Collab first before the link will work. Some plugins (such as NoScript) will block that link from working.  Unless otherwise indicated, both lectures stopped at the same point.

| Num | Date | Day of week | Lab & Tutorial | Planned topic | Actual lecture progress (and recording) |
|-----|--------|-------------|----------------------------------------------------------|--------------------------|--------------------------|
| 1 | Aug&nbsp;27 | Wednesday | no lab this week | [Course introduction](course-introduction.html) |  |
| 2 | Aug&nbsp;29 | Friday | | [Course introduction](course-introduction.html), [01: C++](../slides/01-cpp.html) |  |
| 3 | Sep&nbsp;1 | Monday | | [01: C++](../slides/01-cpp.html) |  |
| 4 | Sep&nbsp;3 | Wednesday | [Lab 1: Intro to C++](../labs/lab01/index.html) ([md](../labs/lab01/index.md)) / [Tutorial 1: Intro to UNIX](../tutorials/01-intro-unix/index.html) ([md](../tutorials/01-intro-unix/index.md)) | (no class: MLK day) |  |
| 5 | Sep&nbsp;5 | Friday | | [01: C++](../slides/01-cpp.html) |  |
| 6 | Sep&nbsp;8 | Monday | | [01: C++](../slides/01-cpp.html) |  |
| 7 | Sep&nbsp;10 | Wednesday | [Lab 2: Linked lists](../labs/lab02/index.html) ([md](../labs/lab02/index.md)) / [Tutorial 2: GDB](../tutorials/02-gdb/index.html) ([md](../tutorials/02-gdb/index.md)) | [02: Lists](../slides/02-lists.html) |  |
| 8 | Sep&nbsp;12 | Friday | | [02: Lists](../slides/02-lists.html) |  |
| 9 | Sep&nbsp;15 | Monday | | [02: Lists](../slides/02-lists.html), [03: Numbers](../slides/03-numbers.html) |  |
| 10 | Sep&nbsp;17 | Wednesday | [Lab 3: Stacks](../labs/lab03/index.html) ([md](../labs/lab03/index.md)) / [Tutorial 3: More UNIX, part 1](../tutorials/03-04-more-unix/index.html), sections 1-4 | [03: Numbers](../slides/03-numbers.html) |  |
| 11 | Sep&nbsp;19 | Friday | | [03: Numbers](../slides/03-numbers.html) |  |
| 12 | Sep&nbsp;22 | Monday | | [03: Numbers](../slides/03-numbers.html) |  |
| 13 | Sep&nbsp;24 | Wednesday | [Lab 4: Numbers](../labs/lab04/index.html) ([md](../labs/lab04/index.md)) / [Tutorial 4: More UNIX, part 2](../tutorials/03-04-more-unix/index.html), sections 5-8 | [04: Arrays & big-Oh](../slides/04-arrays-bigoh.html) |  |
| 14 | Sep&nbsp;26 | Friday | | [04: Arrays & big-Oh](../slides/04-arrays-bigoh.html) |  |
|    | Sep&nbsp;28 | Sunday | Exam 1 review session | Exam 1 review session |  |
| 15 | Sep&nbsp;29 | Monday | | [05: Trees](../slides/05-trees.html) |  |
| 16 | Oct&nbsp;1 | Wednesday | Exam 1 instead during Tuesday's lab | [05: Trees](../slides/05-trees.html) |  |
| 17 | Oct&nbsp;3 | Friday | | [05: Trees](../slides/05-trees.html) |  |
| 18 | Oct&nbsp;6 | Monday | | [05: Trees](../slides/05-trees.html) |  |
| 19 | Oct&nbsp;8 | Wednesday | [Lab 5: Trees](../labs/lab05/index.html) ([md](../labs/lab05/index.md)) / [Tutorial 5: make](../tutorials/05-make/index.html) | [06: Hashes](../slides/06-hashes.html) |  |
| 20 | Oct&nbsp;10 | Friday | | [06: Hashes](../slides/06-hashes.html) |  |
|    | Oct&nbsp;13 | Monday | | no class (reading day) |  |
| 21 | Oct&nbsp;15 | Wednesday | no labs (reading day) | [06: Hashes](../slides/06-hashes.html) |  |
| 22 | Oct&nbsp;17 | Friday | | [07: IBCM](../slides/07-ibcm.html) (machine language) |  |
| 23 | Oct&nbsp;20 | Monday | | [07: IBCM](../slides/07-ibcm.html) (machine language) |  |
| 24 | Oct&nbsp;22 | Wednesday | [Lab 6: Hashes](../labs/lab06/index.html) ([md](../labs/lab06/index.md)) / Tutorial 6: Shell scripting, part 1 (first half of [here](http://en.wikibooks.org/wiki/Bash_Shell_Scripting), through 'exit status') | [07: IBCM](../slides/07-ibcm.html) (machine language) |  |
| 25 | Oct&nbsp;24 | Friday | | [08: x86](../slides/08-x86.html) (assembly language) |  |
| 26 | Oct&nbsp;27 | Monday | | [08: x86](../slides/08-x86.html) (assembly language) |  |
| 27 | Oct&nbsp;29 | Wednesday | [Lab 7: IBCM](../labs/lab07/index.html) ([md](../labs/lab07/index.md)) / Tutorial 7: Shell scripting, part 2 (remainder of [here](http://en.wikibooks.org/wiki/Bash_Shell_Scripting)) | [08: x86](../slides/08-x86.html) (assembly language) |  |
| 28 | Oct&nbsp;31 | Friday | | [08: x86](../slides/08-x86.html) (assembly language) |  |
|    | Nov&nbsp;2 | Sunday | Exam 2 review session | Exam 2 review session |  |
| 29 | Nov&nbsp;3 | Monday | | [08: x86](../slides/08-x86.html) (assembly language) |  |
| 30 | Nov&nbsp;5 | Wednesday | [Lab 8: x86, part 1](../labs/lab08/index.html) ([md](../labs/lab08/index.md)) / [Tutorial 8: nasm](http://cs.lmu.edu/~ray/notes/nasmexamples/), but you can skip some parts; see [here](../tutorials/index.html) ([md](../tutorials/index.md)) for details | [08: x86](../slides/08-x86.html), [09: Advanced C++](../slides/09-advanced-cpp.html) |  |
| 31 | Nov&nbsp;7 | Friday | | [09: Advanced C++](../slides/09-advanced-cpp.html) |  |
| 32 | Nov&nbsp;10 | Monday | | [10: Heaps and Huffman coding](../slides/10-heaps-huffman.html)|  |
| 33 | Nov&nbsp;12 | Wednesday | Exam 2 instead during Tuesday's lab | [10: Heaps and Huffman coding](../slides/10-heaps-huffman.html)|  |
| 34 | Nov&nbsp;14 | Friday | | [10: Heaps and Huffman coding](../slides/10-heaps-huffman.html) |  |
| 35 | Nov&nbsp;17 | Monday | | [10: Heaps and Huffman coding](../slides/10-heaps-huffman.html) |  |
| 36 | Nov&nbsp;19 | Wednesday | [Lab 9: Huffman coding](../labs/lab10/index.html) ([md](../labs/lab10/index.md)) / [Tutorial 09: Objective C](../tutorials/10-objc/index.html) ([md](../tutorials/10-objc/index.md)) | [11: Graphs](../slides/11-graphs.html) |  |
| 37 | Nov&nbsp;21 | Friday | | [11: Graphs](../slides/11-graphs.html) |  |
| 38 | Nov&nbsp;24 | Monday | | [11: Graphs](../slides/11-graphs.html) |  |
|    | Nov&nbsp;26 | Wednesday | | no class (Thanksgiving) |  |
|    | Nov&nbsp;28 | Friday | | no class (Thanksgiving) |  |
| 39 | Dec&nbsp;1 | Monday | [Lab 10: Graphs](../labs/lab11/index.html) ([md](../labs/lab11/index.md)) / [Tutorial 10: doxygen](../tutorials/11-doxygen/index.html) ([md](../tutorials/11-doxygen/index.md)) | [11: Graphs](../slides/11-graphs.html) |  |
| 40 | Dec&nbsp;3 | Wednesday | | [12: Memory](../slides/12-memory.html) |  |
| 41 | Dec&nbsp;5 | Friday | [Lab 11: Conclusion](../labs/lab12/index.html) ([md](../labs/lab12/index.md)) / (no tutorial for this lab) | [12: Memory](../slides/12-memory.html), [Course conclusion](course-conclusion.html) |  |
|    | ??? | ??? | Final exam review session | Final exam review session |  |

------------------------------------------------------------

Grading Concerns
----------------

None yet!
