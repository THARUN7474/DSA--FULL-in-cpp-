#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            vis[arr[i]] = true;
        }
        for (int i = 0; i <= n; i++)
        {
            if (!vis[i])
            {
                return i;
            }
        }
        return -1;
    }
};