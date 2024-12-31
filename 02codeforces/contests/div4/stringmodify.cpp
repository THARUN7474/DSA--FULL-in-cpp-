#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        string a;
        cin>>a;
        char s =a[0];
        bool flag = true;
        int ind=-1;
        for(int i=1;i<a.size();i++){
            if(a[i]!=s){
                flag = false;
                ind = i;
                break;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            a[0] = a[ind];
            a[ind] = s;
            cout<<a<<endl;
        }
    }
}