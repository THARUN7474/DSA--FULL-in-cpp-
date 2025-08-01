// Vectors in STL are basically dynamic arrays that have the ability to change size whenever elements are added or deleted from them. Vector elements can be easily accessed and traversed using iterators. A vector stores elements in contiguous memory locations.
#include <bits/stdc++.h>
using namespace std;

void learnvector() {
    // Initialize an empty vector of integers
    vector<int> v1;

    // Initialize a vector of size 6 with default values (0)
    vector<int> v2(6);

    // Initialize a vector using iterators from another vector
    vector<int> v3(v2.begin(), v2.end() - 1);

    // Initialize a vector with a list of values
    vector<int> v4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Initialize a vector of size 5 with all values set to 100
    vector<int> v5(5, 100);

    // Copy constructor to initialize a vector
    vector<int> v6(v5);

    // Print elements of v6
    for (auto it : v6) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(200);//faster than push_back

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);//see difference here 


    // Initialize a vector with a list of values
    vector<int> v7 = {1, 2, 3, 4, 5, 6, 7};
    vector<int>::iterator it = v7.begin(); // Iterator pointing to the beginning
    vector<int>::iterator it2 = v7.end();  // Iterator pointing to the end (one past the last element)
    // vector<int>::iterator it3 = v7.rbegin(); // Reverse iterator pointing to the last element
    // vector<int>::iterator it4 = v7.rend();   // Reverse iterator pointing to one before the first element


    // even though we access by v[i]
    //iteraters points to the memory location of the data


    // Moving the iterator
    it++;
    cout << *(it) << " " << endl;

    it = it + 2; // Move the iterator two positions forward
    cout << *(it) << " " << endl;

    // Demonstrate various vector member functions
    vector<int> v;

    // Push elements to the vector to avoid out of bounds access
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v.front() << endl;  // Access the first element
    cout << v.back() << endl;   // Access the last element
    cout << v.size() << endl;   // Number of elements in the vector
    cout << v.capacity() << endl; // Current allocated capacity of the vector
    cout << v.max_size() << endl; // Maximum possible number of elements the vector can hold
    cout << v.empty() << endl;    // Check if the vector is empty
    cout << v.data() << endl;     // Get the underlying array pointer
    cout << v.at(2) << endl;      // Access the element at index 2 (bounds-checked)
    cout << v[2] << endl;         // Access the element at index 2 (no bounds-checking)

    // Iterate using iterators
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterate using auto and iterators
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterate using range-based for loop
    for (auto it : v) {
        cout << it << " "; // auto infers the type of it
    }
    cout << endl;

    // Demonstrate vector erase functions
    v.erase(v.begin());              // Erase the first element
    v.erase(v.begin(), v.begin() + 2); // Erase the first two elements

    // Demonstrate vector insert functions
    v.insert(v.begin(), 5);           // Insert 5 at the beginning
    v.insert(v.begin() + 2, 5);       // Insert 5 at index 2
    v.insert(v.begin() + 1, 2, 4);    // Insert 4 twice at index 1
    ;//at where start , no of elements to insert , element to insert

    // Demonstrate inserting a range of elements
    vector<int> c{30, 300};
    v.insert(v.begin(), c.begin(), c.end());

    // Demonstrate assign function
    v.assign(c.begin(), c.end());

    // Demonstrate assignment and swap
    vector<int> vv{1, 2};
    vector<int> vvv;
    vvv.assign(vv.begin(), vv.end());
    for (auto it : vvv) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> vv1 = {3, 4};
    for (auto it : vv) {
        cout << it << " ";
    }
    cout << endl;

    vv1.swap(vv);
    for (auto it : vv) {
        cout << it << " ";
    }
    cout << endl;

    // Demonstrate pop_back function
    vv.pop_back();

    // Demonstrate resizing and shrinking capacity
    vv.resize(10, 100);   // Resize vector to 10 elements, initializing new elements to 100
    vv.shrink_to_fit();   // Shrink capacity to fit the current size

    // Demonstrate reserve function
    vv.reserve(20);   // Reserve space for 20 elements

    // Print final state of the vector
    for (auto it : vv) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    learnvector();
    return 0;
}
