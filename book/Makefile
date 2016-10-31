.PHONY:	ibcm x86

pdf:
	pdflatex main.tex
	pdflatex main.tex

full:
	pdflatex main.tex
	bibtex main
	pdflatex main.tex
	pdflatex main.tex

working:
	pdflatex working.tex
	bibtex working
	pdflatex working.tex
	pdflatex working.tex

ibcm:	ibcm-chapter.tex ibcm.tex
	pdflatex ibcm-chapter.tex
	bibtex ibcm-chapter
	pdflatex ibcm-chapter.tex
	pdflatex ibcm-chapter.tex

x86:	x86-32bit-asm-chapter.tex x86-32bit-ccc-chapter.tex x86-32bit.tex x86-32bit-ccc.tex
	pdflatex x86-32bit-asm-chapter.tex
	pdflatex x86-32bit-asm-chapter.tex
	pdflatex x86-32bit-ccc-chapter.tex
	pdflatex x86-32bit-ccc-chapter.tex

clean:
	/bin/rm -f *.log *.aux *.out *~

fullclean:
	/bin/rm -f *.log *.aux *.out *.toc *.lof *.lol *.lot *.bbl *.blg main.pdf part.pdf working.pdf *.bbl *.blg *~
