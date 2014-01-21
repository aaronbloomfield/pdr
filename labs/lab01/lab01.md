Laboratory 1: Introduction to C++
=================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

This is laboratory is intended to get you up to speed quickly with
both C++ and Unix.

### Background ###

Every week we will have a lab meeting.  Each lab will consist of three
parts: a pre-lab (to be completed by Tuesday at the due time listed on
the [lab due dates](../../cs2150/labduedates.html) page, an in-lab
(activity to be done during lab), and a post-lab.  The pre-lab will
typically also include a tutorial.  Parts of all three of these may be
required to turned in.  The due dates are all listed on the [lab due
dates](../../cs2150/labduedates.html) page. This will all be discussed
in this lab.

### Reading(s) ###

1. [Tutorial 1: Introduction to UNIX](../../tutorials/01-intro-unix/index.html)
2. Optional: online sources as posted on the [Readings page](../../docs/readings.html)

Procedure
---------

### Pre-lab ###
1. If desired, the alternative readings are available on the [Readings
   page](../../docs/readings.html)
2. Complete [Tutorial 1: Introduction to
   UNIX](../../tutorials/01-intro-unix/index.html)
3. Write the xToN.cpp file, as described in the pre-lab section.
   Since you are unfamiliar with the submission system, you should
   read through the in-lab section of the document, which describes
   the submission process.  Submit the xToN.cpp file.
4. Examine the Object life-cycle code
   ([lifecycle.cpp](lifecycle.cpp.html)
   ([src](lifecycle.cpp))).  You may not understand everything in
   this program by the beginning of lab, but you should by the end of
   next week.  We will be using this program during the in-lab activity.
5. Read how to reboot into Linux for the in-lab.  Although the TAs
   will be able to help you, you should still have an idea how to do
   it.
6. The due date for this lab is listed on the [lab due
   dates](../../cs2150/labduedates.html) page -- see the in-lab
   section for more details about submission deadlines.
7. Files to download: [lifecycle.cpp](lifecycle.cpp.html)
   ([src](lifecycle.cpp))
8. Files to submit: xToN.cpp

### In-lab ###
1. Read through the in-lab section of this document.  You should be
   sure to be familiar with the submission system.
2. Clone the github repo into your lab account
3. Complete the in-lab requirements as described in the in-lab
   section, below.
4. Be sure to include your name, email ID, the date, and the name of
   the file in a header comment at the beginning of each file you submit
   (including text files!)
5. Did you understand the part on capitalization in the in-lab section
   of this document?
6. Files to download: [svtest.cpp](svtest.cpp.html)
   ([src](svtest.cpp)), [svutil.cpp](svutil.cpp.html)
   ([src](svutil.cpp)), [svutil.h](svutil.h.html)
   ([src](svutil.h)), and [lifecycle.cpp](lifecycle.cpp.html)
   ([src](lifecycle.cpp))
7. Files to submit: lifecycle.questions.txt, vector.questions.txt,
   LifeCycle.cpp, LifeCycle.h, and TestLifeCycle.cpp

### Post-lab ###
1. See details in the postlab section, below
2. For this lab you will be submitting your code electronically.
   Your submission is due on the Friday of the week of the lab; the
   exact due time is listed on the [lab due
   dates](../../cs2150/labduedates.html) page.  Be sure to include
   your name, email ID, the date, and the name of the file in a header
   comment at the beginning of each file you submit (including text
   files!).
3. Files to download: [list.h](list.h.html) ([src](list.h)),
   [list.cpp](list.cpp.html) ([src](list.cpp))
4. Files to submit: postlab1.question.txt

------------------------------------------------------------

Pre-lab
-------

Complete [Tutorial 1: Introduction to
UNIX](../../tutorials/01-intro-unix/index.html) For this course, you
will need to be familiar with Emacs.  You are welcome to use any
editor that is not an IDE (Integrated Development Environment), such
as emacs, nano, or vim; you may be tested on the key bindings of your
preferred editor. (Notepad doesn't count.)

Below is a sample function with a `main()` function that calls it.  The
source code for this and other examples from the book is on the Collab
site (in the Resources section under misc/textbooks).  You may find
this and other examples helpful in writing your function to compute
*x^n* and the `main()` function to call it.

    #include <iostream>
    using namespace std;
    
    int foo (int a, int b) {
        int tmp = a;
        tmp += b;
        return tmp;
    }
    
    int main( ) {
        int x, y, z;
        cin >> x;
        cin >> y;
        z = foo (x, y);
        cout << x << " + " << y << " = " << z << endl;
        return 0;
    }

For the pre-lab, you will need to write a **recursive** function
called xton() to compute *x^n* for nonnegative integers *n*.  Assume
that *x^0=1*.  Put this function in a program with a `main()`
function.  Your program should prompt the user for two integer values,
and raise the first to the power of the second by calling your xton()
function.

The file should be called xToN.cpp, and should be submitted to the
pre-lab 1 assignment in the submission system.

Note that your program should take in **exactly two inputs and nothing
else**.  We are going to run it through an automated grading script
prior to the TAs grading it -- if your program takes in a different
number of inputs, you will receive points off.

Lastly, take a look at the object life-cycle code
([lifecycle.cpp](lifecycle.cpp.html) ([src](lifecycle.cpp))).  Use it
as a mechanism for understanding how various aspects of C++
work. Compile and run the program (see part III of the
[tutorial](../../tutorials/01-intro-unix/index.html)).  Try stepping
through it by hand.  Use the [readings](../../docs/readings.html), the
web, and any other C++ references to help you look up parts of the
program you do not understand.

### Linux in the lab room ###

This section describes how to log into Linux in the lab room (either
Olsson 001 or Rice 340).  Although this is really part of the in-lab,
you won't be able to access this document until you have logged in,
which is why the directions are listed in the pre-lab section.

The machines in the lab room have two operating systems installed --
Windows and Linux (the Ubuntu distribution).  You have accounts on
each, although the passwords will be separate.  You will need to
reboot the computer into Linux -- to do this, do a regular reboot from
Windows.  Upon the reboot, after the Dell logo screen is shown, a boot
loader screen will appear, allowing you to choose which operating
system to load.  There are a number of choices, but the one we are
interested in is the Ubuntu choice (there are two -- ignore the 'safe
mode' version).  You will note that the default selection is Windows
-- you will have to use the arrow keys to select the Ubuntu line, and
then hit Enter.

Once the login screen appears, you can log in.  Be aware that it may
take a full minute to log you into the machine.  Linux has a number of
*desktop environments* that one can choose from -- each of these has a
different look-and-feel, in the same way that Windows is different
from Mac OS X.  We are currently using Gnome (pronounced 'ga-nome',
not 'nome').  We may later see another one called KDE, and you will be
able to choose whichever one you prefer more.

In Gnome, you will notice that the task bar is at the top.  There is a
Firefox icon there that you can use to launch a web browser to log
into Collab (https://collab.virginia.edu) and complete the lab.  You
will also need to load up a terminal window -- to do this, click on
'Applications' at the top, and select Accessories ->Terminal.

When you are finished, you should log out (from the menu at the top,
or you can hit Ctrl-Alt-Backspace), and reboot the computer (through
the options menu at the bottom of the login screen).

------------------------------------------------------------

In-lab
------

### General In-lab Procedure ###

The purpose of the labs is to allow you to work through the lab
activity, and if you encounter questions or problems, ask for TA
assistance.  Note that each file you electronically submit (including
text files!) should contain a header containing your name, email ID,
file name, and the date.

All of the files required for this lab are listed above (in the
Procedure section), and are also listed below.

### Cloning the github repo ###

The first thing you need to do is clone the github repo into your lab
account.  To do this, enter:

```
git clone https://github.com/aaronbloomfield/pdr.git
```

This will create a 'pdr' directory, which is the copy of the repo.
Each week, you will need to update the repo with the current
contents.  To do so, cd into that 'pdr' directory, and enter:

```
git pull
```

To view the contents in a web browser, you should enter the following
as the URL (replacing 'mst3k' with your userid):

```
file:///home/mst3k/pdr/README.html
```

Note that there are three forward slashes there!

We realize that you cannot view these directions until after you have
the github repo cloned locally.  So hopefully you read these ahead of
time.  Otherwise, the TAs will be able to help you with this part.


### Understanding C++ ###

1. Ask the TAs if you have questions about your *x^n* function.
2. Ask the TAs if you have questions about using Unix.
3. Object Lifecycle Program
   - Download the ([lifecycle.cpp](lifecycle.cpp.html)
     ([src](lifecycle.cpp)) file
   - Compile with clang++ (i.e., 'clang++ lifecycle.cpp') and execute
     the program.
   - Break lifecycle.cpp into multiple files.  It may be helpful to
     look at class slides on the Collab site.  Compile and run this
     program.  Note that to compile a C++ program with multiple files,
     just put them on the same line: 'clang++ LifeCycle.cpp
     TestLifeCycle.cpp' (you usually leave out the .h files when
     compiling).  Add the descriptive header at the top of the file
     containing your identifying information, and name them as
     follows:
     - LifeCycle.h
     - LifeCycle.cpp
     - TestLifeCycle.cpp
   - Comment out the prototype for `getMaxMyObj()`.  Recompile.  What
     happens and why?  Talk to TA if you are unsure.  Now un-comment
     the prototype.
   - Look at the output of lifecycle.cpp.  Write at least one question
     about something in this program. Write your questions in a text
     file named lifecycle.questions.txt.  Remember to include the
     header comment at the top of the file.
4. Using C++ vector container class with strings
   - There are 3 files on the Collab site that demonstrate the use of
     multi-file programs and the use of the vector collection class in
     C++: [svtest.cpp](svtest.cpp.html) ([src](svtest.cpp)),
     [svutil.cpp](svutil.cpp.html) ([src](svutil.cpp)), and
     [svutil.h](svutil.h.html) ([src](svutil.h)).  The class in those
     files is similar to the ArrayList class in the Java standard
     library (or Java's own Vector class).  Compile the program in
     Unix and run it.  The command 'clang++ svutil.cpp svtest.cpp'
     will compile the program.
   - Comment out the `#include <iostream>` preprocessor directive in the
     file svtest.cpp, and then rebuild the program.  Was there an error?
   - Now undo what you did in the previous step, but now comment out
     the using `namespace std;` in svutil.h, and rebuild the
     program. Was there an error?  What objects are now undeclared and
     why?
   - Write at least one question about something in this program.
     This question might be about something that you don't understand
     completely. Write your questions in a file named
     vector.questions.txt

### Troubleshooting ###

Does your program not compile?  Here are a few things to try -- these
are problems that previous students have encountered.

- You must have `#include <iostream>` at the beginning of each file
  (well, really each file that uses `cin` and `cout`, but it doesn't
  hurt to have it at the beginning of each file).
- Likewise, you will need `using namespace std;` at the beginning of
  each file.
- Is your subroutine a method (i.e. part of a class) or a function
  (i.e. not part of a class)?  Make sure you know which is which!  A
  method has its name in the form classname::methodname, whereas a
  function doesn't have a class name or the double-colon.
- Make sure that your subroutine names (whether they be function names
  or method names) are consistent between the .h files and the .cpp
  files
- Have a compiler error that you don't understand?  We have the
  translation!  See the [compilation](../../docs/compilation.html)
  page, which lists common compiler error messages, what they mean,
  and how to solve them.  If you don't see yours listed there, let us
  know, and we'll add it.

### Capitalization ###

Under Windows, the case of a file name is ignored -- thus,
lifecycle.cpp, LifeCycle.cpp, and LIFECYCLE.CPP all refer to the same
file.  However, it is **NOT** true for Linux, which is what we will
use to test and grade your code.  Thus, if your file is called
'LifeCycle.h', and you have (in your TestLifeCycle.cpp file) a line
that states: `#include "lifecycle.h"`, then your program will NOT work
under Linux (since case DOES matter with file names).  Since your code
does not compile, you will get zero credit.  So make sure your file
names match!

### Assignment submission ###

All assignments will be submitted through our custom submission tool.
These can be accesed through Collab, or directly at the link in the
Procedure section of this lab.

Each assignment has 3 dates: an open date (when you can start
submitting the assignment), a due date (when it's due), and a close
date (the last point that you can submit the assignment).  The dates
are listed for the week of the lab (the lab week starts on a Sunday
and ends on a Saturday).  In particular, the due date for the
pre-labs, as well as the open date for the in-labs and post-labs is
when the first lab section starts.  The close date for the post-labs
is the start of Friday's lecture (the first lecture, if there are
multiple lecture periods).

The various dates: open dates, due dates, and close dates, are listed
on the [lab due dates](../../cs2150/labduedates.html) page.

Please note, however, that there are a number of rules that we will
strictly follow:

- Pre-labs are due at the same time for everybody, regardless of your
  lab section; that time is the beginning of the FIRST Tuesday lab.
- In-labs are due at the end of your scheduled lab session, regardless
  of what Collab states.  But see the part about in-lab extensions,
  below.
- An in-lab extension (see below for details) will postpone the in-lab
  due date until 11:59:59 p.m. on Wednesday evening, regardless of your
  lab section; this allows those who have requested a lab extension to
  visit the Wednesday evening office hours.
- In-labs **MUST** be done from the lab in the lab room, or no credit
  will be given for the **ENTIRE** lab.
- Any late lab part will receive 25% off (for just that part) for the
  first 24 hours (or part thereof) that it is late, after which no
  credit will be given.  Note that a computer program does this
  deduction -- so if your lab is 1 second late, it still receives 25%
  off.
- There is no penalty for in-lab extensions, neither is there a limit
  to the number of weeks you can use them. The extended in-lab does
  not need to be completed in the lab room.

The assignments tool does not handle due dates such as "at the end of
your lab session" very well -- indeed, the due date is listed as 10
p.m. on Tuesdays.  Note that we have a script that will test the
assignment's due date against your lab date, so please be sure to
follow the above due dates.

### Lab Extensions ###

You can automatically request a lab extension if you are unable to
complete your in-lab during the allotted time.  This is done through
the lab extension tool, which is accessible either via Collab or
through the link in the Procedure section, above.  Note that this
only applies to the in-lab.  The due date with the extension is the
end of the day on Wednesday (i.e. 11:59 p.m.), regardless of your lab
section, as this gives you a chance to go to the Wednesday evening
office hours.

### Submitting your files ###

All assignments for this course will be submitted through the lab
submission tool, which is accessible either via Collab or through the
link in the Procesure sectionk above.  There is no check to make sure
you have submitted all of the correct files -- on the 'Procedure' page
(always at the top of the lab document), we clearly state which files
should be submitted for each lab part.  For example, for this in-lab,
you should submit the following files for in-lab 1:
lifecycle.questions.txt, vector.questions.txt, LifeCycle.h,
LifeCycle.cpp, and TestLifeCycle.cpp.

Lastly, you should ensure that your program compiles before you submit
it.  This is an advanced programming class, and there is no reason why
you should submit a program that does not compile.  If you are having
problems with your code, you should comment out parts so that it does
compile -- you will receive some credit for a program that has part of
the code commented out than a program that does not compile.  See the
[compilation](../../docs/compilation.html) for hints as to how to get
your code to compile.

Just to be clear: **you will receive zero credit for a lab component
which does not compile.**

### Resubmitting your assignment ###

If you submit your assignment, and you realize you made a mistake
(didn't submit all the files, etc.), you can resubmit your assignment.
The date of submission is the date you re-submitted your assignment --
so if you resubmit your assignment after the due date to add one more
file, the **ENTIRE** assignment will have the late submission date.
We only look at the most recent submission.  There is no penalty for a
reasonable number of submissions (i.e., if you hit 100 or so, we will
think you are hacking our servers).

------------------------------------------------------------

Post-lab
--------

Complete the exercise below, and submit the text file described there
to the submission system.

For this lab you will be submitting your assignment electronically.
Your submission is on the Friday of the week of the lab; the exact
time is listed on the [lab due dates](../../cs2150/labduedates.html)
page.  Be sure to include: your name, the date, and the name of the
file in a banner comment at the beginning of each file you submit.

### Linked List Template code ###

Download the two linked list files ([list.h](list.h.html)
([src](list.h)) and [list.cpp](list.cpp.html)
([src](list.cpp))). Compile and run the program. The compile command
is `clang++ list.cpp`.  If you try to compile the list.h file, it
won't work correctly.

Look at list.h, which is #include'd from list.cpp -- it contains the
**bodies** of the methods, which is not the way that it is usually
done (the bodies are typically in the .cpp file only).  We normally
only include in .h files just the declarations (i.e., prototypes) of
classes, constants, function, etc., but not definitions of
C++ methods (i.e. the bodies of the methods). However, when
implementing template classes, this is something that is necessary to
make the class compile successfully.

Look more closely at TestLinkedList.cpp. The line:

```
List<int> *l = new List<int>();
```

declares a (pointer to) a List of integers, called l. A similar line,
but with a different type, would create a list of something else.  For
example, consider the following line:

```
List<char> list2;
```

This declares a (non-pointer) list of characters (this is not in the
list.cpp file, by the way).  Now all the methods
in the List class will be available to both `l` and `list2`.

Write at least one question about something in this program.  Put your
question(s) in a text file called "postlab1.question.txt" and submit
this to the submission system to the post-lab 1 assignment.
