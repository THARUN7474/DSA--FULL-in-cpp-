#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
{
    if (visited[u] == true)
    {
        return;
    }

    visited[u] = true;
    result.push_back(u);
    for (int &v : adj[u])
    {
        if (!visited[v])
        {
            dfs(adj, v, visited, result); // indirect usage of stack --by using recursion
        }
    }
}

vector<int> dfs_caller(int v, vector<int> mp[])
{
    unordered_map<int, vector<int>> ADJ;
    for (int i = 0; i < v; i++)
    {
        // for(int j=0;j<mp[i].size();j++){
        //     ADJ[i].push_back(mp[i][j]);
        // }

        for (auto it = mp[i].begin(); it != mp[i].end(); it++)
        {
            ADJ[i].push_back(*it);
        }
    }

    vector<bool> visited(v, false);
    vector<int> result;
    dfs(ADJ, v, visited, result);
    return result;
}