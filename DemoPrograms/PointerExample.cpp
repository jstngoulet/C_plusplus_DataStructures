#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	 char  *P1;   // P1 will point to a char cell
	   char  *P2;   // P2 will point to a char cell too

	   // We want to allocate new cells in the Heap area of memory
	   P1 = new char;  // a new cell is created and P1 points to it
	   P2 = new char;  // another cell is created and P2 points to it

	   *P1 = 'a';  // 'a’ goes into the cell pointed to by P1

	   *P2 = 'b';   // 'b’goes into the cell pointed to by P2

	   cout << *P1 << *P2 << endl;

	   delete P2; // releases P2's cell and P2 becomes undefined
	   P2 = P1;   // P2 now points to the same place as P1

	   cout << *P1 << *P2 << endl;

}