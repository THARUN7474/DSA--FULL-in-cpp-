#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int s = 0;
        int m = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // cout<<"start"<<"ss"<<s<<"mm"<<m<<endl;
            if (nums[i] == 1)
            {
                s++;
            }
            else
            {
                m = max(m, s);
                s = 0;
            }
            // cout<<"end"<<"ss"<<s<<"mm"<<m<<endl;
        }
        m = max(m, s);
        return m;
    }
};