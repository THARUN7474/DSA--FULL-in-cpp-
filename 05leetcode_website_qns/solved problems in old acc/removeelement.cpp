#include<bits/stdc++.h>

using namespace std;

// 27. Remove Element
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.

//my 1st thought process, and code of it 
class Solution {
public:
     int removeElement(vector<int>& nums, int val) {
        int k = 0; // Initialize k
        for (auto i = nums.begin(); i != nums.end(); ) {
            if (*i == val) {
                i = nums.erase(i); // Erase and continue from the new iterator position
            } else {
                ++i;   // Increment iterator if no erasure happened
                ++k;   // Increment k if the element is not removed
            }
        }
        return k;
    }
};

// 27. Remove Element - optimized code--maynot ---0(N)---here not used any inbuilt libraries
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (auto i : nums) {
            if (i != val) {
                nums[j++] = i;
            }
        }
        return j;
    }
};