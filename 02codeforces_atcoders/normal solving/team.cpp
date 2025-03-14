#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int ss = 0;
    while (t--)
    {
        int s = 0;
        int i = 3;
        while (i--)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                s += 1;
            }
        }
        if (s >= 2)
        {
            ss += 1;
        }
    }
    cout << ss << endl;
    return 0;
}