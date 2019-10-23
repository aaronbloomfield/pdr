PDR: Laboratory 5: Trees
========================

[Go up to the Labs table of contents page](../index.html)

### Objective: ###

1. Learn about binary trees
2. See tree traversals in the context of a useful application
3. Understand tree rotations
3. Implement a binary search tree and an AVL tree
4. Evaluate the performance of binary search trees and AVL trees

### Background: ###

A binary tree is a tree with a maximum of two children per node.  Tree traversals are commonly associated with binary trees. A pre-order traversal processes the given node first and then processes its left and then right subtrees.  In an in-order traversal, first the node's left subtree is processed, followed by the node itself, and finally its right subtree.  A post-order traversal operates on the left subtree, followed by the right subtree, and finally on the node itself.

A binary search tree is a binary tree that imposes an ordering on its nodes. A node's left child has a lesser value, while its right child has a greater value. Binary search trees are useful for efficient insertion, deletion, and lookup of items with a certain key. As we'll see in this lab, variations of binary search trees offer different performance characteristics.

### Reading(s): ###

The [Wikipedia article on Expression trees](http://en.wikipedia.org/wiki/Expression_tree), especially the [section on construction of expression trees](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree).  Also the [05: Trees](../../slides/05-trees.html) slide set.


Procedure
---------

### Pre-lab ###

1. Complete the [makefile tutorial](../../tutorials/05-make/index.html).  You will need to know how to write one for the in-lab and post-lab, since all the following labs will be compiled via Makefiles. There is one file that needs to be submitted from the tutorial -- you should name this file Makefile-pizza.
2. Your file **MUST** be named `Makefile-pizza` - not Makefile-pizza.txt, not Makefile-Pizza, not Makefilepizza.  If it is not named correctly, it will not work with our grading scripts, and you will not get credit for that part of the lab.
3. Come to lab with a fully functional tree calculator, as described below.  
4. Read the [Wikipedia article on Expression trees](http://en.wikipedia.org/wiki/Expression_tree), especially the [section on construction of expression trees](http://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_Expression_Tree).
5. Files to download: [TreeCalc.h](code/prelab/TreeCalc.h.html) ([src](code/prelab/TreeCalc.h)), [TreeCalc.cpp](code/prelab/TreeCalc.cpp.html) ([src](code/prelab/TreeCalc.cpp)), [TreeNode.h](code/prelab/TreeNode.h.html) ([src](code/prelab/TreeNode.h)), [TreeNode.cpp](code/prelab/TreeNode.cpp.html) ([src](code/prelab/TreeNode.cpp)), and  [TreeCalcTest.cpp](code/prelab/TreeCalcTest.cpp.html) ([src](code/prelab/TreeCalcTest.cpp)).  These files are contained in the prelab/ directory of the [code.zip](code.zip) file.
6. Files to submit: TreeCalc.h/cpp, TreeCalcTest.cpp, TreeNode.h/cpp, Makefile-pizza

### In-lab ###

1. For this lab, you will implement a Binary search tree.
2. Your program must compile with make!
3. Files to download: [BinaryNode.h](code/inlab/BinaryNode.h.html) ([src](code/inlab/BinaryNode.h)), [BinaryNode.cpp](code/inlab/BinaryNode.cpp.html) ([src](code/inlab/BinaryNode.cpp)), [BinarySearchTree.h](code/inlab/BinarySearchTree.h.html) ([src](code/inlab/BinarySearchTree.h)), [BinarySearchTree.cpp](code/inlab/BinarySearchTree.cpp.html) ([src](code/inlab/BinarySearchTree.cpp)), [BSTPathTest.cpp](code/inlab/BSTPathTest.cpp.html) ([src](code/inlab/BSTPathTest.cpp)), [testfile1.txt](code/inlab/testfile1.txt) ([output](code/inlab/testfile1.out.txt)), [testfile2.txt](code/inlab/testfile2.txt) ([output](code/inlab/testfile2.out.txt)), [testfile3.txt](code/inlab/testfile3.txt) ([output](code/inlab/testfile3.out.txt)). These files are contained in the inlab/ directory of the [code.zip](code.zip) file.
4. Files to submit: BinarySearchTree.h, BinarySearchTree.cpp, BinaryNode.h, BinaryNode.cpp, BSTPathTest.cpp, Makefile, and any other files needed to make your code compile.

### Post-lab ###

1. For this lab, you will implement an AVL tree and submit a brief lab report electronically via the submission system.
2. Your report must be in PDF format!  See the [How to convert a file to PDF](../../docs/convert_to_pdf.html) page for details.
3. Files to download: [AVLNode.h](code/postlab/AVLNode.h.html) ([src](code/postlab/AVLNode.h)), [AVLNode.cpp](code/postlab/AVLNode.cpp.html) ([src](code/postlab/AVLNode.cpp)), [AVLTree.h](code/postlab/AVLTree.h.html) ([src](code/postlab/AVLTree.h)), [AVLTree.cpp](code/postlab/AVLTree.cpp.html) ([src](code/postlab/AVLTree.cpp)), [AVLPathTest.cpp](code/postlab/AVLPathTest.cpp.html) ([src](code/postlab/AVLPathTest.cpp)), [testfile1.txt](code/postlab/testfile1.txt) ([output](code/postlab/testfile1.out.txt)), [testfile2.txt](code/postlab/testfile2.txt) ([output](code/postlab/testfile2.out.txt)), [testfile3.txt](code/postlab/testfile3.txt) ([output](code/postlab/testfile3.out.txt)). These files are contained in the postlab/ directory of the [code.zip](code.zip) file.
4. Files to submit: AVLTree.h, AVLTree.cpp, AVLNode.h, AVLNode.cpp, AVLPathTest.cpp, Makefile, any other files needed to make your code compile, analysis.pdf (see the post-lab section for formatting details)

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

For this in-lab, you will implement a Binary search tree. The required class declarations are located in [BinaryNode.h](code/inlab/BinaryNode.h) and [BinarySearchTree.h](code/inlab/BinarySearchTree.h). You may want to create private helper methods for BinarySearchTree, as done for the implementation of `remove`, which is already provided for you. Notice how the private methods take a BinaryNode as a parameter. This allows them to recur over a subtree, a common implementation technique.

Do NOT alter [BSTPathTest.cpp](code/inlab/BSTPathTest.cpp). This program will be used to run automated tests on your implementation. Do not change it.

**IMPORTANT NOTE:** You need to add the following flag as an option to your CXXFLAGS variable in your makefile: **-std=c++11**. WHY? The code we are providing uses some "newer" features of C++ that the grading server won't compile with by default. If you don't add this, your code might compile on your laptop but not the grading server when you submit.

The test program reads a sequence of a sequence of instruction/word pairs and attempts to operate on your tree. Example test files are located in the inlab directory.

- Insert <word>: `I <word>`
- Remove <word>: `R <word>`
- Lookup <word>: `L <word>`

The Lookup instruction will call the `pathTo()` method defined on your tree. `pathTo()` must return a string representing the nodes encountered when finding an element. For instance in the following image, the bold lines indicate the path taken for locating element W.

![avl-tree-pic-1](avl-tree-pic-1.png)

`pathTo("W")` would then return the string `"M P Z W"`. Calling `pathTo()` on an element that doesn't exist would result in an empty string `""`.

The BinarySearchTree.cpp file already contains a few methods implemented for you (including remove()). To aid in debugging, we provide a printTree() method and associated helper methods that will print out your tree to the console in a nice format. This will prove useful if you are having trouble and want to see what your tree is doing over several operations. You can call printTree() to see this output and safely ignore all of the helper methods.

To recap, submit the following files:

- BSTPathTest.cpp: Do NOT modify, contains `main()`.
- BinaryNode.h, BinarySearchTree.h: class declarations the test program requires.
- BinaryNode.cpp: contains the implementation of BinaryNode.
- BinarySearchTree.cpp: contains the implementation of BinarySearchTree.
- Any other .cpp files required to make your program compile.
- Makefile: compiles your program and produces the a.out executable.

------------------------------------------------------------

Post-lab
--------

The objective of this post-lab is to understand the runtime characteristics and trade-offs between normal Binary search trees and AVL trees. You will have to implement an AVL tree and write a brief report to compare its performance with the Binary search tree implemented for the in-lab.

The required class declarations are located in [AVLNode.h](code/postlab/AVLNode.h) and [AVLTree.h](code/postlab/AVLTree.h). Much of the behavior of the AVL implementation is similar to that of the Binary search tree, aside from rotations and rebalancing. You may want to create private helper methods for AVLTree, as done for the implementation of `remove`, which is already provided for you. As with the in-lab, the printTree() method is given to you to aid with visualizing the results of your tree operations and for debugging.

Do NOT alter [AVLPathTest.cpp](code/postlab/AVLPathTest.cpp). This program will be used to run automated tests on your implementation. Do not change it. The example test files are located in the postlab directory.

**IMPORTANT NOTE:** Similar to the in-lab, you need to add the following flag as an option to your CXXFLAGS variable in your makefile: **-std=c++11**. WHY? The code we are providing uses some "newer" features of C++ that the grading server won't compile with by default. If you don't add this, your code might compile on your laptop but not the grading server when you submit.

A common issue when students implement this lab is that the _balance(AVLNode* &node)_ method needs to work for insert and for remove. To help avoid potential issues, below is some pseudocode for the balance method that you may use:

```
//Note that balance factor here is assumed to be height of right - left subtree
balance(node):
	if balance factor of node is 2 we will need to rotate left:
		first, see if we should also rotate right (i.e., do a double rotation)
		if balance factor of right child is negative:
			rotate right on the right child
		endif
		rotate left on node
	else if balance factor of node is -2 we will need to rotate right:
		first, see if we should also rotate left (i.e., double rotation)
		if balance factor of left is positive:
			rotate left on the left child
		endif
		rotate right on node
	endif
```

To recap, submit the following files:

- AVLPathTest.cpp: Do NOT modify, contains `main()`.
- AVLNode.h, AVLTree.h: class declarations the test program requires.
- AVLNode.cpp: contains the implementation of AVLNode.
- AVLTree.cpp: contains the implemention of AVLTree.
- Any other .cpp files required to make your program compile.
- Makefile: compiles your program and produces the a.out executable.
- analysis.pdf: The report for this lab.

The report for this lab should contain the following:

1. Your name, the date, and your CS 2150 lab section.
2. A discussion of what [testfile1.txt](code/postlab/testfile1.txt), [testfile2.txt](code/postlab/testfile2.txt), and [testfile3.txt](code/postlab/testfile3.txt) suggest about the relative performance of AVL trees and Binary search trees.
3. A description of the space-time tradeoff between the two implementations.
4. A characterization of situations where AVL trees are preferable to Binary search trees.

We are looking for these items to be addressed VERY briefly. We estimate the report should be 1 page or less in total. A short paragraph for each item 2-4 is fine.
