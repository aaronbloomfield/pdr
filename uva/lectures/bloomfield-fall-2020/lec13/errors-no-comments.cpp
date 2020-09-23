#include <iostream>
using namespace std;

// can you find the 12 errors in this program?

// there are multiple ways to compile this:
// - `clang++ -Wno-everything errors.cpp` to generate no warnings so you can try to find the errors
// - `clang++ -Wall errors.cpp` to generate lots of warnings
// - `clang++ -fsanitize=address -fno-omit-frame-pointer -g errors.cpp` to run the address sanitizer


int n = 7;

class foo {
    int *k, *m, *p;

public:
    foo() {
        m = &n;
    }
    ~foo() {
        delete p;
        delete m;
    }
    void what() {
        long a = 0;
        k = (int*) a;
    }
    void huh() {
        int *b;
        delete b;
    }
};


int main() {
    foo x;
    int *i = new int(5);
    int *q = new int(7);
    int *j = new int[4];
    int *l = new int(7);
    int *o;

    delete j;

    delete l;
    *l = n;
    delete i;
    delete l;

    i = nullptr;
    delete i;

    n = *i;
    n = *o;

    x.what();
    x.huh();

    return 1;
}
