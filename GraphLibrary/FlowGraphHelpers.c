//
//  FlowGraphHelpers.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/20/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "AdjList.h"
#include "FlowGraphHelpers.h"


Graph constructResidualGraph(Graph G){
    
    
    Graph Gf;
    
    int cur_node_id, next_node_id;
    
    
    Gf = cloneGraph(G);
    Node* cur; Node* cur_tmp;
    
    for (int i = 0; i < G.nNodes ; i++){
        
        cur = G.node_list[i];
        //cur_R = Gf.node_list[i];
        
        cur_node_id = cur->node_id;   
        
        //printf("\n before round : %d \n", i);
        //printGraph(Gf);
        
        while(cur != NULL){
            
            
            // if there is an edge (u,v), add an edge (v,u).
            // Assume that the original graph doesn't have pairwise cycle.
            
            if(cur->nextNode!=NULL){
                 
                next_node_id = cur->nextNode->node_id;
                
                cur_tmp = insertEdge(Gf, next_node_id, cur_node_id,  cur->nextNode->edge_weight);
                
                //set the residual capacity to zero on initialization.
                
                
                cur_tmp->currEdgeFlow = cur->nextNode->maxEdgeCapacity;
                cur_tmp->maxEdgeCapacity = cur->nextNode->maxEdgeCapacity;
                
                cur_tmp->currNodeCapacity = cur->nextNode->maxNodeCapacity - cur->nextNode->currNodeCapacity;
                
                cur_tmp->edge_weight = cur->nextNode->edge_weight;
                cur_tmp->isSink = 0;
                cur_tmp->isSource = 0;
                
                cur_tmp->maxEdgeCapacity = cur->nextNode->maxEdgeCapacity;
                cur_tmp->maxNodeCapacity = cur->nextNode->maxNodeCapacity;
                
                cur_tmp->node_value = cur->node_value;
                
                //printf("\n during round : %d \n", i);
                //printGraph(Gf);
                
            }
            
            cur = cur->nextNode;
            //cur_R = cur_R->nextNode;
            
            
            
        }
        
        
        
    }
    
    //printGraph(Gf);
    
    return Gf;
    
    
    
}


int computeFlow(Graph G, int startNode_id){
    
    Node* cur = G.node_list[startNode_id];
    int flow = 0;
    while(cur->nextNode!= NULL){
       
        cur = cur->nextNode;
        flow += cur->currEdgeFlow;
        
    }
    return flow; 
    
}

//set node with node_id 'n' as source of Flow graph  
int setSource(Graph G, int n){
    
    if(n >= G.nNodes)
        return -1;
    else
        G.node_list[n]->isSource = 1;
    return 1;
}

//set node with node_id 'n' as sink of Flow graph  

int setSink(Graph G, int n){
    
    if(n >= G.nNodes)
        return -1;
    else
        G.node_list[n]->isSource = 1;
    return 1;
    
}

int setMaxEdgeCapacity(Graph G, int n1, int n2, int cap){
    
    Node* cur = isAdjacent(G, n1, n2);
    
    if(cur == NULL)
        return -1;
    //printf(" \n capacity before : %d", cur->currEdgeCapacity);
    
    cur->maxEdgeCapacity = cap;
    
    
    cur = isAdjacent(G, n1, n2);
    
    //printf(" \n capcity after : %d", cur->currEdgeCapacity);
    
    return 1;
}

int setMaxNodeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->maxNodeCapacity = cap;
    return 1;
    
}



int setNodeCapacity(Graph G, int n, int cap){
    
    G.node_list[n]->currNodeCapacity = cap;
    return 1;
}

int incrementEdgeFlow(Graph G, int n1, int n2, int flow){
    
    Node* cur = isAdjacent(G, n1, n2);
    if(cur==NULL)
        return 0;

    if(cur->maxEdgeCapacity < flow)
        return 0;
        
    cur->currEdgeFlow = cur->currEdgeFlow + flow;
    
    assert(cur->currEdgeFlow <= cur->maxEdgeCapacity);
    
    return 1;

}




int getPathCapacity(Graph G, GraphPath p){
    
    int min_capacity = 10000;
    
    Node* edge_buf;
    int res_capacity;
    
    for (int i = p.nNodes ; i > 0 ; i--){
        
        edge_buf = isAdjacent(G, p.node_list[i], p.node_list[i-1]);
        
        res_capacity = edge_buf->maxEdgeCapacity - edge_buf->currEdgeFlow ;
        

        edge_buf = isAdjacent(G, p.node_list[i], p.node_list[i-1]);
                printf("\n getting capacity : %d, %d : %d", p.node_list[i], p.node_list[i-1], res_capacity);
        
        if(res_capacity < min_capacity)
            min_capacity = res_capacity;
            
        
        
    }
    return min_capacity;
    
}


int displayPath(Graph G, GraphPath* p){
    
    printf("\n displaying path :");
    printf("\n #nodes : %d, success : %d \n", 1 + p->nNodes, p->success);
    for(int i = 0; i <= p->nNodes ; i++){
        
        printf("node_id : %d ->",p->node_list[i]);
        
    }
    printf("\n");
    
    
    
    return 1;
}








