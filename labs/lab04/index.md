PDR: Laboratory 4: Number Representation
========================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

To become familiar with the underlying representation of various data types, and to learn how to examine these representations in the debugger.

### Background ###

In class we discussed how various data types -- integers, characters, and floating point numbers -- were represented in computers.  In this lab we will use the debugger to examine some of these representations.

### Reading(s) ###

1. Any of the optional readings on the [Readings](../../docs/readings.html) page, in particular, those on arrays and unions, if you feel you need a bit more background.  If you are a bit confused about unions, you might want to read about them prior to the in-lab.  Do a Google search for 'C++ unions'.

Procedure
---------

### Pre-lab ###

1. Any of the optional readings on the [Readings](../../docs/readings.html) page, in particular, those on arrays and unions, if you feel you need a bit more background.
2. Go through [Tutorial 4: Unix, part 2](../../tutorials/03-04-more-unix/index.html), which is sections 5-8.  This tutorial is originally from the department of Electrical Engineering at the University of Surrey, and is available online [here](http://www.ee.surrey.ac.uk/Teaching/Unix/).  You went through sections 1-4 in the last tutorial; this lab has you completing sections 5-8.
3. Write the `sizeOfTest()` function (note the capitalization!), as described in the pre-lab section.
4. Write the `outputBinary()` function, as described in the pre-lab section.
    - You cannot use the `bitset` class (or anything similar) for this!
5. Write the `overflow()` function, as described in the pre-lab section.
6. Combine these functions into a prelab4.cpp file, as described in the pre-lab section.  This program should only take in a *single* `int` value as input!
7. Get your floating point number [here](http://libra.cs.virginia.edu/getfloat.php), and then complete your floating point conversion, as described in the pre-lab section, into a file called floatingpoint.pdf; you can convert a file into a PDF via the directions on the [How to convert a file to PDF](../../docs/convert_to_pdf.html) page.
    - Note that this must be typed up in a document; you cannot do this by hand and scan it in (or take a photo of it)
    - Make sure you read the part, in the pre-lab section below, about the maximum file size!  Otherwise your submission will not be accepted.
7. Files to download: none
8. Files to submit: prelab4.cpp, floatingpoint.pdf

### In-lab ###

1. Work through the steps in the in-lab one a time.  Be sure that you understand what is happening at each step.
2. The three parts of the in-lab, described below, have you editing both [inlab4.doc](inlab4.doc) and inlab4.cpp.
    1. Size of C++ data types
    2. Representations in memory
    3. Primitive arrays in C++
3. Files to download: [inlab4.doc](inlab4.doc)
4. Convert inlab4.doc to a PDF via the directions on the [How to convert a file to PDF](../../docs/convert_to_pdf.html) page
5. Files to submit: inlab4.pdf (the PDF version of inlab4.doc), inlab4.cpp

### Post-lab ###

1. Write the recursive bit counter, in bitCounter.cpp, as described in the post-lab section.
2. Complete the radix worksheet -- this worksheet is in the [radixWorksheet.doc](radixWorksheet.doc) file.  This will be converted to PDF and called radixWorksheet.pdf.
3. Files to download: [radixWorksheet.doc](radixWorksheet.doc)
4. Files to submit: bitCounter.cpp, radixWorksheet.pdf

------------------------------------------------------------

Pre-lab
-------

One of the deliverables for the pre-lab is a PDF document named floatingpoint.pdf.  It must be in PDF format!  See [How To Convert A File To PDF](../../docs/convert_to_pdf.html) for details.

### Reading ###

You should see the [Readings](../../docs/readings.html) on [arrays](../../docs/readings.html#arrays) -- that will be needed in the in-lab.  Also, the [Readings](../../docs/readings.html) on [unions](../../docs/readings.html#structsunions).

### sizeOfTest() ###

The size of C++ data types is dependent on the underlying hardware on which you are running.  A programmer may determine the size of various data types by using the `sizeof()` operator.  Although it looks like a function, it's a language construct -- somewhat like `while()` or `if()` -- so it's technically an operator.  `sizeof()` returns the size, in bytes, of a given variable or data type.  Note that you can use `sizeof()` with types, variables, pointers, classes, and objects.

Write a small C++ function that demonstrates the use of `sizeof()` with the following types: `int`, `unsigned int`, `float`, `double`, `char`, `bool`, `int*`, `char*`, and `double*`.  Your function should print out all the types and their respective sizes.  You will use the values outputted by your program to fill in the table in the in-lab section.  The function should be called `sizeOfTest()` (note the capitalization!), so as not to confuse C++ with the `sizeof()` operator.  This function should not take in any parameters.

### Binary number output ###

The second coding exercise for the pre-lab is a binary output program.  The function to write is called `outputBinary()`, and it will take in one parameter, an `unsigned int`.  It must be unsigned, or else your code may not work!  You should then print out the 32-bit binary representation (this includes the leading 0s!) of the passed parameters in **big Endian** format. For example:

```
outputBinary(1) //=> 0000 0000 0000 0000 0000 0000 0000 0001
outputBinary(5) //=> 0000 0000 0000 0000 0000 0000 0000 0101
outputBinary(1000000) //=> 0000 0000 0000 1111 0100 0010 0100 0000
```

- If you do use for loops to do this, become familiar with the left shift operator (<<) and what it does to (unsigned) ints, and the binary and/or operators (& and |).
- You can also use a calculator program (including one in Windows) to convert numbers to binary (select View->Scientific), as that is not the coding part of this lab.

You can ***NOT*** use the `bitset` class for this, or any other class that does the work for you.  You have to program this yourself.

### The Limits of Representation ###

What do you think will happen when you add 1 to a variable containing the maximum value of a type?  Write a function called `overflow()` to answer the following questions:

- What happens when you add 1 to an `unsigned int` variable containing the maximum value of an `unsigned int`?
- Does the program halt?
- What answer do you get?
- Why does this happen?

Your function should create an `unsigned int`, give it the max value, and add 1 to that.  By printing out the result, you will effectively answer the first 3 of the 4 questions.  Answer the last question in a `cout` statement (NOT as a comment!).  The function takes in no parameters.

### prelab4.cpp ###

Your three functions, `sizeOfTest()`, `outputBinary()`, and `overflow()` should be combined into a prelab4.cpp file.  This is the one C++ source code file that you will submit for the pre-lab.  The input requirements for this program are fairly strict, so as to allow automated execution of your programs.

**Your program should ask for a single integer value for input**, which we will call *x*.  The program will call the three functions in order: `sizeOfTest()`, `outputBinary()`, and then `overflow()`.  Note that only `outputBinary()` takes in *x* as the parameter.  The program should take in no further input.

### Floating point conversion ###

For the last part of the pre-lab, you will need to convert a floating point number to binary representation, and another number from binary representation to a floating point number.  You should do this by hand (i.e. not in a computer program), and have the worked-out solution (similar to the lecture notes) be in a floatingpoint.pdf file -- you can use any editor you would like to generate the file, as long as what you submit is a PDF file.

First, you will need to determine what your floating point numbers are going to be -- these numbers will be different for each student.  To do so, visit [http://libra.cs.virginia.edu/getfloat.php](http://libra.cs.virginia.edu/getfloat.php) and enter your UVa userid.  Each floating point number is unique to the userid entered.  Note that the hexadecimal number printed is in **little Endian** format.

The first number must be converted into (little-Endian) format -- you should leave your answer in hexadecimal, as that will be an easier way (versus binary) to represent the number.  The second number (the one in hexadecimal) needs to be converted to a base 10 real number as per the algorithm for converting IEEE 754 single-precision (i.e. 32-bit) floating point numbers.

Note that a '0x' before a number means that the number is in hexadecimal.  Thus, 0x11 has decimal value 17, as that is what 11 is in hexadecimal.  The '0x' part is not part of the value.

For example, if you entered 'asb2t', you would get:

```
Your magic (32 bit) floating point number is -35.125
This is the number that needs to be converted to (little endian) binary, and expressed in hexadecimal.

Your other magic floating point number is, in hex, 0x00401f41
This is the number that needs to be converted to a (32 bit) floating point number.
Note that the hexadecimal printed above is in little-endian format!
```

In this example, you would convert -35.125 to 0x800cc2 (or 0x00800cc2 -- same thing with the leading zeros added), and 0x401f41 (or 0x00401f41 -- again, the same thing) to 9.95312.

Note: during the conversion, the numbers provided do not have any 1 bits in the mantissa after the 10th bit.  It could be that your floating point number needs the first 10 bits of the mantissa, or it could need less.  But all bits after the first 10 are supposed to be zero.  So if your conversion has any bits beyond that set to 1, then you are doing something wrong.  You will be expected to be able to do this on a test -- although in an exam situation, because no calculators are allowed, the math involved with determining the mantissa won't be very hard.

Your conversion should be in a PDF file called floatingpoint.pdf, which will be submitted with the pre-lab.  The idea is to show the math behind the conversion (similar to how was done in class), not to write a program to do it.

You must actually type up your work in a word editor (Word is fine, as is Mac Pages; [LibreOffice](http://www.libreoffice.org/) is a free alternative).  You can ***NOT*** do the assignment by hand, then scan it in (or take a photo of it).  It must actually be typeset in your favorite editor of choice.  Note that the Unix honor pledge only applies to development, so you are free to use anything to type up the file.

**File size:** the submission server will only accept files of up to a certain size, and your file must be less than this size.  If you properly type set your document, then this will not be a problem.  But if you write out your assignment by hand, then scan (or take a picture of) it, then it will be too big to submit.  And note that you have to actually type set it, as mentioned above, so you should be doing this anyway.

------------------------------------------------------------

In-Lab
------

For the in-lab, you will complete the [inlab4.doc](inlab4.doc) worksheet and submit it (in PDF format - see [How To Convert A File To PDF](../../docs/convert_to_pdf.html) for details).  To complete this in-lab, you will write a few small functions to help fill in *some* of the values in the inlab4.doc worksheet; you will combine the functions (and some others) into an inlab4.cpp file.  The sections below named [Representation in memory](#memory) and [Primitive Arrays in C++](#arrays) describe what should be in this file.  It should not take in any input, and should just print out the necessary values.

### Worksheet ###


The [inlab4.doc](inlab4.doc) worksheet asks you to fill in two tables describing certain features of primitive types in C++.  The two tables are reproduced below:

| C++ Type | Size in bytes? | Max value? (base 10) | Zero is stored as (in hex)? | One is stored as (in hex)? |
|----------|----------------|----------------------|-----------------------------|----------------------------|
| int | | | | |
| unsigned int | | | | |
| float | | | | |
| double | | | | |
| char | | | | |
| bool | | | | |

&nbsp;

| C++ Type | Size in bytes? | Max value? (base 16/hex) | NULL is stored as (in hex)? |
|----------|----------------|----------------------|-----------------------------|
| int\* | | | |
| char\* | | | |
| double\* | | | |

To fill in this table, we recommend using a combination of short "test" programs, the debugger, a header file containing max and min values of certain types, the [Number Representation slides](../../slides/03-numbers.html), and deductive reasoning.  

Suggestions to get started:

  - For the "Size in Bytes" column, consider using the `sizeof` operator you learned about in the pre-lab.
  - The values for the "Zero" and "One" columns should interpreted appropriately for the data type. For example, "zero" is 0 for an `int`, 0.0 for a `float`, `false` for a bool, the character `'0'` for a `char`, etc.  
  - The header [`climits`](http://en.cppreference.com/w/cpp/header/climits) has constants containing the max values of many types.
  - For types not in `climits` header, you should reason about how the data is stored (this may involve doing some math on paper).
  - For pointers, the highest memory address that can be described is the "max value." For `char`s, we want the maximum integer value that may be stored therein.  Finally, booleans only have two possible values, so choose the max and min from these two. 
  - Hex values should be given in **big-endian**.

### Using the Debugger ###

For some parts of this lab, it is helpful to assign a value to a variable, then inspect that variable's contents using a debugger.  You can write a simple C++ program that creates the variables, and stores the appropriate value (zero, one, or NULL) into them.  Compile (remember the `-g` flag!), load the debugger, set a breakpoint, and start the program execution.  

When using GDB, you can use the 'x' (for 'eXamine') command to print out the pointee of an address.  Consider the C++ program that has two variables defined, `int i` and `int *p`.  To print out the int variable `i`, you would enter `x &i` (as you have to enter the address of the data).  If `p` is a pointer to a value, you would enter `x p` to print out the *pointee*.  This may print it using many more hexadecimal digits than you wanted, so you can add a parameter to the 'x' command to have it print only a certain amount:

- `x/xb p`: this will print the one byte at the address that is pointed to by p
- `x/xh &i`: this will print the two bytes (short) of int variable i
- `x/xw p`: this will print the four bytes at the address that is pointed to by p
- `x/xg &i`: this will print the eight bytes of int variable i

Note that this is only really useful when printing out a **smaller** size than really exists.  If your variable is 4 bytes, and you print out 8 bytes, then the other 4 bytes will be whatever arbitrary values are adjacent in memory.

So, to find out how the value is stored in hex, first find out the address of where the variable is in memory (`print &i`, for example).  Then, using that address, you can use the examine command: `x/x 0xbf8cd9ac`.  The first 'x' is telling gdb to eXamine a location in memory.  The second 'x', after the forward slash, is telling GDB to print out that result in hex, and the address is the output from the previous print command.  This will print the 4 bytes (32 bits) of memory at that location, in hex.  If you want to print 8 bytes (64 bits), use `x/xg` (the 'g' tells GDB to print 8 bytes instead of 4).  You can also combine these commands by entering `x/x &i`.  The `x/x` part works as above; the `&i` tells it to print the value in memory at the address ('&') of the `i` variable.

### Size of C++ data types ###

The size of C++ data types is dependent on the underlying hardware on which you are running.  A programmer may determine the size of various data types by using the `sizeof()` operator, discussed in the pre-lab.  Note that, unlike a function, you can supply a type to the `sizeof()` operator (i.e., `sizeof(int)`) -- you can't do this with a function.

Also, note that `char`, `short`, `int`, and `long` are all integral (i.e. integer) types.  Integral types may be either signed or unsigned.  Signed types have a different range of values than their unsigned counterpart.  A 32-bit `int` can have 2<sup>32</sup> = 4,294,967,296 values.  An `unsigned int` can range from 0 to 4,294,967,295, and a regular (i.e. signed) `int` can range from -2,147,483,648 to 2,147,483,647.  Unless specified as `unsigned` (as in: `unsigned long`), then all integral types in C++ are signed.

For various optimization reasons, when you declare a variable with an initialization value in C++ (e.g. `int x = 17`), it does not actually immediately initialize it.  In fact, it can initialize it right before it is first used.  Thus, if you set a breakpoint after you declare and initialize a variable, but before it is used, the variable will have a random value in it.  You can solve this by printing out the variable via `cout` -- this causes C++ to initialize the variable for the output statement.  You can then set your breakpoint after this `cout` statement.

To convert binary into hex, see the [03-numbers slide set](../../slides/03-numbers.html).  You can also assign variables in C++ directly using hex by prefacing numeric constants with `0x`.  For example, instead of `int x = 17`, you can write `int x = 0x11`.  

### A legacy note on 32-bit machines ###
In the past, we accepted answers to this lab for either 32-bit or 64-bit computers; as we have transitioned the entire course to 64-bit systems, this is no longer the case.

### <a name="memory">Representation in memory</a> ###

This exercise will show you how to read the contents of a particular memory address.  This will be useful for debugging code and for understanding the underlying data representation of abstract data types.

Recall that all Intel 80x86 machines (i.e. all Pentium-class machines) are little-Endian.  Thus, 0xd97c34a2 is stored as: a2 34 7c d9, with the least significant byte listed first.  However, when you examine the value in gdb (using the `x/x` command), it will display it in big-endian format, as that is how humans typically think of numbers.

Write a C++ program, called inlab4.cpp, where you consecutively declare variables of these types: `bool`, `char`, `int`, `double`, `int*`, and assign a value to each of them.  The last line(s) of the program should print out the values.  Put a breakpoint near the end of the program, but before the last print statement(s).  Once the breakpoint is hit, type expressions to examine the addresses of all of these variables (e.g. `&i`).  Then for each of these variables, view the contents of their addresses (via the `x/x` command from above).

Find one of your `int` variables in memory.  Change its value via the `set variable <var> = <value>` command.  Examine the new variable's contents in memory.  Is it what you expected?  Continue the program execution -- did it properly print the changed value?

**This program should take in no input.**

After completing this section of the lab, you will be expected to understand how to use the debugger to:

- View variables in memory.
- Change an int value from positive to negative.
- Observe interesting/different features in memory (e.g. skipped memory) and be able to explain it.

### <a name="arrays">Primitive Arrays in C++</a> ###

For the pre-lab, you should have read the [Readings](../../docs/readings.html) on arrays, if you feel you need a bit more background.  Note how two (or higher) dimensional arrays are stored in row-major order (as described in the [04-arrays-bigoh slide set](../../slides/04-arrays-bigoh.html)) in C++, as opposed to being stored as arrays of arrays in Java.

For this part, you will need to add a bit of code to your inlab4.cpp file.  You program should show a clear separator where the previous section's part of inlab4.cpp ends and where this section's part of inlab4.cpp begins.  The additional code should declare a one dimensional array of chars and a one dimensional array of ints:

```
int IntArray[10];
char CharArray[10];
```

In your program you should also declare a two dimensional array of chars and a two dimensional array of ints:

```
int IntArray2D[6][5];
char CharArray2D[6][5];
```

Assign different values into each element of all four arrays.  As above, put a breakpoint in your program after the four arrays have been assigned values.  Find the address of the first element of each array, and type that address into gdb (via the 'p' command).

**This program should take in no input.**

Examine where the elements of the four arrays are in memory. You will be expected to understand and be able to explain this representation for the exams.

The final part of the inlab4.doc worksheet involves writing an expression for the address of the (i,j)th element of `IntArray2D` as declared above.

The base address of the array is the identifier (IntArray2D), and the expression should be in terms of that, as well as `i`, `j`, and the size of the `int` type.  You can assume that: (0 &le; *i* < 6), and (0 &le; *j* < 5 ).  Note: '&' here means "the address of", you may use '&' in your answer.  

```
&(IntArray2D[i][j]) = _______________________________________________
```

Remember to include the standard identifying header at the top of all your files (name, date, etc.).  The inlab4.doc worksheet should be converted to PDF and submitted, along with the inlab4.cpp file.

------------------------------------------------------------

Post-Lab
--------

### Binary bit counter ###

Write a ***recursive*** function that returns the number of 1's in the binary representation of *n*.  Use the following fact: if *n* is even, the number of bits in the representation of *n* is the same as that in *n/2*; if *n* is odd, the number of bits is the same as that in *floor(n/2)* plus 1.

You may assume that *n* is a non-negative integer that will be stored in two's complement.  However, *n* will be passed in the standard decimal (i.e. base-10) format.  This should be a rather simple function that uses what you've learned about integer representation.  If you find you need things like global variables or the `pow()` function to implement this then you are going too far.

This program, called bitCounter.cpp should take in a value as a command-line parameter (no input!).  See below for how to handle command-line parameters.  Note that if the program is run without any command-line parameters, your program should gracefully exit with an appropriate error message.  Your program need not handle an invalid number for the command-line parameter.  And any additional command-line parameters beyond the first can be (and should be) ignored.

**This program should take in no input, only one command-line parameter.** Command line parameters are discussed in more detail in the [04-arrays-bigoh slide set](../../slides/04-arrays-bigoh.html), along with a source code example showing how to use them.

So far, our `main()` method has had the following prototype:

```
int main()
```

We will now change that prototype to the following:

```
int main (int argc, char **argv)
```

These two parameters are providing you with the command-line parameters.  The first parameter, `argc`, is the number of parameters plus one.  The second parameter, `argv`, is an array of C-style strings (some people list the type as `char *argv[]` to make this more clear -- either way is fine).

Thus, if you supply the program with 3 command-line parameters, then argc would be set to 4, `argv[0]` would be the C-string that contains the program name ('a.out', for example'), and `argv[1]`, `argv[2]`, and `argv[3]` are the 3 supplied command line parameters.

Your task is to implement the binary bit counter function that takes in a single command-line value (which is a standard base-10 integer) and prints out the number of bits contained therein.

### Converting between number systems ###

Complete and submit the [radixWorksheet.doc](radixWorksheet.doc) file as a PDF file called radixWorksheet.pdf.  It must be in PDF format!  See [How To Convert A File To PDF](../../docs/convert_to_pdf.html) for details.


