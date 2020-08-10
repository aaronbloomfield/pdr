/*
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function printList()
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

// When reading in ListItr.h first, it starts reading in this file
// before declaring that ListItr is a class.  This file then include
// ListItr.h, but beacuse of the #ifndef LISTITR_H statement, the code
// in that file is not read.  Thus, in this case, this List.h file
// will be read in, and will not know that ListItr is a class, which
// will cause compilation problems later on in this file.  Got it?
// Isn't C++ fun???
class ListItr;

class List {
public:
    // The default constructor.
    // It should initialize all private data members
    // and set up the basic list structure with the dummy head and tail nodes.
    List();

    // The copy constructor.
    // It should create a **new** list of ListNodes whose contents
    // are the same values as the ListNodes in `source`.
    List(const List& source);

    // The destructor.
    // It should empty the list and reclaim the memory allocated in the constructor for head and tail.
    ~List();

    // The copy assignment operator.
    // It should copy the contents of every ListNode in `source`
    // into an **existing** list (the reference to the calling List object itself).
    List& operator=(const List& source);

    // Returns true if empty, else false
    bool isEmpty() const;

    // Removes (deletes) all items except the dummy head/tail.
    // The list should be a working empty list after this.
    void makeEmpty();

    // Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
    ListItr first();

    // Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
    ListItr last();

    // Inserts x after current iterator position
    void insertAfter(int x, ListItr position);

    // Inserts x before current iterator position
    void insertBefore(int x, ListItr position);

    // Inserts x at tail of list
    void insertAtTail(int x);

    // Returns an iterator that points to the first occurrence of x.
    // When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
    // This makes sense because you can test the return from find() to see if isPastEnd() is true.
    ListItr find(int x);

    // Removes the first occurrence of x
    void remove(int x);

    // Returns the number of elements in the list
    int size() const;

private:
    ListNode* head;       // Dummy node representing the beginning of the list
    ListNode* tail;       // Dummy node representing the end of the list
    int count;            // Number of elements in the list
};

// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!
void printList(List& source, bool forward);

#endif
