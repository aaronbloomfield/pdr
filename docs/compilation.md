PDR: Docs: Compilation Issues
=============================

[Go up to the main documents page](index.html) ([md](index.md))

This page is intended to help when your code does not compile.


Help!  My code doesn't compile!
-------------------------------

There are a number of things you can try:

- Fix the top-most error shown by the compiler, then re-compile.  Sometimes errors will have a cascading effect, hence why we fix the first one and re-compile.
- Check the section, below, on common compiler errors and how to solve them, as the error that you are looking for may be listed there
- Did you submit all the required files?  In particular, if some of the files that you `#include` are not present, then it won't compile.
- Filename case: Linux (what the compilation is done on) does care about the capitalization of file names.  So if your code has an `#include "FileName.cpp"` and your file is named filename.cpp, this will NOT compile under Linux.  Change your file name cases, or your `#include` line.
- Did you include the appropriate system `#include` lines?  If it is complaining that it can't find `exit()`, for example, be sure to `#include <stdlib.h>`.  Many compilers automatically include `<stdlib.h>` and `<stdio.h>`, which means you can directly call functions such as `printf()` and `exit()` without the appropriate `#include` line.  The compiler used by the submission system does not include, by default, any `#include` files.
- Did you enter `using namespace std;` at the top of each file?
- The submission system provides the compilation command - try running it on your machine.  In particular, try creating a NEW directory, copying into that directory the files that you are submitting (and ONLY those files), and then executing the compile command.
- If the compile command is `make` (you learn about make and Makefiles about 1/3 of the way through the course), then your Makefile needs to be configured to properly compile the code
- The output binary should NOT be specified by the `-o` compiler option.  This means it will produce a.out (on Linux and Mac OS X).  The system checks to see that the binary file was produced before it claims compilation success (and since the system is running on a Linux machine, it looks for a.out).

My code still doesn't compile!  What do I do now?
-------------------------------------------------

Here are a few additional things to try:

- See one of the course staff during office hours.  Please don't e-mail the code to us - we are not e-mail debuggers.
- Comment out the code until it compiles.  It is better to have it all commented out and compiling, as you may receive some partial credit when the graders look at the code.


Common compiler errors and how to solve them
--------------------------------------------

In the fall of 2013, we switched over to clang from g++.  Thus, the error messages that we had in this section are going to be different with clang.  If you run into something that you don't understand, please let us know!
