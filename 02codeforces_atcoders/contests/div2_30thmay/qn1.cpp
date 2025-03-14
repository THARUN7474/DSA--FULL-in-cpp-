#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool is_digit = true;
        bool is_gret = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (48 <= s[i] <= 57)
            {
                if (s[i + 1] < s[i])
                {
                    is_gret = false;
                    break;
                }
            }
            else
            {
                if (48 <= s[i + 1] <= 57)
                {
                    is_digit = false;
                    break;
                }
                else if (s[i + 1] < s[i])
                {
                    is_gret = false;
                    break;
                }
            }
        }
        if (is_gret && is_digit)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}