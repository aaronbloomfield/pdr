/*
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function print()
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
    List();				//Constructor
    List(const List& source);	//Copy Constructor
    ~List();			//Destructor
    List& operator=(const List& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    void makeEmpty();	//Removes all items except blank head and tail
    ListItr first(); 		//Returns an iterator that points to
    //the ListNode in the first position
    ListItr last();			//Returns an iterator that points to
    //the ListNode in the last position
    void insertAfter(int x, ListItr position);
    //Inserts x after current iterator position p
    void insertBefore(int x, ListItr position);
    //Inserts x before current iterator position p
    void insertAtTail(int x);	//Insert x at tail of list
    void remove(int x);		//Removes the first occurrence of x
    ListItr find(int x);		//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node

    int size() const; //Returns the number of elements in the list

private:
    ListNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
    friend class ListItr;
};

// printList: non-member function prototype
void printList(List& source, bool direction);
//prints list forwards when direction is true
//or backwards when direction is false
#endif
/* end of List.h */
