#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin >> t;
    // vector<string> str(t);
    while (t--)
    {
        string val;
        cin >> val;
        if (val.size() > 10)
        {
            cout << val[0] << val.size() - 2 << val[val.size() - 1] << endl;
        }
        else
        {
            cout << val << endl;
        }
        // str.push_back(st);
    }
    // for (auto val : str)
    // {
    //     if (val.size() < 10)
    //     {
    //         cout << val << endl;
    //     }
    //     else
    //     {
    //         cout << val[0] << val.size() - 2 << val[val.size() - 1] << endl;
    //     }
    // }
}