/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();                // Constructor

private:
    int value;                 // The value of the node!
    ListNode *next, *previous; // For doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class List;

    // ListItr needs access to value
    friend class ListItr;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.
};

#endif
