//
//  llistClient.cpp
//  llist
//
//  Created by Justin Goulet on 10/10/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//
//
//  Compiler:               XCODE.dmg
//  Author:                 Justin Goulet
//  Date Last Modified:     Oct 12, 2015
//
#include <stdio.h>
#include "llist.h"
#include <iostream>

using namespace std;


llist::llist (){        // constructor
    Front = Rear = NULL;
    Count = 0;
}

llist::~llist(){        // destructor
    //cout << "\nCalling the Llist Destructor" << endl;
    
    if (Count > 0) {
        while (!isEmpty()) {
            deleteFront(Front ->Elem);
        }
    }
}

bool llist::isEmpty(){
    
    //cout << "Is Empty" << endl;
    if (Front == NULL && Rear == NULL && Count == 0)
        return true;
    return false;
}

void llist::displayAll(){
    
    if (Count == 0) {
        cout << "[EMPTY]";
    }
    else{
        Node *P = Front;
        //cout << "Count: " << Count << endl;
        cout << "[";
        
        for (int K = 0; K < Count; K++){
            el_t tempData = P -> Elem;
            
            cout << " " << tempData;
            P = P->Next;
        }
        cout << "]";
    }
}

void llist::addRear(el_t NewNum){
    if (Count == 0) {
        //Create a new node and make the front and rear both point to it.
        Node *newNode = new Node;
        newNode -> Elem = NewNum;
        newNode -> Next = NULL;
        Front = newNode;
        Rear = newNode;
    }
    else{
        Rear->Next = new Node;
        Rear = Rear->Next;
        Rear->Elem = NewNum;
        Rear->Next = NULL;
    }
    Count++;
}

void llist::deleteFront(el_t& OldNum){
    if (Count == 0 || Front == NULL) {
        throw Underflow();
    }
    else if (Count == 1){
        //Delete: delete node then set the front and rear to null
        OldNum = Front->Elem;
        delete Front;
        Front = Rear = NULL;
        Count--;
    }
    else{
        //cout << "Front: " << Front -> Elem << endl;
        OldNum = Front->Elem;
        Node *Second;
        Second = Front->Next;
        delete Front;
        Front = Second;
        Count--;
    }
}

void llist::addFront(el_t NewNum){
    if (Count == 0) {
        Front = new Node;
        Front -> Elem = NewNum;
        Rear = Front;
    }
    else{
        Node *x;
        x = new Node;
        x->Elem = NewNum;
        x->Next = Front;
        Front = x;
    }
    
    Front->Elem = NewNum;
    Count++;
}

void llist::deleteRear(el_t& OldNum){
    
    if (Count <= 0) {
        throw Underflow();
    }
    else if (Count == 1){
        deleteFront(OldNum);
        cout << "current Item (Front): " << OldNum << endl;
    }
    else{
        OldNum = Rear->Elem;
        Node *p = Front;
        //Make p go to the one right before rear (using while) – this does not work if you have only one node
        if (Count == 1) {
            Front = Rear = NULL;
        }
        else{
            //Find the Rear
            for (int i = 1; i < Count -1; i++) {
                p = p -> Next;
            }
            //cout << "P: " << p -> Elem << endl;
            
            //Now that P is the next to rear, set p Next t null and delete rear. Make P the new rear
            p -> Next = NULL;
            Rear = p;
        }
        cout << "current Item: " << OldNum << endl;
        Count--;
    }
}

void llist::deleteIth(int I, el_t& OldNum){

    //cout << "I: " << I << " size: " << Count << endl;
    if (I < 1) {
        throw Underflow();
    }
    else if (I == 1) {
        deleteFront(OldNum);
    }
    else if (I == Count + 1){
        deleteRear(OldNum);
    }
    else if (I > Count + 1){
        throw OutOfRange();
    }
    else if (I < 1){
        throw Underflow();
    }
    else{
        //Save the current front
        Node *tempNode = Front;
        
        //Scan all of the nodes for the one at position i-1
        for (int K = 1; K < I-1; K++)
        { tempNode = tempNode->Next; }
        
        //Save the next position in a pointer variable to delte
        Node *toDelete = tempNode -> Next;
        
        //We got the position at i-1 becuase we need access to set the new next to it
        tempNode -> Next = toDelete -> Next;
        
        delete toDelete;
        
        
        //3) Reduce Count
        Count--;
    }
}

void llist::addbeforeIth(int I, el_t newNum){
    
    //cout << "I: " << I << " size: " << Count << endl;
    if (I < 1) {
        throw Underflow();
    }
    if (I == 1) {
        addFront(newNum);
    }
    else if (I == Count + 1){
        addRear(newNum);
    }
    else if (I > Count + 1){    //The user can still add to the last
        throw OutOfRange();
    }
    else if (I < 1){
        throw Underflow();
    }
    else{
        //Save the current front
        Node *tempNode = Front;
        
        //Scan all of the nodes for the one at position i-1
        for (int K = 1; K < I-1; K++)
        { tempNode = tempNode->Next; }
        
        //Display (for testing) the found node
        //cout << "Found Node: " << tempNode ->Elem << endl;
        //cout << "Put item: " << newNum << " before " << tempNode ->Elem << endl;
        
        //Create a new node to store the variable
        Node *holdingNode = new Node;
        
        //Set the new node Next to the temp node next
        holdingNode -> Next = tempNode -> Next;
        
        //Set the data
        holdingNode -> Elem = newNum;
        
        //set the tempnode next to the new node
        tempNode -> Next = holdingNode;
        
        //4) Increase Count
        Count++;
    }
}

Node llist::frontNode()
{
    return *Front;
}

Node llist::tailNode()
{
    return *Rear;
}

void llist::clearAll()
{
    el_t head;
    while (!isEmpty()) {
        deleteFront(head);
    }
}
