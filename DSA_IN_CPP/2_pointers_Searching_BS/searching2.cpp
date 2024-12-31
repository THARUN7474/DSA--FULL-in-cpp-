#include<bits/stdc++.h>

using namespace std;

// int int lo = 0, hi = 4e18,res=hi;
// while(lo<=hi) {
//     int mid = lo + ((hi-lo) >> 1);
//     auto check = [&](int mid) {
//       return (/*condition here*/);
//     };
//     if(check(mid)){
//         res=mid;
//         hi = mid-1;
//     }
//     else {
//         lo = mid+1;
//     }
// }
/**
 * Performs binary search on a sorted vector of integers to find the smallest element.
 * @param v The sorted vector of integers to search in.
 * @param l The lower index of the search range.
 * @param h The higher index of the search range.
 * @return The smallest element in the vector.
 */
int binarysearch(vector<int> v, int l, int h){
    int res = INT_MAX;
    while(l <= h){
        int mid = l + (h - l) / 2;
        if(v[mid] < res)
            res = v[mid];
        if(v[mid] >= v[l])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return res;
}
int binarysearch(vector<int> v, int l, int h){
    int res = INT_MAX;
    while(l <= h){
        int mid = l + (h - l) / 2;
        if(v[mid] < res)
            res = v[mid];
        if(v[mid] >= v[l])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return res;

}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << binarysearch(v, 0, n-1);
    return 0;
}


// fun(params){
//     if(condn met){
//         return ans or save ans;
//     }
//     else{
//         if a[mid] < v
//          then l = mid +1
//         else{
//             r = mid - 1
//         }
//     }
// }