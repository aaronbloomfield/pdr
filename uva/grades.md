Grading Explanations, Fall 2019
===============================

[Go up to the CS 2150 page](index.html) ([md](index.md))

&nbsp;  


Grade parts
-----------

There were 11 full-length labs, but no lab 12 due to how the semester schedule worked out.  Thus, there were 33 lab parts (11 labs of 3 parts each).  So the total number of points for the labs was 330.  As per the [syllabus](syllabus.html) ([md](syllabus.md)), labs counted for 45% of the final course grade.

Each midterm counted for 15% of the final course grade, even though the total number of points on each midterm was different.  The final counted for 25% of the final course grade.

This grade breakdown (how much each part counts for the final grade) is as listed on the [course syllabus](syllabus.html) ([md](syllabus.md)).


Curves from exams
-----------------

For exam 1 (average was 61%), we promised a curve of "15 to 20 percentage points" ([source](https://uva-cs.github.io/pdr/uva/daily-announcements.html#/26/1)).  Let's assume that means 17.5 percentage points.  This exam was worth 15% of the final grade, so 15% * 17.5% = 2.625 points added to your final course average due to this exam curve.

Exam 2 (average was 60%) also had a curve of "15 to 20 percentage points" ([source](https://uva-cs.github.io/pdr/uva/daily-announcements.html#/6/1)).  The math is the same as for exam 1, so that's another 2.625 points to the final course average.

The final average was 69%.  As a curve for that, it would be 10 percentage points.  Since the final is worth 25% of the course grade, that works out to 2.5 points.

Thus, from the exams, there is a total curve of 2.625 + 2.625 + 2.5 = 7.75 points added to the final course average.


Rounding
--------

Yes, we round grades. Note that `round(x) == floor(x+0.5)`. So instead of adding 7.75 (from above) and rounding, you can just add 8.25 and don't round.  But doing it this way means that rounding has already happened, so if you get an 89.9999999999999999999, it's still a B+, no matter how many times you ask - you don't get to round a second time (in reality, it was an 89.49).  Alternatively, you can add 7.75 and then round -- either way will yield the same result.


Overall course curve
--------------------

There is 7.75 points from the two midterms and the final.  The lab grades were relatively high, so no curve for those either.  Adding in 0.5 points for rounding yields a total curve (without rounding again) of 8.25.  We raised that up to a final curve of 9.0 points.

Thus, you add 9.0 points to your final course average to determine what letter grade you will end up getting.


Grade breakdown
---------------

As stated at the beginning of the semester, each 10-point "decade" is a separate letter grade range (60-70 is a D, 70-80 is a C, etc.).  The exact ranges are below. Take your average from the course gradebook and add 9.0 for the curve (or add 8.5 and then round), then see where the result lies on this table.

| Minimum course average | Letter grade |
|------------------------|--------------|
| 60 | D- |
| 63 | D |
| 67 | D+ |
| 70 | C- |
| 73 | C |
| 77 | C+ |
| 80 | B- |
| 83 | B |
| 87 | B+ |
| 90 | A- |
| 93 | A |
| 102 | A+ |


Recall (again!) that rounding has already been taken into account!  Thus, the cut-offs listed above are hard cut-offs.

Note that the A+ range follows a different algorithm -- it's a percentage of the class (the top 6 people, which ended up being an (uncurved) average of 93.0 or above). A (curved) 60 is the minimum passing grade for a D-. You must receive a C- (70) or higher to take CS courses that have CS2150 as a pre-requisite.


Regrade Statistics
------------------

There were 13,511 lab grades determined this semester -- this roughly 403 (the number of students) times 33 (the number of graded labs).  (The difference between them is for grades that were re-done, or students who dropped.)  There were 313 regrades submitted this semester, which is 2.32% of the number of grades determined.  Of those regrades, 145 (46%) were due to extensions, not an issue with grading.  Of the 168 that remained, 71 resulted in no grade change.  Thus, only 97 graded lab parts -- 0.72% of the total grades determined -- necessitated a regrade.
