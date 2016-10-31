Program and Data Representation: Slides
=======================================

[Go up to the main README file](../README.html) ([md](../README.md))

[Course Introduction](../uva/course-introduction.html#/) **(CS 2150 specific)**

- Source code: [DataStructureComparison.java](../uva/code/introduction/DataStructureComparison.java.html) ([src](../uva/code/introduction/DataStructureComparison.java))


[Slide set 1: C++](01-cpp.html#/)

- Source code:
    - General source code: [evenodd.cpp](code/01-cpp/evenodd.cpp.html) ([src](code/01-cpp/evenodd.cpp)), [pointers.cpp](code/01-cpp/pointers.cpp.html) ([src](code/01-cpp/pointers.cpp)), [swap.cpp](code/01-cpp/swap.cpp.html) ([src](code/01-cpp/swap.cpp)), [dynamic_allocation.cpp](code/01-cpp/dynamic_allocation.cpp.html) ([src](code/01-cpp/dynamic_allocation.cpp)), [delete.cpp](code/01-cpp/delete.cpp.html) ([src](code/01-cpp/delete.cpp)), [memory.cpp](code/01-cpp/memory.cpp.html) ([src](code/01-cpp/memory.cpp)), [swapref.cpp](code/01-cpp/swapref.cpp.html) ([src](code/01-cpp/swapref.cpp)), [cpptest.cpp](code/01-cpp/cpptest.cpp.html) ([src](code/01-cpp/cpptest.cpp))
    - IntCell code: [IntCell.java](code/01-cpp/IntCell.java.html) ([src](code/01-cpp/IntCell.java)), [TestIntCell.cpp](code/01-cpp/TestIntCell.cpp.html) ([src](code/01-cpp/TestIntCell.cpp)), [IntCell.h](code/01-cpp/IntCell.h.html) ([src](code/01-cpp/IntCell.h)), [IntCell.cpp](code/01-cpp/IntCell.cpp.html) ([src](code/01-cpp/IntCell.cpp))
    - Rational code: [Rational.java](code/01-cpp/Rational.java.html) ([src](code/01-cpp/Rational.java)), [Rational.h](code/01-cpp/Rational.h.html) ([src](code/01-cpp/Rational.h)), [Rational.cpp](code/01-cpp/Rational.cpp.html) ([src](code/01-cpp/Rational.cpp)), [TestRational.cpp](code/01-cpp/TestRational.cpp.html) ([src](code/01-cpp/TestRational.cpp))

[Slide set 2: Lists](02-lists.html#/)

- Source code: [findMax.cpp](code/02-lists/findMax.cpp.html) ([src](code/02-lists/findMax.cpp)), [objectCell.h](code/02-lists/objectCell.h.html) ([src](code/02-lists/objectCell.h)), [objectCellMain.cpp](code/02-lists/objectCellMain.cpp.html) ([src](code/02-lists/objectCellMain.cpp))

[Slide set 3: Numbers](03-numbers.html#/)

- Source code: [float_to_hex.cpp](code/03-numbers/float_to_hex.cpp.html) ([src](code/03-numbers/float_to_hex.cpp)), [FloatTest.java](code/03-numbers/FloatTest.java.html) ([src](code/03-numbers/FloatTest.java))

[Slide set 4: Arrays & Big-Oh](04-arrays-bigoh.html#/)

- Source code: [cmdlineparams.cpp](code/04-arrays-bigoh/cmdlineparams.cpp.html) ([src](code/04-arrays-bigoh/cmdlineparams.cpp))

[Slide set 5: Trees](05-trees.html#/)

- The trees diagrams were generated from the files described [here](graphs/index.html)
- The tree animation site is [here](http://www.qmatica.com/DataStructures/Trees/BST.html) ([mirror](http://webdiis.unizar.es/asignaturas/EDA/AVLTree/avltree.html))

[Slide set 6: Hashes](06-hashes.html#/)

- The hash table bucket signs as both a [pdf](misc/hash-table-buckets.pdf) and an [odt](misc/hash-table-buckets.odt)

[Slide set 7: IBCM (machine language)](07-ibcm.html#/)

- The online simulator is [here](http://www.cs.virginia.edu/~cs216/ibcm/) (with mirrors [1](http://pegasus.cs.virginia.edu/ibcm/) and [2](http://people.virginia.edu/~asb2t/ibcm/))
- Source code: [summation.ibcm](../ibcm/summation.ibcm), [array-summation.ibcm](../ibcm/array-summation.ibcm)
- [IBCM book chapter](../book/ibcm-chapter.pdf) as the reading
- There is a separate [IBCM section](../ibcm/index.html) of this repository with more IBCM information, although that additional information will not be needed in this course

Slide set 8: assembly language: in 32 bit and 64 bit flavors

- 64 bit materials: [64 bit assembly slides](08-assembly-64bit.html#/)
    - The x86 book chapters on [x86](../book/x86-64bit-asm-chapter.pdf) and the [C calling convention](../book/x86-64bit-ccc-chapter.pdf) as the reading
        - Another good reading document is the [x86-64 Machine-Level Programming document](https://www.cs.cmu.edu/~fp/courses/15213-s07/misc/asm64-handout.pdf) from CMU, although they use the other assembly language format
    - Source code
        - The generated assembly was generated using `make asm`, which uses gcc/g++; to generate it using clang/clang++, use the 'asmclang' target
        - [Makefile](code/08-assembly-64bit/Makefile.html) ([src](code/08-assembly-64bit/Makefile))
        - Absolute value example: [test_abs.cpp](code/08-assembly-64bit/test_abs.cpp.html) ([src](code/08-assembly-64bit/test_abs.cpp)), [test_abs_c.c](code/08-assembly-64bit/test_abs_c.c.html) ([src](code/08-assembly-64bit/test_abs_c.c)), [test_abs.s](code/08-assembly-64bit/test_abs.s.html) ([src](code/08-assembly-64bit/test_abs.s)), [test_abs_c.s](code/08-assembly-64bit/test_abs_c.s.html) ([src](code/08-assembly-64bit/test_abs_c.s)), [test_abs-non-intel.s](code/08-assembly-64bit/test_abs-non-intel.s.html) ([src](code/08-assembly-64bit/test_abs-non-intel.s))
        - Fibonacci example: [test_fib.cpp](code/08-assembly-64bit/test_fib.cpp.html) ([src](code/08-assembly-64bit/test_fib.cpp)), [test_fib.s](code/08-assembly-64bit/test_fib.s.html) ([src](code/08-assembly-64bit/test_fib.s))
        - Max example: [test_max.cpp](code/08-assembly-64bit/test_max.cpp.html) ([src](code/08-assembly-64bit/test_max.cpp)), [test_max.s](code/08-assembly-64bit/test_max.s.html) ([src](code/08-assembly-64bit/test_max.s)), [test_max-O2.s](code/08-assembly-64bit/test_max-O2.s.html) ([src](code/08-assembly-64bit/test_max-O2.s)), [test_max-noextern.s](code/08-assembly-64bit/test_max-noextern.s.html) ([src](code/08-assembly-64bit/test_max-noextern.s))
        - String compare example: [test_string_compare.cpp](code/08-assembly-64bit/test_string_compare.cpp.html) ([src](code/08-assembly-64bit/test_string_compare.cpp)), [test_string_compare.s](code/08-assembly-64bit/test_string_compare.s.html) ([src](code/08-assembly-64bit/test_string_compare.s))
    - The tutorial for [lab 8](../labs/lab08/index.html) ([md](../labs/lab08/index.md))
       - Tutorial 8 is nasm, which consists of two PDF book chapters that are contained in this repository: [x86 Assembly](../book/x86-32bit-asm-chapter.pdf) and [The x86 C Calling Convention](../book/x86-32bit-ccc-chapter.pdf); the contain more examples of assembly code
        - You can skip a few of the sections (feel free to look at them if interested, but they are not needed): Floating Point Instructions, SIMD Parallelism, Saturated Arithmetic, and Graphics.
- ~~32 bit materials: [32 bit assembly slides](08-assembly-32bit.html#/)~~
    - ~~The x86 book chapters on [x86](../book/x86-32bit-asm-chapter.pdf) and the [C calling convention](../book/x86-32bit-ccc-chapter.pdf) as the reading~~
    - ~~Source code~~
        - ~~The generated assembly was generated using `make asm`, which uses gcc/g++; to generate it using clang/clang++, use the 'asmclang' target~~
        - ~~[Makefile](code/08-assembly-32bit/Makefile.html) ([src](code/08-assembly-32bit/Makefile))~~
        - ~~Absolute value example: [test_abs.cpp](code/08-assembly-32bit/test_abs.cpp.html) ([src](code/08-assembly-32bit/test_abs.cpp)), [test_abs_c.c](code/08-assembly-32bit/test_abs_c.c.html) ([src](code/08-assembly-32bit/test_abs_c.c)), [test_abs.s](code/08-assembly-32bit/test_abs.s.html) ([src](code/08-assembly-32bit/test_abs.s)), [test_abs_c.s](code/08-assembly-32bit/test_abs_c.s.html) ([src](code/08-assembly-32bit/test_abs_c.s)), [test_abs-non-intel.s](code/08-assembly-32bit/test_abs-non-intel.s.html) ([src](code/08-assembly-32bit/test_abs-non-intel.s))~~
        - ~~Fibonacci example: [test_fib.cpp](code/08-assembly-32bit/test_fib.cpp.html) ([src](code/08-assembly-32bit/test_fib.cpp)), [test_fib.s](code/08-assembly-32bit/test_fib.s.html) ([src](code/08-assembly-32bit/test_fib.s))~~
        - ~~Max example: [test_max.cpp](code/08-assembly-32bit/test_max.cpp.html) ([src](code/08-assembly-32bit/test_max.cpp)), [test_max.s](code/08-assembly-32bit/test_max.s.html) ([src](code/08-assembly-32bit/test_max.s)), [test_max-O2.s](code/08-assembly-32bit/test_max-O2.s.html) ([src](code/08-assembly-32bit/test_max-O2.s)), [test_max-noextern.s](code/08-assembly-32bit/test_max-noextern.s.html) ([src](code/08-assembly-32bit/test_max-noextern.s))~~
        - ~~String compare example: [test_string_compare.cpp](code/08-assembly-32bit/test_string_compare.cpp.html) ([src](code/08-assembly-32bit/test_string_compare.cpp)), [test_string_compare.s](code/08-assembly-32bit/test_string_compare.s.html) ([src](code/08-assembly-32bit/test_string_compare.s))~~
    - ~~The tutorial for [lab 8](../labs/lab08/index.html) ([md](../labs/lab08/index.md))~~
       - ~~Tutorial 8 is nasm, which consists of two PDF book chapters that are contained in this repository: [x86 Assembly](../book/x86-32bit-asm-chapter.pdf) and [The x86 C Calling Convention](../book/x86-32bit-ccc-chapter.pdf); the contain more examples of assembly code~~
        - ~~You can skip a few of the sections (feel free to look at them if interested, but they are not needed): Floating Point Instructions, SIMD Parallelism, Saturated Arithmetic, and Graphics.~~


[Slide set 9: Advanced C++](09-advanced-cpp.html#/)

- Source code: [name-contact.cpp](code/09-advanced-cpp/name-contact.cpp.html) ([src](code/09-advanced-cpp/name-contact.cpp))

[Slide set 10: Heaps and Huffman coding](10-heaps-huffman.html#/)

- Source code: [binary_heap.cpp](code/10-heaps-huffman/binary_heap.cpp.html) ([src](code/10-heaps-huffman/binary_heap.cpp)), [binary_heap.h](code/10-heaps-huffman/binary_heap.h.html) ([src](code/10-heaps-huffman/binary_heap.h)), [heap-test.cpp](code/10-heaps-huffman/heap-test.cpp.html) ([src](code/10-heaps-huffman/heap-test.cpp))

[Slide set 11: Graphs](11-graphs.html#/)

[Slide set 12: Memory](12-memory.html#/)

- Source code: [cache.cpp](code/12-memory/cache.cpp.html) ([src](code/12-memory/cache.cpp)), [strings.c](code/12-memory/strings.c.html) ([src](code/12-memory/strings.c))

[Slide set 13: Esoteric Programming Languages](13-esoteric-pls.html#/)

[Course Conclusion](../uva/course-conclusion.html#/) **(CS 2150 specific)**
