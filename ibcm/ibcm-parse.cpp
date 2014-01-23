/* A program that will quickly check if the file names passed in via
 * command line arguments look like IBCM files.  In particular, it
 * checks if the first four digits on each line are all hexadecimal
 * digits.  It does not program validity checking beyond this.  It is
 * useful to tell the students if, on submission, their programs will
 * parse correctly in an IBCM simulator.
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main (int argc, char *argv[]) {
    string line;
    int linenum = 0;
    bool allowComments = false;
    // make sure they gave some command-line parameters
    if ( argc == 1 ) {
        cout << argv[0] << ": no input files" << endl;
        exit(1);
    }
    for ( int i = 1; i < argc; i++ ) {
        // a comment has a '//' as the first two characters on a line
        if ( !strcmp(argv[i],"-allowcomments") ) {
            allowComments = true;
            continue;
        }
        // open the file
        ifstream file(argv[i]);
        if ( !file.is_open() ) {
            cout << argv[0] << ": " << argv[i] << ": no such file" << endl;
            exit(2);
        }
        // read in the entire file...
        while ( file.good() ) {
            // read in a line from the file
            getline (file, line);
            linenum++;
            // is it the last line of the file?
            if ( (line.size() == 0) && (!file.good()) )
                break;
            // is it a comment?
            if ( allowComments && (line.size() >= 2) &&
                    (line[0] == '/') && (line[1] == '/') )
                continue;
            // is the line too short?
            if ( line.size() < 4 ) {
                cout << argv[0] << ": " << argv[i] << " has too short a line on line number " << linenum << "(" << line.size() << ")" << endl;
                exit(3);
            }
            // are the first four digits hex characters?
            for ( int j = 0; j < 4; j++ )
                if ( !isxdigit(line[j]) ) {
                    cout << argv[0] << ": " << argv[i] << " invalid hexadecimal digit on line " << linenum << " character " << (j+1) << endl;
                    exit(3);
                }
        }
        // all done with this file!
        file.close();
    }
    return 0;
}
