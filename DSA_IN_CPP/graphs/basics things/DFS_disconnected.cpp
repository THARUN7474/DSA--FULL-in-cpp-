#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " "; // Process vertex (print or store)

        for (int u : adjList[v])
        {
            if (!visited[u])
            {
                DFSUtil(u, visited);
            }
        }
    }

    void DFSDisconnected()
    {
        vector<bool> visited(V, false); // Mark all vertices as not visited

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }
};

int main()
{
    Graph g(7); // Create a graph with 7 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 6); // Disconnected component

    cout << "DFS traversal for disconnected graph:" << endl;
    g.DFSDisconnected(); // Start DFS traversal for disconnected graph

    return 0;
}






