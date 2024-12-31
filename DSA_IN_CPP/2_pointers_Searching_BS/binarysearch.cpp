#include <bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        if (key < a[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &vec, int key)
{
    int l = 0;
    int h = vec.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (key == vec[mid])
        {
            return mid;
        }
        if (key < vec[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &vec, int key)
{
    int l = 0;
    int h = vec.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (key == vec[mid])
        {
            return mid;
        }
        if (key < vec[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(const vector<int> &vec, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = l + (h - l) / 2; // Corrected calculation

        if (vec[mid] == key)
        {
            return mid;
        }

        if (vec[mid] > key)
        {
            return binarySearchRecursive(vec, l, mid - 1, key);
        }
        else
        {
            return binarySearchRecursive(vec, mid + 1, h, key);
        }
    }

    return -1;
}

// like binary tree divides 2---divide and conquer type
//  tc will be O(log(n)) where n is the number of elements in the tree ==no of comparisions required

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int result = binarySearch(arr, n, key);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int result = binarySearchRecursive(vec, 0, vec.size() - 1, key);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}


// Sure! Let's analyze both the iterative and recursive implementations of the binary search algorithm in terms of time complexity, space complexity, and practical considerations.

// ### 1. Iterative Binary Search

// #### Time Complexity

// - **Best Case**: \(O(1)\) - The key is found at the middle element.
  
// - **Worst Case**: \(O(\log n)\) - Each comparison halves the search space.

// - **Average Case**: \(O(\log n)\)

// #### Space Complexity

// - \(O(1)\) - Constant space is required as no extra memory is used apart from a few variables.

// #### Practical Considerations

// - **Efficiency**: Iterative binary search is efficient and preferred over recursive binary search due to the absence of function call overhead.

// - **Implementation**: The iterative approach is usually more straightforward to implement and understand.

// ### 2. Recursive Binary Search

// #### Time Complexity

// - **Best Case**: \(O(1)\) - The key is found at the middle element.

// - **Worst Case**: \(O(\log n)\) - Each comparison halves the search space.

// - **Average Case**: \(O(\log n)\)

// #### Space Complexity

// - **Stack Space**: \(O(\log n)\) - The maximum depth of the recursive call stack is \(O(\log n)\).

// #### Practical Considerations

// - **Efficiency**: Recursive binary search introduces overhead due to function calls, making it slightly less efficient than the iterative approach.

// - **Readability**: Some developers find the recursive approach more readable and intuitive.

// - **Risk of Stack Overflow**: In cases where the depth of the recursive calls is large, there is a risk of stack overflow.

// ### Conclusion

// Both iterative and recursive binary search algorithms have the same time complexity, but the iterative approach generally offers better performance due to the absence of function call overhead and consumes less memory as it uses constant space. On the other hand, the recursive approach may be easier to understand and implement for some developers but comes with the risk of stack overflow for large input sizes.