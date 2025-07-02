#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ms = INT_MIN;
        int cs = 0;
        for (int i : nums)
        {
            cs = max(i, cs + i);
            ms = max(ms, cs);
        }
        return ms;
    }
};