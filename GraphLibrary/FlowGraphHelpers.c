//
//  FlowGraphHelpers.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/20/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include "AdjList.h"
#include "FlowGraphHelpers.h"


int setSource(Graph G, int n){
    
    if(n >= G.nNodes)
        return -1;
    else
        G.node_list[n]->isSource = 1;
    return 1;
}

int setSink(Graph G, int n){
    
    if(n >= G.nNodes)
        return -1;
    else
        G.node_list[n]->isSource = 1;
    return 1;
    
}

int setMaxEdgeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->maxEdgeCapacity = cap;
    return 1;
}

int setMaxNodeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->maxNodeCapacity = cap;
    return 1;
    
}

int setEdgeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->currEdgeCapacity = cap;
    return 1;
    
}

int setNodeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->currNodeCapacity = cap;
    return 1;
}





