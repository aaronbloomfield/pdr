/* swap() with references
 */

#include <iostream>
using namespace std;

void swap(int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a=0;
    int b=3;
    cout << "Before swap(): a: " << a << "b: " << b << endl;
    swap(b,a);
    cout << "After swap(): a: " << a << "b: " << b << endl;

    return 0;
}
