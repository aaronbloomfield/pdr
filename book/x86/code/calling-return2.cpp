#include <iostream.h>
extern "C" int returnTwo();
int main() {
  if(returnTwo()!=2) {
    cerr << "Does not compute!";
  }
}
