PDR: Laboratory 6: Hashing
==========================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

The purpose of this lab is to gain experience using hash tables by building an interesting application.

### Background ###

A [hash table](https://en.wikipedia.org/wiki/Hash_table) is a dictionary in which keys are mapped to array positions by a *hash function*. Having more than one key map to the same position is called a *collision*. There are many ways to resolve collisions, but they may be divided into two primary strategies: separate chaining and open addressing.

### Tutorial ###

Look over the first 6 sections (through and including 'exit status') of the [Wikibooks article on Bash Shell Scripting](https://en.wikibooks.org/wiki/Bash_Shell_Scripting).  You will be writing a shell script during the in-lab, but you should probably start reading it before then.  The remaining sections of that article will be the tutorial for the next lab, so feel free to read on, if you are interested.

### Recommended Readings ###

1. Learn how to use C++ file streams to read from data files. See the [Input/output with files article](http://www.cplusplus.com/doc/tutorial/files/) on [cplusplus.com](http://www.cplusplus.com/).  You can also see the code in the provided [getWordInGrid.cpp](code/getWordInGrid.cpp.html) ([src](code/getWordInGrid.cpp)) file which uses streams as well.  You may want to use the [good()](http://www.cplusplus.com/reference/fstream/ifstream/) method in the ifstream class -- you can put it in a `while` loop: `while (foo.good())`.

Procedure
---------

### Pre-lab ###

1. Create a word puzzle solver
2. Programmatically time how fast your program takes to run
3. Calculate the big-theta running time of the word-search portion of your solver
4. Files to download: 
    - The 5 provided code files: [getWordInGrid.cpp](code/getWordInGrid.cpp.html) ([src](code/getWordInGrid.cpp)), [primenumber.cpp](code/primenumber.cpp.html) ([src](code/primenumber.cpp)), [timer.cpp](code/timer.cpp.html) ([src](code/timer.cpp)), [timer.h](code/timer.h.html) ([src](code/timer.h)), [timer_test.cpp](code/timer_test.cpp.html) ([src](code/timer_test.cpp)).  These can also be downloaded all at once via the [code.zip](code.zip) file.
    - The data files in the labs/lab06/data/ directory.  These can also be downloaded all at once via the [data.zip](data.zip) file.
5. Files to submit: Makefile, wordPuzzle.cpp, timer.h/cpp, hashTable.h/cpp

### In-lab ###

1. Learn about the `-O2` clang++ optimization flag
2. Compare your output with the expected output using output redirection, pipes, and Unix commands
3. Test your program with the 250x250 grid using words.txt, and the 300x300 grid using words2.txt
4. Create a shell script to calculate the average running time of your program
5. Write a report on the time complexity of your program and the results of its execution
6. Files to download: none
7. Files to submit: averagetime.sh, inlab6.pdf

### Post-lab ###

1. Optimize your implementation of the word puzzle solver
2. Write a report on the running time of your program and the optimizations you applied
3. Files to download: none
4. Files to submit: Makefile, wordPuzzle.cpp, timer.h/cpp, hashTable.h/cpp, postlab6.pdf

------------------------------------------------------------


Word Puzzle Problem
--------------------

Consider the problem called [word search](https://en.wikipedia.org/wiki/Word_search), illustrated in the diagram below.

[![word search puzzle](500px-Wordsearch.svg.png)](https://en.wikipedia.org/wiki/File:Wordsearch.svg)

In this 10x10 grid of letters, the goal is to find words in the puzzle in any of the eight directions.  The word circled in red is in the south-east direction.  Words can go backward (although none do in this example), but they cannot "wrap around" from one side to the other (or from top to bottom, etc.).

A string of letters from the grid depends on four values:

- The *x* value of the starting letter
- The *y* value of the starting letter
- The direction, *d*, of the word
- The length, *l*, of the string

------------------------------------------------------------

Pre-lab
-------

### Overview ###

For this lab you need to implement a solution to the word puzzle problem described above: given a dictionary and word search grid, your program should output all the words in the grid that are in the dictionary.

There are two main parts to this lab: creating a hash table and writing a word search solver.  A high-level specification is provided for the word search solver and the hash table it must use; more details are available in the rest of the pre-lab section.

Your word search solver, implemented in `wordPuzzle.cpp`, should:

- Take in a dictionary file and grid file, in that order, using command line parameters
- Read in a dictionary and store its words in a hash table
    - Which is implemented without using a vector of vectors or any STL hash table
- Read in a word search grid no larger than 500x500 and store it in an appropriate data structure
- Output every word of length three or greater and its location in the grid
    - The required output format is described below
- Output the time it took to find all the words

We are not as interested in how fast your program runs for the pre-lab; leave any optimizations for the post-lab.

### Storing the dictionary ###

As there may be a large number of words in the dictionary, you will have to store those words in a hash table to facilitate efficient lookup.

You **must** write your own hash table for this lab.
We leave the implementation up to you, as long as you do not use a vector of vectors or any STL hash table.

### Manipulating the grid ###

[getWordInGrid.cpp](code/getWordInGrid.cpp.html) ([src](code/getWordInGrid.cpp)) provides two useful functions: `readInGrid()` and `getWordInGrid()`. The former reads in a grid file using C++ streams; the latter returns a word in a 2D grid of letters in a given direction.

You should make sure you understand how these functions work, as you will most likely be using them in your final program.

### Timing ###

We are interested in timing how long it takes to find all the valid words in a grid, not including the time it took to read in the dictionary and grid files or perform any other sort of pre-processing.
You can use the code provided in [timer.cpp](code/timer.cpp.html) ([src](code/timer.cpp)), [timer.h](code/timer.h.html) ([src](code/timer.h)), and [timer_test.cpp](code/timer_test.cpp.html) ([src](code/timer_test.cpp)) to time the relevant portion of your program.

### Other details ###

**Input grids:** Each input grid file has three lines.  The first line is the number of rows, and the second is the number of columns, both representable using integers.  The third line is the grid data, represented by strictly alphabetical characters with no spaces (i.e. it will contain `rows * cols` characters).  Example grids are available in the labs/lab06/data/ directory.

**Dictionary files:** Dictionaries contain one word per line. The longest word in our data files is 22 letters. Words which contain non-alphabetical characters may occur in the dictionary, but would never appear in a valid grid.  Your program should be able to handle dictionaries with such words, although you are not required to put them into the hash table.

**Valid words:** Your program should *only* report words with three or more letters -- there are simply too many hits if one and two letter words are allowed, and it's difficult to judge correctness, even on very small word searches.

**Case sensitivity:** Searches are *case-sensitive*.  Thus, if the word in the dictionary is 'Foo', it should not register a match to the text 'foo' in the grid.

**Duplicates:** If a word occurs more than once in a grid, then each instance should be treated as a separate word.

**Output format:** In an effort to make it easier to determine if the program is working properly or not, we want to standardize the output format.  Below is the [4x7.out.txt](data/4x7.out.txt) file:

```
N (3, 2):       text
E (0, 3):       sod
N (2, 5):       fad
E (1, 0):       pax
NW(3, 6):       eft
E (2, 0):       ace
W (2, 4):       tee
NE(2, 4):       tat
SW(0, 6):       tat
9 words found
Found all words in 0.000835 seconds
```

The exact spacing and order that the words are found in does not matter, as we can easily (and automatically) ignore that when comparing your output to the desired output.  Everything else should all be the same.  The in-lab discusses how to directly compare your output to the expected output (while ignoring spaces and word order) - see the "Input and Output" section of the in-lab.

### Submission ###

You should submit any files required for your word puzzle solver to run as well as a Makefile that produces an `a.out` executable.

### Hints ###

#### Separation of concerns ####
Given the multi-faceted nature of this lab, it is helpful to only focus on one portion at the time.
Start out by using the STL hashtable [unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set) to verify that your word search works, and then work on writing your own hash table implementation to replace it.

The last thing you want is to be staring at incorrect output and not knowing whether that's because of your solver or your hashtable!

#### That hint didn't help, I still have no clue how to start ####
Take it one step at a time.

Start off by reading in the dictionary and printing out all of its words.
Then store those words in a hashtable (probably the STL one for now).
Great, you have a dictionary now.

Next, read in the grid (use the functions in `getWordInGrid.cpp` to help you!).
Plan out how to use the dictionary to find all the valid words in the grid.
There are four variables that control what word is returned -- what does that imply in terms of loops?

At this point, hopefully you have enough to get you going.

#### Storing the grid ####
Creating a dynamic 2D array in C++ is more difficult than it should be -- one solution is to create a vector of vectors, but that is not the most efficient means to do it.
For this lab, you can just create a 500x500 static array, and can assume that you will not have your program run on larger input grids.
This is not very elegant, but it will work until we go over dynamic array creation in lecture.

#### Command-line parameters ####
Your program must be able to run successfully if started with `./a.out <dictionary_file> <grid_file>` and no input.

See the [slide set on arrays](../../slides/04-arrays-bigoh.html) if you need a refresher on command-line parameters; you can also see the [cmdlineparams.cpp](../../slides/code/04-arrays-bigoh/cmdlineparams.cpp.html) ([src](../../slides/code/04-arrays-bigoh/cmdlineparams.cpp)) file.

#### Hash table sizes ####
As discussed in lecture, a hash table needs to be a prime number in size in order to work.
You can adapt the code in the [primenumber.cpp](code/primenumber.cpp.html) ([src](code/primenumber.cpp)) file to determine the next highest prime number (of course, the next highest prime number is determined after you double the size of your original hash table).

Your program will need to handle input dictionaries of various sizes and create hash tables of the appropriate size.
To get the program working the first time, you can just hard code a prime number table size.
But at some point, you will have to handle different size hash tables.

- One option is to implement a `rehash()` function that will double the size of the array, hash all the old values into the new table, and then remove the old table.
- A second option is to do two passes through the dictionary file.  The first time you count the number of elements, use that to create an appropriate sized hash table, and the second time through the dictionary file you insert all the words into the table itself.

------------------------------------------------------------

In-lab
------

### The -O2 flag ###

There are many times when we want our executable program to run as fast as possible.  An example of this is the current lab -- as we are testing our programs for speed (and we want them to run fast), we want to tell the compiler to write an optimized executable.  To do this, we specify the '-O2' flag, short for "optimization level 2" (capital O).  There are multiple optimization levels that clang++ provides, each with benefits and drawbacks.  The only allowable optimization level for this lab is 2 (i.e. '-O2', not any other number after the 'O').  For example, to compile this program, we would enter:

```
clang++ -O2 -Wall wordPuzzle.cpp timer.cpp hashTable.cpp
```

If we wanted to use the -c flag (such as through a Makefile), then the commands would be:

```
clang++ -O2 -c wordPuzzle.cpp
clang++ -O2 -c timer.cpp
clang++ -O2 -c hashTable.cpp
clang++ -O2 wordPuzzle.o timer.o hashTable.o
```

Note that on this last one, that the -O2 flag must be used on each of the individual compilations as well as the final link.  Thus, when put into a Makefile, you should make your CXXFLAGS variable include '-O2' so that it applies to all compilations.

We could always tell the compiler to create an optimized executable file by always using the -O2 flag.  But there are some disadvantages to doing so.  Debugging the program is much harder (if not impossible) with an optimized executable -- much of the debugging information is stripped out of the executable to improve the speed.  So if you want to debug your program, you will have to remove the -O2 flag (and put in the -g flag, of course).  Also, the compiler takes longer to compile the program when optimizing.  These are some reasons programmers usually don't use the -O2 flag until they know the program works, and thus want the additional speed improvement.

Try compiling your program both with and without the -O2 flag.  Run the program both times.  Do you notice a difference in the timed speed of the program?  Our test program decreased in execution time from about 15 seconds to 12 seconds with the -O2 flag.

### Input and Output ###

When we are running the programs, we will want to make sure that they are reporting the same results.  To do so, we will need to save the output into a file, and then make sure that file matches the sample input file.

To redirect output to a file, we enter the following command (we've seen output redirection before -- in [section 3 of the first Unix tutorial](../../tutorials/03-04-more-unix/unix3.html) -- so this should be familiar material).

```
./a.out words2.txt 300x300.grid.txt > output.txt
```

Recall that this command will **OVERWRITE** output.txt (if it exists), and save all the output from the executable into that file.  This program does not ask for input; if it did, we would not see the prompt, but would still have to provide the input.

Once the program is completed, we will need to see if that file is the same as the sample input.  To do so, enter the following command.  We'll assume, for this example, that we are using the 300x300 grid, and words2.txt.

```
diff output.txt 300x300.words2.out.txt
```

This will examine the two files byte-by-byte, and look for differences.  If there are no differences, then diff will not print out ANY output.  If there are differences, then they will be printed to the screen.  This means that if diff prints anything, then your program is NOT producing the same results as we are expecting.  All hope is not lost, though!  If you look at the two files (you can load them up both in Emacs), it may very well be that the difference is in formatting -- you use two spaces, we use one space, for example.

Keep in mind that your program execution may include a bit of additional output -- such as the prompts for the filenames, the timing information, etc.  If that is the only difference between output.txt and the sample output, then that's fine.

If the files are not sorted the same -- meaning that the words listed are the same, but in a different order -- then diff will report differences between the files.  You can use the Unix 'sort' command to sort BOTH files before comparison to fix this:

```
# Pipe the result of your program execution to `sort`, and then redirect that to output.txt
./a.out words2.txt 300x300.grid.txt | sort > output.txt
sort 300x300.words2.out.txt > words2.sorted.out.txt
diff output.txt words2.sorted.out.txt
```

If there are a lot of differences, then you should run your program on a small grid with the smaller word file (i.e. words2.txt).  Once you solve the differences with the smaller grid file and word file, most of the differences with the larger grid/word files should disappear.

Lastly, you can provide the `-w` flag to diff to have it ignore all whitespace on the lines it is comparing.

### Shell Scripting ###

Through the various programming languages we've seen (Java, C++, etc.), we can make a computer do many things.  Yet there are still limitations to what we can do in these languages.  How could you get a directory listing in Java, for example?  Or easily invoke Unix commands from C++?  While these are certainly possible, they are often difficult to accomplish.  

Yet programmers often have a need to do these sorts of things.  For example, a script that we wrote takes all the submissions made to the submission server, compiles and executes them, and saves the execution output to various files.  This allows the compilation and execution to be automated, and thus saves the graders a lot of time.

The *shell* is the command-line interface that you use when you are interactively using Unix (i.e. the Linux command line).  There are many shells out there, some of the more popular being bash, csh, and ksh.  Bash is the standard shell that the vast majority of shell scripts are written in, and is the shell we'll be using for this tutorial.

The original Unix shell was written by Stephen Bourne and released 1978.  It was just called 'sh', which is short for 'shell'.  In 1987, Brian Fox updated the shell, and decided to name it 'Bourne-again shell', a play on the original author's name.  Hence the name of 'bash'.

A *shell script*, then, is a series of commands for the shell to execute.  Shell scripts started off as just a way to have a series of simple commands in one place.  Over time, additional functionality was added to these scripts, mostly the things we are used to in programming languages, such as variables and control structures (`for` and `while` loops, `if` and `case` conditionals, etc.).  Today, shell scripts are a very powerful programming language that one can use to do many things.

Shell scripts are useful when one needs to call a large number of Unix commands (such as the aforementioned compilation/execution example).  Significant computation, such as finding words in a word puzzle, or a lot of arithmetic, are not well suited to shell scripts.

### Average Running Time ###

Write a shell script `averagetime.sh` that will prompt the user for the dictionary and grid file names used by your word puzzle executable.  It will then run the program five times using those parameters.  It will record the time of each execution run, and, once the runs are completed, print out the average run time.  Note that you have not yet seen conditions (`if` or `case`) or loops (`for` or `while`) in shell scripts, so we do not expect your script to have either of these -- you should just have 5 separate commands without a loop.

To make your life easier, you can modify your word puzzle program to print out the total time taken as the last line of output.  **THIS MUST BE AN INTEGER VALUE!**  Otherwise else the shell script will have problems (floating point arithmetic in bash is viable, but more complicated, so we'll stick with integer arithmetic).  Thus, you should multiply the timing result by 1000, and then print it out (hence you are printing out the number of milliseconds that the program took).  You should use the timer's `getTime()` method for this.  You can then capture that line by piping it through the `tail -1` command -- a brief introduction on how to do all of this is presented here.  The back quote (on the same key as the tilde (~), which is usually to the left of the digit 1) tells a shell script to run the program, and use the output for something else (as opposed to displaying the output to the screen).  For example, the following line would run the program (called a.out), only keep the last line, and save that output to a variable.

```
RUNNING_TIME=`./a.out | tail -1`
```

**Note:** your shell script MUST call a.out, and not anything else.

Armed with this, the rest of the required concepts for the shell script are in first six sections of the article.

As you are going through the tutorial, if there is a Unix command that you do not know (or you once knew and have since forgotten), you can find out more information about that command by entering `man command` at the Unix prompt.  This brings up the manual for that command, including all of the command-line parameters.

A few thoughts to help you with your shell script.  If you are unsure if something is working, you can always print out the value of the variable through the `echo` command.  And you need not worry about the decimal precision of the average -- the result of using arithmetic expansion `$(( ... ))` with the sum over the number of runs is fine -- recall that the script has been modified to only print out an integer value (using arithmetic expansion `$(( ... ))` with floating point values will have issues).

Your script should have comments (anything on a line after a '#' is a comment).  Our solution was 10-15 lines, not counting comments.

Below are a few notes to keep in mind when writing your shell script.  Bash is a very powerful language, but it can be rather finicky and unforgiving with syntax.

- The shell script takes two inputs (dictionary file and grid file), in that order; no command-line parameters.
- Your program should be called `averagetime.sh`, and should have `#!/bin/bash` as the very first line of the script
  - If you don't put the `#!/bin/bash`, it will use the wrong shell, and your program won't work properly!
- When setting variables, do not have spaces around the equals sign
- Keep in mind that to grab program output (such as the output of the binary program), you use back quotes (i.e. \`)
- To execute your script, you can just enter, `./averagetime.sh`.  If you get a complaint about that ('permission denied', for example), enter this command: `chmod 755 averagetime.sh`.  This tells your Unix system that averagetime.sh is a program that can be executed (remember chmod?).

### In-lab Report ###

One of the deliverables for the in-lab is a PDF document named inlab6.pdf.

This report should contain items such as:

- Did your implementation produce the correct results?  Did you have to reformat your output?
- How much faster was your program with the -O2 flag?
- What was the speed of your implementation?  How fast did it run on the 250x250 grid using words.txt as the dictionary file?  What about words2.txt and the 300x300 grid?
- What is the big-Theta running speed of the word-search component of your program? Please do this in terms of *r* (rows), *c* (columns), and *w* (words).  You can assume that the maximum word size is some small constant.  Do not take into consideration the file reading or hash table creation time, neither of which are part of the actual word searching.
- What problems did you encounter when implementing this lab?
- How did your shell scripting writing go?  What do you think of shell scripts so far?

Basically, we want a summary of your thoughts and experiences with the lab at this point, as well as the results from your timed runs.  As this is an in-lab report, we don't expect it to be very long winded -- just enough to answer those questions is sufficient. 

------------------------------------------------------------

Post-lab
--------

You will need to optimize your code for the solution to the word puzzle, as well as the post-lab report described below.

### Code optimization ###

Your coding task for the post-lab is to optimize your program.  At this point, your timing code should be in place, and your in-lab shell script should be able to automate the running and timing of your program.

First, record how long it takes to run your program as-is.  We will need this value later.  All these values should be recorded when the executable being run was compiled with the -O2 flag.

You will need to optimize your word search.  There are plenty of optimizations you can try to implement, some of which may work better with your code than others. Here are some ideas:

- Choose a good load factor, &lambda;, for your hash table
- Implement a reasonable collision resolution strategy
- Output to the screen (or redirected into a file) is very slow.  Buffering the input (keeping it in memory in some data structure), and then printing it out after the timing code is finished, may greatly improve performance.
- In addition to storing each word, *W*, you can also store the *prefixes* of that word.  So if the word is "amazing", you would store "ama", "amaz", "amazi", "amazin", and "amazing" in the hash table.  There would need to be some way to differentiate between prefixes ("amaz") and the actual words ("amazing").  This way if you are working in a given direction, and the particular string you are generating is not a prefix, then you know there are no further words in the dictionary in the given direction.
- You can keep track of a previous hash to help compute the next one faster.  For example, if you have just computed the hash for "foo", then you can keep that hash value on hand to compute the hash for "food" faster.
- A better hash functions on the strings.
- If you are using separate chaining, trying different data structures for the buckets.
- Any others that you can think of?

Keep track of what you tried -- if you try each of the collision resolution strategies, and find that the original one you used is faster, record all of this in the post-lab report, along with the times from the other strategies.

There are a couple of restrictions as to what optimizations you may use.  You may not write assembly code for your solution; it must be valid C++ code.  You may not use an optimization level beyond -O2.  You may use other clang++ flags, if that helps, but you can't use -O3, -O4, etc.  The reason for this last one is that a program is not guaranteed to function the same when using optimizations beyond -O2.  Note that although we are trying to get you to think at least a little bit about making your program fast, keep in mind that we still want clean, correct, readable code.  Your solutions will be judged on style and correctness.

How much time and effort should you put into the optimizations?  We want to see (by looking at your code and the post-lab report) that you have spent thought, time, and effort on the optimizations.  If you can get your code to run in under 2-3 seconds (this has been done), then there probably aren't many more optimizations that you can perform.  However, if your pre-lab code already runs that fast, you still need to add some additional optimizations.  But this gives you a rough idea of what to shoot for in terms of execution time.

When reporting times for the post-lab report, all times must be with the words2.txt and 300x300.grid.txt files as the input.  All programs must be compiled with -O2.  You can do this on any computer, but make sure all your times are done on the same computer for comparison consistency.  The timing code must be as specified in the pre-lab section (i.e. around the hash table usage, not the hash table creation).

Feel free to experiment with different hash functions and different implementations of hash tables.  Part of the assignment is to combine what you have learned about picking a good hash function and appropriate table size with big-theta evaluations of running times of your algorithm.

### Post-lab report ###

One of the deliverables for the post-lab is a PDF document named postlab6.pdf.

If you single-space your report, you can divide the page lengths listed below by a factor of 2.  If you single space your report and include a lot of blank space with tables, that's not what we are looking for here.

Include the big-theta running time of your application, and a full explanation as to why.  This should be half a page or so.  This should address only the word-search portion of your application -- not the reading of input files, hash table creation, etc.  This big-Theta runtime should take into account any and all optimizations that you made.  Please do this in terms of *r* (rows), *c* (columns), and *w* (words).  You can assume that the maximum word size is some small constant.

Include the timing information for your application (as described at the end of the in-lab section).  This should also be half a page or more.  You can do this on any machine and data files, just use the same machine and files for all tests.  Be sure to specify which files and machine you used.  Show timing results (use the timer placement as we used in lab) for:

1. Your original application
1. Pick a new hash function designed to make performance worse in terms of time.  What new hash function did you choose and why was your performance worse?
1. Pick a new hash table size designed to make performance worse in terms of time.  What hash table size did you choose and why was your performance worse?

Describe the optimizations you used, and the times that resulted.  You should also include the overall speedup of your optimizations.  If your original running time (unoptimized) was *x*, and your final running time was *y*, then the speedup is just *x*/*y*.  For example, if your program took 10 seconds to run unoptimized, and 5 seconds after optimizations, you have a speedup of 2.0.  You should have a lot to talk about in this section -- the optimizations you tried, why they worked (or didn't work), problems you encountered, numbered results, etc -- two pages or so is what we are looking for here.
