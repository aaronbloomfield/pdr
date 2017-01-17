CS 2150: Program and Data Representation: Course Syllabus
=========================================================

[Go up to the CS 2150 documents page](index.html) ([md](index.md))

### Fall 2014 ###

- M/W/F 11:00-12:00, Gilmer Hall 130

### Instructor ###

[Aaron Bloomfield](http://www.cs.virginia.edu/~asb) / [aaron@virginia.edu](mailto:aaron@virginia.edu) / [@bloomfieldaaron](http://twitter.com/bloomfieldaaron) Office: Rice Hall, room 403 Office hours are M/W 2:00-3:30

### Course Info ###

- Email: none; fill out a [support request](https://libra.cs.virginia.edu/~pedagogy/support.php) instead
- Announcement feed: [\@UVaCS2150](http://twitter.com/UVaCS2150)
- TAs and their office hours will be posted on the [CS 2150 Google Calendar](https://www.google.com/calendar/embed?src=1ea0dfillqvhlop8d7t0m8afuo%40group.calendar.google.com&amp;amp;ctz=America/New_York) (which is linked to via Collab); all office hours start the Sunday after classes start
- Laboratory Meetings (all in Olsson 001):
    - Section 102: Tuesday, 12:15 pm -- 1:50 pm
    - Section 103: Tuesday, 3:50 pm -- 5:25 pm
    - Section 104: Tuesday, 5:30 pm -- 7:05 pm
    - Section 105: Tuesday, 7:30 pm -- 9:05 pm
	- Lab sections 101 and 106 will remain closed

**Course Description:** This course will introduce you to program and data representation from high level concepts to machine level implementation. Data structuring techniques and the representation of data structures during program execution are discussed, as are operations and control structures and their representation during program execution. Representations of numbers, arithmetic operations, arrays, records, recursion, hashing, stacks, queues, trees, graphs, and related concepts are also covered.

**Availability:** It is important to us to be available to my students, and to address their concerns. If you cannot meet with one of us during our office hours, e-mail and we will find the time to meet. That being said, like everybody else we am quite busy, so it may take a day or more to find a time to meet. And if you have any comments on the course - what is working, what is not working, what can be done better, etc. - we are very interested in hearing about them. There is an anonymous feedback tool through Collab, or you can send one of us an e-mail (please do NOT email the TAs directly).  We tend to get bogged down by e-mail as the semester progresses, so seeing one of us in person (right after lecture, during office hours, etc.) is often a good way to get a more immediate response.

**Prerequisites:** CS 2110 (Software Development Methods) or CS 2220 (Engineering Software); and CS 2102 (Discrete Math), all with grades of C- or above.  Note that CS 2102 is allowed as a co-requisite, but see the details for this in the [first slide set](course-introduction.html) (specifically, [here](course-introduction.html#cs2102)).

**Course objectives:** Students who complete the course will:

- Understand program representation from the high-level programming language perspective down to the underlying machine level representation, including: number representation, operations, conditionals, and control structures
- Be able to implement basic and advanced abstract data types in C++ including: linked lists, stacks, queues, hash tables, trees, and graphs
- Be able to evaluate asymptotic time and space complexity analysis of programs and data structure implementations using Big-O, Big-Omega, and Big-Theta notation and assess the suitability of a data structure for a particular problem
- Understand the basic program execution model and the underlying computer hardware and software (fetch-execute cycle, memory hierarchy, operating system, compiler)
- Be able to implement basic program control and data structures in an assembly language (loops, conditionals, subroutines and parameter passing modes, arrays)

**Grades:** Grades will be calculated by the following formula:

- 40%: Laboratories
- 30%: Two midterm exams
- 25%: Final exam
- 5%: Class participation

We expect that grades will follow the standard decade curve: 90 and above is an A of some sort (A-, A, or A+), 80 and above is some sort of a B, etc.  **Note:** I reserve the right to modify the weighting (changing the curve, adding pop quizzes, etc.), especially if attendance drops off significantly.  If this does happen, it will be clearly announced in lecture. Class participation includes such things as random attendance quizzes or in-class quizzes on readings or previously covered topics, using Piazza, useful contributions to the github repo, or otherwise contributing to the course.

**Development Environment:** In this class, you may NOT use Microsoft Visual Studio, any other Microsoft Windows-based development environment, or any IDE (Integrated Development Environment), such as Eclipse, for any reason.  This applies to program development -- obviously, you can use MS Office to edit text documents.  The purpose behind this rule is to introduce you to the Unix environment -- thus, all course work in this class is to be done in a Unix environment (Solaris, Linux, FreeBSD, Cygwin, etc.).  We will discuss how to access and/or install these environments in the beginning of the course.  **In order to take this course, you agree to sign an honor pledge that states that you will NOT use a Microsoft Windows-based development environment or IDE for any course work.**

**Special Circumstances:** Students with special circumstances (athletics, extra time required on exams, final exam conflicts, LNEC considerations, etc.) need to let one of us know during the **first week of class**.

**Textbooks: ** Due to the high cost of textbooks, and their relative low quality, there will be no recommended nor required textbooks this semester.  Instead, there will be selected [Readings](../docs/readings.html) ([md](../docs/readings.md)) that can be used in lieu of a recommended textbook.

**Exams:** There will be two midterm exams held during laboratory sessions (combined worth 30% of the final grade) and one final exam (worth 25% of the final grade). Note that we hope (but do not guarantee!) to have the first exam returned before the SEAS drop date of Monday, March 3rd, 2014.

- Midterm Exam 1: Tuesday, September 30th during lab session in Olsson 001
- Midterm Exam 2: Tuesday, November 11th, during lab session in Olsson 001
- Final Exam: Friday, December 12th from 9:00 am to 12:00 noon

Under **NO** circumstances will anybody be allowed to take the final exam early.  You may **ONLY** request to take the final exam at a different time if you have a final exam **CONFLICT**, not a busy final exam schedule.  But since it is not a common exam time (as has been in the past), there are not likely to be any conflicts.

**Laboratories:** There will be 11 programming labs this semester, and they constitute 40% of your grade (roughly 4% per lab, although some labs may be weighted more than others).  Note that if the number of labs changes, the respective weights for each lab will also be adjusted and announced in class.  The total weight of the labs for the final grade will remain 40%, unless a change in the course grading criteria (as above) is announced in class.  The majority of the work in this class is through the labs -- there are no separate homework assignments.  The labs have different late policies, which will be specified in more detail in the first lab.  **Your lab submission must compile for you to receive *any* credit** -- this is an advanced programming class, and under no circumstances should you be submitting code that does not compile - the Collab wiki has a page on [compilation issues] to help you if you cannot get your code to compile.

All assignments will be submitted through our custom assignments tool, which can be accessed through Collab.  Each assignment has 3 dates: an open date (when you can start submitting the assignment), a due date (when it is due), and a close date (the last point that you can submit the assignment); the close date is 24 hours after the due date, due to the late policy (which is explained in lab 1).  Note that the assignment will be available much earlier (typically Wednesday or Thursday of the week before it's due).  The dates are listed for the week of the lab - the lab week starts on a Sunday and ends on a Saturday.

The various dates: open dates, due dates, and close dates, are listed on the [Lab due dates page](labduedates.html) ([md](labduedates.md)).

Please note, however, that there are a number of rules that we will strictly follow:

- Pre-labs are due at the same time for everybody, regardless of your lab section; that time is the beginning of the FIRST Tuesday lab.
- In-labs are due at the end of your scheduled lab session, regardless of what Collab states.  But see the part about in-lab extensions, next.
- An in-lab extension (see lab 1 for details about getting one on a given lab) will postpone the in-lab due date until 11:59:59 p.m. on Wednesday evening, regardless of your lab section, as this allows you to attend Wednesday office hours
- In-labs MUST be done from the lab in Olsson 001, or no credit will be given for the ENTIRE lab.
- Any late lab part will receive 25% off (for just that part) for the first 24 hours (or part thereof) that it is late, after which no credit will be given.  Note that a computer program does this deduction -- so if your lab is 1 second late, it still receives 25% off.

The assignments tool does not handle due dates such as "at the end of your lab session" very well -- indeed, the due date is listed as 10 p.m. on Tuesdays.  Note that we have a script that will test the assignment's due date against your lab date, so please be sure to follow the above due dates.

**Attendance:** Attendance in labs is mandatory; attendance in lecture is not (although not attending lecture may affect your participation grade).  Not attending lab will result in a zero for the in-lab.  You cannot change labs without prior permission -- we don't have enough computers to accommodate this.  Please see the first set of lecture slides about lab attendance, in particular with regards to the fact that there is a lab both the week of Thanksgiving break.

**Honor Policy:** There have been a large number of honor violations in this class and other low-level CS courses recently.  Outside the normal UVa honor policy rules, we have these additional rules:

- If you are looking at another student's source code for ANY reason (including code from a student from a previous semester), you are in violation of the honor policy.  You may look at another student's source code after the program has been submitted by BOTH parties.
- If you try to hack my submission system, you will be brought up on honor charges, failed for the course, and I will personally call the police. This includes any sort of hacking such as: fork bombs to crash the system, opening up network sockets, looking around the file system, etc. The system has capabilities to detect and/or prevent these from happening, and a file cannot be removed once it's submitted (you can re-submit a file, but the old one is still saved). An honest mistake on a program, or a program crash, is not what we are talking about here - instead, an intentional and malicious hacking attempt is what will bring down the wrath.
- There are two midterm periods where students take exams, with a break between the the individual section times.  Discussing the exam with a student who has not taken it is a violation of the honor policy.

Any honor violation or cheating will be referred to the honor committee, **and will result in an immediate failure for the course**, regardless of the outcome of the honor trial or your other grades.  No exceptions!  I am very strict on this, and one have successfully raised honor charges against students in the past due to violations of this policy.
