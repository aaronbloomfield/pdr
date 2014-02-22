PDR: Makefile Tutorial
======================

[Go up to the Tutorials table of contents page](../index.html)

This tutorial is written to introduce the beginning C++ programmer to Unix Makefiles.  You will need the accompanying [pizza.zip](pizza.zip) file, which contains code that we will use during this tutorial.  The original version of this tutorial was written by Paul Lee.

That code consists of: [Makefile](pizza/Makefile.html) ([src](pizza/Makefile)), [cheese.cpp](pizza/cheese.cpp.html) ([src](pizza/cheese.cpp)), [cheese.h](pizza/cheese.h.html) ([src](pizza/cheese.h)), [mushrooms.cpp](pizza/mushrooms.cpp.html) ([src](pizza/mushrooms.cpp)), [mushrooms.h](pizza/mushrooms.h.html) ([src](pizza/mushrooms.h)), [pepperoni.cpp](pizza/pepperoni.cpp.html) ([src](pizza/pepperoni.cpp)), [pepperoni.h](pizza/pepperoni.h.html) ([src](pizza/pepperoni.h)), [peppers.cpp](pizza/peppers.cpp.html) ([src](pizza/peppers.cpp)), [peppers.h](pizza/peppers.h.html) ([src](pizza/peppers.h)), [pizza.cpp](pizza/pizza.cpp.html) ([src](pizza/pizza.cpp)), [pizzadough.cpp](pizza/pizzadough.cpp.html) ([src](pizza/pizzadough.cpp)), [pizzadough.h](pizza/pizzadough.h.html) ([src](pizza/pizzadough.h)), [tomatosauce.cpp](pizza/tomatosauce.cpp.html) ([src](pizza/tomatosauce.cpp)), [tomatosauce.h](pizza/tomatosauce.h.html) ([src](pizza/tomatosauce.h)), [toppings.cpp](pizza/toppings.cpp.html) ([src](pizza/toppings.cpp)), [toppings.h](pizza/toppings.h.html) ([src](pizza/toppings.h)).


### The -c flag to clang++ ###

When compiling a C++, so far we have compiled all of the .cpp files at one time:

```
clang++ foo.cpp bar.cpp baz.cpp
```

Or, if there are only those three .cpp files in the current directory:

```
clang++ *.cpp
```

There are a number of things going on here.  First, clang++ will *compile* each file separately.  Compiling by itself does not create an executable -- it just creates a part of the final executable program.  After compiling the three files, clang++ has three program parts (called foo.o, bar.o, and baz.o), but no complete program.  It will then *link* the three parts to create the final executable.  Although we see it as one command, it is in fact two separate and distinct stages.

While it may seem a bit more complicated to do this in two separate steps, it turns out to be very useful if you have a very large program -- such as hundreds (or thousands) of .cpp files.  If you modify only one file, you just have to compile that single file, and then link everything together.  Specifically, you don't have to compile all the other files again.  So far, we have been telling the compiler to do these two commands at the same time (i.e., `clang++ foo.cpp bar.cpp baz.cpp` or `clang++ *.cpp`).  This tells clang++ to compile each file separately, and then link them together to create the executable a.out.

If you specify the -c option to clang++, it tells the compiler to just compile the file, but do not link it.  The result of this compilation is called an *object file*, and has a .o extension.  This, if you call 'clang++ -c foo.cpp', the compiler will create a foo.o file.  You will need to compile each .cpp file in this way.  Take your code from the stacks post-lab:

```
clang++ -c postfixCalculator.cpp
clang++ -c stack.cpp
clang++ -c testPostfixCalc.cpp
```

At this point, you will have 3 new files on your computer: postfixCalculator.o, stack.o, and testPostfixCalc.o.  These files contain *object code*, which is essentially compiled (but not linked) C++ code (the .o extension is for 'object').  The 'object' part of 'object code' has nothing to do with object oriented programming -- you can compile C code (which is not object oriented code) into .o files as well.

