#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int numHops(unordered_map<string, vector<string>>& adjList, string v1, string v2);

int main() {
    unordered_map<string, vector<string>> adjList{
        {"A", {"C", "E"}},
        {"C", {"A", "I"}},
        {"I", {"C", "H", "B", "D"}},
        {"H", {"I"}},
        {"D", {"I", "B", "G"}},
        {"B", {"E", "F", "G", "D", "I"}},
        {"G", {"B", "D"}},
        {"F", {"B"}},
        {"E", {"A", "B"}}
    };

    cout << "Number of hops between cities D and A is " << numHops(adjList, "D", "A") << endl; // Should be 3
    cout << "Number of hops between cities A and B is " << numHops(adjList, "A", "B") << endl; // Should be 2
    cout << "Number of hops between cities H and E is " << numHops(adjList, "H", "E") << endl; // Should be 3

    return 0;
}

// Returns the number of hops between vertices v1 and v2
int numHops(unordered_map<string, vector<string>>& adjList, string v1, string v2) {
    if (v1 == v2) {
        return 0; // Same city, no hops needed
    }

    // Using BFS to find the shortest path
    queue<string> q;
    unordered_map<string, bool> visited;

    q.push(v1);
    visited[v1] = true;

    int hops = 0;

    while (!q.empty()) {
        int size = q.size();
        hops++;

        for (int i = 0; i < size; i++) {
            string current = q.front();
            q.pop();

            for (const string& neighbor : adjList[current]) {
                if (neighbor == v2) {
                    return hops; // Found the destination city
                }

                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    return -1; // Cities are not connected in the graph
}
