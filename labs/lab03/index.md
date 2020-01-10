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

1. Write up at least one question that you still have on Unix (or things you are still confused about)
2. Implement a postfix stack calculator for integers using the C++ STL stack
3. Create a simple program to test your calculator
4. Files to download: none
5. Files to submit: postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp, unix.questions.txt

### In-lab ###

1. Ensure your postfix calculator works on all the provided test cases
2. Expand your test program to handle keyboard input
3. Files to download: none (just your pre-lab source code)
4. Files to submit: postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp

### Post-lab ###

1. Implement a stack class
2. Modify your postfix calculator to use your stack rather than the STL stack
3. Describe any difficulties you encountered getting your code working and what you did to solve them
4. Files to download: none (just your in-lab source code)
5. Files to submit: stack.h, stack.cpp, postfixCalculator.h, postfixCalculator.cpp, testPostfixCalc.cpp, difficulties.txt - You may submit additional stack/list files as well, if you want

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
    - testPostfixCalc.cpp that has a hard-coded expression (see below) and evaluates that expression.

The various parts of this lab develop the entire program:

- The pre-lab develops the calculator itself, without dealing with user input or the stack class
- The in-lab develops the user input routines
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

### Stack Calculator Implementation ###

We will be using the C++ STL stack to implement our postfix calculator.  The stack class's documentation can be found [here](https://en.cppreference.com/w/cpp/container/stack).

Your calculator must implement the following arithmetic operations:

  - `+` : addition
  - `-` : subtraction
  - `*` : multiplication
  - `/` : division
  - `~` : unary negation

Notes:

  - We use the tilde (~) as the unary negation operator -- this negates the top element of the stack, and (unlike the other four operators) does not use a second number from the stack.  Do not confuse this operator with the tilde operator in C++, which performs bitwise negation.  Negative numbers still use a regular minus sign (i.e. '-3') and just pushes the negative number on the stack.  But, if you want to do negation (which involves popping the top value, negating it, and pushing that new value back on the stack), then you would use the tilde.
  - For the non-commutative operators (operators where the order of the numbers matters, such as minus and divide), the first value you pop we'll call x, the second value you pop we'll call y; the result **must** be *y-x* or *y/x* -- in other words, the "lower" value in the stack minus/divided by the "higher" one in the stack.

### Input ###

For this part of the lab, you will not deal with keyboard input (that's in the in-lab) -- thus, your submitted program will always compute the exact same value each time it is run.  You will need to hard-code your postfix expressions into the `main()` method. Make sure your tests in main demonstrate the functionality of all operators!

A sample `main()` function that might work is as follows -- this should be modified for your particular situation (i.e. how you declare your class, your method names, etc.).  This `main()` function uses the first sample input given at the very end of this document.

```
int main() {
    PostfixCalculator p;
    p.pushNum (1);
    p.pushNum (2);
    p.pushNum (3);
    p.pushNum (4);
    p.pushNum (5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "Result is: " << p.getTopValue() << endl;
    return 0;
}
```

Keep in mind that you can type up a few of the blocks, and comment them out with the `/* ... */` comment syntax that you are familiar with from Java -- this will allow you to easily switch between the different hard-coded input test cases.

### Postfix Notation ###

Postfix notation (also known as reverse Polish notation) involves writing the operators after the operands.  Note how parentheses are unnecessary in postfix notation.

- Infix: ( 3  +  6 )  -  ( 8  /  4 )
- Postfix: 3  6  +  8  4  /  -

An online description of postfix calculators can be found [on Wikipedia](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

### Hints ###

In the past, students have run into a few problems with this lab.  We list them here in an effort to prevent these particular problems from being encountered again.

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

The purpose of the in-lab is first to ensure that your pre-lab code (the postfix calculator) is working properly.  Then, you will need to add keyboard input to your lab.  By the end of the in-lab, your postfix calculator should be able to read in a single line of space-delimited tokens representing a postfix expression and print out the result of the expression before exiting.

### Input ###

For your keyboard input, your program should read in a single line of space-delimited tokens from standard input.  You should read this in using `string`s (if you are looking at building a tokenizer, then you are making it much more difficult than it need be).  When processing input, you can't know before you read something if it will be an operand (a numeric value) or an operator (a character), so you must read in each space-separated part into a string variable before parsing it.

You will need to accept both negative numbers (-5 for example) and numbers with multiple digits (34 is the number thirty-four, not the separate numbers three and four) -- and thus negative numbers with multiple digits (-34, for example).  No values, nor intermediate computational results, will exceed what can be stored in an `int`.

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

To convert input that represents numbers into their integer form, `<cstdlib>` provides the `int atoi(char* s)` function.
Unfortunately, `atoi` requires C-style strings -- perhaps you should take a look at
[the `string` documentation](https://en.cppreference.com/w/cpp/string/basic_string) to see if anything can help you out.

------------------------------------------------------------

Post-lab
--------

For the post-lab, you will be implementing your own stack and then modifying your postfix calculator to use that stack instead of the STL stack.  This can be code that you write yourself, or you can re-use your List code from lab 2 (make sure it works before you re-use it, though!).

You will also need to write up a difficulties.txt file which contains a paragraph describing any difficulties you encountered getting your code working and what you did to solve them.

Your stack is only required to implement the four methods as described in the prelab: `push()`, `pop()`, `top()`, and `empty()`.
It must also have no maximum capacity -- in other words, we should be able to push as many elements as we'd like.

Most of you will implement your stack in one of the following ways:

1. Re-use your list class from lab 2. You may need to add one or two methods to it for extra convenience.
2. Build a linked-list / pointer-based stack as discussed in lecture. Your stack class would contain a pointer to the head node of the stack, and push and pop would modify the singly-linked list accordingly.
3. Manually implement an array-based stack. If you choose this method, your array must be able to automatically resize if the stack grows large enough to sufficiently fill the array. This is probably the most difficult of the three options.

### Submitting the stack / list files ###

Depending on how you implement the stack class, you may just need the stack.h/cpp files, in addition to the three postfix calculator files (postfixCalculator.h/cpp and testPostfixCalc.cpp).  Or you may need stack.h/cpp and stacknode.h/cpp in addition to the three postfix calculator files.  Or you may want to include the six List/ListItr/ListNode files from lab 2 as well as stack.h/cpp and the three postfix calculator files.  How you do this is up to you - as long as it works, we don't really care, provided that:

1. It compiles with `clang++ *.cpp`
2. The total number of C++ files you submit is 11 or fewer (you can submit 12 files total, but you need to submit a text file called difficulties.txt as well)


------------------------------------------------------------

Test files
----------

The following examples provide postfix expressions and their expected value.

[addition.txt](input/addition.txt): `1 2 3 4 5 + + + +`; expected output: 15

[subtraction.txt](input/subtraction.txt): `20 10 - -3 10 - - 2 -`; expected output: 21

[multiplication.txt](input/multiplication.txt): `-1 -2 -5 3 * 2 -2 * * * *`; expected output: 120

[division.txt](input/division.txt): `-1512 -12 -2 / / -2 / 3 /`; expected output: 42

[negation.txt](input/negation.txt): `-1 ~ ~ ~`; expected output: 1
