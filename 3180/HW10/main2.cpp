#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, const vector<vector<int>>& edges, int source, int destination) {
        // Build an adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Initialize the visited array
        vector<bool> visited(n, false);

        // Start DFS from the source
        return dfs(source, destination, graph, visited);
    }

private:
    bool dfs(int node, int destination, const vector<vector<int>>& graph, vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = true;

        // Check if the destination is reached
        if (node == destination) {
            return true;
        }

        // Explore neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, graph, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    cout << boolalpha << solution.validPath(3, {{0,1},{1,2},{2,0}}, 0, 2) << endl;  // Output: true
    cout << boolalpha << solution.validPath(6, {{0,1},{0,2},{3,5},{5,4},{4,3}}, 0, 5) << endl;  // Output: false

    return 0;
}
