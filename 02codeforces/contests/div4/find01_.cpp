#include<iostream>
#include<string>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        string a;
        cin>>a;
        int count =1;
        bool flag = false;
        for(int i=1;i<a.size();i++){
            if(a[i]=='0' && a[i-1] == '1'){
                count ++;
            }
            else if(a[i]=='1' && a[i-1]=='0'){
                if(flag)count++;
                if(!flag)
                flag = true;
            }
        }
        cout<<count<<endl;
    }
}