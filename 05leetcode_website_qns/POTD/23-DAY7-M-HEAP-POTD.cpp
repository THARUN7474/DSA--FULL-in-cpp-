#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> mp;
        
        int day = 0, index = 0, n = events.size(), result = 0;
        
        while (!mp.empty() || index < n) {
            if (mp.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                mp.push(events[index][1]);
                index++;
            }
            mp.pop();
            result++;
            day++;
            
            while (!mp.empty() && mp.top() < day) {
                mp.pop();
            }
        }
        return result;
    }
};