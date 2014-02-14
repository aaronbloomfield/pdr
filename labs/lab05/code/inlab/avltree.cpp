/* avltree.cpp */
/**
* Implements an unbalanced Avl search tree.
* Note that all "matching" is based on the compares method.
* @author Mark Allen Weiss
*/
/**
* Construct the tree.
*/

#include "avltree.h"

AvlTree::AvlTree( const string & notFound )
    : ITEM_NOT_FOUND( notFound ), root( NULL ) {
    SingleRotations = 0;
    DoubleRotations = 0;
    RightLinksFollowed = 0;
    LeftLinksFollowed = 0;
    num_nodes = 0;
}

/**
* Copy constructor.
*/
AvlTree::AvlTree( const AvlTree & rhs )
    : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ), root( NULL ) {
    *this = rhs;
}

/**
* Destructor for the tree.
*/
AvlTree::~AvlTree( ) {
    makeEmpty( );
}


/**
* Returns the number of left links follwed so far in the tree.
*/
int AvlTree::GetLeftLinksFollowed( ) const {
    return LeftLinksFollowed;
}

/**
* Returns the number of DoubleRotations so far in the tree.
*/
int AvlTree::GetDoubleRotations( ) const {
    return DoubleRotations;
}

/**
* Returns the number of SingleRotations so far in the tree.
*/
int AvlTree::GetSingleRotations( ) const {
    return SingleRotations;
}

/**
* Returns the number of right links follwed so far in the tree.
*/
int AvlTree::GetRightLinksFollowed( ) const {
    return RightLinksFollowed;
}

/**
* Returns the cardinality (number of nodes) in the tree.
*/
int AvlTree::card_of( ) const {
    return num_nodes;
}

/**
* Insert x into the tree; duplicates are ignored.
*/

void AvlTree::insert( const string & x ) {
    insert( x, root );
}

/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void AvlTree::remove( const string & x ) {
    cout << "Sorry, remove unimplemented; " << x <<
         " still present" << endl;
}

/**
* Find the smallest item in the tree.
* Return smallest item or ITEM_NOT_FOUND if empty.
*/
const string & AvlTree::findMin( ) const {
    return elementAt( findMin( root ) );
}

/**
* Find the largest item in the tree.
* Return the largest item of ITEM_NOT_FOUND if empty.
*/
const string & AvlTree::findMax( ) const {
    return elementAt( findMax( root ) );
}

/**
* Find item x in the tree.
* Return the matching item or ITEM_NOT_FOUND if not found.
*/
const string & AvlTree::
find( const string & x ) const {
    return elementAt( find( x, root ) );
}

/**
* Make the tree logically empty.
*/
void AvlTree::makeEmpty( ) {
    makeEmpty( root );
}

/**
* Test if the tree is logically empty.
* Return true if empty, false otherwise.
*/
bool AvlTree::isEmpty( ) const {
    return root == NULL;
}

/**
* Print the tree contents in sorted order.
*/
void AvlTree::printTree( ) const {
    if ( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree( root );
}

/**
* Deep copy.
*/
const AvlTree &
AvlTree::
operator=( const AvlTree & rhs ) {
    if ( this != &rhs ) {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}


double AvlTree::exp_path_length( )
/*
**  Calculate the expected path length of the tree
**  This is the public version, without a parameter.
*/
{
    // YOUR CODE HERE
    return -99.0;  // stub, remove after writing your code
}

int AvlTree::int_path_length(AvlNode *t, int depth) {
    return 0; // put your actual return value here when you write this function
}

/**
* Internal method to get element field in node t.
* Return the element field or ITEM_NOT_FOUND if t is NULL.
*/
const string & AvlTree::elementAt( AvlNode *t ) const {
    return t == NULL ? ITEM_NOT_FOUND : t->element;
}

/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the tree.
*/
void AvlTree::insert( const string & x, AvlNode * & t ) const {
    if ( t == NULL ) {
        t = new AvlNode( x, NULL, NULL );
    } else if ( x < t->element ) {
        insert( x, t->left );
        if ( height( t->left ) - height( t->right ) == 2 ) {
            if ( x < t->left->element ) {
                rotateWithLeftChild( t );
            } else {
                doubleWithLeftChild( t );
            }
        }
    } else if ( t->element < x ) {
        insert( x, t->right );
        if ( height( t->right ) - height( t->left ) == 2 ) {
            if ( t->right->element < x ) {
                rotateWithRightChild( t );
            } else {
                doubleWithRightChild( t );
            }
        }
    } else
        ;  // Duplicate; do nothing
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/
AvlNode *
AvlTree::findMin( AvlNode *t ) const {
    if ( t == NULL)
        return t;
    while ( t->left != NULL )
        t = t->left;
    return t;
}

/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/
AvlNode *
AvlTree::findMax( AvlNode *t ) const {
    if ( t == NULL )
        return t;
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
AvlNode *
AvlTree::find( const string & x, AvlNode *t ) const {
    while ( t != NULL )
        if ( x < t->element ) {
            t = t->left;
        } else if ( t->element < x ) {
            t = t->right;
        } else
            return t;    // Match
    return NULL;   // No match
}

/**
* Internal method to make subtree empty.
*/
void AvlTree::makeEmpty( AvlNode * & t ) const {
    if ( t != NULL ) {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

/**
* Internal method to clone subtree.
*/
AvlNode *
AvlTree::clone( AvlNode * t ) const {
    if ( t == NULL )
        return NULL;
    else
        return new AvlNode( t->element, clone( t->left ),
                            clone( t->right ), t->height );
}

/**
* Return the height of node t or -1 if NULL.
*/
int AvlTree::height( AvlNode *t ) const {
    return t == NULL ? -1 : t->height;
}

/**
* Return maximum of lhs and rhs.
*/
int AvlTree::max( int lhs, int rhs ) const {
    return lhs > rhs ? lhs : rhs;
}

/**
* Rotate binary tree node with left child.
* For AVL trees, this is a single rotation for case 1.
* Update heights, then set new root.
*/
void AvlTree::rotateWithLeftChild( AvlNode * & k2 ) const {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

/**
* Rotate binary tree node with right child.
* For AVL trees, this is a single rotation for case 4.
* Update heights, then set new root.
*/
void AvlTree::rotateWithRightChild( AvlNode * & k1 ) const {
    AvlNode * k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    k1 = k2;
}

/**
* Double rotate binary tree node: first left child.
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/
void AvlTree::doubleWithLeftChild( AvlNode * & k3 ) const {
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

/**
* Double rotate binary tree node: first right child.
* with its left child; then node k1 with new right child.
* For AVL trees, this is a double rotation for case 3.
* Update heights, then set new root.
*/
void AvlTree::doubleWithRightChild( AvlNode * & k1 ) const {
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}

/**
* Internal method to print a subtree in sorted order.
* t points to the node that roots the tree.
*/
void AvlTree::printTree( AvlNode *t ) const {
    if ( t != NULL ) {
        printTree( t->left );
        cout << t->element << endl;
        printTree( t->right );
    }
}
