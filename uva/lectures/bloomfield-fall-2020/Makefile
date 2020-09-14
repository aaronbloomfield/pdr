default:
	make -C ../../..

clean:
	/bin/rm -f *~ */*~ */a.out

code:
	@astyle --style=attach --indent=spaces=4 --indent-switches \
		--suffix=none --formatted */*.cpp */*.h
	@source-highlight -d */*.cpp */*.h

markdown:
	@make clean
	@make code
	@for dir in `ls | sort -r | grep lec`; do \
		title=`echo $$dir | sed s/lec/Lecture\ /g | sed s/Lecture\ 0/Lecture\ /g`; \
		/bin/echo "- $$title: (date)"; \
		for file in `ls $$dir/ | grep -v html | grep -v svg`; do \
			/bin/echo "    - [$$file]($$dir/$$file.html) ([raw code]($$dir/$$file))" ; \
		done ; \
		if [ -e "$$dir/$$dir.svg" ] ; then \
			/bin/echo "    - [sketched image]($$dir/$$dir.svg)" ; \
		fi ; \
	done
