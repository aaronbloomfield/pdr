CXX = clang++ -Wall -Wno-unused-private-field
OFILES = List.o ListItr.o ListNode.o ListTest.o

.PHONY: clean

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~ a.out

# output from `clang++ -MM *.cpp`
List.o: List.cpp List.h ListNode.h ListItr.h
ListItr.o: ListItr.cpp ListItr.h ListNode.h List.h
ListNode.o: ListNode.cpp ListNode.h
ListTest.o: ListTest.cpp List.h ListNode.h ListItr.h
