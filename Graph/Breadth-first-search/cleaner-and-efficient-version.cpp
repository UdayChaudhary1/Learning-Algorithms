#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& traversalOrder, vector<bool>& visited) {
    queue<int> q;
    q.push(0);            // Start BFS from node 0
    visited[0] = true;     // Mark node 0 as visited

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        traversalOrder.push_back(top);

        for (int neighbor : graph[top]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void print(const vector<char>& nodes, const vector<int>& traversalOrder) {
    for (int index : traversalOrder) {
        cout << nodes[index] << endl;  // Print corresponding character for each index in traversal order
    }
}

int main() {
    vector<vector<int>> graph(5);        // Initialize graph with 5 nodes
    vector<char> nodes;                  // Alphabet array
    vector<int> traversalOrder;          // BFS traversal order
    vector<bool> visited(5, false);      // Visited array for 5 nodes

    // Fill nodes with 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c) {
        nodes.push_back(c);
    }

    // Define graph adjacency list
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {};
    graph[3] = {4};
    graph[4] = {};

    // Perform BFS
    bfs(graph, traversalOrder, visited);

    // Print corresponding nodes
    print(nodes, traversalOrder);

    return 0;
}

// The keyword const is used to indicate that a variable, function argument, or object should not be modified. In C++, it's a good practice to use const when you want to make sure that certain data won't be accidentally changed.