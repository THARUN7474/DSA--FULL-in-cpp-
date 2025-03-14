// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int N;
//     cin>>N;
//     while(N--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         if((a+b+c)%2 !=0){
//             cout<<"-1"<<endl;
//             continue;
//         }
//         int count=0;
//         int d=c;
//         for(int i=0;i<d;i++){
//             if(c==0)break;
//             if(a==0&&b==0)break;
//             if(c!=0)
//                 if(b>0){
//                     c--;
//                     b--;
//                     count++;
//                 }
//             if(c!=0)
//                 if(a>0){
//                     c--;
//                     a--;
//                     count++;
//                 }
//                 cout<<a<<b<<c<<endl;
//         }
//         if(a>0&&b>0&&c==0){
//             int min=a;
//             if(a>b)min=b;
//             count+=min;
//         }
//         cout<<count<<endl;
//     }
// }

#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if ((p1 + p2 + p3) % 2 != 0)
        {
            // cout << "-1" << endl;
            continue;
        }
        int c = 0;
        if (p1 + p2 >= p3)
            c = (p1 + p2 + p3) / 2;
        if (p1 + p2 < p3)
        {
            c = (p1 + p2);
        }
        
        // cout << c << endl;
        
    }

    int d = 1 | 2 | 4;
    cout<<d;
}