#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * Breadth-First Search (BFS) is a graph traversal algorithm that starts
 * at a specific vertex (often called the "source") and explores the
 * neighbor vertices at the present depth prior to moving on to vertices
 * at the next depth level.
 */
void bfs(vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";  // Process the vertex (in this case, print it)

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented using an adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};
    int startVertex = 0;  // Starting vertex for BFS

    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    cout << "BFS Traversal starting from vertex " << startVertex << ":\n";
    bfs(graph, startVertex, visited);

    return 0;
}
