PDR: Tutorial 1: Introduction to UNIX: VirtualBox Use
=====================================================

[Go up to the main tutorial 1 page](index.html)

VirtualBox is a free program that allows you to run another operating system on your machine without needing to reinstall anything.  You just have to install the VirtualBox client, which installs like any other program and is available for many different platforms (Windows, Mac, Linux).  We provide you with a pre-configured VirtualBox image that contains an Ubuntu Linux installation that you can use for this course.

### Quick start ###

- A bit of terminology: the 'host' machine is the physical computer (laptop, desktop, etc.) that you are using.  The 'guest' machine is the virtual machine that is running in VirtualBox, and is often just called the 'guest operating system'.
  - You are welcome to try this on a netbook host machine, but the computing power of a netbook may not be enough
  - Your unzip program complains about needing some insane amount of space (like 700 petabytes, where a petabyte is 1,000 terabytes); this is a bug in many unzip programs.  Try [7-zip](http://www.7-zip.org/), which has had more success.
- You will need to install the Virtual Box client.  It can be downloaded for free from [here](http://www.virtualbox.org/) and runs on most operating systems.
   - Under Linux, I installed the 'virtualbox-ose-qt' package (the name of yours might be different), but if you are running Linux already, you won't need to install a virtual machine running Linux...
- Download the provided VirtualBox image (from Collab, in the misc/ folder of the Resources tool).  You will need to unzip this file before using it.
  - This file is rather large (over 2 Gb), so you may want to try downloading it during off hours, such as late at night.  If you have problems downloading it, let us know.  If you do not have sufficient bandwidth to download it, please see us after lecture, and we will provide it on a different media for you.
- Run VirtualBox, and import the image:
  - To do that, click on 'New', and choose the right OS/version (Linux/Ubuntu - don't choose "Ubuntu (64 bit)").  Give it a name to help differentiate it from other virtual machines that you may end up using in later classes.
  - Stay with the default memory amount (you can change it later)
  - At the 'Virtual Hard Disk' screen select 'use existing hard disk', and click the folder icon to the right of the drop-down list.  You want to use the file you unzipped above.
  - That should be it for the Wizard
- Boot the machine (click the Start icon at the top - it's a green rightward pointing arrow).  You may notice some display artifacts during boot-up as the virtual machine changes video modes, but that will stabilize once booting has completed.
- The login is 'student' (although you'll probably click on the 'L33t Hax0r' button on the login screen), and the password is 'password'.  You can click on the command-prompt icon on the top toolbar to get a terminal window.
  - The documentation is available online in either [HTML format](http://www.virtualbox.org/manual/UserManual.html) or [PDF format](http://download.virtualbox.org/virtualbox/UserManual.pdf), although most of the salient details are listed on this page.

### Notes ###

- No root password is set (you can use 'sudo' instead); to change the root password, run 'sudo passwd'.
- The 'host key' is defined by your host machine's operating system (it's the right control button under Linux, for example).  This key is used for a number of contexts, including un-capturing the mouse.  To have VirtualBox warn you about what the host key is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up.
- We did not install the latest version of Ubuntu, but instead installed the Long-Term Support (LTS) version, which is 12.04.  The difference is that the LTS versions are supported for far longer (3 years or so) than the non-LTS versions (which are only supported for a year or so).  For this class, there won't be a noticable difference between 12.04 and more recent versions.
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

The easiest solution may be the last one listed here, so read through these before you start on any of them.

One option is to set up an e-mail client (or use a web browser - firefox is installed, and the icon is on the top menu bar) and e-mail your files back and forth.  Or use an online file server.

You can also set up 'shared folders' to directly read and write files back and forth.  **HOWEVER** note that students who have tried this have had lots of difficulties doing so.  To do this:

- Find the VirtualBox toolbar at the bottom (this is not the Gnome toolbar at the bottom, but the toolbar that appears when you are **not** in full-screen mode).  Right-click on the icon that looks like a blue folder, and select 'shared folders'.
- Configure one (or more) shared folders.  You will need to select a name for the shared folder (I'll assume it's called 'home' for the commands below), and the directory that it reads from and writes to.
- This makes the folder available to the guest operating system, but does not automatically mount it.
- To do that, first create a directory that where you want to mount the shared folder, such as 'foo'.
- Enter the following command: 'sudo mount.vboxsf home foo' (this may require your password).
  - Many people choose to mount the shared folders in /mnt/.
- At this point, you can transfer files back and forth.
- Be careful not to accidentally delete all your files through the mount point!.

We have had various reports that this has not worked out so well (we have not had a chance to verify this yet), so proceed with caution!

VirtualBox also provides an Automounter, which sort of works.  This will mount the files into /media/ and appends a suffix of 'sf_' to your folder name. But then there will be permissioning issues; to fix those issues, you need to run: `sudo adduser student vboxsf`, followed by a logout and then a login.

[Dropbox](http://dropbox.com) may be the easiest way to sync files between your virtual machine and your host machine.  To install:

- download the 32-bit Ubuntu version downloaded from [here](https://www.dropbox.com/install?os=lnx) - be sure to save the file, not open it, from Firefox
- install it from the command-line via 'sudo dpkg -i dropbox_1.4.0_i386.deb' but note that the file name may change as a new version is released
  - note: dropbox requires a supporting package (python-gpgme), but I already installed that on the image
- once installed, a vibrating icon will appear in the left-hand launcher; click on that, then click on "Start Dropbox"
- this will download the proprietary daemon (a daemon is a background process) and install it
- at that point, the standard dropbox registration wizard will appear


### Image creation details ###

For those who are interested, here is what I did to set up the image:

- Create a new VirtualBox image
  - which I named "Ubuntu 12.04.3"
  - I set the disk to resize dynamically, and everything else was set at the default
- I installed Ubuntu 12.04.3 LTS (32 bit), desktop edition, from the CD image downloaded from http://www.ubuntu.com (the specific image file is [here](http://releases.ubuntu.com/precise/ubuntu-12.04.3-desktop-i386.iso)
  - when prompted, I clicked on 'download updates' and 'install 3rd party software' when the options were given
  - The computer name is cassiopeia, the login name is 'student', full name is 'L33t Hax0r', and the password is 'password'
  - this account can run root (system) commands via 'sudo' - if you don't know what this means, you can safely ignore it
- Once it was finished, I rebooted, and logged in
- I ran 'sudo apt-get update' and then 'sudo apt-get dist-upgrade'.
- installed the other packages: `sudo apt-get install clang emacs nasm astyle tofrodos source-highlight doxygen doxygen-doc ddd git g++ python-gpgme`
  - python-gpgme is a supporting package for Dropbox, in case students want to install that
- Reboot after all these apt-gets, and then ran 'apt-get autoremove' and 'apt-get clean'.
- Ran the following two commands:
  - `sudo update-alternatives --set cc /usr/bin/clang`
  - `sudo update-alternatives --set c++ /usr/bin/clang++`
- Downloaded Google Chrome from [here](https://www.google.com/intl/en/chrome/browser/), and installed it via 'sudo dpkg -i google-chrome-stable_current_i386.deb'
  - That installation did not work perfectly (which was expected), and to fix an installation such as this you run 'sudo apt-get -f install'
  - Then ran 'apt-get autoremove' and 'apt-get clean' again
- Added terminal, emacs, and google chrome icons to the launch bar
- Browser customization
  - Set both firefox and chrome's home page to Collab
  - Cleared both histories
  - Chrome is set as the default browser
- The VirtualBox "Guest Additions" are what allow for proper mouse integration and, more importantly, proper full-screening.  The ones that the system wanted to install (via System Settings -> Hardware -> Additional Drivers) appear to have a [bug](https://www.virtualbox.org/ticket/11709) that has since been fixed.  So I installed the latest version of the guest additions (4.3.6, which matches the latest version of VirtualBox) via the VirtualBox menu item Devices->Insert Guest Additions CD Image, and then rebooted.  At that point, the system would full screen properly.
- I loaded up emacs, and then told it to disable showing the startup messages (this could also be accomplished by following the guidelines [here](http://xenon.stanford.edu/~manku/dotemacs.html)).
- Added a few aliases were added (the last 4 lines of .bashrc) to help prevent people from accidentally removing files (adding -i for rm, mv, and cp; and aliasing xemacs to emacs)
- Cloned the github repo via `git clone https://github.com/aaronbloomfield/pdr`
  - Note that a `git pull` will still have to be executed each time to update it
  - I added the pdr/cs2150/index.html page as the second tab loaded up by both Firefox and Chrome
- Ran `history -c` to remove the history of the command entered
- To reduce the size of the hard disk (since I have to host it for people to download), I ran "cat /dev/zero > zero" until it ran out of space, then removed that file (this writes all 0's to the hard drive).  I shut down the guest, and ran: 'VBoxManage modifyhd ubuntu-12.04.3.vdi --compact'.  A better way would be to load up into recovery mode and run zerofill, but the grub menu does not seem to be easily available to load into recovery mode, so I didn't pursue it any further.
  - Note that in the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command "VBoxManage internalcommands sethduuid disk.vdi" will change the UUID, and allow you to proceed
- A few quick notes
  - The guest hard drive reported 3.8 Gb of space used prior to distribution of the image
  - the guest additions (the drivers that make Ubuntu in a VirtualBox image work nicely with the host system) were installed by the additional drivers step done before
  - Firefox was a recent version, and flash worked right out of the box
  - the VM may capture the mouse - to uncapture it, you press the "host key", which is the right Control key on Linux.  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up
