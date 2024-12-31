//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> factorialNumbers(long long N) {
        vector<long long> result;
        long long factorial = 1, i = 1;
        while (factorial <=N) {
            result.push_back(factorial);
            factorial *= ++i;
        }
        return result;
    }

    long long fact(long long n){
        if(n == 1 || n == 0){
            return 1;
        }
        else{
            return n * fact(n - 1);
        }
    }

    vector<long long> factorialNumbers(long long N)
    {
        vector<long long> vl;
        long long i = 1;
        long long factorial = fact(i);

        while(factorial <= N) {
            vl.push_back(factorial);
            i++;
            factorial = fact(i);
        }
        
        return vl;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends

// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.