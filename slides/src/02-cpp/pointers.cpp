/* Author: Michele Co, CS 216, Spring 2007
 * Filename: pointers.cpp
 * Description: Examples demonstrating pointers and C++ syntax related to pointers
 */
#include <iostream>
using namespace std;

int main() {
    // declare and initialize some int variables
    int x = 1;
    int y = 5;

    // declare a pointer to int and initialize to the address of x
    int * x_pointer = &x;

    // print the values of each of these variables
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    // change the value of the memory pointed to by x_pointer
    // by dereferencing and assigning a new value
    *x_pointer = 2;

    // print the values of all variables
    cout << "After *x_pointer = 2 " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    // change the address that x_pointer points to, to y
    x_pointer = &y;

    // print the values of all variables
    cout << "After x_pointer = &y " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    // change the value of the memory pointed to by x_pointer
    // by dereferencing and assigning a new value
    *x_pointer = 3;

    // print the values of all variables
    cout << "After *x_pointer = 3 " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    return 0;
}
