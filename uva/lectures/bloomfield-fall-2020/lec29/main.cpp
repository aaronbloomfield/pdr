#include <iostream>
#include <string>
using namespace std;

class gplistnode {
public:
    gplistnode* prev, *next;
    int id;
    gplistnode() : prev (nullptr), next (nullptr) {
        cout << "In gplistnode::constructor()" << endl;
        id = 1;
    }
    virtual ~gplistnode() { }
    virtual int getID() {
        return id;
    }
};

class person {
public:
    int id;
    string name;
    person (string n) : name (n) {
        cout << "In person::constructor(string)" << endl;
        id = 2;
    }
    virtual ~person() { }
    virtual int getID() {
        return id;
    }
};

class student : public gplistnode, public person {
public:
    int id;
    student (string n) : person (n), gplistnode() {
        cout << "In student::constructor(string)" << endl;
        person::id = 3;
        this->gplistnode::id = 4;
        id = 5;
    }
    virtual ~student() { }
    virtual int getID() {
        return id;
    }
};

int main() {
    cout << "hello, world" << endl;
    cout << "sizeof(pointer): " << sizeof (void*) << endl;
    cout << "sizeof(int): " << sizeof (int) << endl;
    cout << "sizeof(string): " << sizeof (string) << endl;
    cout << "sizeof(gplistnode): " << sizeof (gplistnode) << endl;
    cout << "sizeof(person): " << sizeof (person) << endl;

    person* p = new person ("Jane Doe");
    cout << p->id << endl;
    cout << p->getID() << endl;

    student s ("John Doe");
    cout << s.person::getID() << endl;
    cout << s.gplistnode::getID() << endl;

    person* q = new student ("Chris Doe");
    cout << q->getID() << endl;

    cout << "about to seg fault..." << endl;
    delete q;
    delete p;
    return 0;
}




/*

class shape {
  // ...
  virtual draw() = 0;
};

class circle : public shape {
};
class triangle : public shape {
};
// ...

void foo() {
  vector<shape> v;

  for ( all elements in vector )
    v.draw();

*/
