#include<bits/stdc++.h>

using namespace std;

// my solution:
// The problem is to find the number of possible original strings that could have been typed given a string `word` where characters can be repeated consecutively. The solution involves counting the number of consecutive characters in the string and returning that count.
class Solution {
public:
    int possibleStringCount(string word) {
        // finding repeated char counts, or finding size - unique chars 
        int n = word.length();
        int k = 1;
        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]){
                k++;
            }
        }
        return k;
    }
};

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