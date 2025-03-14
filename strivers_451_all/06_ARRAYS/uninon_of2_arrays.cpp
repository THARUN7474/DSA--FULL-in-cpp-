//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        vector<int> v;
        int i = 0, j = 0;
        int n1 = a.size();
        int n2 = b.size();

        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                if (v.empty() || a[i] != v.back())
                { // Check if `v` is empty before accessing `back()`
                    v.push_back(a[i]);
                }
                i++;
            }
            else if (a[i] > b[j])
            {
                if (v.empty() || b[j] != v.back())
                { // Check if `v` is empty before accessing `back()`
                    v.push_back(b[j]);
                }
                j++;
            }
            else
            { // a[i] == b[j]
                if (v.empty() || a[i] != v.back())
                {
                    v.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        // Process remaining elements of `a`
        while (i < n1)
        {
            if (v.empty() || a[i] != v.back())
            {
                v.push_back(a[i]);
            }
            i++;
        }

        // Process remaining elements of `b`
        while (j < n2)
        {
            if (v.empty() || b[j] != v.back())
            {
                v.push_back(b[j]);
            }
            j++;
        }

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
