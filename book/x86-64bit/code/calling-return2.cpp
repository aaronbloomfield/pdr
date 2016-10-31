#include <iostream>
using namespace std;

extern "C" int returnTwo();

int main() {
  cout << "calling returnTwo() returned: " 
       << returnTwo() << endl;
  return 0;
}
