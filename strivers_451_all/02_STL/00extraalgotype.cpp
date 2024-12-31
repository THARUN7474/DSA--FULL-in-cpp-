#include <bits/stdc++.h>
using namespace std;

// Custom comparator function for sorting pairs
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
    {
        return true;
    }
    else if (p1.second == p2.second)
    {
        if (p1.first > p2.second)
            return true;
    }
    return false;
}

void explainExtra()
{
    // Sorting array a from index 2 to 4
    int a[] = {5, 4, 3, 2, 1};
    sort(a + 2, a + 4);

    // Sorting entire array a in ascending order
    sort(a, a + 5);

    // Sorting vector v in ascending order
    vector<int> v = {5, 4, 3, 2, 1};
    sort(v.begin(), v.end());

    // Sorting array a in descending order
    sort(a, a + 5, greater<int>());

    // Sorting an array of pairs according to second element
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    // Sort it according to the second element
    // If second element is the same, then sort it according to the first element in descending order
    sort(arr, arr + 3, comp);

    // Displaying sorted pairs
    for (auto p : arr)
    {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    // Count the number of set bits in an integer
    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << "Number of set bits in " << num << " is " << cnt << endl;

    // Count the number of set bits in a long long integer
    long long num_ll = 165786578687;
    int cnt_ll = __builtin_popcountll(num_ll);
    cout << "Number of set bits in " << num_ll << " is " << cnt_ll << endl;

    // Generate all permutations of a string
    string s = "123";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Reverse all permutations of a string
    sort(s.begin(), s.end(), greater<char>());
    do
    {
        cout << s << endl;
    } while (prev_permutation(s.begin(), s.end()));

    // Reverse a vector
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end());

    // Find minimum and maximum in a range
    int minElement = *min_element(a, a + 5);
    int maxElement = *max_element(a, a + 5);
    cout << "Min element: " << minElement << endl;
    cout << "Max element: " << maxElement << endl;

    // Accumulate (Sum) elements
    int sum = accumulate(a, a + 5, 0);
    cout << "Sum of elements: " << sum << endl;

    // Count occurrences of an element
    int countOf2 = count(vec.begin(), vec.end(), 2);
    cout << "Count of 2s: " << countOf2 << endl;

    // Remove duplicates from a vector
    vector<int> vec2 = {1, 2, 2, 3, 4, 4, 5};
    sort(vec2.begin(), vec2.end());
    vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());

    // Rotate a vector
    rotate(vec.begin(), vec.begin() + 2, vec.end());  // Rotates left by 2 positions

    // Merge two sorted ranges
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};
    vector<int> result(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

    // Find lower bound and upper bound
    vector<int> vec3 = {1, 2, 2, 3, 4, 5};
    auto lb = lower_bound(vec3.begin(), vec3.end(), 2);  // First position of 2
    auto ub = upper_bound(vec3.begin(), vec3.end(), 2);  // First position greater than 2
    cout << "Lower bound of 2: " << (lb - vec3.begin()) << endl;
    cout << "Upper bound of 2: " << (ub - vec3.begin()) << endl;
}

int main()
{
    explainExtra();
    return 0;
}



