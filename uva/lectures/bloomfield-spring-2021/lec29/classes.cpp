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

class student : public gplistnode, public virtual person {
public:
    int id;
    student (string n) : person (n)  {
        cout << "In student::constructor(string)" << endl;
        id = 3;
    }
    virtual ~student() { }
    virtual int getID() {
        return id;
    }
};

class professor : public gplistnode, public virtual person {
public:
    int id;
    professor (string n) : person (n)  {
        cout << "In professor::constructor(string)" << endl;
        id = 4;
    }
    virtual ~professor() { }
    virtual int getID() {
        return id;
    }
};

class student_prof : public virtual student, public virtual professor {
public:
    int id;
    student_prof (string n) : student (n), professor (n), person (n)  {
        cout << "In student_prof::constructor(string)" << endl;
        cout << student::prev << endl;
        cout << professor::prev << endl;
        id = 5;
    }
    virtual ~student_prof() { }
    virtual int getID() {
        return id;
    }
};


int main() {
    cout << "sizeof(string): " << sizeof (string) << endl;
    cout << "sizeof(gplistnode): " << sizeof (gplistnode) << endl;
    cout << "sizeof(person): " << sizeof (person) << endl;
    cout << "sizeof(student): " << sizeof (student) << endl;
    cout << "sizeof(professor): " << sizeof (professor) << endl;
    cout << "sizeof(student_prof): " << sizeof (student_prof) << endl;

    student_prof s ("Batman");

    return 0;
}
