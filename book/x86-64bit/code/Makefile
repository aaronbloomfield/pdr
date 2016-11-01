return2:
	nasm -felf -o return2.o return2.s
	clang++ -m32 -c calling-return2.cpp
	clang++ -m32 calling-return2.o return2.o -o return2

myfunc:
	nasm -felf -o callee-example-1.o callee-example-1.s
	clang++ -m32 -c callee-example-main.cpp
	clang++ -m32 callee-example-main.o callee-example-1.o -o myfunc

clean:
	/bin/rm -f *.o

fullclean:
	/bin/rm -f *.o
	/bin/rm -f return2 myfunc
