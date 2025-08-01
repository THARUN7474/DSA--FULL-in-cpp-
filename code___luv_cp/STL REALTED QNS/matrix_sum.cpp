#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // accumulate(v.begin(),v.end(),0)//sum of 1-Darray using stl ;

        int row = 0;
        auto lam = [&](int su,vector<int> vec){
            su = su + vec[row];
            if(row != vec.size()-row-1){
                su = su + vec[vec.size()-row-1];
            }

            row++;
            return su;
        };
        int s = accumulate(mat.begin(),mat.end(),0,lam);
        return s;
    }
};

class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == j && n-j-1 == i)
                {
                    sum = sum + matrix[i][j];
                }
                else if(i == j)
                {
                    sum = sum + matrix[i][j];
                }
                else if(i == n-j-1)
                {
                    sum = sum + matrix[i][j];
                }
            }
        }
        return sum;
    }
};



// int maxSubarraySum(vector<int> arr) {
//     int n = arr.size();
//     int max_so_far = INT_MIN, max_ending_here = 0;

//     for (int i = 0; i < n; i++) {
//         max_ending_here = max_ending_here + arr[i];

//         if (max_so_far < max_ending_here)
//             max_so_far = max_ending_here;

//         if (max_ending_here < 0)
//             max_ending_here = 0;
//     }

//     return max_so_far;
// }

// int maxSubarraySum(vector<int> arr) {
//     int n = arr.size();
//     int max_so_far = arr[0], curr_max = arr[0];

//     for (int i = 1; i < n; i++) {
//         curr_max = max(arr[i], curr_max + arr[i]);
//         max_so_far = max(max_so_far, curr_max);
//     }

//     return max_so_far;
// }