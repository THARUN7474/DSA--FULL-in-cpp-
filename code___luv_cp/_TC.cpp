#include<bits/stdc++.h>
using namespace std;

// Question:
// You are given several test cases. Each test case consists of an array of integers.
// Your task is to compute the sum of the elements in each array and print the results.

// Constraints:
// - 1 <= T <= 100,000 (Number of test cases)
// - 1 <= N <= 100,000 (Number of elements in each array)
// - 1 <= a[i] <= 1,000 (Value of each element in the array)
// - The sum of N over all test cases does not exceed 10^7.------this is important to note as it means that the total number of elements across all test cases will not exceed 10 million.
// - The input is provided in a single line, with the first number being T, followed by N and the elements of the array for each test case.
int main() {
    int t; // Number of test cases
    cin >> t;
    int ct = 0;
    while(t--) {
        int n; // Number of elements in the array
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            int a; // Element of the array
            cin >> a;
            sum += a; // Add element to sum
            ct++; // Increment count of elements processed---no of operatiosn ---after all test cases the value of ct will be equal to the sum of N over all test cases.---time complexwirty will be O(ct)---> her ct is equal to the sum of N over all test cases.< 10e7 as given in the constraints.
        }
        cout << sum << endl; // Output the sum for the current test case
    }
    return 0;
}


//TC is here like O(T*N)-----when T= N = 10e5 then it wont be accepetd in 1s case so 
// we need to reduce it !!

// IN 1 SEC WE CAN DO 10^8 OPERATIONS SO WE NEED TO REDUCE THE TIME COMPLEXITY
// TO O(N) OR O(logN) OR O(1) OR O(NlogN) OR O(sqrt(N)) OR O(N^2) OR O(N^3)