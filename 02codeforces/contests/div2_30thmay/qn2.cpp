#include <bits/stdc++.h>

using namespace std;

// Function to find the nearest element to b in the vector a
long long findNearestElement(const vector<long long> &a, long long b)
{
    if (a.empty())
        return LLONG_MAX; // or some other indication of failure

    // Perform binary search
    auto it = lower_bound(a.begin(), a.end(), b);

    if (it == a.end())
    {
        // If b is larger than all elements in the array
        return *(it - 1);
    }
    else if (it == a.begin())
    {
        // If b is smaller than all elements in the array
        return *it;
    }
    else
    {
        // Otherwise, check the closest of the two neighbors
        long long after = *it;
        long long before = *(it - 1);
        if (abs(after - b) < abs(before - b))
        {
            return after;
        }
        else
        {
            return before;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v1;
        vector<long long> v2;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long m;
            cin >> m;
            v1.push_back(m);
        }
        for (int i = 0; i < n + 1; i++)
        {
            long long m;
            cin >> m;
            v2.push_back(m);
        }
        bool find = true;
        for (int i = 0; i < n + 1; i++)
        {
            if (i < n)
            {
                // cout << abs(v1[i] - v2[i]) << "ele wise" << endl;
                // cout << v1[i] << v2[i] << "last ele" << v2[n] << "booli" << find << endl;
                if ((v1[i] <= v2[n] && v2[n] <= v2[i]) || (v2[i] <= v2[n] && v2[n] <= v1[i]))
                {
                    find = false;
                }
                ans = ans + abs(v1[i] - v2[i]);
            }
            else
            {
                sort(v1.begin(), v1.end());
                // nearest element to b
                long long nearest = findNearestElement(v1, v2[i]);
                // cout << nearest << "copy" << endl;
                // cout << "mmfinal" << v2[i] << endl;
                ans++;
                // cout << "finalbool" << find << endl;
                if (find)
                {
                    ans = ans + abs(nearest - v2[i]);
                    // cout << abs(v1[i] - v2[i]) << "differenece" << endl;
                }
            }
        }
        cout << ans << endl;
    }
}