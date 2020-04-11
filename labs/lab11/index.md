PDR: Laboratory 11: Graphs
==========================

[Go up to the Labs table of contents page](../index.html)

### Objective ###

To become familiar with representing directed acyclic graphs (DAGs), topological sorting, and the traveling salesperson problem.

### Background ###

A graph is a set of vertices connected by edges.  In a directed graph, an edge is an ordered pair of vertices, where you can follow an edge from one vertex to another.  In a directed acyclic graph (DAG), no path starts and ends at the same vertex.  A topological sort orders the vertices in a DAG such that any edge from vertex i to vertex j satisfies i < j.

### Tutorial ###

Go through the [Doxygen tutorial](../../tutorials/11-doxygen/index.html), which is a program that allows you to generate documentation for your code.

### Recommended Readings ###

1. The [Wikipedia page on Topological sort](https://en.wikipedia.org/wiki/Topological_sorting)
2. The [Wikipedia page on the Traveling Salesperson problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
3. [The slides on graphs](../../slides/11-graphs.html)

Procedure
---------

### Pre-lab ###

1. Understand and document the [middleearth.h](middleearth.h.html) ([src](middleearth.h)) and [middleearth.cpp](middleearth.cpp.html) ([src](middleearth.cpp)) files
2. Write a program to compute a topological sort of a graph
3. Document your topological.cpp with doxygen comments
4. Write a Makefile to compile your code and generate documentation
5. Files to download: [prelab-test-full.txt](prelab-test-full.txt), [prelab-test-small.txt](prelab-test-small.txt), [middleearth.h](middleearth.h.html) ([src](middleearth.h)), [middleearth.cpp](middleearth.cpp.html) ([src](middleearth.cpp)), [fileio2.cpp](fileio2.cpp.html) ([src](fileio2.cpp))
6. Files to submit: topological.cpp, middleearth.h/cpp, Makefile, Doxyfile

### In-lab ###

1. Implement a brute-force traveling salesperson solution
2. Document your C++ files with doxygen commands
3. Write a Makefile to compile your code and generate documentation
4. Files to download: [traveling-skeleton.cpp](traveling-skeleton.cpp.html) ([src](traveling-skeleton.cpp)) (which you'll have to rename to traveling.cpp), and your commented middleearth.h / middleearth.cpp code from the pre-lab
5. Files to submit: traveling.cpp, middleearth.h, middleearth.cpp, Makefile, Doxyfile

### Post-lab ###

1. Write a report on the time and space complexity of your pre-lab and in-lab code, and discuss ways to accelerate the travelling salesperson algorithm
2. Files to download: none
3. Files to submit: postlab11.pdf

------------------------------------------------------------

Pre-lab
-------

### Good code documentation ###

For this lab, any code you submit must be properly documented using doxygen.
There are many doxygen commands, and we expect for you to use more than just those that were provided in the tutorial.

### Topological sort ###

Recall from lecture that given a graph *G* = (*V*,*E*), a topological sort of a directed acyclic graph is a linear listing of the vertices such that, for all pairs of vertices *v*,*w* &isin; *V*, *v* is listed before *w* in the topological sort if (*v*,*w*) &isin; *E* (i.e. if there is an edge from *v* to *w* in the graph, then *v* must be listed before *w* in the topological sort).  This implies that if there is a *path* from *v* to *w* (not just an edge), then *v* must still list before *w* in the topological sort.

For the programming part of this lab, you will need to write a program that can perform a topological sort.  This problem is specified in the next section.  The specification is similar to that found in the [International Collegiate Programming Contests](https://icpc.baylor.edu/) -- a problem description, followed by a detailed explanation of the input and the output.

How you represent your graph is up to you -- choices include: node-with-pointers, adjacency list, adjacency matrix, and others.  Just keep in mind that you will have to do a topological sort on this graph.  The program must read in a list of directed edges from a file and (internally) generate the graph from it.

To read in strings from a file in the C++ manner, see the [fileio2.cpp](fileio2.cpp.html) ([src](fileio2.cpp)) file.

### Makefile ###

The first target in your Makefile can be named anything you want, but should do **two** things: compile your code, and run doxygen.  You can have two tabbed lines after the target specifier, which is the easiest way to accomplish this.  In other words, we are just going to call `make`, and we want it to both compile your code and create your doxygen documentation.  You are welcome to have additional targets, such as `clean`, if you would like.

------------------------------------------------------------

Pre-lab Problem: Topological Sort
---------------------------------

It turns out that one of our teaching assistants did not take all of the pre-requisite computer science courses!  That TA is all ready to graduate, but it turns that CS 1110 was never taken.  The department came down hard, and decided to make that TA take all of the courses over again, to have the proper pre-requisite classes completed for each successive class.  But the TA just got a job at Microsoft, and can only take one course a semester while working full time.  In what order should the teaching assistant take the list of required courses to properly fulfill the pre-requisites this time around?

Given the following course pre-requisite graph:

![pre-reqs.svg](pre-reqs.svg)

There are multiple valid orders that the courses can be taken in; each is a valid topological sort:

- cs1110 cs2110 cs2102 cs3330 cs2150 cs4414
- cs1110 cs2110 cs2102 cs2150 cs3330 cs4414
- cs1110 cs2102 cs2110 cs3330 cs2150 cs4414
- cs1110 cs2102 cs2110 cs2150 cs3330 cs4414
- cs1110 cs2110 cs3330 cs2102 cs2150 cs4414

Any one of these topological sorts is sufficient.

### Input ###

The program will consist of a single file, `topological.cpp`, and take a single command-line parameter.  This parameter will specify the file name that contains the input.

The input file will consist of a series of lines that each designate a directed edge.  Each line will have two vertex names, separated by a single space; the edge is directed from the first to the second listed vertex name on a given line.  Every vertex name is a series of alphanumeric characters only (a-z, A-Z, 0-9) without any spaces or punctuation.  Note that case is relevant, so vertex `abc` is distinct from vertex `ABC`.  The edges can be listed in any order.

The end of the input file is signified by two 0s on the same line, separated by a single space.

You can assume that the provided graph is a directed acyclic graph, that it is weakly connected, and thus that there is at least one valid topological sort.  You can further assume that there will not be more than 100 vertices in the graph.

### Output ###

The output is a valid topological sort of the vertices, each separated by one space, and all on one line.  If there are multiple topological sorts, then any valid one is acceptable.  No additional output!

### Example ###

Given the input file:

```
cs2110 cs2150
cs2102 cs2150
cs1110 cs2110
cs3330 cs4414
cs2150 cs4414
cs2110 cs3330
cs1110 cs2102
0 0
```

A valid topological sort would be

```
cs1110 cs2110 cs2102 cs3330 cs2150 cs4414
```

------------------------------------------------------------

In-lab
------

### The Traveling Salesperson ###

You are going to implement a program that will find a solution to the [traveling salesperson problem](https://www-e.ovgu.de/mertens/TSP/TSP.html).  This problem is known to be [NP-complete](https://en.wikipedia.org/wiki/NP-completeness), which means that there is no known efficient solution to the problem.  Thus, we will be implementing a rather inefficient solution -- a brute-force method that tries every possible path combination.

The traveling salesperson problem is as described in lecture.  In brief, you start from a given city (your "home" city), and have to travel to a number of other cities before returning home.  There is a fixed cost between any two cities (miles traveled, dollars spent, time taken, etc).  The goal of this algorithm is to find the least costly path that travels to each of the cities, in any order.

The world we have chosen is [Middle-Earth](https://en.wikipedia.org/wiki/Middle-earth), the location of J.R.R. Tolkien's Hobbit and Lord of the Rings books and movies.  The middleearth.h and middleearth.cpp files contain a class that will create a random 2-dimensional world.  The "randomness" means that it will pick a given number of cities (or places), and randomly place them in the "world".  You can travel from any city to any other city, for a given cost (the distance).  The city names are all from the books and movies, and can be seen at the beginning of the middleearth.cpp file -- there is a textual description in the code as to what all the places are.  The randomness of the world means that cities that are nowhere near each other in the books/movies might be right next to each other in the random world.

When your program is completed, you will need to specify five command-line parameters to execute the traveling salesperson problem.  The parameters are, in order:

1. The x-size (i.e. width) of the world.  We'll use 20 throughout this lab.
1. The y-size (i.e. height) of the world.  We'll use 20 throughout this lab.
1. The number of cities in the world.  There are currently 40 names specified at the top of middleearth.cpp, so you can't specify more than 40 cities.
1. The random seed.  If you specify a given number, the same world will be created each time -- we'll use this, below, when we talk about debugging.  Supplying -1 will create a different random world each time the program is run.
1. The number of cities to visit, other than the "home" city -- this can be as low as 1.

The skeleton code provided ([traveling-skeleton.cpp](traveling-skeleton.cpp.html) ([src](traveling-skeleton.cpp))) already parses the command-line parameters properly.

### STL Helper Functions ###

There are a number of STL functions that will help you in writing this program.  All of these algorithms (and more!) are provided in the `<algorithms>` header file.  This file is already included by traveling-skeleton.cpp.

First, take a look at the `random_shuffle()` method in middleearth.cpp:

```
random_shuffle(cities.begin(), cities.end());
```

This method takes a vector, and will randomly shuffle it, similar to Java's `Collections.shuffle()`.  The parameters specify the amount of the vector that we want to shuffle.  Because we want to shuffle the entire vector, we specify the beginning and end of the list.

The `sort()` method has the same parameters as shuffle, and sorts the list.  It is similar to Java's `Collections.sort()` method.  It returns no value.

The `next_permutation()` method will cycle through each and every permutation of the passed vector.  ***It must start out with a sorted vector***, and will move through each and every possible list ordering until the vector ends up in reverse sorted order.  It takes the same parameters as `random_shuffle()` and `sort()`.  Note that it does not return a new permutation, but instead modifies the vector that is passed in.  It returns `true` if it found another permutation and `false` if there are no more permutations to provide.  Thus, it is often put into a `while` loop.  For an example of using `next_permutation()` in a while loop, see [here](https://en.cppreference.com/w/cpp/algorithm/next_permutation).  This is a good way to iterate through each possible combination of cities to travel to.

### Middle-Earth methods ###

The MiddleEarth class provides a number of methods to help you write your brute-force solution.  The constructor is called by the skeleton code, and uses the parameters read in from the command line.  The `print()` method will print out statistics of the world.

The `printTable()` method will print out a table of the distances between all cities.  Different random seeds will produce different tables, obviously.  This will be useful to help you debug your program.  Redirect it to a file, and then load it up in a spreadsheet program.

The `getDistance()` method will return the distance, as a float, between the two provided cities.  In an effort to make your code as efficient as possible, `getDistance()` has the same expected running time as a hash table.  Lastly, `getItinerary()` will return a vector of the cities that you must visit.  The first city provided is the start (and thus end) city -- you should remove this from the vector before you consider all possible cycles through the graph.

### How to proceed ###

We provide the skeleton code for the algorithm -- your job is to complete traveling.cpp.

1. First complete `printRoute()`, as that will be useful when debugging your code.  It should print a route in the form: `Gladden Fields -> Bywater -> Dagorlad -> Pelennor Fields -> Cirith Ungol -> Gladden Fields`.  Note that we aren't picky about exactly how it's printed, as long as it prints all the cities.
2. Next, complete `computeDistance()`.  You can create a sample string vector to test it, and verify it against the distances in the output of `printTable()`.
3. Start on the `main()` method.  Make sure that you can print out all the permutations of the list of destinations.  Note that for n cities, there are n! possible permutations.  Remember that the start city should not be permuted!
4. At this point, you can now compute the distance and keep track of the minimum cycle length.

Your final program should should print out the shortest path as the last thing printed.  You can print out multiple paths as you find the shortest one, but you should **NOT** print out _every_ path you try.

Note that you are determining a cycle of cities to visit.  So if your cycle has the cities in reverse, then it's still a valid solution.

### Getting your itinerary correct ###

The starting city is **not to be permuted**, as you will always start (and end) at that city.  It's the *other* cities that are going to be permuted through the calls to `next_permutation()`.

### Timing your code ###

Keep in mind that as you increase the size of the city tour, the running time increases exponentially.  Modern-day computers can probably compute about 200,000 routes per second (with well written and optimized code).  Our 10-route cycle took 18 seconds.  A 15 route cycle would take 2.5 months.  A 20 route cycle would take 385,734 years!  Realistically, you shouldn't be trying anything with an itinerary greater than 9 or 10.

And when you are planning on testing long paths, you should really compile your code with the `-O2` compiler option.  It can speed up the program by a factor of two.  

To time your code, enter `time` before the command on the command-line.  For example:

```
student@cassiopeia:~/labs/lab11$ time ./a.out 20 20 20 14 8
./a.out 20 20 20 14 8
Minimum path has distance 53.2757: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields ->
                                   Mirkwood -> Minas Morgul -> Dale -> Bywater -> Weathertop -> Gladden Fields

real    0m0.105s
user    0m0.076s
sys     0m0.020s
student@cassiopeia:~/labs/lab11$ 
```

The time we are looking at is the "user" time; this is how long it took to run the user's program.  The "sys" line is how much time the system was doing things during the program execution, such as I/O.  The "real" time is the "wall time" -- meaning if you had a stop watch, it would report the "real" time.  The "real" time includes many other things, such as other tasks you are doing on the computer -- if you have an animation running in a web browser, for example, it will increase the "real" time, as the system is spending some effort rendering those animations.  We'll only use the "user" time for this lab.

### Sample output ###

For this lab, we will keep the size of the 2-D world fixed at (20,20).  These are the first two command line parameters.  We'll also create a world of 20 cities (chosen from the 40 names in middleearth.cpp) -- this is the third command line parameter.

If the random seed (the fourth parameter) is 14, then the path lengths and paths for the various itinerary lengths are listed below.  Because we are explicitly setting the random seed, it should produce the exact same results each time -- and thus your code should also produce the same results.

The results for a random seed of 14, world size of 20x20 with 20 cities, and various path lengths:

1. Minimum path has distance 26.1857: Gladden Fields -> Pelennor Fields -> Gladden Fields
2. Minimum path has distance 26.4977: Gladden Fields -> Dagorlad -> Pelennor Fields -> Gladden Fields
3. Minimum path has distance 29.7681: Gladden Fields -> Cirith Ungol -> Pelennor Fields -> Dagorlad -> Gladden Fields
4. Minimum path has distance 43.7977: Gladden Fields -> Bywater -> Dagorlad -> Pelennor Fields -> Cirith Ungol -> Gladden Fields
5. Minimum path has distance 48.3503: Gladden Fields -> Cirith Ungol -> Pelennor Fields -> Dagorlad -> Bywater -> Weathertop -> Gladden Fields
6. Minimum path has distance 52.5048: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields -> Dale -> Bywater -> Weathertop -> Gladden Fields
7. Minimum path has distance 52.7636: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields -> Mirkwood -> Dale -> Bywater -> Weathertop -> Gladden Fields
8. Minimum path has distance 53.2757: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields -> Mirkwood -> Minas Morgul -> Dale -> Bywater -> Weathertop -> Gladden Fields
9. Minimum path has distance 53.3647: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields -> Hobbiton -> Mirkwood -> Minas Morgul -> Dale -> Bywater -> Weathertop -> Gladden Fields
10. Minimum path has distance 55.9726: Gladden Fields -> Dagorlad -> Cirith Ungol -> Pelennor Fields -> Hobbiton -> Mirkwood -> Minas Morgul -> Dale -> Trollshaws -> Bywater -> Weathertop -> Gladden Fields

Your cycle may be the same cities but in reverse; this is perfectly acceptable.

Your final program needs to both be able to compile and run with the specified command-line parameters.

### Makefile ###

Your Makefile should have **only one** target, which you can name anything you want.  This target should do **two** things: compile your code, and run doxygen.  You can have two tabbed lines after the target specifier, which is the easiest way to accomplish this.  In other words, we are just going to call `make`, and we want it to both compile your code and create your doxygen documentation.  The in-lab Makefile should have the same dual-purpose target.

------------------------------------------------------------

Post-lab
--------

There are two parts to the post-lab: a complexity analysis of your code, as well as an investigation into acceleration techniques for the traveling salesperson problem.  

The deliverable for the post-lab is a PDF document named postlab11.pdf.

### Complexity analysis ###

For this part of the post-lab, we want you to do a time and space complexity analysis of both of your pre-lab code and your in-lab code.  How long is your algorithm?  In addition to a big-Theta notation, give an explanation as to why.

### Acceleration techniques ###

We all know that the solution for the traveling salesperson is inefficient.  So inefficient that a 20 route tour through Middle Earth (i.e. using the command-line parameters `20 20 20 14 20`) would take over 3 hundred thousand years, assuming the computer can check about 200,000 paths per second.  We could run it on a more efficient computer -- this would help, but not much.  If you are trying to compute a [61-route tour](https://www.google.com/search?q=61!), then there are more possibilities than there are [atoms in the known universe](https://www.universetoday.com/36302/atoms-in-the-universe/).  So it's not likely that you will be able to push that many electrons through your computer, even if you could wait the [10<sup>70</sup>](https://www.google.com/search?q=61!%2F(200000*60*60*24*365.25)) years required.  You might be able to lower that somewhat if you used a more efficient computer -- perhaps to 10<sup>69</sup> years.  That's still longer than the expected life of the universe.

It's safe to say that we can all agree that this problem is very inefficient.  Yet the world record for the longest traveling salesperson solution is a whopping 85,900 cities!  See the [here](https://en.wikipedia.org/wiki/Travelling_salesman_problem#Exact_algorithms) for details.

Let's do a bit of math.  If we assume that a properly coded solution runs in &Theta;(*n*!) time (yours may be different, by the way, but probably not by much), then this size input set would take 85960! steps.  That's 9.61 * 10<sup>386,526</sup> (yes, there are more than 1/3 of a million digits in this number).  Let's assume we could get a fast program to compute 1 million possible paths per second.  With 60 seconds per minute, 60 minutes per hour, 24 hours per day, and 365.25 days per year, that will take 3.04 * 10<sup>386,516</sup> years (the exponent lowered by 10).  With a number this big, a faster computer will not make much of a difference.

The people who computed the 85,900 city traveling salesperson problem obviously did not wait forever for it to compute.  In fact, they managed to compute it in 136 CPU years!  It took far less time to complete (say, 6 months or so), as it ran in parallel on multiple computers.

To accomplish this, they had to use a number of acceleration techniques.

The second part of the post-lab is for you to research other acceleration techniques that can be used to speed up the traveling salesperson problem.  You are welcome to view the Wikipedia page -- however, we also know what's on the Wikipedia page.  So just copying that information down will get you no credit -- you need to understand the acceleration techniques, and write them in your *OWN* words.

Your report should include information on 3 such techniques (again, feel free to start with the 3 that Wikipedia mentions).  You should write sufficient text on each to explain how it would work, the running time, and an estimate of how much faster it would make your code.  You don't need to implement any of these techniques -- just understand (at a high level) how they work.

You should discuss at least one approximation technique (ones that get a reasonable answer, but not necessarily an exact answer) and at least one exact acceleration technique.  Your third one can be either.
