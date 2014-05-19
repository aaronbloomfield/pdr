/*
 * This program is designed to show some nuances of C++ syntax,
 * reference usage, and the various methods in a class (copy
 * constructor, operator=(), etc.).
 *
 * The addresses you get when running this program will most likley
 * differ; that is expected.  In fact, the addresses will differ upon
 * successive executions of the program.  If you are compiling this on
 * a 64-bit machine, you may want to use the -m32 flag to g++ to
 * compile it in 32-bit mode -- this keeps the pointers to 32 bits (as
 * opposed to 64 bits).
 *
 * Copyright (c) 2012 by Aaron Bloomfield (aaron@virginia.edu).  All
 * rights reesrved.
 */

#include <iostream>
using namespace std;

//--------------------------------------------------
// this would be in test.h

class test {
    static int idcount;
    const int id;
    int value;
public:
    test();
    test(int v);
    test(const test& x);
    ~test();
    test& operator=(const test& other);
    friend ostream& operator<<(ostream& out, const test& f);
};

//--------------------------------------------------
// this would be in test.cpp

int test::idcount = 0;

test::test() : id (idcount++), value(0) {
    cout << "calling test(); object created is " << *this
         << "; address is " << this << endl;
}

test::test(int v) : id (idcount++), value(v) {
    cout << "calling test(" << v << "); object created is " << *this
         << "; address is " << this << endl;
}

test::test(const test& x) : id(x.id), value(x.value) {
    cout << "calling test(&test) on " << *this << "; address is " << this << endl;
}

test::~test() {
    cout << "calling ~test() on " << *this << endl;
}

test& test::operator=(const test& other) {
    cout << "calling operator=(" << other << ")" << endl;
    test *tmp = new test(other);
    return *tmp;
}

ostream& operator<<(ostream& out, const test& f) {
    out << "test[id=" << f.id << ",v=" << f.value << "]";
}


//--------------------------------------------------
// this would be in main.cpp

test bar(test param) {
    return test(10);
}

int main() {

    // this does NOT create a test object; instead, it creates a function
    // called a() that has no body (and thus C++ defaults it to return
    // 1).  Note that there is no output statement from the default
    // constructor.
    test a();
    cout << "attempted to create a: " << a << endl;
    // output:
    // attempted to create a: 1

    // this does  create a test object, calling  the default constructor.
    // Since  putting parenthesis in  there for  creating an  object and
    // calling  the  default  constructor  has another  meaning  in  C++
    // (specifically,  creating  a  function),   we  have  to  omit  the
    // parenthesis.
    cout << "----------------------------------------" << endl;
    test aa;
    cout << "created aa: " << aa << endl;
    // output:
    // ----------------------------------------
    // calling test(); object created is test[id=0,v=0]; address is 0xff852a50
    // created aa: test[id=0,v=0]

    // this creates a test object, calling the specific constructor that
    // takes in a single int value
    cout << "----------------------------------------" << endl;
    test b(1);
    cout << "created b: " << b << endl;
    // output:
    // ----------------------------------------
    // calling test(1); object created is test[id=1,v=1]; address is 0xff852a48
    // created b: test[id=1,v=1]

    // this creates two test objects via pointers and new
    cout << "----------------------------------------" << endl;
    test *c = new test(2);
    cout << "created *c: " << *c << " at " << c << endl;
    test *d = new test;
    cout << "created *d: " << *d << " at " << d << endl;
    // output:
    // ----------------------------------------
    // calling test(2); object created is test[id=2,v=2]; address is 0xa009008
    // created *c: test[id=2,v=2] at 0xa009008
    // calling test(); object created is test[id=3,v=0]; address is 0xa009018
    // created *d: test[id=3,v=0] at 0xa009018

    // subroutine invocation.  The copy constructor is invoked when the
    // actual parameter is copied into the formal parameter.  The
    // subroutine then creates test[id=4,v=10].  The parameter that was
    // copied into the subroutine (via the copy constructor) is then
    // destructed upon termination of the subroutine.
    cout << "----------------------------------------" << endl;
    cout << "about to invoke subroutine..." << endl;
    test e = bar(*c);
    cout << "finished invoking subroutine..." << endl;
    // output:
    // ----------------------------------------
    // about to invoke subroutine...
    // calling test(&test) on test[id=2,v=2]; address is 0xff852a38
    // calling test(10); object created is test[id=4,v=10]; address is 0xff852a40
    // calling ~test() on test[id=2,v=2]
    // finished invoking subroutine...

    // because this assignment happens in the same statement as the
    // declaration, it invokes the copy constructor
    cout << "----------------------------------------" << endl;
    test f = b;
    // output:
    // ----------------------------------------
    // calling test(&test) on test[id=1,v=1]; address is 0xff852a30

    // we are only deleting one of the dynamically created test objects
    cout << "----------------------------------------" << endl;
    cout << "about to delete a test object..." << endl;
    delete c;
    // output:
    // ----------------------------------------
    // about to delete a test object...
    // calling ~test() on test[id=2,v=2]

    // because this assignment does NOT happen in the same statement as
    // the declaration, the operator=() subroutine is called.
    cout << "----------------------------------------" << endl;
    cout << "assignment..." << endl;
    aa = b;
    // output:
    // ----------------------------------------
    // assignment...
    // calling operator=(test[id=1,v=1])
    // calling test(&test) on test[id=1,v=1]; address is 0xa009008

    // upon termination of the main() function, all statically created
    // test objects are deallocated.
    cout << "----------------------------------------" << endl;
    cout << "about to leave main..." << endl;
    // output:
    // ----------------------------------------
    // about to leave main...
    // calling ~test() on test[id=1,v=1]
    // calling ~test() on test[id=4,v=10]
    // calling ~test() on test[id=1,v=1]
    // calling ~test() on test[id=0,v=0]

    // Note that d was created via dynamic memory allocation, so it is
    // not deallcoated by the program.  The operating system will clean
    // up the used memory, but it does not call the destructor on d.
}
