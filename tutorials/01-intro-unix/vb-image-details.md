PDR: Tutorial 1: Introduction to UNIX: VirtualBox image creation details
========================================================================

[Go up to the main tutorial 1 page](index.html)

For those who are interested, this is how the image was set up.  Note that a few of the sections here are for classes beyond PDR (in particular, the LAMP configuration section and the Ruby on Rails configuration section).  If you were to reproduce those on another computer, those two sections can be (and should be) skipped.

**Basic installation**

- Create a new VirtualBox image
    - which I named "Kubuntu 14.04"
    - I ensured that the disk size was "dynamically allocated" and was set to 16 Gb (instead of the default 8 Gb); everything else was set at the default
- I installed Ubuntu 14.04.1 LTS (32 bit), desktop edition, from the CD image downloaded from http://www.ubuntu.com (the specific image file is [here](http://releases.ubuntu.com/14.04.1/ubuntu-14.04.1-desktop-i386.iso))
    - when prompted, I clicked on 'download updates' and 'install 3rd party software' when the options were given
    - for hard drive, I used the default: "Guided -- use entire disk"
    - The computer name is cassiopeia, the login name is 'student', full name is 'L33t Hax0r', and the password is 'password'
    - this account can run root (system) commands via 'sudo' - if you don't know what this means, you can safely ignore it
- Once it was finished, I rebooted, and logged in
- I ran `sudo apt-get update` and then `sudo apt-get dist-upgrade`.
- Clicking on the toolbar image of a hardware card brought up the KDE Driver Manager, and the presented non-free drivers (the VirtualBox drivers) were installed
- Reboot!

**Program and Data Representation configuration**

