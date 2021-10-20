#include <iostream>
using namespace std;

#include "item.h"

const double Item::pi = 3.14159265358979;

int Item::getID() const {
    return id;
}

void Item::setID (int i) {
    id = i;
}
