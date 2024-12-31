#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;


//==================================== compute higher powers with mod ===================================
int power(int x, int y, int p =  MOD)
{
    unsigned long long res = 1;

    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// =============================================================================================================

int modInverse(int n, int p=MOD)       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
{
    return power(n, p - 2, p);
}
// can also derive this using extended euclidean... however this has a much simpler code....



int expon(int a, int x){
    if(x==0){
        // cout << 1 << endl;
        return 1;
    }
    if (x%2==0){
        // cout<<"hi"<<endl;
        int b = expon(a,x/2);
        return b*b;
    }
    else{
        // cout<<"hi2"<<endl;
        int c = expon(a,(x-1)/2);
        return c*c*a;
    }
}
int main(){
    int a,x;
    cin>>a>>x;
    cout<<(a%x)<<endl;
    // int res = 1;
    // for(int i=1;i<=x;i++){
    //     res = res*a;
    // }
    // cout<<res<<" "<<endl;

    int res2 = expon(a,x);

    cout <<res2<< " "<<endl;


    // fermats little theorm
}
