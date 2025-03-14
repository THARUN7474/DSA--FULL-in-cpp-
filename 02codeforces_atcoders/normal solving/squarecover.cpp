#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    // cout << (n + a - 1) / a * (m + a - 1) / a;
    // cout << ((((n-n%a)/a+ 1) + ((m-m%a)/a+ 1) - 1) + ((n-n%a)/a * (m-m%a)/a));
    long long total_flagstones = ceil((double)n / a) * ceil((double)m / a);
    cout << total_flagstones << endl;
}



// import math

// # Read input
// n, m, a = map(int, input().split())

// # Calculate total flagstones needed
// total_flagstones = math.ceil(n / a) * math.ceil(m / a)

// # Output the result
// print(total_flagstones)
