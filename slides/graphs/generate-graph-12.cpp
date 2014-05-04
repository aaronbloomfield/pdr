#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
    int num, ret;
    float radius = 5.0;
    // error checks
    if ( (argc != 2) && (argc != 3) ) {
        cerr << "Usage: " << argv[0] << " <num> [<radius>]" << endl;
        exit(0);
    }
    ret = sscanf (argv[1], "%d", &num);
    if ( ret != 1 ) {
        cerr << "Bad number format: '" << argv[1] << "'" << endl;
        exit(0);
    }
    if ( argc == 3 ) {
        ret = sscanf (argv[2], "%f", &radius);
        if ( ret != 1 ) {
            cerr << "Bad radius format: '" << argv[1] << "'" << endl;
            exit(0);
        }
    }
    // print header
    cout << "# This graph generated with " << num << " nodes";
    if ( argc == 2 )
        cout << " and the radius set to the default of 5.0" << endl;
    else
        cout << " and a radius of " << radius << endl;
    cout << "digraph G {" << endl;
    cout << "\tgraph [fontname = \"Helvetica\"];" << endl;
    cout << "\tnode [fontname = \"Helvetica\",shape=circle,width=0.6];" << endl;
    cout << "\tedge [fontname = \"Helvetica\",dir=none];" << endl;
    // generate node positions
    for ( int i = 0; i < num; i++ ) {
        double angle = 360.0/((double)num) * i * (M_PI/180.0);
        cout << "\tv" << (i+1) << " [pin=true,pos=\"" << sin(angle)*radius << "," << cos(angle)*radius << "\"];" << endl;
    }
    // generate edges
    for ( int i = 1; i <= num; i++ )
        for ( int j = 1; j <= num; j++ )
            if ( i < j )
                cout << "\tv" << i << " -> " << "v" << j << ";" << endl;
    cout << "}" << endl;
    return 0;
}
