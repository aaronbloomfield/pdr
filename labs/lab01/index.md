PDR: Laboratory 1: Introduction to C++
======================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

This is laboratory is intended to get you up to speed quickly with both C++ and Unix.

### Background ###

There will be a lab every week, which consists of three parts: a pre-lab, an in-lab, and a post-lab.  The due dates are all listed on the [lab due dates](../../uva/labduedates.html) page. This will all be discussed in this lab.

### Tutorial ###

Most labs will have a tutorial.
You are expected to complete this tutorial before beginning the lab,
as the lab will use concepts from each tutorial.

The tutorial for this lab is [Tutorial 1: Introduction to UNIX](../../tutorials/01-intro-unix/index.html),
which will help you set up your UNIX environment.

### Recommended Readings ###

We have attempted to compile a collection of readings that go over topics covered in this course.
Readings are always optional and are there for you to use as you see fit.

- Introduction to C++ section on the [Readings page](../../docs/readings.html)

Procedure
---------

### Pre-lab ###

1. Write a recursive function to compute exponentiation
2. Investigate the C++ object lifecycle
3. Learn about the submission system
4. Files to download: [lifecycle.cpp](lifecycle.cpp.html) ([src](lifecycle.cpp))
5. Files to submit: xToN.cpp

### In-lab ###

1. Ask the TAs if you have any questions about the pre-lab code or Unix
2. Separate the object lifecycle code to better follow C++ conventions
3. Investigate an example program and ask questions about it
4. Files to download: [svtest.cpp](svtest.cpp.html) ([src](svtest.cpp)), [svutil.cpp](svutil.cpp.html) ([src](svutil.cpp)), [svutil.h](svutil.h.html) ([src](svutil.h)), and [lifecycle.cpp](lifecycle.cpp.html) ([src](lifecycle.cpp))
5. Files to submit: lifecycle.questions.txt, vector.questions.txt, LifeCycle.cpp, LifeCycle.h, and TestLifeCycle.cpp

### Post-lab ###

1. Investigate a more complicated example program and ask questions about it
2. Files to download: [list.h](list.h.html) ([src](list.h)), [list.cpp](list.cpp.html) ([src](list.cpp))
3. Files to submit: postlab1.question.txt

------------------------------------------------------------

Pre-lab
-------

Complete [Tutorial 1: Introduction to UNIX](../../tutorials/01-intro-unix/index.html) before proceeding.
Remember that you should always complete the tutorial before starting the lab.

For the pre-lab, you will need to write a **recursive** function called `xton()` to compute *x^n* for non-negative integers *n*.  Assume that *x^0=1*.  Put this function in a program with a `main()` function.  Your program should prompt the user for two integer values, and raise the first to the power of the second by calling your `xton()` function.  To keep the code simple, you can assume that your program will only be called with valid inputs.

The file should be called xToN.cpp, and should be submitted to the pre-lab 1 assignment in the submission system -- more details below.

Note that your program should take in **exactly two inputs and nothing else**.  We are going to run it through an automated grading script prior to the TAs grading it -- if your program takes in a different number of inputs, you will receive points off.

To help you out, we have provided an example C++ file below.  You may find this example helpful in writing your function to compute *x^n* and the `main()` function to call it.

```
#include <iostream>
using namespace std;

int sum (int a, int b) {
    int tmp = a;
    tmp += b;
    return tmp;
}

int main () {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = sum (x, y);
    cout << x << " + " << y << " = " << z << endl;
    return 0;
}
```

Lastly, take a look at the object life-cycle code ([lifecycle.cpp](lifecycle.cpp.html) ([src](lifecycle.cpp))).  Use it as a mechanism for understanding how various aspects of C++ work and try stepping through it by hand.  Use the [readings](../../docs/readings.html), the web, and any other C++ references to help you look up parts of the program you do not understand.

### Assignment submission ###

All assignments will be submitted through our custom submission tool which can be accessed through Collab's Course Tools link or directly at [https://libra.cs.virginia.edu/~pedagogy](https://libra.cs.virginia.edu/~pedagogy).

Every file submitted, including text files, should include your name, email ID, the date, and the name of the file in a header comment at the beginning of the file.

There is no check to make sure you have submitted all of the correct files -- on the 'Procedure' page (always at the top of the lab document), we clearly state which files should be submitted for each lab part.  For example, for this pre-lab, you should submit just the following file for pre-lab 1: xToN.cpp.

