graphs:
	@echo Making all graphs into .svg files...
	@ls *.dot | grep -v Red-black | grep -v graph | sed s/.dot//g | awk '{print "dot -Tsvg "$$1".dot -o "$$1".svg"}' | bash
	@ls *.dot | grep -v Red-black | grep -v graph | sed s/.dot//g | awk '{print "dot -Tps "$$1".dot -o "$$1".ps"}' | bash
	@ls *.dot | grep -v Red-black | grep -v graph | sed s/.dot//g | awk '{print "dot -Tpng "$$1".dot -o "$$1".png"}' | bash
	@ls *.dot | grep Red-black | sed s/.dot//g | awk '{print "dot -Tsvg -Kneato "$$1".dot -o "$$1".svg"}' | bash
	@ls *.dot | grep Red-black | sed s/.dot//g | awk '{print "dot -Tps -Kneato "$$1".dot -o "$$1".ps"}' | bash
	@ls *.dot | grep Red-black | sed s/.dot//g | awk '{print "dot -Tpng -Kneato "$$1".dot -o "$$1".png"}' | bash
	@ls graph-*.dot | sed s/.dot//g | awk '{print "dot -Tsvg -Kneato "$$1".dot -o "$$1".svg"}' | bash
	@ls graph-*.dot | sed s/.dot//g | awk '{print "dot -Tps -Kneato "$$1".dot -o "$$1".ps"}' | bash
	@ls graph-*.dot | sed s/.dot//g | awk '{print "dot -Tpng -Kneato "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[56].dot | sed s/.dot//g | awk '{print "dot -Tsvg "$$1".dot -o "$$1".svg"}' | bash
	@ls graph-[56].dot | sed s/.dot//g | awk '{print "dot -Tps "$$1".dot -o "$$1".ps"}' | bash
	@ls graph-[56].dot | sed s/.dot//g | awk '{print "dot -Tpng "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[4].dot | sed s/.dot//g | awk '{print "dot -Tsvg -Kneato -Gstart=5 "$$1".dot -o "$$1".svg"}' | bash
	@ls graph-[4].dot | sed s/.dot//g | awk '{print "dot -Tps -Kneato -Gstart=5 "$$1".dot -o "$$1".ps"}' | bash
	@ls graph-[4].dot | sed s/.dot//g | awk '{print "dot -Tpng -Kneato -Gstart=5 "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[8].dot graph-13?.dot | sed s/.dot//g | awk '{print "dot -Tsvg -Kfdp "$$1".dot -o "$$1".svg"}' | bash
	@ls graph-[8].dot graph-13?.dot | sed s/.dot//g | awk '{print "dot -Tps -Kfdp "$$1".dot -o "$$1".ps"}' | bash
	@ls graph-[8].dot graph-13?.dot | sed s/.dot//g | awk '{print "dot -Tpng -Kfdp "$$1".dot -o "$$1".png"}' | bash

graphpngs:
	@ls graph-*.dot | sed s/.dot//g | awk '{print "dot -Tpng -Kneato "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[56].dot | sed s/.dot//g | awk '{print "dot -Tpng "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[4].dot | sed s/.dot//g | awk '{print "dot -Tpng -Kneato -Gstart=5 "$$1".dot -o "$$1".png"}' | bash
	@ls graph-[8].dot graph-13?.dot | sed s/.dot//g | awk '{print "dot -Tpng -Kfdp "$$1".dot -o "$$1".png"}' | bash

markdown:
	@ls *.svg | awk '{print "["$$1"]("$$1"), "}'

clean:
	/bin/rm -f *.ps *.png *~
