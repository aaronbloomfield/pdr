#include <iostream>
using namespace std;

int main() {
    int x[6];
    int i;

    cout << "enter 6 integer values:" << endl;
    for ( i = 0; i <  6; i++ )
        cin >> x[i];

    for ( i = 0; i <  6; i++ )
        cout << x[i] << endl;

    int *ages = new int[5];
    int a[10];

    return 0;
}
