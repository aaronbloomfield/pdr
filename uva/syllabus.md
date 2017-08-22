CS 2150: Program and Data Representation: Course Syllabus
=========================================================

[Go up to the CS 2150 page][1] ([md][2])

## Fall 2017

### Instructor ###

- [Mark Floryan][38] / [mrf8t@virginia.edu][39].  Office: Rice Hall, room 203.  Office hours are TBD

### Course Info ###

- Lecture: M/W/F 12:00-12:50, Thornton E303; 2:00-2:50, Maury 209
- Email: none; fill out a [support request][42] instead
- Announcement feed: [\@UVaCS2150][34]
- TAs and their office hours will be posted on the [CS 2150 Google Calendar][35] (which is also linked to via Collab); all office hours start the Sunday after classes start
- Laboratory Meetings (all in Olsson 001):
    - Section 101: Tuesday, 9:30 am -- 10:45 am
    - Section 102: Tuesday, 11:00 pm -- 12:15 pm
    - Section 103: Tuesday, 12:30 pm -- 1:45 pm
    - Section 104: Tuesday, 2:00 pm -- 3:15 pm
    - Section 105: Tuesday, 3:30 pm -- 4:45 pm
    - Section 106: Tuesday, 5:00 pm -- 6:15 pm
    - Section 107: Tuesday, 6:30 pm -- 7:45 pm

**Course Description:** This course will introduce you to program and data representation from high level concepts to machine level implementation. Data structuring techniques and the representation of data structures during program execution are discussed, as are operations and control structures and their representation during program execution. Representations of numbers, arithmetic operations, arrays, records, recursion, hashing, stacks, queues, trees, graphs, and related concepts are also covered.

**Availability:** It is important to me to be available to my students, and to address their concerns. If you cannot meet with me during office hours, e-mail and I will try to find the time to meet. That being said, like everybody else I am quite busy, so it may take a day or more to find a time to meet. And if you have any comments on the course - what is working, what is not working, what can be done better, etc. - I am very interested in hearing about them. There is an [anonymous feedback tool through Collab][37], or you can send me an e-mail (please do NOT email the TAs directly). I tend to get bogged down by e-mail as the semester progresses, so seeing me in person (right after lecture, during office hours, etc.) is often a good way to get a more immediate response.

**Prerequisites:** CS 2110 (Software Development Methods) or CS 2220 (Engineering Software); and CS 2102 (Discrete Math), all with grades of C- or above.  Note that CS 2102 is allowed as a co-requisite, but see the details for this in the [first slide set][11] (specifically, [here][12]).

**Course objectives:** Students who complete the course will:

- Understand program representation from the high-level programming language perspective down to the underlying machine level representation, including: number representation, operations, conditionals, and control structures
- Be able to implement basic and advanced abstract data types in C++ including: linked lists, stacks, queues, hash tables, trees, and graphs
- Be able to evaluate asymptotic time and space complexity analysis of programs and data structure implementations using Big-O, Big-Omega, and Big-Theta notation and assess the suitability of a data structure for a particular problem
- Understand the basic program execution model and the underlying computer hardware and software (fetch-execute cycle, memory hierarchy, operating system, compiler)
- Be able to implement basic program control and data structures in an assembly language (loops, conditionals, subroutines and parameter passing modes, arrays)

**Grades:** Grades will be calculated by the following formula:

- 45%: Laboratories
- 30%: Two midterm exams
- 25%: Final exam

I expect that grades will follow the standard decade curve: 90 and above is an A of some sort (A-, A, or A+), 80 and above is some sort of a B, etc.  **Note:** I reserve the right to modify the weighting (changing the curve, adding pop quizzes, etc.), especially if attendance drops off significantly.  If this does happen, it will be clearly announced in lecture.

**Development Environment:** In this class, you may NOT use Microsoft Visual Studio, any other Microsoft Windows-based development environment, or any IDE (Integrated Development Environment), for any reason.  This includes, among others, Eclipse, Netbeans, Xcode, Geany, Visual Studio, and Atom. This applies to program development -- obviously, you can use MS Office to edit text documents. The purpose behind this rule is to introduce you to the Unix environment -- thus, all course work in this class is to be done in a Unix environment (Solaris, Linux, FreeBSD, Cygwin, etc.). We will discuss how to access and/or install these environments in the beginning of the course. **In order to take this course, you agree to sign an honor pledge that states that you will NOT use a Microsoft Windows-based development environment or IDE for any course work.**

