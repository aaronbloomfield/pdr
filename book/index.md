Program and Data Representation: Textbook
=========================================

[Go up to the main README file](../README.html) ([md](../README.md))

Herein lies the beginnings of a textbook to accompany the course.  The only part that is complete at this point is the chapter on IBCM: [ibcm-chapter.pdf](ibcm-chapter.pdf).  The two chapters on x86 are **NOT** complete, and are not meant to be used at this time.

In addition to a standard LaTeX installation, the texlive-pstricks package will need to be installed in order to compile the book from the LaTeX source.

Due to the fact that it is currently used in the course, and that students may not have LaTeX installed, the [ibcm-chapter.pdf](ibcm-chapter.pdf) file is directly committed to the repository.


Directory contents
------------------

All of the files in this directory are not listed on this web page, just a few that need an explanation:

- main.tex: The full book, which has spaces for each chapter.  As mentioned above, only 1 chapter (IBCM) is anywhere near complete, and two others (the two x86 chapters) are in the draft stage.
- working.tex: this is meant to allow LaTeX to be run on the individual chapter(s) that are being worked on, without having to recompile the entire book.  This was used to generate the [ibcm-chapter.pdf](ibcm-chapter.pdf) file.
- references.bib: all the references used throughout in the book.
- Makefile: a series of targets to automate the building of the PDF documents in this book.

Each chapter is named as foo.tex, with a foo/ direcotry to hold the images and source code for that chapter (all source code is kept external to the LaTeX files).
