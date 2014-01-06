// utility functions for vectors of strings

#include "svutil.h"

// prints the strings in the vector
void svOutput ( const vector<string> &vect ) {
    for (int i=0; i < vect.size(); ++i) {
        cout << vect.at(i) << " ";
    }
    cout << endl;
}


// finds a string in a vector and returns its index
int svFind ( const vector<string> &vect, string s) {
    for (int i=0; i < vect.size(); ++i) {
        if ( vect.at(i) == s ) return i;
    }
    return -1;
}

// removes an element from the vector at index idx
// returns true if remove successful, otherwise false
bool svDeleteAt ( vector<string> &vect, int idx ) {
    int lastIndex = vect.size()-1;
    if ( idx < 0 || idx > lastIndex )
        return false;
    if ( idx == lastIndex )
        vect.pop_back();
    else {
        string temp = vect.at(lastIndex);
        vect.pop_back();
        vect.at(idx) = temp;
    }
    return true;
}

// sorts a vector of string in ascending order
void svSort ( vector<string> &vect ) {
    // not implemented yet
    return;
}

// return the index of the largest string in range index start to end
int svFindMax( const vector<string> &vect, int start, int end ) {
    // not implemented yet
    return -1;
}

