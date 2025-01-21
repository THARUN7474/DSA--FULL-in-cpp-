Here's the equivalent implementation of the logic shown in the image in **C++**, designed to find connected components in a graph:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Global variables
int n; // Number of nodes in the graph
vector<vector<int>> graph; // Adjacency list representing the graph
vector<bool> visited; // Visited array
vector<int> components; // Component number for each node
int count = 0; // Component count

// DFS function to traverse a component
void dfs(int node) {
    visited[node] = true;
    components[node] = count;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Function to find all connected components
pair<int, vector<int>> findComponents() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            count++;
            dfs(i);
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

    // Resize graph and initialize variables
    graph.resize(n);
    visited.resize(n, false);
    components.resize(n, 0);

    // Input: edges of the graph
    cout << "Enter the edges (u v format, 0-indexed):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
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
```

### Explanation:
1. **Global Variables**:
   - `graph`: Adjacency list to store the graph.
   - `visited`: Boolean vector to track visited nodes.
   - `components`: Stores the component number for each node.

2. **DFS Function**:
   - Recursively visits all nodes in the same connected component starting from a given node.
   - Marks nodes as visited and assigns them to the current component.

3. **findComponents Function**:
   - Iterates over all nodes in the graph.
   - If a node is not visited, it starts a new DFS, marking a new component.

4. **Input/Output**:
   - The program reads the number of nodes, edges, and edge connections.
   - Outputs the total number of connected components and the component each node belongs to.

---

### Example Input/Output:

#### Input:
```
Enter the number of nodes: 6
Enter the number of edges: 4
Enter the edges (u v format, 0-indexed):
0 1
1 2
3 4
4 5
```

#### Output:
```
Number of connected components: 2
Node to component mapping:
Node 0 belongs to component 1
Node 1 belongs to component 1
Node 2 belongs to component 1
Node 3 belongs to component 2
Node 4 belongs to component 2
Node 5 belongs to component 2
```

Let me know if you need additional features or modifications!