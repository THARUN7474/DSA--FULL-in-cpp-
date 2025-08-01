#include <bits/stdc++.h>

using namespace std;

// Function to merge two halves of the array
void merge(vector<int> &v, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    // Create temporary arrays for left and right halves
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[], if there are any
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[], if there are any
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergesort(vector<int> &a, int l, int h)
{
    if (l >= h)
    {
        return; // Base case: if array has only one element, it is already sorted
    }
    int mid = l + (h - l) / 2; // Find the middle point
    mergesort(a, l, mid); // Sort the first half
    mergesort(a, mid + 1, h); // Sort the second half
    merge(a, l, mid, h); // Merge the sorted halves
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergesort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}