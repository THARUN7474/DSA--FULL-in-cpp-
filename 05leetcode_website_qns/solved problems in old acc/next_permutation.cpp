#include <bits/stdc++.h>

using namespace std;

// next_permutation(nums.begin(), nums.end());

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int p = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                p = i;
                break;
            }
        }
        if (p == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = n - 1; i > p; i--)
            {
                if (nums[i] > nums[p])
                {
                    swap(nums[i], nums[p]);
                    break;
                }
            }

            reverse(nums.begin() + p + 1, nums.end());
        }
    }
};