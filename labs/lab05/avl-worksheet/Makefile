graphs:
	@echo Making all graphs into .svg files...
	@ls *.dot | sed s/.dot//g | awk '{print "dot -Tpdf "$$1".dot -o "$$1".pdf"}' | bash
	pdflatex avl-worksheet.tex

clean:
	/bin/rm -f *~ *.log *.aux
