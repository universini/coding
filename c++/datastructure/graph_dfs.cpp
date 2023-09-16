#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * Depth-First Search (DFS) is a graph traversal algorithm that starts
 * at a specific vertex (often called the "source") and explores as far
 * as possible along each branch before backtracking.
 */
void dfs(vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
    stack<int> stk;
    stk.push(startVertex);
    visited[startVertex] = true;

    while (!stk.empty()) {
        int currentVertex = stk.top();
        stk.pop();
        cout << currentVertex << " ";  // Process the vertex (in this case, print it)

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stk.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented using an adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};
    int startVertex = 0;  // Starting vertex for DFS

    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    cout << "DFS Traversal starting from vertex " << startVertex << ":\n";
    dfs(graph, startVertex, visited);

    return 0;
}