**Special Circumstances:** Students with special circumstances (athletics, extra time required on exams, final exam conflicts, LNEC considerations, etc.) need to let one of us know during the **first week of class**.

**Textbooks: ** Due to the high cost of textbooks, and their relative low quality, there will be no recommended nor required textbooks this semester.  Instead, there will be selected [Readings][9] ([md][10]) that can be used in lieu of a recommended textbook.

**Exams:** There will be two midterm exams held during laboratory sessions (combined worth 30% of the final grade) and one final exam (worth 25% of the final grade). Note that we hope (but do not guarantee!) to have the first exam returned before the SEAS drop date.

- Midterm Exam 1: Tuesday, September 26, during lab session in Olsson 001
- Midterm Exam 2: Tuesday, November 7, during lab session in Olsson 001
- Final Exam: Monday, December 1 from 7 p.m. to 10 p.m.
	- Exam room TBD
    - This is a common exam time, and conflicts with several other courses
    - Information about conflicting exams will be dealt with later in the semester

Under **NO** circumstances will anybody be allowed to take the final exam early.  You may **ONLY** request to take the final exam at a different time if you have a final exam **CONFLICT**, not a busy final exam schedule.  Since it is a common exam time, the only conflicts are the courses listed on UVa's official exam schedule.

You may submit lab questions for regrading within 10 days of when they are returned to you (less time for the final due to the end of the semester); this is done via the [course tools][41].  However, you MUST be aware of the [Frivolous regrade policy][3] ([md][4]), which will be strictly enforced.

**Laboratories:** There will be 11 or 12 programming labs this semester, and they constitute 45% of your grade (roughly 4% per lab, although some labs may be weighted more than others).  Note that if the number of labs changes, the respective weights for each lab will also be adjusted and announced in class.  The total weight of the labs for the final grade will remain 45%, unless a change in the course grading criteria (as above) is announced in class.  The majority of the work in this class is through the labs -- there are no separate homework assignments.  The labs have different late policies, which will be specified in more detail in the first lab.  **Your lab submission must compile for you to receive *any* credit** -- this is an advanced programming class, and under no circumstances should you be submitting code that does not compile - we have a page on [compilation issues][5] ([md][6]) to help you if you cannot get your code to compile.

All assignments will be submitted through our custom assignments tool, which can be accessed through Collab or [here][41] (Netbadge login required).  Each assignment has 3 dates: an open date (when you can start submitting the assignment), a due date (when it is due), and a close date (the last point that you can submit the assignment); the close date is 24 hours after the due date, due to the late policy (which is explained in [lab 1][13] ([md][14])).  Note that the assignment will be available much earlier, typically Wednesday or Thursday of the week before it's due.  The dates are listed for the week of the lab - the lab week starts on a Sunday and ends on a Saturday.

The various dates: open dates, due dates, and close dates, are listed on the [Lab due dates page][7] ([md][8])

Please note, however, that there are a number of rules that we will strictly follow:

- Pre-labs are due at the same time for everybody, regardless of your lab section; that time is about at the beginning of the FIRST Tuesday lab.
- In-labs are due at the end of your scheduled lab session, regardless of what the submission system states.  But see the part about in-lab extensions, next.
- An in-lab extension (see [lab 1][13] ([md][14]))  for details about getting one on a given lab) will postpone the in-lab due date until 11:59:59 p.m. on Wednesday evening, regardless of your lab section, as this allows you to attend Wednesday office hours
- In-labs MUST be done from the lab in Olsson 001, during your lab time, or no credit will be given for the ENTIRE lab (this means you must either submit the lab from that computer, or submit a lab extension from that computer)
- Any late lab part will receive 25% off (for just that part) for the first 24 hours (or part thereof) that it is late, after which no credit will be given.  Note that a computer program does this deduction -- so if your lab is 1 second late, it still receives 25% off.

The assignments tool does not display due dates such as "at the end of your lab session" very well -- indeed, the due date is listed as 10 p.m. on Tuesdays.  Note that we have a script that will test the assignment's due date against your lab date, so please be sure to follow the above due dates.

