Program and Data Representation
===============================

This repository contains the materials for the course entitled "CS
2150: Program and Data Representation" at the University of Virginia.
It will contain all of the slides, labs, exams, etc. used throughout
the course.

Students in the course should view the
[cs2150/index.html](cs2150/index.html) file in the **cloned** repo
(i.e., don't try to view it on github.com).

The contents of this repository will be filled in throughout the
spring 2014 semester as the materials are developed (or, more
specifically, as they are converted into a git-friendly form and added
to this repository).  It is likely that this repository will be
largely incomplete until the spring 2014 semester is completed;
completion date is May, 2014.

The primary author is [Aaron
Bloomfield](http://www.cs.virginia.edu/~asb),
[aaron@virginia.edu](<mailto:aaron@virginia.edu>),
[@bloomfieldaaron](http://twitter.com/bloomfieldaaron).  The spring
2014 semester will be the 14th consecutive semester I have taught the
course.


Contents
--------

**Note that the links below will not work correctly if you are viewing
this via the github repo -- you will need to download the repo first**

- book/: the beginnings of a textbook to be used for this course.  It
  is written using LaTeX.
- [docs](docs/index.html): a series of usefull documents that are not
  labs or tutorials.  To view these fiels, see the
  [docs/index.html](docs/index.html) file.
- [cs2150](cs2150/index.html): the materials that are specific to CS
  2150 as taught at the University of Virginia, such as daily
  announcements, due dates, etc.  To view these files, see the
  [cs2150/index.html](cs2150/index.html) file.
- exams/: past exams for the course; there are two midterms and a
  final for each semester.  Currently they are all in PDF format, but
  that may change in the future.  The more recent ones were developed
  using LaTeX, the earlier ones using Word.
- [labs](labs/index.html): the labs are the main assignments in the
  course, and each lab is split into pre-lab, in-lab, and post-lab
  parts. To view the labs, see the [labs/index.html](labs/index.html)
  file.  There are 11 full labs, with a partial 12th lab that is an
  optional component of the course.  The labs are written using
  [markdown](http://daringfireball.net/projects/markdown/), and the 
  rendered HTML version of each lab is also committed to this
  repository.
- [slides](slides/index.html): Contains the slides used in the course; view
  [slides/index.html](slides/index.html) for the table of contents.
  The slides use [reveal.js](https://github.com/hakimel/reveal.js/), a
  HTML presentation framework.
- [tutorials](tutorials/index.html): the tutorials that are used as
  part of the lab assignments, these are primarily Linux tutorials.
  To view the tutorials, see the
  [tutorials/index.html](tutorials/index.html) page.


Course Description
------------------

This course is a second-year course for computer science majors.  It
is the primary data structures course in the University of Virginia's
computer science curriculum.  Unlike many other data structure courses
at other institutions, it is intended as the *third* course in
sequence, meaning that students are expected to have taken two
semesters of Java (or equivalent, although some of the examples are
specifically from Java).  The course focuses on how programs and data
are represented from the high level down to the low level.  For
programs, we examine (from high to low): abstract data types, Java
code, C++ code, C code, assembly (x86) code, and a customized machine
language.  For data, we examine (also from high to low): abstract data
types, objects, primitive types, and how numbers are encoded (both
floats (IEEE 754) and integers (two's complement)).

The [ABET](http://www.abet.org) course objects are as follows:

- Understand program representation from the high-level programming
  language perspective down to the underlying machine level
  representation, including: number representation, operations,
  conditionals, and control structures
- Be able to implement basic and advanced abstract data types in C++
  including: linked lists, stacks, queues, hash tables, trees, and
  graphs
- Be able to evaluate asymptotic time and space complexity analysis of
  programs and data structure implementations using Big-O, Big-Omega,
  and Big-Theta notation and assess the suitability of a data structure
  for a particular problem
- Understand the basic program execution model and the underlying
  computer hardware and software (fetch-execute cycle, memory hierarchy,
  operating system, compiler)
- Be able to implement basic program control and data structures in an
  assembly language (loops, conditionals, subroutines and parameter
  passing modes, arrays)


Markdown
--------

The majority of the content in this repository was created using
Markdown.  Unfortunately, the only standardized Markdown is very old
(2004), and has limited support for many HTML features, such as
tables.  Indeed, the default Ubuntu version of Markdown is the 2004
version.  To address this, a [markdown.c](utils/markdown.c.html)
([src](utils/markdown.c)) program was written to use more recent
Markdown features.  This program uses the libmarkdown library, which
does support more recent Markdown features.  This library installed on
Ubuntu via the 'libmarkdown2-dev' package.  Note that reveal.js, which
is used for the slides, also supports more modern Markdown features.
That being said, the extra Markdown features used in this repository
should be compatible with the generally accepted Markdown features.

To compile: "gcc markdown.c -o markdown -lmarkdown". To use, specify
the input file name, and optionally an output file.  The resulting
document is a full HTML document -- meaning it adds the doctype, html,
head, and body tags to the document, as necessary.

For all the Markdown files, both the original (.md) file and the HTML
version (.html) are added to the repository, so that people who do not
have Markdown installed can still view the contents of this
repository.


Source code
-----------

All source code is formatted via astyle and then highlighted via
source-highlight.  Both the original (foo.cpp) and the highlihged
version (foo.cpp.html) are included in the repo.  All links to source
code will like to the .html, with a "([src](...))" after it
to link to the original source code.

- astyle options: -A2 -s4 --indent-switches
- source-highlight options: -d


Canvas notes
------------

To add a canvas to a slide (to allow drawing with a mouse or a
stylus), you must do a few things:

1. The slide can NOT be Markdown, it must be all pure HTML
2. include the js/canvas.js and css/dhtmlwindow.js scripts, as well as
   the dhtmlwindow.css CSS file (the two dhtmlwindow.* files are for
   the calibration feature)
3. include the css/dhtmlwindow.css CSS file (but only if you want to
   enable cailbration)
4. add an `onload="init()"` to the body tag
5. add the following immediately after the body tag (this is for
   the calibration feature):

        <div id="dhtmlwindowholder"><span style="display:none">.</span></div>

6. add the following code at the end of the .html file (just before
   the three script tags):

        <div id="calibratediv" style="display:none">
          <div id="calibratecanvasdiv">
            <canvas id="calibratecanvas" width="300" height="300">Your browser does not support the canvas tag</canvas>
          </div>
          <p style="text-align:center">Click the center of the target<br><a href="#" onClick="calibratewin.close(); return false">Close window</a></p>
        </div>

Then, on each slide, you add the following:  
`<script language="javascript" type="text/javascript">insertCanvas(42);</script>`  
The parameter provided (42 in this case) need to be a number, and must
be unique (i.e., each slide needs to have a separate number).

A few other notes:

- The canvas is larger than the slide itself, and the amount is the
  `canvas_border` variable in the canvas.js file
- To add colors, add them to the `colors` array in the canvas.js
  file


Licensing
---------

The material in this repository is released under a [Creative Commons
Attribution-ShareAlike 4.0 International
License](http://creativecommons.org/licenses/by-sa/4.0/) (CC BY-SA).

Various components in this repository were obtained from other
sources, all of which have compatible licenses, and all of which are
listed below.  Anything not listed below is released under the CC
BY-SA license mentioned above.

- [reveal.js](https://github.com/hakimel/reveal.js/) (used for the
  slides), released under an MIT license
- Some of the images images
  - The green double arrow (slides/images/green-double-arrow.png) was
    adapted from [openclipart.org](http://openclipart.org),
    specifically
    [here](http://openclipart.org/detail/3677/arrow-left-right-by-torfnase);
    the red double arrow (slides/images/red-double-arrow.png) was
    adapted from that as well.  These images are released into the
    public domain with no restrictions; see
    [here](http://openclipart.org/share) for details.
- [slides/images/menuicon.png](slides/images/menuicon.png) is from
  [here](http://androgeek.com/wp-content/uploads/2010/03/android-free-menu-icon-set.png)
