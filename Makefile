markdown:
	@echo Converting markdown files to html format...
	@chmod 755 utils/convert-markdown-to-html.sh
	@utils/convert-markdown-to-html.sh
	@git checkout uva/old/*.html
	@echo done!

all: markdown format highlight

format:
	@echo Formatting source files...
	@chmod 755 utils/format-source-files.sh
	@utils/format-source-files.sh
	@git checkout uva/old/*.html
	@echo done!

highlight:
	@echo Highlighting source files...
	@chmod 755 utils/highlight-source-files.sh
	@utils/highlight-source-files.sh
	@git checkout uva/old/*.html
	@echo done!

clean:
	/bin/rm -rf *~ */*~ */*/*~ */*/*/*~
	/bin/rm -f uva/*.aux uva/*.log
