#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            int n = s.size();
            if(equal(s.begin(),s.begin()+n/2, s.rbegin())){
                return s;
            }
        }
        return "";
    }
};