#include <bits/stdc++.h>

using namespace std;

int linear_search(vector<int> a, int b)
{

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
        {
            return i;
        }
    }
    return -1;
}

void printvectorarray(vector<int> a){
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "enter the element: ";
        cin >> x;
        v.push_back(x);
    }

    printvectorarray(v);
    vector<int> v2;
    v2 = {1, 2, 32, 4, 55, 6, 33, 5, 9};

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    sort(v2.begin(), v2.end());
    for (int num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    int res = linear_search(v, 5);
    cout << "the position of elemeent is(if it is -1 no element found): " << res << endl;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int linearSearch(const string& str, char key) {
//     for (size_t i = 0; i < str.length(); ++i) {
//         if (str[i] == key) {
//             return i;  // Return index of the key if found
//         }
//     }
//     return -1;  // Return -1 if key is not found
// }

// int main() {
//     string str = "hello";
//     char key = 'l';
//     int result = linearSearch(str, key);
//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int linearSearch(const vector<int>& vec, int key) {
//     for (size_t i = 0; i < vec.size(); ++i) {
//         if (vec[i] == key) {
//             return i;  // Return index of the key if found
//         }
//     }
//     return -1;  // Return -1 if key is not found
// }

// int main() {
//     vector<int> vec = {10, 20, 30, 40, 50};
//     int key = 30;
//     int result = linearSearch(vec, key);
//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int linearSearch(int arr[], int size, int key) {
//     for (int i = 0; i < size; ++i) {
//         if (arr[i] == key) {
//             return i;  // Return index of the key if found
//         }
//     }
//     return -1;  // Return -1 if key is not found
// }

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int key = 30;
//     int result = linearSearch(arr, size, key);
//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }
//     return 0;
// }

// Algorithm analysis involves evaluating an algorithm's performance based on factors like time complexity, space complexity, and other practical considerations. Let's analyze the linear search algorithm.

// Time Complexity
// The time complexity of the linear search algorithm is O(n), where n is the number of elements in the collection being searched. This means the time taken by the algorithm increases linearly with the number of elements.

// Best Case:
// The best-case scenario occurs when the element being searched for is the first element in the collection. In this case, the algorithm would execute in constant time, O(1).

// Worst Case:
// The worst-case scenario occurs when the element being searched for is the last element in the collection or is not present in the collection. In this case, the algorithm would have to iterate through all n elements, resulting in a time complexity of O(n).

// Average Case:
// In the average case, the element being searched for could be anywhere in the collection. On average, the algorithm would need to check half of the n elements, resulting in a time complexity of  O(n/2), which is still considered O(n).

// Space Complexity
// The space complexity of the linear search algorithm is O(1) because it requires only a constant amount of additional memory to store the variables used in the algorithm, regardless of the input size.

// Practical Considerations
// Simplicity: Linear search is straightforward and easy to implement.
// Applicability: Suitable for small datasets or when the dataset is unordered.
// Performance: Not efficient for large datasets compared to other search algorithms like binary search on sorted arrays.

// Conclusion
// Linear search is a simple and straightforward searching algorithm with a time complexity of
// O(n). While it's easy to understand and implement, it may not be the most efficient choice for large datasets or when performance is a critical factor. For large datasets, algorithms with better time complexities, like binary search O(logn)) on sorted arrays, are more suitable.