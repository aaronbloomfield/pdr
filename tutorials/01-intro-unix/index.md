PDR: Tutorial 1: Introduction to UNIX
=====================================

[Go up to the Tutorials table of contents page](../index.html)

Part I: Introduction and setting up your UNIX environment
---------------------------------------------------------

This tutorial is meant to get you up and running with editing, compiling, and executing a program in a Unix-like environment.  There are a number of options that you can use to do this, depending on if you have your own PC, and how much time you want to spend installing software.  We recommend the first of the options listed if you are using Windows; Mac OS X users should use the second option listed.

The options are:

- Use VirtualBox, a free virtual machine software package.  This will allow you to run Linux on your home machine without needing to re-install anything.  Directions for setting up and how to use VirtualBox can be found at [Tutorial 1: Introduction to UNIX: VirtualBox use](virtual-box.html)
- Mac OS X users are already running UNIX, as Mac OS X runs on top of FreeBSD (a version of UNIX).  So you can just use the computer you have.  HOWEVER, note that you still can't use an IDE (Eclipse, Xcode, etc.).  You can download Emacs (an editor) from [here](http://emacsformacosx.com/).  From a terminal window, try typing in `clang++` - if you get "Command not found", you will need to install Xcode from the App Store, and then install the Command Line Tools (under Preferences - Downloads).  In newer versions of OS X, after typing `clang++`, a popup should appear asking if you would like to install command line developer tools.  Also note that you cannot load up Emacs easily from a command line, but you can load it up as you would any other application.
    - You will need to install Xcode and the command line tools (with the latest version of Xcode, you have to download and install the command-line tools separately)
    - Note that some software that you will need for this course (in particular, doxygen and x86 code creation) does NOT work well on a Mac, and you will likely need the VirtualBox image for that
- Install a Unix variant on your home machine.  There are a number of options: Linux, FreeBSD, Solaris, etc.  We use Linux (specifically, the Ubuntu distribution), as it has a large user community, both at the University and outside.  Thus, if you run into a problem, the course staff might be able to help you.  This will require repartitioning your hard drive, and thus there is a chance of data loss.  **THUS YOU NEED TO BACK UP YOUR DATA FIRST!!!** You will have to choose a distribution of Linux to install -- as mentioned above, we use Ubuntu.  You can find install guides on the web.  Be sure to install the development environments with Linux -- pretty much all of the required software will be included in that.  Also consider [Wubi](http://wubi-installer.org/), an easy-to use installer for Windows (while we have not used it ourselves, we have heard good reports about it from previous students).

Should you not want to install anything on your machine, or you want to work elsewhere, there are other options available to you as well:

- Complete this lab in any ITC lab -- oh, wait.  They got rid of them because undergraduate education is too expensive.  Idiotic decision...
- Complete this lab in Olsson 001 using Linux.  You will need to speak to me to get a key (and it will require a $5 deposit).  Note that while you can generally use the lab at any time, you are not allowed to be in the room when another lab is going on.  The lab machines already have both Linux and Windows installed, although you will have to reboot the computer into Linux (see below).

----

Part II: A (brief!) Unix tutorial
---------------------------------

Unix is a very powerful operating system that has been around, in one form or another, for almost 40 years.  The fact that it still exists attests to how powerful it can be for completing tasks on a computer.  The reason it is not more widely adopted is because it is not very easy to use or intuitive -- it was written by computer programmers for computer programmers.  While the people in this course are certainly capable of learning it, many people just want a computer to work, and to run an Office suite and a set of Internet programs such as a browser.  For those users, an easier to use operating system (such as Windows or Mac OS X) is often better.  Unix is coming more into the mainstream lately with the increased popularity of Linux, as well as the fact that Mac OS X is built upon a Unix operating system (FreeBSD, in particular).

The word "Unix" can mean any Unix-like operating system.  There are many available -- Linux, FreeBSD, Solaris, Mac OSX, etc.  We will be using the word Unix in this class to mean whichever Unix-like environment we are using for this course.

A quick note: Unix IS CASE SENSITIVE.  Thus, foo, Foo, FOO, and FoO are all different, and allowable, file names.  This causes problems with Windows, which sees all those names as the same thing.  So be careful about your cases!

### Connecting to Unix ###

First, you need to load up a command shell.  For those who have used DOS, or the Windows command prompt, it is a somewhat similar interface.

**A Unix system installed on your home machine, including VirtualBox:** In Linux (or FreeBSD, Solaris, etc.): Log in (presumably to the X-Windows interface), and load up a command shell.  How you load that up is dependent on your version of Linux.  With VirtualBox, it's one of the icons on the top toolbar.

**A Linux machine in Olsson 001:** You will need to reboot the computer into Linux -- see the directions in the first lab for how to do this.


### The Unix Tutorial ###

Here is a quick primer of basic Unix commands.  Try each of these out.  The idea is for you to be able to manipulate files and directories -- the full Unix tutorial starts next week.

- `ls` will show the contents of the current directory (similar to `dir` in DOS).  'ls' stands for 'list', but without the 'i' and the 't'.
- `pwd` (for print working directory) shows the current directory.  If you enter it now, it will print something like '/home/Yourname'.  Like Windows Explorer, you are always in a given directory at any given time -- if you modify files or create directories, for example, it will occur in the current working directory.  The current directory ('/home/Yourname') is called your home directory.
- `cd foo` will change to the foo directory -- in other words, it changes the current working directory.  As there are no directories in '/home/Yourname', you can enter `cd ..` (notice the one space and then two periods) -- this will move you up one directory (to '/home').  Also, you can enter `cd -` to jump to the previous directory you were in (the Ctrl-Z of directory hopping).
- If you didn't already, change to the directory above your home directory (by entering `cd ..`).  If you do an `ls`, you will probably see only one entry: 'Yourname'.  Move up one more directory (`cd ..`), and do an `ls` -- there should be a dozen or so directory entries.  At this point, it's hard to see what is a directory and what is not -- you can do an `ls -F`, which will put a single character after most files to let you know what they are -- for example, 'home/' shows up, and the slash tells you that 'home' is a directory.
- To get back to your home directory, just enter `cd`.  The current working directory is changed to your home directory.
- You can make directories by `mkdir` (note that 'md' will not work), and remove them by `rmdir` (not 'rd').  This is the same as creating a folder in Windows Explorer.  A directory that is not empty cannot be removed.  For now, we recommend that any directory names (or file names) only have letters, digits, or the underscore in their names (there are ways around that, but they are complicated).
- Once we start saving files, we will want them to be somewhere easily accessible from Windows.  With VirtualBox, the [Tutorial 1\: Introduction to UNIX\: VirtualBox use] page discusses how to transfer files back and forth to the virtual machine.

That's it for the Unix tutorial for now.  There are many further tutorials online, feel free to read those.  You can do all your editing in your desktop folder -- this way, if you want to rename or move your files, you can use Windows Explorer to do so (there are Unix ways to do it, and we'll get to those later).


