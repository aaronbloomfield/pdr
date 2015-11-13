GDB vs LLDB
===========

[Go up to the main documents page](index.html) ([md](index.md))

Both gdb and lldb are excellent debuggers.  GDB is part of the GNU framework, and was created to work alongside of `g++`, which is the GNU C++ compiler.  LLDB is part of the LLVM framework, and was created to work alongside of `clang++`, which is the LLVM C++ compiler.

Ideally, you would use the debugger of the same framework that the compiler is part of.  However, a bug with LLVM prevents it from working inside a Ubuntu VirtualBox image (see [here](http://llvm.org/bugs/show_bug.cgi?id=20446) for the bug tracker about this issue).  Thus, we are going to use gdb instead of lldb, even though we will continue to use the clang++ compiler.

Both debuggers can debug code compiled by either compiler.  The only real differences, as far as this class is concerned, have to do with some of the commands.  There are other differences between the debuggers, but those differences are not commands that we will see in this course.  The full list of commands can be found on the [GDB command summary](gdb_summary.html) page and the [LLDB command summary](lldb_summary.html) page.

The majority of the commands are the same; this document only highlights the commands that are different between the two debuggers.  The categories listed below match those on the two specific debugger pages ([GDB command summary](gdb_summary.html) and [LLDB command summary](lldb_summary.html)).

----

Assembly-specific commands

- displaying the values in the registers: `info registers` for gdb, `registers read` for lldb
- set the assembly output format to what we are used to in class (and what we are programming in): `set disassembly-flavor intel` for gdb, `settings set target.x86-disassembly-flavor intel` for lldb
- prints the assembly code for the supplied function (up until the next label): `disassemble (function)` for gdb, `disassemble --name (function)` for lldb

Program execution

- starts a program execution, and breaks when it enters the main() function: `start` in gdb; there is no direct equivalent in lldb (but you can do it via two commands: `b main` and `run`)
- shows the lines of source code before and after the point at which the program paused: `list` in gdb, `f` in lldb

Breakpoints

- show breakpoints: `info break` in gdb, `breakpoint list` in lldb
- delete all breakpoints: `delete` (or just `d`) in gdb, `breakpoint delete` in lldb
- delete the breakpoint indicated by (num): `delete (num)` in gdb, `breakpoint delete (num)` in lldb

Examining data

- display all the local variables and their values: `info locals` in gdb, `frame variable` in lldb
- set the variable (var) to the value (value): `set variable (var) = (value)` in gdb, `expr (var) = (value)` in lldb
