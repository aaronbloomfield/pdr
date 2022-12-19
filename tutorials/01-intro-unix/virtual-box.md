PDR: Tutorial 1: Introduction to UNIX: VirtualBox Use
=====================================================

[Go up to the main tutorial 1 page](index.html)

VirtualBox is a free program that allows you to run another operating system on your machine without needing to reinstall anything.  You just have to install the VirtualBox client, which installs like any other program and is available for many different platforms (Windows, macOS, Linux).  We provide you with a pre-configured VirtualBox image that contains an Ubuntu Linux installation that you can use for this course.

### Emulating 64-bit ###

When stepping through the steps below, you need to select 64-bit Linux/Ubuntu, and **NOT** 32-bit.  If the *only* options that appear at that step are 32-bit OSes, then you need to enable your computer to emulate 64-bit OSes.  Two of these things are done in the BIOS (hit delete, F1, or F10 when your computer starts).  Because everybody's BIOS is different, we cannot provide specific instructions as to which exact steps to take.  However, you need to enable the following two features in the BIOS:

1. Intel Virtualization Technology
2. VT-d

In addition, if you are using a Windows machine, you will need Hyper-V disabled in the "Turn Windows Features on and off" menu.  You can get to it by searching for that quoted text in the start menu.


### Quick start ###

- A bit of terminology: the 'host' machine is the physical computer (laptop, desktop, etc.) that you are using.  The 'guest' machine is the virtual machine that is running in VirtualBox, and is often just called the 'guest operating system'.
    - You are welcome to try this on a netbook host machine, but the computing power of a netbook may not be enough
- You will need to install the VirtualBox client.  It can be downloaded for free from [here](https://www.virtualbox.org/) and runs on most operating systems.
	- Under Linux, I installed the 'virtualbox-ose-qt' package (the name of yours might be different), but if you are running Linux already, you won't need to install a virtual machine running Linux...
- Download the provided VirtualBox image, the link to which is posted on the Collab workspace landing age.  You will need to unzip this file before using it.
    - This file to download is rather large (about 2.8 Gb), so you may want to try downloading it during off hours, such as late at night.  If you have problems downloading it, let us know.  If you do not have sufficient bandwidth to download it, please see us after lecture, and we will provide it on a different media for you.
	- Unzip this file; it will take up about 9.8 Gb on your machine.  Once uncompressed, you can delete the .zip file that you downloaded.
        - Your unzip program may complain about needing some insane amount of space (like 700 petabytes, where a petabyte is 1,000 terabytes); this is a bug in many unzip programs.  Try [7-zip](https://www.7-zip.org/), which has had more success.
- Run VirtualBox, and import the image:
    - To do that, click on 'New', and choose the right OS type/version ("Linux"/"Ubuntu (64 bit)" -- don't choose the 32 bit version!).  Give it a name to help differentiate it from other virtual machines that you may end up using in later classes.
    - Stay with the default memory amount (you can change it later).  You don't want to use less than 2048 Mb (2 Gb) -- it will not really be usable with less than that.  For a reasonable speed, you will want more -- 3072 Mb (3 Gb) or even 4096 (4 Gb), if your computer has it.  In any case, you probably shouldn't dedicate more than half of your host computer's memory to the VirtualBox image.  You can always change this later, as mentioned (right-click on the icon for the machine when VirtualBox starts up, and click on Settings).
    - At the 'Hard drive' screen select 'use an existing virtual hard drive file', and click the folder icon to the right of the drop-down list.  You want to use the file you unzipped above.
    - That should be it for the Wizard
- Boot the machine (click the Start icon at the top - it's a green rightward pointing arrow).  You may notice some display artifacts during boot-up as the virtual machine changes video modes, but that will stabilize once booting has completed.
- The login is 'student' (although you'll probably click on the 'L33t Hax0r' button on the login screen), and the password is 'password'.
    - The documentation is available online in either [HTML format](https://www.virtualbox.org/manual/UserManual.html) or [PDF format](https://download.virtualbox.org/virtualbox/UserManual.pdf), although most of the salient details are listed on this page.

### Notes ###

- No root password is set (you can use `sudo` instead); to change the root password, run `sudo passwd`.
- The 'host key' is defined by your host machine's operating system (it's the right control button on Windows, for example).  This key is used for a number of contexts, including un-capturing the mouse.  To have VirtualBox warn you about what the host key is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up.  It may also be listed in the lower-right of the VirtualBox window.
- We did not always install the latest version of Ubuntu, but instead usually prefer a Long-Term Support (LTS) version.  The difference is that the LTS versions are supported for far longer (3 years or so) than the non-LTS versions (which are only supported for a year or so).  For this class, there won't be a noticable difference between the LTS version and any newer versions of Ubuntu.
- Sound and network should work automatically, as the VirtualBox program will connect those to your host machine's sound and network device drivers.

### How-Tos ##
- To open a terminal: it's towards the bottom of the menu on the left-hand launcher column.
- To load emacs: it's also in the menu on the left-hand launcher column, right above the terminal launcher icon
- To change the password: when logged in, you enter the 'passwd' command from a terminal window.  You should do this.  The original password is 'password'.
- To toggle between full-screen and windowed mode, click on the host key and 'f'.  Don't know what the host key is?  Read the bullet point about this in the 'Notes' section, above.
- To change the screen resolution: from the top menu bar, click on the circular power button icon on the far right, and select 'Displays'.  Note that there are not many resolutions available, but you can use full-screen mode which will change the resolution to your host machine's resolution.
- To set up printing: it's probably easiest to print to a PDF, transfer that file to your host machine (see below), and print from your host machine.
- Load up a file manager (like Windows Explorer): from the 'Places' menu (upper-left of the screen), select 'Home Folder'
- Make emacs show one screen (and not be a split-screen): press control-x then press '1' (this should not be necessary, by the way)


### Transferring files back and forth ###

The easiest solution may be the last one listed here, but read through all of these before you start on any of them.

One option is to set up an e-mail client (or use a web browser - Google Chrome is installed, and the icon is on the bottom menu bar) and e-mail your files back and forth.  Or use an online file server.

You can also set up 'shared folders' to directly read and write files back and forth.  To do so, see [here](https://www.ubuntugeek.com/how-to-access-windows-host-shared-folders-from-ubuntu-guest-in-virtualbox.html).

[Dropbox](https://www.dropbox.com) may be the easiest way to sync files between your virtual machine and your host machine.  To install, see the instructions toward the bottom of the [Virtual Box Image Creation Details](vb-image-details.html) ([md](vb-image-details.md)) page.

### Image creation details ###

[Here](vb-image-details.html) ([md](vb-image-details.md)) are the
 details of how the image was created.  That page lists a number of
 installation options.  The only sections needed for this course are the
 [Basic Installation](vb-image-details.md#basic)
 ([html](vb-image-details.html#basic)), and the
 [Development Installation](vb-image-details.md#development)
 ([html](vb-image-details.html#development)).  The Development
 Installation has three sections, and only the first is needed for
 this course; however, the image has the other two sections configured
 as well (they are used for
 [another course](https://aaronbloomfield.github.io/slp)).  In addition,
 the Image Finalization part of the
 [Image Completion](vb-image-details.md#completion)
 ([html](vb-image-details.html#completion)) section was done on the
 image, although that is not necessary if one is installing this on
 their own machine.
