#include <iostream>
#include <deque>

using namespace std;

void learnDequeue() {
    // Initialize deques
    deque<int> dq; // empty deque
    deque<int> dq1(6); // deque of size 6 with default values (0)
    deque<int> dq2(dq1.begin(), dq1.end()); // copy elements from dq1
    deque<int> dq3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // initialize with list
    deque<int> dq4(5, 100); // deque of size 5 with all elements 100
    deque<int> dq5(dq4); // copy constructor

    // Print elements of dq5
    for (auto it : dq5) {
        cout << it << " ";
    }
    cout << endl;

    // Modify dq5
    dq5.pop_back(); // remove last element
    dq5.push_back(1); // add 1 at the end
    dq5.pop_front(); // remove first element
    dq5.push_front(2); // add 2 at the front

    // Emplace (insert) elements efficiently
    dq5.emplace_back(22); // add 22 at the end
    dq5.emplace(dq5.begin(), 22); // add 22 at the beginning

    // Insert and erase elements
    dq5.insert(dq5.begin(), 5); // insert 5 at the beginning
    dq5.erase(dq5.begin()); // erase first element
    dq5.erase(dq5.begin(), dq5.begin() + 2); // erase first two elements

    // Clear and assign
    dq5.clear(); // clear all elements
    dq5.assign(dq5.begin(), dq5.end()); // assign range

    // Swap and resize
    dq5.swap(dq5); // swap with itself (no effect)
    dq5.resize(10); // resize to 10 elements (default value 0)
    dq5.resize(10, 100); // resize to 10 elements, new elements are 100

    // Memory management
    dq5.shrink_to_fit(); // reduce capacity to fit size

    // Emplace at specific positions
    dq5.emplace_front(1); // add 1 at the front
    dq5.emplace_back(2); // add 2 at the end
    dq5.emplace(dq5.begin(), 1); // add 1 at the beginning

    // Access front and back elements
    cout << "Front element: " << dq5.front() << endl;
    cout << "Back element: " << dq5.back() << endl;

    // Iterate using iterators
    cout << "Elements in dq5: ";
    for (auto it = dq5.begin(); it != dq5.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Rest of the operations are similar to vector
    // begin(), end(), rbegin(), rend(), insert(), erase(), swap(), clear(), etc.
}

int main() {
    learnDequeue();
    return 0;
}
