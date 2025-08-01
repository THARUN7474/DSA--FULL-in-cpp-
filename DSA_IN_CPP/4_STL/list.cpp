#include <iostream>
#include <list>
using namespace std;

void learnlist() {
    // Initialize an empty list of integers
    list<int> l1;

    // Initialize a list with 6 elements, all initialized to 0
    list<int> l2(6);

    // Initialize a list using iterators from another list
    list<int> l3(l2.begin(), l2.end());

    // Initialize a list with a list of values
    list<int> l4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Initialize a list of size 5 with all values set to 100
    list<int> l5(5, 100);

    // Copy constructor to initialize a list
    list<int> l6(l5);

    // Print elements of l6
    for (auto it : l6) {
        cout << it << " ";
    }
    cout << endl;

    // Initialize a list with a list of values
    list<int> l7 = {1, 2, 3, 4, 5, 6, 7};
    list<int>::iterator it = l7.begin(); // Iterator pointing to the beginning
    list<int>::iterator it2 = l7.end();  // Iterator pointing to the end (one past the last element)
    list<int>::reverse_iterator rit = l7.rbegin(); // Reverse iterator pointing to the last element
    list<int>::reverse_iterator rit2 = l7.rend();  // Reverse iterator pointing to one before the first element

    // Moving the iterator
    it++;
    cout << *(it) << " " << endl;

    advance(it, 2); // Move the iterator two positions forward
    cout << *(it) << " " << endl;

    // Demonstrate various list member functions
    list<int> l;

    // Push elements to the list
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    cout << l.front() << endl;  // Access the first element
    cout << l.back() << endl;   // Access the last element
    cout << l.size() << endl;   // Number of elements in the list
    cout << l.empty() << endl;  // Check if the list is empty

    // Iterate using iterators
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterate using auto and iterators
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterate using range-based for loop
    for (auto it : l) {
        cout << it << " "; // auto infers the type of it
    }
    cout << endl;

    // Demonstrate list erase functions
    l.erase(l.begin());               // Erase the first element
    l.erase(l.begin(), l.begin()++);  // Erase the first two elements

    // Demonstrate list insert functions
    l.insert(l.begin(), 5);            // Insert 5 at the beginning
    l.insert(next(l.begin(), 2), 5);   // Insert 5 at position 2
    l.insert(next(l.begin(), 1), 2, 4); // Insert 4 twice at position 1

    // Demonstrate inserting a range of elements
    list<int> c{30, 300};
    l.insert(l.begin(), c.begin(), c.end());

    // Demonstrate assign function
    l.assign(c.begin(), c.end());

    // Demonstrate assignment and swap
    list<int> ll{1, 2};
    list<int> lll;
    lll.assign(ll.begin(), ll.end());
    for (auto it : lll) {
        cout << it << " ";
    }
    cout << endl;

    list<int> ll1 = {3, 4};
    for (auto it : ll) {
        cout << it << " ";
    }
    cout << endl;

    ll1.swap(ll);
    for (auto it : ll) {
        cout << it << " ";
    }
    cout << endl;

    // Demonstrate pop_back function
    ll.pop_back();

    // Demonstrate resizing (note: resizing adds default-initialized elements)
    ll.resize(10, 100);   // Resize list to 10 elements, initializing new elements to 100

    // Demonstrate clearing all elements
    ll.clear();

    // Print final state of the list
    for (auto it : ll) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    learnlist();
    return 0;
}


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void learnlist() {
    // Initialize lists
    list<int> l1 = {1, 2, 3};
    list<int> l2 = {4, 5, 6};

    // Splice l2 into l1 at second position
    auto it = l1.begin();
    advance(it, 1);
    l1.splice(it, l2);

    // Print l1 after splice
    cout << "l1 after splice: ";
    for (auto &elem : l1) {
        cout << elem << " ";
    }
    cout << endl;

    // Merge two sorted lists
    list<int> l3 = {1, 3, 5};
    list<int> l4 = {2, 4, 6};
    l3.merge(l4);

    // Print l3 after merge
    cout << "l3 after merge: ";
    for (auto &elem : l3) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements
    list<int> l5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l5.remove(5);

    // Print l5 after removing 5
    cout << "l5 after removing 5: ";
    for (auto &elem : l5) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements based on a condition
    l5.remove_if([](int x) { return x % 2 == 0; });

    // Print l5 after removing even numbers
    cout << "l5 after removing evens: ";
    for (auto &elem : l5) {
        cout << elem << " ";
    }
    cout << endl;

    // Make elements unique
    list<int> l6 = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    l6.unique();

    // Print l6 after unique
    cout << "l6 after unique: ";
    for (auto &elem : l6) {
        cout << elem << " ";
    }
    cout << endl;

    // Sort the list
    list<int> l7 = {5, 3, 1, 4, 2};
    l7.sort();

    // Print l7 after sort
    cout << "l7 after sort: ";
    for (auto &elem : l7) {
        cout << elem << " ";
    }
    cout << endl;

    // Reverse the list
    list<int> l8 = {1, 2, 3, 4, 5};
    l8.reverse();

    // Print l8 after reverse
    cout << "l8 after reverse: ";
    for (auto &elem : l8) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    learnlist();
    return 0;
}
