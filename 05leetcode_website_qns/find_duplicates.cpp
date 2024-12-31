#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {

        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return true;                }
        //     }
        // }
        // return false;

        // unordered_map<int,int> v;
        // for(auto i: nums){
        //     v[i]++;
        // }
        // for(auto i : v){
        //     if(i.second != 1){
        //         return true;
        //     }
        // }
        // return false;

        unordered_map<int, int> v;
        for (auto i : nums)
        {
            if (v[i] == 1)
            {
                return true;
            }
            v[i]++;
        }
        return false;
    }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num))
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};