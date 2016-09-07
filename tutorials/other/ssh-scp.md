PDR: ssh and scp Tutorial
=========================

[Go up to the Tutorials table of contents page](../index.html)

Students often need reliable access to the
course lab servers in order to successfully complete the assembly language
(architecture dependent) assignments, as well as to easily synchronize work done on 
the lab computers (e.g. source code files) with personal laptops. This tutorial 
should--hopefully--make it simple to navigate the process of remotely logging
onto lab machines and copy files back and forth (via `ssh` and `scp`
respectively).

## What do ssh and scp mean, and when would I want to use them? ##

`ssh` is the [**s**ecure **sh**ell](https://en.wikipedia.org/wiki/Secure_Shell)
protocol, which will allow us to remotely login to the course lab machines (yes,
the same synchronized file system you have access to on any of the lab desktops during labs). `ssh`
provides a way for you to use your lab account's `bash` shell without needing to be present in the
room; you can work on assignments for PDR on the lab machines from anywhere.
No graphical applications/windows, including any usage of your mouse, are available via
`ssh` (well, X-11 forwarding is not enabled on our servers)-- so you will need to get comfortable with the keystrokes for `emacs`,
`vim`, [or whichever other editor you use](https://xkcd.com/378/) if you plan to do your work with this
protocol (the editor will open within the `bash` shell). While you're on an
`ssh` session, using `screen` or `tmux` to assist with more complicated screen-splitting 
maneuvers is a good resource. Learn more with `man screen` or `man tmux`.

`scp` is the [**s**ecure
**c**o**p**y](https://en.wikipedia.org/wiki/Secure_copy) protocol, which will
allow us to copy files back-and-forth between your local machine (e.g. laptop/VirtualBox course image) and the lab machines. How could this come in
handy? If you are working on an assignment for PDR via `ssh` on a lab server and are 
ready to [submit your
files](https://libra.cs.virginia.edu/~pedagogy/submit.php), you will need to first 
transfer them to your local machine and then upload them using the [course
tools page](https://libra.cs.virginia.edu/~pedagogy/index.php) on your web browser (we have no means for you to submit your work 
via `bash` at the time of writing this tutorial). Another reason why you may
want to use `scp` is to keep your work on the lab computers and your local
machine in sync -- you could, for instance, work on an assignment during Tuesday
lab, save your work, then retrieve your source code files remotely at a time
convenient to you. In addition, you could send any files you worked on from your laptop to the
server so that it is waiting for you on the lab desktops when you come in on
Tuesday.

There are Windows versions of `ssh` and `scp` as well; one set of these applications are called SecureCRT and SecureFX (UVa provides them for free in its Software Central).  [PuTTY](http://www.putty.org/) is a free and low-overhead ssh client for Windows.

**Lastly, if your VirtualBox image/macOS/WSL/native Linux environment
etc is *destroyed or unusable* by some means, using `ssh` and `scp` with the 
lab servers is an excellent alternative way to do your course assignments.**

## Using ssh to login to a lab server from your local machine ##

Open the `bash` terminal on your laptop (via either the course image in VirtualBox, macOS, WSL, native Linux
environment etc). Have your lab account password available (if you
did not change it from the default password, it should be in email sent to
*yourComputingID*@virginia.edu from root@virginia.edu).
Run the command `ssh yourComputingID@labunix01.cs.virginia.edu` (you may
substitute `01` with `02` or `03`, these will all work the same and are
synchronized, it does not matter which number you use). 
You will be prompted to enter your lab account password, and as
you enter it **you may notice that nothing appears to happen on the screen**; do
not worry, this
is how `bash` hides your password from being shown in plain text, rather than
using the "common" practice of printing `*`s for
each character you enter. When you are done entering the password, press enter
and you should see the prompt on your terminal change to something along the
lines of `yourComputingID@labunix01:~$`. Try running `ls` to ensure your files
from the lab desktops are all present, and go ahead and run `clang++` on one of your
`.cpp` files to see that you can successfully compile code while logged in (you
do not *need* to do this, but it's a good practice to ensure your environment works
as you expect it to). `w`
or `users` will show you who else is online...

You can use `emacs`, `vim` etc to work on your course assignments while logged on. To exit the `ssh` session, simply press `Ctrl+D` or run `logout`. You should be
returned to your local machine's `bash` terminal.

If you are having problems getting `ssh` to work for you, come speak to us
during office hours/with Piazza/submitting a support request! Whichever means
you deem appropriate.

## Using scp to copy files back-and-forth between your local machine and a lab server ##

**NOTE:** **Use `scp` *only on your local machine (e.g. laptop)* for all of your
file-transferring needs, to-and-from. `scp` is more
trouble than it's worth to try to use on the lab machines themselves, so do not
plan on using the commands listed here from a lab machine; if you know what you
are getting into, you are welcome to try to do that on your own (`sftp` or
`rsync` are the more
likely commands to look into for that scenario).**

Open the `bash` terminal on your laptop (via either the course image in VirtualBox, macOS, WSL, native Linux
environment etc). Have your lab account password available (if you
did not change it from the default password, it should be in email sent to
*yourComputingID*@virginia.edu from root@virginia.edu). 

Below are 4 scenarios which most students tend to use `scp` for (remember that
you can substitute `01` with `02` or `03` in specifying the lab server to use):

1\. Transferring a **single file** ***from*** the lab machine ***to*** your local machine 

Run the command
```
scp yourComputingID@labunix01.cs.virginia.edu:~/remote/path/to/file/ ~/local/path/to/destination/
```

Note the `:` that follows the remote machine address (and the lack of a `:` for
referring to your local machine's path). `~` means "my home directory on that
machine". If you just want the file to be put in your current local directory, `./` is 
the local path to use.


2\. Transferring a **single file** ***from*** your local machine ***to*** the lab machine

Run the command
```
scp ~/local/path/to/file/ yourComputingID@labunix01.cs.virginia.edu:~/remote/path/to/destination/
```

Yes, this is exactly the same as (1), except you have switched the
order of the arguments to `scp` (i.e. what was 'to' is now 'from' and what was 'from' is now 'to').
Note the `:` that follows the remote machine address (and the lack of a `:` for
referring to your local machine's path). `~` means "my home directory on that
machine". If you just want the file to be put in your remote machine's home
directory, `~/` is the remote path to use.

3\. Transferring an **entire directory or pattern** (incl. sub-directories)
***from*** the
lab machine ***to*** your local machine

Run the command
```
scp -r yourComputingID@labunix01.cs.virginia.edu:~/remote/path/to/directory/or/pattern/ ~/local/path/to/destination/directory/ 
```

Notice the `-r` flag: we are now able to **r**ecursively transfer files by
directory and/or regex pattern. So, `*.cpp`, `~/lab06/*`, `myCoolFile{0-3}.*` etc will now work over the
protocol. Note the `:` that follows the remote machine address (and the lack of a `:` for
referring to your local machine's path). `~` means "my home directory on that
machine". If you just want the files/directories to be put in your current local directory, `./` is 
the local path to use.


4\. Transferring an **entire directory or pattern** (incl. sub-directories)
***from*** your local machine ***to*** the lab machine

Run the command
```
scp -r ~/local/path/to/directory/or/pattern/ yourComputingID@labunix01.cs.virginia.edu:~/remote/path/to/destination/directory/
```

Yes, this is exactly the same as (3), except you have switched the
order of the arguments to `scp` (i.e. what was 'to' is now 'from' and what was 'from' is now 'to').
Notice the `-r` flag: we are now able to **r**ecursively transfer files by
directory and/or regex pattern. So, `*.cpp`, `~/lab06/*`, `myCoolFile{0-3}.*` etc will now work over the
protocol. Note the `:` that follows the remote machine address (and the lack of a `:` for
referring to your local machine's path). `~` means "my home directory on that
machine". If you just want the files/directories to be put in your remote machine's home
directory, `~/` is the remote path to use.

**For more complicated file moves, try `sftp` or `rsync`. Learn more with `man
sftp` or `man rsync`.**

## Still need assistance? Stuck somewhere? ##
Here are some good ways to get any help you may need:

* see [Luther Tychonievich's fall 2016 `ssh`/`scp` tutorial for CS 3330
students](https://www.cs.virginia.edu/~lat7h/3330/F2016/sshscp.html)
* attend office hours with questions
* post on the Piazza forum
* submit a support request
* [reference `man` pages](https://en.wikipedia.org/wiki/Man_page) (a manual on how to use a command you are trying to run)
* use a web browser + search engine to troubleshoot on your own (and then try the 
  above suggestions again if needed)
