The files in this directory contain the C and C++ code discussed in
the 09-x86 lecture set, and the assembly that results from running
that C and C++ code through g++ to obtain the assembly equivalent.

This code will NOT work in nasm -- it's the output of g++, not the
input to nasm.

To use the code, you can use make to make a number of targets:

compile: will compile all the files into executables to run

asm: will generate all the assembly files that were gone over in lecture

clean: will remove the executables

asmclean: will remove the assmebly files that were generated with 'asm'
	  (works in either Linux or Cygwin)
