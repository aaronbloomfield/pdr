// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

extern "C" long addOrMult (bool addOrMult, long* arr, long n);

int  main () {

    // delcare the local variables
    long  n, *vec;

    // make sure longs are 8 bytes in size, else this program won't work right
    assert (sizeof (long) == 8);

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
    srand ( (unsigned) time (NULL) );

    // fill the array with random values
    for (long i = 0; i < n; ++i) {
        vec[i] = (rand() % 50) + 1;
        cout << "\tvec[" << i << "] = " << vec[i] << endl;
    }

    bool which = rand() % 2;

    if (which) {
        // sum up the array and print out results
        cout << "boolean is true, summing array" << endl;
        long sum = addOrMult (true, vec, n);
        cout << "The sum of all array elements is " << sum << endl;
    } else {
        cout << "boolean is false, multiplying array" << endl;
        long prod = addOrMult (false, vec, n);
        cout << "The product of all array elements is " << prod << endl;
    }

    // properly deallocate the array
    delete [] vec;

    // all done!
    return 0;
}
