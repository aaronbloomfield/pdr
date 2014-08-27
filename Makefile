markdown:
	@echo Converting markdown files to html format...
	@chmod 755 utils/convert-markdown-to-html
	@utils/convert-markdown-to-html
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~ */*/*/*~
	/bin/rm -f cs2150/*.aux cs2150/*.log

