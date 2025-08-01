// Other functions:
// cbegin() – it refers to the first element of the set.
// cend() – it refers to the theoretical element after the last element of the set.
// rbegin() – it points to the last element of the set.
// rend() – it points to the theoretical element before the first element of the set.
// bucket_size() – gives the total number of elements present in a specific bucket in a set.
// emplace() – to insert an element in the set.
// max_size() – the maximum elements a set can hold.
// max_bucket_count() – to check the maximum number of buckets a set can hold.

#include <iostream>
#include <set>
using namespace std;

void learnset() {
    set<int> s;

    // Insert elements
    s.insert(1); // {1}
    s.insert(2); // {1, 2}
    s.insert(3); // {1, 2, 3}
    s.emplace(1); // {1, 2, 3} (duplicate 1 is ignored)
    s.emplace(2); // {1, 2, 3} (duplicate 2 is ignored)
    s.emplace(3); // {1, 2, 3} (duplicate 3 is ignored)

    // Find element
    auto it = s.find(2);
    if (it != s.end()) {
        cout << "Element 2 found: " << *it << endl;
    } else {
        cout << "Element 2 not found" << endl;
    }

    // Erase element by value
    s.erase(2); // {1, 3}

    // Check if element is removed
    it = s.find(2);
    if (it == s.end()) {
        cout << "Element 2 has been erased" << endl;
    }

    // Clear all elements
    s.clear(); // {}

    // Insert elements again
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // Erase using iterator
    it = s.find(3);
    if (it != s.end()) {
        s.erase(it); // {1, 2}
    }

    // Print elements using iterators
    cout << "Set elements: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Erase range
    s.insert(3);
    s.insert(4);
    s.insert(5); // {1, 2, 3, 4, 5}
    s.erase(s.find(3), s.end()); // {1, 2}

    // Lower bound (first element not less than the given value)
    auto lb = s.lower_bound(2);
    if (lb != s.end()) {
        cout << "Lower bound of 2: " << *lb << endl;
    }

    // Upper bound (first element greater than the given value)
    auto ub = s.upper_bound(2);
    if (ub != s.end()) {
        cout << "Upper bound of 2: " << *ub << endl;
    }

    // Equal range (range of elements equal to a given value)
    auto er = s.equal_range(2);
    if (er.first != s.end()) {
        cout << "Equal range for 2: " << *er.first << endl;
    }

    // Print elements again after all operations
    cout << "Final set elements: ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // Time Complexity Information:
    // insert() - O(log n)
    // emplace() - O(log n)
    // find() - O(log n)
    // erase(val) - O(log n)
    // erase(it) - O(1)
    // erase(range) - O(k) where k is the number of elements being erased
    // clear() - O(n)
    // lower_bound() - O(log n)
    // upper_bound() - O(log n)
    // equal_range() - O(log n)

    // Other methods specific to set:
    // swap(set& other) - Swaps the contents of the two sets.
    // count(val) - Returns the number of elements matching the specified value (0 or 1 for set).
}

int main() {
    learnset();
    return 0;
}
