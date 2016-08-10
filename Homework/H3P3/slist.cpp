//
//  slist.cpp
//  llist
//
//  Created by Justin Goulet on 10/19/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include "slist.h"
#include <iostream>

using namespace std;

slist::slist (){        // constructor
    Front = Rear = NULL;
    Count = 0;
}

/**
 *  Function:   Replace the value Elem with the value at the current position, i. If i = 0, I DNE
 *
 *  @params:    Elem:   The new element you wish to place
 *              i:      The index of which you wish to replace
 */
void slist::replace(el_t Elem, int i){
    
    if (i == 0) {
        //Do nothing because it is not in list
    }
    else{
        Node *current = Front;
        
        //Find the node at index i
        //Note it is -2 because we took in the position, not the index
        for (int position = 0; position <= i-2; position++) current = current->Next;
        
        //Set the new element
        current -> Elem = Elem;
    }
}

/**
 *  Function:   Search for the key in the list
 *
 *  @params:    key:        the object you wish to search for
 *
 *  @returns    iterator:   The index at which the object was found. 0 if DNE
 */
int slist::search(el_t key){
    
    Node *current = Front;
    int iterator = 1;
    
    //While the node is not the last and while there are still more to search
    while (iterator <= Count && current->Elem != key) {
        current = current->Next;
        iterator++;
    }
    
    //If we went too far, it DNE, return 0
    if (iterator > Count) return 0;
    
    return iterator;
}

/**
 *  Function:   Overload operator
 *
 *  @params:    el_t:       The object you are comparing
 *
 *  @returns    boolean:    Whether or not the object is the same or not
 */
// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference
slist& slist::operator=(const slist& OtherOne)
{
    el_t previous;
    
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
            this->deleteRear(previous);
        // this-> object has to be built up by allocating new cells (**)
        
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne.
        {
            this->addRear(P->Elem);    //P’s element is added to this->
            P = P->Next;               // Go to the next node in OtherOne
        }
    }// end of if
    return *this;    // return the result unconditionally.
}

/**
 *  Function:   Copy Constructor
 *
 *  @params:    slist:      The object you are copying
 *
 *  @returns    Nothing
 */
slist::slist(const slist& Original)
{
   
    
    if (Original.Count == 0) {
        //Do nothing (nothing to copy)
    }
    else{
        //  this->'s data members need to be initialized first
        this->Front = Original.Front;
        this->Rear = Original.Rear;
        this->Count = 0;
        
        //  this-> object has to be built up by allocating new cells
        //  and copying the values from Original into each cell as we did with
        //  operator= above. To do this, see the (**) lines in Operator Overloading of =.
        
        Node *currentNode = Original.Front;
        
        while (this->Count != Original.Count) {
            this->addRear(currentNode->Elem);
            currentNode = currentNode->Next;
        }
        
    }
    
    //  Nothing to return.
}

/**
 *  Function:   Overload operator ==
 *
 *  @params:    slist:      The object you are comparing
 *
 *  @returns    boolean:    Whether or not the object is the same or not
 */
bool slist::operator==(slist &list2)
{
    //In order to check if the objects are the same, they must have the same nodes, in the same order. We are going to run a comparison for each node. If the node is not the same, then we will break out of the loop by returning false.
    //If the list is true, then rerturn true
    
    //First, check to see if the count is different on the lists. This is an easy indicator wheteher or not they are the same. If tehy have differnt sizes, we dont have to do any further comparisons
    if (this->Count != list2.Count) {return false;}
    else{
        //Now that the sizes are the same, let's start the comparison
        Node *list2CurrentNode = list2.Front;
        Node *list1CurrentNode = this -> Front;
        
        //Begin loop
        for (int i = 0; i < list2.Count; i++) {
            //For testing, display the comparison
            //displayNode(*list1CurrentNode);
            //displayNode(*list2CurrentNode);
            
            //If they are equal, move to the next one
            if (list1CurrentNode->Elem == list2CurrentNode->Elem)
            {
                //Now that the current ones are the same, let's make sure they are pointing to the same value as well.
                if ((list1CurrentNode->Next != NULL) && (list2CurrentNode->Next != NULL)){
                    if (list1CurrentNode->Next->Elem == list2CurrentNode->Next->Elem){
                        //If the next nodes are not null and they still exists, move the current node to the next one.
                        list1CurrentNode = list1CurrentNode->Next;
                        list2CurrentNode = list2CurrentNode->Next;
                    }
                    else return false;
                
                }
                
            }//End of checking current
            
            //If they are not eaual, stop loop now.
            else
                return false;
        }
    }
    
    //If you made it this far, everything is equal
    return true;
}

//Please note that this method should be in the llist class, but because we aren't turning that in, I placed it here.

/**
 *  Function:   Display Node
 *
 *  @params:    Node:       The node that will be displayed on the screen
 *
 *  @returns    Nothing.
 */
void slist::displayNode(Node aNode)
{
    if (aNode.Next == NULL) {
        cout << "\n{\n\t\"Elem\" : \""
        << aNode.Elem
        << "\"\n\t\"Next\" : \""
        << "NULL"
        << "\"\n}" << endl;
    }
    else{
        cout << "{\n\t\"Elem\" : \""
        << aNode.Elem
        << "\"\n\t\"Next\" : \""
        << aNode.Next->Elem
        << "\"\n}" << endl;
    }
}

