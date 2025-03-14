#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        int a,b;
        cin>>a>>b;
        if(a<=b)cout<<a<<" "<<b<<endl;
        else cout<<b<<" "<<a<<endl;
    }
}