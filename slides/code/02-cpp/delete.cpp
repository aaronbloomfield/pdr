#include <iostream>
#include <string>
using namespace std;

int main() {
    string * pointerToString = new string("hi");
    // some code that uses pointerToString here
    delete pointerToString;
    return 0;
}
