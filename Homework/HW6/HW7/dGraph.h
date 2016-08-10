//
//  dGraph.hpp
//  HW7
//
//  Created by Justin Goulet on 11/21/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

const int SIZE = 20;

// this will be in each GTable slot
struct Gvertex
{
    char vertexName;       //the vertex Name
    int outDegree;	//the Out degree
    slist adjacentOnes;   //the adjecent vertices in an slist
    int visit;            // This will hold the visit number in HW7
};

class dgraph
{
    
private:
    Gvertex Gtable[SIZE];
    int  countUsed; // how many slots of the Gtable are actually used
    int currentVertex(char vertexLetter);   //The index of the current vertex
    
public:
    
    dgraph();    // initialize vertexName (blank) and visit numbers (0)
    // initialize countUsed to be 0
    ~dgraph();   // do we have to delete all nodes of slists in table??
    // Question: If we do not do this, will the llist destructor
    // be called automatically???
    
    
    void fillTable();   // read from the input file table.txt and fill GTable
    
    void displayGraph();  // displays in an easy to read format
    
    int findOutDegree(char);  // returns the out degree of a given vertex
    
    slist findAdjacency(char);  // returns the adjacency list of a given vertex
    
    void visit(int, char);  //Enter the given visit number for a given vertex. This is to indicate the order in which the vertexes were visited.
    
    bool isMarked(char);    //Returns true if a guven vertex was already visited (0 means not visited) (0 == False)
    
};