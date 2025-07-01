
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e7 + 10;
int arr[N];
int fd[N];
int bd[N];

//always take 1 based array or index it helps alot in prefix things 

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        fd[i] = gcd(fd[i-1], arr[i]);
    };
    for(int i = n; i >=1; i--){
        bd[i] = gcd(bd[i+1], arr[i]);
    };


    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        long long ans = 0;
        // for (int i = 1; i <= l-1; i++){
        //     ans = gcd(arr[i], ans);
        // }
        // for (int i = r+1; i <= n; i++){
        //     ans = gcd(arr[i], ans);
        // }
        ans = gcd(fd[l-1],bd[r+1]);
        cout << ans << endl;
    }
}
