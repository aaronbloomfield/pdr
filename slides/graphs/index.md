Graph Generation
================

[Go up to the main slides table of contents page](../index.html)

The files in this directory use [GraphViz](http://www.graphviz.org/) to generate the images.  To run GraphViz:

```
dot -Tsvg filename.dot -o outname.svg
```

However, you can just run `make` in the slides/graphs/ directory to convert all of the .dot files in this repository to .svg files.  This also creates .png and .ps versions of the graphs, which can be removed via `make clean`.

Both the original .dot files, as well as the .svg files (which are what are used in the slides) are include in this repository.

References
----------

- [GraphViz: creating balanced trees](http://www.graphviz.org/content/FaqBalanceTree)
