#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
	
	 int *P;
	  
	  P = new int;
	  cout << P << endl;
	  delete P;
	   //P = NULL;		//To point to nothing.
	  cout << P << endl;
	  *P = 3;  // going to a non-existing cell 

	  cout << *P << endl;
	   
	   return 0;
	
}