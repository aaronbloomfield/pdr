#include <iostream>

using namespace std;

class foo {
public:
    void bar() {
        cout << "in foo's bar()" << endl;
    }
};

class qux {
public:
    void bar() {
        cout << "in qux's bar()" << endl;
    }
};

class thud : public qux, public foo {
public:
    virtual void bar() {
        cout << "in thud's bar()" << endl;
    }
};

class bletch : public thud {
public:
    virtual void bar() {
        cout << "in bletch's bar()" << endl;
    }
};

int main() {
    thud* x = new bletch();
    x->bar();
    return 0;
}
