#include "timer.h"

#include <iostream>

using namespace std;

// this main method just counts the time taken to iterate 1 billion
// times through an idle loop
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 2) {
        cerr << "usage: " << argv[0] << " <iterations>" << endl;
        return 1;
    }

    // convert the second parameter to a int
    int e = stoi(argv[1]);

    // compute 10^e
    long n = 1;
    for (int i = 0; i < e; i++) {
        n *= 10;
    }

    timer t;
    t.start();
    // do something that takes some time...
    for (long i = 0; i < n; i++);
    t.stop();
    cout << t << endl;
}
