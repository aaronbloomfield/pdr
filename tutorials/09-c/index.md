PDR: C Tutorial for C++ programmers
===================================

[Go up to the Tutorials table of contents page](../index.html)

### Originally by Jeremy W. Sheaffer ###

This document assumes that you have a strong working knowledge of the most basic and important aspects of C++.  It is designed to introduce you to important concepts in C - most of them also available in C++, but rarely used there - with which you likely have little familiarity.

------------------------------------------------------------

Hello World, Hello World, Hello World!
------------

A basic C program looks like the following:

```
/* hello world x3 */
#include <stdio.h>
int main() {
    int i;
    for (i = 0; i < 3; i++) {
        printf ("hello world!\n");
    }
    return 0;
}
```

A few things to note about this program:
- The `<stdio.h>` was #included (stdio stands for Standard I/O library), which is where `printf()` (and, later, `scanf()`) live.  These are the basic input and output routines in C, analogous to cout and cin in C++.  More on these functions are below
- There are no namespaces in C
- Comments are enclosed in `/*` and `*/`.  The `//` notation does not work in pure C, but most C compilers will allow it anyway
- The iterating variable `i` is not declared within the `for` statement in pure C, but most C compilers will allow it anyway.

To use `malloc()`, which is the C version of `new`, you will need to include the `<stdlib.h>` file (stdlib is the standard library) - more on `malloc()` is also below.

------------------------------------------------------------

Input and Output
----------------

C does not have *iostreams* or *stream operators*, such as `<<` (for cout) and `>>` (for cin).  For most I/O, we use the `printf()` family of functions (for output) and the `scanf()` family (for input).

### int printf(const char *format, ...) ###

`printf()` takes a *format string*, containing verbatim text that you want to display and *conversion specifiers* which describe to `printf()` how to interpret and display the remaining arguments.  The conversion specifiers may contain *flags*, which control such things as field width, precision, and format.  All conversion specifiers begin with a `%`.  To print a `%`, your format string must contain `%%`.  Other special characters will have to be escaped with a backslash (i.e., to do a return, we enter `\n`; for a backslash, we enter `\\`).

For example, to print an integer, we would enter:

```
printf ("this is an int: %d\n", x);
```

The `%d` part tells printf to format the appropriate parameter (x, in this case) as an integer, and insert it at that spot in the string.


Commonly used conversion specifiers are:


| Specifier | Meaning |
|-|-|
| d | converts an int |
| f | converts a float |
| c | converts a char |
| s | converts a string |
| p | converts a pointer |


and flags:

| Flag | Meaning |
|-|-|
| l	(a lower-case 'L') | Instead of an int or float, convert a long int or double |
| ll (two lower-case 'L's) | ..., convert a long long int or long double |
| 0 (zero) | Zero pad the conversion to fill the field width |
| - | Left justify the field |
| ' ' (a space) | Leave a blank space where an omitted '+' would go |
| + | Display a '+' for positive numbers |
| Non-zero integer | Minimum field width |
| '.' followed by a non-zero integer | Number of digits of precision |


Some examples:

```
printf("pi = %.0f\n", pi);         /* output: pi = 3    */
printf("pi = '%+10.4f'\n", pi);    /* pi = '   +3.1416' */
printf("Hello from %s, which begins at %p!\n",  __PRETTY_FUNCTION__, main);  /* Hello from main, which begins at 0x4004f4! */
```

This last one uses the `__PRETTY_FUNCTION__` macro, which is a string representation of the function name.  And the 'main' in there is printing out the hexadecimal address of where the `main()` function begins in the x86 code section.

### Variable argument lists ###

We've seen variable argument lists in the context of the C calling convention (that's why the parameters are pushed onto the stack in reverse order).  The `...` portion of the `printf()` function signature signifies that it take a variable number of arguments.  I/O functions in C commonly combine this notation with a format string.  Any use of variable argument lists must include clues so that the callee can correctly identify the number and type of its arguments.  An interesting example of a function which uses variable argument lists in a less obvious way is open():

```
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

but C does not support function overloading!  While the `open()` manual page displays the two prototypes above, the actual signature of `open()` is:

```
int open(const char *pathname, int flags, ...);
```

The variable argument list (mode) is only used if flags includes the bit `O_CREAT`, giving `open()` the information it needs to decide whether or not to access arguments beyond flags.

### int scanf(const char *format, ...) ###

`scanf()` converts input, rather than output.  Its format strings look very similar to those of `printf()`, with a few more complex conversions, which we will not cover in this tutorial as they are not often used.  The key point to remember to differentiate usage of `scanf()` and `printf()` is that while `printf()` converts values (as in *pass-by-value*), `scanf()` converts input and thus needs a place to store it (*pass-by-address*, which is really passing a pointer by value; C does not have *pass-by-reference*, only C++ does).

`scanf()` will precisely match all non-whitespace characters in the format string.  Whitespace is handled specially, in that each individual instance of whitespace in the format string is treated like a single space, and a single space in the format string matches one or more whitespace characters in the input.  Conversion usually stops at the first whitespace character.  All matched input is discarded, save that which is converted.

Be careful of buffer overflow! `scanf()` doesn't know how large your buffer is.  If you don't know either, don't use `scanf()`.  We prefer to use `fgets()` followed by `sscanf()` for this reason.

Some examples:

```
int age;
char grade;
char school[3];

