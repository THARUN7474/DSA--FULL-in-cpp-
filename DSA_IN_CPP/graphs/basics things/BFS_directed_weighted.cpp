#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Graph
{
private:
    int V;                                  // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list representation with weight

public:
    Graph(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back({v, weight});
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(V, false);     // Mark all vertices as not visited
        queue<int> q;                       // Create a queue for BFS
        unordered_map<int, int> lastParent; // To store the last parent vertex for each vertex
        unordered_map<int, int> distance;   // To store distance of each vertex from startVertex

        visited[startVertex] = true; // Mark the current node as visited and enqueue it
        q.push(startVertex);
        distance[startVertex] = 0; // Distance of startVertex from itself is 0

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // Get all adjacent vertices and their weights of the dequeued vertex u
            for (const auto &neighbor : adjList[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    lastParent[v] = u;                  // Update last parent vertex
                    distance[v] = distance[u] + weight; // Update distance from startVertex
                }
            }
        }

        cout << "Vertex\tLast Parent\tDistance from Source" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << i << "\t" << (lastParent[i] == 0 ? "None" : to_string(lastParent[i])) << "\t\t"
                 << (visited[i] ? to_string(distance[i]) : "Infinity") << endl;
        }
    }
};

int main()
{
    Graph g(5); // Create a graph with 5 vertices

    // Add edges to the graph with weights
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 1);

    cout << "BFS traversal with last parent and distance from source starting from vertex 0:" << endl;
    g.BFS(0); // Start BFS traversal from vertex 0

    return 0;
}





// // Inside the Graph class definition:

// void BFS(int startVertex, vector<bool>& visited) {
//     queue<int> q; // Create a queue for BFS
//     unordered_map<int, int> lastParent; // To store the last parent vertex for each vertex
//     unordered_map<int, int> distance; // To store distance of each vertex from startVertex

//     visited[startVertex] = true; // Mark the current node as visited and enqueue it
//     q.push(startVertex);
//     distance[startVertex] = 0; // Distance of startVertex from itself is 0

//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         // Get all adjacent vertices and their weights of the dequeued vertex u
//         for (const auto& neighbor : adjList[u]) {
//             int v = neighbor.first;

//             if (!visited[v]) {
//                 visited[v] = true;
//                 q.push(v);
//                 lastParent[v] = u; // Update last parent vertex
//                 distance[v] = distance[u] + neighbor.second; // Update distance from startVertex
//             }
//         }
//     }

//     // You can print or process the results here
// }

// void BFSDisconnected() {
//     vector<bool> visited(V, false); // Mark all vertices as not visited

//     for (int i = 0; i < V; ++i) {
//         if (!visited[i]) {
//             BFS(i, visited); // Start BFS from unvisited vertex with shared visited vector
//         }
//     }
// }
