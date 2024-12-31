#include <bits/stdc++.h>

using namespace std;

void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    result.push_back(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                result.push_back(v);
            }
        }
    }
}

vector<int> bfs_caller(int v, vector<int> mp[])
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
    bfs(ADJ, v, visited, result);
    return result;
}