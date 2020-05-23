#!/bin/bash

# take every path in the repo ending in .md, ignoring those under reveal.js
for infile in `find . -type f -name '*.md' | grep -v 'reveal\.js'`; do
    # derive HTML page title from header of MD file
    lineone=`head -1 $infile`
    # derive output file name (replace .md with .html)
    outfile=`echo $infile | sed 's/md$/html/g'`
    # calculate relative path from any file in a subdirectory to another (CSS) in the root directory
    pathprefix=`echo ${infile:2} | tr -d -c '/' | sed -r 's/\//..\//g'`
    # perform the conversion from MD to HTML, linking CSS in the process
    pandoc --standalone --variable "pagetitle:$lineone" --css ${pathprefix}markdown.css\
           --from markdown --to html5 --output $outfile $infile
done

pandoc --standalone --variable "pagetitle:Teaching Assistants" --css ../markdown.css --css tas.css\
       --from markdown --to html5 --output uva/tas.html uva/tas.md
