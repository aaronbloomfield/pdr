markdown:
	@echo Converting .md files to .html...
	@ls *.md | sed s/.md//g | grep -v reveal.js | awk '{print "pandoc -f markdown -c markdown.css -t html -o "$$1".html " $$1".md"}' | bash
	@ls */*.md | sed s/.md//g | grep -v reveal.js | awk '{print "pandoc -f markdown -c ../markdown.css -t html -o "$$1".html " $$1".md"}' | bash
	@ls */*/*.md | sed s/.md//g | grep -v reveal.js | awk '{print "pandoc -f markdown -c ../../markdown.css -t html -o "$$1".html " $$1".md"}' | bash
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~ */*/*/*~
