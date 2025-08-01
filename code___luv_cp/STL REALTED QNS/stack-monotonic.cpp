#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> finalPrices(vector<int>& prices) {
            stack<int> s;
            int n = prices.size();
            for(int i = 0; i< n; i++){
                while(!s.empty() && prices[i] <= prices[s.top()]){
                    int in = s.top();
                    s.pop();
                    prices[in] -= prices[i];
                }
                s.push(i);
            }
            return prices;
        }
    };