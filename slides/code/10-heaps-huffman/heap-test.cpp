// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "binary_heap.h"

binary_heap bh;

int main() {
    srand(time(NULL));
    cout << "isEmpty(): " << bh.isEmpty() << endl;
    try {
        cout << bh.findMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    try {
        cout << bh.deleteMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    cout << "inserting a value into the heap..." << endl;
    bh.insert(rand() % 1000);
    cout << "isEmpty(): " << bh.isEmpty() << endl;
    try {
        cout << bh.findMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    for ( int i = 0; i < 40; i++ )
        bh.insert(rand() % 1000);
    cout << bh.findMin() << endl;
    cout << "size: " << bh.size() << endl;
    bh.print();
    cout << "deleting min..." << endl;
    int min = bh.deleteMin();
    cout << "\t" << min << endl;
    cout << "size: " << bh.size() << endl;
    bh.print();
    cout << "isEmpty(): " << bh.isEmpty() << endl;
    cout << "calling makeEmpty()" << endl;
    bh.makeEmpty();
    cout << "isEmpty(): " << bh.isEmpty() << endl;
    cout << "inserting a value into the heap..." << endl;
    bh.insert(100);
    cout << "size: " << bh.size() << endl;
    cout << "deleting min..." << endl;
    bh.deleteMin();
    cout << "size: " << bh.size() << endl;
    cout << "isEmpty(): " << bh.isEmpty() << endl;
    return 0;
}
