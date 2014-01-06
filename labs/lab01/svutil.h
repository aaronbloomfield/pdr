// utility functions for vectors of string

#ifndef SVUTIL_H
#define SVUTIL_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// prints the strings in the vector
void svOutput ( const vector<string> &vect );

// finds a string in a vector and returns its index
int svFind ( const vector<string> &vect, string s);

// removes an element from the vector at index idx
// returns true if remove successful, otherwise false
bool svDeleteAt ( vector<string> &vect, int idx );

// sorts a vector of string in ascending order
void svSort ( vector<string> &vect );

// return the index of the largest string in range index start to end
int svFindMax( const vector<string> &vect, int start, int end );


#endif
