// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int vecsum (int *, int);

// Purpose: This main program produces a vector of random
//          numbers between 0 and 99, then calls the
//          externally defined function 'vecsum' to add
//          up the elements of the vector.
// Author:  Adam Ferrari

int  main () {
    int  n, *vec, sum;
    cout << "Please enter a vector size:  ";
    cin >> n;

    // sanity check the vector size
    if (n <= 0) {
        cerr << "Vector size must be greater than zero.\n";
        return 1;
    }

    // allocate, initialize, and display vector
    vec = new int[n];

    // use current time as random seed
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        vec[i] = rand() % 100;
        cout << "\tvec[" << i << "] = " << vec[i] << endl;
    }

    // sum up the vector and print out results
    sum = vecsum(vec, n);
    cout << "The sum of all vector elements is " << sum << endl;
    return 0;
}
