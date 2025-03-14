#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        unordered_set<long long> ele;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ele.insert(a[i]);
        }

        int ml = 0;

        for (int m = 1; m < (1 << n); m++)
        {
            long long cLCM = 1;
            bool valid = true;
            int length = 0;

            for (int i = 0; i < n; i++)
            {
                if (m & (1 << i))
                {
                    cLCM = lcm(cLCM, a[i]);
                    if (cLCM > 1e9)
                    {
                        valid = false;
                        break;
                    }
                    length++;
                }
            }

            if (valid && ele.find(cLCM) == ele.end())
            {
                ml = max(ml, length);
            }
        }

        cout << ml << endl;
    }

    return 0;
}
