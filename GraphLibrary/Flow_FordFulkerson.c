//
//  Flow_FordFulkerson.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/25/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include "AdjList.h"
#include "FlowGraphHelpers.h"
#include "GraphTraversalAlgorithms.h"
#include "FlowAlgos.h"





int Ford_Fulkerson(Graph G,  int sourceNodeId, int sinkNodeId){
    
    int flow = -1; int count = 0;
    int pathCapacity = 0;
    
    Graph Gc = constructResidualGraph(G);
    
    
    
    GraphPath* p;
    
    p = getPath(Gc, sourceNodeId, sinkNodeId);
    
    
   
    
    while(p->success){
        
        printf("\n Iteration : %d", ++count);
        
        pathCapacity = getPathCapacity(Gc, *p);
        
        //printGraph(Gc);

        for(int i=p->nNodes ; i > 0; i--){
            incrementEdgeFlow(Gc, p->node_list[i], p->node_list[i-1], pathCapacity);
        }
        
        //printGraph(Gc);
        
        for(int i=0 ; i < p->nNodes; i++){
            incrementEdgeFlow(Gc, p->node_list[i], p->node_list[i+1], -pathCapacity);
        }
        
        //printGraph(Gc);
        
        //printf("path Capacity : %d \n", pathCapacity);
        
        //return 1;
        p = getPath(Gc, sourceNodeId, sinkNodeId);
    }
    
    printGraph(Gc);
    
    flow = computeFlow(Gc, sourceNodeId);
    
    return flow;
}