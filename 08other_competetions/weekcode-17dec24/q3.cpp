#include <bits/stdc++.h>
using namespace std;

void find_leaders(vector<int> &arr)
{
    int n = arr.size();
    int max_so_far = INT_MIN;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= max_so_far)
        {
            max_so_far = arr[i]; // Update max_so_far
        }
        else
        {
            arr[i] = -1; // Mark non-leader elements with -1 (or any invalid value)
        }
    }

    // Optionally remove the -1 values if you only want the leaders in the array
    arr.erase(remove(arr.begin(), arr.end(), -1), arr.end());
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    find_leaders(arr);

    // Print output
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
