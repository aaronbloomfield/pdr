Program and Data Representation
===============================

Contents
--------

- [Introduction](#introduction)
- [Contributing to this repository](#contributing)
- [Repository contents](#contents)
- [Course description](#description)
- [Markdown](#markdown)
- [Source code](#sourcecode)
- [Canvas notes](#canvasnotes)
- [License](#license)

<a name="introduction"></a>Introduction
---------------------------------------

This repository contains the materials for the course entitled "CS
2150: Program and Data Representation" at the [University of
Virginia](http://www.virginia.edu).  It will contain all of the
slides, labs, exams, etc. used throughout the course.  The course
description is [below](#description).

Students in the course should view the
[cs2150/index.html](cs2150/index.html) file in the **cloned**
repository (i.e., don't try to view it on github.com).

The contents of this repository will be filled in throughout the
spring 2014 semester as the materials are developed (or, more
accurately, as they are converted into a git-friendly form and added
to this repository).  It is likely that this repository will be
largely incomplete until the spring 2014 semester is completed;
the expected completion date is May, 2014.

The primary author is [Aaron
Bloomfield](http://www.cs.virginia.edu/~asb)
([aaron@virginia.edu](<mailto:aaron@virginia.edu>),
[@bloomfieldaaron](http://twitter.com/bloomfieldaaron)).  The spring
2014 semester will be the 14th consecutive semester I have taught the
course.


<a name="contributing"></a>Contributing to this Repository
----------------------------------------------------------

Updates to the repository are restricted to approved individuals only,
to prevent anybody from messing with the slides right before a
lecture.  However, others can still contribute to this repository --
to do so, take the following steps:

1. Create a github account, if you do not have one
2. Fork this repository: you can click on the "Fork" link in the upper
   right, or just click
   [here](https://github.com/aaronbloomfield/pdr/fork)
3. Clone your forked repository on to your local machine
4. Make any changes you want to your forked version, then commit and
   push your changes back to your forked repository
5. Create a pull request, following the instructions
   [here](https://help.github.com/articles/creating-a-pull-request)

At that point, I will receive a notice that a change has been
submitted, and I'll look at it and hopefully accept it into the main
repository.

When you want to bring in the updates from the main pdr github
repository into your cloned repository, you will need to follow the
instructions [here](https://help.github.com/articles/syncing-a-fork).


<a name="contents"></a>Repository Contents
------------------------------------------

**Note that the links below will not work correctly if you are viewing
this online at github.com -- you will need to download the repository
first**

- book/: the beginnings of a textbook to be used for this course.  It
  is written using LaTeX.
- [docs](docs/index.html): a series of useful documents that are not
  labs or tutorials.  To view these files, see the
  [docs/index.html](docs/index.html) file.
- [cs2150](cs2150/index.html): the materials that are specific to CS
  2150 as taught at the University of Virginia, such as daily
  announcements, due dates, etc.  To view these files, see the
  [cs2150/index.html](cs2150/index.html) file.
- [exams](exams/index.html): past exams for the course; there are two
  midterms and a final for each semester.
- [labs](labs/index.html): the labs are the main assignments in the
  course, and each lab is split into pre-lab, in-lab, and post-lab
  parts. To view the labs, see the [labs/index.html](labs/index.html)
  file.  There are 11 full labs, with a partial 12th lab that is an
  optional component of the course.  The labs are written using
  [markdown](http://daringfireball.net/projects/markdown/), and the 
  rendered HTML version of each lab is also committed to this
  repository.
- [slides](slides/index.html): Contains the slides used in the course;
  view [slides/index.html](slides/index.html) for the table of
  contents. The slides use
  [reveal.js](https://github.com/hakimel/reveal.js/), an HTML
  presentation framework.
- [tutorials](tutorials/index.html): the tutorials that are used as
  part of the lab assignments, these are primarily Linux tutorials.
  To view the tutorials, see the
  [tutorials/index.html](tutorials/index.html) page.
- [utils](utils/index.html): various utilities for this repository

<a name="description"></a>Course Description
--------------------------------------------

This course is a second-year course for computer science majors.  It
is the primary data structures course in the [University of
Virginia](http://www.virginia.edu)'s [computer
science](http://www.cs.virginia.edu) curriculum.  Unlike many other
data structure courses at other institutions, it is intended as the
*third* course in sequence, meaning that students are expected to have
taken two semesters of Java (or equivalent, although some of the
examples are specifically from Java).  The course focuses on how
programs and data are represented from the high level down to the low
level.  For programs, we examine (from high to low): abstract data
types, Java code, C++ code, C code, assembly (x86) code, and a
customized machine language.  For data, we examine (also from high to
low): abstract data types, objects, primitive types, and how numbers
are encoded (both floats (IEEE 754) and integers (two's complement)).
About two-thirds of this course is programming using C++.  The
remainder of this course uses other languages, including (in
decreasing order): x86 assembly, IBCM (a machine language), C,
Objective C, and shell scripting.

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


<a name="markdown"></a>Markdown
-------------------------------

The majority of the content in this repository was created using
[Markdown](http://daringfireball.net/projects/markdown/).
Unfortunately, the only standardized Markdown is very old (2004), and
has limited support for many HTML features, such as tables.  Indeed,
the default Ubuntu version of Markdown is the 2004 version.  To
address this, a [markdown.c](utils/markdown.c.html)
([src](utils/markdown.c)) program was written to use more recent
Markdown features.  This program uses the libmarkdown library, which
does support more recent Markdown features.  This library installed on
Ubuntu via the 'libmarkdown2-dev' package.  Note that reveal.js, which
is used for the slides, also supports more modern Markdown features.
And the two sets of Markdown features are not the same.  That being
said, the extra Markdown features used in this repository should be
compatible with the generally accepted Markdown features, and are
intended to be features that are supported by both the provided
program and reveal.js.

To compile the program, enter: "gcc markdown.c -o markdown
-lmarkdown". To use, specify the input file name, and optionally an
output file.  The resulting document is a full HTML document --
meaning it adds the `<doctype>`, `<html>`, `<head>`, and `<body>` tags
to the document, as necessary.

For all the Markdown files in this repository, both the original (.md)
file and the HTML version (.html) are added to the repository, so that
people who do not have Markdown installed can still view the contents
of this repository.

Note that Github supports an enhanced version of Markdown, called
[Github Flavored
Markdown](https://help.github.com/articles/github-flavored-markdown),
or GFM.  This mostly pertains to this README file.  In an effort to
ensure compatibility with other Markdown programs (such as the one
described here and reveal.js), GFM specific features are generally
avoided.  One example is the use of anchors in this document -- the
HTML tags are included instead of using GFM's version.


<a name="sourcecode"></a>Source code
------------------------------------

All source code is formatted via
[astyle](http://astyle.sourceforge.net/) and then highlighted via
[source-highlight](http://www.gnu.org/software/src-highlite/source-highlight.html).
Both the original file (foo.cpp) and the highlighted version
(foo.cpp.html) are included in the repository.  All links to source
code will like to the .html, with a "([src](...))" after it to link to
the original source code.

- astyle options: -A2 -s4 -S -xG
  - note that the current version of astyle on Ubuntu 12.04 seems to
    ignore the -xG flag...
- source-highlight options: -d


<a name="canvasnotes"></a>Canvas notes
--------------------------------------

To add a canvas to a slide (to allow drawing with a mouse or a
stylus), you must do a few things:

1. The slide can NOT be Markdown, it must be all pure HTML
2. Include the js/canvas.js and css/dhtmlwindow.js scripts, as well as
   the dhtmlwindow.css CSS file (the two dhtmlwindow.* files are for
   the calibration feature)
3. Add an `onload="init()"` to the body tag
4. Add the following immediately after the `<body>` tag (this is for
   the calibration feature):

        <div id="dhtmlwindowholder"><span style="display:none"></span></div>

5. Add the following code at the end of the .html file (just before
   the three script tags):

        <div id="calibratediv" style="display:none">
          <div id="calibratecanvasdiv">
            <canvas id="calibratecanvas" width="300" height="300">Your
                          browser does not support the canvas tag</canvas>
          </div>
          <p style="text-align:center">Click the center of the target<br><a 
                          href="#" onClick="calibratewin.close(); return
                          false">Close window</a></p>
        </div>

Then, on each slide, you add the following:  
`<script language="javascript" type="text/javascript">insertCanvas();</script>`  

A few other notes:

- The canvas is larger than the slide itself, and the amount is the
  `canvas_border` variable in the canvas.js file
- To add colors, add them to the `colors` array in the canvas.js
  file; more color names can be found
  [here](http://www.tutorialspoint.com/html5/html5_color_names.htm).


<a name="license"></a>License
-----------------------------

The material in this repository is released under a [Creative Commons
Attribution-ShareAlike 4.0 International
License](http://creativecommons.org/licenses/by-sa/4.0/) (CC BY-SA).

Copyright (c) 2013-2014 by Aaron Bloomfield.

Some parts of this repository are taken, with permission, from other
sources.  The details are in the [License](LICENSE.html) file.
