PDR: Slides: Slide Graph Diagrams
=================================

[Go up to the main slides table of contents page](../index.html) ([md](../index.md))

The files in this directory use [GraphViz](http://www.graphviz.org/) to generate the images.  To run GraphViz:

```
dot -Tsvg filename.dot -o outname.svg
```

The three Red-black tree insertion case images need the `-Kneato` flag for proper layout.  You can also just run `make` in the slides/graphs/ directory to convert all of the .dot files in this repository to .svg files.  This also creates .png and .ps versions of the graphs, which can be removed via `make clean`.  A fairly recent version of GraphViz is needed for 'rarrow' shape.

Both the original .dot files, as well as the .svg files (which are what are used in the slides) are include in this repository.

Some of these images (the expression trees and the red-black insertion cases) were added the the appropriate Wikiedpia pages as well.

References
----------

- [GraphViz](http://www.graphviz.org/)
- [GraphViz: creating balanced trees](http://www.graphviz.org/content/FaqBalanceTree)
- Wikipedia articles on [Binary expression trees](https://en.wikipedia.org/wiki/Binary_expression_tree) and [Red-black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)


Images
------

- High-level diagrams: [list-diagram-1.svg](list-diagram-1.svg), [list-diagram-2.svg](list-diagram-2.svg), [tree-diagram.svg](tree-diagram.svg)
- Expression trees
    - Expression tree images: [exp-tree-1.svg](exp-tree-1.svg), [exp-tree-2.svg](exp-tree-2.svg), [exp-tree-3.svg](exp-tree-3.svg)
    - Expression tree formation images: [exp-tree-ex-1.svg](exp-tree-ex-1.svg), [exp-tree-ex-2.svg](exp-tree-ex-2.svg), [exp-tree-ex-3.svg](exp-tree-ex-3.svg), [exp-tree-ex-4.svg](exp-tree-ex-4.svg), [exp-tree-ex-5.svg](exp-tree-ex-5.svg), [exp-tree-ex-6.svg](exp-tree-ex-6.svg), [exp-tree-ex-7.svg](exp-tree-ex-7.svg), [exp-tree-ex-8.svg](exp-tree-ex-8.svg), [exp-tree-ex-9.svg](exp-tree-ex-9.svg), [exp-tree-ex-10.svg](exp-tree-ex-10.svg)
- Binary trees
    - Binary search tree images: [bst-1.svg](bst-1.svg), [bst-2.svg](bst-2.svg), [bst-3.svg](bst-3.svg), [bst-4.svg](bst-4.svg), [bst-5.svg](bst-5.svg), [bst-6.svg](bst-6.svg), [bst-7.svg](bst-7.svg), [bst-8.svg](bst-8.svg), [bst-9.svg](bst-9.svg), [bst-10.svg](bst-10.svg), [bst-11.svg](bst-11.svg), [bst-12.svg](bst-12.svg), [bst-13.svg](bst-13.svg)
    - AVL tree images: [avl-tree-1.svg](avl-tree-1.svg), [avl-tree-2.svg](avl-tree-2.svg), [avl-tree-3.svg](avl-tree-3.svg), [avl-tree-4.svg](avl-tree-4.svg), [avl-tree-5.svg](avl-tree-5.svg), [avl-tree-6.svg](avl-tree-6.svg), [avl-tree-7.svg](avl-tree-7.svg), [avl-tree-8.svg](avl-tree-8.svg), [avl-tree-9.svg](avl-tree-9.svg), [avl-tree-10.svg](avl-tree-10.svg), [avl-tree-11.svg](avl-tree-11.svg), [avl-tree-12.svg](avl-tree-12.svg), [avl-tree-13.svg](avl-tree-13.svg), [avl-tree-14.svg](avl-tree-14.svg), [avl-tree-15.svg](avl-tree-15.svg), [avl-tree-16.svg](avl-tree-16.svg), [avl-tree-17.svg](avl-tree-17.svg), [avl-tree-18.svg](avl-tree-18.svg), [avl-tree-19.svg](avl-tree-19.svg), [avl-tree-20.svg](avl-tree-20.svg), [avl-tree-21.svg](avl-tree-21.svg), [avl-tree-22.svg](avl-tree-22.svg), [avl-tree-23.svg](avl-tree-23.svg), [avl-tree-24.svg](avl-tree-24.svg)
    - Red-black tree images: [rb-tree-1.svg](rb-tree-1.svg), [Red-black_tree_insert_case_3.svg](Red-black_tree_insert_case_3.svg), [Red-black_tree_insert_case_4.svg](Red-black_tree_insert_case_4.svg), [Red-black_tree_insert_case_5.svg](Red-black_tree_insert_case_5.svg)
    - Additional red-black tree images, specifically the removal cases, are not included in this repository but can be found [here](https://github.com/aaronbloomfield/wikipedia)
- Miscellaneous trees
    - File tree images: [file-tree-1.svg](file-tree-1.svg)
    - Program tree images: [program-tree-1.svg](program-tree-1.svg)
- Heap images: [heap-1.svg](heap-1.svg), [heap-2.svg](heap-2.svg), [heap-3.svg](heap-3.svg), [heap-4.svg](heap-4.svg), [heap-5.svg](heap-5.svg), [heap-6.svg](heap-6.svg), [heap-7.svg](heap-7.svg), [heap-8.svg](heap-8.svg), [heap-9.svg](heap-9.svg), [heap-10.svg](heap-10.svg), [heap-11.svg](heap-11.svg), [heap-12.svg](heap-12.svg), [heap-13.svg](heap-13.svg), [heap-14.svg](heap-14.svg), [heap-15.svg](heap-15.svg), [heap-16.svg](heap-16.svg), [heap-17.svg](heap-17.svg), [heap-18.svg](heap-18.svg)
- Huffman tree images: [huffman-1.svg](huffman-1.svg), [huffman-2.svg](huffman-2.svg), [huffman-3.svg](huffman-3.svg), [huffman-4.svg](huffman-4.svg), [huffman-5.svg](huffman-5.svg), [huffman-6.svg](huffman-6.svg), [huffman-7.svg](huffman-7.svg), [huffman-8.svg](huffman-8.svg), [huffman-9.svg](huffman-9.svg), [huffman-10.svg](huffman-10.svg), [huffman-11.svg](huffman-11.svg), [huffman-12.svg](huffman-12.svg), [huffman-13.svg](huffman-13.svg), [huffman-14.svg](huffman-14.svg)
- Graph images: [graph-1.svg](graph-1.svg), [graph-2.svg](graph-2.svg), [graph-3.svg](graph-3.svg), [graph-4.svg](graph-4.svg), [graph-5.svg](graph-5.svg), [graph-6.svg](graph-6.svg), [graph-7.svg](graph-7.svg), [graph-8.svg](graph-8.svg), [graph-9.svg](graph-9.svg), [graph-10.svg](graph-10.svg), [graph-11.svg](graph-11.svg), [graph-12.svg](graph-12.svg), [graph-13a.svg](graph-13a.svg), [graph-13b.svg](graph-13b.svg), [graph-13c.svg](graph-13c.svg), [graph-13d.svg](graph-13d.svg), [graph-13e.svg](graph-13e.svg), [graph-14.svg](graph-14.svg), [graph-15.svg](graph-15.svg)
- Other: [c-string-1.svg](c-string-1.svg)
