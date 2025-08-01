#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool valid(const vector<int> &arr, int n, int m, int limit)
    {
        int slot = 1; // Number of subarrays
        int currentSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > limit)
                return false; // A single element exceeds limit
            if (currentSum + arr[i] <= limit)
            {
                currentSum += arr[i];
            }
            else
            {
                slot++; // Start a new subarray
                currentSum = arr[i];
                if (slot > m)
                    return false; // Too many subarrays
            }
        }
        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            return -1; // Impossible to split into more parts than elements

        int s = *max_element(nums.begin(), nums.end());  // Smallest possible largest sum
        int e = accumulate(nums.begin(), nums.end(), 0); // Largest possible largest sum
        int ans = e;

        while (s <= e)
        {
            int m = s + (e - s) / 2; // Avoid overflow
            if (valid(nums, n, k, m))
            {
                ans = m;
                e = m - 1; // Try smaller sums
            }
            else
            {
                s = m + 1; // Try larger sums
            }
        }

        return ans;
    }
};
