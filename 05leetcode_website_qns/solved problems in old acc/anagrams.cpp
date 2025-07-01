#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/valid-anagram/description/


class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;

        for (auto i : s)
        {
            mp[i]++;
        }
        for (auto i : t)
        {
            if (mp[i] == 0)
            {
                return false;
            }
            mp[i]--;
        }
        for (auto i : mp)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// Sorting/


// 2. Hash Table
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};


//3. Hash Table (Optimal)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count)
        {
            if (val != 0)
            {
                return false;
            }
        }
        return true;
    }
};