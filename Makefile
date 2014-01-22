markdown:
	@echo Converting .md files to .html...
	@ls *.md | sed s/.md//g | grep -v reveal.js | awk '{print "utils/markdown -css markdown.css "$$1".md > "$$1".html"}' | bash
	@ls */*.md | sed s/.md//g | grep -v reveal.js | awk '{print "utils/markdown -css ../markdown.css "$$1".md > "$$1".html"}' | bash
	@ls */*/*.md | sed s/.md//g | grep -v reveal.js | awk '{print "utils/markdown -css ../../markdown.css "$$1".md > "$$1".html"}' | bash
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~
