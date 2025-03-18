#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct {
  char nome[20];
  int idade;
} Pessoa;

void print(Graph *g) {
  Vertex *v;
  Edge *e;
  
  Pessoa *p, *q;
  
  if (g) {
    v = g->first;
    while (v) {
      p = v->value;
      
      printf("[%s]->", p->nome);
      
      e = v->first;
      while (e) {
        q = e->head->value;
        
        printf("(%s)->", q->nome);
        e = e->next;
      }
      printf("\n");
      
      v = v->next;
    }
  }
}

int contarSeguidos(Graph *g, char *nome) {
  Vertex *v;
  Pessoa *p;
  
  v = g->first;
  while (v) {
    p = v->value;
    
    if (strcmp(p->nome, nome) == 0) 
      return v->n;
    
    v = v->next;
  }
  
  return 0;
}

int cmp(void *a, void *b) {
  Pessoa *p1 = a;
  Pessoa *p2 = b;
  return strcmp(p1->nome, p2->nome);
}

int main() {
  Graph *g = Graph_alloc();
  
  Pessoa p[9] = {
    {"joao",25},   
    {"ana",23},
    {"caio",20},
    {"pedro",20},
    {"jane",30},
    {"marcos",19},
    {"bruna",23},
    {"felipe",20},
    {"renata",35}
  };
  
  for (int i=0; i<9; i++) 
    Graph_insertVertex(g, i, &p[i]);
  
  Graph_insertEdge(g, 0, 1);
  Graph_insertEdge(g, 0, 2);
  Graph_insertEdge(g, 0, 3);
  Graph_insertEdge(g, 1, 0);
  Graph_insertEdge(g, 1, 4);
  Graph_insertEdge(g, 3, 2);
  Graph_insertEdge(g, 3, 4);
  Graph_insertEdge(g, 3, 5);
  Graph_insertEdge(g, 3, 6);
  Graph_insertEdge(g, 4, 3);
  Graph_insertEdge(g, 4, 5);
  Graph_insertEdge(g, 4, 6);
  Graph_insertEdge(g, 5, 7);
  Graph_insertEdge(g, 5, 8);
  Graph_insertEdge(g, 6, 8);
  Graph_insertEdge(g, 7, 5);
  Graph_insertEdge(g, 7, 8);
  
  print(g); 
  
  char nome[20] = "ana";
  Vertex **path = Graph_dfs(g, nome, cmp);
  //Vertex **path = Graph_bfs(g, nome, cmp);
  Pessoa *pss;
  
  for (int i=0; i<g->n; i++) {
    if (path[i]) {
      pss = path[i]->value;
      printf("[%s]", pss->nome);
    }
    else
      break;
  }
  printf("\n");
  
  return 0;
}






