#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] != 0)
            {
                return nums[i];
            }
            mp[nums[i]] = 1;
        }
        return -1;
    }

    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        } // tc === O(nlogn)
        // sc == O(N)
    }

    int findDuplicate(vector<int> &nums)
    {
        while (nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[nums[0]];
    }

    // visited method
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] < 0)
            {
                return abs(nums[i]);
            }
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        // tc == O(n);
    }

    int findDuplicate(std::vector<int> &nums)
    {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = 0;

            // Count the numbers less than or equal to mid
            for (int num : nums)
            {
                if (num <= mid)
                {
                    count++;
                }
            }

            // If count is greater than mid, the duplicate lies in the left half
            if (count > mid)
            {
                right = mid;
            }
            else
            { // Otherwise, it lies in the right half
                left = mid + 1;
            }
        }

        return left;
    }

    int findDuplicate(std::vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
