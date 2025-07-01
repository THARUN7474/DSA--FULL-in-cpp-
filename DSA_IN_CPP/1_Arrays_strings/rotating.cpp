#include <bits/stdc++.h>
using namespace std;

// Function to rotate array to the left by B positions
vector<int> leftRotate(vector<int>& A, int B) {
    int n = A.size();
    vector<int> result;

    // Normalize B in case it's larger than n
    B = B % n;

    // Left rotation logic:
    // New index of A[i] will be (i + B) % n
    for (int i = 0; i < n; i++) {
        result.push_back(A[(i + B) % n]);
    }

    return result;
}

// Function to rotate array to the right by B positions
vector<int> rightRotate(vector<int>& A, int B) {
    int n = A.size();
    vector<int> result;

    // Normalize B in case it's larger than n
    B = B % n;

    // Right rotation logic:
    // New index of A[i] will be (i + n - B) % n
    for (int i = 0; i < n; i++) {
        result.push_back(A[(i + n - B) % n]);
    }

    return result;
}

// Utility function to print a vector
void printArray(const vector<int>& arr, string label) {
    cout << label << ": ";
    for (int val : arr) cout << val << " ";
    cout << "\n";
}

int main() {
    // Sample input
    vector<int> A = {1, 2, 3, 4, 5, 6};
    int B = 2;

    // Get left and right rotated versions
    vector<int> leftRotated = leftRotate(A, B);
    vector<int> rightRotated = rightRotate(A, B);

    // Output both arrays
    printArray(A, "Original Array");
    printArray(leftRotated, "Left Rotated");
    printArray(rightRotated, "Right Rotated");

    return 0;
}

// We are not moving each element in-place. Instead, we are:

// “Finding the element that should come at the 1st place in the new array, and then just building the new array from there.”



#include <bits/stdc++.h>
using namespace std;

// Utility to reverse a portion of array in-place
void reverse(vector<int> &A, int start, int end) {
    while (start < end) {
        swap(A[start], A[end]);
        start++; end--;
    }
}

// In-place left rotate by B positions
void rotateLeft(vector<int> &A, int B) {
    int n = A.size();
    B = B % n;  // handle if B > n

    reverse(A, 0, B - 1);       // Step 1 1st B elements reverse
    reverse(A, B, n - 1);       // Step 2 last n-B elements reverse
    reverse(A, 0, n - 1);       // Step 3 over all array reversing
}

// In-place right rotate by B positions
void rotateRight(vector<int> &A, int B) {
    int n = A.size();
    B = B % n;
 
    reverse(A, n - B, n - 1);   // Step 1 last B elements reverse
    reverse(A, 0, n - B - 1);   // Step 2 1st n-B elements reverse
    reverse(A, 0, n - 1);       // Step 3 over all array reversing
}

// Driver
int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6};
    int B = 2;

    // Rotate left
    rotateLeft(A, B);
    cout << "Left Rotation: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    // Reset array
    A = {1, 2, 3, 4, 5, 6};

    // Rotate right
    rotateRight(A, B);
    cout << "Right Rotation: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    return 0;
}

