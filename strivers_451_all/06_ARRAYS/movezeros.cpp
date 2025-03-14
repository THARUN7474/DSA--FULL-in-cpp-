#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if(nums[i]==0){
            //     s++;
            // }
            // else{
            //     swap(nums[i],nums[i-s]);
            // }
            if (nums[i] != 0)
            {
                swap(nums[s], nums[i]);
                s++;
            }
        }
    }
};