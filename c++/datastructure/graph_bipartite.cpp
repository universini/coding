#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(int node, int color, const vector<vector<int>>& graph, vector<int>& colorMap) {
    if (colorMap[node] != -1) {
        return colorMap[node] == color;
    }

    colorMap[node] = color;

    for (int neighbor : graph[node]) {
        if (!dfs(neighbor, 1 - color, graph, colorMap)) {
            return false;
        }
    }

    return true;
}

bool isBipartite(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colorMap(n, -1);

    for (int i = 0; i < n; ++i) {
        if (colorMap[i] == -1 && !dfs(i, 0, graph, colorMap)) {
            return false;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "color: " << colorMap[i] << endl;
    }

    return true;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    if (isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
