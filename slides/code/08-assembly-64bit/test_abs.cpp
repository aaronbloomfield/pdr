#include <iostream>
using namespace std;
extern "C" long absolute_value(long x);

long absolute_value(long x) {
    if (x<0)	// if x is negative
        x = -x;	// negate x
    return x;	// return x
}

int main() {
    long theValue=0;
    cout << "Enter a value: " << endl;
    cin >> theValue;
    long theResult = absolute_value(theValue);
    cout << "The result is: " << theResult << endl;
    return 0;
}
