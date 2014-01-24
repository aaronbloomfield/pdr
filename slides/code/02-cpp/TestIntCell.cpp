// File TestIntCell.cpp

#include "IntCell.h"
#include <iostream>
using namespace std;
int main( ) {
    IntCell m1;
    IntCell m2( 37 ); //
    //IntCell m2 = 37; // does not work
    cout << m1.getValue( ) << " " << m2.getValue( ) << endl;
    m1 = m2;
    m2.setValue( 40 );
    cout << m1.getValue( ) << " " << m2.getValue( ) << endl;
    return 0;
}
