#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Function to find the shortest path in a binary matrix
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    // If the start or end is blocked, there's no valid path
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
    {
        return -1;
    }

    // Define the 8 possible directions
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // Up, Down, Left, Right
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1} // Diagonals
    };

    // BFS setup
    queue<pair<int, int>> q;                                 // Queue to store (row, col)
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // Visited matrix
    q.push({0, 0});                                          // Start BFS from the top-left corner
    visited[0][0] = true;

    int pathLength = 1; // Initial path length (starting at (0,0))

    // BFS loop
    while (!q.empty())
    {
        int size = q.size(); // Number of nodes at the current level

        for (int i = 0; i < size; ++i)
        {
            auto [x, y] = q.front(); // Current node
            q.pop();

            // If we reach the bottom-right cell, return the path length
            if (x == n - 1 && y == n - 1)
            {
                return pathLength;
            }

            // Explore all 8 directions
            for (auto &[dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;

                // Check if the new cell is within bounds, walkable, and unvisited
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true; // Mark as visited
                }
            }
        }

        pathLength++; // Increment path length after processing all nodes at the current level
    }

    // If no path is found, return -1
    return -1;
}

int main()
{
    // Example input
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};

    // Find and output the shortest path
    int result = shortestPathBinaryMatrix(grid);
    cout << "Shortest Path Length: " << result << endl;

    return 0;
}
