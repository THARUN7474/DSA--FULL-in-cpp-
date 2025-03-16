//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int l = 0; int r = 0;
        int s = arr[0];
        int ml = 0;
        int n = arr.size();
        while(r<n){
            while(l<=r && s >k){
                s -= arr[l];
                l++;
            }
            if(s==k){
                ml = max(ml,r-l+1);
            }
            r++;
            if(r<n){
                s =s+arr[r];
            }
        }
        return ml;
    }

    int longestSubarray(vector<int>& arr, int k) {
        int l = 0, r = 0;
        int sum = 0;
        int maxLength = 0;
        int n = arr.size();

        while (r < n) {
            sum += arr[r]; // Expand window

            while (l <= r && sum > k) { // Shrink window if sum exceeds k
                sum -= arr[l];
                l++;
            }

            if (sum == k) {
                maxLength = max(maxLength, r - l + 1); // Update max length
            }
            r++; // Move right pointer
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends