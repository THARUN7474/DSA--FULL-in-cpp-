#include <iostream>
using namespace std;
// Function to print array
void printArray(int ans[], int n)
{
    cout << "The reversed array is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
// Function to reverse array using an auxiliary array
void reverseArray(int arr[], int n)
{
    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[n - i - 1] = arr[i];
    }
    printArray(ans, n);
}

void reverseArray2(int arr[], int n)
{
    int p1 = 0, p2 = n - 1;
    while (p1 < p2)
    {
        swap(arr[p1], arr[p2]);
        p2--;
        p1++;
    }
    printArray(arr, n);
}

void reverseArray3(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    swap(arr[s],arr[e]);
    reverseArray3(arr,s+1,e-1);
}


int main()
{
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};
    reverseArray(arr, n);
    reverseArray2(arr, n);
    reverseArray3(arr,0,n-1);
    return 0;
}
