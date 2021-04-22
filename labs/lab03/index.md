PDR: Laboratory 3: Stacks
=========================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

To understand the workings of a stack as well as postfix notation, and to be introduced to the C++ Standard Template Library (STL).

### Background ###

A stack is a basic data structure similar in use to a physical stack of papers.  You can add to the top (push) and take from the top (pop), but you are not allowed to access the middle or bottom.  A stack adheres to the [LIFO](http://en.wikipedia.org/wiki/LIFO_%28computing%29) property.

### Tutorial ###

Go through [Tutorial 3: Unix, part 1](../../tutorials/03-04-more-unix/index.html), which is the introduction and sections 1-4.  This tutorial is originally from the department of Electrical Engineering at the University of Surrey, and is available online [here](http://www.ee.surrey.ac.uk/Teaching/Unix/).  You should complete the introductory part and sections 1-4.  You should already be somewhat familiar with some of the materials in the first few of these tutorials, as they were covered in the [Unix tutorial from the first lab](../../tutorials/01-intro-unix/index.html).  The rest of the tutorial (sections 5-8) are for next week's lab, but feel free to go through it this week, if you are interested.

### Recommended Readings ###

- Postfix Calculation and Stacks and Queues sections on the [Readings](../../docs/readings.html) page

Procedure
---------

### Pre-lab ###

1. Implement a postfix stack calculator for integers using the C++ STL stack. For this prelab you are only required to implement addition and subtraction
2. Create a simple program that takes in keyboard input to test your calculator
3. Files to download: none
4. Files to submit: postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp

### In-lab ###

1. Expand your test program to handle negative numbers, multiplication, division, and negation
2. Ensure your postfix calculator works on all the provided test cases
3. Files to download: none (just your pre-lab source code)
4. Files to submit: postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp

### Post-lab ###

1. Implement a stack class
2. Modify your postfix calculator to use your stack rather than the STL stack
3. Files to download: none (just your in-lab source code)
4. Files to submit: stack.h, stack.cpp, postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp - You may submit additional stack/list files as well, if you want

------------------------------------------------------------

Pre-lab
-------

### Code Description ###

In this lab, you will:

- Implement a stack class that handles a stack of integer numbers.  This stack implementation is done for the post-lab; for the pre-lab and the in-lab, you will be using a pre-existing stack class from C++'s standard library.
    - Documentation on the standard library routines can be found at [https://en.cppreference.com](https://en.cppreference.com). The stack class's documentation can be found [here](https://en.cppreference.com/w/cpp/container/stack).
- Write a program that uses this class to implement a postfix calculator. This will include the following files:
    - postfixCalculator.h, which is the class declaration of the postfix calculator
    - postfixCalculator.cpp, which is the implementation of the postfix calculator
    - testPostfixCalc.cpp that accepts user-input (see below) and evaluates that expression.

The various parts of this lab develop the entire program:

- The pre-lab develops the calculator with only addition and subtraction, and also deals with user input (excluding negative numbers)
- The in-lab adds multiplication, division, and negation to the calculator, and also handles negative numbers from user input
- The post-lab develops the stack class that your calculator uses

Note that the program should be able to fully run after each lab portion.

### Stacks ###

A stack is a container that implements the LIFO (last in, first out) property.  Often it internally uses a linked list, array, vector, or a doubly-linked list to contain the elements.  In general, a stack needs to implement the following interface and functionality:

- `void push(int e)`: This adds the passed element to the top of the stack.
- `int top()`: This returns the element on the top of the stack.  It does not remove that element from the top.  If the stack is empty, then somehow an error must be indicated -- printing an error message and exiting is fine for reporting errors for this lab.
- `void pop()`: This removes the element on the top of the stack, but does not return it.  If the stack is empty, then somehow an error must be indicated -- for this lab, you can just print out an error message and then exit.
- `bool empty()`: This tells whether there are any elements left in the stack (false) or not (true).

Often, the `top()` and `pop()` functionality are joined as an `int pop()` function, but in this lab, it is beneficial to separate them, as that is what the STL stack does.

If `pop()` or `top()` are called on an empty stack, terminate the program with the function call `exit(-1)`, which is from the `<cstdlib>` library.

For this lab, you will use a stack of `int` values.

### Postfix Notation ###

Postfix notation (also known as reverse Polish notation) involves writing the operators after the operands.  Note how parentheses are unnecessary in postfix notation.

- Infix: ( 3  +  6 )  -  ( 8  /  4 )
- Postfix: 3  6  +  8  4  /  -

An online description of postfix calculators can be found [on Wikipedia](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

### Stack Calculator Implementation ###

We will be using the C++ STL stack to implement our postfix calculator.  The stack class's documentation can be found [here](https://en.cppreference.com/w/cpp/container/stack).

Your calculator must implement the following arithmetic operations:

- `+`: addition (prelab)
- `-`: subtraction (prelab)
- `*`: multiplication (inlab)
- `/`: division (inlab)
- `~`: unary negation (inlab)

Notes:

- We use the tilde (~) as the unary negation operator -- this negates the top element of the stack, and (unlike the other four operators) does not use a second number from the stack.  Do not confuse this operator with the tilde operator in C++, which performs bitwise negation.  Negative numbers still use a regular minus sign (i.e. '-3') and just pushes the negative number on the stack.  But, if you want to do negation (which involves popping the top value, negating it, and pushing that new value back on the stack), then you would use the tilde.
- Each binary operation follows the format `left_operand right_operand operator`.  For example, `1 2 -` translates to `1 - 2`.

### Input ###

For your keyboard input, your program should read in a single line of space-delimited tokens from standard input.  You should read this in using `string`s (if you are looking at building a tokenizer, then you are making it much more difficult than it need be).  When processing input, you can't know before you read something if it will be an operand (a numeric value) or an operator (a character), so you must read in each space-separated part into a string variable before parsing it. No values, nor intermediate computational results, will exceed what can be stored in an `int`.

We provide you with a number of input files that match the input shown at the end of this lab document.  Recall that you can supply the contents of a file as input to your program via input redirection (as described in the Unix tutorial):

```
./a.out < addition.txt
```

### Terminating Input ###

How should the program know when you are finished providing input?  There are a couple of ways to do this.

- Continuously read in input with `cin`. **This will require entering a Control-D at the end of the provided input** (i.e., enter the postfix expression, hit Enter, and then hit Control-D).  The input we provide during the execution will provide the Control-D at the end of said input.
- Only read in one line, and not accept any more input -- if you handle it this way, you will have to use the `getline()` method, but this is likely the harder way to deal with it.

As mentioned in the Unix tutorial, Control-D stands for "end of file", which lets `cin` know that there is no more input to read.

***NOTE:*** When hitting Control-D, you have to enter it *on its own line*.  This means that you first have to hit Enter, then Control-D.

### Sample Execution Run ###

Below is a sample execution run to show you the input and output format we are looking for.

Input
```
1 2 + 3 -
```
Output
```
0
```

You do not need to supply any input prompting for this assignment. When the program runs, nothing should print out to the terminal and the user should be able to input a postfix expression.

### Assumptions ###

1. The input, i.e. the postfix expression, will be entered on one line and that all numbers and operators will be separated by a single space.
2. The input will contain a valid postfix expression, a newline, and a Control-D if necessary.

### Hints ###

#### Reading input ####
`cin` is the opposite of `cout` -- rather than printing to standard output, it reads from standard input.
When you type a line and press enter, that entire line gets sent to `cin`,
which then automatically splits on whitespace to produce multiple _tokens_.
Therefore, if we were to supply `+ 2 3 isn't 2150 great??` as input, we would get six tokens back.
This is very helpful as the postfix expressions are already space-delimited.

A sample code snippet to continuously read from standard input would look something like this:
```
string token;
while (cin >> token) {
    // Do stuff with `token`!
    // For example, we can print each token back out on its own line:
    cout << token << endl;
}
```

#### Parsing tokens ####
There are two cases you will need to handle when parsing each token: operators and numbers.

C++ allows you to compare strings for equality with `==`.
For example, you can check if `s` is the division operator with `if (s == "/")`.\
Hint: we can check for all the operators, since there are only five of them.  If all the checks fail, what does that mean the token has to be?

cin takes in all input as strings, but we need to convert those to ints so that we can push them into the stack.
Perhaps you should take a look at [the `string` documentation](https://en.cppreference.com/w/cpp/string/basic_string) to see if anything can help you out.

#### Templates ####
The C++ `stack` class is templated,
which means it can hold whatever type you specify (think back to ArrayLists in Java).
Since we will be using `int`s for our postfix calculator,
we can specify that by saying `stack<int>` when declaring our stack.

#### Checking if the stack is empty ####
Given that you will need to check if the stack is empty before every `top` and `pop` call,
it may be worth it to add helper methods to your postfix calculator that, when called,
will perform the necessary checks before top/pop.

#### Compiling ####
When compiling your code, remember to compile ALL of your cpp files in the compile command:
```
clang++ postfixCalculator.cpp testPostfixCalc.cpp
```

You can also use `clang++ *.cpp` if there are no other C++ files in your directory.

------------------------------------------------------------

In-lab
------

The purpose of the in-lab is first to ensure that your pre-lab code (the postfix calculator) is working properly.  Then, you will need to handle negative integer inputs and add the remaining three operators: multiplication, division, negation.  By the end of the in-lab, your postfix calculator should be able to read in a single line of space-delimited tokens representing a postfix expression and print out the result of the expression before exiting.

### Input ###

The core functionality of user input should be completed in the pre-lab. For this section, you must add code that allows the program to accept negative numbers (e.g -1, -10) for use with the calculator.  In addition to handling negative numbers, you must also add functionality that allows the user to enter the symbols for multiplication, division, and negation, which are respectively: `*`, `/`, `~` 

### Output ###

See the Sample Execution Run section of the pre-lab for specifications.

### Hints ###
By expanding the integer input to also include negative numbers, you must be careful not to accidentally parse a negative number as the subtraction operator. For example, if your code were to only check the first character of every token, then it may mistake a number like `-5` as the subtraction operator `-`. To handle this, your code should check the length of tokens and their first character in order to determine exactly what the user has just input to your calculator.

------------------------------------------------------------

Post-lab
--------

For the post-lab, you will be implementing your own stack and then modifying your postfix calculator to use that stack instead of the STL stack.

Your stack class must:

- Implement the `void push(int e)`, `void pop()`, `int top()`, and `bool empty()` methods to perform the same functionality as the STL stack
- Internally use a linked list
- Have no maximum capacity (we should be able to push as many elements as we'd like)
- Not use any STL containers

You may modify and re-use your LinkedList code from Lab 2, or you may write your own code, as long as you satisfy the above requirements.

### Submitting the stack / list files ###

Depending on how you implement the stack class, you may just need the stack.h/cpp files, in addition to the three postfix calculator files (postfixCalculator.h/cpp and testPostfixCalc.cpp).  Or you may need stack.h/cpp and stacknode.h/cpp in addition to the three postfix calculator files.  Or you may want to include the six List/ListItr/ListNode files from lab 2 as well as stack.h/cpp and the three postfix calculator files.  How you do this is up to you - as long as it works, we don't really care, provided that is compiles with `clang++ *.cpp`

------------------------------------------------------------

Test files
----------

The following examples provide postfix expressions and their expected value.

[addition.txt](input/addition.txt): `1 2 3 4 5 + + + +`; expected output: 15

[subtraction.txt](input/subtraction.txt): `20 10 - -3 10 - - 2 -`; expected output: 21

[multiplication.txt](input/multiplication.txt): `-1 -2 -5 3 * 2 -2 * * * *`; expected output: 120

[division.txt](input/division.txt): `-1512 -12 -2 / / -2 / 3 /`; expected output: 42

[negation.txt](input/negation.txt): `-1 ~ ~ ~`; expected output: 1
