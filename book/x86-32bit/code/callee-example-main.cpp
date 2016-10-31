#include <iostream>
using namespace std;

extern "C" int myFunc(int,int,int);

int main() {
  int x = 3;
  cout << "myFunc() returned: "
       << myFunc(x,5,10) << endl;
  return 0;
}
