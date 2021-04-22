// C++
#include <iostream>
using namespace std;

int max (int a, int b);

int main() {
    cout << "Hello World" << endl;

    cout << max (3, 4) << endl;

    return 0;
}


int max (int a, int b) {
    if ( a > b )
        return a;
    else
        return b;
}

