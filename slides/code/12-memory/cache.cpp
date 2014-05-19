#include <iostream>
#include <unistd.h>
using namespace std;

int main (void) {
    cout << "page size: " << getpagesize() << endl;
    int array[1024][1024];
    for ( int i = 0; i < 1024; i++ )
        for ( int j = 0; j < 1024; j++ )
            array[i][j] = 0;
    for ( int c = 0; c < 1024; c++ )
        for ( int i = 0; i < 1024; i++ )
            for ( int j = 0; j < 1024; j++ )
                array[i][j]++;
    int sum = 0;
    for ( int i = 0; i < 1024; i++ )
        for ( int j = 0; j < 1024; j++ )
            sum += array[i][j];
    cout << sum << endl;
    return 0;
}

// average time for i as outer, j as inner: 2.696  sec
// average time for j as outer, i as inner: 124.947 sec
// a factor of 46.345
