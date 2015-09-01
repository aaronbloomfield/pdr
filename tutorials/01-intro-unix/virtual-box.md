PDR: Tutorial 1: Introduction to UNIX: VirtualBox Use
=====================================================

[Go up to the main tutorial 1 page](index.html)

VirtualBox is a free program that allows you to run another operating system on your machine without needing to reinstall anything.  You just have to install the VirtualBox client, which installs like any other program and is available for many different platforms (Windows, Mac, Linux).  We provide you with a pre-configured VirtualBox image that contains an Ubuntu Linux installation that you can use for this course.

### Quick start ###

- A bit of terminology: the 'host' machine is the physical computer (laptop, desktop, etc.) that you are using.  The 'guest' machine is the virtual machine that is running in VirtualBox, and is often just called the 'guest operating system'.
    - You are welcome to try this on a netbook host machine, but the computing power of a netbook may not be enough
- You will need to install the Virtual Box client.  It can be downloaded for free from [here](http://www.virtualbox.org/) and runs on most operating systems.
    - For the fall 2015 semester, you **MUST USE VIRTUALBOX VERSION 4.3** -- version 5.0 and above does not work properly
    - Under Linux, I installed the 'virtualbox-ose-qt' package (the name of yours might be different), but if you are running Linux already, you won't need to install a virtual machine running Linux...
- Download the provided VirtualBox image (from Collab, in the misc/ folder of the Resources tool).  You will need to unzip this file before using it.
    - This file is rather large (about 2 Gb), so you may want to try downloading it during off hours, such as late at night.  If you have problems downloading it, let us know.  If you do not have sufficient bandwidth to download it, please see us after lecture, and we will provide it on a different media for you.
	- Unzip this file; it will take up about 6.4 Gb on your machine.  Once uncompressed, you can download the .zip file that you downloaded.
        - Your unzip program may complain about needing some insane amount of space (like 700 petabytes, where a petabyte is 1,000 terabytes); this is a bug in many unzip programs.  Try [7-zip](http://www.7-zip.org/), which has had more success.
- Run VirtualBox, and import the image:
    - To do that, click on 'New', and choose the right OS/version ("Ubuntu (32 bit)" -- don't choose the 64 bit version!).  Give it a name to help differentiate it from other virtual machines that you may end up using in later classes.
    - Stay with the default memory amount (you can change it later)
    - At the 'Hard drive' screen select 'use an existing virtual hard drive file', and click the folder icon to the right of the drop-down list.  You want to use the file you unzipped above.
    - That should be it for the Wizard
- Boot the machine (click the Start icon at the top - it's a green rightward pointing arrow).  You may notice some display artifacts during boot-up as the virtual machine changes video modes, but that will stabilize once booting has completed.
- The login is 'student' (although you'll probably click on the 'L33t Hax0r' button on the login screen), and the password is 'password'.  You can click on the command-prompt icon on the bottom toolbar to get a terminal window.
    - The documentation is available online in either [HTML format](http://www.virtualbox.org/manual/UserManual.html) or [PDF format](http://download.virtualbox.org/virtualbox/UserManual.pdf), although most of the salient details are listed on this page.

### Notes ###

- No root password is set (you can use `sudo` instead); to change the root password, run `sudo passwd`.
- The 'host key' is defined by your host machine's operating system (it's the right control button under Linux, for example).  This key is used for a number of contexts, including un-capturing the mouse.  To have VirtualBox warn you about what the host key is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up.  It may also be listed in the lower-right of the VirtualBox window.
- We did not install the latest version of Ubuntu, but instead installed the Long-Term Support (LTS) version, which is 14.04.  The difference is that the LTS versions are supported for far longer (3 years or so) than the non-LTS versions (which are only supported for a year or so).  For this class, there won't be a noticable difference between 14.04 and more recent versions.
- Sound and network should work automatically, as the VirtualBox program will connect those to your host machine's sound and network device drivers.

### How-Tos ##
- To load a terminal (a.k.a. command prompt): it's towards the bottom of the menu on the left-hand launcher column.
- To load emacs: it's also in the menu on the left-hand launcher column, right above the terminal launcher icon
- To change the password: when logged in, you enter the 'passwd' command from a terminal window.  You should do this.  The original password is 'password'.
- To toggle between full-screen and windowed mode, click on the host key and 'f'.  Don't know what the host key is?  Read the bullet point about this in the 'Notes' section, above.
- To change the screen resolution: from the top menu bar, click on the circular power button icon on the far right, and select 'Displays'.  Note that there are not many resolutions available, but you can use full-screen mode which will change the resolution to your host machine's resolution.
- To set up printing: it's probably easiest to print to a PDF, transfer that file to your host machine (see below), and print from your host machine.
- Load up a file manager (like Windows Explorer): from the 'Places' menu (upper-left of the screen), select 'Home Folder'
- Make emacs show one screen (and not be a split-screen): press control-x then press '1' (this should not be necessary, by the way)


### Transferring files back and forth ###

The easiest solution may be the last one listed here, but read through these before you start on any of them.

One option is to set up an e-mail client (or use a web browser - Google Chrome is installed, and the icon is on the bottom menu bar) and e-mail your files back and forth.  Or use an online file server.

You can also set up 'shared folders' to directly read and write files back and forth.  To do so, see [here](http://www.ubuntugeek.com/how-to-access-windows-host-shared-folders-from-ubuntu-guest-in-virtualbox.html).

[Dropbox](http://dropbox.com) may be the easiest way to sync files between your virtual machine and your host machine.  To install, see the instructions toward the bottom of the [Virtual Box Image Creation Details](vb-image-details.html) ([md](vb-image-details.md)) page.

### Image creation details ###

[Here](vb-image-details.html) ([md](vb-image-details.md)) are the details of how the image was created.
