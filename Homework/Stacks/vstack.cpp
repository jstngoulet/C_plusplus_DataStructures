//
//  vstack.cpp
//  vstacks
//
//  Created by Justin Goulet on 9/21/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//


//HW1P2 vstack
//Your name: Justin Goulet
//Complier:  X-Code
//File type: c++

//================================================================

#include <iostream>
#include "vstack.h"
#include <vector>

using namespace std;


//** Constructor must initialize top to be -1 to begin with.
vstack::vstack()
{
    //Init the vector (default size ten)
    size = 10;
    vector<el_t> currentStack(size);
    currentPosition = -1;
}

vstack::~vstack()
{
    //Do nothing.
}

// ** Destructor does not have to do anything since this is a static array.
//vstack::~vstack();

// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool vstack::isEmpty()
{
    if (size == 0)
        return true;
    else
        return false;
}

// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool vstack::isFull()
{
    return false;
}

// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void vstack::push(el_t elem)
{
    size++;
    currentStack.push_back(elem);
    currentPosition++;
}

// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
el_t vstack::pop()
{
    if (isEmpty())
    {
        throw Underflow();
        return NULL;
    }
    else {
        
        el_t currentElement = currentStack[currentPosition];
        currentStack.pop_back();
        currentPosition--;
        
        //cout << "Current Element: " << currentElement <<endl;
        
        if (!isdigit(currentElement)) {
            return currentElement;
        }
        else
            return (int)currentElement - 48;
    }
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
el_t vstack::topElem()
{
    return currentStack[currentStack.size() - 1];
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void vstack::displayAll()
{
    if (isEmpty())
        cout << ".[ empty ]." << endl;
    else
        for (int i=0; i<currentStack.size(); i++)
        {
            cout << currentStack[i] << endl;
        }
}

//** clearIt pops all elements from the vstack to make it empty if it is not empty yet.
void vstack::clearIt()
{
    while (!isEmpty()) {
        currentStack.pop_back();
    }
    
    size = 1;
    currentPosition = 0;
}
