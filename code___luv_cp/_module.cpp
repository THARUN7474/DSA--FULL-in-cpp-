#include <bits/stdc++.h>
using namespace std;

// print answer of module of 10^9+7(M)--why we use this?
// because the answer can be very large so we take mod of it with M -
// -to keep the answer in limit and also to avoid overflow of int or long long int
// -this is done in many problems in competitive programming--so we do this here too

// Question:
// You are given several test cases. For each test case, you are given an integer n.
// Your task is to compute the factorial of n and print the result. The factorial of n is defined as:
// n! = n * (n-1) * (n-2) * ... * 1
// Precompute the factorials for numbers up to 100,000 to answer each query in constant time.

// Constraints:
// - 1 <= T <= 100,000 (Number of test cases)
// - 1 <= n <= 100,000 (The number for which factorial is to be computed)

const int M = 1e9 + 7;  // A large prime number (commonly used for modulo operations, though not used here)--MMI --modular multiplicative inverse --this is used to find inverse of a number mod M  SO IT IS IDEAL
const int N = 1e5 + 10; // Size of the factorial array
long long fact[N];      // Array to store precomputed factorials

int main()
{
    fact[0] = fact[1] = 1; // Initial values for factorial of 0 and 1
    for (int i = 2; i < N; ++i)
    {
        fact[i] = (fact[i - 1] * i) % M; // Compute factorial iteratively--and modules it by M -
        // -(a*b)%M== ((a%m)*(b%m))%m --this done at every step of this---same for  addition and subtraction too
        // (a+b)%M== ((a%m)+(b%m))%m --this done at every step of this--same for  multiplication and subtraction too
        // (a-b)%M== ((a%m)-(b%m) + M )%m --this is for - as we add M to make it positive
        // (a/b)%M== ((a%m)*(b^-1)%m)%m --this is for / as we take inverse of b mod M -
        // -and we can do this as M is prime so we can use Fermat's little theorem to find inverse of b mod M
        // b^-1 mod M = b^(M-2) mod M --this is done using fast exponentiation -
        // -or we can use extended euclidean algorithm to find inverse of b mod M----multiplicative inverse

        int t; // Number of test cases
        cin >> t;
        while (t--)
        {
            int n; // Number for which factorial is needed
            cin >> n;
            cout << fact[n] << endl; // Output the precomputed factorial of n--THIS TAKES ALMOST OF o(T)

            // this below on TAKES----O(n^2==T*N) almost
            //  // Compute factorial of n from scratch
            //  long long fact = 1;
            //  for(int i = 1; i <= n; ++i) {
            //      fact = (fact * i) // Compute factorial --IT OVER FLOWS THE INT OR LONG LONG INT FORM 21 FACTORIAL
            //      fact = (fact * i) % M; // Compute factorial modulo M
            //  }

            // cout << fact << endl; // Output the factorial of n
        }
        return 0;
    }
}
