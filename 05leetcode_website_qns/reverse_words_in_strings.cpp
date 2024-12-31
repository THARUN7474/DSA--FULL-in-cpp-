#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        reverse(s.begin(),s.end());
        for(int i = 0; i< s.length();i++){
            string w = "";
            while(i<s.length() && s[i]!=' '){
                w = w + s[i];
                i++;
            }
            reverse(w.begin(),w.end());
            if(w.length()>0){
                ans += " " +w;
            }
        }
        return ans.substr(1);
    }
};