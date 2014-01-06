GDB command summary
===================

[Go up to the main documents page](index.html)

Assembly-specific commands

- stepi: step one MACHINE instruction (i.e. assembly instruction),
  instead of one C++ instruction (which is what 'step' does)
- info registers: display the values in the registers
- 'set disassembly-flavor intel': set the assembly output format to
  what we are used to in class (and what we are programming in)
- 'disassemble': like list, but displays the lines of assembly code
  currently being executed.
- 'disassemble (function)': prints the assembly code for the supplied
  function (up until the next label)

Program execution

- run: starts a program execution, and continues until it exits,
  crashes, or hits a breakpoint
- start: starts a program execution, and breaks when it enters the
  main() function
- bt: prints a back trace, which is the list of function calls that
  got to the current point
- list: shows the lines of source code before and after the point at
  which the program paused
- up: move up the back trace function stack list
- down: move down the back trace function stack list
- step (or just 's'): step INTO the next line of code to execute
- next (or just 'n'): step OVER the next line of code to execute
- continue (or just 'c'): continue execution
- finish: finishes executing the current function and then pauses
- quit: exits gdb

Breakpoints

- b (pos) (or break (pos)): set a breakpoint at (pos).  A breakpoint
  can be a function name (e.g., 'b GetMax'), a line number (e.g., 'b
  22'), or either of the above preceded by a file name (e.g., 'b
  lab2.cpp:22' or 'b lab2.cpp:GetMax')
- tbreak (pos): set a temporary breakpoint (only breaks the first
  time)
- info break: show breakpoints
- delete (or just 'd'): deletes all breakpoints
- delete (num): delete the breakpoint indicated by (num)
- clear (pos): clear a breakpoint, where (pos) is either a function
  name or line number

Examining data

- print (or 'p'): print the value in the given variable
- print \*: print the destination of a pointer
- examine (var): look at top of stack
- info locals: display all the local variables and their values
- display (var): always display the value in (var) whenever the
  program pauses
- display: show the variables that have been entered with 'display'
  and their numeric IDs
- undisplay (num): stop displaying the variable with numeric ID num
- print function_call(params): execute the function, and print the
  result
- set variable (var) = (value): set the variable (var) to the value
  (value)
