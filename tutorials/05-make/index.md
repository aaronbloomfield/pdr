PDR: Makefile Tutorial
======================

[Go up to the Tutorials table of contents page](../index.html)

This tutorial is written to introduce the beginning C++ programmer to Unix Makefiles.  You will need the accompanying [pizza.zip](pizza.zip) file, which contains code that we will use during this tutorial.  The original version of this tutorial was written by Paul Lee.

That code consists of: [Makefile](pizza/Makefile.html) ([src](pizza/Makefile)), [cheese.cpp](pizza/cheese.cpp.html) ([src](pizza/cheese.cpp)), [cheese.h](pizza/cheese.h.html) ([src](pizza/cheese.h)), [mushrooms.cpp](pizza/mushrooms.cpp.html) ([src](pizza/mushrooms.cpp)), [mushrooms.h](pizza/mushrooms.h.html) ([src](pizza/mushrooms.h)), [pepperoni.cpp](pizza/pepperoni.cpp.html) ([src](pizza/pepperoni.cpp)), [pepperoni.h](pizza/pepperoni.h.html) ([src](pizza/pepperoni.h)), [peppers.cpp](pizza/peppers.cpp.html) ([src](pizza/peppers.cpp)), [peppers.h](pizza/peppers.h.html) ([src](pizza/peppers.h)), [pizza.cpp](pizza/pizza.cpp.html) ([src](pizza/pizza.cpp)), [pizzadough.cpp](pizza/pizzadough.cpp.html) ([src](pizza/pizzadough.cpp)), [pizzadough.h](pizza/pizzadough.h.html) ([src](pizza/pizzadough.h)), [tomatosauce.cpp](pizza/tomatosauce.cpp.html) ([src](pizza/tomatosauce.cpp)), [tomatosauce.h](pizza/tomatosauce.h.html) ([src](pizza/tomatosauce.h)), [toppings.cpp](pizza/toppings.cpp.html) ([src](pizza/toppings.cpp)), [toppings.h](pizza/toppings.h.html) ([src](pizza/toppings.h)).

### The -c flag to clang++ ###

When compiling a C++, so far we have compiled all of the .cpp files at one time:

```
clang++ postfixCalculator.cpp stack.cpp testPostfixCalc.cpp
```

Or, if there are only those three .cpp files in the current directory:

```
clang++ *.cpp
```

There are a number of things going on here.  First, clang++ will *compile* each file separately.  Compiling by itself does not create an executable -- it just creates a part of the final executable program.  After compiling the three files, clang++ has three program parts (called postfixCalculator.o, stack.o, and testPostfixCalc.o), but no complete program.  It will then *link* the three parts to create the final executable.  Although we see it as one command, it is in fact two separate and distinct stages.

While it may seem a bit more complicated to do this in two separate steps, it turns out to be very useful if you have a very large program -- such as hundreds (or thousands) of .cpp files.  If you modify only one file, you just have to compile that single file, and then link everything together.  Specifically, you don't have to compile all the other files again.  So far, we have been telling the compiler to do these two commands at the same time (i.e., `clang++ postfixCalculator.cpp stack.cpp testPostfixCalc.cpp` or `clang++ *.cpp`).  This tells clang++ to compile each file separately, and then link them together to create the executable a.out.

If you specify the -c option to clang++, it tells the compiler to just compile the file, but do not link it.  The result of this compilation is called an *object file*, and has a .o extension.  Thus, if you call `clang++ -c postfixCalculator.cpp`, the compiler will create a postfixCalculator.o file.  You will need to compile each .cpp file in this way.

```
clang++ -c postfixCalculator.cpp
clang++ -c stack.cpp
clang++ -c testPostfixCalc.cpp
```

At this point, you will have 3 new files on your computer: postfixCalculator.o, stack.o, and testPostfixCalc.o.  These files contain *object code*, which is essentially compiled (but not linked) C++ code (the .o extension is for 'object').  The 'object' part of 'object code' has nothing to do with object oriented programming -- you can compile C code (which is not object oriented code) into .o files as well.

The second step is to link these three files together to create the executable:

```
clang++ postfixCalculator.o stack.o testPostfixCalc.o
```

Note on this line we specified the .o files, not the .cpp files.  The three .o files that you specify tell clang++ to link them into a single executable file -- clang++ knows that any file with a .o extension is already compiled, so it will just link the files rather than trying to compile them.  Note that we could also have written that last line as follows if those are the only three .o files in the current directory.

```
clang++ *.o
```

Try compiling your program this way.  We certainly aren't requiring you to always compile your programs in this manner, as we know it's rather tedious.  Makefiles, the subject of this tutorial, provide a shortcut to compile programs, and they use the -c flag, which is why we are learning about it now.

### Introduction to `make` ###

