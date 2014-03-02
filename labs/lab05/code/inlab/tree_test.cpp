#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <stdlib.h>

#include "binarysearchtree.h"
#include "avltree.h"

using namespace std;

void print_stats(BinarySearchTree * tree, AvlTree * avl_tree) {
    cout << "BST: " << endl;
    cout << "Left links followed = " << tree->GetLeftLinksFollowed() << endl;
    cout << "Right links followed = " << tree->GetRightLinksFollowed() << endl;
    cout << "Total number of nodes = " << tree->card_of() << endl;
    cout << "Avg. node depth = " << tree->exp_path_length() << endl << endl;
    cout << "AVL Tree: " << endl;
    cout << "Left links followed = " << avl_tree->GetLeftLinksFollowed() << endl;
    cout << "Right links followed = " << avl_tree->GetRightLinksFollowed() << endl;
    cout << "Total number of nodes = " << avl_tree->card_of() << endl;
    cout << "Single Rotations = " << avl_tree->GetSingleRotations() << endl;
    cout << "Double Rotations = " << avl_tree->GetDoubleRotations() << endl;
    cout << "Avg. node depth = " << avl_tree->exp_path_length() << endl << endl;
}

int main () {
    BinarySearchTree  * tree;
    AvlTree  * avl_tree;
    string word;
    string inFile;
    const string ITEM_NOT_FOUND("");
    int i;
    int n=0;
    int num_words=0;
    string        word_found;			// return value for tree->find()
    string        avl_word_found;       // return value for tree->find()
    string response;
    tree = new BinarySearchTree(ITEM_NOT_FOUND);
    avl_tree = new AvlTree(ITEM_NOT_FOUND);
    cout << "Please enter the name of a file of words: ";
    cin >> inFile;
    ifstream fin(inFile.c_str());
    if (!fin) {
        cerr <<"Cannot open " << inFile << endl;
        exit(1);
    }
    while (fin >> word) {
        n = int (word.size());
        assert(n > 0);
        for (i=0; i < n; ++i) {			// Convert to lowercase.
            word[i] = tolower(word[i]);
        }
        if (!isalpha(word[n - 1])) {	// eliminate trailing punctuation
            word = word.substr(0, n-1);
        }
        // Echo the contents the words that have been read to the screen.
        cout << " " << word;
        num_words++;
        tree->insert(word);
        avl_tree->insert(word);
    }
    cout << "\n" << num_words << " words in this text\n";
    cout << endl << endl;
    // Print out Statistics about Shape of the trees
    // and number of links followed.
    print_stats(tree, avl_tree);
    // Find a word in both trees.
    cout << "\tEnter word to lookup > ";
    cin  >> response;
    word_found = tree->find(response);
    avl_word_found = avl_tree->find(response);
    if (word_found != ITEM_NOT_FOUND && avl_word_found != ITEM_NOT_FOUND) {
        cout << "\tWord was found: " << word_found << endl;
    } else {
        cout << response << " was not found in "
             << inFile.c_str() << endl;
    }
    // Print out Statistics about Shape of the trees
    // and number of links followed.
    print_stats(tree, avl_tree);
    fin.close();
    return 0;
}
