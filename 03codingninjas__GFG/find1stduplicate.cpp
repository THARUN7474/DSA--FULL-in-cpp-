//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++
class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    found = true;
                    return i + 1;
                }
            }
        }
        return -1;
    }

    int firstRepeated(int arr[], int n)
    {
        // code here
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if(mp[arr[i]]>1){
                return i + 1;
            }
        }
    }
};

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int find(int arr[], int len, int seek)
    {
        for (int i = 0; i < len; ++i)
        {
            if (arr[i] == seek)
                return i;
        }
        return -1;
    }
    int firstRepeated(int arr[], int n)
    {
        // code here
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second > 1)
            {
                return find(arr, n, i.first);
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends