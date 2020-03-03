PDR: Laboratory 7: IBCM Programming
===================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

To become familiar with programming with IBCM, and understand how high-level language programs are represented at the machine level.

### Background ###

IBCM (Itty Bitty Computing Machine) is a simulated computer with a minimal instruction set.  Despite its tiny instruction set, IBCM can compute anything that a modern computer can.

### Tutorial ###

The tutorial for this lab is the remainder of the [Wikibooks article on Bash Shell Scripting](https://en.wikibooks.org/wiki/Bash_Shell_Scripting).
The tutorial will be necessary for the post-lab, though you may read through it earlier if you'd like.

### Recommended Readings ###

1. Read the [slides on IBCM](../../slides/07-ibcm.html)
2. Read [IBCM book chapter](../../book/ibcm-chapter.pdf) (PDF)
3. Run IBCM code online [here](https://pegasus.cs.virginia.edu/ibcm/).  The sample code in the book chapter is also in the repo: [summation.ibcm](../../ibcm/summation.ibcm) and [array-summation.ibcm](../../ibcm/array-summation.ibcm)

Procedure
---------

### Pre-lab ###

1. Write two IBCM programs to familiarize yourself with IBCM
2. Files to download: None
3. Files to submit: addition.ibcm, array.ibcm

### In-lab ###

1. Implement bubble sort in IBCM
2. Files to download: [bubblesort.cpp](bubblesort.cpp.html) ([src](bubblesort.cpp))
3. Files to submit: bubblesort.ibcm

### Post-lab ###

1. Improve your `averagetime.sh` shell script using what you learned in the tutorial
2. Implement a quine in IBCM
3. Write a report on your experience with IBCM
4. Files to download: [counter.cpp](counter.cpp.html) ([src](counter.cpp)), [timer.cpp](timer.cpp.html) ([src](timer.cpp)), [timer.h](timer.h.html) ([src](timer.h))
5. Files to submit: averagetime.sh, quine.ibcm, postlab7.pdf

------------------------------------------------------------

Pre-lab
-------

For the pre-lab, you will need to write two IBCM programs.
The programs will need to have an .ibcm extension when submitting, but they are text files, so you can still edit them in Emacs.

### addition.ibcm ###

Write an IBCM program that:

- Gets three values from user input
- Stores the values into three variables
- Adds the variables together, and prints the sum (you may use additional memory if you wish)
- If the sum is zero, prints the three values and stops
- If the sum is not zero, starts over (tries to get three values, etc.)

### array.ibcm ###

Write another IBCM program that finds the maximum value in a hardcoded array of values.

- The array base address is hard-coded into memory, meaning it's a pre-set value that isn't obtained by user input.  You can have the array be all or part of the IBCM program, or a section of memory after the program with values that you have selected.
- You should also hard-code other values, such as the number of elements in the array and the array elements themselves, into your program.  The program should not need any user input.
- Before your program halts, it prints out the maximum value of the array

You ***MUST*** iterate through the array by creating the array load instruction, similarly as was done in lecture in the [array-simulation.ibcm](../../ibcm/array-summation.ibcm) program.  You may ***NOT*** have a series of separate instructions to each load a separate value from the array -- such a program will receive zero credit.

### Writing IBCM Code ###

You **MUST** comment your IBCM code copiously.  This means (practically) every line should have a comment describing what you are doing.  However, you cannot have a line that is only comments, as the emulator will have trouble reading that line!  The examples provided in the handouts posted on the course website and discussed in class illustrate a good way of doing this, where there are columns for each of the following:

1. the hexadecimal values that will go into that memory location
2. the address of that memory location
3. labels for jumps or variable names
4. the operation-name for the instruction on that line
5. a symbolic name for the address the instruction references
6. comments (that explain what's happening in a higher-level form)

Note that together the operation name and the address are sort of an assembly language version of the hexadecimal version of the operations in the first column. You probably want to write those first, and then turn these into the hex instruction that will go into column 1.

The simulator will only read the first 4 character on each line of a file.  So you can't have entire lines with comments, or blank lines.  The simulator can't handle these (and doesn't check for this), and you will get a strange error.

### Running IBCM Code ###

You may run your IBCM code via the online simulator at [https://pegasus.cs.virginia.edu/ibcm/](https://pegasus.cs.virginia.edu/ibcm/).

Beware of the following quirks of the simulator:

- If your code contains an infinite loop, the simulator will hang your browser
- The simulator will not work if there are blank lines at the end of the file

### Submitting your code ###

Submit addition.ibcm and array.ibcm with comments explaining your code.

### Hints ###

#### Leave room for mistakes ####
Sprinkle some nop (opcode: B) instructions throughout your program that can be replaced later in case you realize that you need some extra variables or are missing some instructions.

------------------------------------------------------------

In-lab
------

### Bubble sort ###

Download and look at the [bubblesort.cpp](bubblesort.cpp.html) ([src](bubblesort.cpp)) algorithm.  This algorithm is what needs to be implemented in IBCM, although you should **NOT** implement the output in the IBCM version.

To encode this program, follow these steps:

1. Write up high-level pseudo-code for your design on paper (make sure that it is absolutely correct, or you will probably regret it later)
2. Refine this pseudo-code, making it closer to the assembly code level
3. Alter your code into IBCM assembly code with labels instead of addresses
4. Run through a sufficient number of test cases by hand of your IBCM code from step (3) to convince yourself that it is correct
5. Encode into actual hex IBCM code and addresses, and test it using the simulator
6. Identify and fix the errors that you did not pick up in the previous steps

The file should be called bubblesort.ibcm.  It **MUST** have comments in the file so that the TAs can grade it.  No comments will earn a zero for the grade.

**NOTE:** Just like for the pre-lab array.ibcm file, you must create an array load instruction. If your program has separate instructions for loading separate values from the array, you will receive zero credit for this in-lab.

------------------------------------------------------------

Post-lab
--------

### Post-lab report ###

One of the deliverables for the post-lab is a PDF document named postlab7.pdf.  It must be in PDF format!  See [How to convert a file to PDF](../../docs/convert_to_pdf.html) for details about creating a PDF file.

Submit a report, called postlab7.pdf, that contains your thoughts on IBCM.  What did you think?  How easy was it to use?  Would modifications to the simulator make life easier for you?  How confident do you feel in writing IBCM code?  A (single-spaced) quarter to half a page is fine.

### What is a quine ###

Based on the experience from the in-lab, you should now be able to write an IBCM program on your own. For the postlab, you should individually write an IBCM program that prints itself.  This type of program is known as a *quine*.

> quine: /kwi:n/ /n./ [from the name of the logician Willard van Orman Quine, via Douglas Hofstadter] A program that generates a copy of its own source text as its complete output. Devising the shortest possible quine in some given programming language is a common hackish amusement.

Wikipedia has a good [article about quines](http://en.wikipedia.org/wiki/Quine_%28computing%29), including examples in a few programming languages.  The smallest C/C++ quine is described [here](http://www.ioccc.org/1994/smr.hint) (that is not needed for this lab).

While at first this idea may sound like a serious mind-bender, in reality it is a rather short program that is not too tough to do in IBCM.  This is not a fully general program, it is a carefully crafted program that will only print itself out. The program may contain very specific information such as a variable that is initialized to contain the length of the program.  For example, if your quine is 25 lines long (data and instructions), then when it runs, it will print out 25 lines where each line consists of four hex digits.  The 25 lines you print out may differ from the original file read into the IBCM simulator in a couple of places; these may be variables and instructions which you have modified between the time the program was loaded and the time that particular line is printed.  It is possible to write this program in as few as 8 lines of IBCM code, but most likely you will have closer to 15-20 lines.

You may ***NOT*** submit a zero line quine!  Even though this is technically valid, it will not earn credit for this lab.

We will test your program by running it, recording the output, and running that output as a program.  You should do the same.

### Bash shell script ###

The tutorial for this lab is the remainder of the [Wikibooks article on Bash Shell Scripting](http://en.wikibooks.org/wiki/Bash_Shell_Scripting).

For this lab, you will need to work a bit more on the shell script that you wrote for the last lab.  The shell script will also compute the average running time for 5 executions of a program.  The difference is that you will be using control structures, such as conditionals (if-then-else) and loops (for or while) in this shell script.

First, download the [counter.cpp](counter.cpp.html) ([src](counter.cpp)), [timer.cpp](timer.cpp.html) ([src](timer.cpp)), and [timer.h](timer.h.html) ([src](timer.h)) files.  The timer program has been modified from lab 6 to print out the time in milliseconds.  counter.cpp doesn't actually do anything useful; it just takes in a numeric command line parameter, and runs through an idle loop many times.  We'll call the command line parameter taken in *e* -- given an input of *e*, the program should run through the idle loop 10^*e*^ times.  Thus, you should not enter a value for *e* greater than 9 (as 10^9^ (1 billion) is the largest power of 10 that an `int` value can hold).  On a modern computer, entering 9 as the parameter should take between 1 and 5 seconds to run, but keep in mind that the output is in milliseconds.

Do not compile your program with `-O2`, as clang++ is smart enough to recognize that your for loop is not doing any work and will thus remove it from the compiled binary!

Your `averagetime.sh` shell script should take in the number of iterations as a single input value (not as a command line parameter).  If that input is `quit`, then the script should exit.  Otherwise, execute the program a total of 5 times, printing and keeping track of the execution time taken for each one.  Your script should then print the average time taken for each execution.  **You MUST call your executable program `a.out` in your shell script.**

Your shell script **MUST** have an `if` statement (to see if it should exit), and **MUST** have a `for` or `while` loop.  The number of times to iterate through the `for` or `while` loop (initially set to 5) should be a variable set previously in the script.

If you want to compare values in a while expression (such as the bash equivalent of `while ( i < s )`), you should see [here](https://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO-7.html).  In particular, you need to use `-lt` for the less than operator, and square brackets instead of the parenthesis.

Below are a few notes to keep in mind when writing your shell script.  Bash is a very powerful language, but it can be rather finicky and unforgiving with syntax.

- Your program should be called `averagetime.sh`, and should have `#!/bin/bash` as the very first line of the script
- Bash is a bit finicky with having Boolean operators within an `if` clause, so try to avoid that (it can do it, but the syntax is very particular)
- When setting variables, do **NOT** have spaces around the equals sign
- When adding up values (using arithmetic expansion `$(( ... ))`), there **SHOULD** be spaces around the arithmetic operators as well as an equals sign within the parentheses.
- A `for` loop requires a `do` keyword before the for loop body; likewise, an `if` statement has a `then` before the body.  Either these words must be on the next line, or a semi-colon must be there before the `do` or `then`
- To grab program output (such as the output of the binary program), you use back quotes (i.e. \`)
- To execute your script, you can just enter `./averagetime.sh`.  If your computer denies you permission, remind it who's boss and put it in its place with `chmod +x averagetime.sh`.  This tells your Unix system that averagetime.sh is a program that can be executed (remember chmod?).

Below is the output when we wrote this shell script.  Obviously, your times may vary.

```
enter the exponent for counter.cpp:
9
Running iteration 1...
time taken: 1256 ms
Running iteration 2...
time taken: 1232 ms
Running iteration 3...
time taken: 1238 ms
Running iteration 4...
time taken: 1240 ms
Running iteration 5...
time taken: 1256 ms
5 iterations took 6222 ms
Average time was 1244 ms
```
