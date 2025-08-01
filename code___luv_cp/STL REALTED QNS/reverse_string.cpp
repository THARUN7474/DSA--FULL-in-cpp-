#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        for (int i = 0; i < n; i = i + 2 * k)
        {
            if (n - i >= 2 * k)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else if (n - i < 2 * k && n - i >= k)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;

        // or else
        // for(int i = 0; i < n; i += 2 * k) {  // Fix loop increment
        //     if (n - i >= k) {----both conidtions here merged
        //         reverse(s.begin() + i, s.begin() + i + k);
        //     } else {  // If less than k characters remain, reverse all of them
        //         reverse(s.begin() + i, s.end());
        //     }
        // }
    }
};