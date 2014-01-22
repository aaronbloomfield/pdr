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
    int i, inidx, outidx;
    FILE *fpin, *fpout;
    char *css = NULL;
    if ( !strcmp(argv[1],"-css") ) {
        if ( (argc != 4) && (argc != 5) ) {
            printf ("Usage: %s [-css <css_file>] <input_file> <output_file>\n", argv[0]);
            exit(0);
        }
        css = argv[2];
    } else {
        if ( (argc != 2) && (argc != 3) ) {
            printf ("Usage: %s [-css <css_file>] <input_file> <output_file>\n", argv[0]);
            exit(0);
        }
    }
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
    if ( (fpin = fopen(argv[inidx],"r")) == NULL ) {
        printf ("Error: unable to open input file: %s\n", argv[1]);
        exit(0);
    }
    if ( (outidx == -1) || (!strcmp(argv[outidx],"-")) )
        fpout = stdout;
    else if ( (fpout = fopen(argv[outidx],"w")) == NULL ) {
        printf ("Error: unable to open output file: %s\n", argv[2]);
        exit(0);
    }
    MMIOT* doc = mkd_in(fpin, 0);
    if ( doc == NULL ) {
        printf ("Error processing markdown input file in mkd_in()\n");
        exit(0);
    }
    fprintf (fpout, "<!doctype html>\n<html>\n<head>\n");
    if ( css )
        fprintf (fpout, "<link href=\"%s\" media=\"all\" rel=\"stylesheet\" type=\"text/css\">", css);
    fprintf (fpout, "</head>\n<body>\n");
    markdown (doc, fpout, 0);
    fprintf (fpout, "</body>\n</html>\n");
    fclose(fpout);
    mkd_cleanup(doc);
    return 0;
}
