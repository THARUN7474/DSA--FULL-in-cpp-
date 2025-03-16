//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {// similiarly ----secondsmallest and retuening both as pair --- 
        // Code Here
        int f = -1; 
        int s = -1;// here we just use INT_MAX instead of -1 FOR SECOND SMALLEST CASE 
        
        for(int i : arr){
            if(i>f){
                s = f;
                f = i;
            }
            else if(i>s && i<f){
                s = i;
            }
        }
        
        return s;
    }

    int getsecondsmallest(vector<int> &arr){
        int f = INT_MAX;
        int s = INT_MAX;
        
        for(int i : arr){
            if(i<f){
                s = f;
                f = i;
            }
            else if(i<s && i>f){
                s = i;
            }
        }
        
        return s;
    }   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends