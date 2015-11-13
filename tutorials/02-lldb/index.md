PDR: LLDB Tutorial
==================

[Go up to the Tutorials table of contents page](../index.html)

This tutorial is meant to get you used to using the LLVM debugger,
lldb.  As you read through the first part of the tutorial, you are not
expected to remember everything -- there is a reference list at the
end of this tutorial, and is also contained on the
[LLDB command summary](../../docs/lldb_summary.html) page.  This
tutorial will guide you through the process of using those commands.

Some terminology:

- `lldb` is a command-line debugger (we may see graphical debuggers
  later in the semester.)
- "LLVM" is the compiler framework that includes many things,
  including the `clang` compiler that we are using, as well as `lldb`
- `gdb` is the debugger that was used in the past, and is often used
  elsewhere -- it is analgous to `lldb` in how it works

------------------------------------------------------------

Part I: LLDB Tutorial
--------------------

### What is a Debugger? ###

A debugger is a utility program that allows you to run a program under
development while controlling its execution and examining the internal
values of variables.  We think of a program running "inside" a
debugger.  The debugger allows us to control the execution of the
program by pausing its execution and then resuming it.  While paused,
we can find out where we are in the program, what values variables
have, reset the values of variables, etc.  If a program crashes, the
debugger can tell you exactly *where* the program crashsed (something
that Java does naturally, but C++ does not).  The principles and
commands described in this document are specific to the lldb debuggers
for clang++ under UNIX, but every debugger has similar commands.

All computer scientists should learn the basics of debugging and how
to use a debugger.  It will save you literally hours of time when
finding and fixing problems in your programs.  The few minutes of
investment you put into learning how to use a debugger will pay off
tremendously in a matter of weeks.  Work smart!

### Sample Program ###

Consider the following buggy program into [prog1.cpp](prog1.cpp.html)
([src](prog1.cpp)):

```
#include <iostream>
using namespace std;

void my_subroutine() {
    cout << "Hello world" << endl;
}

int main() {
    int x = 4;
    int *p = NULL;
    my_subroutine();
    *p = 3;
    cout << x << ", " << *p << endl;
    return 0;
}
```

This program will throw a segmentation fault every time (as we are
trying to dereference a `NULL` pointer), but that's fine for what we
want to do here.

### Compiling for Debugging ###

Programs normally have to be compiled with a special option to allow
debugging to take place.  On UNIX, the option for clang++ is the `-g`
option.  For example:

```
clang++ -Wall -g -o prog1 prog1.cpp 
```

We also include the `-Wall` option, which lists warnings (the 'all' is
to list all warnings).  Note that this option leads to executable
files that are larger and slower, so you may not want to use it for
final distributions or time-critical programs.  But you can always
remove the debugging information from an executable without
recompiling it with the `strip` command.  For more information on
that, see the man page for `strip` (i.e., run `man strip` from the
command line).

The `-g` option causes the compiler to include information about the
source file (the .cpp file) that is needed for debugging as part of
the executable file.  This causes the executable to be larger in size,
and slightly slower, but allows for debugging.  So when you run the
debugger, you specify the executable file (not the source file) as the
input to the debugger.

### How to Start Using lldb on our UNIX Systems ###

The LLVM C++ compiler, clang, has an accompanying debugger: lldb.  To
run the command-line version, compile your program as described above,
and then type:

```
lldb prog1
```

Note that some systems may have the debugger have a slightly different
name:

```
lldb-3.4 prog1
```

