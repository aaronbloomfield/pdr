CS 2150: Program and Data Representation: Course Syllabus
=========================================================

[Go up to the CS 2150 page][1] ([md][2])

## Spring 2020

### Instructor ###

- [Aaron Bloomfield][33] / [aaron@virginia.edu](mailto:aaron@virginia.edu).  Office: Rice Hall, room 402.  Office hours: M 11-12, W 12-1, F 9-10

### Course Info ###

- Lectures: M/W/F 10:00-10:50 (CHM 402) or 1:00-1:50 (Minor 125)
- Email: none; fill out a [support request][42] instead
- Announcement feed: [\@UVaCS2150][34] and the [daily announcements slide set][15]; you are responsible for checking both
- TA office hours are 6-10 on Sundays, Mondays, Wednesdays, and Thursdays in the Thornton stacks; faculty office hours are listed [here](course-introduction.html#/profoh); all office hours start the Sunday after classes start
- Laboratory Meetings (in Olsson 001): all on Tuesdays

**Course Description:** This course will introduce you to program and data representation from high level concepts to machine level implementation. Data structuring techniques and the representation of data structures during program execution are discussed, as are operations and control structures and their representation during program execution. Representations of numbers, arithmetic operations, arrays, records, recursion, hashing, stacks, queues, trees, graphs, and related concepts are also covered.

**Availability:** It is important to me to be available to my students, and to address your concerns. If you cannot meet with me during office hours, e-mail and I will try to find the time to meet. That being said, like everybody else I get quite busy, so it may take a day or more to find a time to meet. And if you have any comments on the course - what is working, what is not working, what can be done better, etc. - I are very interested in hearing about them. There is an [anonymous feedback tool through Collab][37], or you can send an e-mail (please do NOT email the TAs directly). I tend to get bogged down by e-mail as the semester progresses, so seeing me in person (right after lecture, during office hours, etc.) is often a good way to get a more immediate response.

**Prerequisites:** CS 2110 (Software Development Methods) or CS 2220 (Engineering Software); and CS 2102 (Discrete Math), all with grades of C- or above.  Note that CS 2102 is allowed as a co-requisite, but see the details for this in the [first slide set][11] (specifically, [here][12]).

**Course Objectives:** Students who complete the course will:

- Understand program representation from the high-level programming language perspective down to the underlying machine level representation, including: number representation, operations, conditionals, and control structures
- Be able to implement basic and advanced abstract data types in C++ including: linked lists, stacks, queues, hash tables, trees, and graphs
- Be able to evaluate asymptotic time and space complexity analysis of programs and data structure implementations using Big-O, Big-Omega, and Big-Theta notation and assess the suitability of a data structure for a particular problem
- Understand the basic program execution model and the underlying computer hardware and software (fetch-execute cycle, memory hierarchy, operating system, compiler)
- Be able to implement basic program control and data structures in an assembly language (loops, conditionals, subroutines and parameter passing modes, arrays)

**Grades:** Grades will be calculated by the following formula:

- 45%: Laboratories
- 30%: Two midterm exams
- 25%: Final exam

The course grades will follow the standard decade curve: 90 and above is an A of some sort (A-, A, or A+), 80 and above is some sort of a B, etc.  **Note:** We reserve the right to modify the weighting (changing the curve, adding pop quizzes, etc.), especially if attendance drops off significantly.  If this does happen, it will be clearly announced in lecture.

**Development Environment:** In this class, you may NOT use Microsoft Visual Studio, any other Microsoft Windows-based development environment, or any IDE (Integrated Development Environment), for any reason.  This includes, among others, Eclipse, Netbeans, Xcode, Geany, Visual Studio, and Atom. This applies to program development - obviously, you can use MS Office to edit text documents. The purpose behind this rule is to introduce you to the Unix environment - thus, all course work in this class is to be done in a Unix environment (typically Linux or FreeBSD). We will discuss how to access and/or install these environments in the beginning of the course. **In order to take this course, you agree to sign an honor pledge that states that you will NOT use a Microsoft Windows-based development environment or IDE for any course work.**

**Disabilities:**  The University of Virginia strives to provide accessibility to all students. If you require an accommodation to fully access this course, please contact the Student Disability Access Center (SDAC) at (434) 243-5180 or sdac@virginia.edu. If you are unsure if you require an accommodation, or to learn more about their services, you may contact the SDAC at the number above or by visiting their website at http://studenthealth.virginia.edu/student-disability-access-center/faculty-staff.

**Special Circumstances:** Students with special circumstances (athletics, extra time required on exams, final exam conflicts, LNEC considerations, etc.) need to let me know at least **one week** prior to when said accommodation will be needed.
 
**Textbooks:** Due to the high cost of textbooks, and their relative low quality, there will be no recommended nor required textbooks this semester.  Instead, there will be selected [Readings][9] ([md][10]) that can be used in lieu of a recommended textbook.

**Exams:** There will be two midterm exams held during laboratory sessions (combined worth 30% of the final grade) and one final exam (worth 25% of the final grade). Note that we hope (but do not guarantee!) to have the first exam graded and returned before the SEAS drop date.

- Midterm Exam 1: Tuesday, February 18th, during lab session
- Midterm Exam 2: Tuesday, March 31st, during lab session
- Final Exam: Thursday, April 30th from 7 p.m. to 10 p.m.
    - This is a common exam time, and conflicts with other courses (BIOL 2100, CS 2110, KOR 1010, KOR 2010, KOR 3010, STAT 2120, and STAT 3120)
    - Let us know by the end of January if you have a conflict (via a support request); we will deal with scheduling conflicts later in the semester

***YOU WILL HAVE TO BRING YOUR UVA ID TO ALL EXAMS!!!***

Under **NO** circumstances will anybody be allowed to take the final exam early.  You may **ONLY** request to take the final exam at a different time if you have a final exam **CONFLICT**, not a busy final exam schedule.  However, that request ***MUST*** be submitted by the end of January.  Since it is a common exam time, the only conflicts are the courses listed on UVa official exam schedule.  For Spring 2020, they are: APMA 3110, APMA 3140, and ECON 2020 (sections 001 and 002)

You may submit exam questions for regrading within 10 days of when they are returned to you (less time for the final due to the end of the semester); this is done via the [course tools][41].  However, you MUST be aware of the [Frivolous regrade policy][3] ([md][4]), which will be strictly enforced.

**Laboratories:** There will be 11 or 12 programming labs this semester, and they constitute 45% of your grade (roughly 4% per lab, although some labs may be weighted more than others).  Note that if the number of labs changes, the respective weights for each lab will also be adjusted and announced in class.  The total weight of the labs for the final grade will remain 45%, unless a change in the course grading criteria (as above) is announced in class.  The majority of the work in this class is through the labs -- there are no separate homework assignments.  The labs have different late policies, which will be specified in more detail in the first lab.  **Your lab submission must compile for you to receive *any* credit** -- this is an advanced programming class, and under no circumstances should you be submitting code that does not compile - we have a page on [compilation issues][5] ([md][6]) to help you if you cannot get your code to compile.  Note that the *entire* assignment will receive zero credit if even *one* part of it does not compile.

All assignments will be submitted through our custom assignments tool, which can be accessed through Collab or [here][41] (Netbadge login required).  Each assignment has 3 dates: an open date (when you can start submitting the assignment), a due date (when it is due), and a close date (the last point that you can submit the assignment); the close date is 24 hours after the due date, due to the late policy (which is explained in [lab 1][13] ([md][14])).  Note that the assignment will be available much earlier, typically Wednesday or Thursday of the week before it is due.  The dates are listed for the week of the lab - the lab week starts on a Sunday and ends on a Saturday.

The various dates: open dates, due dates, and close dates, are listed on the [Lab due dates page][7] ([md][8])

Please note, however, that there are a number of rules that we will strictly follow:

- Pre-labs are due at the same time for everybody, regardless of your lab section; that time is the beginning of the FIRST Tuesday lab.
- In-labs are due at the end of the day on Tuesday.
- Post-labs are due at the start of the *first* lecture on Friday, regardless of which lecture section you are registered for; the exact time is on the [lab due dates page][7]
- Any late lab part will receive 25% off (for just that part) for the first 24 hours (or part thereof) that it is late, after which no credit will be given. Note that a computer program does this deduction -- so if your lab is 1 second late, it still receives 25% off.

**Computing resources:** There are two specific computer resources needed for this course:

- You need to have a working computer that can run a recent build of [VirtualBox][36], with enough hard drive space (and memory) to use a course VirtualBox image (about 15 Gb will be needed for the install, and then 10 Gb  will be used once the installation files are deleted).  Any computer made in the last 3 years will suffice for these requirements (and many older ones will as well).  It does not matter if it is a desktop or notebook; nor does the speed matter.
    - If your computer breaks, you can contact the CS systems staff for a loaner laptop -- they are in the basement of Rice hall, in rooms ?? and ??.  Tell them you are in my class, and they will provide you with a machine to borrow.
- There are a few documents that you will have to print (the UNIX honor pledge, etc.).  We will attempt to provide copies for you.  The total printing load will be under 5 pages for the entire semester.  You will need to obtain access to a printer for those pages.

**Attendance:** Attendance is highly recommended but not required in either lecture or lab. Unless you have received special permission, you cannot attend labs that you are not enrolled in due to space constraints.  Please see the [first set of lecture slides][11] for more information about the lab schedule, in particular with regards to the fact that there is a lab the week of Thanksgiving break (in fall semesters) or the weeks before and after spring break (in spring semesters).

**Professionalism:** We are all adults, and should act like such.  Acting in an unprofessional manner that disrupts the class will first incur a stern talking-to.  After that, a grade penalty may be assessed.  Examples include: disrupting class, trolling people on Piazza, abusing the support request system, etc.  This is meant to keep people from repeatedly disrupting class; we are not trying to be super strict on this.  While we generally expect to give a warning prior to any other action, infractions that go well beyond unprofessional may incr penalties with no warning.

**Honor Policy:** There have been a large number of honor violations in this class and other low-level CS courses recently.  Outside the normal UVa honor policy rules, we have these additional rules:

1. If you are looking at another student's source code for ANY reason (including code from a student from a previous semester), you are in violation of the honor policy.  You may look at another student's source code after the program has been submitted by BOTH parties.
2. If you try to hack my submission system, you will be brought up on honor charges, failed for the course, and I will personally call the police. This includes any sort of hacking such as: fork bombs to crash the system, opening up network sockets, looking around the file system, etc. The system has capabilities to detect and/or prevent these from happening, and a file cannot be removed once it is submitted (you can re-submit a file, but the old one is still saved). An honest mistake on a program, or a program crash, is not what we are talking about here - instead, an intentional and malicious hacking attempt is what will bring down the wrath.
3. There are multiple midterm periods where students take exams, with a break between the the individual section times.  Discussing the exam with a student who has not taken it is a violation of the honor policy.
4. Releasing your homework online, including a public github repository, is an honor violation
5. Using a computer to generate your *assembly* code, instead of writing yourself, is an honor violation (this includes using the compiler to generate assembly code for submission, although not for including in a report)
6. We realize we should have to say this, but we will not sign more than one conscientious retraction for a given student within one semester.

Any honor violation or cheating will be referred to the honor committee, **and will result in an immediate failure for the course**, regardless of the outcome of the honor trial or your other grades.  No exceptions!  I am very strict on this, and one have successfully raised honor charges against students in the past due to violations of this policy.

**Your Well Being:** The Engineering School proudly serves as a safe space for its students and aims to promote their well being. If you are feeling overwhelmed, stressed, or isolated, there are many individuals here who are ready and wanting to help.   In addition to the course instructors, you can seek help through the Engineering Undergraduate office (Thornton A122), or Alex Hall (aec5d, 924-7601) who is the assistant dean of students for the Engineering school.

Alternatively, there are also other University of Virginia resources available. The Student Health Center offers Counseling and Psychological Services (CAPS) for its students. Call 434-243-5150 (or 434-972-7004 for after hours and weekend crisis assistance) to get started and schedule an appointment. If you prefer to speak anonymously and confidentially over the phone, call Madison House's HELP Line at any hour of any day: 434-295-8255.

If you or someone you know is struggling with gender, sexual, or domestic violence, there are many community and University of Virginia resources available. The Office of the Dean of Students, Sexual Assault Resource Agency (SARA), Shelter for Help in Emergency (SHE), and UVA Women's Center are ready and eager to help. Contact the Director of Sexual and Domestic Violence Services at 434-982-2774.

**Reasonable Modifications:** Try as we might, we cannot predict the future.  There may be situations that arise during the semester that are not adequately covered by this syllabus, and which will require us to make adaptations or modifications during the semester.  We do not expect this to happen often.  And if we knew what types of situations these would be, we would change professions to fortune telling...

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
[15]: daily-announcements.html#/

[31]: http://www.cs.virginia.edu/~mrf8t
[32]: mailto:mrf8t@virginia.edu
[33]: http://www.cs.virginia.edu/~asb
[34]: http://twitter.com/UVaCS2150
[35]: https://calendar.google.com/calendar/embed?src=fnt7qr3f64egh65rfe1bng8f8s%40group.calendar.google.com&ctz=America/New_York
[36]: https://www.virtualbox.org/
[37]: https://collab.its.virginia.edu/portal/site/eb965f29-11d0-4069-9140-6b4eb0f44444/tool-reset/495df88d-2624-46bf-872f-db154dd6048e
[38]: http://www.cs.virginia.edu/~nn4pj
[39]: mailto:mrf8t@virginia.edu


[41]: https://libra.cs.virginia.edu/~pedagogy/
[42]: https://libra.cs.virginia.edu/~pedagogy/support.php
[43]: https://www.cs.virginia.edu/~cr4bd/
[44]: mailto:creiss@virginia.edu