**Computing resources:** There are two specific computer resources needed for this course:

- You need to have a working computer that can run a recent build of [VirtualBox][36], with enough hard drive space (and memory) to use a course VirtualBox image (about 10 Gb will be needed for the install, and then 6 Gb  will be used once the installation files are deleted).  Any computer made in the last 3 years will suffice for these requirements (and many older ones will as well).  It doesn't matter if it's a desktop or notebook; nor does the speed matter.
- There are a few documents that you will have to print (a worksheet with lab 5, the UNIX honor pledge, etc.).  The total printing load will be under 5 pages for the entire semester.  You will need to obtain access to a printer for those pages.

**Attendance:** Attendance in labs is mandatory; attendance in lecture is not. Not attending lab will result in a zero for the in-lab. You cannot change labs without prior permission -- we don't have enough computers to accommodate this.  Please see the [first set of lecture slides][11] about lab attendance, in particular with regards to the fact that there is a lab the week of Thanksgiving break.

**Professionalism:** We are all adults, and should act like such.  Acting in an unprofessional manner that disrupts the class will first incur a stern talking-to.  After that, a grade penalty may be assessed.  Examples include: disrupting class, trolling people on Piazza, abusing the support request system, etc.  This is meant to keep people from repeatedly disrupting class; we aren't trying to be super strict on this.  And yes, a warning will first be given prior to any other action.

**Honor Policy:** There have been a large number of honor violations in this class and other low-level CS courses recently.  Outside the normal UVa honor policy rules, we have these additional rules:

1. If you are looking at another student's source code for ANY reason (including code from a student from a previous semester), you are in violation of the honor policy.  You may look at another student's source code after the program has been submitted by BOTH parties.
2. If you try to hack my submission system, you will be brought up on honor charges, failed for the course, and I will personally call the police. This includes any sort of hacking such as: fork bombs to crash the system, opening up network sockets, looking around the file system, etc. The system has capabilities to detect and/or prevent these from happening, and a file cannot be removed once it's submitted (you can re-submit a file, but the old one is still saved). An honest mistake on a program, or a program crash, is not what we are talking about here - instead, an intentional and malicious hacking attempt is what will bring down the wrath.
3. There are multiple midterm periods where students take exams, with a break between the the individual section times.  Discussing the exam with a student who has not taken it is a violation of the honor policy.
4. Releasing your homework online, including a public github repository, is an honor violation
5. Using a computer to generate your *assembly* code, instead of writing yourself, is an honor violation (this includes using the compiler to generate assembly code for submission, although not for including in a report)

Any honor violation or cheating will be referred to the honor committee, **and will result in an immediate failure for the course**, regardless of the outcome of the honor trial or your other grades.  No exceptions!  I am very strict on this, and one have successfully raised honor charges against students in the past due to violations of this policy.

[1]: index.html
[2]: index.md
[3]: frivolous-regrades.html
[4]: frivolous-regrades.md
[5]: ../docs/compilation.html
[6]: ../docs/compilation.md
[7]: labduedates.html
[8]: labduedates.md
[9]: ../docs/readings.html
[10]: ../docs/readings.md
[11]: course-introduction.html#/
[12]: course-introduction.html#/cs2102
[13]: ../labs/lab01/index.html
[14]: ../labs/lab01/index.md

[31]: http://www.cs.virginia.edu/~mrf8t
[32]: mailto:mrf8t@virginia.edu
[33]: http://twitter.com/bloomfieldaaron
[34]: http://twitter.com/UVaCS2150
[35]: https://calendar.google.com/calendar/embed?src=fnt7qr3f64egh65rfe1bng8f8s%40group.calendar.google.com&ctz=America/New_York
[36]: https://www.virtualbox.org/
[37]: https://collab.itc.virginia.edu/portal/site/415219f8-1a72-4ade-a753-b37ec6aecb61/page/37b584bf-c5a5-41e1-bda7-1f2fcbec258e
[38]: http://www.cs.virginia.edu/~mrf8t/
[39]: mailto:mrf8t@virginia.edu

[41]: https://libra.cs.virginia.edu/~pedagogy/
[42]: https://libra.cs.virginia.edu/~pedagogy/support.php
