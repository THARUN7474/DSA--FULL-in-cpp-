#include<bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/find-the-difference-of-two-arrays/


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());

        vector<int> v1,v2;

        set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(v1));
        set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),back_inserter(v2));
        
        return {v1,v2};
    }
};




class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>arr1(2);
        unordered_set<int>a(nums1.begin(),nums1.end());//removing duplicates
        unordered_set<int>b(nums2.begin(),nums2.end());//removing duplicates or we can use looping and removing double ones


        for(int i:a){
            if(b.find(i)==b.end()){
                arr1[0].push_back(i);//in a but not in b
            }
        }
        for(int j:b){
            if(a.find(j)==a.end()){
                arr1[1].push_back(j);//in b but not in a
            }
        }
        return arr1;
        
    }
};