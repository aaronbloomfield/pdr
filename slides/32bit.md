32-bit Assembly Materials
=========================

The assembly materials in this repo used to be taught in 32-bit assembly.  This is not used anymore (we use 64-bit), but it is included here for historical purposes.

- 32 bit materials: [32 bit assembly slides](08-assembly-32bit.html#/)
    - The x86 book chapters on [x86](../book/x86-32bit-asm-chapter.pdf) and the [C calling convention](../book/x86-32bit-ccc-chapter.pdf) as the reading
    - Source code
        - The generated assembly was generated using `make asm`, which uses gcc/g++; to generate it using clang/clang++, use the 'asmclang' target
        - [Makefile](code/08-assembly-32bit/Makefile.html) ([src](code/08-assembly-32bit/Makefile))
        - Absolute value example: [test_abs.cpp](code/08-assembly-32bit/test_abs.cpp.html) ([src](code/08-assembly-32bit/test_abs.cpp)), [test_abs_c.c](code/08-assembly-32bit/test_abs_c.c.html) ([src](code/08-assembly-32bit/test_abs_c.c)), [test_abs.s](code/08-assembly-32bit/test_abs.s.html) ([src](code/08-assembly-32bit/test_abs.s)), [test_abs_c.s](code/08-assembly-32bit/test_abs_c.s.html) ([src](code/08-assembly-32bit/test_abs_c.s)), [test_abs-non-intel.s](code/08-assembly-32bit/test_abs-non-intel.s.html) ([src](code/08-assembly-32bit/test_abs-non-intel.s))
        - Fibonacci example: [test_fib.cpp](code/08-assembly-32bit/test_fib.cpp.html) ([src](code/08-assembly-32bit/test_fib.cpp)), [test_fib.s](code/08-assembly-32bit/test_fib.s.html) ([src](code/08-assembly-32bit/test_fib.s))
        - Max example: [test_max.cpp](code/08-assembly-32bit/test_max.cpp.html) ([src](code/08-assembly-32bit/test_max.cpp)), [test_max.s](code/08-assembly-32bit/test_max.s.html) ([src](code/08-assembly-32bit/test_max.s)), [test_max-O2.s](code/08-assembly-32bit/test_max-O2.s.html) ([src](code/08-assembly-32bit/test_max-O2.s)), [test_max-noextern.s](code/08-assembly-32bit/test_max-noextern.s.html) ([src](code/08-assembly-32bit/test_max-noextern.s))
        - String compare example: [test_string_compare.cpp](code/08-assembly-32bit/test_string_compare.cpp.html) ([src](code/08-assembly-32bit/test_string_compare.cpp)), [test_string_compare.s](code/08-assembly-32bit/test_string_compare.s.html) ([src](code/08-assembly-32bit/test_string_compare.s))
    - The tutorial for [lab 8](../labs/lab08/index.html) ([md](../labs/lab08/index.md))
       - Tutorial 8 is nasm, which consists of two PDF book chapters that are contained in this repository: [x86 Assembly](../book/x86-32bit-asm-chapter.pdf) and [The x86 C Calling Convention](../book/x86-32bit-ccc-chapter.pdf); the contain more examples of assembly code
        - You can skip a few of the sections (feel free to look at them if interested, but they are not needed): Floating Point Instructions, SIMD Parallelism, Saturated Arithmetic, and Graphics.
