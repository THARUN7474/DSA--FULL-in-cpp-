#include <bits/stdc++.h>

using namespace std;

// my solution:
// The problem is to find the number of possible original strings that could have been typed given a string `word` where characters can be repeated consecutively. The solution involves counting the number of consecutive characters in the string and returning that count.

// i will just count the char and its consecutive char count and if it is more than 1 then i will just add all its count -1 and add 1 and return ans

class Solution
{
    public: 
    int possibleStringCount(string word)
    {
        unordered_map<char, int> mp;
        char l = word[0];
        for (int i = 0; i<word.length(); i++)
        {
            if(word[i]==l){
                mp[word[i]]++;
            }
            else{
                l = word[i];
                if(mp[word[i]]<1){
                     mp[word[i]]++;
                }
               
            }
        }
        int c = 1;
        for (auto e : mp)
        {
            if (e.second > 1)
            {
                c = c + e.second - 1;
            }
        }
        return c;
    }
};

// nice way to solve this problem is to just count the number of unique characters in the string and return that count as the result. This is because each unique character can be typed at most once, and consecutive characters of the same type can be considered as a single character for the purpose of counting. --better coding style and understanding and presenatation 
// better solution: 
    // int possibleStringCount(string word)
    // {
    //     int n = word.length();
    //     if (n == 0) return 0; // Handle empty string case
    //     int count = 1; // Start with the first character
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (word[i] == word[i - 1]) // If current char is same from previous
    //         {
    //             count++; // Increment count for a new character
    //         }
    //     }
    //     return count; // Return the total count of unique characters
class Solution
{
public:
    int possibleStringCount(string word)
    {
        // finding repeated char counts, or finding size - unique chars
        int n = word.length();
        int k = 1;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1])
            {
                k++;
            }
        }
        return k;
    }
};

// it works coz we can only remove same type of characters, so if we have 3 'a's in a row, we can only remove 2 of them, leaving us with 1 'a'. Thus, the count of original strings is equal to the number of consecutive characters in the string.
// we cant remove 1 b and 1 c from aabbcc as she made atmost 1 mistake

// Alternative solutions: -expore these solutions for better understanding and efficiency. --learn from these solutions.

// class Solution {
//   int possibleStringCount(string word) {
//     int ans = 1;
//     int count = 1;
//     string last = word[0];

//     for (int i = 1; i < word.length; i++) {
//       if (word[i] != last) {
//         ans += count - 1;
//         count = 1;
//         last = word[i];
//       } else {
//         count++;
//       }
//     }
//     ans += count - 1;
//     return ans;
//   }
// }



class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;// Initialize answer to 1 as we have at least one valid string (the original string itself) and we remove the given strings from all the cases possible so we add 1 time at 1st only 

        // intial group
        int cnt = 1;
        char ch = word[0]; // last character in the group

        for(int i=1;i<word.size();i++){
            if(word[i]==ch){
                // current group increases
                cnt++;
            }
            else{
                // add valid sstrings to answer
                ans+=(cnt - 1); // here we add all the possible strings coz of maybe mistakes of that char and remvoving 1 char from that group that is no mistake case 

                // new group started;
                ch = word[i];
                cnt=1;
            }    
        }

        // last group
        ans += (cnt-1);

        return ans;
    }
};


class Solution {
public:
    static int possibleStringCount(string& word) {
        int n=word.size(), cnt=n;
        for(int i=1; i<n; i++)
            cnt-=(word[i]!=word[i-1]);
        return cnt;
    }
};



//and all this given constrain 1< word.length() < 100 so we can make this happen 
// and time complexity is O(n) and space complexity is O(1) as we are not using any extra space except for the map which is constant in size (26 letters in the alphabet).
// and we are just traversing the string once to count the characters and then traversing the map to count the unique characters, so the overall time complexity is O(n) where n is the length of the string.
// and we are using unordered_map to store the count of each character, so the space complexity is O(1) as the size of the map is constant (26 letters in the alphabet).

// // good solutions : for better soltuions and explanations, refer to the link below:
//  https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6905499/in-detail-explanation-beginner-easy-code-dry-run-notes-beats-100
//  https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6904590/counting-principle-add-vs-subtract-c-100-py3-1-liner
//  https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6904550/advanced-approach-for-longer-strings-beats-100-featuring-1-liner-regex

// int main() {
//     Solution sol;
//     string word;
//     cin >> word;
//     cout << sol.possibleStringCount(word) << endl;
//     return 0;
// }