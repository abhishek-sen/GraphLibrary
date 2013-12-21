//
//  AdjList.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/19/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include"AdjList.h"

Graph initGraph(Graph G, int nNodes, int isDirected, int isFlowGraph){

    G.node_list = (Node**)malloc(nNodes*sizeof(Node*));
    
    for(int i = 0; i < nNodes; i++){
        G.node_list[i] = initNode(i,0);
    }

    G.nNodes = nNodes;
    G.isDirected = isDirected;
    G.isFlowGraph = isFlowGraph;
    
    return G;    
}

Node* initNode(int node_id , int weight){
    
    Node* buf = (Node*)malloc(sizeof(Node));
    
    buf->node_id = node_id;
    buf->node_value = -1;
    buf->nextNode = NULL;
    buf->edge_weight = 0;
    
    buf->currEdgeCapacity = -1;
    buf->currNodeCapacity = -1;
    buf->maxEdgeCapacity = -1;
    buf->maxNodeCapacity = -1;
    
    buf->isSource = 0;
    buf->isSink = 0;
    
    
    return buf;
    
}

void printGraph(Graph G){
    
    Node* cur = NULL;
    
    printf("\nPrinting the graph \n");
    
    for (int i = 0 ;i<G.nNodes ; i++){
        cur = G.node_list[i];
        
        while(cur!=NULL){
            
            printf("%d, ", cur->node_id);
            cur = cur->nextNode;
            
        }
        printf("\n");
        
        
    }
}



int insertEdge(Graph G, int n1, int n2, float weight12){
    
    
    Node* cur = NULL;
    float weight21 = weight12;
    
    Node* buf = initNode(n2, weight12);
    
    cur = G.node_list[n1];
    
    while(cur->nextNode!=NULL){
        if(cur->nextNode->node_id == n2)
            return 1;
        cur = cur->nextNode;      
    }
    
    cur->nextNode = buf;
    buf->nextNode = NULL;
    
    if(G.isDirected)
        return 1;
    
    
    buf = initNode(n1, weight21);
    cur = G.node_list[n2];
    while(cur->nextNode!=NULL){
        if(cur->nextNode->node_id == n1)
            return 1;
        cur = cur->nextNode;     
    }
    
    cur->nextNode = buf;
    buf->nextNode = NULL;
    
    return 1;
    
}

int deleteEdge(Graph G, int n1, int n2){
    
    Node* cur = NULL;
    Node* prev = NULL;
    
    if(!isAdjacent(G, n1, n2))
        return -1;

    cur = G.node_list[n1];

    while(cur->node_id!= n2){
        prev = cur;
        cur = cur->nextNode; 
    }
    
    prev->nextNode = cur->nextNode;
    
    if(G.isDirected)
        return 1;

    cur = G.node_list[n2];
    while(cur->node_id!= n1){
        prev = cur;
        cur = cur->nextNode;   
    }
    
    prev->nextNode = cur->nextNode;
        
    return 1;
    
}

/* 
 
 If Edge is found return the pointer to the node.
 Otherwise return NULL
 
 */
Node* isAdjacent(Graph G, int n1, int n2){
    
    Node* cur = NULL;

    cur = G.node_list[n1];
    
    while(cur->nextNode!=NULL){
        if(cur->nextNode->node_id == n2)
            return cur->nextNode;
        cur = cur->nextNode;
    }
    
    return NULL;
   
}

int* getNeighbours(Graph G, int n1 , int* buf){
    
    // buf pointer to an array of integers.
    // Assume that buf is of sufficient size.
    
    Node* cur = NULL;
 
    int count = 0;
    cur = G.node_list[n1];
    
    while(cur->nextNode!=NULL){
        
        cur = cur->nextNode;
        buf[count++] = cur->node_id;
    }

    return buf;
    
}

int getNodeValue(Graph G, int n){
    
    return G.node_list[n]->node_value;
}

int setNodeValue(Graph G, int n, int val){
    
    if(n >= G.nNodes)
        return -1;
    else
        G.node_list[n]->node_value = val;
    
    return 1;
        
}



