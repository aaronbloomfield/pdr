main:
	@echo You should read the readme.txt file!

compile:
	gcc -o test_abs_c test_abs_c.c
	g++ -o test_abs test_abs.cpp
	g++ -o test_fib test_fib.cpp
	g++ -o test_max test_max.cpp
	g++ -o test_string_compare test_string_compare.cpp

asm:
	g++ -m32 -masm=intel -S test_abs_c.c -o test_abs_c.s
	g++ -m32 -masm=intel -S test_abs.cpp -o test_abs.s
	g++ -m32 -masm=intel -S test_fib.cpp -o test_fib.s
	g++ -m32 -masm=intel -S test_string_compare.cpp -o test_string_compare.s
	g++ -m32 -masm=intel -S test_max.cpp -o test_max.s
	g++ -O2 -m32 -masm=intel -S test_max.cpp -o test_max-O2.s
	grep -v extern test_max.cpp > foo.cpp
	g++ -m32 -masm=intel -S foo.cpp -o test_max-noextern.s
	/bin/rm -rf foo.cpp

asmclang:
	clang -m32 -mllvm --x86-asm-syntax=intel -S test_abs_c.c -o test_abs_c.s
	clang++ -m32 -S test_abs.cpp -o test_abs-non-intel.s
	clang++ -m32 -mllvm --x86-asm-syntax=intel -S test_abs.cpp -o test_abs.s
	clang++ -m32 -mllvm --x86-asm-syntax=intel -S test_fib.cpp -o test_fib.s
	clang++ -m32 -mllvm --x86-asm-syntax=intel -S test_string_compare.cpp -o test_string_compare.s
	clang++ -m32 -mllvm --x86-asm-syntax=intel -S test_max.cpp -o test_max.s
	clang++ -O2 -m32 -mllvm --x86-asm-syntax=intel -S test_max.cpp -o test_max-O2.s
	grep -v extern test_max.cpp > foo.cpp
	clang++ -m32 -mllvm --x86-asm-syntax=intel -S foo.cpp -o test_max-noextern.s
	/bin/rm -rf foo.cpp

clean:
	/bin/rm -f test_abs_c test_abs_c.exe test_fib test_fib.exe test_max \
		test_max.exe test_string_compare test_string_compare.exe \
		test_abs test_abs.exe

asmclean:
	/bin/rm -f *.s
