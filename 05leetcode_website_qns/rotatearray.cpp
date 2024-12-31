#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
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

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Ensure k is within the range [0, n)

    // Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the rest of the elements after k
    reverse(nums.begin() + k, nums.end());
}

void rev(vector<int> &nums, int s, int e)
{
    // Reverse the elements between indices s and e
    while (s < e)
    {
        swap(nums[s++], nums[e--]);
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();    // Size of the array
    k = k % n;              // Normalize k to be within bounds of the array length
    int rotate = n - k - 1; // Calculate the point to split the array

    // Step 1: Reverse the first part
    rev(nums, 0, rotate);

    // Step 2: Reverse the second part
    rev(nums, rotate + 1, n - 1);

    // Step 3: Reverse the entire array
    rev(nums, 0, n - 1);
}