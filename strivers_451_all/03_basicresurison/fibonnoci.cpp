#include<bits/stdc++.h>

using namespace std;


//recursive way
int fib(int n){
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

// Time Complexity: O(2^N) { This problem involves two function calls for each iteration which further expands to 4 function calls and so on which makes worst-case time complexity to be exponential in nature }.

// Space Complexity: O(N) { At maximum there could be N function calls waiting in the recursion stack since we need to calculate the Nth Fibonacci number for which we also need to calculate (N-1) Fibonacci numbers before it }.


//the way---iterative
int fib2(int n){
    int a=0, b=1, c;
    for(int i=2; i<=n; ++i){
        c=a+b;
        a=b;
        b=c;
    }
    return a;
}
// Time Complexity: O(N).As we are iterating over just one for a loop.

// Space Complexity: O(1).


//dp way--used memory
int fib3(int n){
    if(n==0 || n==1) return n;
    vector<int> v(n+1);
    v[0]=0;v[1]=1;
    for(int i=2; i<=n;++i){
        v[i]=v[i-1]+v[i-2];
    }
    return v[n];
// }
// Time Complexity: O(n)+O(n), for calculating and printing the Fibonacci series.

// Space Complexity: O(n), for storing Fibonacci series.
