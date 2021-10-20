#include <iostream>
using namespace std;

void notswap (int x, int y) { // formal parameters
    int temp = x;
    x = y;
    y = temp;
}

void swap_r (int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap_p (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 0;
    int b = 3;
    cout << "Before notswap(): a: " << a << ", b: "
         << b << endl;
    notswap (b, a); // actual parameters
    cout << "Before swap_p(): a: " << a << ", b: "
         << b << endl;
    swap_p (&b, &a);
    cout << "After swap_p(): a: " << a << ", b: "
         << b << endl;
    swap_r (b, a);
    cout << "After swap_r(): a: " << a << ", b: "
         << b << endl;
    return 0;
}
