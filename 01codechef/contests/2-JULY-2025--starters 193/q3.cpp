#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    vector<int> p(a);
	    if(b ==1){
	        for(int i = 0 ; i<a; ++i){
	            p[i] = a-i;
	        }
	    }
	    else if(b==a){
	        for(int i =0;i<a;++i){
	            p[i] = i+1;//1 indexed 
	        }
	    }else {
            int same = a - b + 1;
            for (int i = 0; i < same; ++i) {
                p[i] = same - i;
            }
            for (int i = same; i < a; ++i) {
                p[i] = i + 1;
            }
        }
        for (int i = 0; i < a; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
	}
	return 0;
	
}
