#include <iostream>
using namespace std;

// can you find the 12 errors in this program? // error D1: there are 16 errors, not including this one

// there are multiple categories of errors:
// category A: those that will cause the program to crash
// category B: those that will not cause the program to crash and that the address sanitizer will find
// category C: those that will not cause the program to crash and that the address sanitizer will NOT find
// category D: these are logical, bad prgramming, or other errors, but will not cause a run-time or compile-time error
// category E: those that compiling with -Wall will find
// category F: warnings only, not errors

// there are multiple ways to compile this:
// - `clang++ -Wno-everything errors.cpp` to generate no warnings so you can try to find the errors
// - `clang++ -Wall errors.cpp` to generate lots of warnings
// - `clang++ -fsanitize=address -fno-omit-frame-pointer -g errors.cpp` to run the address sanitizer


int n = 7;

class foo {
    int* k, *m; // , *p; // error F1: unused variable warning for p once error B2 is fixed

public:
    foo() {
        m = &n;
        // error D6: should initialize all fields
    }
    ~foo() {
        //delete p; // error B2: delete unitialized or bad pointer
        //delete m; // error A1: delete global variable
        // error D5: k is not deleted, was this intentional?  If so, then insert a comment stating so
    }
    void what() {
        long a = 0;
        k = (int*) a; // error D4: never a good practice to do this
    }
    void huh() {
        // if huh() is called after what(), b is created in the same spot as a, and has value 0 (nullptr)
        //int *b; // // error F3: unused variable warning when error E1 is resolved
        //delete b; // error E1: still technically unititalized, but it is likely to have value 0
    }
};


int main() {
    foo x;
    int* i = new int (5);
    int* q = new int (7);
    int* j = new int[4];
    int* l = new int (7);
    //int *o; // error F3: unused variable warning once error E3 is fixed

    delete[] j; // error E2: delete[] not delete

    delete l;
    //*l = n; // error B1: use after delete
    delete i;
    //delete l; // error A2: double free

    i = nullptr;
    delete i; // red herring -- this is not an error

    delete q; // error B3: no delete of q
    //n = *i; // error A3: null dereference
    //n = *o; // error E3: following unitiailized pointer

    x.what();
    x.huh();

    return 1; // error D2: should return 0
}
