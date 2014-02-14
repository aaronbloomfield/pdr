#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


#include "binarynode.h"
#include <iostream>       // For NULL
#include <string>

using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

class BinarySearchTree {
public:
    explicit BinarySearchTree( const string & notFound );
    BinarySearchTree( const BinarySearchTree & rhs );
    ~BinarySearchTree( );

    int GetLeftLinksFollowed() const;
    int GetRightLinksFollowed() const;
    double exp_path_length();
    int int_path_length(BinaryNode *t, int depth);

    int card_of() const;
    const string & findMin( ) const;
    const string & findMax( ) const;
    const string & find( const string & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert( const string & x );
    void remove( const string & x );

    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

private:
    const string ITEM_NOT_FOUND;
    BinaryNode *root;
    mutable int num_nodes;
    mutable int LeftLinksFollowed;
    mutable int RightLinksFollowed;

    const string & elementAt( BinaryNode *t ) const;

    void insert( const string & x, BinaryNode * & t ) const;
    void remove( const string & x, BinaryNode * & t ) const;
    BinaryNode * findMin( BinaryNode *t ) const;
    BinaryNode * findMax( BinaryNode *t ) const;
    BinaryNode * find( const string & x, BinaryNode *t ) const;
    void makeEmpty( BinaryNode * & t ) const;
    void printTree( BinaryNode *t ) const;
    BinaryNode * clone( BinaryNode *t ) const;
};

#endif
