/*
 * Filename: ListItr.h
 * Description: ListItr class definition
 */
#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    ListItr();			//Constructor
    ListItr(ListNode* theNode);	// One parameter constructor
    bool isPastEnd() const;	//Returns true if past end position
    // in list, else false
    bool isPastBeginning() const;//Returns true if past first position
    // in list, else false
    void moveForward();	//Advances current to next position in list
    //(unless already past end of list)
    void moveBackward();	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
    int retrieve() const;	//Returns item in current position

private:
    ListNode* current;		//holds the position in the list
    friend class List;	// List class needs access to “current”
    // ListNode's private data members
};

#endif
/* end of ListItr.h */
