#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int andXorOr(vector<int> a) {
    stack<int> st;
    int maxSi = 0;

    for (int i = 0; i < a.size(); i++) {
        while (!st.empty()) {
            int top = st.top();
            int Si = ((top & a[i]) ^ (top | a[i])) & (top ^ a[i]);
            maxSi = max(maxSi, Si);
            if (a[i] < top) {
                st.pop();
            } else {
                break;
            }
        }
        st.push(a[i]);
    }

    return maxSi;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << andXorOr(a) << endl;

    return 0;
}




