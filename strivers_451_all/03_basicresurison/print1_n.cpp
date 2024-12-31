//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Complete this function
       void printNosHelper(int current, int N) {
        if (current > N) {
            return;
        }
        cout << current << " ";
        printNosHelper(current + 1, N);
    }

    void printNos(int N) {
        printNosHelper(1, N);
    }

    void printNos(int N){
        if(N==0){
            return;
        }
        printNos(N-1);

        cout<<N<<" ";

        // this ensure that
        // After the recursive call returns, it prints the current number N. This happens in the order from 1 to N because of the nature of recursion unwinding (i.e., after reaching the base case, it starts executing the print statements from the deepest call back up to the initial call).
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) } 

// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.