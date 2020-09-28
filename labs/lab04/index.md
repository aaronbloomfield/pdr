PDR: Laboratory 4: Number Representation
========================================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

To become familiar with the underlying representation of various data types, and to learn how to examine these representations in the debugger.

### Background ###

In class we discussed how various data types -- integers, characters, and floating point numbers -- were represented in computers.  In this lab we will use the debugger to examine some of these representations.

### Tutorial ###

Go through [Tutorial 4: Unix, part 2](../../tutorials/03-04-more-unix/index.html), which is sections 5-8.  This tutorial is originally from the department of Electrical Engineering at the University of Surrey, and is available online [here](http://www.ee.surrey.ac.uk/Teaching/Unix/).  You went through sections 1-4 in the last tutorial; this lab has you completing sections 5-8.

### Recommended Readings ###

- Structs and Unions and Arrays sections on the [Readings](../../docs/readings.html) page

Procedure
---------

### Pre-lab ###

1. In prelab4.cpp:
    - Write a `sizeOfTest()` function to view the sizes of various types
    - Write an `overflow()` function to investigate how C++ handles integer overflow
    - Write an `outputBinary()` function to display the binary representation of integers
2. Files to download: none
3. Files to submit: prelab4.cpp

### In-lab ###

1. In inlab4.cpp:
    - Investigate how variables are represented in memory
    - Investigate how arrays are represented in memory
2. Files to download: [inlab4.cpp](inlab4.cpp.html) ([src](inlab4.cpp))
3. Files to submit: inlab4.cpp

### Post-lab ###

1. Write a recursive bit counter to count the number of 1s in the binary representation of an integer
2. Write a converter to convert integers from one base to another.
3. Files to download: none
4. Files to submit: bitCounter.cpp

------------------------------------------------------------

Pre-lab
-------

### prelab4.cpp ###

There are three parts to the C++ file you will be submitting as a part of the pre-lab.

**Your program should ask for a single integer value for input (via cin)**, which we will call *x*.  The program will call the three functions below in order: `sizeOfTest()`, `overflow()`, and then `outputBinary(x)`.  Note that only `outputBinary()` takes in *x* as the parameter.

#### sizeOfTest() ####

The size of C++ data types is dependent on the underlying hardware on which you are running.  A programmer may determine the size of various data types by using the `sizeof()` operator.  Although it looks like a function, it's a language construct -- somewhat like `while()` or `if()` -- so it's technically an operator.  `sizeof()` returns the size, in bytes, of a given variable or data type.  Note that you can use `sizeof()` with types, variables, pointers, classes, and objects.

Write a small C++ function that demonstrates the use of `sizeof()` with the following types: `int`, `unsigned int`, `float`, `double`, `char`, `bool`, `int*`, `char*`, and `double*`.  Your function should print out all the types and their respective sizes.  You will use the values outputted by your program to fill in the table in the in-lab section.  The function should be called `sizeOfTest()` (note the capitalization!), so as not to confuse C++ with the `sizeof()` operator.  This function should not take in any parameters.

#### The Limits of Representation ####

What do you think will happen when you add 1 to a variable containing the maximum value of a type?  Write a function called `overflow()` to answer the following questions:

- What happens when you add 1 to an `unsigned int` variable containing the maximum value of an `unsigned int`?
- Does the program halt?
- What answer do you get?
- Why does this happen?

Your function should create an `unsigned int`, give it the max value, and add 1 to that.  By printing out the result, you will effectively answer the first 3 of the 4 questions. Your cout statement should have the format shown below.

`<max_number> + 1 = <result>`

However, when you run the program, you will have actual numbers in place of `<max_number>` and `<result>`

#### Binary number output ####

The third coding exercise for the pre-lab is a binary output program.  The function to write is called `outputBinary()`, and it will take in one parameter, an `unsigned int`.  It must be unsigned, or else your code may not work!  You should then print out the 32-bit binary representation (this includes the leading 0s!) of the passed parameters in **big Endian** format. For example:

```
outputBinary(1) //=> 0000 0000 0000 0000 0000 0000 0000 0001
outputBinary(5) //=> 0000 0000 0000 0000 0000 0000 0000 0101
outputBinary(1000000) //=> 0000 0000 0000 1111 0100 0010 0100 0000
```

You can ***NOT*** use the `bitset` class for this, or any other class that does the work for you.  You have to program this yourself.

### Sample Execution Run ###
Your program will have the printout of three separate methods, and the ordering of these printouts are very important: `sizeOfTest()` --> `overflow()` --> `outputBinary()`. **Do not** include any output that prompts the user for input. Below is a sample execution run to show you the input and output format we are looking for.

Input
```
1
```
Output
```
Size of int: 4
Size of unsigned int: 4
Size of float: 4
Size of double: 8
Size of char: 1
Size of bool: 1
Size of int*: 8
Size of char*: 8
Size of double*: 8
4294967295 + 1 = 0
0000 0000 0000 0000 0000 0000 0000 0001
```

### Hints ###

#### Converting to binary ####
Consider first how you might convert a number to binary using pencil and paper, and develop an algorithm.
Next, take a look at left-shifts (`<<`) as well as right-shifts (`>>`) and see if they would be helpful in implementing your algorithm.

#### Storing as binary ####
Remember how we discussed that little-endian often makes more sense to represent numbers.
Even though your function must print the final result out in big-endian,
that does not prevent you from using little-endian for the conversion itself if you find that to be easier to reason about.

#### Finding the max value ####
The header [`climits`](https://en.cppreference.com/w/cpp/header/climits) has constants containing the max values of many types.

------------------------------------------------------------

In-Lab
------

For the in-lab, you will complete the [inlab4.cpp](inlab4.cpp.html) ([src](inlab4.cpp)).  To complete this in-lab, you should write (but not submit) a separate cpp file that has a few small functions to help fill in *some* of the values in inlab4.cpp; you will use those functions and the debugger to fill in the inlab4.cpp file.  The sections below named [Representation in memory](#memory) and [Primitive Arrays in C++](#arrays) describe what should be in this file.  It should not take in any input, and should just print out the necessary values.

### Output Tables ###

The [inlab4.cpp](inlab4.cpp.html) ([src](inlab4.cpp)) program asks you to fill in two arrays that describe certain features of primitive types in C++.  The two arrays in table form are shown below:

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

To fill in these blanks, we recommend using a combination of short "test" programs, the debugger, a header file containing max and min values of certain types, the [Number Representation slides](../../slides/03-numbers.html), and deductive reasoning.

Notes:

- The values for the "Zero" and "One" columns should interpreted appropriately for the data type. For example, "zero" is 0 for an `int`, 0.0 for a `float`, `false` for a bool, the character `'0'` for a `char`, etc.
- For pointers, the highest memory address that can be described is the "max value." For `char`s, we want the maximum integer value that may be stored therein.  Finally, booleans only have two possible values, so choose the max and min from these two.
- All hex values should be given in **big-endian** and in the same size as their data type (e.g int hexidecimals should only have 4 bytes, char has 1, etc). **For the max value field of float and double, represent the value as the closest power of 2**. The format will be exactly as follows: 2^exponent, but replace exponent with the appropriate number in each case. We want you to do it this way because it would be inconvenient for you to type out all of the whole number.

### inlab4.cpp ###

There are two parts to the C++ file you will be submitting as a part of the in-lab.
1. The two arrays that you will fill out with the appropriate information
2. A `tableDump(string (*arr)[5], string (*arr1)[4])` method that prints out the two arrays in a format that we can autograde

You **must only** replace the empty strings in those arrays with your findings, you do not need to modify anything else in the file. Since we take care of the output for you, don't worry about any formatting for this part of the lab.

#### <a name="memory">Representation in memory</a> ####
This exercise will show you how to read the contents of a particular memory address.  This will be useful for debugging code and for understanding the underlying data representation of abstract data types.

Recall that almost all computers use little-Endian processors.  Thus, 0xd97c34a2 is stored as: `a2 34 7c d9`, with the least significant byte listed first.  However, when you examine the value in LLDB (using the `x/x` command), it will display it in big-endian format, as that is how humans typically think of numbers.

Write a C++ program, called inlab4.cpp, where you consecutively declare variables of these types: `bool`, `char`, `int`, `double`, `int*`, and assign a value of your choosing to each of them.  The last line(s) of the program should print out the values.  Put a breakpoint near the end of the program, but before the last print statement(s).  Once the breakpoint is hit, type expressions to examine the addresses of all of these variables (e.g. `&i`).  Then for each of these variables, view the contents of their addresses (via the `x/x` command from above).

Find one of your `int` variables in memory.  Change its value via the `expr (var) = (value)` (LLDB) or `set variable <var> = <value>` (GDB) command.  Examine the new variable's contents in memory.  Is it what you expected?  Continue the program execution -- did it properly print the changed value?

After completing this section of the lab, you will be expected to understand how to use the debugger to:

- View variables in memory.
- Change an int value from positive to negative.
- Observe interesting/different features in memory (e.g. skipped memory) and be able to explain it.

#### <a name="arrays">Primitive Arrays in C++</a> ####
If you feel you need a bit more background on arrays, there are [readings](../../docs/readings.html#arrays) available.  Note how two (or higher) dimensional arrays are stored in row-major order (as described in the [04-arrays-bigoh slide set](../../slides/04-arrays-bigoh.html)) in C++, as opposed to being stored as arrays of arrays in Java.

This section of the lab is not required, but is recommended since you will be required to know this information for the exams.  Your code should declare a one dimensional array of ints and a one dimensional array of chars, as well as two-dimensional versions of each:

```
int IntArray[10];
char CharArray[10];

int IntArray2D[6][5];
char CharArray2D[6][5];
```

Assign different values of your choosing into each element of all four arrays.  As above, put a breakpoint in your program after the four arrays have been assigned values.  Find the address of the first element of each array, and type that address into LLDB (via the 'p' command).

Examine where the elements of the four arrays are in memory. You will be expected to understand and be able to explain this representation for the exams.

After exploring the array element locations in the debugger, develop an expression for the address of the (i,j)th element of `IntArray2D` as declared above.  You can assume that (0 &le; *i* < 6), (0 &le; *j* < 5), and an int is 4 bytes.

```
&(IntArray2D[i][j]) = _______________________________________________
```

### Hints ###

#### sizeof ####
For the size in bytes of each type, we can easily use the `sizeof` operator or the `sizeOfTest` function from the pre-lab.

#### Max values ####
`climits` will come in handy here again.
For types not in `climits`, you should reason about how the data is stored and the size of that type.

#### Viewing values ####
For some parts of this lab, it is helpful to assign a value to a variable, then inspect that variable's contents using a debugger.
You can write a simple C++ program that creates the variables, and stores the appropriate value (zero, one, or NULL) into them.
Compile (remember the `-g` flag!), load the debugger, set a breakpoint, and start the program execution.

When using LLDB, you can use the 'x' (for 'eXamine') command to print out the pointee of an address.
Consider the C++ program that has two variables defined, `int i` and `int *p`.
To print out the int variable `i`, you would enter `x &i` (as you have to enter the address of where the data is located).
If `p` is a pointer to a value, you would enter `x p` to print out the *pointee*.
This may print it using many more hexadecimal digits than you wanted,
so you can add a parameter to the 'x' command to have it print only a certain amount:

- `x/xb p`: this will print the one byte at the address that is pointed to by p
- `x/xh &i`: this will print the two bytes of int variable i
- `x/xw p`: this will print the four bytes at the address that is pointed to by p
- `x/xg &i`: this will print the eight bytes of int variable i

Note that you don't want to print out more bytes than the size of the type itself.
If your int is 4 bytes, and you print out 8 bytes,
then the other 4 bytes will be whatever arbitrary values are adjacent in memory.

------------------------------------------------------------

Post-Lab
--------

### Binary bit counter ###

In bitCounter.cpp, create a ***recursive*** function that returns the number of 1s in the binary representation of *n*, which will be passed in as a command-line parameter.  Use the following fact: if *n* is even, the number of 1s in the representation of *n* is the same as that in *n/2*; if *n* is odd, the number of 1s is one more than that in *floor(n/2)*.

You may assume that *n* is a non-negative integer that will be stored in two's complement.  However, *n* will be passed in the standard decimal (i.e. base-10) format.  This should be a rather simple function that uses what you've learned about integer representation.  If you find you need things like global variables or the `pow()` function to implement this then you are going too far.

If your program is run without any command-line parameters, your program should gracefully exit with an appropriate error message.  Your program need not handle an invalid number for the command-line parameter.  Any additional command-line parameters beyond the first should be ignored.

### Base converter ###

In bitCounter.cpp, create a function that takes a number *n* from *startBase* and returns the number in *endBase*. This means that your program will take in **four** command-line parameters total (excluding the executable name) in the order shown below.
1. bitcount number (int)
2. number to convert (string)
3. start base (int)
4. end base (int)

Notice that the number we are converting will be passed in as a string; this is because many bases (like hexidecimal) require non-numeric characters for their representations (e.g. A, B, ...). To make things simpler, you may assume that all characters are capitalized. For example, when we input our numbers for you to convert, we will input them as `DEADBEAF123` instead of `deadbeaf123` or `deADbEAf123`. Furthermore, we will not provide any bases less than 1 or greater than 36. 

### Sample Execution Run ###
Your output will be split into two sections, the bit counter and the converter. You can run your methods in any order you please, but your program must print the results of the bit counter **before** the results of the converter. An example I/O when running `./a.out 1 ABCD 16 10`

```
1 has 1 bit(s)
ABCD (base 16) = 43981 (base 10)
```

### Command-line parameters ###

So far, our `main()` method has had the following prototype:

```
int main()
```

We will now change that prototype to the following:

```
int main (int argc, char **argv)
```

These two parameters provide you with the command-line parameters.  The first parameter, `argc`, is the number of parameters plus one -- the 0th parameter is always the name of the executable itself (`a.out`, for example).  The second parameter, `argv`, is an array of C-style strings (some people list the type as `char *argv[]` to make this more clear -- either way is fine).

Command-line parameters are passed in as space-delimited values after the executable name:
```
./a.out 3 hi example.txt
```

Here, `argc` would be set to 4, `argv[0]` would be `a.out`, and `argv[1]`, `argv[2]`, and `argv[3]` would be the strings `3`, `hi`, and `example.txt`, respectively.

Command-line parameters are discussed in more detail in the [04-arrays-bigoh slide set](../../slides/04-arrays-bigoh.html), along with a source code example showing how to use them.

### Hints ###

#### Working with command-line parameters ####
Since `argv` is a `char**`, all parameters are stored as C-style strings.
You will need some method of converting your string parameter to an integer that can be passed to your bit-counter function.
Not sure what to do? Look back at Lab 3 for some clues.

#### Flooring values ####
In the real world, `5 / 2 = 2.5`.
In most programming languages, including C++, dividing two integers will also yield an integer
with the fractional portion removed (which is the same thing as flooring).\
Hence, in C++, `5 / 2 = 2`, as division implicitly floors the result.

#### Converting bases ####
When converting bases, there are two steps that you should follow:
1. Convert the number from the start base to base 10.
2. Convert the base 10 number to the end base. 

In many cases with conversion, you will need to convert characters to integers in order to correctly perform calculations. Instead of trying to use `atoi` or `stoi` like in previous assignments, it is easy to convert character numbers into their integer form by taking advantage of ascii values. For example, the ascii value for the character '9' is 57. So to convert the character '9' to an integer is a simple subtraction, `int converted = '9' - 48;` or `int converted = '9' - '0'`. This same logic can be extended to the numbers 0-8 and a similar approach can be used to convert letters to their correct numerical representation (e.g. 'A' = 10, 'B' = 11, ...). 
