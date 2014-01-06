Program and Data Representation
===============================

This repository contains the materials for the course entitled "CS
2150: Program and Data Representation" at the University of Virginia.
It will contain all of the slides, labs, exams, etc. used throughout
the course.

This course is a second-year course for computer science majors.  It
is the primary data structures course in the University of Virginia's
computer science curriculum.  Unlike many other data structure courses
at other institutions, it is intended as the *third* course in
sequence, meaning that students are expected to have taken two
semesters of Java (or equivalent, although some of the examples are
specifically from Java).

The contents of this repository will be filled in throughout the
spring 2014 semester as the materials are developed (or, more
specifically, as they are converted into a git-friendly form and added
to this repository).  It is likely that this repository will be
largely incomplete until the spring 2014 semester is completed
(completion date is May, 2014).

The primary author is [Aaron
Bloomfield](http://www.cs.virginia.edu/~asb),
[aaron@virginia.edu](<mailto:aaron@virginia.edu>),
[@bloomfieldaaron](http://twitter.com/bloomfieldaaron).  The spring
2014 semester will be the 14th consecutive semester I have taught the
course.

Contents
--------

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
- labs/: the labs are the main assignments in the course, and each lab
  is split into pre-lab, in-lab, and post-lab parts.  There are 11
  full labs, with a partial 12th lab that is an optional component of
  the course.  The labs are written using
  [markdown](http://daringfireball.net/projects/markdown/), and the 
  rendered HTML version of each lab is also committed to this
  repository.
- [slides](slides/index.html): Contains the slides used in the course; view
  [slides/index.html](slides/index.html) for the table of contents.
  The slides use [reveal.js](https://github.com/hakimel/reveal.js/), a
  HTML presentation framework.
- tutorials/: the tutorials that are used as part of the lab
  assignments, these are primarily Linux tutorials.

Markdown
--------

The majority of the content in this repository was created using
Markdown.  Unfortunately, the only standardized Markdown is very old
(2004), and has limited support for many HTML features, such as
tables.  Indeed, the default Ubuntu version of Markdown is the 2004
version.  To address this, a [markdown.c](utils/markdown.c.html)
([src](utils/markdown.c)) program was written to use more recent
Markdown features.  This program uses the libmarkdown library, which
does support more recent Markdown features.  This library installed
on Ubuntu via the 'libmarkdown2-dev' package.  Note that reveal.js,
which is used for the slides, also supports more modern Markdown
features.

The resulting document is a full HTML document -- meaning it adds the
doctype, html, head, and body tags to the document, as necessary.

To compile: "gcc markdown.c -o markdown -lmarkdown". To use, specify
the input file name, and optionally an output file.

That being said, the extra Markdown features used in this repository
should be compatible with the generally accepted Markdown features.

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
