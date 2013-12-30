//
//  GraphTraversalAlgorithms.h
//  GraphLibrary
//
//  Created by Abhishek Sen on 12/24/13.
//  Copyright (c) 2013 Abhishek Sen. All rights reserved.
//

#ifndef GraphLibrary_GraphTraversalAlgorithms_h
#define GraphLibrary_GraphTraversalAlgorithms_h
#include "AdjList.h"



GraphPath* init_path();

GraphPath* DFS_Traversal(Graph, int, int*, int, GraphPath*);

GraphPath* getPath(Graph, int, int);

#endif
