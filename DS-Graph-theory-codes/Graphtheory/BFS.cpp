#include <bits/stdc++.h>

using namespace std;

int main() {
    // Number of nodes and edges
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Adjacency list to store the graph
    vector<int> adj[n + 1];

    // Reading edges and constructing the adjacency list
    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add v to the list of neighbors of u
        adj[v].push_back(u); // Add u to the list of neighbors of v (since the graph is undirected)
    }

    // Visited array to keep track of visited nodes
    vector<bool> vis(n + 1, false);

    // Queue for BFS
    queue<int> q;

    // Start BFS from node 1
    cout << "BFS starting from node 1:" << endl;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Print the current node

        for (auto it : adj[node]) { // Iterate over all neighbors of the current node
            if (!vis[it]) { // If the neighbor has not been visited
                q.push(it); // Add the neighbor to the queue
                vis[it] = true; // Mark the neighbor as visited
            }
        }
    }

    return 0;
}


// Enter the number of nodes and edges: 5 4
// Enter the edges (u v) one by one:
// 1 2
// 1 3
// 2 4
// 3 5
// BFS starting from node 1:
// 1 2 3 4 5