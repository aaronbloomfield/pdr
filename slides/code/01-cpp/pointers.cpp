/* Original author: Michele Co, CS 216, Spring 2007
 * Updated by Aaron Bloomfield, CS 2150, Spring 2017
 * Filename: pointers.cpp
 * Description: Examples demonstrating pointers and C++ syntax related to pointers
 *
 * To force 64-bit operation, this file will have to be compiled with
 * the -m64 flag
 */

#include <iostream>
using namespace std;

int main() {
    // declare and initialize some int variables (we use longs to
    // ensure 64-bit operation)
    long y = 5;
    long x = 1;

    // declare a pointer to int and initialize to the address of x
    long * x_pointer = &x;

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
