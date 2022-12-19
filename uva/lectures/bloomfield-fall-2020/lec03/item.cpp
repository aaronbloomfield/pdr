#include <iostream>
using namespace std;

#include "item.h"

int Item::x = 9;

int Item::getID() const {
    return id;
}


void Item::setID (int i) {
    id = i;
}