- installed the other packages: `sudo apt-get install clang emacs24 nasm astyle tofrodos source-highlight doxygen doxygen-doc ddd git g++ python-gpgme lldb-3.4 gobjc gnustep gnustep-make gnustep-common libgnustep-base-dev`
    - python-gpgme is a supporting package for Dropbox, in case students want to install that
	- the last 5 packages are for Objective C, based on the instructions [here](http://www.fatvat.co.uk/2010/04/getting-started-with-objective-c-on.html)
- Ran the following two commands:
```
sudo update-alternatives --set cc /usr/bin/clang
sudo update-alternatives --set c++ /usr/bin/clang++
```
- Downloaded Google Chrome from [here](https://www.google.com/intl/en/chrome/browser/), and installed it via `sudo dpkg -i google-chrome-stable_current_i386.deb`
    - That installation did not work perfectly (which was expected), and to fix an installation such as this you run `sudo apt-get -f install`
    - Then the .deb file was removed
- Added terminal, emacs, and google chrome icons to the launch bar
- Browser customization
    - Set both firefox and chrome's home page to Collab
    - Chrome is set as the default browser
- I loaded up emacs from the command line, and then told it to disable showing the startup messages (this could also be accomplished by following the guidelines [here](http://xenon.stanford.edu/~manku/dotemacs.html)).
- Added a few aliases were added (the last 4 lines of .bashrc) to help prevent people from accidentally removing files (adding -i for rm, mv, and cp; and aliasing xemacs to emacs)
```
alias mv='mv -i'
alias rm='rm -i'
alias cp='cp -i'
alias xemacs='emacs'
```
- Cloned the github repo via `git clone https://github.com/aaronbloomfield/pdr`
    - Note that a `git pull` will still have to be executed each time to update it
    - I added the pdr/cs2150/index.html page as the second tab loaded up by both Firefox and Chrome
- Removed all the emtpy default directories in ~/student other than Desktop
- Disabled the KDE Wallet, as it was annoying and kept popping up all the time (System Settings -> Account Details -> KDE Wallet)

**LAMP configuration**

- Installed more packages: `sudo apt-get install apache2 php5 php5-cli netbeans phpmyadmin phpunit libmysqlclient-dev mysql-server mysql-client php5-mysql default-jdk openssh-server python-django tk-dev python-mysqldb php5-mcrypt php5-intl`
    - any prompted passwords (such as mysql) are 'password'
    - phpmyadmin is only configured with the apache2 server; the default option to the prompted yes/no question was used
- apache2 configuration
    - enabled the userdir apache2 module (i.e., using ~userid/ for each userid): `sudo a2enmod userdir`
    - enabled the URL rewriting apache2 module: `sudo a2enmod rewrite`
    - changed the default html directory to "~/html": edited two files in /etc/apache2/mods-available/: userdir.conf and php5.conf, and changed all instances of 'public_html' to 'html'
    - enabled PHP in user directories: comment out the 'php_admin_value engine Off' line in /etc/apache2/mods-available/php5.conf
	- enabled two PHP modules needed for CakePHP: `sudo php5enmod intl` and `sudo php5enmod mcrypt`
    - restart apache: `sudo service apache2 restart`
    - the 'student' user can already view the apache2 error logs (in /var/log/apache2), but if they couldn't, then they would have to have been added to the 'adm' group (i.e., `usermod -a -G adm student`, but this requires logging out and logging in for the group change to take effect)
    - made a 'html' directory both in ~/student and /etc/skel
- ssh'ed to localhost to accept the ssh key

**Ruby on Rails configuration**

- This method will take up about 400 Mb in your home directory
- I followed the directions at https://gorails.com/setup/ubuntu/14.04 -- this installs Ruby version 2.1.2 and Rails version 4.1.5 (as of the time of this writing; more recent versions may have since been produced)
    - You need to switch the C/C++ compiler back to gcc/g++:
```
sudo update-alternatives --set cc /usr/bin/gcc
sudo update-alternatives --set c++ /usr/bin/g++
```
    - The git/github configuration step was skipped, as that requires the final user of the image
    - MySQL was already set up in the LAMP configuration section
    - PostgreSQL is another SQL DB, but we are not using that on the image
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

**Image finalization**

- Reboot
- Run `apt-get autoremove` and `apt-get clean`
- Ran `history -c` to remove the history of the commands entered on the command line
- Cleared both browser histories
- To reduce the size of the hard disk (since I have to host it for people to download), I ran `cat /dev/zero > zero` until it ran out of space, then removed that file (this writes all 0's to the hard drive).  I shut down the guest, and ran: `VBoxManage modifyhd kubuntu-14.04.1.vdi --compact`
    - A better way would be to load up into recovery mode and run zerofill, but the grub menu does not seem to be easily available to load into recovery mode, so I didn't pursue it any further.
    - Note that in the image creation process, you may run into a problem with VirtualBox where it cannot register a new (or different) disk because it has the same UUID as a previous disk that you are replacing.  If so, then the command `VBoxManage internalcommands sethduuid disk.vdi` will change the UUID, and allow you to proceed

**Notes**

- The guest hard drive reported 5.7 Gb of space used, and 8.7 Gb of space available, prior to distribution of the image.  The disk image itself was, after compaction, 6.4 Gb.  When compressed via zip, it was 2.1 Gb in size.
- The guest additions (the drivers that make Ubuntu in a VirtualBox image work nicely with the host system) were installed by the additional drivers step done before
- Firefox was a recent version, and flash worked right out of the box, along with sound
- The VM may capture the mouse - to uncapture it, you press the "host key", which is the right Control key on Linux.  To have it warn you about what this is, you can reset all warnings via the VirtualBox help menu, and it will warn you about this at boot-up


**Installing Dropbox**

- If you want to install Dropbox, you can download the package from https://www.dropbox.com/install
- You want the 32-bit Ubuntu file which is [here](https://www.dropbox.com/download?dl=packages/ubuntu/dropbox_1.6.2_i386.deb) (although if they come out with a version newer than 1.6.2, that link will no longer work); the file name is "dropbox_1.6.2_i386.deb"
- Install it via `sudo dpkg -i dropbox_1.6.2_i386.deb`
- The installation will likely fail -- that's fine (there were likely supporting packages needed).  Two things to try:
    - Note that if you were installing this on your own computer, you would need the python-gpgme package (`sudo apt-get install python-gpgme`), but that was installed already on the virtual box image
    - Run `sudo apt-get -f install` -- the `-f` part tells apt-get to install the packages needed to fix an installation
- To finish installing dropbox, run `dropbox start -i`.  This will download and install the rest of the dropbox files needed
- To start dropbox, run `dropbox start`.  This first time it will provide a link -- once you go to that link, and log in, it will know which account to link the computer to, and it will start downloading your files.
- **WARNING:** Many people have a ***lot*** of files in their Dropbox folder.  And if you have 8 Gb of files there, and you install Dropbox on your virtual box image, then it will need to download 8 Gb of files.  In addition to taking quite some time, this will also cause the virtual box image to take up an additional 8 Gb of space.  And note that the VirtualBox image is set to only 16 Gb, and nearly 8 is taken up by the OS itself.

**Increasing the disk size**

The hard drive size was set at 16 Gb, and about 8.7 Gb is available; the rest is used by the operating system (and the swap partition).  If you need more space than this, you will have to expand the hard drive.  Be careful -- it is easy to accidentally erase the entire hard drive while doing this!

- The process has two steps: increase the VirtualBox disk image itself, then increase the partition of the guest OS.
- To increase the VirtualBox disk image, power it down, and then run the following command.  The size listed is the size in Mb, so 20480 Mb is 20 Gb.  The command is: `VBoxManage modifyhd <imagefile> --resize 20480`
  - Note that `<imagefile>` is the .vdi disk image, and should be the absolute path including the name and extension
- The second step is to resize the guest OS partition.  The easiest way to do this is to download a bootable disk image for this purpose.  You can use [Gparted](http://sourceforge.net/projects/gparted/files/gparted-live-stable/), which is free.  Keep in mind that your guest OS is 32-bit, so you will want the 386 (or 486) version.
- To boot up via the Gparted image, Go to Setings -> Storage.  In the "Storage Tree" box, there will be a "Controller: IDE" entry, with an "Empty" line below that; click on the "Empty" line, and select the Gparted disk image (using the blue DVD icon on the right).  Click Okay, then start the image.  It should start the Gparted disk.
- When Gparted boots, selected the default boot option.  In the text-based menus, hit Enter to select the defaults.
- From the GUI, resize your partition.  Keep in mind that you will need a 500 Mb swap partition.  Hit "Apply" when done.
- Double click on the red "Exit" icon, and select shutdown.
- Back in Settings -> Storage -> Controller: IDE -> Empty, remove that disk from the virtual CD/DVD drive (under the blue DVD icon, select the last option to remove the image).  Click OK.
- Boot into Kubuntu normally.

** Changes for the future **

For future installs (fall of 2015 and beyond), the following changes will be made to this document:

- Install additional packages: `sudo apt-get install graphviz php5-mcrypt php5-intl phpunit`.  Graphviz is needed for doxygen to create call graphs; the two PHP packages are needed for CakePHP installations to work properly; phpunit is for PHP unit tests.
- Enable the two PHP modules just installed: `sudo php5enmod intl` and `sudo php5enmod mcrypt`; then restart apache2: `sudo service apache2 restart`
- Which packages need to be installed for Objective C?  Definitely `libgnustep-base-dev`, but likely not all of the ones listed above...
