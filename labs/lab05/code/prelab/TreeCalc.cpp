// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    return i;
}
