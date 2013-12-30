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


// Initializes the Graph given :
//
// nNodes : number of Nodes
// isDirected : if the Graph is directed
// isFlowGraph : if the Graph is a flow graph.
//
// return : initialized Graph

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

// Initialize a Node , given:
//
// node_id : id of the node
// weight : assign the edge weight connecting this node to it's previous node
//
// return : reference to the initialized Node

Node* initNode(int node_id , int weight){
    
    Node* buf = (Node*)malloc(sizeof(Node));
    
    buf->node_id = node_id;
    buf->node_value = -1;
    buf->nextNode = NULL;
    buf->edge_weight = weight;
    
    buf->currEdgeFlow = 0;
    buf->currNodeCapacity = -1;
    buf->maxEdgeCapacity = -1;
    buf->maxNodeCapacity = -1;
    
    buf->isSource = 0;
    buf->isSink = 0;
    
    
    return buf;
    
}


// print the Graph G in adjacency list format

void printGraph(Graph G){
    
    Node* cur = NULL;
    
    printf("\nPrinting the graph \n");
    
    for (int i = 0 ;i<G.nNodes ; i++){
        cur = G.node_list[i];
        
        while(cur!=NULL){
            
            printf("(%d : %d)-> ", cur->node_id, cur->currEdgeFlow);
            cur = cur->nextNode;
            
        }
        printf("\n");
        
        
    }
}



Node* insertEdge(Graph G, int n1, int n2, float weight12){
    
    
    Node* cur = NULL;
    float weight21 = weight12;
    
    Node* buf = initNode(n2, weight12);
    
    cur = G.node_list[n1];
    
    while(cur->nextNode!=NULL){
        if(cur->nextNode->node_id == n2)
            return cur->nextNode;
        cur = cur->nextNode;      
    }
    
    cur->nextNode = buf;
    buf->nextNode = NULL;
    
    if(G.isDirected)
        return buf;
    
    
    buf = initNode(n1, weight21);
    cur = G.node_list[n2];
    while(cur->nextNode!=NULL){
        if(cur->nextNode->node_id == n1)
            return cur->nextNode;
        cur = cur->nextNode;     
    }
    
    cur->nextNode = buf;
    buf->nextNode = NULL;
    
    return buf;
    
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
        
        if(!(G.isFlowGraph && (cur->currEdgeFlow >= cur->maxEdgeCapacity)))
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


Graph cloneGraph(Graph G){
    
    Graph Gc ;
    Gc = initGraph(Gc, G.nNodes, G.isDirected, G.isFlowGraph);
    int cur_node_id, next_node_id;
    Node *cur_R, *cur;
    
    
    for (int i = 0; i < G.nNodes ; i++){
        
        cur = G.node_list[i];
        cur_R = Gc.node_list[i];
        
        cur_node_id = cur->node_id;        //printf("%d", cur_R->node_value);
        
        while(cur != NULL){
            
            //printf("accessed \n");
            
            // copy the content of node
            cur_R->currEdgeFlow = cur->currEdgeFlow;
            cur_R->currNodeCapacity = cur->currNodeCapacity;
            cur_R->edge_weight = cur->edge_weight;
            cur_R->isSink = cur->isSink;
            cur_R->isSource = cur->isSource;
            cur_R->maxEdgeCapacity = cur->maxEdgeCapacity;
            cur_R->maxNodeCapacity = cur->maxNodeCapacity;
            cur_R->node_value = cur->node_value;
            
            // if there is an edge in G, add an edge in Gc.
            
            if(cur->nextNode!=NULL){
                next_node_id = cur->nextNode->node_id;
                insertEdge(Gc, cur_node_id, next_node_id, cur->nextNode->edge_weight);
                
            }
            
            cur = cur->nextNode;
            cur_R = cur_R->nextNode;
            
            
   
        }
        
 
    }
    
    //printf("Cloned graph \n ");
    //printGraph(Gc);
    
    
    return Gc;
    
    
}


