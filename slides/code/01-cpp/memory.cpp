#include <iostream>
using namespace std;

class Foo {
    long x, y;
};

int main() {
    cout << "sizeof(long): " << sizeof(long) << endl;
    cout << "sizeof(Foo): " << sizeof(Foo) << endl;

    Foo *qux = new Foo();
    Foo *bar = new Foo();

    cout << "1st Foo: " << qux << endl;
    cout << "2nd Foo: " << bar << endl;

    long diff = ((long)bar)-((long)qux);

    cout << "Difference: " << diff << endl;

    delete qux;
    delete bar;
    return 0;
}
