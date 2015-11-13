PDR: Tutorial 1: Introduction to UNIX: VirtualBox image creation details
========================================================================

[Go up to the main tutorial 1 page](index.html)

For those who are interested, this is how the image was set up.  Note that a few of the sections here are for classes beyond PDR (in particular, the LAMP configuration, Ruby on Rails configuration, and the Programming Contest configuration sections).  If you were to reproduce those on another computer, those sections can be (and should be) skipped.

These directions are identical to the ones in the [SLP repository](https://github.com/aaronbloomfield/slp) (specifically the ones found [here](http://aaronbloomfield.github.io/slp/docs/virtualbox-image-details.html)).


# Introduction

This page has a number of different sections, and the sections you need to install will vary depending on what you are using this image for.  The image provided with the class has only two sections not installed: Dropbox configuration (in "Image completion") and Turning of the Internet access (in "Programming Contest configuration").

The top of each section describes which of the sub-sections need to be installed for what.

**Versions**

This installation document installs the following versions:

- Kubuntu 14.04
- Apache 2.4.7
- PHP 5.5.9
- Python 2.7.6 and 3.4.0; Django 1.8.4
- Ruby 2.2.3; Rails 4.2.3

Newer versions of the above may have since come out, but at the time of the writing of this document (August 2015), they were either the versions installed via apt-get (Apache, PHP, and Python), or the latest versions installed manually (Django, Ruby, and Rails).

**Notes**

- The guest hard drive reported 5.4 Gb of space used, and 13 Gb of space available, prior to distribution of the image.  The disk image itself was, after compaction, 6.2 Gb.  When compressed via zip, it was 1.9 Gb in size.
- Firefox was a recent version, and video (via youtube) worked right out of the box, along with sound; video and sound (also via youtube) worked fine with Chrome
- The VM may capture the mouse - to uncapture it, you press the "host key", (which is the right Control key on Linux and Windows hosts, and the left Command key on Mac hosts).  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up
- In the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command `VBoxManage internalcommands sethduuid disk.vdi` (changing `disk.vdi` appropriately) will change the UUID, and allow you to proceed

# Basic installation

All installations need to run through this, as it sets up the default Kubuntu installation.

**Basic installation**

- Created a new VirtualBox image
    - I named it "Kubuntu 14.04" or similar; this automatically selected Linux as the OS type; I manually selected "Ubuntu (32 bit)" as the version
    - I set the memory at 1024 Mb (instead of the default of 512 Mb), ensured that the disk size was "dynamically allocated" and was set to 20 Gb (instead of the default 8 Gb); everything else was set at the default
- I installed Kubuntu 14.04.2 LTS (32 bit), desktop edition, from the DVD image downloaded from [http://www.kubuntu.org/getkubuntu](http://www.kubuntu.org/getkubuntu) (the specific image file is [here](http://cdimage.ubuntu.com/kubuntu/releases/trusty/release/kubuntu-14.04.2-desktop-i386.iso))
    - When prompted, I clicked on 'download updates' and 'install 3rd party software' when the options were given
    - For hard drive, I used the default: "Guided -- use entire disk"
    - The computer name is cassiopeia, the login name is 'student', full name is 'L33t Hax0r', and the password is 'password'
    - This account can run root (system) commands via 'sudo' - if you don't know what this means, you can safely ignore it
- Once it was finished, I rebooted, and logged in
- Ran `sudo apt-get update`
- Installed the guest addition drivers.  There are many ways to do this, but few seemed to work.  I got it working via modifying the directions [here](http://askubuntu.com/questions/451805/screen-resolution-problem-with-ubuntu-14-04-and-virtualbox) (one of the comments of the top rated answer):
	- Ran `sudo apt-get install xserver-xorg-core` (the package manager had a lot of complaints with this, but it all seemed to work...)
	    - Another source indicated that xserver-xorg-core and xorg-video-abi-15 are the two packages to be installed, but the images as created here didn't test this out
	- Ran `sudo apt-get install -f virtualbox-guest-dkms virtualbox-guest-x11`
	- Reboot; the X11 screen started resizing with the VirtualBox window
- Ran `sudo apt-get dist-upgrade`.
- Reboot!
- Ran `apt-get autoremove`

# Development installation

The "Program and Data Representation configuration" section
is for the [Program and Data Representation](http://aaronbloomfield.github.io/pdr) course, and it includes all of the compilers and editors needed.  The "LAMP configuration (with both PHP and Python)" section installs a full [LAMP stack](https://en.wikipedia.org/wiki/LAMP_%28software_bundle%29) for use with web development; both PHP and Python are installed.  The "Ruby on Rails configuration" section is for developing Ruby on Rails software.

**Program and Data Representation configuration**

- Installed the other packages: `sudo apt-get install clang emacs24 nasm astyle tofrodos source-highlight gdb doxygen doxygen-doc graphviz ddd git g++ python-gpgme gobjc gnustep gnustep-make gnustep-common libgnustep-base-dev`
    - Note that there are two other `apt-get install` lines to be run, below: when installing LAMP and when following the [Ruby on Rails installation instructions](https://gorails.com/setup/ubuntu/14.04), both of which are described below
    - The python-gpgme package is a supporting package for Dropbox, in case students want to install that
	- The last 5 packages are for Objective C, based on the instructions [here](http://www.fatvat.co.uk/2010/04/getting-started-with-objective-c-on.html) (it may be that only a subset of those packages are actually necessary)
	- If this were a native machine, then the "lldb-3.5" package should also be installed; however, lldb does not work in Ubuntu 14.04 when running through VirtualBox (but gdb does) ([reference](http://lists.cs.uiuc.edu/pipermail/lldb-dev/2014-April/003879.html))
- Ran the following two commands to change the default C/C++ compiler to clang:
```
sudo update-alternatives --set cc /usr/bin/clang
sudo update-alternatives --set c++ /usr/bin/clang++
```
- Downloaded Google Chrome from [here](https://www.google.com/intl/en/chrome/browser/), and installed it via `sudo dpkg -i google-chrome-stable_current_i386.deb`
    - That installation did not work perfectly (which was expected), and to fix an installation such as this you run `sudo apt-get -f install`
    - Then the .deb file was removed
- Added konsole, emacs, and google chrome icons to the launch bar
- Browser customization
    - Set both Firefox and Chrome's home page to Collab
    - Added the pdr/cs2150/index.html page as the second tab loaded up by both Firefox and Chrome
    - Chrome is set as the default browser
- I loaded up emacs from the command line, and then told it to disable showing the startup messages (this could also be accomplished by following the guidelines [here](http://xenon.stanford.edu/~manku/dotemacs.html)).
- Added a few aliases were added (the last 4 lines of .bashrc) to help prevent people from accidentally removing files (adding -i for rm, mv, and cp; and aliasing xemacs to emacs).  This was done both in /home/student/.bashrc and /etc/skel/.bashrc.
```
alias mv='mv -i'
alias rm='rm -i'
alias cp='cp -i'
alias xemacs='emacs'
```
- Cloned the github repo via `git clone https://github.com/aaronbloomfield/pdr`; note that a `git pull` will still have to be executed each time to update it
- Removed all the empty default directories in ~/student other than Desktop and Downloads
- Disabled the KDE Wallet, as it was annoying and kept popping up all the time (KMenu -> Computer -> System Settings -> Account Details -> KDE Wallet)

**LAMP configuration (with both PHP and Python)**

- Installed more packages: `sudo apt-get install apache2 php5 php5-cli netbeans phpmyadmin phpunit libmysqlclient-dev mysql-server mysql-client php5-mysql default-jdk openssh-server tk-dev python-mysqldb php5-mcrypt php5-intl python-pip`
 - any prompted passwords (such as mysql) are 'password'
    - phpmyadmin is only configured with the apache2 server; the default option to the prompted yes/no question was used
- apache2 configuration
    - enabled the userdir apache2 module (i.e., using ~userid/ for each userid): `sudo a2enmod userdir`
    - enabled the URL rewriting apache2 module: `sudo a2enmod rewrite`
	- enabled the two PHP modules needed for the CakePHP framework: `sudo php5enmod intl` and `sudo php5enmod mcrypt`
    - enabled PHP in user directories: comment out the 'php_admin_value engine Off' line in /etc/apache2/mods-available/php5.conf
    - restart apache: `sudo service apache2 restart`
    - the 'student' user can already view the apache2 error logs (in /var/log/apache2), but if they couldn't, then they would have to have been added to the 'adm' group (i.e., `usermod -a -G adm student`, but this requires logging out and logging in for the group change to take effect)
    - made a 'public_html' directory both in ~student and /etc/skel
- ssh'ed to localhost to accept the ssh key
- Installed Django: the version of Django installed via apt-get is 1.6 (via the [python-django](http://packages.ubuntu.com/trusty/python-django) package); this version is [no longer supported](https://en.wikipedia.org/wiki/Django_%28web_framework%29#Versions), and thus 1.8 was installed instead. Django 1.8 is a long-term support release, and will be supported until at least April 2018 ([reference](https://en.wikipedia.org/wiki/Django_%28web_framework%29#Versions)).  To install: `sudo pip install Django==1.8.4`
- Installed Composer (the package manager for PHP) globally following the directions [here](https://getcomposer.org/doc/00-intro.md): ran `curl -sS https://getcomposer.org/installer | php` followed by `mv composer.phar /usr/local/bin/composer`.

**Ruby on Rails configuration**

- This method will take up about 200 Mb in your home directory; it installs the files locally, not system-wide.
- First, switch the C/C++ compiler back to gcc/g++:
```
sudo update-alternatives --set cc /usr/bin/gcc
sudo update-alternatives --set c++ /usr/bin/g++
```
- I then followed the directions at [https://gorails.com/setup/ubuntu/14.04](https://gorails.com/setup/ubuntu/14.04).  The versions I used were Ruby 2.2.3, and Rails 4.2.3 (at the time of this document's writing); newer versions may have since appeared.
    - The git/github configuration step was skipped, as that requires the final user of the image
    - MySQL was already set up in the LAMP configuration section
    - PostgreSQL is another SQL database, but we are not using that on the image
- To start rails application, execute the following commands (the edit to be done in emacs is listed below):
```
cd
rails new myapp -d mysql
cd myapp
emacs config/database.yml
rake db:create
rails server
```
    - When you edit config/database.yml, you should change the mysql password (line 17 or so) to the root mysql user's password (likely just 'password')
    - You can now view the rails app at http://localhost:3000 in your web browser
- Changed the C/C++ compiler back over to clang/clang++:
```
sudo update-alternatives --set cc /usr/bin/clang
sudo update-alternatives --set c++ /usr/bin/clang++
```

# Programming Contest configuration sections

These sections are for configuring the image to run a programming contest using [PC^2](http://www.ecs.csus.edu/pc2/), and are not needed if you are *not* running (or participating in) such a contest.  One of the sections below will detail how to turn off the Internet for use in the actual contest, and that should only be completed for the final contest image.

**Programming Contest configuration**

- If you are upgrading from a previous image version, run `sudo apt-get update` and then `sudo apt-get dist-upgrade`
- Install the packages: `sudo apt-get install emacs24 vim eclipse g++ git gdb openjdk-7-jdk gedit`
    - If the Basic Installation section, above, was installed, then some of these packages have already been installed
	- The openjdk-7-doc package is not installed here to keep the image size down, but the packages above install it anyway
	- For various reasons, the eclipse package is typically not installed on the image released to the students, but should be installed on the final contest image
- Download the latest [PC^2](http://www.ecs.csus.edu/pc2/) software and unzip it in /usr/local/
	- At the time of this writing, the latest version is 9.2.4-2837, and the direct download link is [here](http://www.ecs.csus.edu/pc2/code/v9/pc2-9.2.4-2837/pc2-9.2.4-2837.zip); thus, the directory it is unzipped into would be `/usr/local/pc2-9.2.4`
	- After unzipping, create a symlink: from /usr/local/ run (changing the version as necessary): `sudo ln -s pc2-9.2.4 pc2`
	- Edit /usr/local/pc2/pc2v9.ini and replace `localhost` on the `server` line (likely line 12) with the full server name of the primary submission server
- Create a script to restore the Internet access after the contest (this does not hurt anything to have it ready, as it won't do anything if the Internet is not turned off).  This can be `/usr/local/bin/restore-internet` -- the commands therein need sudo, so only the `student` user can run them. This is typically executed at the end of the contest if the contestants want to save their work.  All that has to be done is to modify the default policy for the chains. Be sure to also run `chmod 755 /usr/local/bin/restore-internet`.
```
#!/bin/bash
sudo iptables -P INPUT ACCEPT
sudo iptables -P OUTPUT ACCEPT
sudo iptables -P FORWARD ACCEPT
```
- Create a `/usr/local/bin/pc2team` shell script, and chmod that to 755 (`chmod 755 /usr/local/bin/pc2team`):
```
#!/bin/bash
cd
/bin/cp -f /usr/local/pc2/pc2v9.ini .
/usr/local/pc2/bin/pc2team &
```

**User account configuration**

- Add in the four aliases to .bashrc, as described above in the "Basic installation" section
- Put the often used icons in the tool bar: Chrome or Firefox, Emacs, Konsole (and Eclipse, if it is installed)
- Load up Chrome and/or Firefox, and set the contest site as the default home page
- Load up emacs, click on "never show this again", and then "dismiss startup screen"; exit emacs
- Remove all directories in the account other than Downloads and Desktop
- If there is a second user, then run `chmod 700 /home/*` to prevent the second user from accessing any other user accounts (if there is only one user account on the system, then this is not necessary)
- Create an icon in the task bar for pc2team (it may be easiest to use an icon adapted from another application); use an [appropriate logo](https://www.google.com/search?q=icpc+logo) for that


**Turning off Internet access (and other things)**

- Prior to the contest itself, a bunch of things need to occur to the image for it to work: Internet needs to be turned off, etc.  These modifications are ***NOT*** made to the image as released, and should be made only right before the final image is prepared for the contest.
- If eclipse is not installed, then do so now (`sudo apt-get install eclipse`); put that icon in the tool bar
- Edit /etc/hosts to allow that to resolve domain names to IP addresses. Put in the course
servers, their aliases, and their IP addresses:
```
1.2.3.4 server1.university.edu server1
5.6.7.8 server2.university.edu server2
9.10.11.12 server3.university.edu server3
```
- Configure iptables: this details how to turn *off* network access.  **It is ONLY to be used on the final image for a programming contest!!!**
    - These directions based on the ones [here](https://help.ubuntu.com/community/IptablesHowTo) and [here](http://stackoverflow.com/questions/21870386/iptables-block-access-to-all-ports-except-from-a-partial-ip-address). We want to allow access to the submission servers, but deny everything else. We set the policy to all
three chains to DROP, and add ACCEPT lines for localhost and the course servers for the INPUT and
OUTPUT chains (we don’t do anything, other than changing the default policy, to the FORWARD chain).  For example, the following commands will work (assuming the servers are server1.cs.univeristy.edu through server3.cs.university.edu):
```
iptables -A INPUT -i lo -j ACCEPT
iptables -A OUTPUT -o lo -j ACCEPT
iptables -A INPUT -j ACCEPT -s server1.cs.university.edu
iptables -A INPUT -j ACCEPT -s server2.cs.university.edu
iptables -A INPUT -j ACCEPT -s server3.cs.university.edu
iptables -A OUTPUT -j ACCEPT -d server1.cs.university.edu
iptables -A OUTPUT -j ACCEPT -d server2.cs.university.edu
iptables -A OUTPUT -j ACCEPT -d server3.cs.university.edu
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP
```
    - Once those commands are entered via the command line, we save the rules: `iptables-save > /etc/iptables.rules`
    - After saving the rules, we configure the system to apply those rules on boot (specifically, when bringing the network interface up). Edit /etc/network/interfaces.  There will only be a clause for lo (the loopback interface) present.  Under the `iface lo inet loopback` line, put in the following line (indented): `pre-up iptables-restore < /etc/iptables.rules`
- **IMPORTANT**: having the contestants log in as `student` is problematic, as that is the user that can restore the Internet access (with the password and via `sudo`).  So either create another user, or change the password to something else and have the contest staff log the students in.
    - If you are creating a second user, be sure to run through the "user account configuration" section, above
    - Let's assume that the second user is `hspcteam`; once this account is all set up, create an hspcteam backup to allow resetting: from /home/student, run `sudo /bin/cp -a /home/hspcteam .`; then enter the following script (and make it executable) as `/usr/local/bin/reset-hspcteam`:
```
#!/bin/bash
cd
sudo rsync -a --del hspcteam/ /home/hspcteam/
```

# Image completion

The "Installing Dropbox" section is not installed by default.  The "Image finalization" section should be run on every image.  The other sections largely deal with maintenance.

**Image finalization**

- Reboot (rebooting also clears out /tmp)
- Run `apt-get autoremove` and `apt-get clean`
- Cleared both browser histories
- To reduce the size of the hard disk (since I have to host it for people to download), I ran `sudo cat /dev/zero > zero; sudo /bin/rm -f zero`.  This creates a large file of all 0's until it runs out of space, then removes that file.
- Ran `history -c` to remove the history of the commands entered on the command line
- Logged out then shut down the guest, and ran: `VBoxManage modifyhd disk.vdi --compact` (using the real image file name instead of "disk.vdi").  A better way would be to load up into recovery mode and run zerofill, but the grub menu does not seem to be easily available to load into recovery mode, so I didn't pursue it any further.

**Installing Dropbox (optional)**

- If you want to install Dropbox, you can download the package from https://www.dropbox.com/install
- You want the 32-bit Ubuntu version from [this page](https://www.dropbox.com/install?os=lnx)
- Install it via `sudo dpkg -i dropbox_2015.02.12_i386.deb` (adjust the package name to match what you just downloaded)
- The installation will likely fail -- that's fine (there were likely supporting packages needed).  Two things to try:
    - Note that if you were installing this on your own computer, you would need the python-gpgme package (`sudo apt-get install python-gpgme`), but that was installed already on the virtual box image
    - Run `sudo apt-get -f install` -- the `-f` part tells apt-get to install the packages needed to fix an installation
- To finish installing Dropbox, run `dropbox start -i`.  This will download and install the rest of the dropbox files needed
- To start dropbox, run `dropbox start`.  This first time it will provide a link -- once you go to that link, and log in, it will know which account to link the computer to, and it will start downloading your files.
- **WARNING:** Many people have a ***lot*** of files in their Dropbox folder.  And if you have 8 Gb of files there, and you install Dropbox on your virtual box image, then it will need to download 8 Gb of files.  In addition to taking quite some time, this will also cause the virtual box image to take up an additional 8 Gb of space.  And note that the VirtualBox image is set to 20 Gb, and nearly 8 is taken up by the OS itself.  So you may want to increase the disk size, which brings us to...

**Increasing the disk size**

The hard drive size was set at 20 Gb, and about 8.7 Gb is available; the rest is used by the operating system (and the swap partition).  If you need more space than this, you will have to expand the hard drive.  Be careful -- it is easy to accidentally erase the entire hard drive while doing this!

- The process has two steps: increase the VirtualBox disk image itself, then increase the partition of the guest OS.
- To increase the VirtualBox disk image, power it down, and then run the following command.  The size listed is the size in Mb, so 20480 Mb is 20 Gb.  The command is: `VBoxManage modifyhd <imagefile> --resize 20480`
  - Note that `<imagefile>` is the .vdi disk image, and should be the absolute path including the name and extension
- The second step is to resize the guest OS partition.  The easiest way to do this is to download a bootable disk image for this purpose.  You can use [Gparted](http://sourceforge.net/projects/gparted/files/gparted-live-stable/), which is free.  Keep in mind that your guest OS is 32-bit, so you will want the 386 (or 486 or 586) version.
- To boot up via the Gparted image, Go to Settings -> Storage.  In the "Storage Tree" box, there will be a "Controller: IDE" entry, with an "Empty" line below that; click on the "Empty" line, and select the Gparted disk image (using the blue DVD icon on the right).  Click Okay, then start the image.  It should start the Gparted disk.
- When Gparted boots, selected the default boot option.  In the text-based menus, hit Enter to select the defaults.
- From the GUI, resize your partition.  Keep in mind that you will need a 500 Mb swap partition.  Hit "Apply" when done.
- Double click on the red "Exit" icon, and select shutdown.
- Back in Settings -> Storage -> Controller: IDE -> Empty, remove that disk from the virtual CD/DVD drive (under the blue DVD icon, select the last option to remove the image).  Click OK.
- Boot into Kubuntu normally.

**Upgrading from a previous version**

For those who had a previous version of this image, these are the presumed steps to upgrade.  It should be the case that the new image can do everything that the old images can do (and more).  As the fall images are created from scratch, these steps have not been tested.  Depending on which previous version of the image you have, some of these steps may have already been done.

- Increase the disk size, if necessary -- it should be about 16-20 Gb, whereas some previous versions were 8 Gb.  See above for how to do this.
- Run `sudo apt-get update` and then `sudo apt-get dist-upgrade`
- Install some new packages: `sudo apt-get install php5-mcrypt php5-intl phpunit graphviz`
    - That being said, re-running the apt-get installation commands listed above can't hurt, just to be sure that all the packages have been installed
- Enable the two PHP modules needed for the CakePHP framework: `sudo php5enmod intl` and `sudo php5enmod mcrypt`
- Uninstall the default Django version: `sudo apt-get remove python-django`
- Install the new Django version: `sudo pip install Django==1.8.4`
- Upgrade the Ruby on Rails version.  This is most easily done by reinstalling it from scratch, following the directions above all over again.  In particular, you should remove the `~/.gemrc` file and the `~/.rbenv` and `~/.gem` directories.  Also, the changes made previously to `~/.bashrc` may need to be removed, as they are re-done by following the above directions.
- Install composer, following the directions in the last bullet point in the "Lamp configuration" section.

**Changes for the future**

None known yet!
