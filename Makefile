markdown:
	find . | grep '.md$$' | sed s/.md//g | grep -v reveal.js | awk '{print "utils/markdown "$$1".md > "$$1".html"}' | bash

clean:
	/bin/rm -rf *~ */*~ */*/*~
