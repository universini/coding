#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node *next;
};

// struct node *create_node(int v);

struct graph_node {
  int num_vertices;
  int *is_visited;
  struct node **adj_list; // node** *to store an array of Linked lists
};

void dfs(struct graph_node *graph, int vertex) {
  struct node *adj_list = graph->adj_list[vertex];
  struct node *temp = adj_list;

  graph->is_visited[vertex] = 1;
  printf("visited %d\n", vertex);

  while (temp != NULL) {
    int connected_vertex = temp->vertex;

    if (graph->is_visited[connected_vertex] == 0) {
      dfs(graph, connected_vertex);
    }
    temp = temp->next;
  }
}

struct node *create_node(int v) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

struct graph_node *create_graph(int vertices) {
  struct graph_node *graph = malloc(sizeof(struct graph_node));

  graph->num_vertices = vertices;
  graph->adj_list = malloc(vertices * sizeof(struct node*));
  graph->is_visited = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++) {
    graph->adj_list[i] = NULL;
    graph->is_visited[i] = 0;
  }

  return graph;
}

void add_edge(struct graph_node *graph, int src, int dest) {
  // Add edge from src to dest
  struct node *new_node = create_node(dest);
  new_node->next = graph->adj_list[src];
  graph->adj_list[src] = new_node;

  // Add edge from dest to src
  new_node = create_node(src);
  new_node->next = graph->adj_list[dest];
  graph->adj_list[dest] = new_node;
}

void print_graph(struct graph_node *graph) {
  int v;
  for (v = 0; v < graph->num_vertices; v++) {
    struct node *temp = graph->adj_list[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct graph_node *graph = create_graph(4);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);

  print_graph(graph);

  dfs(graph, 2);

  return 0;
}
