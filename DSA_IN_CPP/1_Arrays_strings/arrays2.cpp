#include "bits/stdc++.h"

using namespace std;

void printvector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void finduniqueele(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << arr[i] << endl;
        }
    }
}
// other way to use find(from next element in array we need to find if there move to next element and repeat if not found it is unique element );
void finduniqueele2(vector<int> &arr)
{
    int a = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        a = a ^ arr[i];
    }
    cout << "unique element" << a << endl;

    // we cant solve all cases like 1 2 2 2 or 3 4 4 4 or 0 0 1 1 2 2  cases lead to misleadinf answer

    // if qn given like every element is 2 times but 1 is not then this is best method
}

int main()
{

    vector<int> arr;

    int si = sizeof(arr);
    int sii = sizeof(arr) / sizeof(int);
    cout << si << endl;
    cout << sii << endl;

    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
    cout << arr.max_size() << endl;

    arr.push_back(1);
    arr.push_back(2);

    int si2 = sizeof(arr);
    int sii2 = sizeof(arr) / sizeof(int);
    cout << si2 << endl;
    cout << sii2 << endl;
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
    cout << arr.max_size() << endl;

    arr.push_back(arr.size());

    int si3 = sizeof(arr);
    int sii3 = sizeof(arr) / sizeof(int);
    cout << si3 << endl;
    cout << sii3 << endl;
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
    cout << arr.max_size() << endl;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(50);

    int si4 = sizeof(arr);
    int sii4 = sizeof(arr) / sizeof(int);
    cout << si4 << endl;
    cout << sii4 << endl;
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
    cout << arr.max_size() << endl;

    for (int i = 0; i < arr.capacity(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    printvector(arr);

    cout << "\n================================" << endl;

    vector<int> arr2(10);
    vector<int> arr3(30, -1);

    cout << arr2.size() << endl;
    cout << arr2.capacity() << endl;
    cout << arr3.size() << endl;
    cout << arr3.capacity() << endl;

    printvector(arr2);
    printvector(arr3);

    vector<int> arr4{10, 30, -1};
    printvector(arr4);

    vector<int> arr5(arr4);
    vector<int> arr6;

    cout << arr4.empty() << endl;
    cout << arr5.empty() << endl;
    cout << arr6.empty() << endl;

    printvector(arr4);
    printvector(arr5);
    printvector(arr6);

    cout << "\n================================" << endl;

    int n;
    cin >> n;
    vector<int> arr7(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr7[i];
    }

    finduniqueele2(arr7);
    finduniqueele(arr7);

    cout << "\n================================" << endl;

    vector<int> arr8{1, 3, 4, 5, 6, 6, 7};
    vector<int> arr9{11, 32, 4, 5, 6, 7, 10, 102, 11};

    vector<int> uninon1;
    int s8 = arr8.size();
    int s9 = arr9.size();
    while (s8--)
    {
        uninon1.push_back(arr8[s8]);
    }
    while (s9--)
    {
        uninon1.push_back(arr9[s9]);
    }

    printvector(uninon1);

    vector<int> is1;

    cout << "\n================================" << endl;
    printvector(is1);
    printvector(arr8);
    printvector(arr9);
    for (int i = 0; i < arr8.size(); i++)
    {
        int ele = arr8[i];
        for (int j = 0; j < arr9.size(); j++)
        {
            if (ele == arr9[j])
            {
                arr9[j] = INT_MIN;
                is1.push_back(ele);
            }
        }
    }
    printvector(is1);
    printvector(arr8);
    printvector(arr9);

    for (auto val : is1)
    {
        cout << val << " ";
    }

    cout << "\n================================" << endl;

    vector<int> uninon2;
    for (int i = 0; i < arr8.size(); i++)
    {
        if (arr8[i] != INT_MIN)
        {
            uninon2.push_back(arr8[i]);
        }
    }
    for (int i = 0; i < arr9.size(); i++)
    {
        if (arr9[i] != INT_MIN)
        {
            uninon2.push_back(arr9[i]);
        }
    }

    printvector(uninon2);
}