
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e7 + 10;
int arr[N];
int sum[N];

// for 2nd qn
const int NN = 1e3 + 1;
int dp[NN][NN];
int pf[NN][NN];


//always take 1 based array or index it helps alot in prefix things 


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        long long ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans += arr[i];//THIS GIVES TC -- 0(N*T)---10^10 ---NOT DONE IN 1S DO USE PRE CPMUTATION TECH
        }
        ans = sum[r] - sum[l - 1];//this is O(N)---10^5
        cout << ans << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dp[i][j];
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + dp[i][j]; 
        }
    }
    int t;
    cin>> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for (int i = a; i <= c; i++){
            for (int j = b; j <= d; j++){
                ans += dp[i][j];
            }
        }//TC --- O(N^2) + O(T*N^2) SO WE NEED TO REDUCE SO USING PRE COMPUTAION
        ans = pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];
        cout << ans << endl;

    }
}