The second step is to link these three files together to create the executable:

```
clang++ -o pfcalc postfixCalculator.o stack.o testPostfixCalc.o
```

Note on this line we specified the .o files, not the .cpp files.  Here we are using the -o flag to create a `pfcalc` executable.  The three .o files that you specify tell clang++ to link them into a single executable file -- clang++ knows that any file with a .o extension is already compiled, so it will just link the files rather than trying to compile them.  Note that we could also have written that last line as follows.

```
clang++ -o pfcalc *.o
```

The '*.o' will compile all the files with a .o extension -- as long as there are only those 3 .o files in the current directory (postfixCalculator.o, stack.o, and testPostfixCalc.o), then it will do the same thing.

Try compiling your program this way.  We certainly aren't requiring you to always compile your programs in this manner, as we know it's rather tedious.  Makefiles, the subject of this tutorial, provide a shortcut to compile programs, and they use -c flag, which is why we are learning about it now.

**When submitting code in this course, you should *NEVER* name a program via the -o flag unless specifically told otherwise.**  Doing so will prevent the executable from being called 'a.out', which will prevent the grading scripts from properly finding (and running) your program.

### Introduction to make ###

Object code, which is what is in the .o files, is advantageous if we have a large project, because making a change after a compile will only require re-compiling the files that have changed, and then linking it with the rest of the object files.  A lot of time can be saved using this recompilation procedure.  However, it can be tedious for a programmer to keep track of all of the dependencies and type in the commands to efficiently recompile a large project.  This is where make and Makefiles help.  make is a Unix utility and a Makefile is a file that make reads in, and that file tells make what to do.
	
Note that the 'object' of 'object code' has nothing to do with object-oriented programming.  Non-OO programming languages (such as C) still produce 'object' code when compiled with the -c option.

make allows a programmer and the users of their program to be able to easily compile and manage their program without a lot of typing.  make will allow a programmer to easily recompile only the minimal number of files required to generate an updated executable file.

### What's inside a Makefile? ###

A typical Makefile consists of comments, macro (variable) definitions, rules, and dependencies.  We'll get to each of these in turn.  First, though, we need to obtain the code used in this tutorial.

- Download the zip file for this tutorial called [pizza.zip](pizza.zip)
- Unzip the files with the command: 'unzip pizza.zip'

To compile your program, just type 'make' from the pizza/ directory.  Notice that it will go through each of the individual .cpp files, and compile each one (with the -c option).  Once that is done, it will link all of the .o files to create the 'pizza' executable.

Try typing 'make' again.  Notice that it will not recompile anything, as none of the source code has changed.  Indeed, it responds with, `make: 'pizza' is up to date`.

Edit the 'peppers.cpp' file.  Nothing complicated -- just put in a comment (such as your name) at the top.  Specifically, we don't want to change any of the source code, only the comments.  Save the file, and type 'make' again.  Notice that it recompiled two files (peppers.cpp and toppings.cpp), and then re-linked the program.  In particular, it did not need to recompile the other files.

