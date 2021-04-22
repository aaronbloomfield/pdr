#include <iostream>
using namespace std;

int global_id = 1;


class Item {

public:

    Item() {
        id = new int (global_id++);
        price = new double (0);
        cout << "Item default constructor called for id " << *id << endl;
    }

    ~Item() {
        cout << "Item destructor called with id " << *id << endl;
        delete id;
        delete price;
    }

    Item (const Item& source) {
        id = new int (global_id++);
        price = new double ( * (source.price) );
        cout << "Item copy constructor called with id " << *id << endl;
    }

    Item (int i, double p) {
        // ...
    }

    Item& operator= (const Item& source) {
        id = new int;
        *id = * (source.id);
        price = new double ( * (source.price) );
        cout << "Item operator=() called with id " << *id << endl;
        return *this;
    }

    int getID() const {
        return *id;
    }
    void setID (int i) {
        *id = i;
    }
    int getPrice() const {
        return *price;
    }
    void setPrice (double p) {
        *price = p;
    }

private:
    int* id;
    double* price;
};


void foo (Item x) {
    cout << "In foo()" << endl;
}


int main() {
    cout << "Hello, world!" << endl;
    Item i; // = new Item();
    i.setPrice (5);
    Item* j = new Item();
    j->setPrice (10);
    cout << "ID of i: " << i.getID() << "; price of i: " << i.getPrice() << endl;
    cout << "ID of j: " << j->getID() << "; price of j: " << j->getPrice() << endl;

    Item k = i; // Item k(i);
    cout << "ID of k: " << k.getID() << "; price of k: " << k.getPrice() << endl;

    Item l;
    l = i;
    cout << "ID of l: " << l.getID() << "; price of l: " << l.getPrice() << endl;

    cout << "About to call foo()" << endl;
    foo (i);

    delete j; // j's destructor called here upon the delete call
    return 0;
    // i's desctructor called here when it goes out of scope
}
