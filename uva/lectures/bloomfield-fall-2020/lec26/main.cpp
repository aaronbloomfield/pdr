// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

extern "C" void factArray (long* arr, long n);
extern "C" long factorial (long n);

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
        vec[i] = (rand() % 10) + 3;
        cout << "\tvec[" << i << "] = " << vec[i] << endl;
    }

    // call the assembly routine
    factArray (vec, n);

    // print out the results of the array
    cout << endl << "factorialized array is: " << endl;
    for (long i = 0; i < n; ++i)
        cout << "\tvec[" << i << "] = " << vec[i] << endl;

    // a call to factorial() as well
    cout << "\nAnd the factorial of 10 is: " << factorial (10) << endl;

    // properly deallocate the array
    delete [] vec;

    // all done!
    return 0;
}
