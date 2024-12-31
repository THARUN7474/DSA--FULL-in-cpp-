//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        set<int> setA(A, A + n1);
        set<int> setB(B, B + n2);
        set<int> setC(C, C + n3);

        // Use an unordered_map to store counts of common elements
        unordered_map<int, int> mp;
        
        // Store elements of setA in the map with a count of 1
        for (int num : setA) {
            mp[num] = 1;
        }
        
        // For each element in setB, if it exists in the map, increment its count
        for (int num : setB) {
            if (mp[num]==1) {
                mp[num]++;
            }
        }
        
        // For each element in setC, if it exists in the map and has a count of 2, it's a common element
        vector<int> result;
        for (int num : setC) {
            if (mp[num] == 2) {
                result.push_back(num);
            }
        }
        
        return result;
    }
        vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        // Initialize sets with the elements from arrays A, B, and C
        set<int> setA(A, A + n1);
        set<int> setB(B, B + n2);
        set<int> setC(C, C + n3);

        // Use an unordered_map to store counts of common elements
        unordered_map<int, int> mp;
        
        // Store elements of setA in the map with a count of 1
        for (int num : setA) {
            mp[num] = 1;
        }
        
        // For each element in setB, if it exists in the map, increment its count
        for (int num : setB) {
            if (mp.find(num) != mp.end()) {
                mp[num]++;
            }
        }
        
        // For each element in setC, if it exists in the map and has a count of 2, it's a common element
        vector<int> result;
        for (int num : setC) {
            if (mp.find(num) != mp.end() && mp[num] == 2) {
                result.push_back(num);
            }
        }
        
        return result;
    }
        vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        // Use an unordered_map to store counts of elements from the first array
        unordered_map<int, int> mp;
        for (int i = 0; i < n1; ++i) {
            mp[A[i]] = 1;
        }
        
        // Check the second array and update the map
        for (int i = 0; i < n2; ++i) {
            if (mp.find(B[i]) != mp.end() && mp[B[i]] == 1) {
                mp[B[i]] = 2;
            }
        }
        
        // Use a set to store common elements to handle duplicates
        set<int> s;
        for (int i = 0; i < n3; ++i) {
            if (mp.find(C[i]) != mp.end() && mp[C[i]] == 2) {
                s.insert(C[i]);
            }
        }
        
        // Convert the set to a vector
        vector<int> result(s.begin(), s.end());
        return result;
    }

    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        // Initialize starting indexes for A, B, and C
        int i = 0, j = 0, k = 0;
        
        // Initialize the result vector
        vector<int> result;
        
        // Iterate through the arrays while all arrays have elements left
        while (i < n1 && j < n2 && k < n3) {
            // If A[i] == B[j] and B[j] == C[k], record the common element
            if (A[i] == B[j] && B[j] == C[k]) {
                // To handle duplicates, we should only add the element if it is not the same as the last added element
                if (result.empty() || result.back() != A[i]) {
                    result.push_back(A[i]);
                }
                i++;
                j++;
                k++;
            }
            // If A[i] < B[j], increment i
            else if (A[i] < B[j]) {
                i++;
            }
            // If B[j] < C[k], increment j
            else if (B[j] < C[k]) {
                j++;
            }
            // We reach here when A[i] > B[j] and B[j] >= C[k], increment k
            else {
                k++;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends