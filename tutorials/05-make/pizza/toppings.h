#ifndef TOPPINGS_H
#define TOPPINGS_H

#include "cheese.h"
#include "mushrooms.h"
#include "peppers.h"
#include "pepperoni.h"


class Toppings {
private:
    Cheese* cheese;
    Mushrooms* mushrooms;
    Peppers* peppers;
    Pepperoni* pepperoni;
public:
    Toppings(int cheeseAmount, int mushroomsAmount, int peppersAmount, int pepperoniAmount);
    ~Toppings();
};
#endif
