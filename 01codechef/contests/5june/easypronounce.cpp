#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Convert string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
        
        bool found = false;
        for (int i = 0; i <= n - 4; i++) {
            if (find(ch.begin(), ch.end(), s[i]) != ch.end() &&
                find(ch.begin(), ch.end(), s[i + 1]) != ch.end() &&
                find(ch.begin(), ch.end(), s[i + 2]) != ch.end() &&
                find(ch.begin(), ch.end(), s[i + 3]) != ch.end()) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
//this above is 1st approch and it is exactly ooposite of qn asked  for

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Convert string to lowercase (though it's mentioned that the input is already lowercase)
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Vowels set for easy lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        bool found = false;
        int consecutiveConsonants = 0;

        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) == vowels.end()) {
                // It's a consonant
                consecutiveConsonants++;
                if (consecutiveConsonants >= 4) {
                    found = true;
                    break;
                }
            } else {
                // It's a vowel
                consecutiveConsonants = 0;
            }
        }

        if (found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

bool isHardToPronounce(const string& s) {
    string vowels = "aeiou";
    int consecutiveConsonants = 0;

    for (char c : s) {
        if (vowels.find(c) == string::npos) {
            // It's a consonant
            consecutiveConsonants++;
            if (consecutiveConsonants >= 4) {
                return true;
            }
        } else {
            // It's a vowel
            consecutiveConsonants = 0;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (isHardToPronounce(s)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
