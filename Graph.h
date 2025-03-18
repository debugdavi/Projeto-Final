typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Edge {
  Vertex *head, *tail;
  float value;
  int label;
  Edge *next;
};

struct Vertex {
  Edge *first;
  int label;
  void *value;
  Vertex *next;
};

struct Graph {
  Vertex *first;
  int n;
};

Graph  *Graph_alloc();
void    Graph_free(Graph *g);

void    Graph_insertVertex(Graph *g, int label, void *value);
void    Graph_insertEdge(Graph *g, int head, int tail);

Vertex *Graph_removeVertex(Graph *g, int label);
Edge   *Graph_removeEdge(Graph *g, int head, int tail);

Edge   *Graph_findEdge(Graph *g, int head, int tail);
Vertex *Graph_findVertex(Graph *g, int label);

void    Graph_print(Graph *g);



