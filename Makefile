markdown:
	@echo Converting markdown files to html format...
	@chmod 755 utils/convert-markdown-to-html
	@utils/convert-markdown-to-html
	@git checkout uva/old/*.html
	@echo done!

highlight:
	@echo Highlighting source files...
	@chmod 755 utils/highlight-source-files
	@utils/highlight-source-files
	@git checkout uva/old/*.html
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~ */*/*/*~
	/bin/rm -f uva/*.aux uva/*.log
