#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int temp;
        int t;
        temp = min(a, b);
        t = max(a, b);
        a = temp;
        b = t;
        temp = min(c, d);
        t = max(c, d);
        c = temp;
        d = t;
        if (a > c && a < d && !(b > c && b < d))
        {
            cout << "YES";
        }
        else if (!(a > c && a < d) && b > c && b < d)
        {
            cout << "YES";
        }
        else
            cout << "NO";
        cout << endl;
    }
}