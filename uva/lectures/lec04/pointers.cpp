#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;

    int i = 1;
    float f = 2.0;
    double d = 3.0;

    int* ip = nullptr;  // or NULL
    float* fp = &f;
    double* dp;

    cout << "variable values:" << endl;
    cout << i << endl;
    cout << f << endl;
    cout << d << endl;

    cout << "variable addresses:" << endl;
    cout << &i << endl;
    cout << &f << endl;
    cout << &d << endl;

    cout << "pointer addresses:" << endl;
    cout << ip << endl;
    cout << fp << endl;
    cout << dp << endl;

    cout << "pointer dereferences:" << endl;
    //cout << *ip << endl;
    cout << *fp << endl;
    //cout << *dp << endl;

    ip = &i;
    fp = &f;
    dp = &d;

    cout << "pointer addresses:" << endl;
    cout << ip << endl;
    cout << fp << endl;
    cout << dp << endl;

    cout << "pointer dereferences:" << endl;
    cout << *ip << endl;
    cout << *fp << endl;
    cout << *dp << endl;

    *ip = 10;
    *fp = 20.0;
    *dp = 30.0;

    cout << "pointer addresses:" << endl;
    cout << ip << endl;
    cout << fp << endl;
    cout << dp << endl;

    cout << "pointer dereferences:" << endl;
    cout << *ip << endl;
    cout << *fp << endl;
    cout << *dp << endl;

    cout << "variable values:" << endl;
    cout << i << endl;
    cout << f << endl;
    cout << d << endl;

    cout << "sizeof() the pointers:" << endl;
    cout << sizeof (ip) << endl;
    cout << sizeof (fp) << endl;
    cout << sizeof (double*) << endl;

    cout << "sizeof() the variables:" << endl;
    cout << sizeof (i) << endl;
    cout << sizeof (f) << endl;
    cout << sizeof (double) << endl;

    cout << "comparisons:" << endl;
    int j = 10;
    int* jp = &j;
    if ( i == j )
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    if ( *ip == *jp )
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    cout << ip << endl;
    cout << jp << endl;
    if ( ip == jp )
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
