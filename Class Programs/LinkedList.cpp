#include <iostream>

using namespace std;


	
int main(int argc, char *argv[]) {
	
	struct Node{
			int Elem;
			Node *Front;
			Node *Next;
			Node *Rear;
		};
	
		Node *Front;  	// will point to the front node
	   Node *Rear;   	// will point to the rear node
	   Node *Second;  // will point to the second node

	   Front = new Node;     // Front points to a new node
	   Rear  = Front;        	 // Rear points to the same node
	   Rear->Next = NULL;    // no other nodes
	   Rear->Elem = 3;       	// put data in the rear node

	   // This adds a node to the rear
	   Rear->Next = new Node; 	 // make the rear node point to a new node
	   Rear = Rear->Next;      	// rear points to the new one
	   Rear->Next = NULL;      	// new ones points to nothing yet
	   Rear->Elem = 5;         	// put 5 in the new one

	   cout << "Front: " <<Front->Elem << endl;   // Q 12: what's in the front node?
	   cout << "Rear: " << Rear->Elem << endl;    // Q 13: what's in the rear node?

	   // This deletes a node from the front
	   Second = Front->Next;     // Front's next pointer is saved
	   delete Front;             		// Front node is gone
	   Front = Second;           	// Front pointer is reassigned.

	   cout << "Front: " << Front->Elem << endl;   // Q 14: what's in the front node?

}