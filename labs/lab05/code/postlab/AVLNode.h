#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif