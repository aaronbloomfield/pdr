#include <iostream>
using namespace std;
#include "pizzadough.h"
#include "tomatosauce.h"
#include "toppings.h"

int main() {
    //PizzaDough(Portion of pizza dough)
    PizzaDough dough(1);
    //TomatoSauce(Portion of tomato sauce)
    TomatoSauce sauce(5);
    //Toppings(Portion of cheese, Portion of mushrooms, Portion of peppers, Portion of pepperoni)
    Toppings toppings(8,20,20,20);
    cout<<"This is a pizza" << endl;
    return 0;
}
