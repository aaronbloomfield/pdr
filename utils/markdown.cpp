/* A more modern markdown converter.
 *
 * Copyright (c) 2014 by Aaron Bloomfield
 *
 * This is part of the https://github.com/aaronbloomfield/pdr
 * repository, and is released under the CC BY-SA license (along with
 * the rest of that repository).
 *
 * The default markdown that is installed with Ubuntu (version 1.0.1
 * from 2004) does not support more modern tags, such as tables.  This
 * program will use the libmarkdown library, which does have support
 * for those tags, to perform a markdown conversion.  The full list of
 * additional features it supports can be found at
 * http://manpages.ubuntu.com/manpages/raring/man7/mkd-extensions.7.html.
 * It requires the libmarkdown2-dev pacakage be installed under
 * Ubuntu.
 *
 * The resulting document is a full HTML document -- meaning it adds
 * the <doctype>, <html>, <head>, and <body> tags to the document.
 *
 * To compile: "gcc markdown.c -o markdown -lmarkdown"
 *
 * To use, specify the input file name, and optionally an output file
 * name.
 */

#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include <mkdio.h>
}

using namespace std;

int main (int argc, char **argv) {
    int i, inidx, outidx;
    FILE *fpin, *fpout;
    char *css = NULL;
    // check command line parameters
    if ( !strcmp(argv[1],"-css") ) {
        if ( (argc != 4) && (argc != 5) ) {
            cout << "Usage: " << argv[0] << " [-css <css_file>] <input_file> <output_file>" << endl;
            exit(0);
        }
        css = argv[2];
    } else {
        if ( (argc != 2) && (argc != 3) ) {
            cout << "Usage: " << argv[0] << " [-css <css_file>] <input_file> <output_file>" << endl;
            exit(0);
        }
    }
    // if the -css flag is there, then the input and output file names will be in a different place
    if ( css ) {
        inidx = 3;
        if ( argc == 4 )
            outidx = -1;
        else
            outidx = 4;
    } else {
        inidx = 1;
        if ( argc == 2 )
            outidx = -1;
        else
            outidx = 2;
    }
    // try to open the file
    ifstream fin(argv[inidx]);
    if ( !fin.is_open() ) {
        cout << "Error: unable to open input file: " << argv[1] << endl;
        exit(0);
    }
    // read in the file into an internal string
    bool codemode = false;
    string codeprefix = "    ";
    string file, line, firstline;
    bool gotfirstline = false;
    while ( getline(fin,line) ) {
        if ( !gotfirstline ) {
            gotfirstline = true;
            firstline = line;
        }
        if ( (line[0] == '`') && (line[1] == '`') && (line[2] == '`') ) {
            // we ignore any language specification after the three back quotes
            codemode = !codemode;
            continue;
        }
        if ( codemode )
            file += codeprefix;
        file += line + "\n";
    }
    // try to process the string
    MMIOT* doc = mkd_string(file.c_str(),file.length(),0);
    if ( doc == NULL ) {
        cout << "Error processing markdown input file in mkd_in()" << endl;
        exit(0);
    }
    // determine where the output is going
    if ( (outidx == -1) || (!strcmp(argv[outidx],"-")) )
        fpout = stdout;
    else if ( (fpout = fopen(argv[outidx],"w")) == NULL ) {
        printf ("Error: unable to open output file: %s\n", argv[2]);
        exit(0);
    }
    // write the output
    fprintf (fpout, "<!doctype html>\n<html>\n<head>\n<meta charset=\"utf-8\">\n<title>%s</title>\n", firstline.c_str());
    if ( css )
        fprintf (fpout, "<link href=\"%s\" media=\"all\" rel=\"stylesheet\" type=\"text/css\">", css);
    fprintf (fpout, "</head>\n<body>\n");
    markdown (doc, fpout, 0);
    fprintf (fpout, "</body>\n</html>\n");
    fclose(fpout);
    mkd_cleanup(doc);
    return 0;
}
