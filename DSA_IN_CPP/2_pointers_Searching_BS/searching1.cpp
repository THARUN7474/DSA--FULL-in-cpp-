#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int mind = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int firstocc(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int lastocc(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 6, 8, 10, 13, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int find = binary_search(arr, arr + n, key);
    cout << key << " found " << find;
    cout << endl;
    int index = bs(arr, n, key);
    if (index == -1)
    {
        cout << "key not found" << endl;
    }
    else
    {
        cout << key << " found at index " << index << endl;
    }

    int ar[] = {1, 2, 3, 3, 4, 5, 5, 5, 5, 5, 6, 6, 7, 9, 10};
    int n1 = sizeof(ar) / sizeof(ar[0]);
    int key1 = 5;
    int index1 = firstocc(ar, n1, key1);
    cout << key1 << " found at index " << index1 << endl;
    int index2 = lastocc(ar, n1, key1);
    cout << key1 << " found at index " << index2 << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    reverse(ar, ar + n1);
    for (int i = 0; i < n1; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    // int index3 = firstocc(ar, n1, key1);
    int index3 = firstocc(ar, n1, key1);
    cout << key1 << " found at index " << index3 << endl;
    return 0;
}