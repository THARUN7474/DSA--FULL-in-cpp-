#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        int t;
        cin>>t;
        string str;
        cin>>str;
        string o=str;
        if(t%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        int n=0,s=0,e=0,w=0;
        for(int i=0;i<t;i++){
            if(str[i]=='N')n++;
            else if(str[i]=='S')s++;
            else if(str[i]=='E')e++;
            else if(str[i]=='W')w++;
        }
        int len,brr;
        bool l=false,b=false;
        if(n-s>=0){
            len=n-s;
            l=true;
        }
        else if(n-s<0)len = s-n; 
        if(e-w>=0){
            brr = e-w;
            b=true;
        }
        else if(e-w<0)brr = w-e;
        if(len%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        if(brr%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        if(t==2 && str[0]!=str[1]){
            cout<<"NO"<<endl;
            continue;
        }
        if(len==0 && brr==0){
            if(n==0){
                int c=0,d=0;
                for(int i=0;i<t;i++){
                    if(str[i]=='E'&&c<e){
                        o[i]='R';
                        c++;
                    }
                    if(c==e && str[i]=='E')o[i]='H';
                    if(str[i]=='W' && d<e){
                        o[i]='R';
                        d++;
                    }
                    if(d==e && str[i]=='W')o[i]='H';

                }
            }
            else if(e==0){
                int c=0,d=0;
                for(int i=0;i<t;i++){
                    if(str[i]=='N'&&c<n){
                        o[i]='R';
                        c++;
                    }
                    if(c==n && str[i]=='N')o[i]='H';
                    if(str[i]=='S' && d<n){
                        o[i]='R';
                        d++;
                    }
                    if(d==n && str[i]=='S')o[i]='H';

                }
            }
            else{
                for(int i=0;i<t;i++){
                    if(str[i]=='N' || str[i]=='S'){
                        o[i]='R';
                    }
                    else o[i]='H';
                }
            }
            cout<<o<<endl;
            continue;
        }
        if(l&&b){
            int count=0;
            int c=0;
            for(int i=0;i<t;i++){
                if(str[i]=='S')o[i]='R';
                if(str[i]=='W')o[i]='R';
                if(count<=(s+(len/2)) && str[i]=='N'){
                    o[i]='R';
                    count++;
                }
                if(count>(s+(len/2)) && str[i]=='N')o[i]='H';
                if(c<=(w+(brr/2)) && str[i]=='E'){o[i]='R';c++;}
                if(c>(w+(brr/2)) && str[i]=='E')o[i]='H';
            }
        }
        if(l&&!b){
            int count=0;
            int c=0;
            for(int i=0;i<t;i++){
                if(str[i]=='S')o[i]='R';
                if(str[i]=='E')o[i]='R';
                if(count<=(s+(len/2)) && str[i]=='N'){o[i]='R';count++;}
                if(count>(s+(len/2)) && str[i]=='N')o[i]='H';
                if(c<=(e+(brr/2)) && str[i]=='W'){o[i]='R';c++;}
                if(c>(e+(brr/2)) && str[i]=='W')o[i]='H';
            }
        }
        if(!l&&b){
            int count=0;
            int c=0;
            for(int i=0;i<t;i++){
                if(str[i]=='N')o[i]='R';
                if(str[i]=='W')o[i]='R';
                if(count<=(n+(len/2)) && str[i]=='S'){o[i]='R';count++;}
                if(count>(n+(len/2)) && str[i]=='S')o[i]='H';
                if(c<=(w+(brr/2)) && str[i]=='E'){o[i]='R';c++;}
                if(c>(w+(brr/2)) && str[i]=='E')o[i]='H';
            }
        }
        if(!l&&!b){
            int count=0;
            int c=0;
            for(int i=0;i<t;i++){
                if(str[i]=='N')o[i]='R';
                if(str[i]=='E')o[i]='R';
                if(count<=(n+(len/2)) && str[i]=='S'){o[i]='R';count++;}
                if(count>(n+(len/2)) && str[i]=='S')o[i]='H';
                if(c<=(e+(brr/2)) && str[i]=='W'){o[i]='R';c++;}
                if(c>(e+(brr/2)) && str[i]=='W')o[i]='H';
            }
        }
        cout<<o<<endl;

    }
}