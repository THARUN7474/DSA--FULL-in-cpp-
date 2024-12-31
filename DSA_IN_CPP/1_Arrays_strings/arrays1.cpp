#include "bits/stdc++.h"
using namespace std;

void printarray(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inc(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        arr[i]++;
    }
    printarray(arr, s);
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i; // Return index of the key if found
        }
    }
    return -1; // Return -1 if key is not found
}

int main()
{

    cout << "***********************************array lec-1********************************" << endl;
    int arr0[100];
    int arr1[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 15; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // int arr2[10];

    // cout << "taking input array" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> arr2[i];
    // }

    // cout << "printing values" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr2[i] * 2 << " ";
    // }
    // cout << endl;

    int a[5];
    memset(a, 0, sizeof(a)); // Initialize all elements to 0
    for (int i = 0; i < 5; i++)
        cout << a[i] << " "; // Output: 0 0 0 0 0
    cout << endl;

    memset(a, -1, sizeof(a)); // Initialize all elements to -1
    for (int i = 0; i < 5; i++)
        cout << a[i] << " "; // Output: -1 -1 -1 -1 -1
    cout << endl;
    // The reason is that memset works byte by byte.

    cout << "****************************************************************8" << endl;

    int arr3[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int si = 15;

    printarray(arr3, si);
    inc(arr3, si);
    printarray(arr3, si);

    cout << "****************************************************************8" << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int aa = INT_MIN;
    int bb = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > aa)
        {
            aa = arr[i];
        }
        if (arr[i] < bb)
        {
            bb = arr[i];
        }
    }

    cout << "the maxm element in arr is " << aa << " and at position " << linearSearch(arr, size, aa) << endl;
    cout << "the minm element in arr is " << bb << " and at position " << linearSearch(arr, size, bb) << endl;

    int key = 30;
    int result = linearSearch(arr, size, key);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << "****************************************************************8" << endl;

    int arr5[] = {0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1};
    int sze = sizeof(arr5) / sizeof(arr5[0]);
    int counter1 = 0;
    for (int i = 0; i < sze; i++)
    {
        if (arr5[i] != 0)
        {
            counter1++;
        }
    }
    cout << "no of 1's are" << counter1 << endl;
    cout << "no of 0's are" << sze - counter1 << endl;

    cout << "****************************************************************8" << endl;
    cout << "extreme print---2 pointer method basic example" << endl;

    int arr6[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int se = sizeof(arr6) / sizeof(arr6[0]);

    int start = 0;
    int end = se - 1;
    while (true)
    {
        if (start < end)
        {
            cout << arr6[start] << " ";
            cout << arr6[end] << " ";
            start++;
            end--;
        }
        else if (start = end)
        {
            cout << arr6[start] << " ";
            break;
        }
        else
        {
            break;
        }
    }
    cout << endl;
    cout << "****************************************************************8" << endl;
    cout << "reverse array--2 pointer method basic example" << endl;

    int arr7[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    int se7 = sizeof(arr7) / sizeof(arr7[0]);
    int start7 = 0;
    int end7 = se7 - 1;

    printarray(arr7, se7);
    while (true)
    {
        if (start7 < end7)
        {
            // int temp = arr7[start7];
            // arr7[start7] = arr7[end7];
            // arr7[end7] = temp;
            swap(arr7[start7], arr7[end7]);
            start7++;
            end7--;
        }
        else
        {
            break;
        }
    }
    printarray(arr7, se7);
    while (start7 < end7)
    {
        swap(arr7[start7], arr7[end7]);
        start7++;
        end7--;
    }
    printarray(arr7, se7);
}