// This file contains the main code to test the List class
//
// Copyright (c) 1994, 2014 by Aaron Bloomfield
// Released under a CC BY-SA license
//
// Revision history
// 05-07-94: Main code written
// 07-12-95: Bug updates
// 01-13-14: Modified to fit modern C++ compilers; reformatted

#include <iostream>
#include <stdio.h>
#include "list.h"

using namespace std;

int main() {
    cout << "main(): started." << endl;
    List<int> *l = new List<int>();
    int *n, i;

    l->display();

    cout << "size(): returned " << l->size() << endl;

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    cout << "empty() called, returned " << l->empty() << endl;

    cout << "element(): '" << 2 << "' returned: " << l->element(2) << endl;

    l->push(2);
    l->display();
    cout << "empty() called, returned " << l->empty() << endl;

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    l->push(3);
    l->display();

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    cout << "element(): '" << 2 << "' returned: " << l->element(2) << endl;
    cout << "element(): '" << 4 << "' returned: " << l->element(4) << endl;

    cout << "empty() called, returned " << l->empty() << endl;

    cout << endl;

    l->push(4);
    l->display();

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    l->push(5);
    l->display();

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    cout << "empty() called, returned " << l->empty() << endl;

    cout << endl;

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    n = l->head();
    if ( n == NULL )
        cout << "head(): returned NULL." << endl;
    else
        cout << "head(): returned " << *n << endl;

    n = l->tail();
    if ( n == NULL )
        cout << "tail(): returned NULL." << endl;
    else
        cout << "tail(): returned " << *n << endl;

    cout << "size(): returned " << l->size() << endl;

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    cout << "empty() called, returned " << l->empty() << endl;

    cout << endl;

    l->push(1);
    l->push(2);
    l->push(3);
    l->push(4);
    l->display();

    l->push(5);
    l->display();

    l->push_head(0);
    l->display();

    n = l->pop();
    if ( n == NULL )
        cout << "pop(): list is empty, pop(): returned NULL." << endl;
    else
        cout << "pop(): returned " << *n << endl;

    l->display();

    n = l->pop_head();
    if ( n == NULL )
        cout << "pop_head(): list is empty, pop_head(): returned NULL." << endl;
    else
        cout << "pop_head(): returned " << *n << endl;

    l->display();

    cout << "empty() called, returned " << l->empty() << endl;

    l->clear();
    cout << "clear() called." << endl;

    l->display();
    cout << "empty() called, returned " << l->empty() << endl;

    l->remove(1);
    l->push(1);
    l->display();

    l->remove(1);
    l->display();

    l->push(1);
    l->push(2);
    l->push(3);
    l->push(4);
    l->push(5);
    l->display();

    l->remove(5);
    l->display();

    l->remove(6);
    l->display();

    delete l;

    cout << endl;

    cout << "main(): Goodbye." << endl;

    return 0;
}
