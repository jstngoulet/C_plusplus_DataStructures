//INSTRUCTION
//Look for **.

// =========================================================

//HW1P1 stack client
//Your name: Justin Goulet
//Complier:  X-Code
//File type: Client1.c++ (Driver Program)


/**
 *
 *  Please note that this single client program operates both the Stack and the Queue Data Structures.
 */

//================================================================

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "vstack.h"
using namespace std;



int main()
{
    
    //The below is for the stack test
    stack postfixstack;  // integer stack
    string expression;
    
    int i = 0;  // character position within expression
    int operatorCount = 0, numberCount = 0;
    
    //Array of strings to test
    string test[] = {"34+", "345+*", "722+-", "34+56++", "12+34*45+-+", "1234567891234", "+", "3+", "3#", "2345+"};
    int placeholder = 0;
    
    int box1;  // receive things from pop
    int box2;  // receive things from pop
    
    bool errorFound = false;
    
    //Ten test items
    for (placeholder = 0; placeholder < 10; placeholder++) {
        
        cout << "Expression: " << test[placeholder] << endl;
        expression = test[placeholder];
        
        while (expression[i] != '\0')
        {
            try
            {
                //cout << "Expression: " << expression << endl;
                
                if (isdigit(expression[i])) {
                    //cout << "Is Digit: " << expression[i] << endl;
                    postfixstack.push(expression[i]);
                    numberCount ++;
                }
                else if (expression[i] == '+' | expression[i] == '-' | expression[i] == '*')
                {
                    //cout << "Is operator: " << expression[i] << endl;
                    box1 = (int)postfixstack.pop();
                    box2 = (int)postfixstack.pop();
                    
                    switch (expression[i]) {
                        case '+':
                            cout << box1 << " + " << box2;
                            box1 += box2;
                            cout << " = " << box1 << endl;
                            operatorCount++;
                            break;
                            
                        case '-':
                            cout << "" << box2 << " - " << box1;
                            box1 = box2 - box1;
                            cout << " = " << box2 << endl;
                            operatorCount++;
                            break;
                            
                        case '*':
                            cout << box1 << " * " << box2;
                            box1 *= box2;
                            cout << " = " << box1 << endl;
                            operatorCount++;
                            break;
                            
                        default:
                            cout << "Unattributable Expression. Please try again." << endl;
                            errorFound =  true;
                            break;
                    }
                    
                    //cout << "Result in Stack: " << box1 <<endl;
                    postfixstack.push(box1);
                }
                else {
                    errorFound = true;
                    throw "invalid item";
                }
            } // this closes try
            
            // Catch exceptions and report problems and quit the program now.
            catch (stack::Overflow)
            {
                errorFound = true;
                cout << "Please realloc stack. There seems to be a max size issue." << endl;
                break;
            }
            catch (stack::Underflow)
            {
                errorFound = true;
                cout << "Ran out of items. Please check structure of expression!" << endl;
                break;
            }
            catch (char const* errorcode) // for invalid item
            {
                errorFound = true;
                cout << "Error Code Recieved: ";
                cout << errorcode << endl;
            }
            
            i++;
            
            
            
        }// end of while
        if (numberCount == 0)
        {
            errorFound = true;
            cout << "No Numbers Found!" << endl;
        }
        else if (operatorCount != numberCount - 1) {
            errorFound = true;
            cout << "Too Few Operands!" << endl;
        }
        else if(!errorFound)
        {
            cout << "\nResult: " << (int)postfixstack.topElem() << endl;
        }
        postfixstack.clearIt();
        i = 0;
        operatorCount = 0;
        numberCount = 0;
        
        cout <<"\n\n"<<endl;
    }
    
    //End of stack test.
    
    /*
    //Start of queue test
    queue letterQ;
    string alphaExpression, tempHolder;
    
    i = 0;
    letterQ.add("A");
    letterQ.add("B");
    letterQ.add("C");
    
    while (i < letterQ.getSize()) {
        
        //We are going to make this last as long as we can.
        //We are going to take the first element, remove it and make it the temp, then add it to every element after it.
        tempHolder = letterQ.frontElem();
        cout << "Temp Holder: " << tempHolder << endl;
        for (int current = 0; current < letterQ.getSize(); current++) {
            letterQ.add(tempHolder + letterQ.remove());
        }
        
        letterQ.remove();
        
        //cout <<"end line" <<endl;
        i++;
        
    }
    
    letterQ.displayAll();
    
    //End of Queue Test
    */
    
    //Start of VStack Test
    vstack postFixStackVector;  // integer stack
    string vectorExpression;
    
    i = 0;  // character position within vectorExpression
    operatorCount = 0, numberCount = 0;
    
    //Array of strings to test
    placeholder = 0, box1 = 0, box2 = 0;
    
    errorFound = false;
    
    //Ten test items
    for (placeholder = 0; placeholder < 10; placeholder++) {
        
        cout << "vectorExpression: " << test[placeholder] << endl;
        vectorExpression = test[placeholder];
        //placeholder--;
        //cout << "placeholder: " <<placeholder <<endl;
        
        while (vectorExpression[i] != '\0')
        {
            try
            {
                //cout << "vectorExpression: " << vectorExpression << endl;
                
                if (isdigit(vectorExpression[i])) {
                    //cout << "Is Digit: " << vectorExpression[i] << endl;
                    postFixStackVector.push(vectorExpression[i]);
                    numberCount ++;
                }
                else if (vectorExpression[i] == '+' | vectorExpression[i] == '-' | vectorExpression[i] == '*')
                {
                    //cout << "Is operator: " << vectorExpression[i] << endl;
                    box1 = (int)postFixStackVector.pop();
                    box2 = (int)postFixStackVector.pop();
                    //cout << "Box 1: " << box1 << "\nBox 2: " << box2 << "\n\n" <<endl;
                    
                    switch (vectorExpression[i]) {
                        case '+':
                            //cout << box1 << " + " << box2;
                            box1 += box2;
                            //cout << " = " << box1 << endl;
                            operatorCount++;
                            break;
                            
                        case '-':
                            //cout << "" << box2 << " - " << box1;
                            box1 = box2 - box1;
                            //cout << " = " << box2 << endl;
                            operatorCount++;
                            break;
                            
                        case '*':
                            //cout << box1 << " * " << box2;
                            box1 *= box2;
                            //cout << " = " << box1 << endl;
                            operatorCount++;
                            break;
                            
                        default:
                            cout << "Unattributable Expression. Please try again." << endl;
                            errorFound =  true;
                            break;
                    }
                    
                    //cout << "Result in Stack: " << box1 <<endl;
                    postFixStackVector.push(box1);
                }
                else {
                    errorFound = true;
                    throw "invalid item";
                }
            } // this closes try
            
            // Catch exceptions and report problems and quit the program now.
            catch (stack::Overflow)
            {
                errorFound = true;
                cout << "Please realloc stack. There seems to be a max size issue." << endl;
                break;
            }
            catch (stack::Underflow)
            {
                errorFound = true;
                cout << "Ran out of items. Please check structure of expression!" << endl;
                break;
            }
            catch (char const* errorcode) // for invalid item
            {
                errorFound = true;
                cout << "Error Code Recieved: ";
                cout << errorcode << endl;
            }
            
            i++;
            
            
            
        }// end of while
        if (numberCount == 0)
        {
            errorFound = true;
            cout << "No Numbers Found!" << endl;
        }
        else if (operatorCount != numberCount - 1) {
            errorFound = true;
            cout << "Too Few Operands!" << endl;
        }
        else if(!errorFound)
        {
            cout << "\nResult: " << (int)postFixStackVector.topElem() << endl;
            
        }
        i = 0;
        operatorCount = 0;
        numberCount = 0;
        box2 = 0; box1 = 0;
        //postFixStackVector.clearIt();
        cout <<"\n\n"<<endl;
    }
    
    //End of Vstack Test
    
    return 0;
    
}

