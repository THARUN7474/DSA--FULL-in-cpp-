#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> v;
        int j = 0;
        for (int i : nums)
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                v.emplace_back(i);
            }
        }
        // cout << "j" << j << endl;

        while (j != 0)
        {
            v.push_back(0);
            j--;
        }
        for (int i = 0; i < v.size(); i++)
        {
            nums[i] = v[i];
            // cout << v[i] << endl;
        }
    }
};

// snowball method
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                s++;
            }
            else if (s > 0)
            {
                int t = nums[i];
                nums[i] = 0;
                nums[i - s] = t;
            }
        }
    }
};

// 2 pointer methods using that 1 for left side and 2 for right side ----and moving right one and swapping when l and r are not both 0
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[s], nums[i]);
                s++;
            }
        }
    }
};