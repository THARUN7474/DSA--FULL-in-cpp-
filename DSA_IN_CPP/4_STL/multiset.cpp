#include <iostream>
#include <set>
using namespace std;

void learnmultiset() {
    multiset<int> ms;

    // Insert elements
    ms.insert(1); // {1}
    ms.insert(2); // {1, 2}
    ms.insert(3); // {1, 2, 3}
    ms.emplace(1); // {1, 1, 2, 3}
    ms.emplace(2); // {1, 1, 2, 2, 3}
    ms.emplace(3); // {1, 1, 2, 2, 3, 3}

    // Print elements using iterators
    cout << "Multiset elements: ";
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Find element
    auto it = ms.find(2);
    if (it != ms.end()) {
        cout << "Element 2 found: " << *it << endl;
    } else {
        cout << "Element 2 not found" << endl;
    }

    // Count occurrences of an element
    int count2 = ms.count(2);
    cout << "Element 2 appears " << count2 << " times" << endl;

    // Erase element by value (only one occurrence)
    ms.erase(ms.find(2)); // {1, 1, 2, 3, 3}

    // Erase all occurrences of an element
    ms.erase(1); // {2, 3, 3}

    // Print elements after erase
    cout << "Multiset elements after erase: ";
    for (const auto& elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    // Clear all elements
    ms.clear(); // {}

    // Insert elements again
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);

    // Erase using iterator
    it = ms.find(3);
    if (it != ms.end()) {
        ms.erase(it); // {1, 2}
    }

    // Print elements again after all operations
    cout << "Final multiset elements: ";
    for (const auto& elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    // Lower bound (first element not less than the given value)
    auto lb = ms.lower_bound(2);
    if (lb != ms.end()) {
        cout << "Lower bound of 2: " << *lb << endl;
    }

    // Upper bound (first element greater than the given value)
    auto ub = ms.upper_bound(2);
    if (ub != ms.end()) {
        cout << "Upper bound of 2: " << *ub << endl;
    }

    // Equal range (range of elements equal to a given value)
    auto er = ms.equal_range(2);
    cout << "Equal range for 2: ";
    for (auto it = er.first; it != er.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Time Complexity Information:
    // insert() - O(log n)
    // emplace() - O(log n)
    // find() - O(log n)
    // count() - O(log n)
    // erase(val) - O(log n)
    // erase(it) - O(1)
    // erase(range) - O(k) where k is the number of elements being erased
    // clear() - O(n)
    // lower_bound() - O(log n)
    // upper_bound() - O(log n)
    // equal_range() - O(log n)

    // Other methods specific to multiset:
    // swap(multiset& other) - Swaps the contents of the two multisets.
    // count(val) - Returns the number of elements matching the specified value.

    // Print elements using reverse iterators
    cout << "Multiset elements in reverse order: ";
    for (auto it = ms.rbegin(); it != ms.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    learnmultiset();
    return 0;
}
