// #include <iostream>
// #include <cmath>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         long long a;
//         cin >> a;
//         if (a == 1)
//         {
//             cout << 1 << endl;
//         }
//         else
//         {

//             // Find the nearest power of 2 greater than or equal to 'a'
//             long long ans = 1;
//             int i = 1;
//             while (ans <= a)
//             {
//                 i++;
//                 ans = ans << 1; // Corrected bitwise left shift operation
//             }

//             // Calculate twice the nearest power of 2
//             long long ans2 = ans;

//             // Construct vector to represent differences between ans2 - a and powers of 2
//             // cout << i << " " << endl;
//             // cout << ans2 << endl;
//             vector<int> aa(i, 0); // Corrected vector initialization
//             // cout << "ff" << ans2 - a << endl;
//             if ((ans2 - a) % 2 != 0)
//             {
//                 ans2 = ans2 - 1;
//                 aa[0] = -1;
//             }

//             // Find the power of 2 that 'ans2' is
//             int p = log2(ans2 - a); // Include <cmath> header for log2 function
//             // cout << p << endl;
//             if (p < i)
//             {
//                 aa[p] = -1;
//             }

//             aa[i - 1] = 1;

//             // Output the constructed vector
//             for (auto x : aa)
//             {
//                 cout << x << " ";
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        vector<int> a;
        while (x > 0)
        {
            if (x % 2 == 0)
            {
                a.push_back(0);
            }
            else if (x % 4 == 1)
            {
                a.push_back(1);
            }
            else
            {
                a.push_back(-1);
                x += 1;
            }
            x /= 2;
        }

        int n = a.size();
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
