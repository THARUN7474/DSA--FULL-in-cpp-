#include <bits/stdc++.h>

using namespace std;



// my solution i got at 1st but here i thought of using mid caluaiton instead of j<i but i foudn otu and made this way 
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        if (numRows == 0)
            return ans; // Handle the case when numRows is 0
        if (numRows == 1)
        {
            ans[0].push_back(1); // Handle the case when numRows is 1
            return ans;
        }
        if (numRows == 2)
        {
            ans[0].push_back(1); // First ele is always [1]
            ans[1].push_back(1); // Second else is always [1, 1]
            return ans;          // Handle the case when numRows is 2
        }
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                ans[i].push_back(1); // First row
            }
            else if (i == 1)
            {
                ans[i].push_back(1); // Second row
                ans[i].push_back(1);
            }
            else
            {
                ans[i].push_back(1); // Start with 1
                for (int j = 1; j < i; j++)
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]); // Calculate middle values
                }
                ans[i].push_back(1); // End with 1
            }
        }
        return ans;
    }
};


//less lines code mysoluiion 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){// means 1 means 0 , 3 means 2 , 4 means 3, 5 means 4 
        // so if we need 5 elemenets row means 4 , as last and 1st are 1's we will cal middle 3 so ,
        // we just traverse inner loop from 1 -2 -3 upto i-1(4-1 ) we get those 3 mid elements 
        vector<int> ele(i+1, 1);// here size will be i+1 only as it cant be 0 we start with [1] and then for 2 --[1] [1,1] ---to make 1st last all 1s we made this way
        for(int j = 1; j<= i-1; j++){
            ele[j] = ans[i-1][j-1]+ ans[i-1][j]; // like 01, 12,23  of prevs element 
            // heer we cant pushback this so dont try it as we already filled array with 1's 
        }
        ans.push_back(ele);

        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1; // First and last elements are always 1
            for (int j = 1; j < i; j++) { // Iterate up to i
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]; // Filling the triangle
            }
        }
        return ans;
    }
};

// for all ---the above code is same logic but different ways of writing it
// and time complexity is O(n^2) and space complexity is O(n^2) as we are storing all the elements in a 2D vector
// and we are using 2 loops one for rows and one for columns to fill the triangle we cant optimize it further as we need to store all the elements in a 2D vector

// any way the given contraints are small so we can use this approach Constraints:
// 1 <= numRows <= 30 by seeign this i am fixed that i can give a code of O(n^2) time complexity and O(n^2) space complexity
// and it will work fine for all the test cases and we can use this approach to solve




int main() {
    Solution sol;
    int numRows = 5; // Example input
    vector<vector<int>> result = sol.generate(numRows);
    
    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}