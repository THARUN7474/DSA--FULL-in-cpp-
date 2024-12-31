#include <iostream>
#include <vector>

using namespace std;

class GraphMatrix {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;
    // vector<vector<pair<int,int>>> adjMatrix;//for weighted gprah and while add add weight too 

public:
    GraphMatrix(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
        //only one way for directed grpah
    }

    void printMatrix() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    g.printMatrix();

    return 0;
}
