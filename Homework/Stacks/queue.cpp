//=====================================================
//INSTRUCTION
//Update comments
//Fill in the function body

// =========================================================

//HW1P1 queue
//Your name: Justin Goulet
//Complier:  X-Code
//File type: C++

//================================================================

#include "queue.h"   // constructor
#include <String>
#include <iostream>
using namespace std;


queue::queue()
{
    //Create the object here.
    count = 0;
    front = count;
    rear = 0;
}

queue:: ~queue()
{
    //Remove all objects
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
    if (count > 0) {
        return false;
    }
    else
        return true;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
    if (count == MAX_SIZE) {
        return true;
    }
    else
        return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// HOW TO CALL: provide the element to be added
void queue::add(myType element)
{
    if (isFull()) {
        displayAll();
        throw OverFlow();
    }
    else
    {
        //cout << "Element: " << element <<endl;
        el[count] = element;
        rear++;
        count++;
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back
// HOW TO CALL: provide a holder for the element removed (pass by ref)
myType queue::remove()
{
    if (count > 0) {
        //count--;
        front++;
        return el[front-1];
    }
    else
    {
        throw UnderFlow();
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// TO CALL: provide a holder for the element (pass by ref)
myType queue::frontElem()
{
    return el[front];
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::getSize(){
    return count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
    if (isEmpty())
        cout << ".[ empty ]." << endl;
    else
    {
        cout << "[";
        for (int i=0; i < count; i++)
        {
            if (i < rear - 1) {
                cout << el[i] << ", ";
            }
            else
            {
                cout << el[i];
            }
        }
        cout << "];" <<endl;
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{
    if (count == 1) {
        //Do nothing
    }
    else
    {
        //Set the front to the rear
        front = count;
    }
}