But why did it recompile toppings.cpp?  It makes sense that it recompiled peppers.cpp, as that file was modified (note that a computer can't easily tell that only the comments were modified).  As we'll see in a bit, there was a *dependency* -- meaning that the Makefile specifically stated that when peppers.cpp is modified, then toppings.cpp should also be recompiled (into toppings.o).  More on dependencies in a bit.

Note that the default name for a Makefile is just 'Makefile' (note the capitalization).  You can name it something else (how to do this is at the very end of this tutorial), but it's easier to keep this naming convention.  If you name it something else, you will need to call make with the -f flag: `make -f Makefile-by-any-other-name`.

### Editing the Makefile ###

Comments in a Makefile must begin with '#', and should generally start in the left-most column of a given line.  Edit the pizza Makefile, and put your name and lab section at the top of the Makefile.

Macros allow a programmer to easily specify the compiler used, compiler arguments, file paths, targets, and pretty much anything else that one may need to specify when compiling a file.  For example, you can specify that you will always compile with the '-Wall' option (which will list all warnings while compiling).  make already comes with a default list of predefined macros, but it is good practice to define them even if they are the same as the default definition.  You can also define your own macros, as we'll see in a moment.  Note that if you define a predefined macro, your definition will override the default definition.

The following is a list of some predefined macros in make (taken from the [GNU Make Manual](http://www.gnu.org/software/make/manual/), specifically [section 10.3](http://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables)):

| Macro name | Meaning |
|------------|---------|
| AS | Program for compiling assembly code; default 'as'; this will be needed in lab 8 |
| CC | Program for compiling C programs; default 'clang' |
| CXX | Program for compiling C++ programs; default 'clang++' |
| CFLAGS | Options provided to the C compiler |
| CXXFLAGS | Options provided to the C++ compiler |
| PC | Program for compiling Pascal programs; default 'pc' |
| RM | Command to remove a file; default 'rm -f' |


Note that in the pizza Makefile, the CXX macro is defined as clang++.  Whenever a macro is *used*, it appears surrounded by $ and parentheses.  For example, `clang++ project.cpp` would be entered as `$(CXX) project.cpp`.  However, whenever a macro is *defined*, the $ and parentheses are not needed as in `CXX=clang++`.

In the pizza Makefile, the first macro in the file is:

```
CXX=clang++ $(CXXFLAGS)
```

This line defines the C++ compiler to be clang++.  It also specifies to put any clang++ flags after the compiler command -- so if we defined the flags to be '-Wall', then each compilation by clang++ would include that option.  We don't define CXXFLAGS in that file, but it's a good idea to put CXXFLAGS there, so that if we do add a CXXFLAGS variable, we won't have to make any other changes.

### Target rules ###

A single Makefile can hold the instructions to make a number of what are called *targets*.  A target is just a name for something that make should do.  A target can be a program (such as the 'pizza' target in the provided Makefile), a debug version of the program (to run through gdb, for example), an optimized version of the program (for the final release), a target to clean up all the temporary files, etc.

Rules define dependencies between other files and targets.  Some rules may look something like this:

```
target:  target1.o target2.o 
	$(CXX) target1.o target2.o -o output 

target1.o: target1.cpp
	$(CXX) -c target1.cpp

target2.o: target2.cpp
	$(CXX) -c target2.cpp
```

Note that a target always has a colon after it -- this is what tells make that you are specifying the name of a target.  The 'rule' here is that 'target' requires 'target1.o' and 'target2.o'.  Alternatively, one can state that 'target1.o' and 'target2.o' are *dependencies* of 'target', as target depends on them to perform it's task.

Spacing in Makefiles is ***VERY*** specific.  Any target must start at the left-most column in a given line.  In the example above, each one is followed by a single command (we can have more than one, as we'll see in a bit).  Each command must start the line with a single tab (not spaces!).  make is very unforgiving if you do not have your spacing exactly correct.

For the 'target' rule above, it depends on target1.o and target2.o -- meaning, if either target1.o or target2.o are modified, then this rule has something to do (as opposed to being already up to date).  In this case, make will go to target1.o and see that it depends on target1.cpp.  Since there is no rule for target1.cpp, it will check to see if target1.cpp has been updated (i.e. modified).  If either target1.cpp has been updated since the last creation of target1.o (or if target1.o does not exist), make will then execute the action defined for target1.o.  After `$(CXX) $(CXXFLAGS) -c target1.cpp` generates target1.o, make will go to the rule for target2.o.  Again, it will see that target2.o depends on target2.cpp -- so make will check to see if target2.cpp has been updated.  If target2.cpp has been updated since the last creation of target2.o (or if target2.o does not exist), make will then execute the action defined for target2.o.  After target2.o is generated, make will go back to the first rule ('target') and execute the action defined for target since all of the dependencies for target have been visited.  The end result will be a file called output output as specified in the action for the first rule.

The provided pizza Makefile has a number of target rules -- a target rule is just a few lines that define what to do for a particular target.  One of them is 'pizza' -- this will create the entire pizza program.  As it is the first rule listed, you can just call 'make', and it will use this rule.  Alternatively, you can invoke the rule by name by entering 'make pizza', and it will also make this rule.

Another target is 'clean'.  This will remove all the .o files, as well as the executable.  As it is not the first rule, it needs to be invoked by calling 'make clean'.

There are also specific rules for each of the .o files -- we will get to these in a moment.

### Dependencies ###

As we have seen, a Makefile determines which files to compile based on the specified dependencies.  For example, the toppings.cpp file depends on a number of files: toppings.cpp, toppings.h, cheese.h, mushrooms.h, peppers.h, and pepperoni.h.  A dependency, then, is a file that is either the source code (such as toppings.cpp), directly included (such as toppings.h), or indirectly included (such as cheese.h, mushrooms.h, peppers.h, and pepperoni.h).  Note that this list of dependency files does not match what is in the predefined Makefile -- more on this later.  The first .h file (toppings.h) is included by toppings.cpp, whereas the rest are included by toppings.h.  Thus, at the end of our Makefile, we could have the following line:

```
toppings.o: toppings.cpp toppings.h cheese.h mushrooms.h \
  peppers.h pepperoni.h 
```

The backslash at the end of the first line tells make that the dependency line continues on the next line.  This entire statement will cause a recompilation of toppings.o if any of the listed files are modified.  Notice that a number of .h files (such as pizzadough.h) are not included, as toppings.o does not depend on them.

Creating these dependency lines is essential for a properly functioning Makefile, but they are tedious to create.  If you wrote another file that included toppings.h (anchovies.cpp, for example), you would have to remember that toppings.h included four other .h files, and should thus include anchovies.h.  Fortunately, we can use clang++ to generate these dependency lists for us by entering the following command:

```
clang++ -MM *.cpp
```

This tells clang++ to look through each of the files that end in .cpp, and generate Makefile-style dependency lines (that is what the '-MM' switch does).  The output would be the following:

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

You will notice that the lines in the provided Makefile (purposely) do not exactly mimic the lines above -- for example, toppings.o in the Makefile depends on a few .cpp files, and not what is listed just above.  We will get to fixing this shortly.

These dependency rules look very similar to target rules.  The difference is that a target rule has one or more lines of commands after rule, whereas the dependency only lists dependencies.

Once we have these dependency rules, we can cut-and-paste them directly into the Makefile, to tell make what the dependencies are.  We will do this in a bit.

### Suffix rules ###

If you examine the Makefile, you'll notice that the same compilation command is repeated for each .o target:

```
$(CXX) -c filename.cpp
```

Although we have not defined anything for our CXXFLAGS macro, it's a good idea to include it right after the CXX macro.

You can imagine that if you had a thousand (or more) files in your system, then this would be a difficult Makefile to edit -- you would have to enter such a line for each file in the system.  There certainly exist such systems of this size -- the Linux kernel, for example, has about 10,000 C files (plus many other files, such as assembly files).  As a side note, while such big systems often use make, they also have tools that automatically will generate the Makefiles -- for example, the tools will create a Makefile, and automatically put in the output from 'clang++ -MM' at the end of the file.  We won't see those tools here, though.

What we would like to do is to tell make that for all files that end in .cpp, we want to have a common compilation command.  To do this, we enter the following line in the Makefile:

```
.SUFFIXES: .o .cpp
```

This is a *suffix rule*, which tells make how to create files with the .o suffix.  Suffix rules are also known as implicit rules, but we'll use the former terminology here.  This command tells make that it should create a .o file from a similarly named .cpp file (i.e. pizza.o from pizza.cpp).  Fortunately, make knows that a .cpp file is a C++ file, and that a .o file is a object file.  Make will then automatically call the following command for each .o file that it wants to create:

```
$(CXX) $(CXXFLAGS) -c filename.cpp
```

Notice that make will use the predefined CXX macro (as make knows that you are compiling a C++ file) and the predefined CXXFLAGS macro as parameters to the compiler (such as '-Wall').

In order to compile our final program, we would still utilize the pizza rule in the Makefile:

```
pizza: pizza.o pizzadough.o tomatosauce.o toppings.o \
  mushrooms.o peppers.o cheese.o pepperoni.o
        $(CXX) $(DEBUG) pizza.o pizzadough.o tomatosauce.o \
			toppings.o mushrooms.o peppers.o cheese.o \
  pepperoni.o -o pizza
        @echo "Pizza is Hot and Ready!"
```

The line spacing is odd here because three of the lines wrap around to the next line.  We snuck in a `$(DEBUG)` macro usage here, which could have been a user-defined macro at the top of the Makefile.

Notice, though, that we have to repeat all the .o files in this target rule.  We can avoid this by creating a macro:

```
OFILES = pizza.o pizzadough.o tomatosauce.o toppings.o \
    mushrooms.o peppers.o cheese.o pepperoni.o
```

And changing the pizza rule to:


```
pizza: $(OFILES)
        $(CXX) $(DEBUG) $(OFILES) -o pizza
        @echo "Pizza is Hot and Ready!"
```

If we set up our CXX macro to include the C++ flags macro (i.e., `CXX = clang++ $(CXXFLAGS)` at the top of the Makefile), then we do not need to include CXXFLAGS in the above line.  Otherwise, we will want to replace that line with, `$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES) -o pizza`.  This will allow any clang++ compiler options to be included also.

What happens when make is run is that it knows it has to create eight .o files (pizza.o, toppings.o, etc.).  In order to do so, it looks at the suffix rule, which tells make how to create a .o file from a similarly named .cpp file.  make will then create the final executable, and the print out the 'pizza is hot and ready' line.  Note that 'echo' is a print command -- it just prints out what is on the rest of the line.  If you are going to use punctuation, it is best to put it in quotes (many characters have special meanings, such as !).

### More on rules and targets ###

Observe that the general format for any rule is:

```
<target>: <dependencies>
<tab>	<actions>
```

The tab is very important here!  make will not work without the tab!

Also notice that <target> does not have to be a file, but could just be a reference to another rule.  For example, if we had another target called target2 that we wanted our Makefile to process, we could just create the following rule:

```
outcome: target target2
```

The above rule would not require an action since the actions would be defined in the rules for target and target2.  As there is no rule for this line (i.e., nothing defined in the <actions> part), it is just called a dependency -- this is what the output from `clang++ -MM` generates.

A rule can also have more than one action, and those actions are not just limited to compiling files.  As a matter of fact, any line that begins with a tab will be executed (macros, such as CXX, being replaced by their definition before hand).  Each line designated as an action to be performed all begin in the directory where make is executed.  If a line is so long that it is hard to read, you can use '\\' to continue to the next line and have both lines interpreted as one line.  For example:

```
target: target1 target 2 target3 target4 target5 target6 \
   target7 target8 target9 target10 target11 target12
	mkdir folder1
cd folder1
mkdir folder2
	cd folder2 
@echo I am in folder 2
```

When make is invoked, after performing an action, make will output the action to the screen.  If you do not want an action to be displayed after invoking make, you can use '@' before the command.  This is useful if you want to echo something but not have echo appear; however, the @echo statement must be on a separate line.

In the pizza directory, pizza.cpp contains `main()` which uses the PizzaToppings, PizzaDough, and TomatoSauce classes.  PizzaToppings is a class which makes use of the Cheese, Pepperoni, Peppers, and Mushrooms classes.  

Note the following rules in the provided Makefile:

```
pizza: pizza.o pizzadough.o tomatosauce.o toppings.o \
       mushrooms.o peppers.o cheese.o pepperoni.o
$(CXX) pizza.o pizzadough.o tomatosauce.o toppings.o \
       mushrooms.o peppers.o cheese.o pepperoni.o -o pizza
@echo "Pizza is Hot and Ready!"

toppings.o: pepperoni.cpp peppers.cpp mushrooms.cpp cheese.cpp \ 
 toppings.cpp pepperoni.h peppers.h mushrooms.h \
 cheese.h toppings.h
	$(CXX) -c toppings.cpp
```

The first rule above should create a pizza executable file.  Notice that in the second rule, the action performed is on only one of the files that toppings.o depends on.  One way to think about it is that if any of the files that toppings.o depends on changes, then toppings.o will have to be regenerated.  Rules to produce the rest of the .o files have not been defined yet.

### Automatic variables ###

A Makefile may also have a feature called automatic variables which have a value depending on where and when it is used.  There two useful automatic variables that we'll study here: $@, which is the file name of the target, and $?, which is the names of all the changed dependents.  Examples of their use are below.

```
project.o: project.cpp
	clang++ -c $@.cpp -o $@

project: project1.o project2.o project3.o
	clang++ $? -o $@
```

### Other targets ###

Makefiles usually have a 'clean' target that has no dependencies, but will remove any unwanted files produced.  It will usually look something like this:

```
clean:
	-rm -f *.o *~ outputfile
```

The above clean rule does not depend on anything, and its action will not be performed unless directly invoked by calling 'make clean'.  The above rule removes all files ending in .o, all files ending in `~` (backup files created by emacs), and a file called outputfile.  The '-' in front of rm means that it does not matter if rm was unsuccessful in removing a .o file (if a command fails, make normally things that it should abort due to the error, but the '-' here tells make to ignore it if this command fails).  The '-f' option does a few things, one of which is to prevent printing of error messages if the files do not exist (i.e. if you run 'make clean' twice in a row).

Makefiles may also have a "debug" and "optimized" target.  These targets will generate a version of the output file for debugging (through gdb, for example) and a version of the output file with optimization flags.  Another way to do this is to edit the Makefile, enter '-g' or '-O2' in the CXXFLAGS macro, then do a 'make clean' and then 'make'.

### Creating a new Makefile ###

We have seen a number of ways to improve the provided pizza Makefile.  We'll put them together into a single, well-formed, Makefile.  Below are the steps to do so; each of these steps are described in more detail above.

- Comments!  This Makefile will be submitted as part of [lab 5](../../labs/lab05/index.html) (see below), so you will need to put in your name and userid at the top of the file.
- We will want to declare the pre-defined macros, CXX and CXXFLAGS.  CXX is going to be clang++, and we can define CXXFLAGS to be `-Wall -O2` (give all warnings and optimize the code).
- We'll want to define a macro, probably called OFILES, that will list all of the .o files that we are compiling into our target executable.
- A suffix rule that will tell make to compile all .o files from the corresponding .cpp files.
- Our first rule -- probably called 'pizza' -- will be for compiling the program.  It will depend on all of the .o files (defined in the OFILES macro), and will define how to compile the program executable.
- Our second rule we'll call 'clean', and it will remove the executable itself, all the .o files, and all files that end in the tilde (i.e., *~, the backup files that Emacs creates).
- Lastly, we will need to have clang++ create all the dependency lines, which we will copy-and-paste into the bottom of the Makefile.

Test out the Makefile to make sure it works.  You will need to rename it to Makefile-pizza, and submit it as part of pre-lab 5 (we can't name it 'Makefile', as you are submitting a Makefile for the post-lab already).  Note that if the Makefile is not actually called 'Makefile', you can tell make to use a different one by specifying, 'make -f Makefile.foo'.  To specify a different target, the target name goes after the file name: 'make -f Makefile.foo clean'. 

### Further information ###

For more information, consult the man page for make and/or go to the [GNU website for make](http://www.gnu.org/software/make/manual/).  Google searches will also turn up lots of good resources.
