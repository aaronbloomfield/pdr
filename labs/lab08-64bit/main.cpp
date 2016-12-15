// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long vecsum (long*, long);

// Purpose: This main program produces a vector of random numbers
// between 0 and 99, then calls the externally defined function
// 'vecsum' to add up the elements of the vector.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

    // delcare the local variables
    long  n, *vec, sum;

    // how big is the array we want to use?
    cout << "Please enter a array size:  ";
    cin >> n;

    // sanity check the array size
    if (n <= 0) {
        cerr << "Array size must be greater than zero.\n";
        return 1;
    }

    // allocate the array
    vec = new long[n];

    // use current time as random seed
    srand((unsigned) time(NULL));

    // fill the array with random values
    for (long i = 0; i < n; ++i) {
        vec[i] = rand() % 100;
        cout << "\tvec[" << i << "] = " << vec[i] << endl;
    }

    // sum up the array and print out results
    sum = vecsum(vec, n);
    cout << "The sum of all array elements is " << sum << endl;

    // properly deallocate the array
    delete [] vec;

    // all done!
    return 0;
}
