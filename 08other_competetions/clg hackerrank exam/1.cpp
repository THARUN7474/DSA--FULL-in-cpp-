#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Simple sieve to generate primes up to sqrt(m)
vector<int> simpleSieve(int limit) {
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Segmented sieve to find primes in range [n, m]
vector<int> segmentedSieve(int n, int m) {
    int limit = sqrt(m) + 1;
    vector<int> primes = simpleSieve(limit);

    // Create a boolean array to mark primes in range [n, m]
    vector<bool> isPrime(m - n + 1, true);

    // Mark non-prime numbers in the range [n, m] using primes from the simple sieve
    for (int p : primes) {
        // Find the minimum number in the range [n, m] that is a multiple of p
        int start = max(p * p, n + (p - n % p) % p); // Start from the maximum of p^2 and the nearest multiple of p >= n
        
        for (int j = start; j <= m; j += p) {
            isPrime[j - n] = false;
        }
    }
    
    // Handle special case where n == 1 (1 is not prime)
    if (n == 1) {
        isPrime[0] = false;
    }
    
    // Collect primes in the range [n, m]
    vector<int> primesInRange;
    for (int i = n; i <= m; i++) {
        if (isPrime[i - n]) {
            primesInRange.push_back(i);
        }
    }
    
    return primesInRange;
}

// Function to solve the problem
int solve(int n, int m) {
    vector<int> primesInRange = segmentedSieve(n, m);
    
    int twinPrimeCount = 0;
    for (int i = 1; i < primesInRange.size(); i++) {
        if (primesInRange[i] - primesInRange[i - 1] == 2) {
            twinPrimeCount++;
        }
    }
    
    return twinPrimeCount;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;

    return 0;
}
