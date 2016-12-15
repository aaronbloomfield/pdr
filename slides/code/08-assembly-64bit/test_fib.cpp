#include <iostream>
using namespace std;

extern "C" long fib(unsigned int n);

long fib(unsigned int n) {
    if ((n==0) || (n==1))
        return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    unsigned int theValue = 0;
    cout << "Enter value for fib(): " << endl;
    cin >> theValue;
    long theResult = fib(theValue);
    cout << "The result is: " << theResult << endl;
    return 0;
}
