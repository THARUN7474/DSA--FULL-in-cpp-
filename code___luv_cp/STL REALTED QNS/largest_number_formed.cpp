#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });

        if (nums[0] == 0) return "0";

        string res = "";
        for (int num : nums) {
            res += to_string(num);
        }

        return res;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto cmp = [](int &a, int &b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        };

        sort(nums.begin(),nums.end(),cmp);
        
        if(nums[0]==0){
            return "0";
        }

        string res = "";
        for(auto &n : nums){
            res += to_string(n);
        };

        return res;
    }
};


class Solution {
public:
    static bool cmp(string a, string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int n:nums){
            str.push_back(to_string(n));
        }

        sort(str.begin(), str.end(), cmp);
        if(str[0] == "0") return "0";
        string ans = "";

        for(string s:str){
            ans += s;
        }
        return ans;
    }
};


class Solution {
public:
    // Custom comparator to decide the order of two numbers
    bool compare(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int n : nums) {
            strNums.push_back(to_string(n));
        }

        // Bubble sort with custom comparator
        int n = strNums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (!compare(strNums[j], strNums[j + 1])) {
                    swap(strNums[j], strNums[j + 1]);
                }
            }
        }

        // If the largest number is "0", return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        string result = "";
        for (string &s : strNums) {
            result += s;
        }

        return result;
    }
};



class Solution {
public:
    // Custom comparator to decide the order of two numbers
    bool compare(string &a, string &b) {
        return a + b > b + a;
    }

    // Merge function
    void merge(vector<string> &arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        vector<string> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        // Merge the two halves
        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (compare(L[i], R[j])) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge sort function
    void mergeSort(vector<string> &arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strNums;
        for (int n : nums) {
            strNums.push_back(to_string(n));
        }

        // Apply merge sort
        mergeSort(strNums, 0, strNums.size() - 1);

        // If the largest number is "0", return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        string result = "";
        for (string &s : strNums) {
            result += s;
        }

        return result;
    }
};
