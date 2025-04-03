#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}

// Now, if the element is not present, we have to find the nearest greater number of the target number. So, basically, we are trying to find an element arr[ind] >= x and hence the lower bound of the target number i.e. x.

// The lower bound algorithm returns the first occurrence of the target number if the number is present and otherwise, it returns the nearest greater element of the target number.