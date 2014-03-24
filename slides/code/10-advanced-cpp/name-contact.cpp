#include <iostream>
using namespace std;

class Name {
public:
    Name(void) : myName("") { }
    ~Name(void) {  }
    void SetName(string theName) {
        myName = theName;
    }
    void print(void) {
        cout << myName << endl;
    }

private:
    string myName;
};

class Contact: public Name {
public:
    Contact(void) {
        myAddress = "";
    }
    ~Contact(void) { }
    void SetAddress(string theAddress) {
        myAddress = theAddress;
    }
    void print(void) {
        Name::print();
        cout << myAddress << endl;
    }
private:
    string myAddress;
};

int main(void) {
    Contact c;
    c.SetName("John Doe");
    c.SetAddress("009 Olsson Hall");
    c.print();
}
