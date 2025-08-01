The problem asks us to generate all possible orderings (permutations) of a list of distinct integers. A common and effective way to solve this is by using **backtracking**.

---

## **Concept**

1. **Backtracking**:  
   Backtracking is a general algorithm for finding all (or some) solutions to problems that incrementally build candidates to the solutions. It works by exploring a decision tree:
   - **Choice**: At each step, you have several options (e.g., which number to add next).
   - **Constraint**: You have to follow the rule that no number is used more than once in a permutation.
   - **Goal**: When the current permutation reaches the same length as the input array, it is a complete permutation.

2. **How It Works Here**:  
   - **Start** with an empty permutation.
   - **Iterate** over the numbers. For each number that hasn't been used yet, add it to the current permutation.
   - **Recurse**: Call the function recursively to fill the next position.
   - **Backtrack**: After recursion, remove the last added number and mark it as unused so that other permutations can be explored.
   - **Collect** the complete permutation when its length equals the input array's length.

---

## **Code Explanation**

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result; // Stores all the complete permutations

    // Helper function to perform backtracking
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr) {
        // Base case: if current permutation is complete
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        // Try every number in the input list
        for (int i = 0; i < nums.size(); i++) {
            // If this number is already used in the current permutation, skip it
            if (used[i]) continue;
            // Mark the number as used
            used[i] = true;
            // Add it to the current permutation
            curr.push_back(nums[i]);
            // Recurse to fill the next position
            backtrack(nums, used, curr);
            // Backtrack: remove the last number added and mark it as unused
            curr.pop_back();
            used[i] = false;
        }
    }
    
    // Main function that initializes the process
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;                  // Current permutation being built
        vector<bool> used(nums.size(), false); // Tracks which numbers are used
        backtrack(nums, used, curr);         // Start backtracking
        return result;                       // Return all the permutations collected
    }
};
```

### **Step-by-Step Walkthrough**

1. **Result Storage**:  
   We maintain a `result` vector to store all complete permutations.

2. **Backtracking Helper Function (`backtrack`)**:
   - **Base Case**:  
     When the `curr` (current permutation) size equals the size of `nums`, we have a complete permutation. It is added to `result`.
   - **Iteration**:  
     We loop over every index `i` in `nums`.
   - **Skip Used Numbers**:  
     If `used[i]` is `true`, it means `nums[i]` is already in the current permutation, so we skip it.
   - **Choose & Explore**:
     - Mark `nums[i]` as used.
     - Add `nums[i]` to the current permutation (`curr`).
     - Recursively call `backtrack` to build the permutation further.
   - **Backtrack**:
     - After recursion, remove `nums[i]` from `curr`.
     - Mark `nums[i]` as unused so that it can be used in a different permutation branch.

3. **Main Function (`permute`)**:
   - Initializes an empty current permutation (`curr`) and a `used` vector (all set to false).
   - Calls the `backtrack` function.
   - Returns the `result` vector containing all permutations.

---

## **Conclusion**

This solution uses backtracking to explore all possibilities by choosing a number, recursing to complete the permutation, and then undoing the choice (backtracking) to try other numbers. Since the input numbers are distinct, we simply use a `bool` array to track usage.

This is a clean and efficient way to generate all permutations of a given array.


Let's walk through a dry-run of the backtracking solution using the input `nums = [1, 2, 3]`.

We'll use these key variables:

- **`curr`**: The current permutation being built.
- **`used`**: A boolean vector tracking which numbers are already in `curr`.
- **`result`**: The collection of all complete permutations.

### **Initial Setup**

- **nums**: `[1, 2, 3]`
- **used**: `[false, false, false]`
- **curr**: `[]`
- **result**: `[]`

We call `backtrack(nums, used, curr)`.

---

### **Level 0 (curr = []):**

**Loop over all indices: i = 0, 1, 2**

#### **Iteration 1: i = 0**

- **Choose**: `nums[0] = 1`
- **Update**:
  - `curr` becomes `[1]`
  - `used` becomes `[true, false, false]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [1]`

---

### **Level 1 (curr = [1]):**

**Loop over indices: i = 0, 1, 2**

- **i = 0**: Skip (already used)
  
#### **Iteration 1.2: i = 1**

- **Choose**: `nums[1] = 2`
- **Update**:
  - `curr` becomes `[1, 2]`
  - `used` becomes `[true, true, false]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [1, 2]`

---

### **Level 2 (curr = [1, 2]):**

**Loop over indices: i = 0, 1, 2**

- **i = 0**: Skip (used)
- **i = 1**: Skip (used)

#### **Iteration 2.3: i = 2**

- **Choose**: `nums[2] = 3`
- **Update**:
  - `curr` becomes `[1, 2, 3]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [1, 2, 3]`

---

### **Level 3 (curr = [1, 2, 3]):**

- Now, `curr.size() == nums.size()`, so we have a complete permutation.
- **Add**: `[1, 2, 3]` to `result`.

- **Result now**: `[[1, 2, 3]]`
- **Backtrack**: Return to Level 2.

---

### **Backtracking from Level 2:**

- **Revert** the choice at Level 2:
  - Remove the last element (`3`) from `curr` → `curr` becomes `[1, 2]`.
  - Mark `used[2]` as `false` → `used` becomes `[true, true, false]`.
- Continue loop in Level 2: No more indices left.
- **Return** to Level 1.

---

### **Back at Level 1 (curr = [1]):**

After finishing iteration i = 1, back in Level 1, continue with next index.

#### **Iteration 1.3: i = 2**

- **Choose**: `nums[2] = 3`
- **Update**:
  - `curr` becomes `[1, 3]`
  - `used` becomes `[true, false, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [1, 3]`

---

### **Level 2 (curr = [1, 3]):**

**Loop over indices: i = 0, 1, 2**

- **i = 0**: Skip (used)
  
#### **Iteration 2.2: i = 1**

- **Choose**: `nums[1] = 2`
- **Update**:
  - `curr` becomes `[1, 3, 2]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [1, 3, 2]`

---

### **Level 3 (curr = [1, 3, 2]):**

- `curr.size() == nums.size()`, so add `[1, 3, 2]` to `result`.

- **Result now**: `[[1, 2, 3], [1, 3, 2]]`
- **Backtrack**: Return to Level 2.

---

### **Backtracking from Level 2 (curr = [1, 3]):**

- **Revert** the choice:
  - Remove `2` → `curr` becomes `[1, 3]`.
  - Mark `used[1]` as `false` → `used` becomes `[true, false, true]`.
- Continue loop in Level 2: i = 2 is skipped (used).
- **Return** to Level 1.

---

### **Backtracking from Level 1 (curr = [1]):**

- **Revert** the choice at Level 1:
  - Remove `3` → `curr` becomes `[1]`.
  - Mark `used[2]` as `false` → `used` becomes `[true, false, false]`.
- No more indices to try at Level 1.
- **Return** to Level 0.

---

### **Back at Level 0 (curr = []):**

After finishing iteration i = 0 in Level 0, continue with next index.

#### **Iteration 0.2: i = 1**

- **Choose**: `nums[1] = 2`
- **Update**:
  - `curr` becomes `[2]`
  - `used` becomes `[false, true, false]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [2]`

---

### **Level 1 (curr = [2]):**

**Loop over indices: i = 0, 1, 2**

#### **Iteration 1.1: i = 0**

- **Choose**: `nums[0] = 1`
- **Update**:
  - `curr` becomes `[2, 1]`
  - `used` becomes `[true, true, false]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [2, 1]`

---

### **Level 2 (curr = [2, 1]):**

**Loop over indices: i = 0, 1, 2**

- **i = 0**: Skip (used)
- **i = 1**: Skip (used)

#### **Iteration 2.3: i = 2**

- **Choose**: `nums[2] = 3`
- **Update**:
  - `curr` becomes `[2, 1, 3]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [2, 1, 3]`

---

### **Level 3 (curr = [2, 1, 3]):**

- `curr` is complete. Add `[2, 1, 3]` to `result`.

- **Result now**: `[[1, 2, 3], [1, 3, 2], [2, 1, 3]]`
- **Backtrack**: Return to Level 2.

---

### **Backtracking from Level 2 (curr = [2, 1]):**

- **Revert**:
  - Remove `3` → `curr` becomes `[2, 1]`.
  - Mark `used[2]` as `false` → `used` becomes `[true, true, false]`.
- End of loop in Level 2; return to Level 1.

---

### **Back at Level 1 (curr = [2]):**

After finishing i = 0, continue in Level 1.

#### **Iteration 1.2: i = 1**

- **Skip**: i = 1 is already used.

#### **Iteration 1.3: i = 2**

- **Choose**: `nums[2] = 3`
- **Update**:
  - `curr` becomes `[2, 3]`
  - `used` becomes `[false, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [2, 3]`

---

### **Level 2 (curr = [2, 3]):**

**Loop over indices: i = 0, 1, 2**

#### **Iteration 2.1: i = 0**

- **Choose**: `nums[0] = 1`
- **Update**:
  - `curr` becomes `[2, 3, 1]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [2, 3, 1]`

---

### **Level 3 (curr = [2, 3, 1]):**

- `curr` is complete. Add `[2, 3, 1]` to `result`.

- **Result now**: `[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1]]`
- **Backtrack**: Return to Level 2.

---

### **Backtracking from Level 2 (curr = [2, 3]):**

- **Revert**:
  - Remove `1` → `curr` becomes `[2, 3]`.
  - Mark `used[0]` as `false` → `used` becomes `[false, true, true]`.
- End of loop at Level 2; return to Level 1.

---

### **Backtracking from Level 1 (curr = [2]):**

- **Revert**:
  - Remove `3` → `curr` becomes `[2]`.
  - Mark `used[2]` as `false` → `used` becomes `[false, true, false]`.
- End of loop at Level 1; return to Level 0.

- **Revert**:
  - Remove `2` → `curr` becomes `[]`.
  - Mark `used[1]` as `false` → `used` becomes `[false, false, false]`.

---

### **Back at Level 0 (curr = []):**

#### **Iteration 0.3: i = 2**

- **Choose**: `nums[2] = 3`
- **Update**:
  - `curr` becomes `[3]`
  - `used` becomes `[false, false, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [3]`

---

### **Level 1 (curr = [3]):**

**Loop over indices: i = 0, 1, 2**

#### **Iteration 1.1: i = 0**

- **Choose**: `nums[0] = 1`
- **Update**:
  - `curr` becomes `[3, 1]`
  - `used` becomes `[true, false, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [3, 1]`

---

### **Level 2 (curr = [3, 1]):**

**Loop over indices: i = 0, 1, 2**

- **i = 0**: Skip (used)
  
#### **Iteration 2.2: i = 1**

- **Choose**: `nums[1] = 2`
- **Update**:
  - `curr` becomes `[3, 1, 2]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [3, 1, 2]`

---

### **Level 3 (curr = [3, 1, 2]):**

- `curr` is complete. Add `[3, 1, 2]` to `result`.

- **Result now**: `[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2]]`
- **Backtrack**: Return to Level 2.

---

### **Backtracking from Level 2 (curr = [3, 1]):**

- **Revert**:
  - Remove `2` → `curr` becomes `[3, 1]`.
  - Mark `used[1]` as `false` → `used` becomes `[true, false, true]`.
- End loop at Level 2; return to Level 1.

---

### **Back at Level 1 (curr = [3]):**

After finishing iteration for i = 0, continue:

#### **Iteration 1.2: i = 1**

- **Choose**: `nums[1] = 2`
- **Update**:
  - `curr` becomes `[3, 2]`
  - `used` becomes `[false, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [3, 2]`

---

### **Level 2 (curr = [3, 2]):**

**Loop over indices: i = 0, 1, 2**

#### **Iteration 2.1: i = 0**

- **Choose**: `nums[0] = 1`
- **Update**:
  - `curr` becomes `[3, 2, 1]`
  - `used` becomes `[true, true, true]`
- **Call**: `backtrack(nums, used, curr)` with `curr = [3, 2, 1]`

---

### **Level 3 (curr = [3, 2, 1]):**

- `curr` is complete. Add `[3, 2, 1]` to `result`.

- **Result now**:  
  ```
  [[1, 2, 3],
   [1, 3, 2],
   [2, 1, 3],
   [2, 3, 1],
   [3, 1, 2],
   [3, 2, 1]]
  ```
- **Backtrack**: Return to Level 2.

---

### **Final Backtracking:**

- Backtrack through all remaining calls until `curr` is empty and all choices have been explored.

---

### **Conclusion**

The complete set of permutations generated is:
- `[1, 2, 3]`
- `[1, 3, 2]`
- `[2, 1, 3]`
- `[2, 3, 1]`
- `[3, 1, 2]`
- `[3, 2, 1]`

This dry-run shows how the backtracking algorithm systematically chooses a number, recurses to build the permutation, and then undoes the choice (backtracks) to try another possibility.

---

### **For a Simpler Example ([0, 1]):**

1. **Initial**: `curr = []`, `used = [false, false]`.
2. **Iteration i = 0**: Choose `0`, update: `curr = [0]`, `used = [true, false]`.
   - Recurse: At next level, choose `1`, complete permutation `[0, 1]`.
   - Backtrack to try next possibility.
3. **Iteration i = 1**: Choose `1`, update: `curr = [1]`, `used = [false, true]`.
   - Recurse: Choose `0`, complete permutation `[1, 0]`.

**Result**: `[[0, 1], [1, 0]]`.

This dry-run demonstrates the systematic approach of the backtracking algorithm for generating all permutations.

### **Using `next_permutation` in C++ STL**
C++ provides an inbuilt function **`next_permutation`**, which generates the **next lexicographically greater permutation** of a string. This allows us to generate all permutations without recursion.

---

### **Code (Using `next_permutation`)**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> ans;
        sort(s.begin(), s.end()); // Ensure the starting permutation is the smallest lexicographically
        do {
            ans.push_back(s); // Store the current permutation
        } while (next_permutation(s.begin(), s.end())); // Generate next permutation
        
        return ans;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);

        // Print results
        for (auto &str : ans) {
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

---

### **How `next_permutation` Works**
1. **Sort the input string** (ensuring permutations are generated in lexicographical order).
2. **Iteratively call `next_permutation`** until all unique permutations are generated.
3. **Store and return permutations** in a sorted manner.

---

### **Time Complexity Analysis**
- **Sorting the string**: \( O(N \log N) \)
- **Generating each permutation**: \( O(N!) \)  
- **Overall complexity**: \( O(N! \cdot N) \) (as `next_permutation` runs in \( O(N) \))

---

### **Example Walkthrough**
#### **Input**
```
1
AAB
```
#### **Lexicographically Sorted Permutations**
```
AAB → ABA → BAA
```
#### **Output**
```
AAB ABA BAA
```

---

### **Why `next_permutation`?**
✅ **No recursion needed**  
✅ **Handles duplicate characters efficiently**  
✅ **Lexicographically sorted output**  

This method is more efficient than the recursive backtracking approach if sorting is acceptable.

Let me know if you need further clarifications! 🚀

### **Brute Force Approach to Generate All Permutations**
The brute force method involves:
1. Generating all **possible permutations** of the given string.
2. Using a **set** to store unique permutations (to avoid duplicates).
3. Sorting the results before returning.

---

### **Code (Brute Force with Set)**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generatePermutations(string s, set<string> &uniquePerms, int index) {
        if (index == s.size()) {
            uniquePerms.insert(s); // Store unique permutations
            return;
        }

        for (int j = index; j < s.size(); j++) {
            swap(s[index], s[j]); // Swap
            generatePermutations(s, uniquePerms, index + 1); // Recursive call
            swap(s[index], s[j]); // Backtrack
        }
    }

public:
    vector<string> findPermutation(string s) {
        set<string> uniquePerms;
        generatePermutations(s, uniquePerms, 0);

        // Convert set to vector and sort lexicographically
        vector<string> result(uniquePerms.begin(), uniquePerms.end());
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);

        // Print results
        for (auto &str : ans) {
            cout << str << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

---

### **Time Complexity Analysis**
- **Generating all permutations**: \( O(N!) \)  
- **Using a set (to remove duplicates)**: \( O(N! \log N!) \)  
- **Sorting the unique permutations**: \( O(N! \log N!) \)  
- **Final complexity**: \( O(N! \log N!) \)

---

### **Example Walkthrough**
#### **Input**
```
1
AAB
```
#### **Recursive Calls**
```
AAB → ABA → AAB (Duplicate)
→ BAA → BAA (Duplicate)
```
#### **Output**
```
AAB ABA BAA
```

---

### **Optimizations**
✅ **Use a boolean array instead of swapping** to track used characters.  
✅ **Use `next_permutation` in C++ STL** for an alternative approach.

This brute force approach ensures we **generate all unique permutations** in a **sorted order**.

Let me know if you need further clarifications! 🚀