VirtualBox image creation details
=================================

[Go up to the main directory page](index.html) ([md](index.md))

For those who are interested, this is how the VirtualBox image was created.
It is not necessary to complete Tutorial 1.

# Introduction

This page has a number of different sections, and the sections you need to install will vary depending on what course you are using this image for.  The top of each section describes which of the sub-sections need to be installed for what.

**Software Versions**

This installation document installs the following versions:

- [Ubuntu 18.04, 64-bit](http://ubuntu.com)
- Clang++ version 6.0.0
- g++ version 7.4.0
- Python [3.6.8](http://packages.ubuntu.com/xenial/python3)

Newer versions of the above may have since come out, but at the time of the last update of this document (August 2019), they the latest versions installed via apt-get.

**Notes**

- The guest hard drive reported 27 Gb of space available, prior to distribution of the image.  The disk image itself was, after compaction, 10 Gb.  When compressed via zip, it was 4.3 Gb in size.
- You will likely need to use a different unzip program to extract the image; the ones that come bundled with most operating systems can not handle archives of that size.  We have used [7-zip](http://www.7-zip.org/) with success.
- Video and sound (via youtube) worked fine with both Chrome and Firefox (although it may a bit slow depending on your computer's speed)
- The VM may capture the mouse - to uncapture it, you press the "host key", (which is the right Control key on Linux and Windows hosts, and the left Command key on Mac hosts).  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up
- In the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command `VBoxManage internalcommands sethduuid disk.vdi` (changing `disk.vdi` appropriately) will change the UUID, and allow you to proceed

# Basic installation

All installations need to run through this, as it sets up the default Ubuntu installation.

**Basic installation**

- Created a new VirtualBox image
    - I named it "Ubuntu 18.04" or similar; this automatically selected Linux as the OS type; I manually selected "Ubuntu (64 bit)" as the version
    - I set the memory at 4096 Mb (instead of the default of 512 Mb), ensured that the disk size was "dynamically allocated" and was set to 40 Gb (instead of the default 8 Gb); everything else was set at the default
- I installed Ubuntu 18.04.3 LTS (64 bit), desktop edition, from the DVD image downloaded from [ubuntu.com](https://www.ubuntu.com)
    - When prompted, I clicked on 'download updates' and 'install 3rd party software' when the options were given
    - For hard drive, I used the default option that was already selected
    - The computer name is cassiopeia, the login name is 'student', full name is 'l33t h4x0r', and the password is 'password'
    - This account can run root (system) commands via 'sudo' - if you don't know what this means, you can safely ignore it
- Once it was finished, I rebooted, and logged in
- Via a Konsole, ran `sudo apt-get update` then `sudo apt-get dist-upgrade`
- Reboot!
- Ran `apt-get autoremove` (which didn't have to remove anything)
- VirtualBox guest additions
    - These are the utilities so that VirtualBox will work correctly with the host computer (proper full screen, etc.)
    - The menu option to "Insert Guest Additions CD Image" downloads a version that will not work with the current Linux kernel version, so the ISO must be manually downloaded from [http://download.virtualbox.org/virtualbox/](http://download.virtualbox.org/virtualbox/)
	- Installing these requires the `gcc make perl` packages to be installed first
    - Once done, run `autorun.sh` from `/media/student/VBOXADDITIONS_4.3.36_105129` (or similar), and follow the prompts.  Alternatively, if that does not work, try running `sudo bash VBoxLinuxAdditions.run` from that same directory.
- Reboot!
- As per [here](https://askubuntu.com/questions/973017/wrong-nameserver-set-by-resolvconf-and-networkmanager) to fix an issue with /etc/resolv.conf, edited /etc/systemd/resolved.conf to put 8.8.8.8 as the DNS line, and then ran the commands from the second answer: `sudo rm -f /etc/resolv.conf` followed by `sudo ln -s /run/systemd/resolve/resolv.conf /etc/resolv.conf`, and then rebooted
- Ran `apt-get remove thunderbird`
- Disable the KDE wallet system (if using KDE)

# Development installation

The "Program and Data Representation configuration" section is for the [Program and Data Representation](http://uva-cs.github.io/pdr) course, and it includes all of the compilers and editors needed.  The "Python/Django" section installs the files needed to run Python 3 and the Django framework.

### Program and Data Representation configuration

- Installed the other packages: `sudo apt-get install clang emacs25 vim nasm astyle tofrodos source-highlight gdb lldb doxygen doxygen-doc graphviz ddd git g++ gobjc gnustep gnustep-make gnustep-common libgnustep-base-dev evince g++-multilib libc6-dev-i386 libc6-dev:i386 flex`
    - Note that there are two other `apt-get install` lines to be run, below
	- The last 5 packages are for Objective C, based on the instructions [here](http://www.fatvat.co.uk/2010/04/getting-started-with-objective-c-on.html) (it may be that only a subset of those packages are actually necessary)
- Ran the following two commands to change the default C/C++ compiler to clang:
```
sudo update-alternatives --set cc /usr/bin/clang
sudo update-alternatives --set c++ /usr/bin/clang++
```
- Downloaded Google Chrome from [here](https://www.google.com/chrome/browser/desktop/index.html), and installed it via `sudo dpkg -i google-chrome-stable_current_i386.deb`
    - If that installation does not work perfectly, run `sudo apt-get -f install`
    - Then the .deb file was removed
- GNOME customization
    - Removed RhythmBox, Ubuntu Software, and Amazon from the favorites bar on the left-hand side
    - Added Terminal, Emacs, and Chrome to the favorites on the left-hand side
	- Disabled the screen saver lock, as detailed in the first answer [here](https://stackoverflow.com/questions/28281077/how-do-i-disable-the-gnome-desktop-screen-lock)
- Browser customization
    - Set the home pages for both Chrome and Firefox to online course repo site (http://uva-cs.github.io/pdr) and to Collab
    - Chrome is set as the default browser
- I loaded up emacs from the command line, and then told it to disable showing the startup messages (this could also be accomplished by following the guidelines [here](http://xenon.stanford.edu/~manku/dotemacs.html)).
- Added a few aliases were added (the last 4 lines of .bashrc) to help prevent people from accidentally removing files (adding -i for rm, mv, and cp; and aliasing xemacs to emacs).  This was done both in /home/student/.bashrc and /etc/skel/.bashrc.
```
alias mv='mv -i'
alias rm='rm -i'
alias cp='cp -i'
alias xemacs='emacs'
```
- Cloned the github repo via `git clone https://github.com/uva-cs/pdr`; note that a `git pull` will still have to be executed each time to update it
- Removed all the empty default directories in ~/student other than Desktop and Downloads

### Introduction to Cybersecurity configuration

These are not included in this repo, but can be found [in the aaronbloomfield/ics repo](https://github.com/aaronbloomfield/ics/blob/master/docs/vb-image-details.md#introduction-to-cybersecurity-configuration).  These instructiosn were last updated in August 2019.

### Service Learning Practicum configuration section

These sections are no longer included here, nor used in the images currently distributed, but can be found in [the latest version of the aaronbloomfield/slp repo](https://github.com/aaronbloomfield/slp/blob/master/docs/virtualbox-image-details.md#development-installation).  There were two sections for this: "LAMP configuration (with both PHP and Python 3)" and "Ruby on Rails configuration".  Note that that repo, and the linked instructions, were last updated in August of 2017.  All the versions stated therein are outdated, and many (all?) of those instructions may need tweaking to work properly again.


### Programming Contest configuration section

This section is no longer included here, nor used in the images currently distributed, but can be found in [an old version of the PDR repo](https://github.com/uva-cs/pdr/blob/2019-spring/tutorials/01-intro-unix/vb-image-details.md#programming-contest-configuration-sections).  That version was last updated in the spring of 2018.

# Image completion

The "Image finalization" section should be run on every image.

**Image finalization**

- Reboot (rebooting also clears out /tmp)
- Run `apt-get autoremove` and `apt-get clean`
- Cleared browser history
- Removed the apt-get proxy, if present: `sudo /bin/rm -f /etc/apt/apt.conf.d/02proxy`
- To reduce the size of the hard disk (since I have to host it for people to download), I ran `sudo cat /dev/zero > zero; sudo /bin/rm -f zero`.  This creates a large file of all 0's until it runs out of space, then removes that file.
- Ran `history -c` to remove the history of the commands entered on the command line
- Logged out then shut down the guest, and ran: `VBoxManage modifyhd disk.vdi --compact` (using the real image file name instead of "disk.vdi").  A better way would be to load up into recovery mode and run zerofill, but the grub menu does not seem to be easily available to load into recovery mode, so I didn't pursue it any further.

**Increasing the disk size**

The hard drive size was set at 40 Gb, and about 27 Gb is available; the rest is used by the operating system (and the swap partition).  If you need more space than this, you will have to expand the hard drive.  Be careful -- it is easy to accidentally erase the entire hard drive while doing this!

- The process has two steps: increase the VirtualBox disk image itself, then increase the partition of the guest OS.
- To increase the VirtualBox disk image, power it down, and then run the following command.  The size listed is the size in Mb, so 40960 Mb is 40 Gb.  The command is: `VBoxManage modifyhd <imagefile> --resize 40960` -- but you will want to use a larger value if you are increasing the size.
    - Note that `<imagefile>` is the .vdi disk image, and should be the absolute path including the name and extension
- The second step is to resize the guest OS partition.  The easiest way to do this is to download a bootable disk image for this purpose.  You can use [Gparted](http://sourceforge.net/projects/gparted/files/gparted-live-stable/), which is free.  Keep in mind that your guest OS is 64-bit, so you will want the "amd64" version.
- To boot up via the Gparted image, Go to Settings -> Storage.  In the "Storage Tree" box, there will be a "Controller: IDE" entry, with an "Empty" line below that; click on the "Empty" line, and select the Gparted disk image (using the blue DVD icon on the right).  Click Okay, then start the image.  It should start the Gparted disk.
- When Gparted boots, selected the default boot option.  In the text-based menus, hit Enter to select the defaults.
- From the GUI, resize your partition.  Hit "Apply" when done.
- Double click on the red "Exit" icon, and select shutdown.
- Back in Settings -> Storage -> Controller: IDE -> Empty, remove that disk from the virtual CD/DVD drive (under the blue DVD icon, select the last option to remove the image) -- it should not be there by default at this point.  Click OK.
- Boot into Kubuntu normally.


**Changes for the future**

- none, yet
