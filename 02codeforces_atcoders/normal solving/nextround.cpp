#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // sort(v.begin(), v.end());
    for (int i : v)
    {
        // cout << i << " ";
        // cout<<v[i] << " ";
        // cout<<a<<i << " ";
        // cout<<b<<i << " ";
        // cout << v[b] << endl;
        if (i >= v[b-1] && i != 0)
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}