#include <iostream>
#include <map>
using namespace std;

void explainMultimap()
{
    // Declaration of multimap
    multimap<int, int> mmp; // Multimap with int keys and int values

    // Insert elements into the multimap
    mmp.insert({1, 2}); // Inserts {1, 2}
    mmp.insert({3, 1}); // Inserts {3, 1}
    mmp.insert({2, 4}); // Inserts {2, 4}
    mmp.insert({1, 5}); // Inserts another {1, 5} (multiple values for key 1 are allowed)
    mmp.insert({2, 3}); // Inserts another {2, 3}

    // Printing elements of the multimap
    for (auto it : mmp)
    {
        cout << it.first << " " << it.second << endl; // Prints elements in the multimap
    }

    // Access elements
    auto range = mmp.equal_range(1); // Get range of elements for key 1
    cout << "Elements with key 1: ";
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << "{" << it->first << ", " << it->second << "} ";
    }
    cout << endl;

    // Other multimap methods
    auto it = mmp.find(2); // Returns iterator to the first element with key 2
    if (it != mmp.end())
    {
        cout << "Found: " << it->first << " " << it->second << endl;
    }

    mmp.erase(1); // Removes all elements with key 1
    mmp.clear();  // Clears all elements in the multimap

    // Inserting elements again for lower_bound and upper_bound examples
    mmp.insert({1, 2});
    mmp.insert({2, 3});
    mmp.insert({3, 4});
    mmp.insert({2, 1});

    // Lower bound and upper bound
    auto lb = mmp.lower_bound(2); // Returns iterator to the first element >= 2
    auto ub = mmp.upper_bound(2); // Returns iterator to the first element > 2
    if (lb != mmp.end())
    {
        cout << "Lower bound of 2: " << lb->first << " " << lb->second << endl;
    }
    if (ub != mmp.end())
    {
        cout << "Upper bound of 2: " << ub->first << " " << ub->second << endl;
    }

    // Printing final multimap
    cout << "Final multimap elements: ";
    for (auto it : mmp)
    {
        cout << "{" << it.first << ", " << it.second << "} ";
    }
    cout << endl;
}

int main()
{
    explainMultimap();
    return 0;
}

/*
Methods and Usage:
- Insertion:
  - `mmp.insert({key, value});`: Inserts a new element. Multiple elements with the same key are allowed.

- Access and Modifiers:
  - `mmp.erase(key);`: Removes all elements with the specified key.
  - `mmp.find(key);`: Returns an iterator to the first element with the specified key, or `mmp.end()` if not found.
  - `mmp.clear();`: Removes all elements from the multimap.
  - `mmp.equal_range(key);`: Returns a pair of iterators representing the range of elements with the specified key.

- Bounds:
  - `mmp.lower_bound(key);`: Returns an iterator to the first element not less than (i.e. greater or equal to) the given key.
  - `mmp.upper_bound(key);`: Returns an iterator to the first element greater than the given key.

Time Complexity:
- Insertion and Access: O(log n)
- Deletion: O(log n)
- Find: O(log n)
- Lower Bound / Upper Bound: O(log n)
- Clear: O(n)

Notes:
- `multimap` is typically implemented as a self-balancing binary search tree (e.g., Red-Black tree), which ensures logarithmic time complexity for insertion, deletion, and access operations.
- Unlike `map`, `multimap` allows multiple elements with the same key.
- `multimap` maintains the order of elements based on the keys.
*/
