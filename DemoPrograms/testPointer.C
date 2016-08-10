
// What will this do?  Try on empress and then on your PC

#include <iostream>
using namespace std;

int main()
{
  int *P;
  
  P = new int;
  cout << P << endl;
  delete P;
  //  P = NULL;
  cout << P << endl;
  *P = 3;  // going to a non-existing cell 

  cout << *P << endl;
}