Object code, which is what is in the .o files, is advantageous if we have a large project, because making a change after a compile will only require re-compiling the files that have changed, and then linking it with the rest of the object files.  A lot of time can be saved using this recompilation procedure.  However, it can be tedious for a programmer to keep track of all of the dependencies and type in the commands to efficiently recompile a large project.  This is where `make` and Makefiles help.  `make` is a Unix utility and a Makefile is a file that `make` reads in, and that file tells `make` what to do.

Note that the 'object' of 'object code' has nothing to do with object-oriented programming.  Non-OO programming languages (such as C) still produce 'object' code when compiled with the -c option.

`make` allows a programmer and the users of their program to be able to easily compile and manage their program without a lot of typing.  It recompiles only the minimal number of files required to generate an updated executable file.

### What's inside a Makefile? ###

A typical Makefile consists of comments, variables, rules, and prerequisites.  We'll get to each of these in turn.  First, though, we need to obtain the code used in this tutorial.

- Download the zip file for this tutorial called [pizza.zip](pizza.zip)
- Unzip the files with the command: `unzip pizza.zip`

To compile your program, just type `make` from the pizza/ directory.  Notice that it will go through each of the individual .cpp files, and compile each one (with the -c option).  Once that is done, it will link all of the .o files to create the 'pizza' executable.

Try running `make` again.  Notice that it will not recompile anything, as none of the source code has changed.  Indeed, it responds with, `make: 'pizza' is up to date`.

Edit the 'peppers.cpp' file.  Nothing complicated -- just put in a comment (such as your name) at the top.  Specifically, we don't want to change any of the source code, only the comments.  Save the file, and run `make` again.  Notice that it recompiled two files (peppers.cpp and toppings.cpp), and then re-linked the program.  In particular, it did not need to recompile the other files.

