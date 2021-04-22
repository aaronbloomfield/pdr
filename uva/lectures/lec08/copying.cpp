#include <iostream>
using namespace std;

int global_id = 0;


class Item {
private:
    int id;
    double* price;

public:

    Item() {
        id = global_id++;
        price = new double (3.14);
        cout << "Item default constructor called for id " << id << endl;
    }

    ~Item() {
        delete price;
        cout << "Item destructor called for id " << id << endl;
    }

    Item (const Item& source) {
        id = global_id++;
        price = new double (* (source.price) );
        cout << "Item copy constructor called for id " << id << endl;
    }

    Item& operator= (const Item& source) {
        // not set id
        *price = * (source.price);
        cout << "Item operator=() method called for id " << id << endl;
        return *this;
    }

    double getPrice() const {
        return *price;
    }

    void setPrice (double p) {
        *price = p;
    }

    int getID() const {
        return id;
    }

    void setID (int i) {
        id = i;
    }

};


int main() {
    cout << "hello world" << endl;

    Item i;
    Item j;

    cout << "ID of i: " << i.getID() << "; price of i: " << i.getPrice() << endl;
    cout << "ID of j: " << j.getID() << "; price of j: " << j.getPrice() << endl;

    Item k = j; // call the copy constructor: equivalent to: Item k(j);
    cout << "ID of k: " << k.getID() << "; price of k: " << k.getPrice() << endl;
    j = i;
    cout << "ID of j: " << j.getID() << "; price of j: " << j.getPrice() << endl;

    return 0;
}
