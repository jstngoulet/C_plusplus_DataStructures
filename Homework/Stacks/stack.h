
//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp

// =======================================================

// HW1P1
// Your name: Justin Goulet
// Compiler:  X-Code
// File type: header file stack.h

//=======================================================

const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef char el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        el_t     el[MAX];       // el is  an array of el_t's
        int      top;           // top is index to the top of stack

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t& item);

        // HOW TO CALL: Set the variable into the temp variable recieved. (Similar to peek());
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t& item);

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

