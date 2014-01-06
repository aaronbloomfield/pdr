#include <iostream>
using namespace std;

bool even (int x);

bool odd (int x) {
    if ( x == 0 )
        return false;
    else
        return even (x-1);
}

bool even (int x) {
    if ( x == 0 )
        return true;
    else
        return odd (x-1);
}

int main () {
    int x;
    cout << "Enter a non-zero integer: ";
    cin >> x;
    cout << "This number is even: " << even(x) << endl;
    cout << "This number is odd: " << odd(x) << endl;
    return 0;
}
