#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false; // Break in sorting order
    }
    return true;
}

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        {
            ++count;
        }
    }

    return (count <= 1);
}

// 🔥 Final Observations
// If count == 0, it's either already sorted or a single-element array → Valid ✅

// If count == 1, it's a sorted array with one rotation → Valid ✅

// If count > 1, multiple breaks exist → Invalid ❌

bool isSortedAndRotated(vector<int> &nums, int &breakIndex)
{
    int n = nums.size();
    int count = 0;
    breakIndex = -1; // Default, means no break

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        { // Rotation break
            count++;
            breakIndex = i; // Store break point index
        }
    }

    return (count <= 1); // Valid sorted & rotated if max one break
}

int findPeakIndex(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1])
        {
            left = mid + 1; // Move to the increasing part
        }
        else
        {
            right = mid; // Move to the decreasing part
        }
    }
    return left; // Peak index
}
