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
    List();                                     // Constructor
    List(const List& source);                   // Copy constructor
    ~List();                                    // Destructor
    List& operator=(const List& source);        // Copy assignment operator
    bool isEmpty() const;                       // Returns true if empty; else false
    void makeEmpty();                           // Removes all items except blank head and tail
    ListItr first();                            // Returns an iterator that points to the ListNode in the first position
    ListItr last();                             // Returns an iterator that points to the ListNode in the last position
    void insertAfter(int x, ListItr position);  // Inserts x after current iterator position
    void insertBefore(int x, ListItr position); // Inserts x before current iterator position
    void insertAtTail(int x);                   // Inserts x at tail of list
    ListItr find(int x);                        // Returns an iterator that points to the first occurrence of x or the dummy tail if not found
    void remove(int x);                         // Removes the first occurrence of x
    int size() const;                           // Returns the number of elements in the list

private:
    ListNode *head, *tail; // Dummy nodes for beginning and end of the list
    int count;             // Number of elements in the list
    friend class ListItr;  // Allow ListItr to access head and tail
};

// printList: non-member function prototype
// prints list forwards when forward is true
// or backwards when forward is false
void printList(List& source, bool forward);

#endif
