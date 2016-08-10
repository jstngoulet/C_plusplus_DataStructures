//
//  vector.h
//  Stacks
//
//  Created by Justin Goulet on 9/21/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

// HW1P2
// Your name: Justin Goulet
// Compiler:  X-Code
// File type: header file vector.h

//=======================================================
#include <vector>
// MAX is unknown to the client

typedef char el_t;      // the el_t type is ** for now
// el_t is unknown to the client

using namespace std;


class vstack
{
    
private: // to be hidden from the client
    
    vector<el_t> currentStack;
    int currentPosition;
    
public: // prototypes to be used by the client
    
    int size;
    
    // exception handling classes
    class Overflow{};
    class Underflow{};
    
    vstack();   // constructor
    ~vstack();  // destructor
    
    // HOW TO CALL: pass the element to be pushed
    // PURPOSE: if not full, enters an element at the top;
    //          otherwise throws an exception - Overflow
    void push(el_t);
    
    // HOW TO CALL: provide variable to receive the popped element
    // PURPOSE: if not empty, removes and gives back the top element;
    //          otherwise throws an exception - Underflow
    el_t pop();
    
    // HOW TO CALL: Set the variable into the temp variable recieved. (Similar to peek());
    // PURPOSE: if not empty, gives the top element without removing it;
    //          otherwise, throws an exception - Underflow
    el_t topElem();
    
    // ************ add good comments for each function *****
    /**
     *    How to call: Use as a boolean expression
     *    Purpose: Determines if the stack is empty by checking the top value.
     */
    bool isEmpty();
    
    /**
     *    How to call: Use as a boolean expression
     *    Purpose: Determines if the stack is ful and needs to be realloc or not.
     */
    bool isFull();
    
    /**
     *    How to call: Use as a single line that does not equate.
     *    Purpose: Shows all remaining elements in the stack
     */
    void displayAll();
    
    /**
     *    How to call: Use as a single line that does not equate
     *    Purpose: resets the stack so the vairable can be reused as a new allocation, but with the same memory use.
     */
    void clearIt();
    
};

// Note: semicolon is needed at the end of the header file


