PDR: Docs: LLDB Command Summary
==============================

[Go up to the main documents page](index.html) ([md](index.md))

Assembly-specific commands

- `stepi`: step one MACHINE instruction (i.e. assembly instruction), instead of one C++ instruction (which is what `step` does)
- `registers read`: display the values in the registers
- `settings set target.x86-disassembly-flavor intel`: set the assembly output format to what we are used to in class (and what we are programming in)
- `disassemble`: like list, but displays the lines of assembly code currently being executed.
- `disassemble --name (function)`: prints the assembly code for the supplied function (up until the next label)

Program execution

- `run`: starts a program execution, and continues until it exits, crashes, or hits a breakpoint
- `bt`: prints a back trace, which is the list of function calls that got to the current point
- `f`: shows the lines of source code before and after the point at which the program paused
- `list (function)`: prints the lines of code around (function) or the current breakpoint otherwise if no (function) is provided.
- `up`: move up the back trace function stack list
- `down`: move down the back trace function stack list
- `step` (or just `s`): step INTO the next line of code to execute
- `next` (or just `n`): step OVER the next line of code to execute
- `continue` (or just `c`): continue execution
- `finish`: finishes executing the current function and then pauses
- `quit`: exits the debugger

Breakpoints

- `b (pos)` (or `break (pos)`): set a breakpoint at (pos).  A breakpoint can be a function name (e.g., `b GetMax`), a line number (e.g., `b 22`), or either of the above preceded by a file name (e.g., `b lab2.cpp:22` or `b lab2.cpp:GetMax`)
- `tbreak (pos)`: set a temporary breakpoint (only breaks the first time)
- `breakpoint list`: show breakpoints
- `breakpoint delete` (or just `br del`): deletes all breakpoints
- `breakpoint delete (num)`: delete the breakpoint indicated by (num)

Examining data

- `print (var)` (or `p`): print the value in the given variable
- `print &(var)`: print the address that the given variable is located
- `print *(ptr)`: print the destination of a pointer
- `x/(format) (var/address)`: format controls how the memory should be displayed, and consists of (up to) 3 components: a numeric count of how many elements to display; a single-character format, indicating how to interpret and display each element -- e.g. a few of the flags are `x/x` displays in hex, `x/d` displays in signed decimals, `x/c` displays in characters, `x/i` displays in instructions, and `x/s` displays in C strings; and a single-character size, indicating the size of each element to display -- e.g. b, h, w, and g, for one-, two-, four-, and eight-byte blocks, respectively. You can have multiple at a time, e.g. `x/30x (var/address)` will display 30 elements in hexidecimal from the provided `var/address` OR if no `var/address` is provided, from the top of the stack.
- `frame variable`: display all the args and the local variables and their values for their current frame
- `display (var)`: always display the value in (var) whenever the program pauses
- `display`: show the variables that have been entered with `display` and their numeric IDs
- `undisplay (num)`: stop displaying the variable with numeric ID num
- `print function_call(params)`: execute the function, and print the result
- `expr (var) = (value)`: set the variable (var) to the value (value) -- e.g. `expr foo = 5`
