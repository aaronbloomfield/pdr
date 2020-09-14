#include <iostream>

#include "item.h"

using namespace std;


int main() {
    cout << "Hello world" << endl;
    Item i; // = new Item();
    i.setID(1234);
    cout << "ID of i: " << i.getID() << endl;
    Item j = i;
    cout << "ID of i: " << i.getID() << endl;
    cout << "ID of j: " << j.getID() << endl;
    j.setID(7);
    cout << "ID of i: " << i.getID() << endl;
    cout << "ID of j: " << j.getID() << endl;
    return 0;
}
