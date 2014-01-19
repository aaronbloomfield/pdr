#include <iostream>
#include "objectCell.h"
using namespace std;

int main() {
    ObjectCell<int> m1;
    ObjectCell<double> m2(3.14);
    m1.setValue(37);
    m2.setValue(m2.getValue() *2);
    // ...
    return 0;
}