This was assuming your executable (created with clang's `-o` option)
was "prog1".  If you didn't use the -o option, then you'll type:

```
lldb a.out
```

The following sections describe the important types of things you can
do with lldb, organized by "category" of activity.  These activities
and operations will have been implemented in other debuggers you may
have used, such as the debuggers that come with various IDEs.

### Executing your Program ###

Once in lldb, use the `run` command to start your program running.  It
will run until it completes, until it crashes, or until it reaches a
breakpoint that you set (more on this later) -- and it will pause for
input, of course.  Once it finishes, you're still in lldb, so you can
run it again from the beginning.

If your program requires command-line arguments, you can give them
after the run command.  If you would normally run the program on the
command line by entering:

```
prog1 100 test1.dat
```

In the debugger, you would enter: 

```
run 100 test1.dat
```

Note, however, that the prog1 that we are editing here does not need
any comand line parameters.

### Where Am I? Where Did It Crash? ###

Under UNIX, one of the most frustrating things about running C or C++
programs is that they normally give little useful information when
they crash -- usually they just say, 'segmentation fault'.  Part of
the reason is that by default the executable file doesn't include
information about the source code that is needed to print an error
message (like the line number).

But when you run a program inside a debugger, you can easily see what
the current line is when a program crashes.  Type `f` to see the
current and surrounding lines.

More usefully, you can see a list of the function calls that led you
to this point in your program.  Your program may have died deep inside
a function that is called many times in your program, and you need to
know which sequence of nested functions calls led to the failure.  In
the command-line mode, type `backtrace` or `bt` to show this list.
IMPORTANT: this command is one of the most important and useful
debugging commands you'll see in this lesson!

While we're talking about reaching a point in a sequence of nested
function calls, sometimes in lldb you will need to understand the
concept of frames.  When a program stops, you can examine local
variables, view lines of code, etc.  that are local to that function.
If you need to move up to the function that called this one, you need
to move up to the higher frame using the `up` command to debug there.
The `down` command moves you back down a frame towards where you
started.  The up and down commands let you move up and down the
calling stack (of nested function calls) so you can issue debug
commands about the function that's "active" at each level.

### Making your Program Pause: Breakpoints ###

One of the most fundamental things you want to do while debugging is
make the program pause at a particular line or at the start of a
function.  These locations in a program where execution pauses are
called "breakpoints."  IMPORTANT: You must choose a line of code that
actually executes something: not a comment, for example.

In lldb you can set breakpoints by typing either `break` or `b`
followed by information on where you want the program to pause.  After
the `b` command, you can put either:

- a function name (e.g., `b my_subroutine`)
- a line number (e.g., `b 12`)
- either of the above preceded by a file name (e.g., `b prog1.cpp:12`
  or `b prog1.cpp:my_subroutine`)

Here, the `my_subroutine()` function doesn't start on line 12 (it
starts on line 4) -- the breakpoint on line 12 is for the `NULL`
pointer dereference in the `main()` function.  We could have also set
a breakpoint at the beginning on the my_subroutine() function by
calling `b 4`.

At any time you can see information about all the breakpoints that
have been defined by entering `breakpoint list` (or `br list`).  You
can remove a breakpoint using the `breakpoint delete` command (or just
`br del`).  You can delete all breakpoints (`br del`) or a specific
one (`br del 1` or `br del my_subroutine`).

Breakpoints stick around until you delete them.  This is handy if you
put a breakpoint inside a function that is called more than once or if
you put one inside a loop.  You can set a temporary breakpoint with
the `tbreak` command; the program pauses the first time, but after it
pauses there, that breakpoint is cleared.

An important thing to keep in mind with breakpoints is that if you set
a breakpoint for line 12, then the program will pause BEFORE executing
that line.

### Controlling Execution After a Breakpoint ###

After you make your program pause, you may want to execute it
line-by-line to see what it does next.  There are two commands that
make a program execute the next line and then pause again: `next` and
`step`.

The difference between these two is how they behave when the program
reaches a function call.  The `step` command steps into that function;
in other words, you see the debugging session move into the called
function.  The `next` command steps over that function call, and you
see the current line as the one after the function call.  Both are
useful, depending on what level of detail you need.

Sometimes after you've hit a break point and are doing line-by-line
execution, you want to resume normal execution until the next
breakpoint is reached (or the program completes).  The command to do
this is `continue`.  A useful variant on this is the `finish` command
which finishes executing the current function and then pauses.

You can use the abbreviations `s`, `n` and `c` for the common commands
described in this section.

### Displaying Variables and Expressions ###

