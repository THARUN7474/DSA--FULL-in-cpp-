#include <iostream>
#include <unordered_map>
using namespace std;

void explainUnorderedMap() {
    // Declaration of unordered_map
    unordered_map<int, int> ump; // Unordered map with int keys and int values

    // Insert elements into the unordered_map
    ump[1] = 2;       // Inserts {1, 2}
    ump.emplace(3, 1);// Inserts {3, 1}
    ump.insert({2, 4});// Inserts {2, 4}
    ump[4] = 10;      // Inserts {4, 10}

    // Printing elements of the unordered_map
    for (auto it : ump) {
        cout << it.first << " " << it.second << endl; // Prints elements in the unordered_map
    }

    // Access elements
    cout << "Element with key 2: " << ump[2] << endl; // Access value with key 2

    // Check if a key exists
    if (ump.find(3) != ump.end()) {
        cout << "Key 3 found with value: " << ump[3] << endl;
    } else {
        cout << "Key 3 not found" << endl;
    }

    // Erase elements
    ump.erase(1); // Removes element with key 1
    ump.erase(ump.begin()); // Removes element at the beginning

    // Other unordered_map methods
    cout << "Size of unordered_map: " << ump.size() << endl; // Prints size of unordered_map
    ump.clear(); // Clears all elements in the unordered_map

    // Inserting elements again for demonstration
    ump[1] = 2;
    ump[2] = 3;
    ump[3] = 4;
    ump[2] = 1; // Updates value for key 2

    // Iterating over the unordered_map
    cout << "Final unordered_map elements: ";
    for (auto it : ump) {
        cout << "{" << it.first << ", " << it.second << "} ";
    }
    cout << endl;

    // Count function
    cout << "Count of key 2: " << ump.count(2) << endl; // Returns 1 if key 2 exists, else 0

    // Bucket interface
    cout << "Number of buckets: " << ump.bucket_count() << endl;
    cout << "Load factor: " << ump.load_factor() << endl;
    cout << "Max load factor: " << ump.max_load_factor() << endl;
    cout << "Bucket size of key 1: " << ump.bucket_size(1) << endl;
    cout << "Bucket of key 1: " << ump.bucket(1) << endl;
}

int main() {
    explainUnorderedMap();
    return 0;
}

/*
Methods and Usage:
- Insertion:
  - `ump[key] = value;`: Inserts or updates the value associated with the key.
  - `ump.emplace(key, value);`: Inserts a new element if the key does not already exist.
  - `ump.insert({key, value});`: Inserts a new element if the key does not already exist.

- Access and Modifiers:
  - `ump.erase(key);`: Removes the element with the specified key.
  - `ump.find(key);`: Returns an iterator to the element with the specified key, or `ump.end()` if not found.
  - `ump.clear();`: Removes all elements from the unordered_map.
  - `ump.size();`: Returns the number of elements in the unordered_map.
  - `ump.empty();`: Checks if the unordered_map is empty.
  - `ump.count(key);`: Returns the number of elements with the specified key (0 or 1 for unordered_map).

- Bucket Interface:
  - `ump.bucket_count();`: Returns the number of buckets.
  - `ump.load_factor();`: Returns the load factor (number of elements / number of buckets).
  - `ump.max_load_factor();`: Returns the maximum load factor.
  - `ump.bucket_size(bucket);`: Returns the number of elements in the specified bucket.
  - `ump.bucket(key);`: Returns the bucket number for the specified key.

Time Complexity:
- Average Case:
  - Insertion, Access, Deletion: O(1)
  - Find: O(1)
  - Count: O(1)
- Worst Case:
  - Insertion, Access, Deletion: O(n)
  - Find: O(n)
  - Count: O(n)

Notes:
- `unordered_map` is implemented using hash tables.
- Average case time complexity for operations is O(1), but worst-case complexity can be O(n) due to hash collisions.
- Does not maintain any order of elements.
- Allows unique keys only.
*/
