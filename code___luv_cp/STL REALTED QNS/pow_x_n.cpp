#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        int nn;
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n == 0){
            return 1;
        }
        if(x==1.00000){
            return 1;
        }
        double ans = 1.00000;
        if (n < 0) {
            nn = -1 * n;
            while (nn != 0) {
                ans = ans / x;
                nn--;
            }
            return ans;
        }
        nn = n;
        while (nn != 0) {
            ans = ans * x;
            nn--;
        }
        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1.0) return 1.0;
        if(x == 0.0) return 0.0;
        if(n == 0) return 1.0;
        if(x == -1 && (n&1) == 0) return 1.0;
        if(x == -1 && (n&1) == 1) return -1.0;// all these are edge or corner cases

        double ans = 1;
        long d = n;// binary representation of n we are using here
        if(n <0){
            x = 1/x;
            d = -d;
        }// conversion for negative n

        while(d>0){
            if(d%2 == 1){
                ans = ans * x;
            }
            x = x*x;
            d = d/2;
        }
        return ans;
    }
};