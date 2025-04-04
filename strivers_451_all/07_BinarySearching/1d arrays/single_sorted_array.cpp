#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {// we can use xor operation to find the single element in O(n) time and O(1) space complexity.

            // Binary search approach to find the single element in a sorted array
            // The array is sorted and all elements appear twice except for one element.
            int n = nums.size();
            int s = 0, e = n - 1;
    
            // Binary search
            while (s < e) {
                int m = s + (e - s) / 2;
    
                // Ensure m is even for correct pairing of elements
                // If m is odd, decrement it to make it even
                // This ensures that we are always checking pairs of elements
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
    