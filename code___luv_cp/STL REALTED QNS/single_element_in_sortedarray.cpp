#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int e = n - 1;
        int s = 0;
        // or else we can simply use the  xor operator--for O(n)--linear TC

        if (n==1) return nums[0];

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (m == 0 && nums[0] != nums[1])
                return nums[m]; // left edge case
            if (m == n - 1 && nums[n - 2] != nums[n - 1])
                return nums[m]; // right edge case

            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                return nums[m];
            } else if (m % 2 == 0) {
                if (nums[m] == nums[m - 1]) {
                    e = m - 1;
                } else {
                    s = m + 1;
                }
            } else {
                if (nums[m] == nums[m - 1]) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        // Binary search
        while (s < e) {
            int m = s + (e - s) / 2;

            // Ensure m is even for correct pairing
            if (m % 2 == 1) {
                m--;
            }

            // If the pair starts at m, the single element is on the right
            if (nums[m] == nums[m + 1]) {
                s = m + 2;
            } else {
                e = m; // Single element is on the left
            }
        }

        // 's' will eventually point to the single element
        return nums[s];
    }
};
