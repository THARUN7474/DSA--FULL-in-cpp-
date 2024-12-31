#include "bits/stdc++.h"

using namespace std;

string getBinary(int x)
{
    // String s = "";
    // while(x>0){
    //     s = (char)(x%2 + '0') + s;
    //     x = x/2;
    // }
    // return s;

    bitset<16> b(x);
    return b.to_string();
}

int main()
{

    int a = 25;
    int b = 46;
    int c = a & b;
    int d = a | b;
    int e = a ^ b;
    int f = ~a;
    int g = a << 1;
    int h = a << 5;
    int i = a >> 1;
    int j = a >> 5;
    // cout<<getBinary(16)<<endl;
    // cout<<getBinary(160)<<endl;
    cout << getBinary(a) << endl;
    cout << a << endl;
    cout << getBinary(b) << endl;
    cout << b << endl;
    cout << getBinary(c) << endl;
    cout << c << endl;
    cout << getBinary(d) << endl;
    cout << d << endl;
    cout << getBinary(e) << endl;
    cout << e << endl;
    cout << getBinary(f) << endl;
    cout << f << endl;
    cout << getBinary(g) << endl;
    cout << g << endl;
    cout << getBinary(h) << endl;
    cout << h << endl;
    cout << getBinary(i) << endl;
    cout << i << endl;
    cout << getBinary(j) << endl;
    cout << j << endl;

    int num = 4;
    for (int i = 0; i < 32; i++)
    {
        if (num & (1 << i))
        {
            cout << "set" << i << endl;
        }
        else
        {
            cout << "unset" << i << endl;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (num & (1 << i))
        {
            int rs = num ^ (1 << i);
            cout << rs<<" "<<i << endl;
        }
        else
        {
            int rs2 = num | (1 << i);
            cout << rs2 <<" "<<i<< endl;
        }
    }

    return 0;
}