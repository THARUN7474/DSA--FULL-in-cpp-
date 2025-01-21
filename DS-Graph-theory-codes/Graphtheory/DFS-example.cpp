#include <iostream>
#include <vector>
using namespace std;

// Global variables
int n; // Number of nodes in the graph
vector<vector<int>> g; // Adjacency list representing the graph
vector<bool> visited; // Visited array
vector<int> components; // Component number for each node
int count = 0; // Component count

// DFS function to explore nodes in a single connected component
void dfs(int at) {
    visited[at] = true; // Mark the node as visited
    components[at] = count; // Assign the current component number

    // Visit all neighbors of the current node
    for (int next : g[at]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

// Function to find all connected components in the graph
pair<int, vector<int>> findComponents() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // If node is not visited
            count++; // Start a new component
            dfs(i);  // Perform DFS for the component
        }
    }
    return {count, components};
}

int main() {
    // Input: number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    int edges;
    cin >> edges;

    // Resize graph and initialize global variables
    g.resize(n);
    visited.resize(n, false);
    components.resize(n, 0);

    // Input: edges of the graph
    cout << "Enter the edges (u v format, 0-indexed):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // For undirected graph
    }

    // Find connected components
    auto result = findComponents();

    // Output the number of components
    cout << "Number of connected components: " << result.first << endl;

    // Output the component of each node
    cout << "Node to component mapping:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << " belongs to component " << components[i] << endl;
    }

    return 0;
}



// Enter the number of nodes: 6
// Enter the number of edges: 4
// Enter the edges (u v format, 0-indexed):
// 0 1
// 1 2
// 3 4
// 4 5


// Number of connected components: 2
// Node to component mapping:
// Node 0 belongs to component 1
// Node 1 belongs to component 1
// Node 2 belongs to component 1
// Node 3 belongs to component 2
// Node 4 belongs to component 2
// Node 5 belongs to component 2
