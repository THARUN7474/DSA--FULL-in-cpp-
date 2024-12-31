#include<bits/stdc++.h>
using namespace std;

// Question:
// You are given several test cases. For each test case, you are given an integer n.
// Your task is to compute the factorial of n and print the result. The factorial of n is defined as:
// n! = n * (n-1) * (n-2) * ... * 1
// Precompute the factorials for numbers up to 100,000 to answer each query in constant time.

// Constraints:
// - 1 <= T <= 100,000 (Number of test cases)
// - 1 <= n <= 100,000 (The number for which factorial is to be computed)

const int M = 1e9+7; // A large prime number (commonly used for modulo operations, though not used here)
const int N = 1e5+10; // Size of the factorial array
long long fact[N]; // Array to store precomputed factorials

int main() {
    fact[0] = fact[1] = 1; // Initial values for factorial of 0 and 1
    for(int i = 2; i < N; ++i) {
        fact[i] = (fact[i-1] * i)%M; // Compute factorial iteratively--and modules it by M -
        // -(a*b)%M== ((a%m)*(b%m))%m --this done at every step of this
    }

    int t; // Number of test cases
    cin >> t;
    while(t--) {
        int n; // Number for which factorial is needed
        cin >> n;
        cout << fact[n] << endl; // Output the precomputed factorial of n--THIS TAKES ALMOST OF o(T)

        //this below on TAKES----O(n^2==T*N) almost 
        // // Compute factorial of n from scratch
        // long long fact = 1;
        // for(int i = 1; i <= n; ++i) {
        //     fact = (fact * i) % M; // Compute factorial modulo M
        // }
        
        // cout << fact << endl; // Output the factorial of n
    }
    return 0;
}
