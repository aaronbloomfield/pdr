//
// Bubblesort of an array of 5 integers.
//
// Pass through the array right to left.  On each pass through the
// outer loop, the smallest remaining value will "bubble" over to its
// appropriate final location in the left side of the array.

#include <iostream>

using namespace std;

const int MAX=5;

int main() {
    int A[MAX];
    int temp;
    int k;
    // The following output line should NOT be encoded into IBCM -- it
    // is just to make the C++ implementation easier to understand
    // when run
    cout << "Enter " << MAX << " numbers to sort, one per line." << endl;
    // read in the array values.  For IBCM implementation, assume that
    // array is hard coded AFTER the end of the program to perform
    // bubblesort
    for (k = 0; k < MAX; ++k) {
        cin >> A[k];
    }
    // print out the user input to the screen
    cout << endl << "Original: ";
    for (k = 0; k < MAX; ++k) {
        cout << A[k] << " ";
    }
    // Your IBCM program should be these 2 nested for loops plus some
    // additional variable declarations to store the information you
    // need.  This is what you have to implement in IBCM.
    for (int i = 0; i < MAX; ++i) {
        for (int j = MAX-1; j > i; --j) {
            if (A[j] < A[j-1]) {
                //	swap(A[j], A[j-1]);
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
        // You don't have to worry about all this output for the IBCM
        // version.
        cout << endl << "After Pass "<< i << "  ";
        for (k = 0; k < MAX; ++k) {
            cout << A[k] << " ";
        }
    }
    // You DO NOT have to implement this. It is only provided so that
    // You may build and run the program via g++ to understand how the
    // algorithm works.
    cout << endl << "Sorted: ";
    for (k = 0; k < MAX; ++k) {
        cout << A[k] << " ";
    }
    cout << endl;
}
