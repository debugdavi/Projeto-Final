#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {
  Graph *g = Graph_alloc();
  
  Graph_insertVertex(g, 1, NULL);
  Graph_insertVertex(g, 2, NULL);
  Graph_insertVertex(g, 3, NULL);
  Graph_insertVertex(g, 4, NULL);
  
  Graph_insertEdge(g, 1, 2);
  Graph_insertEdge(g, 1, 3);
  Graph_insertEdge(g, 2, 3);
  Graph_insertEdge(g, 2, 4);
  Graph_insertEdge(g, 3, 4);
  
  Graph_print(g); 
  return 0;
}
