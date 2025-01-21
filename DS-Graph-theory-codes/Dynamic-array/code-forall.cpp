#include <iostream>
#include <stdexcept>
#include <cstring> // For std::memcpy

// A generic dynamic array implementation
template <typename T>
class DynamicArray
{
public:
    // Iterator class for range-based loops
    class Iterator
    {
        T *ptr;

    public:
        explicit Iterator(T *p) : ptr(p) {}
        Iterator &operator++()
        {
            ptr++;
            return *this;
        }
        T &operator*() const { return *ptr; }
        bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
    };

private:
    T *arr;
    size_t len;
    size_t capacity;

    void resize()
    {
        capacity *= 2;
        T *newArr = new T[capacity];
        for (size_t i = 0; i < len; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructors
    DynamicArray(size_t cap = 8) : len(0), capacity(cap)
    {
        if (capacity < 1)
            throw std::invalid_argument("Capacity must be greater than 0");
        arr = new T[capacity];
    }

    DynamicArray(const T *array, size_t n) : len(n), capacity(n)
    {
        arr = new T[capacity];
        std::memcpy(arr, array, n * sizeof(T));
    }

    // Destructor
    ~DynamicArray()
    {
        delete[] arr;
    }

    // Add an element to the array
    void add(const T &elem)
    {
        if (len >= capacity)
        {
            resize();
        }
        arr[len++] = elem;
    }

    // Get the size of the array
    size_t size() const
    {
        return len;
    }

    // Check if the array is empty
    bool isEmpty() const
    {
        return len == 0;
    }

    // Access an element at a specific index
    T &operator[](size_t index)
    {
        if (index >= len)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    // Remove an element at a specific index
    void removeAt(size_t index)
    {
        if (index >= len)
            throw std::out_of_range("Index out of range");
        for (size_t i = index; i < len - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        len--;
    }

    // Remove the first occurrence of a specific element
    bool remove(const T &elem)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (arr[i] == elem)
            {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    // Reverse the array
    void reverse()
    {
        for (size_t i = 0; i < len / 2; i++)
        {
            std::swap(arr[i], arr[len - i - 1]);
        }
    }

    // Sort the array (requires operator< to be defined for T)
    void sort()
    {
        std::sort(arr, arr + len);
    }

    // Binary search for an element (requires a sorted array)
    int binarySearch(const T &key) const
    {
        size_t low = 0, high = len;
        while (low < high)
        {
            size_t mid = (low + high) / 2;
            if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return (low < len && arr[low] == key) ? low : -1;
    }

    // Get an iterator pointing to the beginning of the array
    Iterator begin()
    {
        return Iterator(arr);
    }

    // Get an iterator pointing to the end of the array
    Iterator end()
    {
        return Iterator(arr + len);
    }
};

int main()
{
    // Example with integers
    DynamicArray<int> intArray;
    intArray.add(10);
    intArray.add(20);
    intArray.add(30);
    intArray.add(40);

    // Print using iterator
    std::cout << "Integer array: ";
    for (const auto &val : intArray)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Example with strings
    DynamicArray<std::string> stringArray;
    stringArray.add("hello");
    stringArray.add("world");
    stringArray.add("dynamic");
    stringArray.add("array");

    // Print using iterator
    std::cout << "String array: ";
    for (const auto &val : stringArray)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Testing reverse and binary search
    intArray.reverse();
    std::cout << "Reversed integer array: ";
    for (const auto &val : intArray)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    intArray.sort();
    std::cout << "Sorted integer array: ";
    for (const auto &val : intArray)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    int idx = intArray.binarySearch(20);
    std::cout << "Binary search for 20: " << (idx != -1 ? "Found at index " + std::to_string(idx) : "Not Found") << "\n";

    return 0;
}
