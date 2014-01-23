Itty Bitty Computing Machine (IBCM)
===================================

[Go up to the main README file](../README.html)

The Itty Bitty Computing Machine (IBCM) is a machine language designed
to be simple enough to teach the concepts of machine language, while
being complicated enough to write any program.  The *IBCM
computational model* (which is slighly different than the IBCM
presented here) is [Turing
complete](http://en.wikipedia.org/wiki/Turing_complete).  IBCM is
meant to be taught in a week of lecture.

IBCM was described in a SIGCSE 2011 article: "[IBCM: The Itty Bitty
Computing Machine](http://dl.acm.org/citation.cfm?id=1953273)" by
Aaron Bloomfield and William Wulf (Proceedings of the 42nd ACM
Technical Symposium on Computer Science Education (SIGCSE), March
2011, Dallas, TX); that article describes the Turing completeness of
IBCM.  Due to copyright restrictions, that article cannot be included
in this repository.

The primary mechanism for learning IBCM is through the [IBCM slide
set](../slides/08-ibcm.html) and the [IBCM book
chapter](../book/index.html).  The material in both of those largely
duplicates itself, but in different formats.  IBCM is utilized through
an online set of web pages, described next.


Website
-------

The IBCM is utilized through an online series of webpages.  The IBCM
simulator needs PHP in order to run, and thus must be run from a web
server (i.e., not as a local file).  Most of the computational load is
on the client side (via Javascript), and little is on the server side.
There are a few mirros of this website available, which are listed
below.  All the necessary code to run a separate copy are included in
this repository.

The primary file for the website is [index.html](index.html), and the
directions are on the [directions.html](directions.html) page.  The
simulator itself is on the [simulator.php](simulator.php) page -- but
as described above, this must be run on an actual web server.  Two
supporting files ([simulator.js](simulator.js) and
[ibcm.css](ibcm.css)) and the entire img/ directory are needed as
well.  Note that two of the programs listed below
([summation.ibcm](summation.ibcm) and
[array-summation.ibcm](array-summation.ibcm)) are linked to from the
various website pages.

The mirrors are:


- [http://libra.cs.virginia.edu/ibcm/](http://libra.cs.virginia.edu/ibcm/)
- [http://www.cs.virginia.edu/~cs216/ibcm/](http://www.cs.virginia.edu/~cs216/ibcm/)
- [http://people.virginia.edu/~asb2t/ibcm/](http://people.virginia.edu/~asb2t/ibcm/)


Sample code
-----------

The sample IBCM code included in this repository:

- [summation.ibcm](summation.ibcm): a program that reads in a single
  integer value *n*, and computes the sum from 1 to *n*. This is the
  first program that is discussed in the [IBCM slide
  set](../slides/08-ibcm.html).
- [array-summation.ibcm](array-summation.ibcm): a program that will
  compute the sum of a number of elements in an array.  Due to the
  fact that IBCM is intentionally a simplistic language, array
  indexing instrcutions must be created during run-time.  This is the
  second program that is discussed in the [IBCM slide
  set](../slides/08-ibcm.html).
- [multiply.ibcm](multiply.ibcm): a program that creates an activation
  to allow for recursive calls.  It can call itself recursively about
  1,300 times before it runs out of memory.  The 'stack', which
  contains the activation records, starts at the end of memory, and
  contains only the two parameters to the subroutine and the reutrn
  address.
- [turing.ibcm](turing.ibcm): a Turing machine simulator.  The
  automaton simulated is a four state [Busy
  Beaver](http://en.wikipedia.org/wiki/Busy_beaver) automaton, shown
  below.  Details about the Turing completeness can be found in the
  [IBCM article](dl.acm.org/citation.cfm?id=1953273).

![Busy Beaver automaton](busy-beaver.png)
