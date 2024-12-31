#include <iostream>
#include <vector>
using namespace std;




#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > x(n);
        vector < int > p(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        bool find = true;
        
        for (int i = 1; i < n - 1; i++) {
            if (abs(x[i] - x[i + 1]) > p[i] && abs(x[i] - x[i - 1]) > p[i]) {
                find = false;
            }
            else {
                find = true;
            }
        }
        if (abs(x[0] - x[1]) > p[0]) {
            find = false;
        }
        if (abs(x[n - 1] - x[n]) > p[n - 1]) {
            find = false;
        }
        
        if (find) {
            cout << "YES" << endl;

        } else {
            cout << "NO" << endl;
        }
    }


}