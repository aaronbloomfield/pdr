PDR: Laboratory 5: Trees
========================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

1. Learn about binary trees
2. See tree traversals in the context of a useful application
3. Understand tree rotations
3. Implement a binary search tree and an AVL tree
4. Evaluate the performance of binary search trees and AVL trees

### Background ###

A binary tree is a tree with a maximum of two children per node.  Tree traversals are commonly associated with binary trees. A pre-order traversal processes the given node first and then processes its left and then right subtrees.  In an in-order traversal, first the node's left subtree is processed, followed by the node itself, and finally its right subtree.  A post-order traversal operates on the left subtree, followed by the right subtree, and finally on the node itself.

A binary search tree is a binary tree that imposes an ordering on its nodes. A node's left child has a lesser value, while its right child has a greater value. Binary search trees are useful for efficient insertion, deletion, and lookup of items with a certain key. As we'll see in this lab, variations of binary search trees offer different performance characteristics.

### Tutorial ###

Complete the [Makefile tutorial](../../tutorials/05-make/index.html).  You will need to know how to write one for the pre-lab, in-lab and post-lab, since all the following labs will be compiled via Makefiles.

### Recommended Readings ###

The [Wikipedia article on Expression trees](https://en.wikipedia.org/wiki/Expression_tree), especially the [section on construction of expression trees](https://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_expression_tree).  Also the [05: Trees](../../slides/05-trees.html) slide set.


Procedure
---------

### Pre-lab ###

1. Create a postfix tree calculator
2. Files to download: [TreeCalc.h](code/prelab/TreeCalc.h.html) ([src](code/prelab/TreeCalc.h)), [TreeCalc.cpp](code/prelab/TreeCalc.cpp.html) ([src](code/prelab/TreeCalc.cpp)), [TreeNode.h](code/prelab/TreeNode.h.html) ([src](code/prelab/TreeNode.h)), [TreeNode.cpp](code/prelab/TreeNode.cpp.html) ([src](code/prelab/TreeNode.cpp)), and  [TreeCalcTest.cpp](code/prelab/TreeCalcTest.cpp.html) ([src](code/prelab/TreeCalcTest.cpp)).  These files are contained in the prelab/ directory of the [code.zip](code.zip) file.
3. Files to submit: TreeCalc.h/cpp, TreeCalcTest.cpp, TreeNode.h/cpp, Makefile

### In-lab ###

1. Implement a binary search tree
3. Files to download: [BinaryNode.h](code/inlab/BinaryNode.h.html) ([src](code/inlab/BinaryNode.h)), [BinaryNode.cpp](code/inlab/BinaryNode.cpp.html) ([src](code/inlab/BinaryNode.cpp)), [BinarySearchTree.h](code/inlab/BinarySearchTree.h.html) ([src](code/inlab/BinarySearchTree.h)), [BinarySearchTree.cpp](code/inlab/BinarySearchTree.cpp.html) ([src](code/inlab/BinarySearchTree.cpp)), [BSTPathTest.cpp](code/inlab/BSTPathTest.cpp.html) ([src](code/inlab/BSTPathTest.cpp)), [testfile1.txt](code/inlab/testfile1.txt) ([output](code/inlab/testfile1.out.txt)), [testfile2.txt](code/inlab/testfile2.txt) ([output](code/inlab/testfile2.out.txt)), [testfile3.txt](code/inlab/testfile3.txt) ([output](code/inlab/testfile3.out.txt)). These files are contained in the inlab/ directory of the [code.zip](code.zip) file.
4. Files to submit: BinarySearchTree.h, BinarySearchTree.cpp, BinaryNode.h, BinaryNode.cpp, BSTPathTest.cpp, Makefile, and any other files needed to make your code compile.

### Post-lab ###

1. Implement an AVL tree
2. Files to download: [AVLNode.h](code/postlab/AVLNode.h.html) ([src](code/postlab/AVLNode.h)), [AVLNode.cpp](code/postlab/AVLNode.cpp.html) ([src](code/postlab/AVLNode.cpp)), [AVLTree.h](code/postlab/AVLTree.h.html) ([src](code/postlab/AVLTree.h)), [AVLTree.cpp](code/postlab/AVLTree.cpp.html) ([src](code/postlab/AVLTree.cpp)), [AVLPathTest.cpp](code/postlab/AVLPathTest.cpp.html) ([src](code/postlab/AVLPathTest.cpp)), [testfile1.txt](code/postlab/testfile1.txt) ([output](code/postlab/testfile1.out.txt)), [testfile2.txt](code/postlab/testfile2.txt) ([output](code/postlab/testfile2.out.txt)), [testfile3.txt](code/postlab/testfile3.txt) ([output](code/postlab/testfile3.out.txt)). These files are contained in the postlab/ directory of the [code.zip](code.zip) file.
3. Files to submit: AVLTree.h, AVLTree.cpp, AVLNode.h, AVLNode.cpp, AVLPathTest.cpp, Makefile, and any other files needed to make your code compile (see the post-lab section for formatting details)

------------------------------------------------------------

Pre-lab
-------

For the pre-lab you will be using a stack to help you read in a postfix expression into an expression tree.  While this is similar to lab 3, you will instead be ultimately creating an expression tree for the postfix expression, rather than evaluating it and leaving the result on the stack.

### Implementation ###

Your tree calculator will read in well-formed expressions in postfix notation.  You will need to build an expression tree using the algorithm described in the [Wikipedia article on Expression trees](https://en.wikipedia.org/wiki/Expression_tree#Construction_of_an_expression_tree) and the [trees slide set](../../slides/05-trees.html).  Trees similar to this type of expression tree are used extensively in compilers.

Your fully functional tree calculator must:

- Read well-formed postfix expressions into a stack, supporting the following input:
    - Integers, both positive and negative
    - `+`: addition
    - `-`: subtraction
    - `*`: multiplication
    - `/`: integer division
- Build an expression tree using the items in the stack
- Print the resulting expression tree as a postfix, infix, and prefix expression, in the following format:
    - One space between each value, excluding parentheses (leading and trailing spaces are acceptable)
    - Parentheses around every infix operation, regardless of operator precedence
    - A single line that terminates with a newline character
- Calculate the result of your expression using the expression tree
- Print the result to the screen
- Have no memory leaks

Additionally, you should use the skeleton source files in the prelab/ directory of [code.zip](code.zip) as a basis for your tree calculator.
You may modify and add to the skeleton code as you see fit, but TreeCalcTest, TreeNode, `readInput()`, and `printOutput()` must NOT be modified.

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

### Submission ###

You should submit any files required for your tree calculator to run. TreeCalcTest.cpp, TreeNode.h, and TreeNode.cpp should not be modified.

### Hints ###

**Recursion is the way to go:** Recursion is very useful in traversing
the expression tree.  You'll need to use recursion for many of the
TreeCalc methods.

**Printing in the right order:** Draw a simple tree and see how you
should recurse in order to hit each node in the correct order.  Need
more help? Check the [Wikipedia article](https://en.wikipedia.org/wiki/Expression_tree)!

------------------------------------------------------------

In-lab
------

For this in-lab, you will implement a binary search tree.

### BST Implementation ###

The necessary files are in the inlab/ directory of [code.zip](code.zip).

The required class declarations are located in [BinaryNode.h](code/inlab/BinaryNode.h.html) ([src](code/inlab/BinaryNode.h)) and [BinarySearchTree.h](code/inlab/BinarySearchTree.h.html) ([src](code/inlab/BinarySearchTree.h)). You may want to create private helper methods for BinarySearchTree, as done for the implementation of `remove()`, which is already provided for you. The private methods take BinaryNodes as parameters which allow them to recurse over a subtree, a common implementation technique.

You should use [BSTPathTest.cpp](code/inlab/BSTPathTest.cpp.html) ([src](code/inlab/BSTPathTest.cpp)) to test your implementation, but you may NOT change it.

Unlike the pre-lab, you *can* modify the various files provided EXCEPT for BSTPathTest.cpp and AVLPathTest.cpp.

### Test Files ###

We provide a number of test files that you can use as input: [testfile1.txt](code/inlab/testfile1.txt) ([output](code/inlab/testfile1.out.txt)), [testfile2.txt](code/inlab/testfile2.txt) ([output](code/inlab/testfile2.out.txt)), and [testfile3.txt](code/inlab/testfile3.txt) ([output](code/inlab/testfile3.out.txt))

The test program reads a sequence of instruction/word pairs and attempts to operate on your tree.

- Insert <word>: `I <word>`
- Remove <word>: `R <word>`
- Lookup <word>: `L <word>`

The Lookup instruction will call the `pathTo()` method defined on your tree. `pathTo()` must return a string representing the nodes encountered when finding an element. For instance in the following image, the bold lines indicate the path taken for locating element W.

![](avl-tree-pic-1.png)

`pathTo("W")` would then return the string `"M P Z W"`. Calling `pathTo()` on an element that doesn't exist would result in an empty string `""`.

### Sample Execution Run ###

Below is a sample execution run to show you the input and output format we are looking for.

```
I We
I can't
I solve
I problems
I by
I using
I the
I same
I kind
I of
I thinking
I we
I used
I when
I we
I created
I them
I -Albert
I Einstein
L created
BST path: We can't solve problems kind created
BST numNodes: 18
```

### Submission ###

You should submit your BST, any supporting C++ files, as well as a Makefile to compile everything into an `a.out` executable.

### Hints ###

**Private methods:** Following the suggestion to implement private
versions of all the public methods that take in BinaryNodes will help
considerably.  How should your public method interact with the private
version? In other words, what node should the public method pass in?

**Passing pointers by reference:** When a pointer is passed by
reference, that allows us to change not only the data that the pointer
is pointing to, but also _what the pointer is pointing to in the first
place_.  This is one option that allows you to change the structure of
your tree without having to use parent pointers.

------------------------------------------------------------

Post-lab
--------

The objective of this post-lab is to understand the run-time characteristics and trade-offs between normal Binary search trees and AVL trees. Your deliverable for this post-lab will be an AVL tree implementation.

### AVL Implementation ###

The structure of the provided AVL starter code is analogous to that of
the BST, and is not discussed in further detail here.  The starter
files are in the postlab/ directory of [code.zip](code.zip).  The
comments in the code of the starter files help explain where to start.

You may test your implementation with the same test files as before, though the expected output will be different ([output of testfile1](code/postlab/testfile1.out.txt), [output of testfile2](code/postlab/testfile2.out.txt), [output of testfile3](code/postlab/testfile3.out.txt)).

Unlike the pre-lab, you *can* modify the various files provided EXCEPT for BSTPathTest.cpp and AVLPathTest.cpp.

### Sample Execution Run ###

Below is a sample execution run to show you the input and output format we are looking for.

```
I We
I can't
I solve
I problems
I by
I using
I the
I same
I kind
I of
I thinking
I we
I used
I when
I we
I created
I them
I -Albert
I Einstein
L created
AVL path: problems can't kind created
AVL numNodes: 18
```

### Submission ###

You should submit your AVL tree, any supporting C++ files, and the Makefile.

### Hints ###

#### Balancing ####

`balance(AVLNode*& node)` is crucial for both insert and remove, but has many cases that you must account for. To help avoid potential issues, here is some pseudocode for the balance method that you may use:

```
//Note that balance factor here is assumed to be (height of right subtree - height of left subtree)
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
