#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    sum += j;
                    if (j != i / j)
                    {
                        sum += i / j;
                    }
                }
            }
        }
        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        long long ans = ob.sumOfDivisors(N);
        cout << ans << endl;
    }
    return 0;
}

// Expected Approach:
// Intuition:
// Let n = 6,

// => F(1) + F(2) + F(3) + F(4) + F(5) + F(6)

// => 1 will occurs 6 times in F(1), F(2),

// F(3), F(4), F(5) and F(6)

// => 2 will occurs 3 times in F(2), F(4) and

// F(6)

// => 3 will occur 2 times in F(3) and F(6)

// => 4 will occur 1 times in F(4)

// => 5 will occur 1 times in F(5)

// => 6 will occur 1 times in F(6)

// Every number from 1 to N contributes its presence up to the highest multiple less than N. It can easily be observed that number i is occurring only in their multiples less than or equal to n. Thus, we just need to find the count of multiples and then multiply it with i for full contribution in the final sum. It can easily be done in O(1) time by taking the floor of (n / i) and then multiply it with i for the sum.

// Implementation:
// Initialize a variable sum equal to 0.
// Run a loop from 1 to N.
// Add (N / i) * i to the sum.
// Return sum.

// To optimize the code for calculating the sum of divisors for all integers from 1 to 
// 𝑁
// N, we can use a more efficient approach. Instead of iterating through each number and finding its divisors, we can use the property that a divisor d of a number i implies that i is a multiple of d.

// Thus, we can iterate over each potential divisor d and add d to the sum for all multiples of d. This reduces the number of operations significantly and ensures the code runs within the time limits.

class Solution
{
public:
    // Function to calculate the sum of divisors of a given number N.
    long long sumOfDivisors(int N)
    {
        long long sum = 0;

        // iterating from 1 to N.
        for (int i = 1; i <= N; ++i)
            // calculating and accumulating the sum of divisors.
            sum += (N / i) * i;

        // returning the sum of divisors.
        return sum;
    }
};
