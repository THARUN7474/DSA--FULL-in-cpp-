// An unordered set in STL is a container that stores unique elements in no particular order. Every operation on an unordered set takes O(1) complexity in the average case and takes O(n) in the worst case.

// unordered_set<object_type> variable_name;


// object_type can be anything----a int , a vector , string , or evn an unordered_map , unordered_set 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.insert(i);
    }

    cout << "Elements present in the unordered set: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    int n = 2;
    if (s.find(2) != s.end())
        cout << n << " is present in unordered set" << endl;

    s.erase(s.begin());
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "The size of the unordered set is: " << s.size() << endl;

    if (s.empty() == false)
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;
    s.clear();
    cout << "Size of the unordered set after clearing all the elements: " << s.size();
}

#include <iostream>
#include <unordered_set>
using namespace std;

void learnunorderedset() {
    unordered_set<int> us;

    // Insert elements
    us.insert(1); // {1}
    us.insert(2); // {1, 2}
    us.insert(3); // {1, 2, 3}
    us.emplace(4); // {1, 2, 3, 4}
    us.emplace(2); // {1, 2, 3, 4} (duplicate element, will not be added)

    // Print elements using iterators
    cout << "Unordered set elements: ";
    for (auto it = us.begin(); it != us.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Find element
    auto it = us.find(2);
    if (it != us.end()) {
        cout << "Element 2 found: " << *it << endl;
    } else {
        cout << "Element 2 not found" << endl;
    }

    // Erase element by value
    us.erase(2); // {1, 3, 4}

    // Erase using iterator
    it = us.find(3);
    if (it != us.end()) {
        us.erase(it); // {1, 4}
    }

    // Print elements after erase
    cout << "Unordered set elements after erase: ";
    for (const auto& elem : us) {
        cout << elem << " ";
    }
    cout << endl;

    // Clear all elements
    us.clear(); // {}

    // Check if empty
    if (us.empty()) {
        cout << "Unordered set is empty" << endl;
    }

    // Insert elements again
    us.insert(1);
    us.insert(2);
    us.insert(3);

    // Bucket interface
    cout << "Number of buckets: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;
    cout << "Max load factor: " << us.max_load_factor() << endl;

    // Rehashing
    us.rehash(50); // Increases bucket count to at least 50
    cout << "Number of buckets after rehashing: " << us.bucket_count() << endl;

    // Print bucket info
    for (size_t i = 0; i < us.bucket_count(); ++i) {
        cout << "Bucket " << i << " contains: ";
        for (auto it = us.begin(i); it != us.end(i); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // Other methods specific to unordered_set:
    // us.swap(other_set) - Swaps the contents of the two unordered sets.
    // us.reserve(n) - Reserves space for at least n elements.
    // us.max_size() - Returns the maximum possible number of elements.

    // Time Complexity Information:
    // insert() - Average case O(1), worst case O(n)
    // emplace() - Average case O(1), worst case O(n)
    // find() - Average case O(1), worst case O(n)
    // erase(val) - Average case O(1), worst case O(n)
    // erase(it) - O(1)
    // clear() - O(n)
    // rehash() - O(n)

    // Print final elements
    cout << "Final unordered set elements: ";
    for (const auto& elem : us) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    learnunorderedset();
    return 0;
}
