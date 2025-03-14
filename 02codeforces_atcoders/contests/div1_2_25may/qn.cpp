#include <iostream>
#include <vector>

using namespace std;

bool canpos(vector<int>& nums) {
    int n = nums.size();
    int count_inversions = 0;

    for (int i = 1; i < n; ++i) {
        if (nums[i-1] > nums[i]) {
            ++count_inversions;
        }
    }

    if (nums[0] < nums[n-1]) {
        ++count_inversions;
    }

    return count_inversions <= 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << (canpos(arr) ? "Yes" : "No") << endl;
    }

    return 0;
}


