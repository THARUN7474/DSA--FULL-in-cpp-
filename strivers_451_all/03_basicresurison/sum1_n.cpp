//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long hlper(long long n)
    {
        if (n == 0)
        {
            return 0;
        }
        // cout<<(n*n*n)<<endl;
        return n * n * n + hlper(n - 1);
    }

    long long sumOfSeries(long long n)
    {
        // code here
        return hlper(n);
    }


    // Forward Recursion (Using 1 Parameter):
    // long long sumOfCubesForward(long long n)
    // {
    //     if (n == 0)
    //         return 0;
    //     return n * n * n + sumOfCubesForward(n - 1);
    // }

    // Backward Recursion (Using 1 Parameter):
    // long long sumOfCubesBackward(long long n)
    // {
    //     if (n == 0)
    //         return 0;
    //     long long sum = sumOfCubesBackward(n - 1);
    //     return sum + n * n * n;
    // }

    // Forward Recursion (Using 2 Parameters):
    long long sumOfCubesForward(long long n, long long sum = 0)
    {
        if (n == 0)
            return sum;
        return sumOfCubesForward(n - 1, sum + n * n * n);
    }

    // Backward Recursion (Using 2 Parameters):
    long long sumOfCubesBackward(long long n, long long sum = 0)
    {
        if (n == 0)
            return sum;
        return sumOfCubesBackward(n - 1, sum) + n * n * n;
    }

    // formula way--more easy TC too
    long long sumOfSeries(long long n)
    {
        // Sum of cubes formula: (n * (n + 1) / 2)^2
        long long sum = (n * (n + 1) / 2);
        return sum * sum;
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
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends