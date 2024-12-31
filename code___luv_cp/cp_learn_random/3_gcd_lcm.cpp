#include"bits/stdc++.h"

using namespace std;

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int g =__gcd(a,b);
    int l = (a*b/g);
    cout<<"the gcd of given a and b is"<<g<<"\n";
    cout<<"the lcm of given a and b is"<<l<<endl;
    cout<<"program done";
    return 0;
}