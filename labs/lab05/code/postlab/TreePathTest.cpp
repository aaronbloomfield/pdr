#include "AVLTree.h"
#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
  AVLTree avl;
  BinarySearchTree bst;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      avl.insert(word);
      bst.insert(word);
    } else if (instr == "R") {
      avl.remove(word);
      bst.remove(word);
    } else if (instr == "L") {
      cout << "AVL path: " << avl.pathTo(word) << endl;
      cout << "BST path: " << bst.pathTo(word) << endl;
    }
  }
  cout << "AVL numNodes: " << avl.numNodes() << endl;
  cout << "BST numNodes: " << bst.numNodes() << endl;
}