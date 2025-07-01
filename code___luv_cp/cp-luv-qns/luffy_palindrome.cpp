#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--)
        {
            int r, l;
            cin >> r >> l;
            int hsh[26];
            // fill(hsh, hsh+26, 0);
            for (int i = 0; i < 26; i++)
            {
                hsh[i] = 0;
            }
            l--, r--;
            for (int i = l; i <= r; i++)
            {
                hsh[s[i] - 'a']++;
            }
            int odd_count = 0;
            for (int i = 0; i < 26; i++)
            {
                if (hsh[s[i] - 'a'] % 2 != 0)
                {
                    odd_count++;
                }
            }
            // cout << odd_count << endl;
            if (odd_count > 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        // \\ TC WILL BE-- --O(t * (n + q(26 + n + 26)))---> t*N*q --->10^7 so tle gets
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<vector<int>> hsh(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i)
        {
            hsh[i + 1][s[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                hsh[j][i] += hsh[j - 1][i];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int oddCt = 0;
            for (int i = 0; i < 26; ++i)
            {
                int charCt = hsh[r][i] - hsh[l - 1][i];
                if (charCt % 2 != 0)
                    oddCt++;
            }
            if (oddCt > 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}//optimzed soltuion