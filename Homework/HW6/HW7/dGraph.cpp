//
//  dGraph.cpp
//  HW7
//
//  Created by Justin Goulet on 11/21/15.
//  Copyright © 2015 Justin Goulet. All rights reserved.
//

#include "dGraph.h"
#include <fstream>
using namespace std;
// ====   For the dgraph.cpp file ====================================

dgraph::dgraph()
{
    countUsed = 0;
    
    //Init all names to blank chars
    for (int i = 0; i < SIZE; i++) {
        Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;
    }
}

dgraph::~dgraph(){
    //Called by LList
}

void dgraph::fillTable(){
    
    //Gtable
    
    ifstream fin ("table.txt", ios::in);
    char x; int count = 0;
    while (fin >> x)  // can read another line?
    {
        //cout << "Got " << x;    //This is the new vertex
        
        //For teh particular index, set the vertex name
        if (x) {
            Gtable[countUsed].vertexName = x;
        }
        
        //Get the count of the Adjacency list
        fin >> count;
        
        //Set the count to the GVertex within our table
        Gtable[countUsed].outDegree = count;
        
        //Add each Adjacency to the slist, which will become our Adjacency list
        for (int i = 1; i <= count; i++) // for count times
        {
            fin >> x;
            //cout << " and " << x << " ";
            Gtable[countUsed].adjacentOnes.addRear(x);
        }
        //fin >> x;
        
        //Get the visit count next
        //cout << "remaining: " << x <<endl;
        
        //Display the count
        //cout << "Count: " << count << endl;
        
        //Display the final gtabel
        //cout<< Gtable[numOfVertex].vertexName << " with adjancency: ";
        //Gtable[numOfVertex].adjacentOnes.displayAll();
        
        //Increase the index
        countUsed++;
        
        //cout << endl;
    }
    fin.close();
}

//Hint on displaygraph::
void dgraph::displayGraph(){
    
    //cout << "displaying" <<endl;
    cout << endl;
    cout << "Current Graph:\n\n V | # | Adj.\tVisit #" << endl;
    cout << "------------------------" << endl;
    
    for (int i = 0; i < countUsed; i++)
    {
        //Make it look decent
        cout << " " << Gtable[i].vertexName << " | " << Gtable[i].outDegree << " | ";
        (Gtable[i].adjacentOnes).displayAll();
        cout << "\t" << Gtable[i].visit << endl;
    }
    
    cout << endl;
}

int dgraph::findOutDegree(char a){
    
    if (countUsed == 0) return -1;
    else return Gtable[currentVertex(a)].outDegree;
}

slist dgraph::findAdjacency(char a){
    if (countUsed > 0) return Gtable[currentVertex(a)].adjacentOnes;
    else{
        //Else, it DNE, return an empty one;
        slist empty;
        cout << "DNE";
        return empty;
    }
}

int dgraph::currentVertex(char vertexLetter)
{
    //Determine the index of the vertex
    for (int i = 0; i < countUsed; i++)
        if (Gtable[i].vertexName == vertexLetter) return i;
    
    //If it DNE, return -1
    return -1;
}


void dgraph::visit(int visitNumber, char vertex){
    //Increment the visit number of the vertex
    Gtable[currentVertex(vertex)].visit = visitNumber;
}

bool dgraph::isMarked(char vertex){
    //If the visit number is 0, it has not been marked yet. Else, return tru.
    if (Gtable[currentVertex(vertex)].visit == 0) return false;
    else return true;
}



