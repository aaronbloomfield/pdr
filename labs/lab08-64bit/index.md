PDR: Laboratory 8: x86 Assembly Language, part 1 (64 bit)
=========================================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

This lab is one of two labs meant to familiarize you with the process of writing, assembling, and linking assembly language code. The purposes of the in-lab and post-lab activities are to investigate how various C++ language features are implemented at the assembly level.

There are both [32 bit](../lab08-32bit/index.html) ([md](../lab08-32bit/index.md)) and [64 bit](../lab08-64bit/index.html) ([md](../lab08-64bit/index.md)) versions of this lab.  This is the ***64 bit version***.

### Background ###

The Intel x86 assembly language is currently one of the most popular assembly languages and runs on many architectures from the x86 line through the Pentium 4.  It is a [CISC](http://en.wikipedia.org/wiki/Complex_instruction_set_computing) instruction set that has been extended multiple times (e.g. [MMX](http://en.wikipedia.org/wiki/MMX_%28instruction_set%29)) into a larger instruction set.  In 2004 it was extended to allow for a 64 bit memory space.

### Reading(s) ###

1. Read the [slides on 64 bit x86](../../slides/08-assembly-64bit.html)
2. The x86 book chapters on [x86](../../book/x86-64bit-asm-chapter.pdf) and the [C calling convention](../../book/x86-64bit-ccc-chapter.pdf)
3. An optional online reading is [x86-64 Machine-Level Programming](https://www.cs.cmu.edu/~fp/courses/15213-s07/misc/asm64-handout.pdf) from CMU, although they use the other assembly language format


Procedure
---------

### Pre-lab ###

1. You should be familiar with the readings described above.  They detail the x86 material that this lab requires.
2. Complete the tutorial, which consists of reading the x86 book chapters on [x86](../../book/x86-64bit-asm-chapter.pdf) and the [C calling convention](../../book/x86-64bit-ccc-chapter.pdf).
3. Read through the section, below, on compiling C++ with assembly on different architectures, as well as the vecsum program.
4. There are different program formats for different architectures, and this pre-lab **must** be submitted in the submission format for this lab (see the next section, below).  If you do not submit it in the required format (64-bit Linux), you will not receive credit for the lab, as it will not compile.
5. Follow the pre-lab instructions in this document.  They require you to write a program in x86 assembly called mathlib.s.  To see other examples of nasm code, you should look at the vecsum.s program, as well as the code in the nasm tutorial.
6. Make sure your mathfun.cpp takes in only the input described in the pre-lab section!  Input is to be provided via standard input (i.e., `cin`), not through command-line parameters.
7. Your code must compile with `make`!
     - And does your code work on a 64-bit Linux machine?  It will need to in order to receive credit.
     - You may need to SSH into a lab machine to run your code. To do so, follow the instructions in the SSH/SCP tutorial.
8. Files to download [vecsum.s](vecsum.s.html) ([src](vecsum.s)), [main.cpp](main.cpp.html) ([src](main.cpp)), [Makefile](Makefile.html) ([src](Makefile))
9. Files to submit mathlib.s, mathfun.cpp, Makefile

### In-lab ###

1.  Make sure you have completed the reading on the C calling convention.
2.  Follow the in-lab instructions in this document. Your assignment is to write a function in x86 assembly called mergeSort. The merge function is provided in mergeSort.s.
3.  Your code must compile with `make`. It must work on a 64-bit Linux machine.
4.  When finished with the in-lab, begin working on the post-lab report.
5.  Files to download: [mergeSort.s](mergeSort.s.html) ([src](mergeSort.s)), [testMergeSort.cpp](testMergeSort.cpp.html) ([src](testMergeSort.cpp))
6.  Files to submit: mergeSort.s, testMergeSort.cpp, Makefile

### Post-lab ###

1.  Write a report that explains the topics listed in the post-lab section below. Be sure to address all the issues in each topic!
2.  Files to download: none (other than the results of your pre-lab and in-lab)
3.  Files to submit: postlab8.pdf

------------------------------------------------------------

Platform Architectures
-----------------------


### Different Architectures ###

There are two different platforms that students are potentially developing their code on:

1. 64-bit Linux (what is on the VirtualBox image and what the submission server is running, as well as what is installed on the computers in Rice 340 and Olsson 001)
2. 64-bit Mac OS X

**Your code must compile and run on the submission server, which is a 64-bit Linux machine!**

There are three changes that will have to be made to compile your program (and thus to the Makefile) depending on your own development platform:

- You will have to determine whether to name your function `vecsum` instead of `_vecsum` (note the lack of underscore in the former) in vecsum.s (this file is described more below).  In the final linking step, if you get a message such as, `main.cpp:(.text+0x12): undefined reference to 'vecsum'`, then you should change the name of the function.
- Some systems will have to supply a command-line parameter to clang++; this can be put on the `CXX` or `CXXFLAGS` macro(s) line in your Makefile
- All systems will have a specific nasm file format option (via `-f`) that will need to be specified.

The first bullet point highlights a compatibility problem between Linux and Mac OS X.  When calling a subroutine, which in C++ would be called `foo()`, there are two standards as to how to name the assembly routine: you can name it either `_foo` (adding an underscore is added before the name), or name it just `foo` (with no underscore).  Unfortunately, Linux uses a different standard than Mac OS X, so we have to make (minor) code modifications in order to compile the code on the other system: in Mac OS X, the vecsum.s file should have the subroutine be called `_vecsum`, and under Linux, it should be called `vecsum` (this is twice, on lines 11 and 15).

In an effort to make sure all the files submitted conform to one standard or the other, **all assembly and C/C++ code must be submitted in Linux form** (i.e. will be called `foo` and not `_foo`).  Note that in many programs, such as the vecsum.s that we provided you, you have to change the name in TWO places: on the `global` line (line 11 of vecsum.s) and on the label line (line 15 of vecsum.s).  **If your code does not compile on the submission system, you will receive zero credit!**

Also note that your code must compile with `make`.  We provide a sample Makefile that will compile vecsum, so you can just modify this Makefile to compile your pre-lab program.  **Please note that you should NOT specify a `-o` flag to clang++ (not even `-o a`)**, as we want it to be named the default (a.out).  This allows easy porting between the two operating systems.

If you plan to develop this lab in Mac OS X, we suggest that you develop it normally (putting in the `_` before the subroutine name).  Then, once you have verified everything works, remove the underscores from **all** the relevant lines, and test it out on a 64-bit Linux machine, such as the VirtualBox image, before submitting it.

### Platform Specifics ###

Each of these different platforms has different compilation lines to allow it to compile.  Some of them require changing the assembly files as well.  You only need to read the line(s) pertaining to the platform(s) you are developing on.

**64-bit Linux:** You have to explicitly tell clang++ to compile in 64-bit mode by passing in the `-m64` parameter.  All assembly subroutine names must **NOT** have a leading underscore (i.e. they should be `vecsum` and not `_vecsum`).  nasm is invoked with the `-f elf64` option.  If you are using your own Linux installation (not the course VirtualBox image), and you run into compilation issues, try installing the g++-multilib package - we realize that we are not using the g++ compiler, but this installs the correct library in the correct place (if this differs with your version of Linux, then please let us know!).

**64-bit Mac OS X:** To run the code, will need to rename all the assembly function names with a leading underscore (i.e. `_vecsum` not `vecsum`).  You will also have to use the `-f macho64` format for nasm, and tell clang++ to generate the correct architecture code.  In the provided Makefile, change the `ASFLAGS` macro line to `-f macho64` (instead of the default `-f elf64`).  You will probably want to remove the `-m64` flag on the `CXX` macro line, but be sure to put that back in before you resubmit.  Note that you **MUST** change all of this back in order for it to compile via the submission system!  Also note that some versions of Mac OS X do not support the format of assembly that we use in this course, which means that you will be stuck reading the assembly in the other format we discussed in class.

***WARNING FOR MAC OS X:*** As mentioned in the class introduction (specifically, [here](../../uva/course-introduction.html#/unixinfo)), some parts of this lab may **NOT** be compatible with Mac OS X.  So if things are not working, or the directions above are running into issues, consider reverting to the VirtualBox image.

Below is a table summarizing the changes


| Platform | nasm flag | x86 subroutine name | clang++ flags | Notes |
|---------|-----|-----|-----|-----------------------------------------|
| 64-bit Linux | -f elf64 | vecsum | -m64 | This is what our submission server is running, **and what your code must work on.**  If you have it on your computer, you must install a few packages as well - see above |
| 64 bit Mac OS X | -f macho64 | \_vecsum | ??? | We are unsure about the clang++ flags necessary.  May not be able to print the assembly in the format discussed in class. |


**IMPORANT:** Just to repeat, when you submit your code, it **MUST** be in 64-bit Linux format.

------------------------------------------------------------

Pre-lab
-------

### Compiling Assembly With C++ ###

For this part, you will need to download three files: [vecsum.s](vecsum.s.html) ([src](vecsum.s)), [main.cpp](main.cpp.html) ([src](main.cpp)), and [Makefile](Makefile.html) ([src](Makefile)).

To compile a program written partly in x86 assembly and partly in C++, we have to build the program in parts.  We build the C++ file as we have in the past:

```
clang++ -m64 -Wall -g  -c -o main.o main.cpp

```

Note that we used the -c flag, which tells the compiler to compile but not link the program.  Linking it will create the final executable -- but as there is not a `vecsum()` function defined (yet), the compiler will report an error stating that it does not know what the vecsum() function is.  The `-o main.o` part tells clang++ to put the compilation output into the file named main.o.  Note that the `-o` flag wasn't really necessary here (as clang++ will use main.o by default when compiling main.cpp), but we wanted to include it, as we are going to use it below.  We include the `-m64` flag to force it to be a 64-bit file.  We also added a few more flags (`-Wall -g`) to print all warnings and compile debugging symbols into the program.

Next, we need to compile the assembly file.  To do this, we enter the following:

```
nasm -f elf64 -g -o vecsum.o vecsum.s
```

This invokes nasm, which is the assembler that we are using for this course.  We'll get to the `-f elf64` part in a moment.  The `-o vecsum.o` option is the same as with clang++ -- it is telling the assembler to put the output into a file named vecsum.o.  If you do not specify a filename with the `-o` flag, it will default to vecsum.obj, NOT vecsum.o -- this is why we are using the `-o` flag.  We also tell it to include debugging symbols via `-g`. The assembly file name is specified by the `vecsum.s` at the end of the command line.

The new flag here is the `-f elf64`.  This tells the assembler the output format for the final executable.  Operating systems can typically execute a number of different formats.  As we are running under 64 bit Linux, we specify the elf64 format.  Mac OS X uses `-f macho64` -- see the above section for more details.

Finally, we have to link the two files into the final executable.  We do this as before:

```
clang++ -m64 -Wall -g vecsum.o main.o
```

This tells clang++ to link both of the .o files created above into an executable, which it called `a.out`.  Note that there isn't any compiling done at this stage (the compilation was done before) -- this just links the two object files into the final executable.  Also note that for our submitted Makefiles, we will NOT have the `-o` flag present.

### Tutorial ###

Complete the C++/assembly tutorial, which consists of reading the book chapters on [x86-64](../../book/x86-64bit-asm-chapter.pdf) and the [calling convention](../../book/x86-64bit-ccc-chapter.pdf). Another good reading is [x86-64 Machine-Level Programming](https://www.cs.cmu.edu/~fp/courses/15213-s07/misc/asm64-handout.pdf) from CMU. (The CMU reading uses the other assembly language format.)

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

Download [mergeSort.s](mergeSort.s.html) ([src](mergeSort.s)), as well as [testMergeSort.cpp](testMergeSort.cpp.html) ([src](testMergeSort.cpp)), which you will use to test your code. Make sure you do not alter testMergeSort.cpp, as you must include the original file in your submission. You will need to create a Makefile for the in-lab. To do so, you can copy the pre-lab Makefile and set `OFILES=mergeSort.o testMergeSort.o`.

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

Once you have completed the in-lab, submit mergeSort.s, testMergeSort.cpp, and your Makefile. **If you finish the in-lab early, you should begin working on the post-lab report.**

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

**Your grade will be based on whether you sufficiently answered and provided evidence for the above questions.**


### Tips for Getting Started on the Post-lab ###

Think about how best to investigate the issues you choose. A good starting point is to write a small C++ program that illustrates one of the issues. This program should be as simple as possible.

Look at the assembly code associated with your C++ code. To examine the disassembled code you have three options. First, you can step through the code in the debugger using the disassembly view. You can also have the C++ code output to an assembly file using `clang++ -S -mllvm --x86-asm-syntax=intel -fomit-frame-pointer fileName.cpp`, which can be viewed in emacs. Lastly, you may use the site [www.godbolt.org](https://www.godbolt.org) to view the assembly code. You can paste your C++ code directly into the editor, or upload a file. Choose either clang or gcc as your compiler.

Focus on devising experiments that will help you learn more about the particular issues. By tracing though some parts of the code, modifying your C++ code, and comparing the generated assembly for the two different versions, you should be able to come up with some reasonably good hypotheses about what is happening. Seek out resources that explain the issue. Keep in mind that you are required to list your sources in your post-lab report.

### Post-lab Report Guidelines ###

The report should be a PDF file called postlab8.pdf. See the [How to convert a file to PDF](../../docs/convert_to_pdf.html) page for details about creating a PDF file. Your report should be single spaced. In your report, label the items according to which list item they came from (parameter passing or objects), and their item number within that list. Your evidence should be embedded into the document. Highlighting portions of code or drawing arrows between things may help make your explanations clearer. For each item, you should include a short explanation (1-2 paragraphs maximum) and at least one piece of evidence. Don't forget to include at least two external resources. Other than your own experiments, feel free to use online x86 assembly references, C++ books, and resources you may find on the Internet or elsewhere. **Discussing these issues is allowed, however, remember that your code and final report must be your own work and that you must credit ANY resources used.**

We want you to investigate the particular topic area from the given list, write code to discover the answers, and learn about this topic on your own.
