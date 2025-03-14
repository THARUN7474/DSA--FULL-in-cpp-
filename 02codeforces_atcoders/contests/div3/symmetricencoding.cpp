#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        string c;
        cin >> c;

        // // Reverse the string s to get c
        // string c(s.rbegin(), s.rend());

        // Use a set to find all unique characters
        set<char> unique_chars_set(c.begin(), c.end());

        // Copy the unique characters to a vector and sort them
        vector<char> unique_chars(unique_chars_set.begin(), unique_chars_set.end());

        // / Sort the vector (although the set insertion ensures they are already sorted)
        sort(unique_chars.begin(), unique_chars.end());

        // for (char ch : unique_chars)
        // {
        //     cout << ch << " ";
        // }
        // cout << endl;

        int len = unique_chars.size();

        string result = c;

        // Loop over the string c and replace each character
        for (int i = 0; i < c.size(); ++i)
        {
            // Find the position of c[i] in unique_chars
            auto it = find(unique_chars.begin(), unique_chars.end(), c[i]);
            int pos = distance(unique_chars.begin(), it);

            // Replace c[i] with the character at (len - pos - 1) in unique_chars
            result[i] = unique_chars[len - pos - 1];
        }

        cout << result << endl;
    }
    return 0;
}