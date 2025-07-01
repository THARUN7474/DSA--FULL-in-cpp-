#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mp = 0;
        int buy = prices[0];
        for (int i = 1; i < n; i++)
        {
            if (prices[i] - buy > mp)
            {
                mp = prices[i] - buy;
            }
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
        }
        return mp;
    }
};