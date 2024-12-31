
// Title: Hashing Negative Numbers: Competitive Programming Tips

// we can use map or unordered_map---stl or

// Hashing negative numbers can lead to unexpected results
// - Represent negative numbers in a way that fits the hashing function
// - Consider using an additional modulus to avoid collisions with negative numbers

// Hash negative numbers using 'Serial method'
// - Utilize the 'Serial method' to hash negative numbers effectively.
// - Understand how to implement this method with the given example (8.28 10).

// Negative numbers can be hashed in competitive programming
// - Negative numbers can be handled by adding a large number to make it positive
// - Learning to hash negative numbers efficiently can be advantageous in competitive programming

// Hashing negative numbers using specific offset
// - Add a fixed offset to make negative numbers positive before hashing
// - Choose the offset carefully to avoid collisions

// Hashing negative numbers creates a new redaction
// - Negative numbers can be handled differently in hashing algorithms.
// - This can be useful for creating unique representations of negative values.

// Understanding hashing for negative numbers in programming.
// - Hashing negative numbers requires handling collisions carefully.
// - Using two's complement can be a helpful approach for hashing negative numbers.

// Understanding the precondition for getting detailed information about Singh
// - The condition of having a thorough understanding of Singh before proceeding
// - Highlighting the significance of gaining detailed knowledge about Singh

// Hashing negative numbers using a specific approach
// - Use a large enough prime number for modulo operation to hash negative numbers
// - Add the prime number to the negative input before taking modulo for hashing

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e7 + 10;
int arr[N];
int fact[N];
int main()
{
    int t;
    cin >> t;
    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % M;
    }//PRE COMUTING THE REQ VALUES FOR BETTER TIME COMPLEXITY
    // for (int i = 0; i < 1000; i++)
        // {
        //     int n;
        //     cin >> n;
        //     arr[n]++;
        // }
        // for (int i = 0; i < 1000; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;--ANOTHER EXAMPLE OF PRE COMPUTING----FOR FREQUENCE WE CAN SAY
    while (t--)
    {
        int n;
        cin >> n;
        cout<< fact[n] << endl;
    }
    return 0;
}

int main()
{
    int N; // Size of the array
    cin >> N;

    vector<int> arr(N);           // Array to store the elements
    unordered_map<int, int> freq; // Hash map to store the frequency of each element

    // Reading the array elements and computing their frequencies
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        freq[arr[i]]++; // Increment the frequency of the element
    }

    int Q; // Number of queries
    cin >> Q;

    // Processing each query
    while (Q--)
    {
        int x; // The integer whose frequency is queried
        cin >> x;
        cout << freq[x] << endl; // Output the precomputed frequency
    }

    return 0;
}

