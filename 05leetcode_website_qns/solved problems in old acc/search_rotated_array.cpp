class Solution {
public:
    // Function to find the pivot (the point where the array is rotated)
    int findPivot(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (s == e) {
                // single element
                return s;
            }
            if (mid <= e && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid - 1 >= s && arr[mid - 1] > arr[mid]) {
                return mid - 1;
            }

            if (arr[s] <= arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }

    // Binary search function
    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    // Function to search in rotated sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);
        
        // If we didn't find a pivot, it means the array is not rotated
        if (pivot == -1) {
            return binarySearch(nums, target, 0, n - 1);
        }

        // If we found the pivot, we have 2 ascending arrays
        if (nums[pivot] == target) {
            return pivot;
        }
        if (target >= nums[0]) {
            return binarySearch(nums, target, 0, pivot - 1);
        }
        return binarySearch(nums, target, pivot + 1, n - 1);
    }
};
