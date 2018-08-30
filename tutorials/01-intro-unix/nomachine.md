PDR: Tutorial 1: NoMachine Usage
================================

[Go up to the Tutorials table of contents page](../index.html)

This tutorial will help you set up and start using NoMachine.

### Installing NoMachine and Connecting ###

NoMachine is basically just a [remote desktop](https://en.wikipedia.org/wiki/Remote_desktop_software) client, but one that the CS department at UVa has configured for your use.

The first step is to download and install the client -- you can download it for free at [https://www.nomachine.com/](https://www.nomachine.com/).  They have the client on numerous operating systems.  You are on your own for the installation.

You will need an account to log in to -- one will be provided for you by the course.  Make note of the password; the userid is just your UVa userid.

When you load up the NoMachine client, you will want to connect to nx.cs.virginia.edu.  It will ask you to confirm the authenticity of the host, and provide the SHA256 hash of 2D B9 74 B2 5C 7A 92 6F DD FD 98 2E 0D 35 A1 E5 99 8A A8 5B 81 A7 41 16 8F 46 0F 03 9E 3F 7F B1 -- as long as that hash matches, you are fine.  Enter your username and password.  It will require you to change your password when you first log in.

You will likely want to clone the PDR repo into your account, as discussed in the in-lab part of [Lab 1: Introduction to C++](../../labs/lab01/index.html).  Note that you may want to work through [Tutorial 1: Introduction to Unix](index.html) before doing this.  Briefly, you enter `git clone https://github.com/uva-cs/pdr.git` only once, which will clone the repo in a `pdr` directory.  Each time you log in to do work, you will want to cd into that directory, and then enter `git pull`.

### Using NoMachine ###

Some other important usage notes:

- Be sure to run `git pull` in the `pdr/` directory every time you log in!
- To get the left-side menu, click on the 'Activities' text in the upper-left corner of the screen.
- The compiler we are using in this class is clang.  If you just type in `clang`, it will say, `bash: clang: command not found`.  To start using the compiler, you have to enter `module load clang-llvm`.  Then when you enter `clang` (or, even better, `clang --version` (there are two dashes there)), it will not report the command was not found.
    - You have to do this once on every login, not once per time you call clang.
- When you are done, you can log out through the down-arrow in the very upper-right hand side of the screen -- click on our username, then 'Log Out'.
- If you plan to use NoMachine *and* VirtualBox, you may want to use the GNOME interface on VirtualBox -- see part 2 of [Tutorial 1: Introduction to Unix](index.html) for details.
- If the screen saver kicks on, just kit the ESC key.
