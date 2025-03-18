typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Edge {
  Vertex *head, *tail;
  int value;
  int label;
  Edge *next;
};

struct Vertex {
  Edge *first, *last;
  int label;
  void *value;
  Vertex *next;
  int visited;
  int n;
};

struct Graph {
  Vertex *first, *last;
  int n;
};

Graph  *Graph_alloc();
void    Graph_free(Graph *g);

void    Graph_insertVertex(Graph *g, int label, void *value);
void    Graph_insertEdge(Graph *g, int head, int tail, int value);

Vertex *Graph_removeVertex(Graph *g, int label);
Edge   *Graph_removeEdge(Graph *g, int head, int tail);

Edge   *Graph_findEdge(Graph *g, int head, int tail);
Vertex *Graph_findVertex(Graph *g, int label);

void    Graph_print(Graph *g);

Vertex **Graph_bfs(Graph *g, void *startValue, int (*cmp)(void*,void*));
Vertex **Graph_dfs(Graph *g, void *startValue, int (*cmp)(void*,void*));
