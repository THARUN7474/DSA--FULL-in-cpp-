#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            int a = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == a && i != j){
                    return {i,j};
                }
            }
        }
        return {};
    }
};