

//INSTRUCTION
//Look for **.
//Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)

// =========================================================

//HW1P1 stack
//Your name: Justin Goulet
//Complier:  X-Code
//File type: c++

//================================================================

#include "stack.h"
#include <iostream>

using namespace std;


//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{
    top = -1; /* indicate an empty stack*/
}

stack::~stack()
{
    //Do nothing.
}

// ** Destructor does not have to do anything since this is a static array.
//stack::~stack();
  
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
  {
      if (top == MAX-1)
          return true;
      else
          return false;
  }
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
    if (isFull())
    {
        throw Overflow();
    }
    else {
        top++;
        el[top] = elem;
    }
}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t&item)
{
    if (isEmpty())
    {
        throw Underflow();
    }
    else {
        if (isdigit(el[top])) {
            item = el[top] - 48;
        }
        else
        {
            item = el[top];
        }
        top--;
    }
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& item)
{
    if (isEmpty())
    {
        try {
            throw Underflow();
        } catch (Underflow) {
            cout <<"Error Found in Expression: "<<endl;
        }
        item = NULL;
    }
    else {
        item = el[top];
    }
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    if (isEmpty())
        cout << ".[ empty ]." << endl;
    else
        for (int i=top; i>=0; i--)
      {
          if (!isdigit(el[i])) {
              cout << (el[i])<< endl;
          }
          else
          {
              cout << el[i] << endl;
          }
      }
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
    top = -1;
}
