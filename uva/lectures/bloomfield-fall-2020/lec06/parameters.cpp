#include <iostream>
using namespace std;

void foo(int *a) {
    *a = 5;
}

int main() {
    int x = 10;
    foo(&x);
    cout << x << endl;
    return 0;
}
