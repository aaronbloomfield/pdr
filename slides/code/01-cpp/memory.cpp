#include <iostream>
using namespace std;

class Foo {
    int x, y;
};

int main() {
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(Foo): " << sizeof(Foo) << endl;

    Foo *qux = new Foo();
    Foo *bar = new Foo();

    cout << "1st Foo: " << qux << endl;
    cout << "2nd Foo: " << bar << endl;

    int diff = ((int)bar)-((int)qux);

    cout << "Difference: " << diff << endl;

    delete qux;
    delete bar;
    return 0;
}
