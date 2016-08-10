//
//  SListWithCompartorClient.cpp
//  llist
//
//  Created by Justin Goulet on 10/26/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "slist.h"
using namespace std;
typedef int el_t ;


void copyTest(slist thisList){
    
    thisList.addRear(6);
    cout << "Displaying the second list" << endl;
    thisList.displayAll();
}

int main()
{
    slist currentList;
    cout << "Creating List 1:" << endl;
    for (int i = 1; i < 6; i++) { currentList.addRear(i);}
    currentList.displayAll();
    
    cout << "\nCalling the copyTest func" << endl;
    copyTest(currentList);
    currentList.displayAll();
    
    cout << "\nset the list = to itself" << endl;
    currentList = currentList;
    currentList.displayAll();
    
    cout << "\nCreate a second list" << endl;
    slist list2;
    for (int i = 7; i < 11; i++) { list2.addRear(i);}
    list2.displayAll();
    
    cout << "\nSet the first list equal to the second" << endl;
    list2 = currentList;
    list2.displayAll();
    
    cout << "\nRemove a rear node from list 1" << endl;
    el_t removedValue;
    currentList.deleteRear(removedValue);
    
    cout << "\nDisplay first list" << endl;
    currentList.displayAll();
    currentList.displayAll();
    
    cout << "\nDisplay second list" << endl;
    list2.displayAll();
}