scanf("AGE: %d", &age);       /* Reads and discards "AGE: ", then converts an integer */
scanf("GRADE: %c", &grade);   /* Discards "GRADE: ", converts a letter grade (probably 'A') */
scanf("SCHOOL: %s", school);  /* Discards "SCHOOL: ", converts a string */
```

The third example above almost certainly overflows the buffer.  `scanf()` will copy input into `school` until it sees the next whitespace character.  If the input is "The University of Virginia", it will save "The", and overflow the buffer by one byte (due to the fact that all C-style strings have a zero byte that terminates the string).  If the input is "UVA", it will save "UVA", but still overflow the buffer.  Using the field width flag `%2s` can solve this buffer overflow problem, but then we will only save "Th" or "UV".  In order to convert whitespace, you must use the more complex conversion.  It's more common to use `fgets()` for this type of input.

------------------------------------------------------------

Pointers
--------

Most data is passed by address in C, so you need to be comfortable with pointer syntax.

### Pointer Syntax ###

As mentioned above, C does not have *pass-by-reference*; in fact, C has no reference types at all. The pointer syntax in C, including the *address* (`&`), *dereference* (`*`), and *structure-* or *union-pointer* (`->`, an implicit dereference) operators, is exactly the same as in C++.

References in C++ provide *syntactic sugar* abstracting away from the programmer the need to explicitly dereference pointers.  A C++ programmer transitioning to C must keep straight exactly what type a variable represents and access its data accordingly.  From the perspective of the compiler developer, there is little difference between references and pointers, and it would seem that Kernighan and Ritchie (the creators of the C programming language) made a conscious decision to require the more explicit syntax of C, probably because it forces programmers to understand their data.

### malloc() and free() ###

In C++ you allocate storage from the heap with `new`, and you return it to the heap with `delete`.  `new` and `delete` are operators, which can even be overloaded, and which, by default, automatically call constructors or destructors for you.

Heap control in C is a bit lower level.  Allocation from the heap is achieved through a call to `malloc()`, which returns a pointer to the newly allocated space on success or `NULL` on failure (i.e., if you are out of memory).  It is important to check the return value of `malloc()` before attempting to access the returned storage.  The storage allocated by `malloc()` is not initialized in any way, though the related functions `calloc()` and `realloc()` (which we will see a bit later in the course) do perform some specific initializations.  You will need to explicitly run initialization subroutines on data structures that you allocate in C.

`malloc()` has the prototype:

```
void* malloc(size_t size)
```

You must explicitly tell it how much storage you require.  The `sizeof` operator is useful here.

`free()` is used to deallocate storage originally allocated with `malloc()`, `calloc()`, or `realloc()`.  `free()` in C is analgous to `delete` in C++.  Its prototype is:

```
void free(void* ptr)
```

It is an error to call `free()` with any address that was not returned by one of the `malloc()` family functions above.  It is an error to call `free()` on a `NULL` pointer.  It is also an error to call `free()` twice on the same address.  Any one of these errors will corrupt your heap. This corruption will manifest in unusual ways which will be very difficult to debug and which will not have any obvious relationship with the root cause (if you are lucky, it will cause a segmentation fault).

The easiest way to debug a memory error is not to make it in the first place. With care, this is easier than it sounds.  Firstly, know when you need dynamic allocation; don't use it if you don't have to.  Secondly, as you would do in C++, write constructors and destructors for all of your data structures, and be consistent about using them.  These functions should handle your heap control and error checking explicitly, so that they are implicit in the code that uses the storage.

If you do manage to develop memory errors, the `MALLOC_CHECK_` environment variable may be helpful (see the `malloc()` manual page), as may the [Electric Fence library](http://en.wikipedia.org/wiki/Electric_Fence).

### Examples ###

```
#include <stdio.h>
#include <stdlib.h>

/* A struct is like a class, but without methods */
struct foo {
  int x;
  struct foo *next;
};


