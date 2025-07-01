#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/submissions/detail/1449797169/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int j = 0;
        vector<int> v;

        for (auto i : nums)
        {
            if (mp[i] == 0)
            {
                v.push_back(i);
                j++;
            }
            mp[i]++;
        }
        // int k = 0;
        // for(auto it : mp){
        //     cout<<it.first<<"ff"<<it.second<<endl;
        //     nums[k++] = it.first;
        // }

        // for(auto it = mp.begin(); it != mp.end(); it++){
        //     cout<<it->first<<"ff"<<it->second<<endl;
        //     nums[k++] = it->first;
        // }
        for (int i = 0; i < v.size(); i++)
        {
            nums[i] = v[i];
        }

        return j;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;

        int i = 1;

        for (int j = 1; j < n; j++)
        {
            if (nums[j] != nums[i - 1])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// it just that using 2 pointers ---one for checking and one for updating the array --inplace

// ### Explanation of the Code

// In this solution, the two-pointer technique is used:

// 1. **Pointers**:
//    - `i`: The "write" pointer (updates the array in-place to keep only unique elements).
//    - `j`: The "read" pointer (scans through the array to check for duplicates).

// 2. **Process**:
//    - Start both pointers at the beginning of the vector.
//    - For each element at `nums[j]`, check if it differs from the previous unique element at `nums[i - 1]`.
//    - If it’s different, assign `nums[i] = nums[j]` (write the unique element to the `i` position), then increment `i` to prepare for the next unique element.

// 3. **Return**:
//    - After the loop, `i` holds the length of the updated array with unique elements, since `i` increments only when a unique element is found.

// ### Sliding Window Concept

// This approach does resemble the sliding window technique:

// - The "window" here is conceptually sliding from left to right, with the `j` pointer moving to check each element in `nums`.
// - `i` updates only when a new unique element is encountered, effectively shrinking the "window" down to the smallest possible unique sequence.

// ### Final Code Summary

// This in-place technique ensures that duplicates are removed with \(O(n)\) time complexity and \(O(1)\) space complexity, making it efficient for arrays that are already sorted, as in this case.

// Your notes on using two pointers for "checking" (`j`) and "updating" (`i`) align perfectly with this solution!