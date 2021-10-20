#include <iostream>
using namespace std;

// can you find the 12 errors in this program?

// there are multiple categories of errors:
// category A: those that will cause the program to crash
// category B: those that will not cause the program to crash and that the address sanitizer will find
// category C: those that will not cause the program to crash and that the address sanitizer will NOT find
// category D: these are logical, bad prgramming, or other errors, but will not cause a run-time or compile-time error
// category E: those that compiling with -Wall will find
// category F: warnings only

// there are multiple ways to compile this:
// - `clang++ -Wno-everything errors.cpp` to generate no warnings so you can try to find the errors
// - `clang++ -Wall errors.cpp` to generate lots of warnings
// - `clang++ -fsanitize=address -fno-omit-frame-pointer -g errors.cpp` to run the address sanitizer


int n = 7;

class foo {
    int* k, *m, *p;

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
        int* b;
        delete b;
    }
};


int main() {
    foo x;
    int* i = new int (5);
    int* q = new int (7);
    int* j = new int[4];
    int* l = new int (7);
    int* o;

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
