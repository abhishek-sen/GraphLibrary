//
//  FlowGraphHelpers.h
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/20/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#ifndef GraphLibrary_FlowGraphHelpers_h
#define GraphLibrary_FlowGraphHelpers_h

#include "AdjList.h"

int setSource(Graph, int);

int setSink(Graph, int);

int setMaxEdgeCapacity(Graph, int, int);

int setMaxNodeCapacity(Graph, int, int);

int setEdgeCapacity(Graph, int, int);

int setNodeCapacity(Graph, int, int);

int setEdgeFlow(Graph, int, int, int);

int incrementEdgeFlow(Graph, int, int);

#endif
