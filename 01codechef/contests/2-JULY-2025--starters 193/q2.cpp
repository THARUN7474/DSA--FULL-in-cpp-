#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    if(a==0){
	        cout<< "No\n";
	    }else if(b==0){
	        cout<< "Yes\n";
	    }else{
	        if(b % a == 0 && b/a >=1){
	            cout<< "Yes\n";
	        }else{
	            cout<< "No\n";
	        }
	    }
	}
	return 0;

}
