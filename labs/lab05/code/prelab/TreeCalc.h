// Add your header information here
// TreeCalc.h: Tree Calculator class definition
// CS 2150: Lab 5
// NOTE: You may use any stack implementation that you wish
// You must submit ALL code to make your project build correctly


#ifndef TREECALC_H
#define TREECALC_H

// include your stack implementation here

#include "TreeNode.h"
using namespace std;

class TreeCalc {
public:

    TreeCalc();						//Constructor
    ~TreeCalc();					//Destructor

    void cleanTree(TreeNode * ptr);	//Deletes tree/frees memory
    void readInput();				//gets data from user
    void insert(const string & val);	//puts value in tree

    // print methods
    void printPrefix(TreeNode * curNode) const;	//prints data in prefix form
    void printInfix(TreeNode * curNode) const;	//prints data in infix form
    void printPostfix(TreeNode * curNode) const;//prints data in postfix form
    void printOutput() const;				//prints in pre,in,post form
    int calculate();					//calls private calculate method

private:
    // declare a stack to hold your expression tree
    int calculate(TreeNode* ptr) const;		//Evaluates tree, returns value

};

#endif
