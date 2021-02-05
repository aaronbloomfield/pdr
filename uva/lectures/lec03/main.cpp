#include <iostream>
using namespace std;

#include "item.h"

int main() {
    cout << "Hello world" << endl;
    Item i;
    i.setID (1234);
    cout << "ID of i: " << i.getID() << endl;
    Item j = i;
    cout << "ID of i: " << i.getID() << endl;
    cout << "ID of j: " << j.getID() << endl;
    j.setID (7);
    cout << "ID of i: " << i.getID() << endl;
    cout << "ID of j: " << j.getID() << endl;
    return 0;
}
