#include"bits/stdc++.h"

using namespace std;

int main()
{
    int sz= 26;
    vector<bool> check(sz,1);//here initially marked all to 1 as primes 
    check[0]=check[1]=0;

    for(int i =2; i<sz;i++){
        if(check[i]==0) continue;//checking if already a composite then no need to entire loop for marking its multiples
        for(int j =i*i;j<sz;j+=i){
            check[j]=0;//here only marking the composite numbers by iterating the multiples of that number like 2----4,6,8,10-----upto sz
            //as if i is 12 then already upto 144 somethings before 12 check those so we started at 12*12 and 144,156---upto sz
        }
    }//as primes are already marked as 1 so we will leftout with primes only 
    for(int i=1;i<sz;i++){
        cout<<i<<" "<< check[i]<<"\n";
    }
    int val=0;
    for(int i =0; i<sz;i++){
        // int val=0;
        // cin>> val;
        if(check[i]==0){
            cout<<"composite\n";
            val++;
        }
        else cout<<"prime\n";
    }
    cout << "the number of composites are" << val;
    cout << "the number of primes are" << sz-val;

    return 0;
}