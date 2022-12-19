// Bubblesort of an array of 5 integers.
//
// Pass through the array right to left.  On each pass through the
// outer loop, the smallest remaining value will "bubble" over to its
// appropriate final location in the left side of the array.

#include <iostream>

using namespace std;

const int MAX = 5;

int main() {
    int A[MAX];

    // The following output line should NOT be encoded into IBCM -- it
    // is just to make the C++ implementation easier to understand
    // when run
    cout << "Enter " << MAX << " numbers to sort, one per line." << endl;

    // Read in the array values.  For IBCM implementation, assume that
    // array is hard coded AFTER the end of the program to perform
    // bubblesort
    for (int k = 0; k < MAX; k++) {
        cin >> A[k];
    }

    // print out the user input to the screen
    cout << endl << "Original:";
    for (int k = 0; k < MAX; k++) {
        cout << " " << A[k];
    }
    cout << endl;

    // Your IBCM program should be these 2 nested for loops plus some
    // additional variable declarations to store the information you
    // need.  This is what you have to implement in IBCM.
    cout << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = MAX - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                // swap A[j] and A[j-1]
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }

        // You don't have to worry about all this output for the IBCM version.
        cout << "After Pass " << i << ":";
        for (int k = 0; k < MAX; k++) {
            cout << " " << A[k];
        }
        cout << endl;
    }
    cout << endl;

    // You DO NOT have to implement this. It is only provided so that
    // you may compile and run your program to understand how the
    // algorithm works.
    cout << "Sorted:";
    for (int k = 0; k < MAX; k++) {
        cout << " " << A[k];
    }
    cout << endl;
}