void main() {
  int *p;
  struct foo *list, *tmp;

  /* dynamically allocate an array of ints */
  p = (int *) malloc(sizeof (int) * 5);
  p[1] = 10;
  printf ("%d\n", p[1]);

  /* free up that array */
  free(p);

  /* calling free(p) again is an error, and will crash the program */
}
```

------------------------------------------------------------

Derived types
-------------

Like C++, C allows programmers to derive types from existing types.  There are several kinds of derived types, including *structures*, *unions*, and *enumerated types*.

### struct ###

C++ does not have classes, but it does have structures.  Early versions of C++ were called *C with Classes*; the C++ "compiler" was little more than a preprocessor, and *class* syntactical constructs were converted to structures so that the output could be compiled by a C compiler.

A structure definition has the following format:

```
struct name {
  type1 member1;
  type2 member2;
  ...
  typen membern;
};
```

In the above, *name* is optional.  If omitted, the structure is said to be *anonymous*; in general, you probably don't want that.  Within the curly braces, *struct name* is an incomplete type or *forward reference* and can be used to build recursive structures.  *struct name* is fully defined after the closing curly brace, and instances can be declared at that point.

The following might be a good definition for a list item data structure.  We'll look at more of the list class further on:

```
struct list_item {
  struct list_item *prev, *next;
  void *datum;
} list_item_t;
```

Note that in pure C, you will have to declare such a variable either on the last line (this is how `list_item_t` was declared) or via a `struct list_item foo` command.  Note that we have to put `struct` in there (the requirement to list the `struct` (or `class` or `union`) was removed in C++, and some C compilers are lax on requiring it.

### union ###

A union is a type for which the compiler allocates space sufficient only for the largest member, not for all members.  At any moment in a union instance's lifetime, only one member is valid.  It is the responsibility of the programmer to ensure that the data is accessed correctly.  The syntax of a union declaration is identical to that of a struct declaration, save the keyword.

An anonymous union provides useful syntactic sugar as a structure member.  Take the following example:

```
struct {
  int type;
  union {
    int i;
    float f;
    double d;
  };
} s;

switch (s.type) {
case 0:
  printf("%d\n", s.i);
  break;
case 1:
  printf("%+2.3f\n", s.f);
  break;
case 2:
  scanf("%lf", &s.d);
  break;
}
```

and compare with:

```
union ifd_t {
  int i;
  float f;
  double d;
};

struct {
  int type;
  union ifd_t u;
} s;

switch (s.type) {
case 0:
  printf("%d\n", s.u.i);
  break;
case 1:
  printf("%+2.3f\n", s.u.f);
  break;
case 2:
  scanf("%lf", &s.u.d);
  break;
}
```

*C with Classes* used unions and function pointers to implement [polymorphism](http://en.wikipedia.org/wiki/Polymorphism_%28computer_science%29).

### Function pointers ###

Function pointers are useful in many instances.  The most common of those include function tables (arrays of function pointers), implementation of code in which you may not statically know what function will be called (like `qsort()` and `bsearch()`; technically *all* instances in which you should use function pointers fall under this heading), and implementation of object oriented code in C.

Syntactically, a function pointer looks like a function prototype, except that the "function name" (actually the name of the pointer) is wrapped in parenthesis with a pointer star at the beginning.  For example:

```
int (*pprintf)(const char *format, ...)
```

defines a pointer that can point to `printf()` (not particularly useful).  A function's name, without parenthesis, evaluates to its address, thus we can assign the address of `printf()` to `pprintf` with the statement:

```
pprintf = printf;
```

and you can call `printf()` through the `pprintf` pointer with:

```
pprintf("Hello, World!\n");
```

### qsort() ###

`qsort()`, short for quick sort, can sort arrays of data of arbitrary type.  In implementing `qsort()`, the subroutine has no knowledge of how to compare the arbitrary elements being sorted, thus `qsort()` takes a pointer to a comparison function.  Its full prototype looks like this:

```
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```

The comparison function takes pointers to two elements of the array starting at base and returns negative, zero, or positive if the first is smaller than, equal to, or larger than the second, respectively.  The array starting at base has nmemb elements of size size.

### Object-Oriented C ###

With `list_item_t` defined as above, consider the following:

```
struct list {
  list_item_t *head, *tail;
  unsigned length;
  int (*compare)(const void *key, const void *with);
  void (*datum_delete)(void *);
};
```

This is a type definition for an object-oriented doubly-linked list class in C.  `list_item_t` contains a pointer to a `void` type.  In other words, it can point to anything, so if we want to do sorted insert, we need a comparison function, just as in `qsort()`.  Furthermore, if we destroy the list, we probably want the data contained in it to be returned to the heap.  If that requires a only shallow delete, `free()` can be passed to the constructor, otherwise, a destructor for the stored type must be passed.  If the list is not to be sorted, or if the data is not to be destroyed with the list, one or both of compare and delete_datum can be `NULL`.

Note that, for the exercise below, you need not implement object-oriented C code; your code can be pure C.

------------------------------------------------------------

Exercise
--------

This exercise is to be developed in C, and compiled using clang (NOT clang++!).  The exercise is to implement a ***very simple*** linked list.  Your program should do the following:

1. Read in an integer, which we'll call *n*
2. Read in *n* more ints, and put those into a linked list
     - The linked list must be dynamically allocated
3. Print out that linked list (we don't care the order)
4. Properly deallocate the linked list

That's it - the point is to have you use many of the features of C discussed here (`printf()`, `scanf()`, structs, `malloc()`, and `free()`).  We aren't looking for multiple subroutines, a full list class, etc. - a long `main()` function is just fine.  Don't make this more complicated than necessary!

The program should be in a file called linkedlist.c.  A sample execution run might look like the following:

```
Enter how many values to input: 4
Enter value 1: 2
Enter value 2: 4
Enter value 3: 6
Enter value 4: 8
8
6
4
2
```
