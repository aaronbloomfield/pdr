#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;

    int i = 1;
    float f = 2.0;
    double d = 3.0;

    int* ip = nullptr;
    float* fp = &f;
    double* dp;

    //cout << *ip << endl; // seg fault

    cout << "uninitialized pointer addresses:" << endl;
    cout << ip << endl;
    cout << fp << endl;
    cout << dp << endl;

    //*ip = i;
    ip = &i;
    fp = &f;
    dp = &d;

    cout << "variable & addresses:" << endl;
    cout << &i << endl;
    cout << &f << endl;
    cout << &d << endl;

    cout << "pointer derefences:" << endl;
    cout << *ip << endl;
    cout << *fp << endl;
    cout << *dp << endl;

    *ip = 10;
    *fp = 20;
    *dp = 30;

    cout << "pointer derefences after:" << endl;
    cout << *ip << endl;
    cout << *fp << endl;
    cout << *dp << endl;

    cout << "variable values:" << endl;
    cout << i << endl;
    cout << f << endl;
    cout << d << endl;

    cout << "sizeof the variables:" << endl;
    cout << sizeof(i) << endl;
    cout << sizeof(f) << endl;
    cout << sizeof(double) << endl;

    i = 1;
    int j = 1;
    ip = &i;
    int *jp = &i;
    if ( ip == jp )
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
