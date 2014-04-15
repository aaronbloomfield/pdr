// This program shows how C-based file I/O works.  It will print a
// file to the screen two times.

// included so we can use cout
#include <iostream>
// stdlib.h is where exit() lives
#include <stdlib.h>

using namespace std;

// include the standard I/O library
#include <stdio.h>

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    char g;
    while ( (g = fgetc(fp)) != EOF )
        cout << g;
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning
    rewind(fp);
    // read the file again, and print to the screen
    while ( (g = fgetc(fp)) != EOF )
        cout << g;
    // close the file
    fclose(fp);
}

