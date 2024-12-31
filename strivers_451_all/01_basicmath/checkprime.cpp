#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            v.push_back(i);
            if (n / i != i)
            {
                cnt++;
                v.push_back(n / i);
            }
        }
    }

    if (cnt > 2)
    {
        cout << "n given number is not prime" << endl;
    }
    else
    {
        cout << "n given number is prime" << endl;
    }

    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << endl;
    }

    int sum = accumulate(v.begin(), v.end(), 0); // sum of divesors
    cout << "Sum of divisors: " << sum << endl;
}