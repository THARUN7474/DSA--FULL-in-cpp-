#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int count = 0;

        if (b % 2 == 1)
        {
            count += (b + 1) / 2;
            if (a > 7 * count + 4)
            {
                a -= (7 * count + 4);
                count += (a % 15 == 0) ? a / 15 : (a / 15) + 1;
            }
        }
        else
        {
            count += b / 2;
            if (a > 7 * count)
            {
                a -= 7 * count;
                count += (a % 15 == 0) ? a / 15 : (a / 15) + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}