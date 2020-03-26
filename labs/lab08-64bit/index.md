PDR: Laboratory 8: x86 Assembly Language, part 1 (64 bit)
=========================================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

This lab is one of two labs meant to familiarize you with the process of writing, assembling, and linking assembly language code. The purposes of the in-lab and post-lab activities are to investigate how various C++ language features are implemented at the assembly level.

There are both [32 bit](../lab08-32bit/index.html) ([md](../lab08-32bit/index.md)) and [64 bit](../lab08-64bit/index.html) ([md](../lab08-64bit/index.md)) versions of this lab.  This is the ***64 bit version***.

<h3 style="color:red"><b>Changes for the spring 2020 semester</b></h3>

<p style="color:red">Due to this course being <a href="../../uva/online.html">taught online</a> (<a href="../../uva/online.md">md</a>) in the spring of 2020, we are making the following changes for this semester, in an effort to make the workload more manageable since we are all working from home.</p>

<ul style="color:red">
<li>Pre-lab: the mathlib.s program only needs to contain just the <code>product()</code> function, as described in the pre-lab section, below.  The <code>power()</code> function will be done in the post-lab.  The rest of the pre-lab is as described in the pre-lab section; just omit the <code>power()</code> function.  Note that if you do do both functions for the pre-lab, that's fine -- but only <code>product()</code> will be graded, so you still have to submit the same code for the post-lab where <code>power()</code> will be graded.</li>
<li>In-lab: it is the same as described in the in-lab section below.</li>
<li>Post-lab: the post-lab section below is not to be done; instead, finish the <code>power()</code> function from the pre-lab.  Thus, the post-lab submission is to be what is described in the pre-lab section, below (i.e., both <code>product()</code> and <code>power()</code>).</li>
</ul>


### Background ###

