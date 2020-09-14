default:
	make -C ../../..

clean:
	/bin/rm -f *~ */*~ */a.out

code:
	@astyle --style=attach --indent=spaces=4 --indent-switches \
		--suffix=none --formatted */*.cpp */*.h
	@source-highlight -d */*.cpp */*.h

markdown:
	for dir in `ls | sort -r | grep lec`; do \
		title=`echo $$dir | sed s/lec/Lecture\ /g | sed s/Lecture\ 0/Lecture\ /g`; \
		/bin/echo "- $$title: (date)"; \
		for file in `ls $$dir/ | grep -v html`; do \
			/bin/echo "    - [$$file]($$dir/$$file.html) ([raw code]($$dir/$$file))" ; \
		done ; \
	done
