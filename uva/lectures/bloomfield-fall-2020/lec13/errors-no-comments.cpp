#include <iostream>
using namespace std;

// can you find the 12 errors in this program?

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
        //delete p; // NO: uninitialized pointer deletion
        //delete m; // NO: delete statically declared variable
        // no delete k
    }
    void what() {
        long a = 0;
        k = (int*) a; // not a good idea
    }
    void huh() {
        //int *b; // has value nullptr
        //delete b; // YES: bad delete
    }
};


int main() {
    foo x;
    int* i = new int (5);
    int* q = new int (7);
    int* j = new int[4];
    int* l = new int (7);
    int* o;

    delete[] j; // YES: should be delete[]

    delete l;
    //*l = n; // YES: access after delete
    delete i;
    //delete l; // YES: double free()

    cout << *q << endl;

    i = nullptr;
    delete i; // not an error: delete nullptr

    //n = *i; // YES: null pointer access
    //n = *o; // NO: accessing uninitialized variable

    // q is not deleted
    delete q;

    x.what();
    x.huh();

    return 1; // error
}
