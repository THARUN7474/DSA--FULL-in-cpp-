#include <iostream>   // For input/output
#include <stdexcept>  // For exceptions like std::out_of_range
#include <cstring>    // For memcpy, used in copying memory

// ------------------- 1. Templates -------------------
// Templates in C++ allow us to write generic code that works for any data type.
// For example, `DynamicArray<int>` will work for integers, and `DynamicArray<std::string>` will work for strings.
template <typename T> // 'T' is a placeholder for any data type.
class DynamicArray {
public:
    // ------------------- 2. Nested Classes (Iterator) -------------------
    // A nested class is defined inside another class. Here, we define the `Iterator` class inside `DynamicArray`.
    class Iterator {
        T* ptr; // Pointer to the current element in the array
    public:
        explicit Iterator(T* p) : ptr(p) {} // Constructor to initialize the pointer
        Iterator& operator++() {           // Overloading ++ operator to move to the next element
            ptr++;
            return *this;
        }
        T& operator*() const {             // Overloading * operator to access the value
            return *ptr;
        }
        bool operator!=(const Iterator& other) const { // Overloading != operator for comparison
            return ptr != other.ptr;
        }
    };

private:
    // ------------------- 3. Data Members -------------------
    // Data members are variables defined inside a class.
    T* arr;           // Pointer to dynamically allocated memory for the array
    size_t len;       // Current number of elements in the array
    size_t capacity;  // Maximum capacity of the array before resizing

    // ------------------- 4. Private Methods -------------------
    // Private methods are helper functions that can only be accessed from within the class.
    void resize() {
        // When the array exceeds its capacity, we double the size.
        capacity *= 2;              // Double the capacity
        T* newArr = new T[capacity]; // Allocate new memory
        for (size_t i = 0; i < len; i++) {
            newArr[i] = arr[i];     // Copy elements to the new array
        }
        delete[] arr;               // Free the old memory
        arr = newArr;               // Update the array pointer
    }

public:
    // ------------------- 5. Constructor -------------------
    // A constructor is a special method that gets called when an object is created.
    DynamicArray(size_t cap = 8) : len(0), capacity(cap) {
        if (capacity < 1) throw std::invalid_argument("Capacity must be greater than 0");
        arr = new T[capacity]; // Dynamically allocate memory for the array
    }

    // Constructor to initialize from an existing array
    DynamicArray(const T* array, size_t n) : len(n), capacity(n) {
        arr = new T[capacity]; // Allocate memory
        std::memcpy(arr, array, n * sizeof(T)); // Copy elements using memcpy
    }

    // ------------------- 6. Destructor -------------------
    // A destructor is a special method that gets called when an object goes out of scope.
    ~DynamicArray() {
        delete[] arr; // Free the dynamically allocated memory
    }

    // ------------------- 7. Public Methods -------------------
    // Methods are functions defined inside a class.

    // Add an element to the array
    void add(const T& elem) {
        if (len >= capacity) {
            resize(); // Resize the array if it exceeds capacity
        }
        arr[len++] = elem; // Add the element and increment the length
    }

    // Access an element at a specific index
    T& operator[](size_t index) {
        if (index >= len) throw std::out_of_range("Index out of range");
        return arr[index];
    }

    // Remove an element at a specific index
    void removeAt(size_t index) {
        if (index >= len) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < len - 1; i++) {
            arr[i] = arr[i + 1]; // Shift elements to the left
        }
        len--; // Reduce the length
    }

    // Get the size of the array
    size_t size() const {
        return len;
    }

    // Check if the array is empty
    bool isEmpty() const {
        return len == 0;
    }

    // Reverse the array
    void reverse() {
        for (size_t i = 0; i < len / 2; i++) {
            std::swap(arr[i], arr[len - i - 1]); // Swap elements at the two ends
        }
    }

    // Get an iterator pointing to the beginning of the array
    Iterator begin() {
        return Iterator(arr);
    }

    // Get an iterator pointing to the end of the array
    Iterator end() {
        return Iterator(arr + len);
    }
};

// ------------------- 8. Main Function -------------------
// The main function is where the program starts execution.
int main() {
    // Example with integers
    DynamicArray<int> intArray; // Create a DynamicArray for integers
    intArray.add(10);           // Add elements
    intArray.add(20);
    intArray.add(30);

    // Print the elements using a range-based for loop
    std::cout << "Integer array: ";
    for (const auto& val : intArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Example with strings
    DynamicArray<std::string> stringArray; // Create a DynamicArray for strings
    stringArray.add("Hello");
    stringArray.add("World");
    stringArray.add("Dynamic");

    // Print the elements
    std::cout << "String array: ";
    for (const auto& val : stringArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Reverse the integer array
    intArray.reverse();
    std::cout << "Reversed integer array: ";
    for (const auto& val : intArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
