Program and Data Representation: Slides
=======================================

[Go up to the main README file](../README.html)

[Slide set 1: Course Introduction](01-intro.html)

- Source code: [DataStructureComparison.java](code/01-intro/DataStructureComparison.java.html) ([src](code/01-intro/DataStructureComparison.java))


[Slide set 2: C++](02-cpp.html)

- Source code:
  - General source code: [evenodd.cpp](code/02-cpp/evenodd.cpp.html) ([src](code/02-cpp/evenodd.cpp)), [pointers.cpp](code/02-cpp/pointers.cpp.html) ([src](code/02-cpp/pointers.cpp)), [swap.cpp](code/02-cpp/swap.cpp.html) ([src](code/02-cpp/swap.cpp)), [dynamic_allocation.cpp](code/02-cpp/dynamic_allocation.cpp.html) ([src](code/02-cpp/dynamic_allocation.cpp)), [delete.cpp](code/02-cpp/delete.cpp.html) ([src](code/02-cpp/delete.cpp)), [memory.cpp](code/02-cpp/memory.cpp.html) ([src](code/02-cpp/memory.cpp)), [swapref.cpp](code/02-cpp/swapref.cpp.html) ([src](code/02-cpp/swapref.cpp)), [cpptest.cpp](code/02-cpp/cpptest.cpp.html) ([src](code/02-cpp/cpptest.cpp))
  - IntCell code: [IntCell.java](code/02-cpp/IntCell.java.html) ([src](code/02-cpp/IntCell.java)), [TestIntCell.cpp](code/02-cpp/TestIntCell.cpp.html) ([src](code/02-cpp/TestIntCell.cpp)), [IntCell.h](code/02-cpp/IntCell.h.html) ([src](code/02-cpp/IntCell.h)), [IntCell.cpp](code/02-cpp/IntCell.cpp.html) ([src](code/02-cpp/IntCell.cpp))
  - Rational code: [Rational.java](code/02-cpp/Rational.java.html) ([src](code/02-cpp/Rational.java)), [Rational.h](code/02-cpp/Rational.h.html) ([src](code/02-cpp/Rational.h)), [Rational.cpp](code/02-cpp/Rational.cpp.html) ([src](code/02-cpp/Rational.cpp)), [TestRational.cpp](code/02-cpp/TestRational.cpp.html) ([src](code/02-cpp/TestRational.cpp))

[Slide set 3: Lists](03-lists.html)

- Source code: [findMax.cpp](code/03-lists/findMax.cpp.html) ([src](code/03-lists/findMax.cpp)), [objectCell.h](code/03-lists/objectCell.h.html) ([src](code/03-lists/objectCell.h)), [objectCellMain.cpp](code/03-lists/objectCellMain.cpp.html) ([src](code/03-lists/objectCellMain.cpp))

[Slide set 4: Numbers](04-numbers.html)

- Source code: [float_to_hex.cpp](code/04-numbers/float_to_hex.cpp.html) ([src](code/04-numbers/float_to_hex.cpp)), [FloatTest.java](code/04-numbers/FloatTest.java.html) ([src](code/04-numbers/FloatTest.java))

[Slide set 5: Arrays & Big-Oh](05-arrays-bigoh.html)

- Source code: [cmdlineparams.cpp](code/05-arrays-bigoh/cmdlineparams.cpp.html) ([src](code/05-arrays-bigoh/cmdlineparams.cpp))

[Slide set 6: Trees](06-trees.html)

- The trees diagrams were generated from the files described [here](graphs/index.html)
- The tree animation site is [here](http://www.qmatica.com/DataStructures/Trees/BST.html) ([mirror](http://webdiis.unizar.es/asignaturas/EDA/AVLTree/avltree.html))

[Slide set 7: Hashes](07-hashes.html)

- The hash table bucket signs as both a [pdf](misc/hash-table-buckets.pdf) and an [odt](misc/hash-table-buckets.odt)

[Slide set 8: IBCM (machine language)](08-ibcm.html)

- The online simulator is [here](http://www.cs.virginia.edu/~cs216/ibcm/) (with mirrors [1](http://libra.cs.virginia.edu/ibcm/) and [2](http://people.virginia.edu/~asb2t/ibcm/))
- Source code: [summation.ibcm](../ibcm/summation.ibcm), [array-summation.ibcm](../ibcm/array-summation.ibcm)
- [IBCM book chapter](../book/ibcm-chapter.pdf) as the reading
- There is a separate [IBCM section](../ibcm/index.html) of this repository with more IBCM information, although that additional information will not be needed in this course

[Slide set 9: x86 (assembly language)](09-x86.html)

- [x86 book chapter](../book/x86-chapter.pdf) as the reading
- Source code
  - [Makefile](code/09-x86/Makefile.html) ([src](code/09-x86/Makefile))
  - Absolute value example: [test_abs.cpp](code/09-x86/test_abs.cpp.html) ([src](code/09-x86/test_abs.cpp)), [test_abs_c.c](code/09-x86/test_abs_c.c.html) ([src](code/09-x86/test_abs_c.c)), [test_abs.s](code/09-x86/test_abs.s.html) ([src](code/09-x86/test_abs.s)), [test_abs_c.s](code/09-x86/test_abs_c.s.html) ([src](code/09-x86/test_abs_c.s)), [test_abs-non-intel.s](code/09-x86/test_abs-non-intel.s.html) ([src](code/09-x86/test_abs-non-intel.s))
  - Fibonacci example: [test_fib.cpp](code/09-x86/test_fib.cpp.html) ([src](code/09-x86/test_fib.cpp)), [test_fib.s](code/09-x86/test_fib.s.html) ([src](code/09-x86/test_fib.s))
  - Max example: [test_max.cpp](code/09-x86/test_max.cpp.html) ([src](code/09-x86/test_max.cpp)), [test_max.s](code/09-x86/test_max.s.html) ([src](code/09-x86/test_max.s)), [test_max-O2.s](code/09-x86/test_max-O2.s.html) ([src](code/09-x86/test_max-O2.s)), [test_max-noextern.s](code/09-x86/test_max-noextern.s.html) ([src](code/09-x86/test_max-noextern.s))
  - String compare example: [test_string_compare.cpp](code/09-x86/test_string_compare.cpp.html) ([src](code/09-x86/test_string_compare.cpp)), [test_string_compare.s](code/09-x86/test_string_compare.s.html) ([src](code/09-x86/test_string_compare.s))
- The tutorial for [lab 8](../labs/lab08/index.html) is the online [nasm tutorial](http://cs.lmu.edu/~ray/notes/nasmexamples/), which has more examples of assembly code
  - You can skip a few of the sections (feel free to look at them if interested, but they are not needed): Floating Point Instructions, SIMD Parallelism, Saturated Arithmetic, and Graphics.


[Slide set 10: Advanced C++](10-advanced-cpp.html)

- Source code: [name-contact.cpp](code/10-advanced-cpp/name-contact.cpp.html) ([src](code/10-advanced-cpp/name-contact.cpp))

Slide set 11: Heaps

Slide set 12: Huffman coding

Slide set 13: Graphs

Slide set 14: Memory
