#include<bits/stdc++.h>

using namespace std;


int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int l = i; l <= j; l++) {  // Third loop to calculate sum
                sum += arr[l];
            }
            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}


int longestSubarray2(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j]; // Running sum instead of third loop
            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int longestSubarray(vector<int>& arr, int k) {
    map<int, int> mp;
    int s = 0;
    int ml = 0;
    int n = arr.size();
    for(int i =0; i<n;i++){
        s=s+arr[i];
        if(s==k){
            ml = max(ml,i+1);
        }
        int r = s-k;
        if(mp.find(r) != mp.end()){
            ml = max(ml,i- mp[r]);
        }
        if(!mp[s]) mp[s] = i;
    }
    return ml;
}

int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> prefixMap; // {prefix sum -> first occurrence index}
    int sum = 0, maxLength = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If subarray from index 0 to i has sum k
        if (sum == k) {
            maxLength = i + 1;
        }

        // If (sum - k) exists, we found a subarray of sum k
        if (prefixMap.find(sum - k) != prefixMap.end()) {
            maxLength = max(maxLength, i - prefixMap[sum - k]);
        }

        // Store first occurrence of prefix sum
        if (prefixMap.find(sum) == prefixMap.end()) {
            prefixMap[sum] = i;
        }
    }
    return maxLength;
}


// ---

// ## **🔹 Comparison Table**
// | Approach | Time Complexity | Space Complexity | Handles Negative Numbers? |
// |----------|---------------|----------------|-----------------------|
// | **Brute Force (O(N³))** | `O(N³)` | `O(1)` | ✅ Yes |
// | **Optimized Brute Force (O(N²))** | `O(N²)` | `O(1)` | ✅ Yes |
// | **HashMap (Prefix Sum O(N))** | `O(N)` | `O(N)` | ✅ Yes |
// | **Sliding Window (O(N))** | `O(N)` | `O(1)` | ❌ No (only for positives) |

// ---
// ## **🔹 Summary**
// 1. **Brute Force (`O(N³)`)** → Check all subarrays (inefficient).
// 2. **Optimized Brute Force (`O(N²)`)** → Maintain sum while iterating (faster).
// 3. **HashMap (`O(N)`)** → Best for **mixed** numbers (**prefix sum technique**).
// 4. **Sliding Window (`O(N)`)** → Best for **positive-only** arrays (**2-pointer method**).

// ---
// **🎯 Final Recommendation:**
// - **Use HashMap (`O(N)`) for all cases.**
// - **Use Sliding Window (`O(N)`) if array has only positives.**

// ---

