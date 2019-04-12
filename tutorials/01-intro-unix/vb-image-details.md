VirtualBox image creation details
=================================

[Go up to the main directory page](index.html) ([md](index.md))

For those who are interested, this is how the VirtualBox image was created.

# Introduction

This page has a number of different sections, and the sections you need to install will vary depending on what you are using this image for.  The image provided with the class has only two sections not installed: Dropbox configuration (in "Image completion") and Turning of the Internet access (in "Programming Contest configuration").

The top of each section describes which of the sub-sections need to be installed for what.

For the fall 2018 version, *only* a few sections were installed on the image:

- Basic Installation
- A Tale of Two GUIs
- Development Installation, but only the "Program and Data Representation" part

All other sections were *not* installed on the fall 2018 version.  The directions for those other parts have not been updated since August 2017, so they may be out of date -- certainly the version numbers are, if not those directions themselves.

**Software Versions**

This installation document installs the following versions:

- [Ubuntu 18.04, 64-bit](http://ubuntu.com)
- Clang++ version 6.0.0
- Python [3.6.5](http://packages.ubuntu.com/xenial/python3); ~~[Django 2.1](https://www.djangoproject.com/download/)~~
- ~~[Ruby 2.4.1; Rails 5.1.3](https://gorails.com/setup/ubuntu/18.04)~~

Newer versions of the above may have since come out, but at the time of the writing of this document (August 2018), they were either the versions installed via apt-get (Clang, Python), or the latest versions installed manually (Django, Ruby, and Rails).

**Notes**

- The guest hard drive reported 9.1 Gb of space available, prior to distribution of the image.  The disk image itself was, after compaction, 9.4 Gb.  When compressed via zip, it was 3.9 Gb in size.
- You will likely need to use a different unzip program to extract the image; the ones that come bundled with most operating systems can not handle archives of that size.  We have used [7-zip](http://www.7-zip.org/) with success.
- Video and sound (via youtube) worked fine with both Chrome and Firefox (although it may a bit slow depending on your computer's speed)
- The VM may capture the mouse - to uncapture it, you press the "host key", (which is the right Control key on Linux and Windows hosts, and the left Command key on Mac hosts).  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up
- In the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command `VBoxManage internalcommands sethduuid disk.vdi` (changing `disk.vdi` appropriately) will change the UUID, and allow you to proceed

# Basic installation

All installations need to run through this, as it sets up the default Ubuntu installation.

**Basic installation**

- Created a new VirtualBox image
    - I named it "Ubuntu 18.04" or similar; this automatically selected Linux as the OS type; I manually selected "Ubuntu (64 bit)" as the version
    - I set the memory at 2048 Mb (instead of the default of 512 Mb), ensured that the disk size was "dynamically allocated" and was set to 20 Gb (instead of the default 8 Gb); everything else was set at the default
- I installed Ubuntu 18.04.1 LTS (64 bit), desktop edition, from the DVD image downloaded from [ubuntu.com](https://www.ubuntu.com)
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
    - From the VirtualBox Device menu, select "Insert Guest Additions CD Image", and follow the prompts
    - Once done, run `autorun.sh` from `/media/student/VBOXADDITIONS_4.3.36_105129` (or similar), and follow the prompts.  Alternatively, if that does not work, try running `sudo bash VBoxLinuxAdditions.run` from that same directory.
- Reboot!

# A Tale of Two GUIs

For students in CS 2150 for the fall 2018 semester, there are two possible GUIs that they may want to use.  KDE is more similar to Windows, which is what everybody is familiar with.  Gnome is quite different, but many people like it better.  Thus, *both* GUIs were installed (yes, this greatly increased the hard disk size).  The installation of KDE was via `sudo apt-get install kubuntu-desktop`.


# Development installation

The "Program and Data Representation configuration" section is for the [Program and Data Representation](http://uva-cs.github.io/pdr) course, and it includes all of the compilers and editors needed.  The "Python/Django" section installs the files needed to run Python 3 and the Django framework.  The "Ruby on Rails configuration" section is for developing Ruby on Rails software.

**Program and Data Representation configuration**

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
- KDE customization
	- Removed Discover, Kontact, and KSysGuard from Favoriteskonso
    - Added konsole, emacs, firefox, and google chrome icons to favorites (from the K (start) menu, right-click and select 'add to favorites'), and the task bar (from the favorites menu, right-click and select 'add to panel'; this may require right-clicking on the panel and selecting panel options -> panel settings prior to moving the icons)
    - Changed the auto-lock feature: K-menu -> Computer -> System Settings -> Desktop Behavior -> Screen Locking, uncheck the "lock screen automatically..." button, and click Apply.
    - Plasmashell, which is part of the graphical window system, was crashing repeatedly.  The reason seems to be tooltip previews of application windows, so these should be disabled: right click taskbar -> Task Manager Settings -> General -> Uncheck "show tooltips"
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

**LAMP configuration (with both PHP and Python 3)**

- Installed more packages: `sudo apt-get install apache2 php php-cli netbeans phpmyadmin phpunit libmysqlclient-dev mysql-server mysql-client php-mysql default-jdk openssh-server tk-dev python-mysqldb php-mcrypt php-intl python3-pip composer libapache2-mod-php sqlite3 postgresql postgresql-contrib`
    - any prompted passwords (such as mysql) are 'password'
    - anything that needed configuration with a web server (phpmyadmin, for example) is only configured with the apache2 server
	- once done, ran `sudo -H pip3 install --upgrade pip`
	- ran `sudo apt-get remove openjdk-8-doc`, since that takes up a lot of space and can be accessed on the Internet
- apache2 configuration
    - enabled the userdir apache2 module (i.e., using ~userid/ for each userid): `sudo a2enmod userdir`
    - enabled the URL rewriting apache2 module: `sudo a2enmod rewrite`
	- enabled the two PHP modules needed for the CakePHP framework: `sudo phpenmod intl` and `sudo phpenmod mcrypt`
    - enabled PHP in user directories: edit (via sudo) `/etc/apache2/mods-available/php7.0.conf`, and change the `Off` in the 
`php_admin_value engine Off` line to `On`
    - restart apache: `sudo service apache2 restart`
    - the 'student' user can already view the apache2 error logs (in /var/log/apache2), but if they couldn't, then they would have to have been added to the 'adm' group (i.e., `usermod -a -G adm student`, but this requires logging out and logging in for the group change to take effect)
    - made a 'public_html' directory both in ~student and /etc/skel; the former is chown'ed to student:student
- ssh'ed to localhost to accept the ssh key
- Installed Django: the version of Django installed via apt-get is old, so we will install via pip: `sudo -H pip install Django==1.11`
- Attempted a CakePHP installation, to ensure that composer worked, and also to pre-download the files that would be used: `composer create-project --prefer-dist cakephp/app test`.  The directory created was then deleted
- Installed the virtualenv Python package: `sudo -H pip install virtualenv`

**Ruby on Rails configuration**

- This method will take up about 200 Mb in your home directory; it installs the files locally, not system-wide.
- First, switch the C/C++ compiler back to gcc/g++:
```
sudo update-alternatives --set cc /usr/bin/gcc
sudo update-alternatives --set c++ /usr/bin/g++
```
- I then followed the directions at [https://gorails.com/setup/ubuntu/16.04](https://gorails.com/setup/ubuntu/16.04).  The versions I used were Ruby 2.4.1, and Rails 5.1.3 (at the time of this document's writing); newer versions may have since appeared.
    - The rbenv installation method for Ruby was used
    - The git/github configuration step was skipped, as that requires the final user of the image
    - MySQL was already set up in the LAMP configuration section
    - PostgreSQL is another SQL database, but we are not using that on the image
	- The `--no-ri --no-rdoc` flags were added to each `gem` command
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
- Install the packages: `sudo apt-get install emacs24 vim eclipse g++ git gdb openjdk-8-jdk gedit`
    - If the Basic Installation section, above, was installed, then some of these packages have already been installed
	- The openjdk-8-doc package is not installed here to keep the image size down, but the packages above install it anyway
	- For various reasons, the eclipse package is typically not installed on the image released to the students, but should be installed on the final contest image
- Download the latest [PC^2](http://www.ecs.csus.edu/pc2/) software and unzip it in /usr/local/
	- At the time of this writing, the latest version is 9.3.2-3449, and the direct download link is [here](http://www.ecs.csus.edu/pc2/code/v9/pc2-9.3.2-3449/pc2-9.3.2-3449.zip); thus, the directory it is unzipped into would be `/usr/local/pc2-9.3.2`
	- After unzipping, create a symlink: from /usr/local/ run (changing the version as necessary): `sudo ln -s pc2-9.3.2 pc2`
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

- I ran a few commands to make sure everything worked properly (and deleted any created directories afterward) -- but only run these if those packages were installed above:
    - `composer create-project --prefer-dist cakephp/app cakephp`
    - `rails new railshw -d mysql`
	- `django-admin startproject mysite`
- Reboot (rebooting also clears out /tmp)
- Run `apt-get autoremove` and `apt-get clean`
- Cleared browser history
- To reduce the size of the hard disk (since I have to host it for people to download), I ran `sudo cat /dev/zero > zero; sudo /bin/rm -f zero`.  This creates a large file of all 0's until it runs out of space, then removes that file.
- Ran `history -c` to remove the history of the commands entered on the command line
- Logged out then shut down the guest, and ran: `VBoxManage modifyhd disk.vdi --compact` (using the real image file name instead of "disk.vdi").  A better way would be to load up into recovery mode and run zerofill, but the grub menu does not seem to be easily available to load into recovery mode, so I didn't pursue it any further.

**Installing Dropbox (optional)**

**NOTE:** these instructions have not been tested for a few years, so they may no longer work properly...

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

The hard drive size was set at 20 Gb, and about 9.9 Gb is available; the rest is used by the operating system (and the swap partition).  If you need more space than this, you will have to expand the hard drive.  Be careful -- it is easy to accidentally erase the entire hard drive while doing this!

- The process has two steps: increase the VirtualBox disk image itself, then increase the partition of the guest OS.
- To increase the VirtualBox disk image, power it down, and then run the following command.  The size listed is the size in Mb, so 20480 Mb is 20 Gb.  The command is: `VBoxManage modifyhd <imagefile> --resize 20480`
    - Note that `<imagefile>` is the .vdi disk image, and should be the absolute path including the name and extension
- The second step is to resize the guest OS partition.  The easiest way to do this is to download a bootable disk image for this purpose.  You can use [Gparted](http://sourceforge.net/projects/gparted/files/gparted-live-stable/), which is free.  Keep in mind that your guest OS is 64-bit, so you will want the "amd64" version.
- To boot up via the Gparted image, Go to Settings -> Storage.  In the "Storage Tree" box, there will be a "Controller: IDE" entry, with an "Empty" line below that; click on the "Empty" line, and select the Gparted disk image (using the blue DVD icon on the right).  Click Okay, then start the image.  It should start the Gparted disk.
- When Gparted boots, selected the default boot option.  In the text-based menus, hit Enter to select the defaults.
- From the GUI, resize your partition.  Hit "Apply" when done.
- Double click on the red "Exit" icon, and select shutdown.
- Back in Settings -> Storage -> Controller: IDE -> Empty, remove that disk from the virtual CD/DVD drive (under the blue DVD icon, select the last option to remove the image) -- it should not be there by default at this point.  Click OK.
- Boot into Kubuntu normally.

**Upgrading from a previous version**

Because previous versions of this image were a different version of Ubuntu (specifically, 16.04), we are not providing upgrade information, as it is too extensive to properly check those instructions.


**Changes made for spring 2019**

These were the changes made for the spring 2019 image, and they have not yet been incorporated into the instructions above.

- As per [here](https://askubuntu.com/questions/973017/wrong-nameserver-set-by-resolvconf-and-networkmanager) to fix an issue with /etc/resolv.conf, edited /etc/systemd/resolve/resolved.conf to put 8.8.8.8 as the DNS line, and then ran the commands from the top answer: `sudo rm -f /etc/resolv.conf`, `sudo ln -s /run/systemd/resolve/resolv.conf`, and then rebooted
- Ran `apt-get remove thunderbird`
- Ran `apt-get install autopsy sleuthkit fcrackzip libarchive-zip-perl libboost-dev libboost-doc`
- Disable the KDE wallet system

**Changes for the future**

- none, yet
