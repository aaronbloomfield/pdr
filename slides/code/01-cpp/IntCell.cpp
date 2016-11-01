// File IntCell.cpp

#include "IntCell.h"
using namespace std; // (not really necessary, but...)

IntCell::IntCell( int initialValue ) : storedValue( initialValue ) {

}

int IntCell::getValue( ) const {
    return storedValue;
}

void IntCell::setValue( int val ) {
    storedValue = val;
}

int IntCell::max(int m) {
    return (m>storedValue) ? m : storedValue;
}
