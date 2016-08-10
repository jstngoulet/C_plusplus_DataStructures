//
//  main.cpp
//  HW7
//
//  Created by Justin Goulet on 11/21/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include <iostream>
#include "dGraph.h"
#include "stack.h"

using namespace std;

int main(int argc, const char * argv[]) {
   
    dgraph aGraph;
    
    //Fill the table fromt he file
    aGraph.fillTable();
    
    //Display the graph
    aGraph.displayGraph();
    
    /** For HW 7 Pt 1
    
    //New line
    cout << endl;
    
    //Find the out degree of a vertex specified by the user (until they type "end")
    string value;
    
    //Find all of the verticies
    while (true) {
        
        cout << "Please enter a vertex you wish to find the out degree of \n(type end to quit): ";
        cin >> value;
        cout << endl;
        
        if (value == "end") break;
        
        cout << "Degree found: " << aGraph.findOutDegree(value[0]) << endl;
    }
    
    //Find all of the Adjacency lists
    
    while (true) {
        
        cout << "Please enter a vertex you wish to find the Adjacency list to \n(type end to quit): ";
        cin >> value;
        cout << endl;
        
        if (value == "end") break;
        
        cout << "List found: ";
        aGraph.findAdjacency(value[0]).displayAll();
    }
    **/
    
    //Below is for HW 7 pt 2
    stack s;
    
    int number = 1;
    s.push('A');
    slist aList;
    char V, X;
    
    while (!s.isEmpty()) {
        cout << "Current stack: " << endl; s.displayAll();
        s.pop(V);
        //cout << "Popped: " << V << endl;
        if (!aGraph.isMarked(V)) {
            aGraph.visit(number, V);
            cout << "\nVisited " << V << endl;
            aList = aGraph.findAdjacency(V);
            //cout << "Adj. List: "; aList.displayAll();
            cout << "Pushing "; aList.displayAll(); cout << endl;
            
            while (!aList.isEmpty()) {
                aList.deleteRear(X);
                //cout << "X: "<< X << endl;
                s.push(X);
                //cout << "Pushed X: "<< X << endl;
            }
            number++;
        }
        
        aGraph.displayGraph();
    }
    cout << "\n\n" << endl;
    aGraph.displayGraph();
    
    
    return 0;
}
