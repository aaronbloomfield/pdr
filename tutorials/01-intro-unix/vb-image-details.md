VirtualBox image creation details
=================================

[Go up to the main directory page](index.html) ([md](index.md))

For those who are interested, this is how the VirtualBox image was created.

# Introduction

This page has a number of different sections, and the sections you need to install will vary depending on what course you are using this image for.  The top of each section describes which of the sub-sections need to be installed for what.

**Software Versions**

This installation document installs the following versions:

- [Ubuntu 20.04.1, 64-bit](http://ubuntu.com)
- Clang++ version 10.0.0
- g++ version 9.3.0
- Python [3.8.2](http://packages.ubuntu.com/xenial/python3)

Newer versions of the above may have since come out, but at the time of the last update of this document (September 2020), they the latest versions installed via `apt` (the package installation program).

**Notes**

- With just the basic and development installations, below, The guest hard drive reported 8.5 Gb used and 29 Gb of space available, prior to distribution of the image.  The disk image itself was, after compaction, 10 Gb.  When compressed via zip, it was 3.9 Gb in size.
- You will likely need to use a different unzip program to extract the image; the ones that come bundled with most operating systems can not handle archives of that size.  We have used [7-zip](http://www.7-zip.org/) with success.
- Video and sound (via youtube) worked fine with both Chrome and Firefox (although it may a bit slow depending on your computer's speed)
- The VM may capture the mouse - to uncapture it, you press the "host key", (which is the right Control key on Linux and Windows hosts, and the left Command key on Mac hosts).  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up
- In the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command `VBoxManage internalcommands sethduuid disk.vdi` (changing `disk.vdi` appropriately) will change the UUID, and allow you to proceed

# Basic installation

All installations need to run through this, as it sets up the default Ubuntu installation.

**Basic installation**

- Created a new VirtualBox image
    - I named it "Ubuntu 20.04" or similar; this automatically selected Linux as the OS type; I manually selected "Ubuntu (64 bit)" as the version
    - I set the memory at 4096 Mb (instead of the default of 1024 Mb), ensured that the disk size was "dynamically allocated" and was set to 40 Gb (instead of the default 10 Gb); everything else was set at the default
- I installed Ubuntu 20.04.1 LTS (64 bit), desktop edition, from the DVD image downloaded from [ubuntu.com](https://www.ubuntu.com)
    - When prompted, I clicked on 'download updates' and 'install 3rd party software' when the options were given
    - For hard drive, I used the default option that was already selected
    - The computer name is cassiopeia, the login name is 'student', full name is 'l33t h4x0r', and the password is 'password'
    - This account can run root (system) commands via 'sudo' - if you don't know what this means, you can safely ignore it
- Once it was finished, I rebooted, and logged in; I skipped the online account creation, did not send usage staistics back to Ubuntu, and ensured that location services were turned off
- Via a Konsole, ran `sudo apt update` then `sudo apt dist-upgrade`
- Reboot!
- Ran `sudo apt autoremove` (which didn't have to remove much)
- VirtualBox guest additions
    - These are the utilities so that VirtualBox will work correctly with the host computer (proper full screen, etc.)
    - I clicked on the menu option to "Insert Guest Additions CD Image", which downloaded it, and then cliked "Run" when prompted
    - Reboot!
	- It should now resize the screen properly and full-screen properly
	- Ran `umount /media/student/VBox_GAs_6.1.10` to umount the guest additions ISO image
	- From the VB menu, I removed the image via Devices -> Optical Drives -> Remove disk from virtual drive
- ~~As per [here](https://askubuntu.com/questions/973017/wrong-nameserver-set-by-resolvconf-and-networkmanager) to fix an issue with /etc/resolv.conf, edited /etc/systemd/resolved.conf to put 8.8.8.8 as the DNS line, and then ran the commands from the second answer: `sudo rm -f /etc/resolv.conf` followed by `sudo ln -s /run/systemd/resolve/resolv.conf /etc/resolv.conf`, and then rebooted~~
- Ran `sudo apt remove thunderbird`
- Disable the KDE wallet system (if using KDE)

# Development installation

The "Program and Data Representation configuration" section is for the [Program and Data Representation](http://uva-cs.github.io/pdr) course, and it includes all of the compilers and editors needed.  The "Python/Django" section installs the files needed to run Python 3 and the Django framework.

### Program and Data Representation configuration

- Installed the other packages: `sudo apt install clang llvm emacs vim nasm astyle tofrodos source-highlight gdb lldb doxygen doxygen-doc graphviz ddd git g++ gobjc gnustep gnustep-make gnustep-common libgnustep-base-dev evince g++-multilib libc6-dev-i386 libc6-dev:i386 flex make`
    - Note that there are other `apt install` lines to be run, below, depending on what else you are installing
	- The last 5 packages are for Objective C, based on the instructions [here](http://www.fatvat.co.uk/2010/04/getting-started-with-objective-c-on.html) (it may be that only a subset of those packages are actually necessary); this is not currently installed with this section, however
- Ran the following two commands to change the default C/C++ compiler to clang:
```
sudo update-alternatives --set cc /usr/bin/clang
sudo update-alternatives --set c++ /usr/bin/clang++
sudo update-alternatives --install /usr/bin/llvm-symbolizer llvm-symbolizer /usr/bin/llvm-symbolizer-10 1000
```
- Downloaded Google Chrome from [here](https://www.google.com/chrome/browser/desktop/index.html), and installed it via `sudo dpkg -i google-chrome-stable_current_i386.deb`
    - If that installation does not work perfectly, run `sudo apt install -f` (although it worked fine for this install)
    - Then the .deb file was removed
	- When Chrome was loaded, it was made the default browser and sending usage statistics were deselected
- GNOME customization
    - Removed RhythmBox and Ubuntu Software from the favorites bar on the left-hand side
    - Added Terminal, Emacs, and Chrome to the favorites on the left-hand side -- this was done by loading them up, and the clicking on the icon and selecting "add to favorites"
	- Disabled the screen saver lock, as detailed in the first answer [here](https://stackoverflow.com/questions/28281077/how-do-i-disable-the-gnome-desktop-screen-lock) (this meant running `gsettings set org.gnome.desktop.session idle-delay 0` from the terminal)
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

These are not included in this repo, but can be found [in the aaronbloomfield/ics repo](https://github.com/aaronbloomfield/ics/blob/master/docs/vb-image-details.md#introduction-to-cybersecurity-configuration).  These instructions were last updated in August 2019.

### Service Learning Practicum configuration section

These sections are no longer included here, nor used in the images currently distributed, but can be found in [the latest version of the aaronbloomfield/slp repo](https://github.com/aaronbloomfield/slp/blob/master/docs/virtualbox-image-details.md#development-installation).  There were two sections for this: "LAMP configuration (with both PHP and Python 3)" and "Ruby on Rails configuration".  Note that that repo, and the linked instructions, were last updated in August of 2017.  All the versions stated therein are outdated, and many (all?) of those instructions may need tweaking to work properly again.


### Programming Contest configuration section

This section is no longer included here, nor used in the images currently distributed, but can be found in [an old version of the PDR repo](https://github.com/uva-cs/pdr/blob/2019-spring/tutorials/01-intro-unix/vb-image-details.md#programming-contest-configuration-sections).  That version was last updated in the spring of 2018.

# Image completion

The "Image finalization" section should be run on every image.

**Image finalization**

- Reboot (rebooting also clears out /tmp)
- Run `sudo apt autoremove` and `sudo apt clean`
- Cleared browser history (for both browsers)
- Removed the apt proxy, if present: `sudo /bin/rm -f /etc/apt/apt.conf.d/02proxy`
- To reduce the size of the hard disk (since I have to host it for people to download), I ran `sudo cat /dev/zero > zero; sudo /bin/rm -f zero`.  This creates a large file of all 0's until it runs out of space, then removes that file.
- Ran `history -c` to remove the history of the commands entered on the command line
- Logged out then shut down the guest, and ran: `VBoxManage modifyhd disk.vdi --compact` (using the real image file name instead of "disk.vdi").  This required me to remove it from the list of known hard drive images via VB's File -> Virtual Media Manager menu option.  Note that there are other ways to do this, but that command worked just fine.

**Increasing the disk size**

With the current selected size of the image, this is no longer necessary.  However, if you are interested in seeing how this is done, you can view it [here](https://github.com/uva-cs/pdr/blob/2020-spring/tutorials/01-intro-unix/vb-image-details.md) (at the very bottom of that page)


**Changes for the future**

None yet!

