PDR: Laboratory 9: x86 Assembly Language, part 2 (64 bit)
=========================================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

This lab is one of two labs meant to familiarize you with the process of writing, assembling, and linking assembly language code. The purposes of the in-lab and post-lab activities are to investigate how various C++ language features are implemented at the assembly level.

There are both [32 bit](../lab09-32bit/index.html) ([md](../lab09-32bit/index.md)) and [64 bit](../lab09-64bit/index.html) ([md](../lab09-64bit/index.md)) versions of this lab.  This is the ***64 bit version***.

### Background ###

The Intel x86 assembly language is currently one of the most popular assembly languages and runs on many architectures from the x86 line through the Pentium 4.  It is a CISC instruction set that has been extended multiple times (e.g. MMX) into a larger instruction set.

### Tutorial ###

Read the [C tutorial](../../tutorials/09-c/index.html) for the post-lab.

### Recommended Readings ###

1. Read the [slides on x86](../../slides/08-x86.html)
2. The two book chapters on x86: [x86 Assembly](../../book/x86-64bit-asm-chapter.pdf) and [The x86 C Calling Convention](../../book/x86-64bit-ccc-chapter.pdf).
3. The [x86 Assembly Guide](http://www.cs.virginia.edu/~evans/cs216/guides/x86.html) from an older course at UVA (ignore the section on Calling Convention)

Lab Procedure
-------------

### Pre-lab ###
1. Create an assembly program to demonstrate the Collatz conjecture
2. Time your program using a helper C++ file
3. Optimize your program and list all optimizations used
4. Files to download: [timer.cpp](../lab06/code/timer.cpp.html) ([src](../lab06/code/timer.cpp)), [timer.h](../lab06/code/timer.h.html) ([src](../lab06/code/timer.h)) (from the lab 6 directory)
5. Files to submit: threexplusone.s, threexinput.cpp, timer.cpp, timer.h, Makefile

### In-lab ###

1. Write a report that addresses one of the topics listed in the in-lab section
2. Files to download: none (other than the results of your pre-lab)
3. Files to submit: inlab9.pdf

### Post-lab ###

1. Implement the linkedlist.c program from [Tutorial 9: C](../../tutorials/09-c/index.html) ([md](../../tutorials/09-c/index.md))
2. Write another report that addresses two topics listed in the in-lab section (the first topic is the one you started in the in-lab; the second one is new for the post-lab)
3. Files to download: none (other than the results of your pre-lab and in-lab)
4. Files to submit: postlab9.pdf, linkedlist.c, Makefile

----

Pre-lab
-------

You may want to reference the "Compiling Assembly With C++" and "Vecsum" sections from the [previous x86 lab](../lab08-64bit/index.html).

### The Collatz Conjecture ###

The 3x+1 conjecture (also called the Collatz conjecture) is an open problem in mathematics, meaning that it has not yet been proven to be true.  The conjecture states that if you take any positive integer, you can repeatedly apply the following function to it:

![](formula.png)

The conjecture is that eventually, the result will reach 1.  For example, consider *x* = 13:

1. *f*(13) = 3 \* 13 + 1 = 40
2. *f*(40) = 40 / 2 = 20
3. *f*(20) = 20 / 2 = 10
4. *f*(10) = 10 / 2 = 5
5. *f*(5) = 3 \* 5 + 1 = 16
6. *f*(16) = 16 / 2 = 8
7. *f*(8) = 8 / 2 = 4
8. *f*(4) = 4 / 2 = 2
9. *f*(2) = 2 / 2 = 1

Note that this took 9 steps to reach the value 1.  And it also shows that this conjecture is true for a number of other values (2, 4, 5, 8, 10, 16, 20, and 40).

[An image](Collatz-graph-all-30-no27.png) (from Wikipedia) shows how paths of most integers less than 50 converge to 1.

While this conjecture has been proven only up to at least 5.6 * 10^13, it is widely believed to be true for all positive integers.  If you are interested, more information on this conjecture can be found [here](http://en.wikipedia.org/wiki/Collatz_conjecture).

We won't be testing with any values above 10^13, so you can safely assume that the Collatz conjecture holds true for all of the input values that we will use.

Your task is to write a routine, called `threexplusone`, that takes in a positive integer and returns the number of steps required for that integer to reach 1 by following the Collatz conjecture.  An input of 13 takes 9 steps, as shown above.  The Wikipedia page shows a few other input sizes and the number of steps: an input of 6 takes 8 steps; an input of 14 takes 17 steps; an input of 27 takes 111 steps.  If the input is 1, the output should be zero.

This routine ***MUST*** call itself recursively using the proper C-style calling convention.  The assembly code should be in a threexplusone.s file.  **If you write your function so that it is an iterative solution, you will not receive credit for this pre-lab.**

### Testing and timing ###

You will need to write a C++ file called threexinput.cpp that allows you to test your subroutine.
This input file should:

1. Ask for an input value, *x*, which is the positive integer to pass to the subroutine
2. Ask for an input value, *n*, which is the number of times to call the subroutine
3. Run the subroutine once and print out the result
4. Run the subroutine *n* times with the parameter *x* as the input

You can assume that both *x* and *n* are positive integers.

We can now time the subroutine to see how fast it runs.  Download the timer code from the hash table lab (lab 6: [timer.cpp](../lab06/code/timer.cpp.html) ([src](../lab06/code/timer.cpp)) and [timer.h](../lab06/code/timer.h.html) ([src](../lab06/code/timer.h))) and use it to print out the average time it took for each function call in step 4 to run.

You should use an appropriate precision number to make sure you don't report zero when you divide the total time by the number of runs.  Your timer code should only include the loop of *n* times that calls the routine with *x* as the parameter.  Nothing else (including the print statement) should be inside the timer code.

### Optimization ###

Now that you can time your program, you will need to optimize it as much as possible.  Any optimization is valid, as long as it computes the correct result, is still a recursive subroutine, and follows the C calling convention.  The grade on this pre-lab will be based both on the correctness of the subroutine and the optimizations included.

What optimizations do you use?

- First, try to figure out how you can write the same routine using fewer x86 instructions.  x86 has lots of complex instructions that can be used for this purpose -- Google is your friend, here.
- `lea` can quickly add and multiply numbers in one instruction.
- Multiplication and division are expensive.  Try to use bit shifts whenever possible -- `4*x+x` is likely to be faster than `5*x`, as the former can be optimized to `x << 2 + x`.
- Branching slows down the execution speed of a program as the branch condition must be checked every iteration.  As much as possible, eliminate branching (if/else statements, loops, etc.).  For loops, consider [loop unrolling](http://en.wikipedia.org/wiki/Loop_unrolling).
- Consider the [memory hierarchy](http://en.wikipedia.org/wiki/Memory_hierarchy) and try to reduce memory accesses (this includes `push` and `pop`).
- Reduce the number of instructions used to create (and remove) the activation record; this was done in a few x86 examples we studied: [max](../../slides/08-assembly-64bit.html#/max) and [fact](../../slides/08-assembly-64bit.html#/fact)
- Reduce the registers that are backed up to the stack in the calling convention
- Many optimizations are listed [here](http://en.wikipedia.org/wiki/Category:Compiler_optimizations), but most would not apply to this one program.

You will need to include at least one optimization beyond just figuring out how to write your subroutine with fewer instructions.  You should put the optimizations used as a comment in the beginning of your assembly file.

Note that we, too, can write the function in C++ and compile it with `clang++ -O2 -S -mllvm --x86-asm-syntax=intel`.  And we will be looking at that assembly code when we grade the pre-lab.  If you write your program this way, it constitutes an honor violation, so please hand-code the assembly yourself.

You may find the `cdq` instruction useful -- do a Google search for 'cdq x86' or 'cdq intel'.

**You must list, as comments in your assembly file, the optimizations that you used!**  Just a brief description of what optimizations you used is fine.

### Different Architectures ###

See the [last lab](../lab08/index.html) for details, but all code must be submitted to run under Linux, which is the platform that does the compilation on the submission system.

------------------------------------------------------------

In-lab
------

Come to lab with a functioning version of the pre-lab, and be prepared to demonstrate that you understand how to build and run the pre-lab programs.  If you cannot, work through the tutorial during lab.  If you are unsure about any part of the pre-lab, talk to a TA.  The in-lab will ask you to write C++ code and examine the generated assembly language for a variety of topics.

You should be able to explain and write recursive functions for the final exam, so make sure that you understand how to implement the pre-lab program.  Speak to a TA if you have any questions.

The general activity of this in-lab will be to write small snippets of C++ code, compile them so that you can look at the generated assembly code, then make modifications and recompile as needed in order to deduce the representation of a number of C++ constructs, listed below.  Remember that we are compiling using `clang++ -S -m64 -mllvm --x86-asm-syntax=intel`.

For the in-lab, you will need to work on one of the items in the list below -- note that this is a different list than the previous lab.  You will do a second topic for the post-lab.  You should be prepared to explain the appropriate items from the list to the TA.

The deliverable for the in-lab is a PDF document named inlab9.pdf.  It must be in PDF format!  See [How to convert a file to PDF](../../docs/convert_to_pdf.html) page for details about creating a PDF file.

In your report, you should explain something from one item in the list in the in-lab report.  Note that for the post-lab, you will have to have two of the items fully explained, but you need only get through one for the in-lab.  Your report would presumably include the code snippets (both C++ and assembly) that you generated during lab, images, screen shots, results, etc.

Recall that using the `-S` flag with g++ will generate the assembly code.  You will also want to use the `-S -m64 -mllvm --x86-asm-syntax=intel` flags.

### Topic List

For the in-lab, you have to address one topic; either the required one or an optional one.  For the post-lab, you will have to address two total topics: the one you addressed from the in-lab, and one additional one for the post-lab.  Note that everybody has to address the dynamic dispatch one, but it is your call whether you do that for the in-lab or the post-lab.

#### Required ####
1. Dynamic dispatch: Describe how dynamic dispatch is implemented.  Note that dynamic dispatch is NOT the same thing as dynamic memory!  Show this using a simple class hierarchy that includes virtual functions.  Use more than one virtual function per class.

#### Optional ####
1. Inheritance (data layout, construction, and destruction): Create an instance of an object that inherits data members from another class, and also includes data members of its own.  Show in memory where data members are laid out in that object.  Then explain how construction and destruction happens in this class hierarchy.  Explain what happens when a user-defined object is instantiated and what happens when it goes out of scope.  What if anything is "destroyed" by the destructor?  Show this process happening in the assembly code using a simple class hierarchy.  Point out in the assembly code exactly where the destructors and constructors are getting called.

2. Optimized code: Compare code generated normally to optimized code.  To create optimized code, you will need to use the `-O2` compiler flag.  Can you make any guesses as to why the optimized code looks as it does?  What is being optimized?  Be sure to show your original sample code as well as the optimized version.  Try loops and function calls to see what "optimizing" does. Be aware that if instructions are "not necessary" to the final output of the program then they may be optimized away completely!  This does not lead to very interesting comparisons.  Describe at least four (non-trivial) differences you see between 'normal' code and optimized code.

3. Templates:  What does the code look like for the instantiation of a simple templated class you wrote?  What if you instantiate the class for different data types, what code is generated then?  Is it the same or different?  If the same, why? If different, why?  Compare code for a user-defined templated class or function to a templated class from the STL (e.g. classes such as vectors or functions such as sort).

------------------------------------------------------------

### Post-lab ###

### Complete the C tutorial's exercise program ###

Read the [C tutorial](../../tutorials/09-c/index.html).  You will need to implement the linkedlist.c program.


### Report! ###

Explore, investigate, and understand two of the four topics from the topic list shown in the in-lab section.  The topic addressed during the in-lab is one of these; for the post-lab, you have to address one other.  Be able to answer "how" and possibly "why" for each item.  Use test cases and the debugger as resources.  Additionally, use resources other than yourself (e.g. books, reputable websites) and external to the course (i.e. "the TAs" or "lecture" don't count towards these sources). Be sure to credit these sources.  ***You must use (and cite!) additional resources for this post-lab!***

Prepare a report that explains your findings.  Follow the guidelines in the Post-lab Report Guidelines section from the previous lab.  Address the following: How the compiler implements the construct at the machine and assembly levels.  What leads you to this conclusion?  You must show evidence of this behavior in the form of assembly code, C++, screenshots, memory dumps, manual quotations, output, etc.  Also include where you found the information that lead to your conclusion. (i.e. your sources).

The deliverable for the in-lab is a Word document named postlab9.pdf.  It must be in PDF format!  See [How to convert a file to PDF](../../docs/convert_to_pdf.html) page for details about creating a PDF file.

### Tips for Getting Started on the Post-lab ###

See the section in the previous lab for these tips.

### Post-lab Report Guidelines ###

See the section in the previous lab for these guidelines.

### How much are we looking for? ###

We want you to investigate the particular topic area from the given list, write code to discover the answers, and learn about this topic on your own.  The questions that we pose are just meant to get you thinking about the possible ramifications of a given question.  They aren't meant to be specific questions that necessarily need answering one at a time.

As with the previous lab, I would expect the explanation of each item (you have to do two items) to be a page or two long, including embedded code snippets and screenshots (obviously, we want a reasonable amount of English text here -- if you do a lot of screen shots, then your total length will be a bit longer).  Did you investigate the topic?  Did you write code to discover what you didn't know?  Was this written in a reasonably readable format?  This is what we are looking for.

This is somewhat vague, and purposely so -- research is often vague.  If we told you exactly what to write, then there wouldn't be much discovery of that on your part, which would defeat the whole point of this lab.

**We are not looking for you to spend hours and hours and hours on this!**  A *page or two* per list item (and you have to do two of them) - which means your final report needs to be 2-4 pages long.  Keep in mind if you have a lot of screenshots, that doesn't count much towards that page limit.

The grading will be based on a set of points that we would expect you to discover when investigating a given topic.  Your grade will be based mostly on how well you hit those points.  A small portion of your grade will be based on the overall report presentation and written ability (while we are a computer science class, we expect you to be able to write in English to some extent!).