The Intel x86 assembly language is currently one of the most popular assembly languages and runs on many architectures from the x86 line through the Pentium 4.  It is a [CISC](http://en.wikipedia.org/wiki/Complex_instruction_set_computing) instruction set that has been extended multiple times (e.g. [MMX](http://en.wikipedia.org/wiki/MMX_%28instruction_set%29)) into a larger instruction set.  In 2004 it was extended to allow for a 64 bit memory space.

### Tutorial ###

The tutorial for this lab is the following two readings on [x86](../../book/x86-64bit-asm-chapter.pdf) and the [C Calling convention](../../book/x86-64bit-ccc-chapter.pdf).

### Recommended Readings ###

1. Read the [slides on 64 bit x86](../../slides/08-assembly-64bit.html)
2. The x86 book chapters on [x86](../../book/x86-64bit-asm-chapter.pdf) and the [C calling convention](../../book/x86-64bit-ccc-chapter.pdf)
3. The [x86 Call Stack](https://www.youtube.com/watch?v=XbZQ-EonR_I) introduction from the University of Washington
4. An optional online reading is [x86-64 Machine-Level Programming](https://www.cs.cmu.edu/~fp/courses/15213-s07/misc/asm64-handout.pdf) from CMU, although they use the other assembly language format
5. An optional [Medium article](https://medium.com/@connorstack/a-guide-to-x86-calling-convention-824a3236ed65) stepping through the calling convention once again.


Procedure
---------

### Pre-lab ###

1. Understand how to compile x86 assembly code
2. Review the sample `vecsum.s` program
3. Write a program in x86, `mathlib.s`, to compute the product of two numbers and power of two numbers
4. Create a C++ program, `mathfun.cpp`, to call the functions in `mathlib.s`
5. Ensure your code compiles on a x64 Linux machine
8. Files to download [vecsum.s](vecsum.s.html) ([src](vecsum.s)), [main.cpp](main.cpp.html) ([src](main.cpp)), [Makefile](Makefile.html) ([src](Makefile))
9. Files to submit mathlib.s, mathfun.cpp, Makefile

### In-lab ###

2. Write an x86 function to perform merge sort
5. Files to download: [mergeSort.s](mergeSort.s.html) ([src](mergeSort.s)), [testMergeSort.cpp](testMergeSort.cpp.html) ([src](testMergeSort.cpp))
6. Files to submit: mergeSort.s, testMergeSort.cpp, Makefile

### Post-lab ###

1. Write a report that explains how parameter passing occurs and how objects are represented in x86
2. Files to download: none
3. Files to submit: postlab8.pdf

------------------------------------------------------------

Platform Architectures
-----------------------

There are a few differences when writing x86 assembly code, depending on whether you are using Linux or macOS.
Specifically, the object file format for nasm will differ, as well as the subroutine name itself.
The instructions in this lab will assume the use of Linux -- if you are using macOS, use the table below for the correct instructions.

| Platform | nasm flag | x86 subroutine name |
| -------- | --------- | ------------------- |
| 64-bit Linux | -f elf64 | `vecsum` |
| 64 bit macOS | -f macho64 | `_vecsum` |

Some additional notes:

- The subroutine name must be changed everywhere it appears in the assembly file, including in `global`
- On Linux, you may need to install the `g++-multilib` command for compilation to succeed

**IMPORTANT:** When you submit your code, it **MUST** be in 64-bit Linux format.

------------------------------------------------------------

Pre-lab
-------

### Compiling Assembly With C++ ###

For this part, you will need to download three files: [vecsum.s](vecsum.s.html) ([src](vecsum.s)), [main.cpp](main.cpp.html) ([src](main.cpp)), and [Makefile](Makefile.html) ([src](Makefile)).

To compile a program written partly in x86 assembly and partly in C++, we have to build the program in parts.  We build the C++ file as we have in the past:

```
clang++ -Wall -g -c main.cpp

```

Note that we used the -c flag, which tells the compiler to compile but not link the program.  Linking it will create the final executable -- but as there is not a `vecsum()` function defined (yet), the compiler will report an error stating that it does not know what the vecsum() function is.  We also added a few more flags (`-Wall -g`) to print all warnings and compile debugging symbols into the program.

Next, we need to compile the assembly file.  To do this, we enter the following:

```
nasm -f elf64 -g vecsum.s
```

This invokes `nasm`, which is the assembler that we are using for this course.  `-f elf64` tells nasm to output the object file using the ELF 64-bit format, which is specific to Linux (and would need to be changed to `-f macho64` for macOS as detailed above).  We also tell it to include debugging symbols via `-g`. The assembly file name is specified by the `vecsum.s` at the end of the command line.

Finally, we have to link the two files into the final executable.  We do this as before:

```
clang++ -Wall -g vecsum.o main.o
```

This tells clang++ to link both of the .o files created above into an executable, which it called `a.out`.  There isn't any compiling done at this stage -- this just links the two object files into the final executable.

### Vecsum ###

Examine the vecsum subroutine in [vecsum.s](vecsum.s.html) ([src](vecsum.s)).  Use the slides and readings to help understand what is happening in vecsum.s.  Make sure you understand the prologue and epilogue implementation, as well as the instructions used in the subroutine.

Compile and run the vecsum program:

- Use the tutorial as a guide, but see the instructions above.
- If you forget the lldb commands described below, see the [LLDB command summary](../../docs/lldb_summary.html), which has a summary of all of these commands.
- You can find the assembly and C++ source code in the repository ([vecsum.s](vecsum.s.html) ([src](vecsum.s)), [main.cpp](main.cpp.html) ([src](main.cpp)), [Makefile](Makefile.html) ([src](Makefile))).  For the C++ code compilation (i.e. main.cpp) and the final link, use the `-g` flag, which allows the program to work well with the lldb debugger.
- Use the debugger to step through the assembly code, view the register contents, and view the computer's memory.
- Set a breakpoint at the line in the main.cpp where the vecsum() function is called (probably line 38).
- Normally, you would use the `step` function to step into the next instruction.  However, since no debugging information was included with the assembler (a shortcoming of nasm), we can't use `step` -- it will just move to the next C++ instruction (the `cout`).  Instead, we will use `stepi`, which will step exactly one *assembly instruction*, which is what we want.
- To display the assembly code that is currently being executed, enter `disassemble`.  This is just like `list`, but it displays the assembly code instead of the C++ code.
- Note that this prints things in a different assembly format.  To set the format to the style we are used to (and the style we are programming in with nasm), enter `settings set target.x86-disassembly-flavor intel`.  Now enter `disassemble` again -- the format should look more familiar.  You only have to enter that set command once (unless you exit and re-enter lldb).
- To see the vecsum function, enter `disassemble --name vecsum`.  Note that this only lists the first third (or so) of the routine -- up until the `start` label.  To see the rest of the code, enter `disassemble --name start`, `disassemble --name done`, etc.
- To show the contents of the registers, use the `info registers` command.

### Pre-lab program: mathlib.s ###

You will need to write two routines in assembly, one that computes the product of two numbers, and one that computes the power of two numbers.

The first subroutine will compute the product of the two integer parameters passed in.  The restrictions are that it **can only use addition**, and thus cannot use a multiplication operation.  We will assume that both of the parameters are positive integers.  It must compute this **iteratively**, not recursively.  The resulting product is then returned to the calling routine.  This subroutine should be called `product`.  We will assume that values will not be provided to the subroutine that will cause an overflow, nor will negative (or zero) parameters be passed in.

The second subroutine will compute the power of the two integer parameters passed in.  We will assume that the first parameter is the base, and the second parameter is the exponent.  Again, both are integers.  The restrictions on this routine are that it **can only use the multiplication** routine described above -- it cannot use `imul` or call any exponentiation routine. Furthermore, it must be defined **recursively**, not iteratively.  This routine should be called `power`.

You can assume that the numbers passed into both routines will both be positive, so you need not consider negative numbers or zero.  Furthermore, as described above, no values will be used on your program that could cause an integer overflow.

Both of these routines should be in a file called mathlib.s, and must use the proper C-style calling convention.  You must also provide a mathfun.cpp file, which calls both of your subroutines -- see the main.cpp file provided as a template.  The program should take in ONLY two integers (we'll call them *x* and *y*).  It should then print out the output of calling `product(x,y)` and `power(x,y)`.  Thus, if the input is 3 and 4, it would print out 12 and 81.

Input is to be read via standard input (i.e., `cin`), not through command-line parameters.

In order for routines in an assembly file to be callable from C/C++, you need to declare them with `global`, like is done in `vecsum.s`.  To have multiple routines in a single assembly file (as is needed for mathlib.s), you should have multiple `global` lines, one for each subroutine that you plan on calling from your C/C++ code.

------------------------------------------------------------

In-lab
------

Come to lab with a functioning version of the pre-lab, and be prepared to demonstrate that you understand how to build and run the pre-lab programs. If you are unsure about any part of the pre-lab, talk to a TA. You should be able to explain and write recursive functions in assembly for the exams in this course, so make sure that you understand how to implement the pre-lab program.

Before starting the in-lab, make sure you read and understand the book chapters on the C calling convention. For the in-lab, you will be implementing merge sort in x86 assembly. We have provided the helper function `merge` in mergeSort.s. Note: `merge` makes use of two caller-saved registers, r10 and r11. **Remember to save and restore these registers** before and after calling `merge`.

Download [mergeSort.s](mergeSort.s.html) ([src](mergeSort.s)), as well as [testMergeSort.cpp](testMergeSort.cpp.html) ([src](testMergeSort.cpp)), which you will use to test your code. Make sure you do not alter testMergeSort.cpp, as you must include the original file in your submission.

Your task for the in-lab is to implement the `mergeSort` function in mergeSort.s. This function takes in three parameters. The first parameter is a pointer to an int array. The second parameter is an integer corresponding to the left index in the array. The third parameter is an integer corresponding to the right index in the array. The return type of this function is void, and it modifies the original array. You may assume the size of the array is nonzero. When testing your function using testMergeSort.cpp, input will be read via standard input, not through command-line parameters. After entering the array size, you will be prompted to enter each element one by one. This test file will call your `mergeSort` function on the array, and print the result. Make sure you test your function on arrays of various sizes.

### Sample Execution Run

Below is a sample execution run to show you the input and output format we are looking for.

    Enter the array size: 5
    Enter value 0: -7
    Enter value 1: 2
    Enter value 2: -39
    Enter value 3: 12
    Enter value 4: 8
    Unsorted array: -7 2 -39 12 8
    Sorted array: -39 -7 2 8 12

The following resource explains the merge sort algorithm. This is what you need to implement in x86 assembly: [www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/](https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/)

Once you have completed the in-lab, submit mergeSort.s, testMergeSort.cpp, and your Makefile.

------------------------------------------------------------

Post-lab
--------

For the post-lab, you should investigate and understand the topics below, and prepare a report that explains your findings. Follow the guidelines in the Post-lab Report Guideline section. You must show evidence of your conclusions in the form of assembly code, C++, screenshots, memory dumps, manual quotations, output, etc. Use test cases and the debugger as resources. Additionally, use resources other than yourself (e.g. books, reputable websites) and external to the course (i.e. "the TAs" or "lecture" don't count). ***You must use (and cite!) at least TWO additional resources for this post-lab!***


### Post-lab 8 topics ###

The questions below are what you must address in your post-lab report. Make sure you answer each part and include sufficient evidence. You should create a simple class to help you answer the following questions. In your class, be sure to include several methods and at least 5 data members of different types and access levels (public and private).

### Parameter passing ###

Show and explain assembly code generated by the compiler for a simple function and function call that passes parameters by a variety of means. Show what is happening both in the caller and in the callee. You do not need to describe parts of the C calling convention we described in class (e.g. saving registers, saving the base pointer, how the call instruction works). The focus here is on examining in detail what happens when parameters are passed.

1.  How are variables (ints, chars, pointers, floats, etc.) passed by value? How are they passed by reference? Create several functions and examine the parameter registers to help you answer this question.
2.  Create a simple function that takes in an object. How are objects passed by value? How are they passed by reference? Specifically, what is contained in the parameter registers in each case?
3.  Create an array in your main method, and write a function that takes it in as a parameter. How are arrays passed into functions? How does the callee access the parameters? Where are the data values placed? Hint: you will need to determine at least a register-relative address.
4.  Is passing values by reference different than passing by pointer? If they are the same, what exactly is passed in the parameter register? If they are different, how so?

### Objects ###

1.  How is object data laid out in memory? Create an object in your main method, and view where each data member is located in memory. How does C++ keep different fields of an object "together"?
2.  Explain how data member access works for objects. How does the assembly know which data member to access? We know how local variables and parameters are accessed (offsets from the base pointer) -- describe how this is done for data fields.
3.  How does method invocation work for objects? Specifically, how does the assembly know which object it is being called out of? Remember that assembly is not object oriented.
4.  How are data members accessed both from inside a member function and from outside? In other words, describe what the assembly code does to access data members in both of these situations.
5.  How are public member functions accessed for your class? Call some of the public member functions for your class and examine the parameters. How is the "this" pointer implemented? Where is it stored? When is it accessed? How is it passed to member functions?

### Tips for Getting Started on the Post-lab ###

Think about how best to investigate the issues you choose. A good starting point is to write a small C++ program that illustrates one of the issues. This program should be as simple as possible.

Look at the assembly code associated with your C++ code. To examine the disassembled code you have three options. First, you can step through the code in the debugger using the disassembly view. You can also have the C++ code output to an assembly file using `clang++ -S -mllvm --x86-asm-syntax=intel -fomit-frame-pointer fileName.cpp`, which can be viewed in emacs. Lastly, you may use the site [www.godbolt.org](https://www.godbolt.org) to view the assembly code. You can paste your C++ code directly into the editor, or upload a file. Choose either clang or gcc as your compiler.

Focus on devising experiments that will help you learn more about the particular issues. By tracing though some parts of the code, modifying your C++ code, and comparing the generated assembly for the two different versions, you should be able to come up with some reasonably good hypotheses about what is happening. Seek out resources that explain the issue. Keep in mind that you are required to list your sources in your post-lab report.

### Post-lab Report Guidelines ###

The report should be a PDF file called postlab8.pdf. In your report, label the items according to which list item they came from (parameter passing or objects), and their item number within that list. Your evidence should be embedded into the document. Highlighting portions of code or drawing arrows between things may help make your explanations clearer. For each item, you should include a short explanation (1-2 paragraphs maximum) and at least one piece of evidence. Don't forget to include at least two external resources. Other than your own experiments, feel free to use online x86 assembly references, C++ books, and resources you may find on the Internet or elsewhere. **Discussing these issues is allowed, however, remember that your code and final report must be your own work and that you must credit ANY resources used.**

We want you to investigate the particular topic area from the given list, write code to discover the answers, and learn about this topic on your own.
