//
//  AdjList.h
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/19/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#ifndef GraphLibrary_AdjList_h
#define GraphLibrary_AdjList_h

typedef struct node{
    
    int node_id;
    int node_value;
    struct node* nextNode;
    
}Node;

typedef struct graph{
    
    Node** node_list;
    int nNodes;
}Graph;

Graph initGraph(Graph, int);

void printGraph(Graph);

Node* initNode(int);

int insertEdge(Graph, int, int);

int deleteEdge(Graph, int, int);

int isAdjacent(Graph, int, int);

int* getNeighbours(Graph, int ,int*);

int getNodeValue(Graph, int);

int setNodeValue(Graph, int, int);



#endif
