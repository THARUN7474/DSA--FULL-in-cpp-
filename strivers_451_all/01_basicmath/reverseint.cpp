#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int reverse(int x) {
    // bool y = true;
    // int result = 0;
    // if(x<0){
    //     y = false;
    //     x = (-1)*x;
    // }
    // while(x){
    //     int n = x %10;
    //     if (result > INT_MAX / 10 || (result == INT_MAX / 10 && n > 7)) return  0;
    //     if (result < INT_MIN / 10 || (result == INT_MIN / 10 && n < -8)) return 0;
    //     result = result*10 +n;
    //     x = x/10;
    // }

    // if(!y){
    //     return (-1)*result;
    // }
    // else{
    //     return result;
    // }
    // }
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;//log10(n)-----time complexoity as here step are divided so definelty log terms will be the TC 
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;
            result = result * 10 + pop;
        }
        return result;
    }
};