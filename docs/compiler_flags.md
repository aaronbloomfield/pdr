PDR: Docs: Useful Compiler Flags
================================

[Go up to the main documents page](index.html) ([md](index.md))

This page is intended to summarize the various compiler flags that we will be learning throughout the semester.  There are hundreds (if not thousands!) of such options; we'll only be dealing with a few of them.

These flags are for the clang compiler, but the are mostly the same for the g++ compiler (the only difference, of the ones listed below, are the flags to generate the particualr assembly flavor).

- `-O2`: Creates an optimized executable.  Note that if you are using the -c command (below), then you should call -O2 for those as well as the final linker call.
- `-c <filename.cpp>`: This flag will compile BUT NOT LINK the passed .cpp file.  It will create a filename.o file.  To create the executable, you must call the compiler with all the .o files (i.e. `clang *.o`)
- `-o <filename>`: This will save the output executable into <filename>.exe (or, in Linux/Unix, just <filename>).  For example, `clang -o foo foo.cpp` will compile the foo.cpp file and name the executable 'foo'.  If you do out specify this flag, the output is saved to a.exe (or a.out in Linux/Unix).  The 'o' in `-o` stands for output (as in output file).
- `-g`: Include debugging information in the executable file.  This is needed to debug the file in gdb.
- `-Wall`: Display all warning messages.  An error will prevent the program from being compiled, whereas a warning will not.  There are many types of warnings that can be displayed, some of which are rather obscure.  The 'all' part means to display all of them.  It is a good idea to use this, as warnings are often bugs in your program.
- `-S`: generate assembly output, and then stop (i.e. does not compile the program beyond the x86 assembly).  Note that the assembly format that is created as a result of this flag has a different format than what we have seen in lecture -- the idea is the same, but the register specification is different, and the destination/source order is reversed for the commands.
- `-mllvm --x86-asm-syntax=intel`: sets the assembly output format to the flavor that we are used to in (this is the only flag on this list that is not the same in g++)
- `-MM`: generates dependencies in the format used in Makefiles

If you want to see all of the clang options, enter `man clang` at the Linux prompt.  It's quite a list!
