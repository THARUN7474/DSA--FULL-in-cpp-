#include <bits/stdc++.h>

using namespace std;

// Outside (global level) we can declare arrays up to ~10^7 elements
// int arr[1e7]; // Automatically all elements are set to 0
// For bool arrays, we can declare up to ~10^8 elements


int stringproblems(){
    string s;
    cin >> s;
    cout << s << endl;
    // return 0;
    int hash[256]= {0};
    int hash2[26]={0};
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;//auto casting
        hash2[s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
        cout<<hash2[c-'a']<<endl;
    }
    return 0;
}

int main() {
    // Inside main (local level) we can declare arrays up to ~10^6 elements
    // int arr[1e6] = {0}; // We need to explicitly initialize to 0
    // For bool arrays, we can declare up to ~10^7 elements

    int n;
    cin >> n;  // Read the number of elements in the array

    int sizze; // The maximum value that can be in the array (max range)
    cin >> sizze;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read the array elements
    }

    // Create and initialize a hash array to count occurrences of each element
    int hash[sizze + 1] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;  // Count occurrences of each element
    }

    int a;
    cin >> a;  // Read the number of queries
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;  // Read the element to query
        cout << hash[x];  // Output the count of the queried element
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements in the array

    int arr[n];
    map<int, int> mpp;

    // Read the array elements and populate the map to count occurrences
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mpp[arr[i]]++;  // Increment the count of arr[i] in the map
        // Time Complexity: O(log n) per insertion into the map
    }
    // Total Time Complexity for insertion: O(n log n)

    // Optional: Iterate over the map and print elements with their counts
    // for(auto it : mpp) {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    int q;
    cin >> q;  // Read the number of queries

    while(q--) {
        int number;
        cin >> number;  // Read the query element
        // Fetch and print the count of the query element from the map
        cout << mpp[number] << endl;
        // Time Complexity: O(log n) per query
    }
    // Total Time Complexity for queries: O(q log n)

    return 0;
}

/*
Overall Time Complexity Analysis:
1. Insertion into the map:
    - Each insertion operation in a map takes O(log n) time.
    - With n elements to insert, the total time complexity is O(n log n).

2. Query processing:
    - Each query to fetch the count from the map takes O(log n) time.
    - With q queries, the total time complexity is O(q log n).

3. Combined total time complexity:
    - O(n log n) for insertion + O(q log n) for queries.
    - Final time complexity: O(n log n + q log n).
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements in the array

    int arr[n];
    // Using an unordered_map instead of map
    unordered_map<int, int> mpp;

    // Read the array elements and populate the unordered_map to count occurrences
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mpp[arr[i]]++;  // Increment the count of arr[i] in the unordered_map
        // Time Complexity: O(1) average per insertion into the unordered_map
    }
    // Total Time Complexity for insertion: O(n) average case

    // Optional: Iterate over the unordered_map and print elements with their counts
    // for(auto it : mpp) {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    int q;
    cin >> q;  // Read the number of queries

    while(q--) {
        int number;
        cin >> number;  // Read the query element
        // Fetch and print the count of the query element from the unordered_map
        cout << mpp[number] << endl;
        // Time Complexity: O(1) average per query
    }
    // Total Time Complexity for queries: O(q) average case

    return 0;
}

/*
Difference between map and unordered_map:
1. Data Structure:
   - `map`: Implemented as a balanced binary search tree (typically Red-Black Tree).
   - `unordered_map`: Implemented as a hash table.

2. Order:
   - `map`: Stores elements in sorted order of keys.
   - `unordered_map`: Stores elements in no particular order.

3. Time Complexity:
   - `map`: 
     - Insertion, Deletion, and Lookup: O(log n) time.
   - `unordered_map`: 
     - Insertion, Deletion, and Lookup: O(1) average time, O(n) worst case due to potential hash collisions.

4. Use Case:
   - `map`: Use when you need ordered data or need to maintain a sorted order.
   - `unordered_map`: Use when you need faster access and do not need order.

Overall Time Complexity Analysis (using unordered_map):
1. Insertion into the unordered_map:
    - Each insertion operation in an unordered_map takes O(1) average time.
    - With n elements to insert, the total time complexity is O(n) average case.

2. Query processing:
    - Each query to fetch the count from the unordered_map takes O(1) average time.
    - With q queries, the total time complexity is O(q) average case.

3. Combined total time complexity:
    - O(n) for insertion + O(q) for queries.
    - Final time complexity: O(n + q) average case.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements in the array

    int arr[n];
    // Using an unordered_map which is based on hashing
    unordered_map<int, int> mpp;

    // Read the array elements and populate the unordered_map to count occurrences
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mpp[arr[i]]++;  // Increment the count of arr[i] in the unordered_map
        // Time Complexity: O(1) average per insertion into the unordered_map
        // Insertion Best Case: O(1)
        // Insertion Average Case: O(1)
        // Insertion Worst Case: O(n) due to collisions
    }
    // Total Time Complexity for insertion: O(n) average case

    // Optional: Iterate over the unordered_map and print elements with their counts
    // for(auto it : mpp) {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    int q;
    cin >> q;  // Read the number of queries

    while(q--) {
        int number;
        cin >> number;  // Read the query element
        // Fetch and print the count of the query element from the unordered_map
        cout << mpp[number] << endl;
        // Time Complexity: O(1) average per query
        // Query Best Case: O(1)
        // Query Average Case: O(1)
        // Query Worst Case: O(n) due to collisions
    }
    // Total Time Complexity for queries: O(q) average case

    return 0;
}

/*
Hashing:
- Hashing is the process of mapping data of arbitrary size to fixed-size values using a hash function.
- It allows for efficient data retrieval.

Collisions:
- Collisions occur when two different keys hash to the same index in a hash table.
- They are managed using techniques like chaining and open addressing.

Difference between map and unordered_map:
1. Data Structure:
   - `map`: Implemented as a balanced binary search tree (typically Red-Black Tree).
   - `unordered_map`: Implemented as a hash table.

2. Order:
   - `map`: Stores elements in sorted order of keys.
   - `unordered_map`: Stores elements in no particular order.

3. Time Complexity:
   - `map`: 
     - Insertion, Deletion, and Lookup: O(log n) time.
   - `unordered_map`: 
     - Insertion, Deletion, and Lookup: O(1) average time, O(n) worst case due to potential hash collisions.

4. Use Case:
   - `map`: Use when you need ordered data or need to maintain a sorted order.
   - `unordered_map`: Use when you need faster access and do not need order.

Overall Time Complexity Analysis (using unordered_map):
1. Insertion into the unordered_map:
    - Each insertion operation in an unordered_map takes O(1) average time.
    - With n elements to insert, the total time complexity is O(n) average case.

2. Query processing:
    - Each query to fetch the count from the unordered_map takes O(1) average time.
    - With q queries, the total time complexity is O(q) average case.

3. Combined total time complexity:
    - O(n) for insertion + O(q) for queries.
    - Final time complexity: O(n + q) average case.
*/


