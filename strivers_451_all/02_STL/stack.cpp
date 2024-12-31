#include <iostream>
#include <stack>

using namespace std;

void learnstack() {
    // Create a stack of integers
    stack<int> S;

    // Push elements onto the stack
    S.push(1); // Stack: 1
    S.push(2); // Stack: 1, 2
    S.push(3); // Stack: 1, 2, 3
    S.push(4); // Stack: 1, 2, 3, 4

    // Get the size of the stack
    cout << "Size of stack: " << S.size() << endl; // Output: 4

    // Access the top element of the stack
    cout << "Top element: " << S.top() << endl; // Output: 4

    // Check if the stack is empty
    cout << "Is stack empty? " << (S.empty() ? "Yes" : "No") << endl; // Output: No

    // Pop the top element from the stack
    S.pop(); // Stack: 1, 2, 3

    // Access the top element after popping
    cout << "Top element after pop: " << S.top() << endl; // Output: 3

    // Emplace an element onto the stack (similar to push but constructs in place)
    S.emplace(1); // Stack: 1, 2, 3, 1

    // Print the stack elements (LIFO order)
    cout << "Stack elements: ";
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl; // Output: 1 3 2 1

    // LIFO (Last In First Out) principle followed
}

int main() {
    learnstack();
    return 0;
}
