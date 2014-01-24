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

clean:
	/bin/rm -f *.log *.aux *.out *~

fullclean:
	/bin/rm -f *.log *.aux *.out *.toc *.lof *.lol *.lot main.pdf part.pdf working.pdf *.bbl *.blg *~
