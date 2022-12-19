ASTYLEOPTS	= --align-pointer=type --align-reference=type --pad-oper \
		  --remove-braces --style=attach --indent=spaces=4 \
		  --pad-paren-out --indent-switches --suffix=none --formatted 

default:
	make -C ../../..

clean:
	/bin/rm -f *~ */*~ */a.out

code:
	@astyle $(ASTYLEOPTS) */*.cpp */*.h
	@source-highlight -d */*.cpp */*.h */*.s */Makefile

markdown:
	@make clean
	@make code
	@for dir in `ls | sort | grep lec`; do \
		title=`echo $$dir | sed s/lec/Lecture\ /g | sed s/Lecture\ 0/Lecture\ /g`; \
		/bin/echo "- $$title: (date)"; \
		for file in `ls $$dir/ | grep -v html | grep -v svg`; do \
			/bin/echo "    - [$$file]($$dir/$$file.html) ([raw code]($$dir/$$file))" ; \
		done ; \
		for file in `ls */*.svg | grep $$dir`; do \
			/bin/echo "    - [sketched image]($$file)" ; \
		done ; \
	done
