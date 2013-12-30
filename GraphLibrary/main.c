//
//  main.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/19/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include "AdjList.h"
#include "FlowGraphHelpers.h"
#include "FlowAlgos.h"


int main(int argc, const char * argv[])
{

    Graph G;
    int flow;
    

 /*
    // initialize the flow graph
    G = initGraph(G, 10, 1, 1);
    
    // add Edges to construct the Flow Graph
    insertEdge(G, 0, 1, 1);
    insertEdge(G, 0, 2, 1);
    insertEdge(G, 0, 3, 1);
    insertEdge(G, 0, 4, 1);
    insertEdge(G, 2, 5, 1);
    insertEdge(G, 3, 6, 1);
    insertEdge(G, 4, 7, 1);
    insertEdge(G, 1, 8, 1);
    insertEdge(G, 5, 9, 1);
    insertEdge(G, 6, 9, 1);
    insertEdge(G, 7, 9, 1);
    insertEdge(G, 8, 9, 1);
    

    
    setSource(G, 0);
    setSink(G, 9);
    
    // add Edge capacity
    
    setMaxEdgeCapacity(G, 0, 1, 3);
    setMaxEdgeCapacity(G, 0, 2, 3);
    setMaxEdgeCapacity(G, 0, 3, 3);
    setMaxEdgeCapacity(G, 0, 4, 3);
    setMaxEdgeCapacity(G, 2, 5, 3);
    setMaxEdgeCapacity(G, 3, 6, 3);
    setMaxEdgeCapacity(G, 4, 7, 3);
    setMaxEdgeCapacity(G, 1, 8, 3);
    setMaxEdgeCapacity(G, 5, 9, 3);
    setMaxEdgeCapacity(G, 6, 9, 3);
    setMaxEdgeCapacity(G, 7, 9, 3);
    setMaxEdgeCapacity(G, 8, 9, 3);
  
    
    // display graph
    //printGraph(G);
    
    flow = Ford_Fulkerson(G, 0 , 9);
  
  */
    
    G = initGraph(G, 6, 1, 1);
    
    insertEdge(G, 0, 1, 1);
    insertEdge(G, 0, 2, 1);
    insertEdge(G, 1, 3, 1);
    insertEdge(G, 1, 4, 1);
    insertEdge(G, 2, 3, 1);
    insertEdge(G, 2, 4, 1);
    insertEdge(G, 3, 5, 1);
    insertEdge(G, 4, 5, 1);
    
    setSource(G, 0);
    setSink(G, 5);
    
    setMaxEdgeCapacity(G, 0, 1, 5);
    setMaxEdgeCapacity(G, 0, 2, 15);
    setMaxEdgeCapacity(G, 1, 3, 5);
    setMaxEdgeCapacity(G, 1, 4, 5);
    setMaxEdgeCapacity(G, 2, 3, 5);
    setMaxEdgeCapacity(G, 2, 4, 5);
    setMaxEdgeCapacity(G, 3, 5, 15);
    setMaxEdgeCapacity(G, 4, 5, 5);
    
    flow = Ford_Fulkerson(G, 0,5);
    
    
    
    printf("Flow = %d", flow);
    


    
    return 0;
}

