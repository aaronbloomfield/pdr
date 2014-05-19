// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "priority_queue.h"

priority_queue pq;

int main() {
    srand(time(NULL));
    cout << "isEmpty(): " << pq.isEmpty() << endl;
    try {
        cout << pq.findMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    try {
        cout << pq.deleteMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    cout << "inserting a value into the heap..." << endl;
    pq.insert(rand() % 1000);
    cout << "isEmpty(): " << pq.isEmpty() << endl;
    try {
        cout << pq.findMin() << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    for ( int i = 0; i < 40; i++ )
        pq.insert(rand() % 1000);
    cout << pq.findMin() << endl;
    cout << "size: " << pq.size() << endl;
    pq.print();
    cout << "deleting min..." << endl;
    int min = pq.deleteMin();
    cout << "\t" << min << endl;
    cout << "size: " << pq.size() << endl;
    pq.print();
    cout << "isEmpty(): " << pq.isEmpty() << endl;
    cout << "calling makeEmpty()" << endl;
    pq.makeEmpty();
    cout << "isEmpty(): " << pq.isEmpty() << endl;
    return 0;
}
