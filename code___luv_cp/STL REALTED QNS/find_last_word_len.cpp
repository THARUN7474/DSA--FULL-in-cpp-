#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length()-1;
        while(s[end]==' '){
            end--;
        }
        int st = end;
        while(st>=0 && s[st]!= ' '){
            st --;
        }
        return end -st;
    }

    
};


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 && s[i] == ' '){
            i--;
        }
        int l = 0;
        while(i>=0 && s[i] != ' '){
            i--;
            l++;
        }
        return l;
    }
};



class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_last_not_of(' ') +1;
        s.erase(i);
        return s.find_last_of(' ') == string::npos ? s.length(): s.length() - s.find_last_of(' ') - 1;
    }
};