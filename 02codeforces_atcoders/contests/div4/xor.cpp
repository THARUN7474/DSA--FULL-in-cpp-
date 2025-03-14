#include <iostream>
#include <vector>
using namespace std;

void lexicographically_smallest_array(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] ^ arr[j]) < 4)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        lexicographically_smallest_array(arr);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
