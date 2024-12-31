#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    enum Color { WHITE, GRAY, BLACK };

    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS(int startVertex) {
        vector<Color> colors(V, WHITE); // Initialize all vertices with WHITE color
        stack<int> s; // Stack for DFS
        s.push(startVertex);

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (colors[u] == WHITE) {
                colors[u] = GRAY;
                cout << u << " "; // Process vertex (print or store)

                // Push all adjacent vertices of u that are not visited into the stack
                for (int v : adjList[u]) {
                    if (colors[v] == WHITE) {
                        s.push(v);
                    }
                }

                colors[u] = BLACK;
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "DFS traversal starting from vertex 0:" << endl;
    g.DFS(0); // Start DFS traversal from vertex 0

    return 0;
}




// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_set>

// using namespace std;

// class Graph {
// private:
//     int V; // Number of vertices
//     vector<vector<int>> adjList;

// public:
//     Graph(int vertices) : V(vertices) {
//         adjList.resize(V);
//     }

//     void addEdge(int u, int v) {
//         adjList[u].push_back(v);
//     }

//     void DFS(int startVertex) {
//         vector<bool> visited(V, false); // Mark all vertices as not visited
//         stack<int> s; // Create a stack for DFS
//         unordered_set<int> visitedSet; // To store visited vertices in order

//         s.push(startVertex);

//         while (!s.empty()) {
//             int u = s.top();
//             s.pop();

//             if (!visited[u]) {
//                 visited[u] = true;
//                 visitedSet.insert(u); // Store visited vertex
//                 cout << u << " "; // Process vertex (print or store)

//                 // Push all adjacent vertices of u that are not visited into the stack
//                 for (int v : adjList[u]) {
//                     if (!visited[v]) {
//                         s.push(v);
//                     }
//                 }
//             }
//         }

//         cout << endl << "Visited vertices in order: ";
//         for (int vertex : visitedSet) {
//             cout << vertex << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Graph g(7); // Create a graph with 7 vertices

//     // Add edges to the graph
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);
//     g.addEdge(2, 5);
//     g.addEdge(2, 6);

//     cout << "DFS traversal starting from vertex 0:" << endl;
//     g.DFS(0); // Start DFS traversal from vertex 0

//     return 0;
// }
