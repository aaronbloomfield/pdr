// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    char buffer[256];
    while ( true ) {
        // read in first character on line
        char first = file.get();
        // catch DOS and UNIX newlines
        if ( (first == '\n') || (first == '\r') )
            continue;
        // read in second character on line
        char second = file.get();
        // did we encounter the separator?
        if ( (first == '-') && (second == '-') ) {
            // read in the rest of the line
            file.getline(buffer, 255, '\n');
            break;
        }
        // read in the prefix code
        file.getline(buffer, 255, '\n');
        // do something with the prefix code
        cout << "character '" << first << "' has prefix code '"
             << buffer << "'" << endl;
    }
    // read in the second section of the file: the encoded message
    char bit;
    while ( (bit = file.get()) != '-' ) {
        if ( (bit != '0') && (bit != '1') )
            continue;
        // do something with the bit read in
        cout << "read in bit '" << bit << "'" << endl;
    }
    // close the file before exiting
    file.close();
}
