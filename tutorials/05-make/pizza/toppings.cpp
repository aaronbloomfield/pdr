#include "toppings.h"

Toppings::Toppings(int cheeseAmount, int mushroomsAmount, int peppersAmount, int pepperoniAmount) {
    cheese=new Cheese(cheeseAmount);
    mushrooms=new Mushrooms(mushroomsAmount);
    peppers=new Peppers(peppersAmount);
    pepperoni=new Pepperoni(pepperoniAmount);
}

Toppings:: ~Toppings() {
    delete cheese;
    delete mushrooms;
    delete peppers;
    delete pepperoni;
}
