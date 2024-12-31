#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        double a[k], b[k], c[q];
        for (int i = 0; i < k; i++)
            cin >> a[i];
        for (int i = 0; i < k; i++)
            cin >> b[i];
        for (int i = 0; i < q; i++)
            cin >> c[i];
        double speed[k];
        speed[0] = (a[0]) / (b[0]);
        for (int i = 1; i < k; i++)
        {
            speed[i] = (a[i] - a[i - 1]) / (b[i] - b[i - 1]);
        }
        for (int i = 0; i < q; i++)
        {
            int j = k - 1;
            while (a[j] > c[i] && j >= 0)
                j--;
            int time;
            if (j < 0)
                time = c[i] / speed[0];
            else
                time = b[j] + (c[i] - a[j]) / speed[j + 1];
            cout << int(time) << " ";
        }
        cout << endl;
    }
}