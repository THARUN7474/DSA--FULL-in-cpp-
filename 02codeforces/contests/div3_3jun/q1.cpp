#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int ans = 0;
        // cout << "ss" << s << endl;
        unordered_map<char, int> mpp = {};
        string c = "ABCDEFG";
        for (int i = 0; i < c.size(); i++)
        {
            mpp[c[i]] = 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }

        for (auto i : mpp)
        {
            // cout << i.first << " " << i.second << endl;
            if (i.second < b)
            {
                ans = ans + b - (i.second);
            }
        }
        cout << ans << endl;
    }
}