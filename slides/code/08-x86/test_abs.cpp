#include <iostream>
using namespace std;
extern "C" int absolute_value(int x);

int absolute_value(int x) {
    if (x<0)	// if x is negative
        x = -x;	// negate x
    return x;	// return x
}

int main() {
    int theValue=0;
    cout << "Enter a value: " << endl;
    cin >> theValue;
    int theResult = absolute_value(theValue);
    cout << "The result is: " << theResult << endl;
    return 0;
}
