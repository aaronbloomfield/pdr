# Makefile for CS 2150 pre-lab 8
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX	= clang++ -m32

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g

# Defines the assembler
AS	= nasm

# Defines the flags for the assembler
ASFLAGS	= -f elf

# All of the .o files for our program
OFILES	= vecsum.o main.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# This tells make to create a .o file from a .s file, using the
# defaults above (i.e. the AS and ASFLAGS macros)
.SUFFIXES: .o .s

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
main:	$(OFILES)
	$(CXX) $(CXXFLAGS) -o vecsum $(OFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
