#include <iostream>
#include <vector>
#include <list>

using namespace std;

class GraphList
{
private:
    int V; // Number of vertices
    vector<list<int>> adjList;
    // vector<vector<pair<int,int>>> adjlist;//for wighted graph

public:
    GraphList(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
        // adjList[u].push_back(v);//only this specific direction for directed graph
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
};

int main()
{
    GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List:" << endl;
    g.printList();

    return 0;
}
