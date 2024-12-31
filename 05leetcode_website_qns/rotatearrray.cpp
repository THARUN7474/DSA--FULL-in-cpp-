#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int n = (i + k) % nums.size();
            arr[n] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = arr[i];
        }
    }
};


// #2 solution

// [6,7,1,2,3,4,5]
//  # # * * * * *
//      k

// For #, nums[:k]
// For *, nums[k:]

//  * * * * * # #
// [1,2,3,4,5,6,7]

// For #, nums[-k:]
// For *, nums[:-k]

// nums[:k], nums[k:] = nums[-k:], nums[:-k]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k != 0) {
            vector<int> temp(nums.end() - k, nums.end());
            temp.insert(temp.end(), nums.begin(), nums.end() - k);
            copy(temp.begin(), temp.end(), nums.begin());
        }        
    }
};



// 3rd way

// reverse(0, last index) → whole array
// reverse(0, k - 1) → before k
// reverse(k, last index) → after k


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }    
};