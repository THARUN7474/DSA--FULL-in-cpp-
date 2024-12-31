#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int ACC = 0;
        bool havinguseful_ele = false;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            ACC += x;
            if (x % 3 == 1)
            {
                havinguseful_ele = true;
            }
        }
        if (ACC % 3 == 0)
        {
            cout << 0 << endl;
        }
        else if (ACC % 3 == 2)
        {
            cout << 1 << endl;
        }
        else
        {
            if (havinguseful_ele == true)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    }
}