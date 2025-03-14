#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int f = b - 1;
        int k = c - 1;
        vector<int> aa;
        for (int i = 0; i < a; i++)
        {
            int x;
            cin >> x;
            aa.push_back(x);
        }
        int x = aa[f];
        // cout<<"x"<<x<<endl;
        // sort(aa.begin(), aa.end());
        sort(aa.begin(), aa.end(), greater<int>());
        // reverse(aa.begin(), aa.end());
        // for(auto i : aa){
        //     cout<<i<<endl;
        // }
        // cout<<"k"<<k<<endl;
        // cout<<"k+1 "<<k+1<<endl;
        if ((k + 1 != a) ? (x >= aa[k] && x != aa[k + 1]) : (x >= aa[k]))
        {
            cout << "Yes" << endl;
        }
        else if ((k + 1 != a) ? (x == aa[k] && aa[k + 1]) : (x == aa[k]))
        {
            cout << "MAYBE" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

// MAYBE    
// YES
// NO
// YES
// YES
// YES
// MAYBE
// MAYBE
// YES
// YES
// YES
// NO