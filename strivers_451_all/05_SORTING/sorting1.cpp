#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void selectionsort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
                min_idx = j;
        }
        swap(v[i], v[min_idx]); // Swapping with the smallest element found so far
        // int temp = arr[mini];
        // arr[mini] = arr[i];
        // arr[i] = temp;
    }
}
// Time complexity: O(N2), (where N = size of the array), for the best, worst, and average cases.
// Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-2 i.e. n-1 times, and for each i, the inner loop j runs from i to n-1. For, i = 0, the inner loop runs n-1 times, for i = 1, the inner loop runs n-2 times, and so on. So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

// Space Complexity: O(1)

void bubbleSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]); // Swapping if current element is greater than next element
        }
    }
}

void bubbleSort2(vector<int> &v)
{
    int n = v.size();
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;

        for (int j = 0; j <= i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]); // Swapping if current element is greater than next element
                didSwap = 1;
                c++;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
    cout << c << "count to get TC " << endl;
}
// Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
// Reason: If we carefully observe, we can notice that the outer loop, say i, is running from n-1 to 0 i.e. n times, and for each i, the inner loop j runs from 0 to i-1. For, i = n-1, the inner loop runs n-1 times, for i = n-2, the inner loop runs n-2 times, and so on. So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

// Space Complexity: O(1)
// Optimized approach (Reducing time complexity for the best case):

// The best case occurs if the given array is already sorted. We can reduce the time complexity to O(N) by just adding a small check inside the loops

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

// Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
// Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-1 i.e. n times, and for each i, the inner loop j runs from i to 1 i.e. i times. For, i = 1, the inner loop runs 1 time, for i = 2, the inner loop runs 2 times, and so on. So, the total steps will be approximately the following: 1 + 2 + 3 +......+ (n-2) + (n-1). The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

// Space Complexity: O(1)

// Best Case Time Complexity:

// The best case occurs if the given array is already sorted. And if the given array is already sorted, the outer loop will only run and the inner loop will run for 0 times. So, our overall time complexity in the best case will boil down to O(N), where N = size of the array.

int main()
{
    vector<int> arr1 = {64, 25, 12, 22, 10, 11, 10};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 6, 7};
    vector<int> arr3 = {7, 6, 5, 4, 3, 2, 2, 1};

    cout << "Original array 1: ";
    print(arr1);
    selectionsort(arr1);
    cout << "Sorted array using Selection Sort: ";
    print(arr1);

    cout << "Original array 2: ";
    print(arr2);
    selectionsort(arr2);
    cout << "Sorted array using Selection Sort: ";
    print(arr2);

    cout << "Original array 3: ";
    print(arr3);
    selectionsort(arr3);
    cout << "Sorted array using Selection Sort: ";
    print(arr3);

    cout << endl;

    arr1 = {64, 25, 12, 22, 10, 11, 10}; // Resetting the arrays
    arr2 = {1, 2, 3, 4, 5, 6, 6, 7};
    arr3 = {7, 6, 5, 4, 3, 2, 2, 1};

    cout << "Original array 1: ";
    print(arr1);
    bubbleSort(arr1);
    cout << "Sorted array using Bubble Sort: ";
    print(arr1);

    cout << "Original array 2: ";
    print(arr2);
    bubbleSort(arr2);
    cout << "Sorted array using Bubble Sort: ";
    print(arr2);

    cout << "Original array 3: ";
    print(arr3);
    bubbleSort(arr3);
    cout << "Sorted array using Bubble Sort: ";
    print(arr3);

    cout << endl;

    arr1 = {64, 25, 12, 22, 10, 11, 10}; // Resetting the arrays
    arr2 = {1, 2, 3, 4, 5, 6, 6, 7};
    arr3 = {7, 6, 5, 4, 3, 2, 2, 1};

    cout << "Original array 1: ";
    print(arr1);
    bubbleSort2(arr1);
    cout << "Sorted array using Bubble Sort 2: ";
    print(arr1);

    cout << "Original array 2: ";
    print(arr2);
    bubbleSort2(arr2);
    cout << "Sorted array using Bubble Sort 2: ";
    print(arr2);

    cout << "Original array 3: ";
    print(arr3);
    bubbleSort2(arr3);
    cout << "Sorted array using Bubble Sort 2: ";
    print(arr3);

    cout << endl;

    arr1 = {64, 25, 12, 22, 10, 11, 10}; // Resetting the arrays
    arr2 = {1, 2, 3, 4, 5, 6, 6, 7};
    arr3 = {7, 6, 5, 4, 3, 2, 2, 1};

    cout << "Original array 1: ";
    print(arr1);
    insertionSort(arr1);
    cout << "Sorted array using Insertion Sort: ";
    print(arr1);

    cout << "Original array 2: ";
    print(arr2);
    insertionSort(arr2);
    cout << "Sorted array using Insertion Sort: ";
    print(arr2);

    cout << "Original array 3: ";
    print(arr3);
    insertionSort(arr3);
    cout << "Sorted array using Insertion Sort: ";
    print(arr3);

    return 0;
}
