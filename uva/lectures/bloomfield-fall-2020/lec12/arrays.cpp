// compile with:
// clang++ -Wall arrays.cpp

#include <iostream>
using namespace std;

void subroutine(int a[], int s) {
    //cout << a[1000000] << endl;
    for ( int i = 0; i < s; i++ )
        cout << a[i] << endl;
    cout << a[100] << endl;
    a[100] = 10;
    cout << a[100] << endl;
}

int main() {
    int a1[3];
    int a2[] = { 1, 3, 5 };
    int *a3 = new int[3];

    a1[0] = 1;
    a1[1] = 3;
    a1[2] = 5;

    cout << "Hello world" << endl;
    cout << "a1: " << a1[0] << ", " << a1[1] << ", " << a1[2] << endl;
    cout << "a2: " << a2[0] << ", " << a2[1] << ", " << a2[2] << endl;
    cout << "a3: " << a3[0] << ", " << a3[1] << ", " << a3[2] << endl;

    if ( a1 == a2 ) // generates warning
        cout << "same" << endl;

    subroutine(a1, 4); // we are intentionally passing the wrong array size

    //a3 = nullptr; // allowed, but causes a memory leak
    //a1 = nullptr; // not allowed -- compile error
    //a3 = a2;      // not allowed -- compile error

    delete [] a3;

    return 0;
}
