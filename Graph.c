#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"

Graph *Graph_alloc() {
  Graph *g = malloc(sizeof(Graph));
  
  if (g) {
    g->n = 0;
    g->first = NULL;
    g->last = NULL;
  }
  
  return g;
}

void Graph_insertVertex(Graph *g, int label, void *value) {
  Vertex *new = NULL;
  
  if (g) {
    new = malloc(sizeof(Vertex));
    new->first = NULL;
    new->label = label;
    new->value = value;
    new->next = NULL;
    new->visited = 0;
    new->n = 0;
    
    if (g->n == 0)
      g->first = new;
    else 
      g->last->next = new; 
    
    g->last = new; 
    
    g->n++;
  }
}

void Graph_print(Graph *g) {
  Vertex *v;
  Edge *e;
  if (g) {
    v = g->first;
    while (v) {
      printf("[%d]->", v->label);
      
      e = v->first;
      while (e) {
        printf("(%d)->", e->head->label);
        e = e->next;
      }
      printf("\n");
      
      v = v->next;
    }
  }
}

void Graph_insertEdge(Graph *g, int tail, int head) {
  Edge *e, *new;
  Vertex *vTail, *vHead;
  if (g) {
    e = Graph_findEdge(g, head, tail);
    
    if (e == NULL) {
      vTail = Graph_findVertex(g, tail);
      vHead = Graph_findVertex(g, head);
      
      new = malloc(sizeof(Edge));
      new->head = vHead;
      new->tail = vTail;
      new->value = 0.0;
      new->label = 0;
      new->next = NULL;
      
      if (vTail->n == 0)
        vTail->first = new;
      else 
        vTail->last->next = new; 
      
      vTail->last = new;
      
      vTail->n++;
    }
  }
}

Vertex *Graph_findVertex(Graph *g, int label) {
  Vertex *v;
  if (g) {
    v = g->first;
    while (v) {
      if (v->label == label)
        return v;
      v = v->next;
    }
  }
  
  return NULL;
}

Edge *Graph_findEdge(Graph *g, int tail, int head) {
  Vertex *vHead, *vTail;
  Edge *e;
  if (g) {
    vHead = Graph_findVertex(g, head);
    vTail = Graph_findVertex(g, tail);
    
    e = vTail->first;
    while(e) {
      if (e->head->label == head)
        return e;
      e = e->next;
    }
  }
  
  return NULL;
}

Vertex *notVisited(Edge *e) {
	
	while(e) {
	  if (e->head->visited == 0)
		return e->head;
	  e = e->next;
	}
  
	return NULL;
}

Vertex * Graph_findVertexByValue(Graph *g, void *value, int (*cmp)(void*,void*)) {
	 Vertex *v;
	  if (g) {
		v = g->first;
		while (v) {
		  if (cmp(v->value, value) == 0)
			return v;
		  v = v->next;
		}
	  }
	  
	  return NULL;
}

Vertex **Graph_bfs(Graph *g, void *startValue, int (*cmp)(void*,void*)) {
	Vertex **path = NULL;
	Vertex *v = NULL, *k = NULL;
	Queue  *q = NULL;
	int count = 0;
	
	if (g && startValue) {
		if ((v = Graph_findVertexByValue(g, startValue, cmp))) {
	
			path = calloc(g->n, sizeof(Vertex*));
			q = Queue_alloc(g->n);
	
			v->visited = 1;
			path[count++] = v;
	
			Queue_push(q, v);
			
			while (!Queue_isEmpty(q)) {
				v = Queue_begin(q);
	
				while ((k = notVisited(v->first)) != NULL) {
					k->visited = 1;
					path[count++] = k;
					Queue_push(q, k);
				}
	
				Queue_pop(q);
			}
		}
	}
	
	return path;
}

void dfs(Vertex *v, Vertex **path, int *count) {
	Vertex *k = NULL;

	if (v) {
		v->visited = 1;
		path[*count] = v;
		
		while ((k = notVisited(v->first)) != NULL) {
			*count += 1;
			dfs(k, path, count);
		}
	}
}

Vertex **Graph_dfs(Graph *g, void *startValue, int (*cmp)(void*,void*)) {
	Vertex **path = NULL, *v = NULL;
	int i, count = 0;

	if (g && startValue) {
		v = Graph_findVertexByValue(g, startValue, cmp);
		
		if (v) {
			path = calloc(g->n, sizeof(Vertex*));	
			dfs(v, path, &count);
		}
	}
	
	return path;
}

