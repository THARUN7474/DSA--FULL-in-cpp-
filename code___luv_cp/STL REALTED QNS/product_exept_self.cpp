#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};




//code in brute force


class Solution { 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    product *= nums[j];
                }
            }
            res[i] = product;
        }
        return res;
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1);
        vector<int> s(n, 1);
        

        // prefix product
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * nums[i - 1];
        }

        // suffix product
        for (int i = n - 2; i >= 0; i--) {
            s[i] = s[i + 1] * nums[i + 1];
        }
        

        // product except self = prefix product * suffix product 
        for (int i = 0; i < n; i++) {
            p[i] = p[i] * s[i];
        }
        return p;
    }
};