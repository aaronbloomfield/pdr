// This code requires the IntCell.h/cpp code from the 02-cpp slide set

#include <iostream>
#include <vector>
#include <string>
#include "IntCell.h"
using namespace std;

template <typename Comparable>
const Comparable & findMax (const vector<Comparable> & a) {
    int maxIndex = 0;
    for( int i = 1; i < a.size( ); i++ )
        if( a[ maxIndex ] < a[ i ] ) // note the use of '<'
            maxIndex = i;
    return a[ maxIndex ];
}

int main() {
    vector<int> v1(37);
    vector<double> v2(40);
    vector<string> v3(80);
    vector<IntCell> v4(75);

    v1.push_back(3);
    v1.push_back(7);
    v1.push_back(5);

    v2.push_back(3.14);
    v2.push_back(2.718);
    v2.push_back(-1.0);

    v3.push_back("aardvark");
    v3.push_back("sloth");
    v3.push_back("platypus");
    v3.push_back("zebra");

    v4.push_back(IntCell(3));
    v4.push_back(IntCell(7));
    v4.push_back(IntCell(5));

    cout << findMax(v1) << endl;  // ok: Comparable = int
    cout << findMax(v2) << endl;  // ok: Comparable = double
    cout << findMax(v3) << endl;  // ok: Comparable = string
    //cout << findMax(v4) << endl;  // Illegal: no operator<

    return 0;
}
