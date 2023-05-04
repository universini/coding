#include <iostream>
#include <list>
using namespace std;

class G_Node {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

 public:
  G_Node(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
G_Node::G_Node(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void G_Node::addEdge(int src, int dest)
{
  adjLists[src].push_front(dest);
}

// DFS algorithm
void G_Node::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i]) DFS(*i);
}

int main() {
  G_Node g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(2);

  return 0;
}
