// File TestRational.cpp

#include <iostream>
using namespace std;

#include "Rational.h"

int main() {
    Rational x, y, z;

    // 1/2 + 1/3 = 5/6
    x = Rational(1, 2);
    y = Rational(1, 3);
    z = x.plus(y);
    z.print();

    // 8/9 + 1/9 = 1
    x = Rational(8, 9);
    y = Rational(1, 9);
    z = x.plus(y);
    z.print();

    //  4/17 * 7/3 = 28/51
    x = Rational(4, 17);
    y = Rational(7,  3);
    z = x.times(y);
    z.print();

    // 0/6 = 0
    x = Rational(0, 6);
    x.print();

    return 0;
}
