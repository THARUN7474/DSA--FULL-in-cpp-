//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printNos(int N)
    {
        // code here
        if (N == 0)
        {
            return;
        }
        cout << N-- << " ";
        printNos(N);
    }

    void func(int i, int n)//pass n,n initally----forward recursively runs 
    {

        // Base Condition.
        if (i < 1)
            return;
        cout << i << endl;

        // Function call to print i till i decrements to 1.
        func(i - 1, n);
    }

    void func(int i, int n)
    {

        // Base Condition.
        if (i > n)
            return;//means breaks at i ==n -then reverse recursive---kid off backtraking gets 

        // Function call to print (i+1) integers.
        func(i + 1, n);
        cout << i << endl;
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;

    // taking testcases
    cin >> T;

    while (T--)
    {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends


// Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

// Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.