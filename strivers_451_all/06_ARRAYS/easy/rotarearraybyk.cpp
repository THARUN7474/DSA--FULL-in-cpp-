#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate1(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    void rotate(vector<int> &nums, int k)
    {
        vector<int> arr(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int n = (i + k) % nums.size();
            arr[n] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = arr[i];
        }
    }
};
