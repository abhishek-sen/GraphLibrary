//
//  main.c
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/19/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#include <stdio.h>
#include "AdjList.h"


int main(int argc, const char * argv[])
{

    Graph G;

    G = initGraph(G, 10);
    printGraph(G);
    
    insertEdge(G,0,1);
    insertEdge(G,2,1);
    insertEdge(G,0,3);
    insertEdge(G,3,1);
    
    printGraph(G);
    
    int* buf = (int*)malloc(10*sizeof(int));
    for (int i = 0;i<10; i++)
        buf[i] = -1;
    
    buf = getNeighbours(G, 0, buf);
    
    printf("\n \n \n \n");
    for (int i = 0;i<10; i++)
        printf("%d \n", buf[i]);
    
    deleteEdge(G,0,1);
    
    printGraph(G);
    
    return 0;
}

