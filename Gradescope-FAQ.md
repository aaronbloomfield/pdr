## Why is my lab grade '-/10' even after the submission deadline?

We have set Gradescope to only display your grade **after we publish them**. This means that your grade will not be known for an assignment until the professors choose to release them. This is primarily so we can identify any grading issues and resolve them before releasing your grades.

## If I passed all the public test on Gradescope, will I get a 10/10?

No. There are many hidden test cases that are not shown to you until **after** we publish the scores.

## How many times can I submit my lab to Gradescope?

As many times as you like.

## I want to request a regrade, but the button is grayed out. What do I do?

Only submit a regrade request if you are absolutely certain that there is an issue on our end with grading. Regrades can be made through support requests under course tools on the collab page.

## My program is failing on Gradescope but works on my machine, why?

There are a lot of reasons this could be happening. The first thing you should check is if your main method is returning 0 or 1 at the end of the program. Non-zero return codes indicate that an error occurred in the executable, so if you're returning 1 in your main method, return 0 instead (you must return 0 if you want the autograder to work). 

If that wasn't the problem, then it could be a discrepancy between the compilers on your computer and on Gradescope. This occurs most often for Mac users, as Apple Clang is far more forgiving than the Linux Clang Gradescope uses. In these cases, the best option to identify the error is to use the VM provided to you for this class. We will always use Gradescope's results to grade your program, and this will typically not be a valid reason to request a regrade, as you can always use the VM to figure out what is wrong.

## How do I read the "diff" output on some of the Gradescope test cases?

When we run your program in some Gradescope tests, we save your output to a file and compare that with the expected output. We then use the `diff` command to print out the difference between your output and what's expected. [This](https://www.computerhope.com/unix/udiff.htm) webpage does a good job of explaining how to read the diff output. It takes some time to get the hang of, but it is the best way to quickly see where your output is incorrect.

## Is Gradescope sensitive to whitespace like spaces, tabs, newlines, etc.?

Gradescope is not sensitive to spaces or tabs, but is sensitive to newlines. So an extra newline in your output may cause a test case to fail, but an extra space will not. This means that sometimes your output will look exactly like what we expect, but all you need to do is either add or remove a newline to get the credit.

## Where to go if Gradescope fails to run my code?

If you see a message saying that the autograder failed to run or to contact course staff, just make a post on piazza so we can help you. Emailing or submitting support requests will not typically be responded to fast enough.

## Why do my programs keep getting timed out on Gradescope?

With the exception of a few labs, we set the timeouts to be much longer than necessary. If your program is timing out, you most likely have an infinite loop or are waiting for some input that you shouldn't be. If you're working on Lab 6 or some other time-critical lab, start optimizing your code.

## Why cant Gradescope find my Makefile or compile my code correctly?

Firstly, make sure your Makefile is called `Makefile` so the make command can properly run. Also make sure your compilation line doesn't rename your executable from a.out to something else. Unless we explicitly tell you to rename your executable, don't do it.