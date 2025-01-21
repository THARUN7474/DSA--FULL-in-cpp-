#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class IntArray {
private:
    int* arr;           // Pointer to the dynamic array
    int len;            // Current size of the array
    int capacity;       // Total capacity of the array

    static const int DEFAULT_CAP = 8; // Default initial capacity

public:
    // Default constructor
    IntArray() : len(0), capacity(DEFAULT_CAP) {
        arr = new int[capacity];
    }

    // Constructor with initial capacity
    IntArray(int initialCapacity) : len(0), capacity(initialCapacity) {
        if (initialCapacity < 0) {
            throw std::invalid_argument("Illegal Capacity: " + std::to_string(initialCapacity));
        }
        arr = new int[capacity];
    }

    // Constructor with an existing array
    IntArray(const int* array, int size) : len(size), capacity(size) {
        if (!array) {
            throw std::invalid_argument("Array cannot be null");
        }
        arr = new int[capacity];
        std::copy(array, array + size, arr);
    }

    // Destructor
    ~IntArray() {
        delete[] arr;
    }

    // Returns the size of the array
    int size() const {
        return len;
    }

    // Returns whether the array is empty
    bool isEmpty() const {
        return len == 0;
    }

    // Get an element at a specific index
    int get(int index) const {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // Set an element at a specific index
    void set(int index, int elem) {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[index] = elem;
    }

    // Add an element to the array
    void add(int elem) {
        if (len + 1 >= capacity) {
            resize();
        }
        arr[len++] = elem;
    }

    // Remove an element at a specific index
    void removeAt(int index) {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of bounds");
        }
        std::copy(arr + index + 1, arr + len, arr + index);
        len--;
    }

    // Remove an element by value
    bool remove(int elem) {
        for (int i = 0; i < len; ++i) {
            if (arr[i] == elem) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    // Reverse the array
    void reverse() {
        std::reverse(arr, arr + len);
    }

    // Perform binary search (requires sorted array)
    int binarySearch(int key) const {
        auto it = std::lower_bound(arr, arr + len, key);
        if (it != arr + len && *it == key) {
            return it - arr;
        }
        return -1; // Not found
    }

    // Sort the array
    void sort() {
        std::sort(arr, arr + len);
    }

    // Print the array as a string
    void print() const {
        std::cout << "[";
        for (int i = 0; i < len; ++i) {
            std::cout << arr[i];
            if (i < len - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

private:
    // Resize the array when capacity is exceeded
    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        int* newArr = new int[capacity];
        std::copy(arr, arr + len, newArr);
        delete[] arr;
        arr = newArr;
    }
};

// Example usage
int main() {
    IntArray arr(10);

    arr.add(3);
    arr.add(7);
    arr.add(6);
    arr.add(-2);

    arr.sort();
    arr.print(); // [-2, 3, 6, 7]

    std::cout << "Element at index 2: " << arr.get(2) << std::endl;

    arr.removeAt(1);
    arr.print(); // [-2, 6, 7]

    arr.reverse();
    arr.print(); // [7, 6, -2]

    return 0;
}
