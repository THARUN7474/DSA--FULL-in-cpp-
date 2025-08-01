#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0; i<n;i++){
            for(int j = i+1; j<n;j++){
                int w = j- i;
                int h = min(height[i],height[j]) ;
                ans = max(ans, w*h);
            }
        }
        return ans;        
    }
};//brute force ----gives TLE


// so now 2 pointer method

//why means? max area is controlled by the smaller of the two heights, the width is controlled by the distance between the two heights.
// so here 2 pointer method, we need to decide logic for which pointer to upgrdae and why and when  it decided by the smaller height here so we will move the pointer of the smaller height everytime we loop through the array and calculate the area and update the max area if needed and return the max area at the end


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0; int j = n-1;
        while(i < j){
            ans = max(ans, (j-i) * min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }

        }
        return ans;        
    }
};