Another thing you often want to do when the program pauses is to see
what value a variable or an expression has.  To do this, just type
`print` or `p` followed by the variable name or expression.  If the
variable or expression is a pointer or an address, you can print the
value that this address references using the `print *` command (i.e.
`print *foo`).  In addition, you can enter `frame variable` to see all
the arguments and local variables (and their values)
displayed.

It is often handy to have the debugger automatically display one or
more variable values at all times so you could watch how they
change. You do this with the `display <var>` command, and lldb will
display that variable's value each time the program execution hits a
breakpoint.  You can use 'display' more than once to show multiple
variables.

To see info on all variables chosen for display, just enter `display`.
To remove a variable from the automatic display list, use the
`undisplay` command followed by the display variable's numeric-id
(entering `display` shows the variables' numeric ids).

### Changing a Variable's Value ###

If you see that a variable has the wrong value, and you'd like to
change that value in mid-stream before continuing execution, you can
do this easily.  Enter `expr` followed by the type, then the variable,
an equals symbol (`=`), and the value or expression.  It's just like a
C++ assignment statement but without the semi-colon at the end.  For
example:

```
expr x = 5
```

The expression can be any C++ expression, including a function call.
So a statement like this is legal:

```
expr y = countNegValues(list, num)
```

Assuming you have a `countNegValues()` method defined, of course.
This would execute your function and then set the variable y to be
whatever your function returns.

Sometimes you want to actually execute a function "by hand" while the
program is stopped, even if this function isn't what would normally be
called at this point in the code.  You can do this using the `set`
command as shown above, or by making the function call the argument to
the print command.  For example, you could type:

```
print initQueue(&myQueue)
```

And the function would be called right now while the program is
paused.  This works even if the function returns void.

### Trying these commands out ###

Compile and run the prog1.cpp file shown above; this should segfault.
The problem is on line 12, when it tries to dereference the NULL
pointer.

Run it in LLDB with the program (`lldb prog`), and try the following:

- type `run`, and let it run to completion (really until it crashes)
- try the `bt` and `f` commands
- set up a break point at line 12, which is the line that is causing
  the crash
- type `run`, and confirm that you want to restart the program
- at the breakpoint, try printing out the value in p (`p p`); note
  that it is `NULL`
- set the `p` pointer, which is currently `NULL`, to point to a valud
  value (the `int` variable `x`): `expr p = &x`
- enter `c` to let it continue running, and it should finish without
  crashing this time

### A few final commands ###

If you find the problem while using the debugger, you may want to exit
lldb (by entering `quit`), recompile your source code, and restart
lldb.  Be sure to use the `-g` option when recompiling!

### Final Remarks ###

The best way to learn these commands is to try them out.  Even if you
don't use a debugger often, you should make sure you know the basics
of breakpoints, single-line execution, and printing a variable's
value.  These commands, along with the `backtrace` command, will be
enough for you to solve most of your problems.

Again, a programmer must know how to use a debugger just like an
accountant must know how to use a spreadsheet program or a calculator.
Your professors and your boss will expect it of you.  Remember this
before you go see your instructor about a run-time bug next time!  The
time you spend now to learn how to use a debugger will save you hours
in the future.

------------------------------------------------------------

Part II: LLDB Lab Exercise
-------------------------

### The Source Code ###

We will be using the [debug.cpp](debug.cpp.html) ([src](debug.cpp))
source code.  There are a few errors in the code, but don't fix them!
We'll use the debugger to find them.
 
### Running the Debugger ###

After you enter the code (remember: if you spot the errors do not
correct them -- we will use the debugger to find them!), compile the
code.  If you plan on using the debugger, you have to specifically
tell clang++ to include debugging information.  To do that, enter the
`-g` flag.  For example, enter:

```
clang++ -Wall -g -o lab2 debug.cpp
```

The `-g` flag will include debugging information.  The `-o lab2` flag
will cause the output executable to be `lab2`.  The `-Wall` flag is a
new one -- it will include all warnings about your code (errors are
still reported without the flag; this includes warnings as well).

There are no compiler or linker errors (or warnings!), so if you get
any you will need to find and fix them.  We should now be ready to go.

First just run the program, and enter the numbers 2, 4, 6, 8, and 10
-- we'll be using those five numbers throughout the debugging of the
program.  The first thing that you should see is that these are not
the numbers that the program displays back to you! What happened?
What's wrong?  Let's use the debugger to find out.

The first feature we will use is the ability to set a breakpoint.

### Setting up Breakpoints ###

Remember that a breakpoint is any point in the executable code where
the execution stops, allowing the programmer to see what is going on
inside the program as it runs.  Breakpoints allow you to run through
portions of the code where there are no problems, so that you can
spend your time focusing on the areas that need to be fixed.

To set up a breakpoint, you enter the 'break' command, and where you
want the breakpoint to be.  There are 3 ways to specify breakpoints,
by entering:

- a function name (e.g., `b GetAverage`)
- a line number (e.g., `b 23`)
- either of the above preceded by a file name (e.g., `b debug.cpp:23`
  or `b debug.cpp:GetAverage`)

If we knew where the problems were, we could skip over some lines, but
since we don't, put a breakpoint on the first line of the code, the
cout statement.  You probably want to set the breakpoint based on the
line number in the code -- you can use the Emacs command `M-x
line-number-mode` to have Emacs display line numbers.  Enter `break
x`, where x is the line of the first cout statement in the main()
method.  Now we need to run the program -- to do this, enter `run`.
Lldb should start running, then should pause and display approximately
the following:

```
(lldb) b 23
Breakpoint 1: where = a.out`main + 31 at debug.cpp:23, address = 0x0000000000400a0f
(lldb) run
Process 10943 launched: '/home/aaron/Dropbox/git/pdr/tutorials/02-gdb/a.out' (x86_64)
Process 10943 stopped
* thread #1: tid = 10943, 0x0000000000400a0f a.out`main + 31 at debug.cpp:23, name = 'a.out', stop reason = breakpoint 1.1
    frame #0: 0x0000000000400a0f a.out`main + 31 at debug.cpp:23
   20       int nCount;
   21  
   22       // Display a prompt:
-> 23       cout << "Enter five numbers: " << endl;
   24  
   25       // First we read in the numbers.
   26       for ( nCount = 0; nCount < MAX; nCount++ ) {
(lldb)
```

Lldb is stating that it hit a breakpoint, on line 23 of debug.cpp, and
displays the line of code.  There are a number of commands we can
enter at this point (try them all):

- `bt`: shows a list of the function calls that got us to this point
  (we are only in the main() method at this point, so it's not all
  that interesting)
- `list`: shows a listing of the source code where the breakpoint
  occurred
- `frame variable` shows the current variables, and their values.
  Note that the variables have not been initialized, so they have
  strange values!
- `p nCount` will print the current value in nCount
- `p nValues` shows all the values in the array nValues

### Examining Data ###

One of the most powerful features of the debugger is the ability to
look at the state of the variables as the program executes.  This way
the programmer can see if the variables are changing the way that they
are intended to change, and to see if the program is doing the things
that were intended.

The `frame variable` command will show all the local variables of the
current scope of execution.  Which variables are displayed will change
as the program executes, always showing the most recently defined
variables, values returned from functions, and changed or referenced
variables.  When our test program hits the breakpoint, two variables
are shown: nCount and nValues.  nCount will be some random integer
which reflects the contents of that memory location at the beginning
of the program.  The nValues variable looks different -- it's an
array, so the entire contents of the array are shown.

### Stepping through the Code ###

Lldb allows you to step through the code in two different ways.  You
can execute one line at a time, stepping into each function call, or
you can run the functions without tracing their execution.  We will
look at examples of both.

First, let's see what happens when we start the program.  You should
now be at the breakpoint from above -- if not, restart the program
(`run`) -- it will break at the breakpoint you entered before.
Entering `frame variable` shows that the nCount variable is filled
with a random number.  Let's step into the loop and see what happens.

First, we'll start by stepping OVER commands.

### Single Stepping through your code ###

Enter `n` (or `next`) -- this steps OVER the next command.  This
stepped over the `cout` command -- if we had entered `s`, it would
have started showing the execution of the cout function call, which is
not what we want.  Note after we entered the `n`, it showed the output
("Enter five numbers:") to the screen.  We were stopped BEFORE the
line executed, so by single stepping, we caused the computer to
execute that one line.  Nothing else has changed (`frame variable`,
`bt`, etc.  are the same), so let's press `n` again.

Now the cout statement inside the for loop is the current line.  Also
notice that now the nCount variable (via `frame variable` or `print
nCount`) has a value - it is zero, because that's where our for loop
begins.  Press `n` again.  The prompt for the next number is
displayed, since the cout statement has executed.  Step through
another line of code.

The code is now stopped on the `cin` statement.  You will need to
enter a value and press enter.

You should see these changes:

- The number you typed shows after the prompt.
- `frame variable` shows that the 2 was entered into the array at
  index 1 (not 0!)

Pressing `n` again will take us to the beginning of the loop; pressing
it again will increment the value of nCount in the watch windows.
Let's single step through another pass through the loop.  Step over
button twice more, entering successive values when prompted (2, 4, 6,
8, 10).  See what happens to the variables.

This shows you one of the errors - the data is all going into
nValues\[1\].  Go to the source window, and correct the line.  Exit
lldb (`quit`), recompile the program, and start up lldb again (`lldb
lab2`).  Set your breakpoint, run the code, and make sure that it is
getting the input correctly.  Try entering `display nValues` after the
first breakpoint -- it will always display the contents of the nValues
array each time the program pauses.

When you are satisfied that the input is working, you can `continue`
(or `c`), and the program will run until the next breakpoint, or the
end of the program.

There appears to be a couple more errors in the code.  Let's address
the problem with the average value.  To do this we'll need to use the
step into ability of the debugger.

Place a breakpoint on the line that the GetAverage() function is
called (the cout line in the main() method, not the GetAverage()
method itself).  Remove the breakpoint from the beginning of the
source code: `br del <line>`, where <line> is the line of code where
the breakpoint is at, or `br del 1`, where 1 is the breakpoint number.
You can see the list of breakpoints by entering `breakpoint list`.
Once you have only one breakpoint set up at line that GetAverage() is
called, run your code (`run`).  It will run normally (we'll enter the
same values: 2, 4, 6, 8, 10) until it hits the breakpoint.

Press the Step Into button (`s`).  Execution of the program now passes
to the first line of the function GetAverage().  Entering `bt` will
show the series of function calls that got us to this point.  We can
now use the step over command (`n`) to step through the function and
identify the errors.

A word of caution: using the step into command at the wrong time may
cause the debugger to load and display either assembly language or
unfamiliar code.  Don't worry; all you've done is stepped into the
code for a standard function or operator such as the insertion
operator.  To exit this code, enter `c` for continue (which will
continue execution until the next breakpoint), or `finish`, which will
execute until the current function ends.

Does the printing of the maximum value work?  If so, great!  If not,
you get to figure that one out on your own...

### Explore on your own ###

There are still a few errors; try tracing through the function and see
what you can fix!  Remember that there are a few different types of
breakpoints.  Rather than entering the line number, you can enter a
breakpoint by specifying the function call -- for example, you can
enter 'break GetAverage' to debug the GetAverage function, rather than
trying to figure out which line the function starts on.

### Finishing up ###

When you are finished debugging the code with lldb -- and it works
correctly -- you should submit the debug.cpp file to inlab2.  Remember
to put your identifying information at the top.

------------------------------------------------------------

Part III: Summary of lldb commands
---------------------------------

These commands are listed on the
[LLDB command summary](../../docs/lldb_summary.html) page.

You can see a difference between the comamnds of lldb and gdb on the
[GDB vs LLDB commands](../../docs/gdb_vs_lldb.html) page.
