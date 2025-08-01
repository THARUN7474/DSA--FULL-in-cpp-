#include <iostream>
#include <vector>
#include <algorithm>

int main() {

//     1. std::sort()
// Algorithm: Introsort (a hybrid sorting algorithm combining quicksort, heapsort, and insertion sort).
// Description: Sorts the elements in the specified range using a comparison function.
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::sort(v.begin(), v.end());
    for (int num : v) {
        std::cout << num << " ";
    }

//     std::stable_sort()
// Algorithm: Merge sort.
// Description: Sorts the elements in the specified range using a comparison function while maintaining the relative order of equivalent elements.

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::stable_sort(v.begin(), v.end());
    for (int num : v) {
        std::cout << num << " ";
    }

//     std::partial_sort()
// Algorithm: Introsort.
// Description: Sorts the elements in the specified range such that the first N elements are in sorted order.

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int N = 5; // Number of elements to partially sort
    std::partial_sort(v.begin(), v.begin() + N, v.end());
    for (int num : v) {
        std::cout << num << " ";
    }

//     std::nth_element()
// Algorithm: Quickselect (a selection algorithm similar to quicksort).
// Description: Rearranges the elements in the specified range such that the element at the N-th position is the same as it would be if the entire range were sorted, with all elements smaller than the N-th element appearing before it and all elements larger than it appearing after it.

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int N = 5; // Index of the element to find
    std::nth_element(v.begin(), v.begin() + N, v.end());
    std::cout << "The " << N << "-th element is " << v[N] << std::endl;
    
    return 0;
}
