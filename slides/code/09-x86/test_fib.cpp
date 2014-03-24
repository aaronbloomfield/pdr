#include <iostream>
using namespace std;

extern "C" int fib(int n);

int fib(int n) {
    if ((n==0) || (n==1))
        return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int theValue = 0;
    cout << "Enter value for fib(): " << endl;
    cin >> theValue;
    int theResult = fib(theValue);
    cout << "The result is: " << theResult << endl;
    return 0;
}
