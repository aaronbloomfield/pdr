#include <iostream>
using namespace std;

void subroutine (int a[], int s) {
    a[5] = 9999;
}

int main() {
    cout << "hello world" << endl;

    int a1[3];
    int a2[] = { 1, 2, 3 };
    int* a3 = new int[3];

    // a1 = a2; // not allowed

    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a3[0] = 1;
    a3[1] = 2;
    a3[2] = 3;

    if ( a1 == a2 )
        cout << "they are the same" << endl;
    else
        cout << "they are different" << endl;

    //a3 = a1;

    cout << "a1: " << a1[0] << ", " << a1[1] << ", " << a1[2] << endl;
    cout << "a2: " << a2[0] << ", " << a2[1] << ", " << a2[2] << endl;
    cout << "a3: " << a3[0] << ", " << a3[1] << ", " << a3[2] << endl;

    subroutine (a2, 3);

    cout << "a1: " << a1[0] << ", " << a1[1] << ", " << a1[2] << endl;
    cout << "a2: " << a2[0] << ", " << a2[1] << ", " << a2[2] << endl;
    cout << "a3: " << a3[0] << ", " << a3[1] << ", " << a3[2] << endl;

    delete [] a3;

    return 0;
}
