#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        for(auto i: nums){
            if(mp[i] > 1){
                return true;
            }
        }
        return false;
    }

    //we can use ---set ----> set<int>(nums.begin(),nums.end()).size() < nums.size() then true --better use unordered_set<> coz of internal implementation
    // we can use 2 loops---O(n^2) so it s not optimal

    // bool containsDuplicate(vector<int>& nums) {
    //     unordered_set<int> seen;
    // for (int num : nums) {
    //     if (seen.count(num)) {
    //         return true;  // Duplicate found
    //     }
    //     seen.insert(num);
    // }
    // return false;  // No duplicates
    // }

};