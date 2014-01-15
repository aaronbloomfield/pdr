// CS 216 exam 1 code

#include <iostream>
#include <stdio.h>
using namespace std;

/* This function will print out the results of the memory diagram
 * question (question 13).  The lines that are commented out in the
 * function are the ones that cause errors: the first a compile-time
 * error, the last two a run-time error.
 */
void memoryDiagramQuestion() {
    cout << "Memory diagram question output: " << endl;
    int a = 7;
    int *b = &a;
    int &c = a;
    int d[5] = { 1, 2, 3, 4, 5 };
    int *e = new int[5];
    int *f = NULL;
    int &g = *f;
    //c = b;
    c = *b;
    cout << "a:  " << a << endl;
    cout << "b:  " << b << endl;
    cout << "*b: " << *b << endl;
    cout << "c:  " << c << endl;
    cout << "d:  " << d << endl;
    cout << "e:  " << e << endl;
    cout << "*e: " << *e << endl;
    cout << "f:  " << f << endl;
    //cout << "*f:  " << *f << endl;
    //cout << "g:  " << g << endl;
}

// The array that is declared in question 3
int x[3][2] = { {1,2}, {3,4}, {5,6} };

// The union used for questin 12
union foo {
    int x;               // used to write the int value
    float f;             // used to read the floating point value
    int *p;              // used to print out the values in hex
    unsigned char c[4];  // used to swap the bytes
};

/* This function will compute the result of the endian number question
 * (question 12).  Because the x86 writes both the floating point
 * number and the int value both in the same endian format, the bytes
 * have to be switched to simulate what was asked in the question.
 */
void endianNumberQuestion() {

    // Write the int to the union, and print out the value in hex.  This
    // is also the value expected for the first part of the 'partial
    // credit' option for this question.
    foo bar;
    bar.x = 2113;
    cout << "Decimal value: " << bar.x << endl;
    cout << "Hex value before endian swap: " << bar.p << endl;

    // Any machine will write both floating point numbers and int
    // numbers in the same endian format.  To simulate the exam question
    // (which has one type written in one endian format, and the other
    // one written in the other endian format), the bytes have to be
    // switched.  Note that it doesn't matter if this is running on a
    // big-endian machine or a little-endian machine, as the byte swap
    // will just switch the bytes to the 'other' format.
    unsigned char g;
    g = bar.c[0];
    bar.c[0] = bar.c[3];
    bar.c[3] = g;
    g = bar.c[1];
    bar.c[1] = bar.c[2];
    bar.c[2] = g;

    // Extract the floating point value
    cout << "Hex value after endian swap: " << bar.p << endl;
    cout << "Floating point value: " << bar.f << endl;

    // This is the second part of the 'partial credit' option for this
    // question.
    bar.x = 0x419c0000;
    cout << "0x419c0000 as a float: " << bar.f << endl;
}

// Calls the two defined functions above, and then exits.
int main(int argc, char **argv) {
    endianNumberQuestion();
    memoryDiagramQuestion();
    return 0;
}


/* Output:

Decimal value: 2113
Hex value before endian swap: 0x841
Hex value after endian swap: 0x41080000
Floating point value: 8.5
0x419c0000 as a float: 19.5
Memory diagram question output:
a:  7
b:  0xbfc8e07c
*b: 7
c:  7
d:  0xbfc8e068
e:  0x804a008
*e: 0
f:  0

*/
