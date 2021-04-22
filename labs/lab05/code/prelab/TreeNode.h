// TreeNode.h: TreeNode class definition
// CS 2150: Lab 5


#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode();                  // Default Constructor
    TreeNode(const string& val); // Constructor

private:
    string value;
    TreeNode* left;
    TreeNode* right;
    friend class TreeCalc;       // gives TreeCalc access to private data
};

#endif
