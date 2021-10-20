// Hello World!

#include <iostream>
using namespace std;


int max (int a, int b);


int main() {
    int x = 7;
    cout << "Hello world" << endl;

    cout << max (1, 2) << endl;
    cout << x << endl;

    if ( (x = 0) ) // I is a bad programmer
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << x << endl;
    return 0;
}


int max (int a, int b) {
    if ( a > b )
        return a;
    else
        return b;
}
