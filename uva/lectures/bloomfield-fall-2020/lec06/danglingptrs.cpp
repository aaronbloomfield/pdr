#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode* next, *prev;
    int value;
};

int main() {

    ListNode l;
    ListNode* n = new ListNode();

    l.value = 100;
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
