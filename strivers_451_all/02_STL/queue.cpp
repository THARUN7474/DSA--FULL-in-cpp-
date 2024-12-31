#include <iostream>
#include <queue>

using namespace std;

void learnqueue() {
    // Create a queue of integers
    queue<int> Q;

    // Push elements into the queue
    Q.push(1); // Queue: 1
    Q.push(2); // Queue: 1, 2
    Q.push(3); // Queue: 1, 2, 3
    Q.push(4); // Queue: 1, 2, 3, 4

    // Get the size of the queue
    cout << "Size of queue: " << Q.size() << endl; // Output: 4

    // Access the front element of the queue
    cout << "Front element: " << Q.front() << endl; // Output: 1

    // Access the back element of the queue
    cout << "Back element: " << Q.back() << endl; // Output: 4

    // Check if the queue is empty
    cout << "Is queue empty? " << (Q.empty() ? "Yes" : "No") << endl; // Output: No

    // Pop the front element from the queue
    Q.pop(); // Queue: 2, 3, 4

    // Access the front element after popping
    cout << "Front element after pop: " << Q.front() << endl; // Output: 2

    // Emplace an element into the queue (similar to push but constructs in place)
    Q.emplace(1); // Queue: 2, 3, 4, 1

    // Print the queue elements (FIFO order)
    cout << "Queue elements: ";
    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl; // Output: 2 3 4 1

    // FIFO (First In First Out) principle followed
}

int main() {
    learnqueue();
    return 0;
}
