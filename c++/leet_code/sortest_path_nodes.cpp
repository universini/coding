#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits>

const int INF = std::numeric_limits<int>::max() / 2;

int shortestPathLength(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, INF));
    std::queue<std::pair<int, int>> q; // Node, state (visited nodes)

    for (int i = 0; i < n; ++i) {
        dp[i][1 << i] = 0;
        q.push({i, 1 << i});
    }

    while (!q.empty()) {
        auto [node, state] = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            int nextState = state | (1 << neighbor);
            if (dp[neighbor][nextState] > dp[node][state] + 1) {
                dp[neighbor][nextState] = dp[node][state] + 1;
                q.push({neighbor, nextState});
            }
        }
    }

    int minPathLength = INF;
    for (int i = 0; i < n; ++i) {
        minPathLength = std::min(minPathLength, dp[i][(1 << n) - 1]);
    }

    return minPathLength - 1; // Subtract 1 as we want the edge count, not the node count
}

int main() {
    std::vector<std::vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
    int shortestPath = shortestPathLength(graph);
    std::cout << "Shortest path length visiting all nodes: " << shortestPath << std::endl;

    return 0;
}
