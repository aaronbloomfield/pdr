/* binarysearchtree.cpp: method implementations for binary search tree */

#include "binarysearchtree.h"

/**
* Implements an unbalanced binary search tree.
* Note that all "matching" is based on the < method.
*/

/**
* Construct the tree.
*/
BinarySearchTree::BinarySearchTree( const string & notFound )
    : ITEM_NOT_FOUND( notFound ), root( NULL ) {
    RightLinksFollowed = 0;
    LeftLinksFollowed = 0;
    num_nodes = 0;
}


/**
* Copy constructor.
*/
BinarySearchTree::BinarySearchTree( const BinarySearchTree & rhs )
    : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ), root( NULL ) {
    *this = rhs;
}

/**
* Destructor for the tree.
*/
BinarySearchTree::~BinarySearchTree( ) {
    makeEmpty( );
}

/**
* Insert x into the tree; duplicates are ignored.
*/

void BinarySearchTree::insert( const string & x ) {
    insert( x, root );
}

/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void BinarySearchTree::remove( const string & x ) {
    remove( x, root );
}

/**
* Returns the number of left links followed so far in the tree.
*/
int BinarySearchTree::GetLeftLinksFollowed( ) const {
    return LeftLinksFollowed;
}

/**
* Returns the number of right links followed so far in the tree.
*/

int BinarySearchTree::GetRightLinksFollowed( ) const {
    return RightLinksFollowed;
}

/**
* Returns the cardinality (number of nodes) in the tree.
*/

int BinarySearchTree::card_of( ) const {
    return num_nodes;
}


double BinarySearchTree::exp_path_length( )
/*
**  Calculate the expected path length of the tree
**  This is the public version, without a parameter.
**  NOTE that it recursively invokes int_path_length()
*/
{
    // YOUR CODE HERE
    return -99.0;  // stub, remove after writing your code
}

int BinarySearchTree::int_path_length(BinaryNode *t, int depth) {
    // Your code here
    return -99; // remove after writing your code
}

/**
* Find the smallest item in the tree.
* Return smallest item or ITEM_NOT_FOUND if empty.
*/

const string & BinarySearchTree::findMin( ) const {
    return elementAt( findMin( root ) );
}

/**
* Find the largest item in the tree.
* Return the largest item of ITEM_NOT_FOUND if empty.
*/

const string & BinarySearchTree::findMax( ) const {
    return elementAt( findMax( root ) );
}

/**
* Find item x in the tree.
* Return the matching item or ITEM_NOT_FOUND if not found.
*/
const string & BinarySearchTree::find( const string & x ) const {
    return elementAt( find( x, root ) );
}

/**
* Make the tree logically empty.
*/

void BinarySearchTree::makeEmpty( ) {
    // call the private makeEmpty() routine
    makeEmpty( root );
}

/**
* Test if the tree is logically empty.
* Return true if empty, false otherwise.
*/

bool BinarySearchTree::isEmpty( ) const {
    return root == NULL;
}

/**
* Print the tree contents in sorted order.
*/

void BinarySearchTree::printTree( ) const {
    if ( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree( root );
}

/**
* Deep copy.
*/

const BinarySearchTree & BinarySearchTree::operator=( const BinarySearchTree & rhs ) {
    if ( this != &rhs ) {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}

/**
* Internal method to get element field in node t.
* Return the element field or ITEM_NOT_FOUND if t is NULL.
*/
const string & BinarySearchTree::elementAt( BinaryNode *t ) const {
    return t == NULL ? ITEM_NOT_FOUND : t->element;
}

/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the tree.
* Set the new root.
*/
void BinarySearchTree::insert( const string & x, BinaryNode * & t ) const {
    if ( t == NULL ) {
        t = new BinaryNode( x, NULL, NULL );
    } else if ( x < t->element ) {
        insert( x, t->left );
    } else if ( t->element < x ) {
        insert( x, t->right );
    } else
        ;
}

/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the tree.
* Set the new root.
*/
void BinarySearchTree::remove( const string & x, BinaryNode * & t ) const {
    if ( t == NULL )
        return;   // Item not found; do nothing
    if ( x < t->element )
        remove( x, t->left );
    else if ( t->element < x )
        remove( x, t->right );
    else if ( t->left != NULL && t->right != NULL ) { // Two children
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    } else {
        BinaryNode *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/

BinaryNode * BinarySearchTree::findMin( BinaryNode *t ) const {
    if ( t == NULL )
        return NULL;
    if ( t->left == NULL )
        return t;
    return findMin( t->left );
}

/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/

BinaryNode * BinarySearchTree::findMax( BinaryNode *t ) const {
    if ( t != NULL )
        while ( t->right != NULL )
            t = t->right;
    return t;
}

/**
* Internal method to find an item in a subtree.
* x is item to search for.
* t is the node that roots the tree.
* Return node containing the matched item.
*/
BinaryNode * BinarySearchTree::find( const string & x, BinaryNode *t ) const {
    if ( t == NULL )
        return NULL;
    else if ( x < t->element ) {
        return find( x, t->left );
    } else if ( t->element < x ) {
        return find( x, t->right );
    } else
        return t;    // Match
}
/****** NONRECURSIVE VERSION*************************

BinaryNode *
BinarySearchTree::find( const string & x, BinaryNode *t ) const
{
while( t != NULL )
if( x < t->element )
t = t->left;
else if( t->element < x )
t = t->right;
else
return t;    // Match

return NULL;   // No match
}
*****************************************************/

/**
* Internal method to make subtree empty.
*/

void BinarySearchTree::makeEmpty( BinaryNode * & t ) const {
    if ( t != NULL ) {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

/**
* Internal method to print a subtree rooted at t in sorted order.
*/

void BinarySearchTree::printTree( BinaryNode *t ) const {
    if ( t != NULL ) {
        printTree( t->left );
        cout << t->element << endl;
        printTree( t->right );
    }
}

/**
* Internal method to clone subtree.
*/
BinaryNode * BinarySearchTree::clone( BinaryNode * t ) const {
    if ( t == NULL )
        return NULL;
    else
        return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
}
