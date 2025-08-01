#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void learnPriorityQueue() {
    // Create a max heap priority queue
    priority_queue<int> pq;
    pq.push(1); // {1}
    pq.push(2); // {2, 1}
    pq.push(30); // {30, 2, 1}
    pq.push(4); // {30, 4, 2, 1}
    pq.emplace(1); // {30, 4, 2, 1, 1}

    // Size of the priority queue
    cout << "Size of pq: " << pq.size() << endl; // Output: 5

    // Top element of the priority queue (max element)
    cout << "Top element of pq: " << pq.top() << endl; // Output: 30

    // Check if the priority queue is empty
    cout << "Is pq empty? " << (pq.empty() ? "Yes" : "No") << endl; // Output: No

    // Pop the top element (max element)
    pq.pop(); // {4, 2, 1, 1}

    // Top element after pop
    cout << "Top element after pop: " << pq.top() << endl; // Output: 4

    // Emplace an element into the priority queue
    pq.emplace(1); // {4, 2, 1, 1, 1}

    // Print the priority queue elements (Max Heap order)
    cout << "Priority queue elements (max heap order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl; // Output: 4 2 1 1 1

    // Min heap can be created by passing greater<int> as the comparator
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(1); // {1}
    mpq.push(2); // {1, 2}
    mpq.push(30); // {1, 2, 30}
    mpq.push(4); // {1, 2, 30, 4}
    mpq.emplace(1); // {1, 1, 30, 4, 2}

    // Print the priority queue elements (Min Heap order)
    cout << "Priority queue elements (min heap order): ";
    while (!mpq.empty()) {
        cout << mpq.top() << " ";
        mpq.pop();
    }
    cout << endl; // Output: 1 1 2 4 30

    // Time Complexity Information:
    // push() - O(log n)
    // emplace() - O(log n)
    // pop() - O(log n)
    // top() - O(1)
    // size() - O(1)
    // empty() - O(1)

    // Other methods specific to priority_queue:
    // swap(priority_queue& other) - Swaps the contents of the two priority queues.
    // Note: We are using the greater<int> comparator for the min heap.
}

int main() {
    learnPriorityQueue();
    return 0;
}
