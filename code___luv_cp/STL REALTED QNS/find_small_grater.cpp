#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char i : letters){
            if(i>target){
                return i;
            }
        }
        return letters[0];
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size()-1;
        int p = -1;
        while(l<=r){
            int m = l+ (r-l)/2;
            if(letters[m]>target){
                p = m;
                r=m-1;
            }else{
                l = m+1;
            }
        }
        if(p == -1){
            return letters[0];
        }
        return letters[p];

    }
};


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ind = upper_bound(letters.begin(),letters.end(),target) - letters.begin();
    
        // int ind = binary_search(letters.begin(),letters.end(),target);---direct binary search fidning the target character
        if(ind == letters.size()){
            return letters[0];
        }
        return letters[ind];
    }
};