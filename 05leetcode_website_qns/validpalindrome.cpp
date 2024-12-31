#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() -1;
        while(i<=j){
            if(!isalnum(s[i])){ i++; continue;}
            if(!isalnum(s[j])) {j--; continue;}
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++;j--;
            }
            
        }
        return true;
    }
};

// Approach
// If a character is not alphanumeric we can simply ignore it and update our pointer to next character (for both pointers)

// and then we check by converting the alphanumeric character to lowercase (tolower() function on numbers has no change)
// if those two are not equal then return false(not palindrome)
// else update both pointers and continue.

// Finally after all checking if reach at last then string must be a valid palindrome so return true.

// Complexity
// Time complexity:O(n)
// Space complexity:O(1) since only use two pointers