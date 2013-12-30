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
    float edge_weight; // generalization for weighted graph
    struct node* nextNode;
    
    // generalization for flow Graph
    int maxEdgeCapacity;
    int currEdgeFlow;
    int maxNodeCapacity;
    int currNodeCapacity;
    int isSource;
    int isSink;
    
}Node;

typedef struct graph{
    
    Node** node_list;
    int nNodes;
    int isDirected;
    int isFlowGraph;
    
    
}Graph;

typedef struct path_struct{
    
    int nNodes;
    int success;
    int* node_list;
    
}GraphPath;


Graph initGraph(Graph, int, int, int);

void printGraph(Graph);

Node* initNode(int, int);

Node* insertEdge(Graph, int, int, float);

int deleteEdge(Graph, int, int);

Node* isAdjacent(Graph, int, int);


int* getNeighbours(Graph, int ,int*);

int getNodeValue(Graph, int);

int setNodeValue(Graph, int, int);

Graph cloneGraph(Graph);




#endif
