#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        long y=0;
        long X=x;
        if(x<0){
            return false;
        }
        while(x){
            y=y*10+x%10;
            x=x/10;
        }
        if(X==y){
            return true;
        }
        else{
            return false;
        }
    }
};