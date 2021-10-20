// Must compile with the -m32 compiler flag

#include <iostream>
using namespace std;

long count = 0;
int space = 0;


class Item {
private:
    int* id;
    double price = 0.0;

public:
    Item() {
        try {
            cout << "Constructor called" << endl;
            id = new int (7);
            count++;
        } catch (bad_alloc& x) {
            cout << "out of memory at allocation # " << count << endl;
            double mem = ( (double) count * (double) space ) / ( 1024.0 * 1024.0 * 1024.0 );
            cout << "Used memory: " << mem << " Gb" << endl;
            cout << "Remaining memory is about: " << (4.0 - mem) * 1024.0 * 1024.0 << " Kb" << endl;
            exit (0);
        }
    }

    ~Item() {
        delete id;
        cout << "Destructor called" << endl;
    }

};

int main() {
    Item i;
    Item* j = new Item();
    int* n = new int, *m = new int;

    cout << "First allocated int: " << n << endl;
    cout << "Second allocated int: " << m << endl;
    space = (int) m - (int) n;
    cout << "sizeof(int): " << sizeof (int) << endl;
    cout << "space allocated between ints: " << space << endl;

    delete n;
    delete m;

    // to run out of memory, uncomment the next three lines
    //while ( count < 300000000 ) {
    //Item i;
    //}

    delete j;
    return 0;
    // destructor for i called here
}