----

Part III: Editing, compiling, and running a C++ program
-------------------------------------------------------

First, you will need to load up a command shell (as in the previous section), from which we will load up the editor.  We will be using a version of Emacs for this course.

For this course, you will need to be familiar with Emacs.  You are welcome to use any editor that is not an IDE (Integrated Development Environment), but I will expect that you are very familiar with Emacs, or optionally Vim, for the exams.  This includes the keyboard shortcuts!

To load up the editor:

- In Linux (via VirtualBox, or in FreeBSD, Solaris, etc.): Log in (presumably to the X-Windows interface), and load up `emacs`.  How you load that up is dependent on your version of Linux -- the easy way is to load up a command shell, or *terminal*, (which you will need anyway), and enter `emacs &` (note the ampersand ('&') at the end, this tells the command shell to start the `emacs` process in the background, which means you can continue to use the command shell and do not have to wait until emacs is closed). To use emacs within your command shell, enter `emacs -nw` (note the `-nw` means no-window, and also note we don't put an `&` here).
- Through SecureCRT to the departmental machines: log in as above.  A few notes: when you load up the editor, enter `emacs helloworld.cpp` -- note that you are not loading the GUI (as this is a text-based terminal you are using), and you are not using an ampersand (`&`).  When you have to switch back to using the shell, you will need to exit Emacs (`C-x C-c` -- see below), run the command, and then re-start Emacs.

You should now have emacs loaded and running -- if not, then something is wrong.  If you are using the VirtualBox image, it will look like the following.  Other systems will look similar.

![Emacs screenshot](screenshot-1.png)

All of the mouse commands in Emacs have keyboard shortcuts.  Eventually, you will want to learn the shortcuts, as they are much faster to enter once they are known.  For the commands below, the keyboard shortcut commands are listed -- partly so you can get used to seeing and using them, and partly because for those using SecureCRT, they cannot use the mouse.

The first commands in Emacs that we will learn will use the control key.  For example, the exit command (to leave emacs) is listed as `C-x C-c`.  This means hit Control-x then Control-c.  We will be going over Emacs command in more detail later.  For now, remember that if you get stuck, hit `C-g` (Control-g) a few times, and that should un-stick it.

We recommend you create a new directory in your desktop for the rest of this tutorial (`mkdir tutorial`).  Either way, `cd` into that directory.

Next, let's open up a new file.  Do do that, go to File->Open (`C-x C-f`).  Enter the name of the file (`helloworld.cpp`).  Note that if the file does not exist, then it is created (thus, it is like File->New in other programs).  If the file does exist, it is opened (like File->Open in other programs).  Also note that in the lower part of the Emacs screen, it should now say "C++ Abbrev" -- this is the mode that Emacs is in.  The "C++ Abbrev" means that it is in C++ mode, which is what we want.

Enter the following program -- feel free to cut-and-paste (there is a 'Edit->Paste' menu entry).  This is the same program found in the first set of slides.  What all this C++ code means, we'll get to later -- this tutorial is just for entering, compiling, and running the programs.

```C++
// C++
#include <iostream>
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

Save the file (File->Save or `C-x C-s`).  If you switch back to the shell, and do an `ls`, you should see that file listed.

Next, we need to compile that file.  To do so, switch to the shell, and enter the command: `clang++ helloworld.cpp`.  It will compile, and if successful, the command prompt will be displayed after a brief pause.  If there were errors, then the it will list them to the screen.

After a successful compilation, do an `ls` -- you will see a second file, called `a.exe` (`a.out` if you are using Linux, OS X, or one of the lava machines).  This is the compiled version of that program.  To run it, enter `./a.exe` (or `./a.out`).  Note the period and slash before the `a.exe` -- why this is there (and how to get rid of it) we will see later in the semester.

Another useful command is the undo command: `C-_`.  This means hold down the control and shift keys, and hit the dash/underscore key.

Right now your Emacs should look approximately like this (with the helloworld.cpp file loaded):

![Emacs screenshot](emacs-screenshot-new.png)

The following is useful for older versions of Emacs. Read over it and familiarize yourself with it, specifically the meta-commands, but note that if you see text coloring and line-numbers, you are good to go.

There are two more Emacs commands that will be very useful as we continue in the course.  The Emacs editor is very powerful, but you would never know it by looking at the code that you just entered.  It really just looks like Notepad right now:

![Emacs screenshot](screenshot-2.png)

Let's color the text and turn on line numbers -- both very useful things to have when you are editing code.  We've seen control commands (such as `C-x C-s` for saving a file).  Next up are commands called meta-commands, because they use the meta (or escape) key.  A meta-command looks like `M-x line-number-mode`.  Thus, to enter the command, hit the escape key, RELEASE THE ESCAPE KEY, and hit `x`.  Note that with the control commands, you hold down the control key while pressing the other key -- with meta commands, you press and then release the escape key, and then hit `x`.  At that point, the bottom of your Emacs screen will look like the following:

![Emacs screenshot](screenshot-3.png)
 
Note the `M-x` at the bottom -- Emacs is ready to receive an 'extended' meta command.  Type in `line-number-mode`, hit Enter, and the line number that the cursor is on will appear in the status bar at the bottom of the Emacs screen.  Note that it is going to be annoying to have to type all of that in each time.  This, if you hit the tab key after entering `line`, it will complete the rest of the command for you.  While this may seem like a lot of typing, once you get used to it, these commands can be entered significantly faster than the mouse clicks needed to do this in other editors.  There are ways you can have line numbers always displayed when you enter Emacs -- we'll get to these later in the semester.  Note that you can enter `M-x line-number-mode` as many times as you want -- it will just toggle the display of the line numbers on and off.

The other command that is useful is to color the program text.  Use the command `M-x font-lock-mode`.  Note that if you hit the tab key after entering `font`, it doesn't fully complete it (you still have to enter 'mode').  Your C++ program should now be colored, and your Emacs window should look like the following.
 
![Emacs screenshot](screenshot-4.png)

In addition to the font coloring of the C++ program code, note that the word 'Font' is between 'C++' and 'Abbrev' on the status bar (as we are now using font colors), and the line number is shown to the right of that (the cursor is on line 1 in the image).

##Summary

In summary, you should be familiar with the following Emacs commands:

- `C-x C-f`: Open a file, or create a new file if the file name is not found
- `C-x C-c`: Exit Emacs (prompts to save the file if it is not saved)
- `C-g`: Quit (stops the current command, doesn't exit Emacs)
- `C-_`: Undo
- `M-x line-number-mode`: Turn on line numbers
- `M-x font-lock-mode`: Turn on font coloring

A good Emacs reference sheet can be found [here](http://www.gnu.org/software/emacs/refcards/pdf/refcard.pdf).  This file is also in the Collab Resources section, under the misc folder.  Note that this page is formatted for A4 paper -- it should print out fine on our letter-sized paper, but you may have to scale the image in Acrobat Reader when you print it out.

When you are all finished, you should exit Emacs (`C-x C-c`), and logout (by typing `logout`).

That's it!  You can now edit, compile, and run C++ programs.  You are ready to proceed to the pre-lab for lab 1.
