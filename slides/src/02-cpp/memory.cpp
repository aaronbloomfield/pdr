#include <iostream>
using namespace std;

class Foo {
    int x, y;
};

int main() {
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(Foo): " << sizeof(Foo) << endl;

    Foo *foo = new Foo();
    Foo *bar = new Foo();

    cout << "1st Foo: " << foo << endl;
    cout << "2nd Foo: " << bar << endl;

    int diff = ((int)bar)-((int)foo);

    cout << "Difference: " << diff << endl;

    delete foo;
    delete bar;
    return 0;
}
