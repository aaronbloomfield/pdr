/* Author: Michele Co, CS 216, Spring 2007
 * Filename: dynamic_allocation.cpp
 * Description: Demonstrates dynamic allocation and de-allocation
 *			using new and delete
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    // read in a value from the user
    cout << "Please enter an integer value: " ;
    cin >> n;

    // use the user's input to create an array of int
    int * ages = new int [n];

    // use a loop to prompt the user to initialize the array
    for (int i=0; i < n; i++) {
        cout << "Enter a value for ages[ " << i << " ]: " ;
        cin >> ages[i];
    }

    // print out the contents of the array
    for(int i=0; i<n; i++) {
        cout << "ages[ " << i << " ]: " << ages[i] << " , ";
    }
    cout << endl;

    // finished with the array, clean up the memory used by calling delete
    delete [] ages;
    return 0;
}
