#ifndef ITEM_H
#define ITEM_H

class Item {

public:
    int getID() const;
    void setID (int i);

private:
    int id;
    double price;
    const float f = 9.9;
    static const double pi;
};

#endif
