#include <bits/stdc++.h>
using namespace std;

// Class to solve the problem
class Solution {
public:
    // Helper function to check if a given limit is valid
    bool valid(vector<int> arr, int n, int m, int limit) {
        int students = 1; // Number of students required
        int currentPages = 0;

        for (int i = 0; i < n; i++) {
            // If a single book has more pages than the limit, return false
            if (arr[i] > limit) return false;

            // Check if adding the current book exceeds the limit
            if (currentPages + arr[i] <= limit) {
                currentPages += arr[i];
            } else {
                // Assign the current book to a new student
                students++;
                currentPages = arr[i];
                
                // If the number of students exceeds 'm', return false
                if (students > m) return false;
            }
        }
        return true;
    }

    // Function to find the minimum number of pages
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // If there are more students than books, return -1

        int start = 0; // Minimum possible value (0 or smallest element)
        int end = accumulate(arr.begin(), arr.end(), 0); // Sum of all pages
        int ans = -1;

        // Binary search to find the minimum value
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If it's valid to allocate books with 'mid' as the maximum pages
            if (valid(arr, n, k, mid)) {
                ans = mid;   // Update the answer
                end = mid - 1; // Search in the left half for a smaller valid value
            } else {
                start = mid + 1; // Search in the right half
            }
        }
        return ans;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();

    while (test_case--) {
        int d; // Number of students
        vector<int> arr; // Array to hold pages in books
        string input;

        // Reading the array of book pages
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Reading the number of students
        getline(cin, input);
        ss.clear();
        ss.str(input);
        ss >> d;

        // Solving the problem
        Solution ob;
        int ans = ob.findPages(arr, d);

        // Output the result
        cout << ans << endl;
        cout << "~\n";
    }
    return 0;
}
