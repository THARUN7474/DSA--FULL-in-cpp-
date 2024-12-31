#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

vector<vector<long long>> multiplyMatrix(vector<vector<long long>> &a, vector<vector<long long>> &b)
{
    vector<vector<long long>> res(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % M;
            }
        }
    }
    return res;
}

vector<vector<long long>> matrixPower(vector<vector<long long>> base, int exp)
{
    vector<vector<long long>> res = {{1, 0}, {0, 1}}; // Identity matrix
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = multiplyMatrix(res, base);
        base = multiplyMatrix(base, base);
        exp /= 2;
    }
    return res;
}

int solve(int a, int b, int n)
{
    if (n == 0)
        return a % M;
    if (n == 1)
        return b % M;

    // Transformation matrix
    vector<vector<long long>> T = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrixPower(T, n - 1);

    // arr[n] = result[0][0] * b + result[0][1] * a
    long long ans = (result[0][0] * b % M + result[0][1] * a % M) % M;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << "\n";
    }

    return 0;
}
