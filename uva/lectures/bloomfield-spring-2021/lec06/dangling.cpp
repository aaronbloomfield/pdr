#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode* next, *prev;
    int value;

    ListNode() {
        cout << "Constructor called" << endl;
    }
};

int main() {
    ListNode l;
    ListNode* n = new ListNode();
    ListNode& m = l;

    l.value = 100;
    m.value = 100;
    (*n).value = 200;
    n->value = 200;

    cout << n->value << endl;

    delete n;

    cout << "dangling pointer: " << n->value << endl;

    n = nullptr;
    n = &l;

    cout << n->value << endl;

    return 0;
}
