Program and Data Representation: Textbook
=========================================

[Go up to the main README file](../README.html) ([md](../README.md))

Herein lies the beginnings of a textbook to accompany the course.  The only part that is complete at this point is the chapter on IBCM: [ibcm-chapter.pdf](ibcm-chapter.pdf).  The two chapters on x86 are **NOT** complete, and are not meant to be used at this time.

In addition to a standard LaTeX installation, the texlive-pstricks package will need to be installed in order to compile the book from the LaTeX source.

Due to the fact that it is currently used in the course, and that students may not have LaTeX installed, the [ibcm-chapter.pdf](ibcm-chapter.pdf) file is directly committed to the repository.


Directory contents
------------------

Each chapter is named as foo.tex, with a foo/ direcotry to hold the images and source code for that chapter (all source code is kept external to the LaTeX files).


#### IBCM files

- [ibcm.tex](ibcm.tex): The actual content of the IBCM chapter; it is included in various other files (main.tex and ibcm-chapter.tex).  One can not LaTeX this file by itself.
- [ibcm-chapter.tex](ibcm-chapter.tex) ([pdf](ibcm-chapter.pdf)): This file includes ibcm.tex, and allows that content to be created into a stand-alone PDF of the IBCM content.
- [ibcm/](ibcm/): The directory that contains the various source code files and images used in the IBCM chapter.


#### x86 (32 bit) files

- [x86-32bit.tex](x86-32bit.tex): The introduction of the 32 bit x86 assembly instruction set; this is the actual content, and this file cannot be LaTeX'ed directly.
- [x86-32bit-ccc.tex](x86-32bit-ccc.tex): The C calling convention for 32 bit x86 assembly; this is the actual content, and this file cannot be LaTeX'ed directly.
- [x86-32bit-asm-chapter.tex](x86-32bit-asm-chapter.tex) ([pdf](x86-32bit-asm-chapter.pdf)): This file includes x86-32bit.tex, and allows that content to be created into a stand-alone PDF of the x86 introduction content.
- [x86-32bit-ccc-chapter.tex](x86-32bit-ccc-chapter.tex) ([pdf](x86-32bit-ccc-chapter.pdf)): This file includes x86-32bit-ccc.tex, and allows that content to be created into a stand-alone PDF of the x86 calling convention content.
- [x86-32bit/](x86-32bit/): The directory that contains the various source code files and images used in the 32 bit x86 chapters.


#### x86 (64 bit) files

- [x86-64bit.tex](x86-64bit.tex): The introduction of the 64 bit x86 assembly instruction set; this is the actual content, and this file cannot be LaTeX'ed directly.
- [x86-64bit-ccc.tex](x86-64bit-ccc.tex): The C calling convention for 64 bit x86 assembly; this is the actual content, and this file cannot be LaTeX'ed directly.
- [x86-64bit-asm-chapter.tex](x86-64bit-asm-chapter.tex) ([pdf](x86-64bit-asm-chapter.pdf)): This file includes x86-64bit.tex, and allows that content to be created into a stand-alone PDF of the x86 introduction content.
- [x86-64bit-ccc-chapter.tex](x86-64bit-ccc-chapter.tex) ([pdf](x86-64bit-ccc-chapter.pdf)): This file includes x86-64bit-ccc.tex, and allows that content to be created into a stand-alone PDF of the x86 calling convention content.
- [x86-64bit/](x86-64bit/): The directory that contains the various source code files and images used in the 32 bit x86 chapters.


#### Common files

- [macros.tex](macros.tex): A number of LaTeX macros used throughout the files herein.
- [main.tex](main.tex) ([pdf](main.pdf)): The full book, which has spaces for each chapter.  As mentioned above, only a few chapters (IBCM and the x86 chapters) are anywhere near complete.
- [Makefile](Makefile): A series of targets to automate the building of the PDF documents in this book.
- [references.bib](references.bib): All the references used throughout in the book.
- [working.tex](working.tex): This is meant to allow LaTeX to be run on the individual chapter(s) that are being worked on, without having to recompile the entire book.
