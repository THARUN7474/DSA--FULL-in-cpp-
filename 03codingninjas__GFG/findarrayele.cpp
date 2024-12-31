//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a, int n, int *b, int m) {
        int c = 0; // carry
        int i = n - 1;
        int j = m - 1;
        string s;

        while (i >= 0 && j >= 0) {
            int sum = a[i] + b[j] + c;
            c = sum / 10;
            s.push_back((sum % 10) + '0');
            i--;
            j--;
        }

        while (i >= 0) {
            int sum = a[i] + c;
            c = sum / 10;
            s.push_back((sum % 10) + '0');
            i--;
        }

        while (j >= 0) {
            int sum = b[j] + c;
            c = sum / 10;
            s.push_back((sum % 10) + '0');
            j--;
        }

        if (c > 0) {
            s.push_back(c + '0');
        }
        while(s[s.size()-1] == '0'){
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends