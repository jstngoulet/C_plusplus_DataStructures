//
//  hw3ec.cpp
//  SList
//
//  Created by Justin Goulet on 10/26/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include <iostream>
#include "slist.h"

using namespace std;

slist L1 = *new slist;
slist L2 = *new slist;
el_t placeHolder;

bool compareLists(slist &list1, slist &list2){
    if (list1 == list2) return true;
    else return false;
}

void displayInfo(){
    //Display if both lists are empty;
    cout << "\nList 1 isEmpty: " << L1.isEmpty() << "\nList 2 isEmpty: " << L2.isEmpty() << endl;
    cout << "Lists are equal?: " << compareLists(L1, L2) << endl;
    
    //Now, display the current lists
    cout << "L1";
    L1.displayAll();
    
    cout << "L2";
    L2.displayAll();
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    //Display that both lists are empty;
    displayInfo();
    
    //add 2 elements to l2
    L2.addRear(1); L2.addRear(2);
    
    //Display if both lists are empty;
    
    //L1 has 2 elements and L2 is empty
    L1 = L2;
    L2.clearAll();
    
    //Display if both lists are empty;
    displayInfo();
    
    //Clear both lists and add 1, 2, 3
    L2.clearAll();
    L1.clearAll();
    for (int i = 1; i < 4; i++) {L1.addRear(i); L2.addRear(i);}
    
    //Display if both lists are empty
    displayInfo();
    
    //Remove item '3' from list 2
    L2.deleteRear(placeHolder);
    displayInfo();
    
    //Add 3 and 4 fo to the rear of list 2
    L2.addRear(3); L2.addRear(4);
    displayInfo();
    
    //Remove '3' from list 2
    L2.deleteIth(3, placeHolder);
    displayInfo();
    
    return 0;
}
