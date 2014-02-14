/* avlnode.h : avl node class definition */
#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <string>
using namespace std;

class AvlNode {
    string element;
    AvlNode   *left;
    AvlNode   *right;
    int       height;

    AvlNode( const string & theElement, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element( theElement ), left( lt ), right( rt ), height( h ) { }
    friend class AvlTree;
};

#endif
