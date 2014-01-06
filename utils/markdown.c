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
 * for those tags, to perform a markdown conversion.  It requires the
 * libmarkdown2-dev pacakage be installed under Ubuntu.
 *
 * The resulting document is a full HTML document -- meaning it adds
 * the <doctype>, <html>, <head>, and <body> tags to the document.
 *
 * To compile: "gcc markdown.c -o markdown -lmarkdown"
 *
 * To use, specify the input file name, and optionally an output file
 * name.
 */

#include <stdio.h>
#include <mkdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {
    int i;
    FILE *fpin, *fpout;

    if ( (argc != 2) && (argc != 3) ) {
        printf ("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(0);
    }

    if ( (fpin = fopen(argv[1],"r")) == NULL ) {
        printf ("Error: unable to open input file: %s\n", argv[1]);
        exit(0);
    }

    if ( (argc == 2) || (!strcmp(argv[2],"-")) )
        fpout = stdout;
    else if ( (fpout = fopen(argv[2],"w")) == NULL ) {
        printf ("Error: unable to open output file: %s\n", argv[2]);
        exit(0);
    }

    MMIOT* doc = mkd_in(fpin, 0);
    if ( doc == NULL ) {
        printf ("Error processing markdown input file in mkd_in()\n");
        exit(0);
    }

    fprintf (fpout, "<!doctype html>\n<html>\n<head>\n</head>\n<body>\n");
    markdown (doc, fpout, 0);
    fprintf (fpout, "</body>\n</html>\n");
    fclose(fpout);

    mkd_cleanup(doc);

    return 0;
}
