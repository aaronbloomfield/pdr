#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avlnode.h"
#include <iostream>       // For NULL

// AvlTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

class AvlTree {
public:
    explicit AvlTree( const string & notFound );
    AvlTree( const AvlTree & rhs );
    ~AvlTree( );

    double exp_path_length();
    int GetLeftLinksFollowed() const;
    int GetRightLinksFollowed() const;
    int GetSingleRotations() const;
    int GetDoubleRotations() const;
    int card_of() const;
    const string & findMin( ) const;
    const string & findMax( ) const;
    const string & find( const string & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    int int_path_length(AvlNode *t, int depth);

    void makeEmpty( );
    void insert( const string & x );
    void remove( const string & x );

    const AvlTree & operator=( const AvlTree & rhs );

private:
    const string ITEM_NOT_FOUND;
    AvlNode *root;
    mutable int num_nodes;
    mutable int LeftLinksFollowed;
    mutable int RightLinksFollowed;
    mutable int SingleRotations;
    mutable int DoubleRotations;

    const string & elementAt( AvlNode *t ) const;

    void insert( const string & x, AvlNode * & t ) const;
    AvlNode * findMin( AvlNode *t ) const;
    AvlNode * findMax( AvlNode *t ) const;
    AvlNode * find( const string & x, AvlNode *t ) const;
    void makeEmpty( AvlNode * & t ) const;
    void printTree( AvlNode *t ) const;
    AvlNode * clone( AvlNode *t ) const;

    // Avl manipulations
    int height( AvlNode *t ) const;
    int max( int lhs, int rhs ) const;
    void rotateWithLeftChild( AvlNode * & k2 ) const;
    void rotateWithRightChild( AvlNode * & k1 ) const;
    void doubleWithLeftChild( AvlNode * & k3 ) const;
    void doubleWithRightChild( AvlNode * & k1 ) const;
};

#endif
