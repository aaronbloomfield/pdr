#include <iostream>
using namespace std;


class ListNode {
public:
    int value = 5;
};


class List {

public:
    List() {
        cout << "In List constructor" << endl;

        // Common mistake 1 (C++ slide 10.15)
        //ListNode* head = new ListNode();

        // Common mistake 2 (C++ slide 10.16)
        //ListNode temp;
        //head = &temp;

        // Correct version:
        head = new ListNode();
    }

private:
    ListNode* head;
};


int main() {
    List* l = new List();
    delete l;
    return 0;
}
