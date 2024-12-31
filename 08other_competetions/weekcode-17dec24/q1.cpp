#include <bits/stdc++.h>
using namespace std;

int min_jumps(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0; // No jump needed for a single element

    unordered_map<int, vector<int>> value_map; // Map value -> list of indices with this value
    for (int i = 0; i < n; ++i)
    {
        value_map[arr[i]].push_back(i);
    }

    vector<bool> visited(n, false); // Mark visited indices
    queue<pair<int, int>> q;        // Queue: (index, steps)
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty())
    {
        auto temp = q.front();
        int idx = temp.first;
        int steps = temp.second;
        q.pop();

        // If we reach the last index, return the steps
        if (idx == n - 1)
            return steps;

        // Explore neighbors: left, right, and same-value indices
        vector<int> next_indices;

        // Add left and right neighbors
        if (idx - 1 >= 0)
            next_indices.push_back(idx - 1);
        if (idx + 1 < n)
            next_indices.push_back(idx + 1);

        // Add all indices with the same value
        next_indices.insert(next_indices.end(), value_map[arr[idx]].begin(), value_map[arr[idx]].end());

        // Clear the list of same-value jumps to avoid revisiting
        value_map[arr[idx]].clear();

        // Visit all possible next indices
        for (int next : next_indices)
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }
    }

    return -1; // This case won't happen as we assume it's always possible to reach the last index
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << min_jumps(arr) << endl;

    return 0;
}
