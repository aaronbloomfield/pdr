#include <iostream>
using namespace std;
extern "C" int max(int x, int y);

int max(int x, int y) {
    int theMax;
    if (x > y) 		// if x > y then x is max
        theMax = x;
    else 		// else y is the max
        theMax = y;
    return theMax;	// return the max
}

int main() {
    int theValue1=0, theValue2=0;
    cout << "Enter value 1: " << endl;
    cin >> theValue1;
    cout << "Enter value 2: " << endl;
    cin >> theValue2;
    int theResult = max(theValue1, theValue2);
    cout << "The result is: " << theResult << endl;
    return 0;
}
