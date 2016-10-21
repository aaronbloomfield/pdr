#include <iostream>
#include <string>
using namespace std;

extern "C" bool compare_string(const char* theStr1, const char* theStr2);

bool compare_string(const char *theStr1, const char *theStr2) {
    // while *theStr1 is not NULL terminator
    // and the current corresponding bytes are equal
    while ( (*theStr1 != 0)
            && (*theStr1 == *theStr2) ) {
        theStr1++;		// increment the pointers to
        theStr2++;		// the next char / byte
    }
    return (*theStr1==*theStr2);
}

int main() {
    string theValue1, theValue2;
    cout << "Enter string 1: " << endl;
    cin >> theValue1;
    cout << "Enter string 2: " << endl;
    cin >> theValue2;
    bool theResult = compare_string(theValue1.c_str(), 					     theValue2.c_str());
    cout << "The result is: " << theResult << endl;
    return 0;
}
