#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list representation

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void printList()
    {
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << ":";
            for (int v : adjList[i])
            {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int>q;
        unordered_map<int,int> distance;
        unordered_map<int,int> lastConnection;

        visited[startVertex] = true;
        distance[startVertex] = 0;
        lastConnection[startVertex] = startVertex;
        q.push(startVertex);

        while(!q.empty()){
            int u = q.front();
            cout<< u << " ";
            q.pop();

            for(int v : adjList[u]){
                if(!visited[v]){
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    lastConnection[v] = u;
                    q.push(v);
                }
            }
        }

        cout << "\nDistance from " << startVertex << " to each vertex:" << endl;
        for (const auto& pair : distance) {
            cout << pair.first << ": " << pair.second << endl;
        }

        cout << "\nLast connection for each vertex:" << endl;
        for (const auto& pair : lastConnection) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS traversal starting from vertex 0:" << endl;
    g.BFS(0); // Start BFS traversal from vertex 0

    return 0;
}




