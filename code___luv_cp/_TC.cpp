#include<bits/stdc++.h>
using namespace std;

// Question:
// You are given several test cases. Each test case consists of an array of integers.
// Your task is to compute the sum of the elements in each array and print the results.

// Constraints:
// - 1 <= T <= 100,000 (Number of test cases)
// - 1 <= N <= 100,000 (Number of elements in each array)
// - 1 <= a[i] <= 1,000 (Value of each element in the array)
// - The sum of N over all test cases does not exceed 10^7.
int main() {
    int t; // Number of test cases
    cin >> t;
    while(t--) {
        int n; // Number of elements in the array
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            int a; // Element of the array
            cin >> a;
            sum += a; // Add element to sum
        }
        cout << sum << endl; // Output the sum for the current test case
    }
    return 0;
}


//TC is here like O(T*N)-----when T= N = 10e5 then it wont be accepetd in 1s case so 
// we need to reduce it !!