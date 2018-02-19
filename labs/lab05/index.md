PDR: Laboratory 5: Trees
========================

[Go up to the Labs table of contents page](../index.html)

### Objective: ###

1. Learn about binary trees 
2. See tree traversals in the context of a useful application
3. Understand tree rotations
4. Evaluate the performance of binary search trees and AVL trees

### Background: ###

A binary tree is a tree with a maximum of two children per node.  Three traversals are commonly associated with binary trees. A pre-order traversal processes the given node first and then processes its left and then right subtrees.  In an in-order traversal, first the node's left subtree is processed, followed by the node itself, and finally its right subtree.  A post-order traversal operates on the left subtree, followed by the right subtree, and finally on the node itself.

### Reading(s): ###

The [Wikipedia article on Expression trees](http://en.wikipedia.org/wiki/Expression_tree), especially the [section on construction of expression trees](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree).  Also the [05: Trees](../../slides/05-trees.html) slide set.


Procedure
---------

### Pre-lab ###

1. Come to lab with a fully functional tree calculator, as described below.  
2. Read the [Wikipedia article on Expression trees](http://en.wikipedia.org/wiki/Expression_tree), especially the [section on construction of expression trees](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree).
3. Files to download: [TreeCalc.h](code/prelab/TreeCalc.h.html) ([src](code/prelab/TreeCalc.h)), [TreeCalc.cpp](code/prelab/TreeCalc.cpp.html) ([src](code/prelab/TreeCalc.cpp)), [TreeNode.h](code/prelab/TreeNode.h.html) ([src](code/prelab/TreeNode.h)), [TreeNode.cpp](code/prelab/TreeNode.cpp.html) ([src](code/prelab/TreeNode.cpp)), and  [TreeCalcTest.cpp](code/prelab/TreeCalcTest.cpp.html) ([src](code/prelab/TreeCalcTest.cpp)).  These files are contained in the prelab/ directory of the [code.zip](code.zip) file.
4. Files to submit: TreeCalc.h/cpp, TreeCalcTest.cpp, TreeNode.h/cpp

### In-lab ###

1. Complete the [AVL tree worksheet](avl-worksheet.pdf), which is a separate file.  If you complete it in lab, the TAs will collect it at the end.  Otherwise, turn in a scanned copy of the PDF electronically. **You need to turn in that sheet** (you can't write your answer on notebook paper, for example) and bubble in your ID at the bottom of the front page.  Feel free to print it single sided or double sided.  We will provide copies of this in lecture for you as well.
2. Complete the [makefile tutorial](../../tutorials/05-make/index.html).  While you will not have to write a makefile for this in-lab, you will need to know how to write on in the future -- all the following labs will be compiled via Makefiles.   There is one file that needs to be submitted from the tutorial -- you should name this file Makefile-pizza.
3. Your file **MUST** be named `Makefile-pizza` - not Makefile-pizza.txt, not Makefile-Pizza, not Makefilepizza.  If it is not named correctly, it will not work with our grading scripts, and you will not get credit for that part of the lab.
4. Files to submit: avl-worksheet.pdf (if not submitted during lab), Makefile-pizza

### Post-lab ###

1. For this lab, you will implement a Binary search tree, an AVL tree, and submit a brief lab report electronically via the submission system.
2. Your report must be in PDF format!  See the [How to convert a file to PDF](../../docs/convert_to_pdf.html) page for details.
3. Files to download: [BinarySearchTree.h](code/postlab/BinarySearchTree.h.html) ([src](code/postlab/BinarySearchTree.h)), [AVLTree.h](code/postlab/AVLTree.h.html) ([src](code/postlab/AVLTree.h)), [AVLTree.cpp](code/postlab/AVLTree.cpp.html) ([src](code/postlab/AVLTree.cpp)), [TreePathTest.cpp](code/postlab/TreePathTest.cpp.html) ([src](code/postlab/TreePathTest.cpp)), [testfile1.txt](code/postlab/testfile1.txt), [testfile2.txt](code/postlab/testfile2.txt), [testfile3.txt](code/postlab/testfile3.txt). These files are contained in the postlab/ directory of the [code.zip](code.zip) file.
4. Files to submit: AVLTree.h, BinarySearchTree.h, TreePathTest.cpp, Makefile, any other files needed to make your code compile (files such as AVLTree.cpp, BinarySearchTree.cpp, etc...), analysis.pdf (see the post-lab section for formatting details)

------------------------------------------------------------

Pre-lab
-------

For this lab you will be using a stack to help you read in a postfix expression into an expression tree.  While this is similar to lab 3, you will instead be ultimately creating a expression tree for the postfix expression, rather than evaluating it and leaving the result on the stack.  You should use the [STL stack class](http://www.cplusplus.com/reference/stack/stack/) for this lab.

Your tree calculator should read in expressions in postfix notation -- you can assume that these will be well-formed expressions as we did in lab 3.  You will need to build an expression tree using the algorithm described in the [Wikipedia article on Expression trees](http://en.wikipedia.org/wiki/Expression_tree), specifically the [section on construction of expression trees](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree).  Trees similar to this type of expression tree are used extensively in compilers.  

### Code base ###

You must use the skeleton source files provided here as a basis for your prelab.  The following guidelines apply to your implementation:

- Do NOT alter [TreeCalcTest.cpp](code/prelab/TreeCalcTest.cpp.html) ([src](code/prelab/TreeCalcTest.cpp)).  This is the testing program that we will use to run automated tests on your implementations.  Do not change it.
- In [TreeCalc.h](code/prelab/TreeCalc.h.html) ([src](code/prelab/TreeCalc.h)) and [TreeCalc.cpp](code/prelab/TreeCalc.cpp.html) ([src](code/prelab/TreeCalc.cpp)):
    - Do NOT alter the `readInput()` method.  Points will be deducted if you do so.
    - The only modification allowed in the `printOutput()` method is to add calls to your implemented `printPrefix()`, `printPostfix()`, and `printInorder()` methods 
- You should implement all the methods as listed in the class definitions for TreeCalc
- You may add additional supporting methods and data members to TreeCalc to complete your implementation.
    - Don't modify TreeNode -- note that TreeCalc is a friend of TreeNode, so you can put all your code in TreeCalc.

Note that the code will not compile out of the box -- you need to add code so that the `printOutput()` method in TreeCalc works.

You should only submit the following five files:

- [TreeCalc.h](code/prelab/TreeCalc.h.html) ([src](code/prelab/TreeCalc.h)) and [TreeCalc.cpp](code/prelab/TreeCalc.cpp.html) ([src](code/prelab/TreeCalc.cpp)), after your modifications
- The unmodified [TreeNode.h](code/prelab/TreeNode.h.html) ([src](code/prelab/TreeNode.h)) and [TreeNode.cpp](code/prelab/TreeNode.cpp.html) ([src](code/prelab/TreeNode.cpp))
- The unmodified [TreeCalcTest.cpp](code/prelab/TreeCalcTest.cpp.html) ([src](code/prelab/TreeCalcTest.cpp))

Note that the last three files should not be modified at all!  If you have additional code to include, put it in TreeCalc.cpp or TreeCalc.h (you should not need to use additional classes).  Just in case it wasn't clear yet, all your modifications should be in the TreeCalc.h and TreeCalc.cpp files.

Your fully functional tree calculator code should do the following:

1. Read user input in postfix order (assume well-formed expressions) into a stack
2. Build an expression tree using the items in the stack (see [here](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree) for the algorithm)
3. Print the resulting expression tree as a *postfix* expression in the EXACT output format as shown in the next section.  Spaces matter!
4. Print the resulting expression tree as an *infix* expression, complete with parentheses.  See the next section.  Your print method must print EXACTLY in this format, including the number and spacing of parentheses.  Spaces matter!
5. Print the resulting expression tree as a *prefix* expression.  (See next section.  Your print method must print EXACTLY this format.)  Spaces matter!
6. Calculate the result of your expression using the expression tree
7. Print the result to the screen.

Make sure your destructor works!  We will be testing that to see if there are any memory leaks.  

A few notes:

- We are not dealing with the negation operator (~) that we used in lab 3
- Your code will need to be able to handle the input of negative numbers, as shown in the example below
- To convert a C-string to an int, you will want to use `atoi`. To use `atoi`, you *must* include `#include <cstdlib>`. Without that `#include`, it may work on your machine, but it will *not* work on the grading server.
- Your stack in TreeCalc.h/cpp should be called mystack (or else you will have to change the name in `printOutput()` -- this is the one change you can make to this method)

### Print Output Format  ###

Postfix notation (also known as [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_polish_notation)) involves writing the operators after the operands.  Note how parentheses are unnecessary in prefix or postfix notation.  Your print methods must print in the following format.  The only spaces are on either side of the operators.  Your entire expression must be printed on a single line that terminates with a newline character.  You should put parenthesis around each infix operation, regardless if it is needed according to operator precedence.

- Infix format: `((34 + 6) - (-8 / 4))`
- Postfix format: `34 6 + -8 4 / -`
- Prefix format: `- + 34 6 / -8 4`

### Sample Execution Run ###

Below is a sample execution run to show you the input and output format we are looking for.

```
Enter elements one by one in postfix notation
Any non-numeric or non-operator character, e.g. #, will terminate input
Enter first element: 34
Enter next element: 6
Enter next element: +
Enter next element: -8
Enter next element: 4
Enter next element: /
Enter next element: -
Enter next element: #
Expression tree in postfix expression: 34 6 + -8 4 / - 
Expression tree in infix expression: ((34 + 6) - (-8 / 4))
Expression tree in prefix expression: - + 34 6 / -8 4 
The result of the expression tree is 42 
```

------------------------------------------------------------

In-lab
------

The deliverables for this in-lab are the AVL worksheet and the Makefile-pizza tutorial. Print out the worksheet and bring it to your lab section. Turn in the worksheet by the end of lab. Make sure to bubble in your ID at the bottom of the page. If you do not finish it by the end of lab, submit a 24 hour extension and turn in a scanned PDF electronically. 

If you have time remaining, you may want to start working on the post-lab. Consult the TAs for any help understanding tree rotations.  

------------------------------------------------------------

Post-lab
--------

The objective of this lab is to understand the runtime characteristics and trade-offs between normal Binary search trees and AVL trees. You will have to implement a Binary search tree, an AVL tree, and compare their results with the test program for the three provided test files.

Both trees must implement their respective class definitions in [BinarySearchTree.h](code/postlab/BinarySearchTree.h.html) ([src](code/postlab/BinarySearchTree.h)) and [AVLTree.h](code/postlab/AVLTree.h.html) ([src](code/postlab/AVLTree.h)). However, you are free to add as many other member functions as you wish. Note that we have provided an implementation of `remove()` in [AVLTree.cpp](code/postlab/AVLTree.cpp.html) ([src](code/postlab/AVLTree.cpp)), but you must still implement `remove()` for the Binary search tree.

Do NOT alter [TreePathTest.cpp](code/postlab/TreePathTest.cpp.html) ([src](code/postlab/TreePathTest.cpp)). This program will be used to run automated tests on your implementations. Do not change it.

Feel free to move the implementation of the AVL tree to another .cpp file. However, we recommend separate .cpp files for the different trees. Additionally, you may find it helpful to have private versions of `insert`, `pathTo`, etc... that take a node as a parameter. This allows them to operate on any node, not just the root.

The test program will read inputs and attempt to insert elements into your trees. Its input format is a sequence of instruction/word pairs defined as follows:
- Insert <word>: `I <word>`
- Remove <word>: `R <word>`
- Lookup <word>: `L <word>`

The Lookup instruction will call the `pathTo()` method defined in your trees. `pathTo()` must return a string representing the nodes encountered when finding an element. For instance in the following image, the bold lines indicate the path taken for locating element W.

![avl-tree-pic-1](avl-tree-pic-1.png)

`pathTo("W")` would then return the string `"M P Z W"`. Calling `pathTo()` on an element that doesn't exist would result in an empty string `""`.

To recap, submit the following files:
- TreePathTest.cpp: Do NOT modify, contains `main()` method.
- AVLTree.h, BinarySearchTree.h: class definitions which the test program depends on.
- Your .cpp files which contain the implementions of AVLTree and BinarySearchTree.
- Makefile: compiles your program and produces the a.out executable
- analysis.pdf: The report for this lab.

The report for this lab should contain the following: 

1. Your name, the date, and your CS 2150 lab section.
2. What do [testfile1.txt](code/postlab/testfile1.txt) ([output](code/postlab/testfile1.out.txt)), [testfile2.txt](code/postlab/testfile2.txt) ([output](code/postlab/testfile2.out.txt)), and [testfile3.txt](code/postlab/testfile3.txt) ([output](code/postlab/testfile3.out.txt)) suggest about the relative performance of AVL trees and BSTs?
3. Actual numerical results for some operations on both AVL trees and BSTs for the three provided test files and any additional tests you created.
4. A characterization of situations where AVL trees are preferable to BSTs.
5. A discussion of the costs incurred in an AVL implementation. 

For parts 4-5, a FULL page (if double spaced) is about what we are looking for (that's a full page for parts 4 & 5 combined).  Feel free to single space -- the same length (in terms of words, not in terms of page length) is still required.