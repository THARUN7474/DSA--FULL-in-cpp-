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

    // Lambda function for DFS
    function<void(int)> dfs = [&](int node) {
        vis[node] = true; // Mark the current node as visited
        cout << node << " "; // Print the current node
        for (auto it : adj[node]) { // Iterate over all neighbors of the current node
            if (!vis[it]) { // If the neighbor has not been visited
                dfs(it); // Recursively perform DFS on the neighbor
            }
        }
    };

    // Start DFS from node 1
    cout << "DFS starting from node 1:" << endl;
    dfs(1);

    return 0;
}

// Enter the number of nodes and edges: 5 4
// Enter the edges (u v) one by one:
// 1 2
// 1 3
// 2 4
// 3 5
// DFS starting from node 1:
// 1 2 4 3 5




// int n = 3;
// vector<int> adj[n+1];

// // Adding edges
// adj[1].push_back(2);
// adj[1].push_back(3);
// adj[2].push_back(1);
// adj[2].push_back(3);
// adj[3].push_back(1);
// adj[3].push_back(2);

// // Printing adjacency list
// for(int i = 1; i <= n; i++) {
//     cout << "Node " << i << ": ";
//     for(int neighbor : adj[i]) {
//         cout << neighbor << " ";
//     }
//     cout << endl;
// }