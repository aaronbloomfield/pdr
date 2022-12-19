#include <iostream>
using namespace std;

class Foo {
public:
    int x = 7;
    Foo() {
        int x = 77;
        cout << x << endl;
        cout << this->x << endl;
    }
    Foo (int x) {
        this->x = x;
        cout << x << endl;
    }
};

int main() {
    Foo f;
    //Foo g();
    Foo h (3);

    Foo* i = new Foo;
    Foo* j = new Foo();
    Foo* k = new Foo (3);

    return 0;
}