Each assignment has 3 dates: an open date (when you can start submitting the assignment), a due date (when it's due), and a close date (the last point that you can submit the assignment).  The dates are listed for the week of the lab -- the lab week starts on a Sunday and ends on a Saturday.  In particular, the due date for the pre-labs, as well as the open date for the in-labs and post-labs is when the first lab section starts.  The due date for the post-labs is the start of Friday's first lecture.

More information on open dates, due dates, and close dates can be found on the [lab due dates](../../uva/labduedates.html) page.

There are a number of rules that we will strictly follow:

- Pre-labs are due at the same time for everybody, regardless of your lab section; that time is the beginning of the FIRST Tuesday lab.
- In-labs are due at the end of the day on Tuesday.
- Any late lab part will receive 25% off (for just that part) for the first 24 hours (or part thereof) that it is late, after which no credit will be given.  Note that a computer program does this deduction -- so if your lab is 1 second late, it still receives 25% off.
- **No credit will be given for a lab component which does not compile.**  If you are having problems with your code, you should comment out parts so that it does compile -- you will receive more credit for a compilable program that has part of the code commented out than you would for a program that does not compile.  See the [compilation](../../docs/compilation.html) for hints as to how to get your code to compile.

### Resubmitting your assignment ###

If you submit your assignment, and you realize you made a mistake (didn't submit all the files, etc.), you can resubmit your assignment as many times as you want.  The date of submission is the date you re-submitted your assignment -- so if you resubmit your assignment after the due date to add one more file, the **ENTIRE** assignment will have the late submission date.  We only look at the most recent submission.

***Note that you have to bring your computer to in-lab!***

------------------------------------------------------------

In-lab
------

### General In-lab Procedure ###

The purpose of the labs is to allow you to work through the lab activity, and if you encounter questions or problems, ask for TA assistance.  Be sure to include your name, email ID, the date, and the name of the file in a banner comment at the beginning of each file you submit.

### Understanding C++ ###

1. Ask the TAs if you have questions about your *x^n* function.
2. Ask the TAs if you have questions about using Unix.
3. Object Lifecycle Program
     - Download the [lifecycle.cpp](lifecycle.cpp.html) ([src](lifecycle.cpp)) file
     - Compile with clang++ (i.e., `clang++ lifecycle.cpp`) and execute the program.
     - Break lifecycle.cpp into multiple files.  It may be helpful to look at the [class slides](../../slides/01-cpp.html).  Compile and run this program.  Note that to compile a C++ program with multiple files, just put them on the same line: `clang++ LifeCycle.cpp TestLifeCycle.cpp` (you usually leave out the .h files when compiling).  Add the descriptive header at the top of the file containing your identifying information, and name them as follows:
         - LifeCycle.h
         - LifeCycle.cpp
         - TestLifeCycle.cpp
     - Comment out the prototype for `getMaxMyObj()`.  Recompile.  What happens and why?  Talk to TA if you are unsure.  Now un-comment the prototype.
     - Look at the output of lifecycle.cpp.  Write at least one question about something in this program. Write your questions in a text file named lifecycle.questions.txt.  Remember to include the header comment at the top of the file.
4. Using C++ vector container class with strings
     - There are 3 files on this repo that demonstrate the use of multi-file programs and the use of the vector collection class in C++: [svtest.cpp](svtest.cpp.html) ([src](svtest.cpp)), [svutil.cpp](svutil.cpp.html) ([src](svutil.cpp)), and [svutil.h](svutil.h.html) ([src](svutil.h)).  The class in those files is similar to the ArrayList class in the Java standard library (or Java's own Vector class).  Compile the program in Unix and run it.  The command `clang++ svutil.cpp svtest.cpp` will compile the program.
     - Comment out the `#include <iostream>` preprocessor directive in the file svtest.cpp, and then rebuild the program.  Was there an error?
     - Now undo what you did in the previous step, but now comment out the `using namespace std;` in svutil.h, and rebuild the program. Was there an error?  What objects are now undeclared and why?
     - Write at least one question about something in this program.  This question might be about something that you don't understand completely. Write your questions in a file named vector.questions.txt.

### Capitalization ###

Under Windows, the case of a file name is ignored -- thus, lifecycle.cpp, LifeCycle.cpp, and LIFECYCLE.CPP all refer to the same file.  However, it is **NOT** true for Linux, which is what we will use to test and grade your code.  Thus, if your file is called 'LifeCycle.h', and you have (in your TestLifeCycle.cpp file) a line that states: `#include "lifecycle.h"`, then your program will NOT work under Linux (since case DOES matter with file names).  Since your code does not compile, you will get zero credit.  So make sure your file names match!

### Troubleshooting ###

Does your program not compile?  Here are a few things to try -- these are problems that previous students have encountered.

- You must have `#include <iostream>` at the beginning of each file (well, really each file that uses `cin` and `cout`, but it doesn't hurt to have it at the beginning of each file).
- Likewise, you will need `using namespace std;` at the beginning of each file.
- Is your subroutine a method (i.e. part of a class) or a function (i.e. not part of a class)?  Make sure you know which is which!  A method has its name in the form classname::methodname, whereas a function doesn't have a class name or the double-colon.
- Make sure that your subroutine names (whether they be function names or method names) are consistent between the .h files and the .cpp files
- Have a compiler error that you don't understand?  We have the translation!  See the [compilation](../../docs/compilation.html) page, which lists common compiler error messages, what they mean, and how to solve them.  If you don't see yours listed there, let us know, and we'll add it.

------------------------------------------------------------

Post-lab
--------

Complete the exercise below, and submit the text file described there to the submission system.

### Linked List Template code ###

Download the two linked list files ([list.h](list.h.html) ([src](list.h)) and [list.cpp](list.cpp.html) ([src](list.cpp))). Compile and run the program. The compile command is `clang++ list.cpp`.  If you try to compile the list.h file, it won't work correctly.

Look at list.h, which is #include'd from list.cpp -- it contains the **bodies** of the methods, which is not the way that it is usually done (the bodies are typically in the .cpp file only).  We normally only include in .h files just the declarations (i.e., prototypes) of classes, constants, function, etc., but not definitions of C++ methods (i.e. the bodies of the methods). However, when implementing template classes, this is something that is necessary to make the class compile successfully.

Look more closely at list.cpp. The line:

```
List<int> *l = new List<int>();
```

declares (a pointer to) a List of integers, called `l`. A similar line, but with a different type, would create a list of something else.  For example, consider the following line:

```
List<char> list2;
```

This declares a (non-pointer) list of characters (this is not in the list.cpp file, by the way).  Now all the methods in the List class will be available to both `l` and `list2`.

Write at least one question about something in this program.  Put your question(s) in a text file called "postlab1.question.txt" and submit this to the submission system to the post-lab 1 assignment.
