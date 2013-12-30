//
//  GraphTraversalAlgorithms.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/24/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"
#include "GraphTraversalAlgorithms.h"
#include "FlowGraphHelpers.h"


GraphPath* init_path(){
    
    GraphPath* p = (GraphPath*)malloc(sizeof(GraphPath));
    p->nNodes = -1;
    p->success = 0;
    p->node_list = (int*)malloc(20*sizeof(int));
    return p;
    
}

GraphPath* DFS_Traversal(Graph G, int sNode_id, int* visited, int eNode_id, GraphPath* p){
    
    // get list of neighbours for startNode
    
    int v_node_id;
    Node* cur;
    
    int* buf = (int*)malloc(10*sizeof(int));
    
    for (int i = 0; i < 10 ;i++)
        buf[i] = -1;
    
    buf = getNeighbours(G, sNode_id, buf);
    
    //for (int i = 0; i < 10 ;i++)
     //   printf("buf[%d] : %d", i, buf[i]);
    
    //printf("\n");
    
    int s_ind = -1;
    while(buf[++s_ind]!=-1){
        v_node_id = buf[s_ind];
        

            
        if(!visited[v_node_id]){
            
            if(G.isFlowGraph){
                cur = isAdjacent(G, sNode_id, v_node_id);
                
                if(cur->currEdgeFlow == cur->maxEdgeCapacity){
                    
                    // no edge exist in residual graph
                    return p;
                }
            }
            
            visited[v_node_id]=1;
            //printf("visiting node : %d \n", v_node_id);
            
            if(v_node_id == eNode_id) {
                
                p->nNodes = p->nNodes+1;
                p->node_list[p->nNodes] = eNode_id;
                p->success = 1;
                
                //printf("\n visit Stat : %d, %d, %d", p->nNodes, p->success, p->node_list[p->nNodes]);
                //printf("\n added node : %d",  p->node_list[p->nNodes]);
                
                return p;
                
            }
            p = DFS_Traversal(G, v_node_id, visited, eNode_id, p);
            if( p->success > 0){
                
                p->nNodes = p->nNodes + 1;
                p->node_list[p->nNodes] = v_node_id;
                

                //printf("\n added node : %d",  p->node_list[p->nNodes]);
                return p;
                
            }
        }
        
    }
    

    
    return p;
    
    
}

GraphPath* getPath(Graph G, int sNode, int eNode){
    
   // printf("Get path called \n ");
   // printf("Starting node : %d, Ending node : %d \n", sNode, eNode);
    
    int* visited = (int*)malloc(G.nNodes*sizeof(int));
    
    GraphPath* p = init_path();
    
    
    
    
    for(int i = 0; i<G.nNodes; i++)
        visited[i] = 0;
    
    p = DFS_Traversal(G, sNode, visited, eNode, p);
    
    if(p->success > 0){
        
        //printf("Here :");
        //printf("\n nNodes in path : %d ", p->nNodes);
        
        
        p->nNodes = p->nNodes + 1;
        p->node_list[p->nNodes] = sNode;
    }
    


    displayPath(G, p);
    return p;
    
    
}






