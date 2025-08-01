#include <iostream>
#include <map>
using namespace std;

void explainMap() {
    // Declaration of map
    map<int, int> mpp; // Map with int keys and int values
    map<int, pair<int, int>> mpp1; // Map with int keys and pair<int, int> values
    map<pair<int, int>, int> mpp2; // Map with pair<int, int> keys and int values

    // Insert elements into the map
    mpp[1] = 2;           // Inserts {1, 2}
    mpp.emplace(3, 1);    // Inserts {3, 1}
    mpp.insert({2, 4});   // Inserts {2, 4}

    // Corrected usage for mpp2 (map with pair<int, int> keys)
    mpp2[{2, 3}] = 10;    // Inserts {{2, 3}, 10}

    // Printing elements of the map
    for(auto it : mpp) {
        cout << it.first << " " << it.second << endl; // Prints elements in the map
    }

    // Access elements
    cout << mpp[1] << endl; // Outputs value for key 1
    cout << mpp[5] << endl; // Outputs value for key 5 (if key doesn't exist, 0 is returned)

    // Other map methods
    mpp.erase(1);           // Removes element with key 1
    auto it = mpp.find(2);  // Returns iterator to the element with key 2, or mpp.end() if not found
    if (it != mpp.end()) {
        cout << "Found: " << it->first << " " << it->second << endl;
    }

    mpp.clear(); // Clears all elements in the map

    // Lower bound and upper bound
    mpp = {{1, 2}, {2, 3}, {3, 4}}; // Reassign values to the map
    auto lb = mpp.lower_bound(2); // Returns iterator to the first element >= 2
    auto ub = mpp.upper_bound(2); // Returns iterator to the first element > 2
    if (lb != mpp.end()) {
        cout << "Lower bound of 2: " << lb->first << " " << lb->second << endl;
    }
    if (ub != mpp.end()) {
        cout << "Upper bound of 2: " << ub->first << " " << ub->second << endl;
    }

    // Printing final map
    cout << "Final map elements: ";
    for(auto it : mpp) {
        cout << "{" << it.first << ", " << it.second << "} ";
    }
    cout << endl;
}

int main() {
    explainMap();
    return 0;
}

/*
Methods and Usage:
- Insertion:
  - `mpp[key] = value;`: Inserts or updates the value for the given key.
  - `mpp.emplace(key, value);`: Inserts a new element or updates the value for the given key.
  - `mpp.insert({key, value});`: Inserts a new element only if the key does not exist.

- Access and Modifiers:
  - `mpp.erase(key);`: Removes the element with the specified key.
  - `mpp.find(key);`: Returns an iterator to the element if found, else returns `mpp.end()`.
  - `mpp.clear();`: Removes all elements from the map.

- Bounds:
  - `mpp.lower_bound(key);`: Returns an iterator to the first element not less than (i.e. greater or equal to) the given key.
  - `mpp.upper_bound(key);`: Returns an iterator to the first element greater than the given key.

Time Complexity:
- Insertion and Access: O(log n)
- Deletion: O(log n)
- Find: O(log n)
- Lower Bound / Upper Bound: O(log n)
- Clear: O(n)

Notes:
- `map` is typically implemented as a self-balancing binary search tree (e.g., Red-Black tree), which ensures logarithmic time complexity for insertion, deletion, and access operations.
- `map` maintains the order of elements based on the keys. If order is not required, consider using `unordered_map` for average constant time complexity operations.
*/
