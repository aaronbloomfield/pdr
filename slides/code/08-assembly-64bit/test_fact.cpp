#include <iostream>
using namespace std;

extern "C" long fact(unsigned int n);

long fact(unsigned int n) {
    if ( n==0 )
        return 1;
    return n * fact(n-1);
}

int main() {
    unsigned int theValue = 0;
    cout << "Enter value for fact(): " << endl;
    cin >> theValue;
    long theResult = fact(theValue);
    cout << "The result is: " << theResult << endl;
    return 0;
}
