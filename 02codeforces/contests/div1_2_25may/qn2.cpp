#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        bool isBeautiful = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool allDivisible = true;
                int currGcd = gcd(arr[i], arr[j]);
                for (int k = 0; k < n; ++k) {
                    if (arr[k] % currGcd != 0) {
                        allDivisible = false;
                        break;
                    }
                }
                if (allDivisible) {
                    isBeautiful = true;
                    break;
                }
            }
            if (isBeautiful)
                break;
        }

        if (isBeautiful)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}