#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int diff = 0;
        for(int i = 0; i < s.size(); i++){
            diff ^= s[i] ^ t[i];
        }
        diff = diff ^ t[t.length() - 1];
        return diff;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> s1,s2;

        for (auto aa: s){
            s1[aa]++;
        }
        for(auto _a:t){
            s2[_a]++;
        }
        for(char i : t){
            if(s1[i]!=s2[i]){
                return i;
            }
        }
        return 'x';
    }
};


// Intuition
// The problem asks us to find one extra character in string t compared to string s. Since t has all characters from s plus one additional character, our goal is to identify that extra character efficiently.

// Approach
// Code-1 (Hash Table Approach)
// Count the occurrences of each character in s using an array hash of size 26.
// Subtract each character in t from the hash array.
// Any non-zero value in hash will indicate the extra character.

// Code-2 (XOR Approach)
// XOR all characters in s and t.
// Since XORing identical characters cancels them out, the result will be the extra character in t.

// Code-3 (Sorting Approach)
// Sort both s and t.
// Compare characters of s and t one by one; the first mismatch is the extra character.
// If all characters match, then the extra character is the last one in t.

// Complexity
// Time complexity & Space Complexity:
// For Hash Table Approach:
// Time complexity:O(n) — We traverse each string once.
// Space complexity:O(1) — Fixed array of size 26 for character counts.
// cpp

// For XOR approach
// Only one pass through each string.
// Space complexity:O(1) — Only one variable is used for XOR operations.

// Sorting Approach
// Time complexity: O(nlogn) — Sorting both strings.
// Space complexity: O(1) if sorting is done in-place, O(n) otherwise.

// Code-1(Using Hash Table Approach)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        for(int j=0;j<t.size();j++){
            hash[t[j]-'a']--;
        }

        char ans;
        for(int k=0;k<26;k++){
            if(hash[k] != 0){
                ans = 'a' + k;
                break;
            }
        }

        return ans;
    }
};
// Code-2(Using XOR Approach)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(char c:s){
            result^=c;
        }

        for(char c:t){
            result^=c;
        }

        return result;
    }
};
// Code-3(Using Sorting Approach)
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        

        for(int i=0;i<t.size();i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return -1;
    }
};