But why did it recompile toppings.cpp?  It makes sense that it recompiled peppers.cpp, as that file was modified (note that a computer can't easily tell that only the comments were modified).  As we'll see in a bit, there was a *prerequisite* -- meaning that the Makefile specifically stated that when peppers.cpp is modified, toppings.cpp should also be recompiled (into toppings.o).

The default name for a Makefile is just 'Makefile' (note the capitalization).  You can name it something else (how to do this is at the very end of this tutorial), but it's easier to keep this naming convention.  If you name it something else, you will need to call `make` with the -f flag: `make -f Makefile-by-any-other-name`.

### Comments ###

Comments in a Makefile must begin with `#`, and should generally start in the left-most column of a given line.
Put your name and lab section as a comment at the top of the Makefile.

### Variables ###

Variables allow a programmer to easily specify the compiler used, compiler arguments, file paths, targets, and pretty much anything else that one may need to specify when compiling a file.  For example, you can specify to always compile with the '-Wall' option (which will list all warnings while compiling), and/or use a variable to store all the object files your program needs.

The following is a list of some predefined variables in `make` (taken from the [GNU `make` Manual](https://www.gnu.org/software/make/manual/), specifically [section 10.3](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables)):

| Variable | Meaning |
|------------|---------|
| CXX | Program for compiling C++ programs |
| CXXFLAGS | Options provided to the C++ compiler |
| CC | Program for compiling C programs |
| CFLAGS | Options provided to the C compiler |
| AS | Program for compiling assembly code; this will be needed in lab 8 |

In the pizza Makefile, the first variable in the file is:

```
CXX=clang++ $(CXXFLAGS)
```

This line defines the C++ compiler to be 'clang++'.  It also specifies to put any clang++ flags after the compiler command -- so if we defined the flags to be '-Wall', then each compilation by `$(CXX)` would include that option.

To use a variable, surround it by $ and parentheses.  For example, `$(CXX) project.cpp` would substitute the value of the `CXX` variable and result in `clang++ project.cpp`.

### Rules ###

Rules dictate what Makefiles can do, and each one is composed of a *target* (the name of the rule), *prerequisites* (any rules that this one depends on), and the *recipe* (a series of commands for `make` to execute).

Rules can:

- create programs (such as the 'pizza' rule in the provided Makefile)
    - including variants optimized for debugging or speed
- clean up any temporary files
- compile a single file
- and much more! Anything that you can do in your terminal, `make` can automate for you

Rules have the following format:

```
target: target1.o target2.o # <-- prerequisites
	$(CXX) target1.o target2.o -o target # <-- the recipe (can be multiple commands, across multiple lines)

# Compile target1.cpp into an object (.o) file if it has changed since the last time this rule was run
target1.o: target1.cpp
	$(CXX) -c target1.cpp

# Ditto, for target2.cpp
target2.o: target2.cpp
	$(CXX) -c target2.cpp
```

Targets always have colons after them, and any prerequisite rules are separated by spaces after the colon.  The rule here in this example is that `make target` will compile 'target1.o' and 'target2.o' into an executable called 'target', but only after making sure the 'target1.o' and 'target2.o' rules have run.

Spacing in Makefiles is ***VERY*** specific.  Any target must start at the left-most column in a given line.  Each command in the recipe must start a single tab (not spaces!).  `make` is very unforgiving if you do not have your spacing exactly correct.

The provided pizza Makefile has a number of rules.  One of them is 'pizza' -- this will create the entire pizza program.  Calling `make` by itself will always run the first rule listed in the Makefile, in this case the 'pizza' rule.  Alternatively, you can invoke a specific rule by providing its target name.  If we wanted to run the 'clean' rule, we would call `make clean`.

### Targets ###

Generally speaking, targets specify the name of the file that should be created after the rule is run.
If the target file doesn't exist, `make` will always execute the rule to create it.
If the target file does exist, `make` then looks at that target's prerequisites to determine whether to execute the rule.

### Prerequisites ###

As mentioned above, rules only run if the target file does not exist or of their prerequisites had to be run.

When we run the 'target' rule, it checks the 'target1.o' rule to see if it should be run.
That rule in turn depends on its respective C++ file.  Since there is no explicit rule for target1.cpp, `make` will look for a file called 'target1.cpp', and see if it has been updated/modified since the last time the 'target1.o' rule was run.
If it has been modified, or if target1.o does not exist, then `make` will run the recipe for 'target1.o'.

Now that we have finished looking at the first prerequisite, `make` will do the same thing for the next prerequisite, 'target2.o'.

Finally, after checking all prerequisite rules, `make` will use the same logic to determine whether to run the recipe for 'target' itself (were both 'target1.o' and 'target2.o' up to date, and does 'target' already exist?).

### Determining prerequisites ###

As we have seen, a Makefile determines which files to compile based on the specified prerequisites.  For example, the toppings.cpp file depends on a number of files: toppings.cpp, toppings.h, cheese.h, mushrooms.h, peppers.h, and pepperoni.h.  A prerequisite, then, is a file that is either the source code (such as toppings.cpp), directly included (such as toppings.h), or indirectly included (such as cheese.h, mushrooms.h, peppers.h, and pepperoni.h).  Note that this list of prerequisites does not match what is in the predefined Makefile -- more on this later.  The first .h file (toppings.h) is included by toppings.cpp, whereas the rest are included by toppings.h.  Thus, at the end of our Makefile, we could have the following line:

```
toppings.o: toppings.cpp toppings.h cheese.h mushrooms.h \
  peppers.h pepperoni.h
```

The backslash at the end of the first line tells `make` that the prerequisite line continues on the next line.  This entire statement will cause a recompilation of toppings.o if any of the listed files are modified.  Notice that a number of .h files (such as pizzadough.h) are not included, as toppings.o does not depend on them.

You may notice that each .o target does not have a recipe attached to it!  This is because `make` contains some [implicit rules](https://www.gnu.org/software/make/manual/make.html#Catalogue-of-Rules) and knows to convert `*.cpp` files to `*.o` files using `$(CXX) $(CXXFLAGS) -c filename.cpp`.

### Automatically generating prerequisites ###

Creating these prerequisite lists are essential for a properly functioning Makefile, but they are tedious to create.  If you wrote another file that included toppings.h (anchovies.cpp, for example), you would have to remember that toppings.h included four other .h files, and should thus include anchovies.h.  Fortunately, we can use clang++ to generate all the prerequisites for us by entering the following command:

```
clang++ -MM *.cpp
```

The '-MM' flag tells clang++ to look through each of the files that end in .cpp, and generate Makefile-style prerequisites.  The output would be the following:

```
cheese.o: cheese.cpp cheese.h
mushrooms.o: mushrooms.cpp mushrooms.h
pepperoni.o: pepperoni.cpp pepperoni.h
peppers.o: peppers.cpp peppers.h
pizza.o: pizza.cpp pizzadough.h tomatosauce.h toppings.h cheese.h \
  mushrooms.h peppers.h pepperoni.h
pizzadough.o: pizzadough.cpp pizzadough.h
tomatosauce.o: tomatosauce.cpp tomatosauce.h
toppings.o: toppings.cpp toppings.h cheese.h mushrooms.h peppers.h \
  pepperoni.h
```

We can cut-and-paste these rules directly into the Makefile, to tell `make` what the prerequisites for each file are.  We will do this in a bit.

You will notice that the lines in the provided Makefile (purposely) do not exactly mimic the lines above -- for example, toppings.o in the Makefile depends on a few .cpp files, and not what is listed just above.  We will get to fixing this shortly.

Once again, we see that implicit rules are being used here for the `*.cpp` to `*.o` conversion, which helps us cut down on a lot of unnecessary repitition.

In order to compile our final program, we would still need to utilize the 'pizza' rule in the Makefile:

```
pizza: pizza.o pizzadough.o tomatosauce.o toppings.o \
       mushrooms.o peppers.o cheese.o pepperoni.o
	$(CXX) $(DEBUG) pizza.o pizzadough.o tomatosauce.o toppings.o \
	                mushrooms.o peppers.o cheese.o pepperoni.o \
	                -o pizza
	@echo "Pizza is Hot and Ready!"
```

The line spacing is odd here because three of the lines wrap around to the next line.  We snuck in a `$(DEBUG)` variable usage here, which could have been a user-defined variable at the top of the Makefile.

Notice, though, that we have to repeat all the .o files in this target rule.  We can avoid this by creating a variable:

```
OBJECTS = pizza.o pizzadough.o tomatosauce.o toppings.o \
          mushrooms.o peppers.o cheese.o pepperoni.o
```

And changing the pizza rule to:

```
pizza: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o pizza
	@echo "Pizza is Hot and Ready!"
```

If we set up our CXX variable to include the C++ flags variable (i.e., `CXX = clang++ $(CXXFLAGS)` at the top of the Makefile), then we do not need to include CXXFLAGS in the above line.  Otherwise, we will want to replace that line with, `$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o pizza`.  This will allow any clang++ compiler options to be included also.

What happens when `make` is run is that it knows it has to create eight .o files (pizza.o, toppings.o, etc.), and looks at the various .o rules to figure out how to do that.  After that, `make` will then create the final executable, and the print out the 'Pizza is Hot and Ready' line.  'echo' is just a normal Unix command -- it prints out what is on the rest of the line.  If you are going to use punctuation, it is best to put it in quotes (many characters have special meanings, such as !).

### Other targets ###

Occasionally, we may want rules whose targets are not associated with specific filenames.  For example, most Makefiles have a 'clean' target that has no prerequisites and will remove any unwanted files produced.  It will usually look something like this:

```
.PHONY: clean
clean:
	-rm -f *.o *~ a.out
```

The `.PHONY` target tells `make` to _always_ execute the 'clean' target, even if there happens to be a file named 'clean'.
You should specify any rules that are not associated with filenames as prerequisites of the `.PHONY` target.

With this rule, `make clean` will remove all files ending in .o, all files ending in `~` (backup files created by emacs), and a file called 'a.out'.  The '-' in front of rm means that it does not matter if rm was unsuccessful in removing a .o file (if a command fails, `make` normally thinks that it should abort due to the error, but the '-' here tells `make` to ignore it if this command fails).  The '-f' option does a few things, one of which is to prevent printing of error messages if the files do not exist (i.e. if you run `make clean` twice in a row).

Makefiles may also have "debug" and "release" targets.  These targets will generate a version of the output file for debugging (through LLDB, for example) and a version of the output file with optimization flags.  Another way to do this is to edit the Makefile, enter '-g' or '-O2' in the CXXFLAGS variable, then do a `make clean` and then `make`.

### Creating a new Makefile ###

We have seen a number of ways to improve the provided pizza Makefile.  We'll put them together into a single, well-formed, Makefile.  Below are the steps to do so; each of these steps are described in more detail above.

- Comments!  This Makefile will be submitted as part of [lab 5](../../labs/lab05/index.html) (see below), so you will need to put in your name and userid at the top of the file.
- We will want to declare the pre-defined variables, CXX and CXXFLAGS.  CXX is going to be `clang++`, and we can define CXXFLAGS to be `-Wall -O2` (give all warnings and optimize the code).
- We'll want to define a variable, probably called OBJECTS, that will list all of the .o files that we are compiling into our target executable.
- Our first rule -- which must be called 'pizza' -- will be for compiling the program.  It will depend on all of the .o files (defined in the OBJECTS variable), and will define how to compile the program executable.
- Our second rule, 'clean', will remove the executable itself, all the .o files, and all files that end in the tilde (`*~`, the backup files that Emacs creates).
- Lastly, we will need to have clang++ create all the prerequisite rules, which we will copy-and-paste into the bottom of the Makefile.

Test out the Makefile to ensure it works.  You will need to rename it to 'Makefile-pizza', and submit it as part of pre-lab 5 (we can't name it 'Makefile', as you are submitting a Makefile for the other parts of the lab already).  To force `make` to use a different Makefile, you can use the `-f` flag: `make -f Makefile-pizza`.  To specify a different target, the target name goes after the file name: `make -f Makefile-pizza clean`.

### Further information ###

This tutorial only scratches the surface of what `make` can do!  There are many more powerful concepts that can be very useful for larger projects.
For more information, consult the man page for `make` and/or go to the [GNU website for `make`](https://www.gnu.org/software/make/manual/).  Google searches will also turn up lots of good resources.
