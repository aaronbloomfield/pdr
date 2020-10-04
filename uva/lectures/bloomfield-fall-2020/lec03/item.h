#ifndef ITEM_H
#define ITEM_H

//#include <iostream>
//using namespace std;

class Item {

public:
    int getID() const;
    void setID(int i);


private:
    int id;
    const float f = 9.9;
    double price;
    static int x;
};

#endif
