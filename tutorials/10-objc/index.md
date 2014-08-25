PDR: Objective C Tutorial
=========================

[Go up to the Tutorials table of contents page](../index.html)

Throughout this semester, we have studied C++, which was one way to add object oriented programming capability to the C programming language.  There are other languages that also do that: the one that we will study in this pre-lab is Objective C.  The others are described [here](http://en.wikipedia.org/wiki/C_programming_language#Related_languages).  Objective C had mostly died out as a language that was widely used until Apple decided to use it for their iPhone (and now iPad) application development.  Now it's all the rage.  We want you to be familiar with it, so that you can see a different way to allow for object oriented programming using a C-like language.  

### Objective C Installation ###

The first part of the pre-lab is to make sure you have access to a compilation environment for Objective C.

The course VirtualBox image has Objective C properly installed.  The lab machines in 001 have Objective C installed.  If you are familiar with ssh (or SecureCRT), you can remotely log in to labunix01.cs.virginia.edu, and write your program there (the login is the same as your 001 Linux login).

**Linux:** Install the gobjc package (and any dependencies), which should allow Objective C compilation.

**Mac OS X:** Try it out from the command line (using the `-lobjc flag`), as it may just work.  If not, then read on, as it may be a bit tricky.  The best Objective C environment available is for Macs, since it is the platform used for iPhone and iPad development.  But we don't want you to spend all that time installing this environment for this one pre-lab; if it's installed, then go ahead and use it.  A few Mac-specific notes, though.  First, you CAN use an IDE for this pre-lab.  Second, the Objective C runtime (which is like the Java virtual machine for Java) is different on Macs and Linux - Macs use the NeXT-step runtime, and Linux uses the GNU runtime.  One big difference will be the Ojbect file that you `#import` at the beginning of your file - with a Mac, it's `<Foundation/NSObject.h>`; with Linux, it's `<objc/Object.h>`.  When you submit it, it must compile on the Linux submission system.  Finally, note that some students reported that they needed to include the `-arch i386` flag to the compiler, but we did not need it on our Mac OS X test systems.  Try it both ways to see what works on your system.

If you are having problems getting the compilation to work for you, come speak to us!  Don't spend hours and hours banging your head against the wall.  And you probably shouldn't wait until the last minute to try out the compilation commands...

### Compiling an Objective C program ###

To compile your code, you enter `clang *.m -lobjc`.  This works on both platforms we are using (Linux and Mac OS X).  Since this is not Objective C++ (which [does exist](http://en.wikipedia.org/wiki/Objective_c#Objective-C%2B%2B)), we are using `clang` instead of `clang++`.  You should put the `-lobjc` part in there -- that tells clang to link your code to the Objective C library to allow your program to run.  Note that some platforms will not need the `-lobjc` line, but others will, and it doesn't hurt to put it in anyway.

Enter the following hello world program into a [helloworld.m](helloworld.m.html) ([src](helloworld.m)) file -- Objective C uses .h files for the interfaces (i.e., header files), just like C++ does.  For the implementation files, however, Objective C uses a .m extension instead of the .cpp extension that C++ uses.

```
#import <stdio.h>
int main (void) {
    printf ("Hello world!\n");
}
```

The only difference between that program and a normal C program is the use of `#import` instead of `#include`.  The compilation command is `clang helloworld.m -lobjc`. Also, just like pure C `for`-loops, in pure Objective-C the iterating variable should be declared before the `for`-statement.

Note that for the first program in the tutorial below, you may have to link it to the math library: put `-lm` at the end of the compilation command, otherwise it will tell you that it cannot find the `sqrt()` implementation.

### Learn Objective C ###

The tutorials that we will be using come from Wikibooks, and can be found [here](http://en.wikibooks.org/wiki/Objective-C_Programming).  The first section ("Objective-C concepts") discusses such things as what is OOP, and what is an object.  You can probably skip that part.  The second section ("Getting Started") talks about how to compile a hello world program, which we have done above, so you can skip that part as well.

The tutorial for this week is the following two sections: [Objective C Syntax](http://en.wikibooks.org/wiki/Objective-C_Programming/syntax) and [Objective C: In Depth](http://en.wikibooks.org/wiki/Objective-C_Programming/in_depth).  While we won't expect you to be experts on Objective C after this lab, we will expect you to be familiar with the material at those two URLs.  The first one is what is necessary to write the program for this tutorial; the second is good information to know (i.e. makes a great final exam question), but probably not necessary for the pre-lab program.  Our solution code for this pre-lab did not use any of the material from the in-depth tutorial.

If you are interested in the history of Objective C, and why it's used on the Apple platforms (including the iPhone and iPad), see the [History section](http://en.wikipedia.org/wiki/Objective_c#History) of the [Wikipedia article on Objective C](http://en.wikipedia.org/wiki/Objective_c) (this is not required reading).

For reasons explained in the aforementioned History section of the Wikipedia page, Apple platforms (Mac OS X, iPhone, iPad, etc.) have full-fledged Objective C libraries, similar in complexity to Java's SDK.  There is a GNU clone (called [GNUstep](http://www.gnustep.org/)), but we didn't have you install that, as it's not a simple installation.  So we are working with a very minimal set of libraries.  Essentially, you can use all the C functionality that you want (input & output, math library, etc.), but no libraries of Objective C objects.

### Hack some Objective C code ###

What lab would be complete without a data structure to implement?

Your task is to implement a data structure in Objective C -- a **very simple singly** linked list for integers.  The program is basically the same as that which was required in the [C tutorial](../09-c/index.html).  The requirements for the program are:

1. Read in an integer, which we'll call *n*
2. Read in *n* more ints, and put those into a linked list
     - The linked list must be dynamically allocated
3. Print out that linked list (we don't care the order)
4. Properly deallocate the linked list

The program should be in a file called linkedlist.m (although see the note about the filenames, below).  A sample execution run might look like the following:

```
Enter how many values to input: 4
Enter value 1: 2
Enter value 2: 4
Enter value 3: 6
Enter value 4: 8
8
6
4
2
```

You will need to implement **ONE** class, ListNode (or whatever you would like to call it).  And a `main()` method, of course.  You can put all of your code in one file (put the interface first, then the implementation, then the `main()`), or you can separate it out into separate files (such as linkedlist.m, linkedlist.h, and main.m).  No Makefile is being submitted for this pre-lab.  As long as it compiles with the following compilation command, we really don't care what the files are named (within reason).  The compile command that we will use to compile your code is:

```
clang *.m -lobjc
```

This is not meant to be a complicated program!  We don't care about the order that the list is printed (forward or reverse is fine); you don't need to implement iterators, or anything too complicated.  Our code had just `main()` method, and a ListNode class with a handful of methods.  Your `insert()` code should be in `main()`, not in your class.  Likewise your code to remove the elements, and to print the list should be in `main()`.

A few requirements for the program:

1. It must have a ListNode (or whatever you want to call it) class, which **must have some basic methods**: getters, setters, that sort of thing.
2. Since this is not Objective C++, it will need to use C input and output, so `printf()` and `scanf()` are your friends
3. You are welcome to have a default constructor, and call two separate setter method (to set, presumably, the value and the next fields of the ListNode).  Or you can call a constructor with two parameters; it's your choice (the former is a bit easier).  The Point class in the Wikibooks tutorial does the former.
4. It must print out what it is doing, and show the resulting list (or return value), so that we can follow what is going on.  See the sample output, above, for an example.  Your output need not match ours, but we must be able to tell what is going on from the output.
5. The point of this pre-lab is to work with calling various methods in Objective C (getters, setters, etc.).  Directly accessing the fields is not what we are looking for.

A few notes while working on the program:

1. Pointers can point to Objective C types (objects, structs, etc.) just like in C and C++
2. See the [Point class](http://en.wikibooks.org/wiki/Objective-C_Programming/syntax#The_interface), in the [Wikibooks syntax tutorial](http://en.wikibooks.org/wiki/Objective-C_Programming/syntax), for a code class example.
3. The `this` pointer in Objective C is called `self`
4. The `NULL` pointer in C++ is called `nil` in Objective C
5. Be careful about naming your list class "List" if you are using Mac OS X, as it will conflict with the List class already declared in an existing library.  Name it something else.
6. An object is deleted by calling the `free` method, which is automatically inherited by all classes.  To create a custom destructor, create another method (`freeCompletely`, or similar), and just call `self free` as the last command of that destructor.  But you probably don't need a custom constructor for this program.

### Constructors ###

Constructors are not explained very well in the tutorial, so we describe them a bit here.

In Objective C, constructors are just functions that start with "init" (for convenience sake), and return a pointer to the type we are constructing.  Typically, the first line in constructor is `[super init];`, which will call the parent's constructor.  The last line is typically `return self;`.  There is no special handling for constructors as there is in Java or C++.

You call the default constructor (`init()`) by the syntax:

```
ListNode *node = [[ListNode alloc] init];
```

Note that this can be shorted to:

```
ListNode *node = [ListNode new];
```

This is how it is declared in the tutorial, but this is just a shorthand for the alloc/init version shown first.  Note that you do not need to declare a default constructor - one is provided for you automatically, just like C++.

To create a specific constructor, you create it as you would any other method with parameters, and it is typically named starting with "init".  It is called similar to the alloc/init format described above: 

```
ListNode *node = [[ListNode alloc] initWithValue: v];
```

The "WithValue: v" is the new part in the calling of the specific constructor.
