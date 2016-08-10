//
//  slist.h
//  llist
//
//  Created by Justin Goulet on 10/19/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

//****************************************************************************
//  CS311 Linked - by Rika for those who could not get HW3 to work
//  Header File  llist.h
//****************************************************************************
//
//  Compiler:               XCODE.dmg
//  Author:                 Justin Goulet
//  Date Last Modified:     Oct 12, 2015
//
#include "llist.h"

typedef int el_t ;


class slist : public llist
{
    
public:
    
    slist ();                                   //Constructor (Same as LList)
    
    int search(el_t key);                       //Returns the index at which the item exists
    
    void replace(el_t Elem, int i);             //Replaces the item at index i with the element Elem
    
    slist& operator=(const slist& OtherOne);    //Ovrloads the = operator
    
    bool operator==(slist &list2);               //Ovrloads the == operator
    
    slist(const slist& Original);               //Copy constructor
    
    void displayNode(Node aNode);              //Displays the disctionary of a node
};
