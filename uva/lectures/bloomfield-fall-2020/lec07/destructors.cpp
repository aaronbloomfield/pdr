#include <iostream>
using namespace std;

class Item {

public:

    Item() {
        //cout << "Item constructor called" << endl;
        id = new int;
        *id = 7;
        price = new double (3.14);
    }

    ~Item() {
        //cout << "Item destructor called with id " << *id << endl;
        //deallocate here..
        delete id;
        delete price;
    }

    int getID() const {
        return *id;
    }

    void setID (int i) {
        *id = i;
    }

private:
    int* id;
    double* price;
};


int main() {
    cout << "hello, world!" << endl;
    Item i; // = new Item();
    i.setID (1234);
    Item* j = new Item();

    j->setID (10);

    (*j).setID (10);


    cout << "ID of i: " << i.getID() << endl;
    cout << "ID of j: " << j->getID() << endl;
    cout << j << endl;
    delete j;
    cout << j << endl;

    // j is a dangling pointer

    for ( long i = 0; i < 100000; i++ ) {
        j = new Item();
        delete j;
    }

    //delete j;
    return 0;
    // desctructor called here
}
