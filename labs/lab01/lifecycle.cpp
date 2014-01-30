#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------  class definition
class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }
    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

// ------------------------------------------------  default constructor
MyObject::MyObject(const char *n) : name(n) {
    id = ++numObjs;
    cout << "MyObject Default constructor: " << *this << endl;
}

// ---------------------------------------------------  copy constructor
MyObject::MyObject(const MyObject& rhs) : name(rhs.name) {
    id = ++numObjs;
    cout << "MyObject Copy constructor:    " << *this << endl;
}

// --------------------------------------------------------  destructor
MyObject::~MyObject() {
    cout << "MyObject Destructor:          " << *this << endl;
}

// ----------------------------------------------------------  print out
ostream& operator<<(ostream& output, const MyObject& obj) {
    // output in format:  ("object name",id)
    return output << "(\"" << obj.name << "\"," << obj.id << ")";
}

//---------------------------------------------------- static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

//---------------------------------------------------------- prototypes
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);

//--------------------------------------------------------------- main
int main () {
    cout << "--PART 1: Start of main--" << endl;
    cout << "--Defining o1, o2(Bob)--" << endl;
    MyObject o1, o2("Bob");
    cout << "--Defining o3(o2)--" << endl;
    MyObject o3(o2);
    cout << "--Defining array of 3 objects--" << endl;
    MyObject array[3];
    cout << "\n--PART 2: call function using call-by-value,"
         " return int--" << endl;
    cmpMyObj(o1, o3);
    cout << "--call function using call-by-value, return MyObject--" << endl;
    getMaxMyObj(o1, o3);
    cout << "\n--PART 3:  o1: " << o1 << endl;
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
    cout << "\n--PART 4: Define reference var.: { MyObject& oref=o1; } --"
         << endl;
    {
        MyObject& oref=o1;
    }
    cout << "-- was anything constructed/destructed?--" << endl;
    cout << "\n--PART 5: new and delete--" << endl;
    cout << "--use new to create one object, then array of 2 objects--"
         << endl;
    MyObject *op1 = new MyObject, *op2 = new MyObject[2];
    cout << "--use delete to remove that one object--" << endl;
    delete op1;
    cout << "--use delete [] to remove that array of 2 objects --" << endl;
    delete [] op2;
    cout << "\n--LAST PART:  End of main--" << endl;
    return 0;
}

//---------------------------------------------------------- cmpMyObj
int cmpMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if ( name1 == name2 )
        return 0;
    else if ( name1 < name2 )
        return -1;
    else
        return 1;
}

//---------------------------------------------------------- getMaxMyObj
MyObject getMaxMyObj(const MyObject o1, const MyObject o2) {
    string name1 = o1.getName(), name2 = o2.getName();
    if ( name1 >= name2 )
        return o1;
    else
        return o2;
}

//---------------------------------------------------------- swapMyObj
void swapMyObj(MyObject& o1, MyObject& o2) {
    MyObject tmp(o1);
    o1.setName(o2.getName());
    o2.setName(tmp.getName());
}
