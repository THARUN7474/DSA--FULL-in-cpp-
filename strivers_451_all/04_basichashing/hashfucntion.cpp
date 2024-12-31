#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Define the hash table size
const int HASH_TABLE_SIZE = 1000;

// A hash table using chaining for collision handling
class HashTable {
private:
    // Array of lists to handle collisions
    vector<list<long long>> table;

    // Hash function
    int hashFunction(long long key) {
        return key % HASH_TABLE_SIZE;
    }

public:
    // Constructor
    HashTable() : table(HASH_TABLE_SIZE) {}

    // Insert a key into the hash table
    void insert(long long key) {
        int index = hashFunction(key); // Compute the hash index
        table[index].push_back(key); // Insert the key in the appropriate list
    }

    // Search for a key in the hash table
    bool search(long long key) {
        int index = hashFunction(key); // Compute the hash index
        for (auto& element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            cout << "Index " << i << ":";
            for (auto& element : table[i]) {
                cout << " " << element;
            }
            cout << endl;
        }
    }
};

int main() {
    // Fixed array of long long values
    long long arr[] = {123456789012345, 987654321098765, 112233445566778, 
                       998877665544332, 556677889900112, 778899001122334};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    HashTable ht;

    // Insert the elements into the hash table
    for (int i = 0; i < n; i++) {
        ht.insert(arr[i]);
    }

    // Display the hash table
    ht.display();

    // Search for a few keys in the hash table
    long long searchKeys[] = {123456789012345, 998877665544332, 555555555555555};
    int q = sizeof(searchKeys) / sizeof(searchKeys[0]); // Calculate the number of queries

    for (int i = 0; i < q; i++) {
        bool found = ht.search(searchKeys[i]);
        cout << "Key " << searchKeys[i] << (found ? " found" : " not found") << " in the hash table." << endl;
    }

    return 0;
}

/*
Hashing:
- Hashing is the process of mapping data of arbitrary size to fixed-size values using a hash function.
- It allows for efficient data retrieval.

Hash Function:
- A hash function maps a key to an index in the hash table.
- In this example, we use a simple modulo operation: key % HASH_TABLE_SIZE.
- The choice of HASH_TABLE_SIZE should ideally be a prime number to reduce collisions.

Collisions:
- Collisions occur when two different keys hash to the same index in a hash table.
- In this example, collisions are handled using chaining (each index in the table is a list).

Time Complexity:
1. Insertion:
    - Best Case: O(1) - No collision occurs.
    - Average Case: O(1) - Assuming a good hash function and low load factor.
    - Worst Case: O(n) - All keys hash to the same index.

2. Search:
    - Best Case: O(1) - The key is directly found at the hashed index.
    - Average Case: O(1) - Assuming a good hash function and low load factor.
    - Worst Case: O(n) - All keys hash to the same index.

3. Deletion (not implemented here, but similar to search):
    - Best Case: O(1)
    - Average Case: O(1)
    - Worst Case: O(n)

Overall Time Complexity:
- For n insertions: O(n) average case.
- For q searches: O(q) average case.
- Final time complexity: O(n + q) average case.
*/
