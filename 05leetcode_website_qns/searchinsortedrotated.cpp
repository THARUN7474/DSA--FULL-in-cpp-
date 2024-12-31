#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            if (nums[s] <= nums[m])
            {
                if (nums[s] <= target && target < nums[m])
                {
                    // s = m + 1;
                    e = m - 1;
                }
                else
                {
                    // e = m - 1;
                    s = m + 1;
                }
            }
            else
            {
                if (nums[m] < target && target <= nums[e])
                {
                    // e = m - 1;
                    s = m + 1;
                }
                else
                {
                    // s = m + 1;
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};