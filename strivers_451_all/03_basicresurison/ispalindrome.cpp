#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string output;

        for (char c : s)
        {
            if (isalnum(c))
            {
                output += tolower(c);
            }
        }
        // output = output;
        // cout<<output<<endl;
        string ss = output;
        // cout<<ss<<endl;
        reverse(ss.begin(), ss.end());
        // cout<<ss<<endl;

        // Create a reversed copy of the original string
        // reverse_copy(originalString.begin(), originalString.end(),back_inserter(reversedCopy));

        return output == ss;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string N;
        getline(cin, N);
        Solution ob;
        bool ans = ob.isPalindrome(N);
        cout << ans << endl;
    }
    return 0;
}

// Intuition
// By reading the question you may think that first we need to convert the string to desired form and then check if its a valid palindrome or not.

// But all of that is just distraction you can check valid palindrome by simply using two pointers no need to convert.

// Approach
// If a character is not alphanumeric we can simply ignore it and update our pointer to next character (for both pointers)
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};

// Time Complexity:  O(N)

// Space Complexity: O(1)

bool palindrome(int i, string &s)
{

    // Base Condition
    // If i exceeds half of the string means all the elements
    // are compared, we return true.
    if (i >= s.length() / 2)
        return true;

    // If the start is not equal to the end, not the palindrome.
    if (s[i] != s[s.length() - i - 1])
        return false;

    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(i + 1, s);
}

// Time Complexity: O(N) { Precisely, O(N/2) as we compare the elements N/2 times and swap them}.

// Space Complexity: O(1) { The elements of the given array are swapped in place so no extra space is required}.