#include <iostream>
#include <string>
using namespace std;

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

// Define the member functions we declared above
// Remember: member functions are defined as Class::method()

// Constructors and destructors - no return types
MyObject::MyObject() {
    // Important: notice how we don't define 'name' or 'id' here
    // Instead, we're setting the variables that we declared in MyObject
    name = "--default--";
    id = ++numObjs;
    cout << "MyObject Default constructor:   " << *this << endl;
}

MyObject::MyObject(string n) {
    name = n;
    id = ++numObjs;
    cout << "MyObject Parameter constructor: " << *this << endl;
}

MyObject::MyObject(const MyObject& rhs) {
    name = rhs.name;
    id = ++numObjs;
    cout << "MyObject Copy constructor:      " << *this << endl;
}

MyObject::~MyObject() {
    cout << "MyObject Destructor:            " << *this << endl;
}

// Regular methods, with return types
string MyObject::getName() const {
    return name;
}

void MyObject::setName(const string& newName) {
    name = newName;
}

// Let cout know how to print MyObjects
ostream& operator<<(ostream& output, const MyObject& obj) {
    // output in format: ("object name", id)
    return output << "(\"" << obj.name << "\", " << obj.id << ")";
}

// Prototypes for non-member functions we define later on
// These are *non-member* functions because we didn't declare them as part of the MyObject class
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);

// Static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

int main () {
    cout << "--PART 1: Start of main--" << endl;
    cout << "--Defining o1, o2(\"Bob\")--" << endl;
    MyObject o1, o2("Bob");

    cout << "--Defining o3(o2)--" << endl;
    MyObject o3(o2);

    cout << "--Defining array of 3 objects--" << endl;
    MyObject array[3];

    cout << endl;

    cout << "--PART 2: call function using call-by-value, return int--" << endl;
    cmpMyObj(o1, o3);

    cout << "--call function using call-by-value, return MyObject--" << endl;
    getMaxMyObj(o1, o3);

    cout << endl;

    cout << "--PART 3:  o1: " << o1 << endl;
    {
        cout << "  --entering new block, define new o1(Sally)--" << endl;
        MyObject o1("Sally");
        o1.setName("Sally");
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;

        cout << "  --call swap function using call-by-reference--" << endl;
        swapMyObj(o1, o2);

        cout << "  --were their values swapped?--" << endl;
        cout << "  o1: " << o1 << "\to2: " << o2 << endl;
        cout << "  --leaving new block--" << endl;
    }
    cout << "o1: " << o1 << endl;

    cout << endl;

    cout << "--PART 4: Define reference var: { MyObject& oref=o1; } --" << endl;
    {
        MyObject& oref=o1;
    }
    cout << "-- was anything constructed/destructed?--" << endl;

    cout << endl;

    cout << "--PART 5: new and delete--" << endl;
    cout << "--use new to create one object, then array of 2 objects--" << endl;
    MyObject *op1 = new MyObject, *op2 = new MyObject[2];

    cout << "--use delete to remove that one object--" << endl;
    delete op1;

    cout << "--use delete [] to remove that array of 2 objects --" << endl;
    delete[] op2;

    cout << endl;

    cout << "--LAST PART:  End of main--" << endl;
    return 0;
}

// Define the functions we declared earlier
int cmpMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 == name2) {
        return 0;
    } else if (name1 < name2) {
        return -1;
    } else {
        return 1;
    }
}

MyObject getMaxMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if (name1 >= name2) {
        return o1;
    } else {
        return o2;
    }
}

void swapMyObj(MyObject& o1, MyObject& o2) {
    MyObject tmp(o1);
    o1.setName(o2.getName());
    o2.setName(tmp.getName());
}
