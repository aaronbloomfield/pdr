#!/bin/bash

# take every path in the repo ending in .c, .cpp, .h, or Makefile, ignoring those under book
for infile in `find . -type f \( -name '*.c' -or -name '*.cpp' -or\
                                 -name '*.h' -or -name 'Makefile' \) | grep -v 'book'`; do
    source-highlight --doc $infile --title `basename $infile` --out-format html5 --quiet --gen-version
done

# for Assembly files, treat them as Assembly and not S
for infile in `find . -type f -name '*.s' | grep -v 'book'`; do
    source-highlight --doc $infile --title `basename $infile` --out-format html5 --quiet --gen-version --lang-def 'asm.lang'
done
