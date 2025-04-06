#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        if (n == 0)
            return {-1, -1};
        if (n == 1)
            return (nums[0] == target) ? vector<int>{0, 0} : vector<int>{-1, -1};

        int found = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                found = m;
                break;
            }
            else if (nums[m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        if (found == -1)
            return {-1, -1};

        int left = found;
        int right = found;

        while (left > 0 && nums[left - 1] == target)
            left--;
        while (right < n - 1 && nums[right + 1] == target)
            right++;

        return {left, right};
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = -1, last = -1;

        int s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
            if (nums[m] == target)
                first = m;
        }

        s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] > target)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
            if (nums[m] == target)
                last = m;
        }

        return {first, last};
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = findFirst(nums, target);
        int right = findLast(nums, target);
        return {left, right};
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
