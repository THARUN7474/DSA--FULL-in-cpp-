#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
long long int arr[N];

void print(long long int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n"; // newline after each output array for better readability.  //
}

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     while (m--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         for (int i = a; i <= b; i++)
//         {
//             arr[i] += c;
//         }
//         print(arr,n);
//     }

//     long long mx = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         mx = max(mx, arr[i]);
//     }
//     cout << mx << "\n";
//     return 0;//this TC is -----O(m*n + n)==2*10^5 * 10 ^7====10^ 12---wont get passs---TLE get --for 1 sec run time
// }


int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a] += c;
        arr[b+1] -= c;
        print(arr,n);
    }

    for(int i= 1; i<=n;i++){
        arr[i]+=arr[i-1];
    }
    print(arr,n);

    long long mx = -1;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, arr[i]);
    }
    cout << mx << "\n";
    return 0;//this TC is -----O(m + n)==2*10^5 + 10 ^7====10^7---get passs---TLE wont get --for 1 sec run time
}