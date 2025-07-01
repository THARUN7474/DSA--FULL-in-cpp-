#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int A[N];//global declared anywhere we can use directly no need to pass----aspecially use for cp ,, but not good coding


void greeting(){
    cout<<"hello bro!";
}

int sum(int a, int b){
    return a+b;
}

int digitsum(int n){
    int digit_sum = 0;
    while(n){
        digit_sum = digit_sum + n%10;
        n = n/10;
    }
    return digit_sum;//alwasy return step is last to execute in that scope or funtion 
}

int increment1(int n){
    n++;
    return n;
}
void increment2(int n,int &b, string &s, int a[]){
    n++;
    b++;
    s="i too follow refernce things!!---- only arrays won't followas refernece passing by default ---arrays always passes as references";
    a[0]=14;
}

void swap(int &a, int &b){
    int temp =a;
    a = b;
    b = temp;//we can use xor , +-- , *// all those too a= a^b, b= a^b; a = a^b;
}

int main(){
    // this may not return anything but its okat but not for other funtions this is main spcl funtion

    cout << sum(2,3)<< endl;
    int n,m;
    cin >> n >> m;
    cout << digitsum(n) + digitsum(m)<<endl;

    //referenences or pointers----for cp no much use of pointers we can do all work as refereneces(&var means its reference means itself will cahneg when ever var chanegs) too 
    int a = 10;
    int b = 100;
    cout << a<< '\n';
    a = increment1(a);
    cout <<a<< endl;
    string s = "hello";
    int aa[10];
    aa[0]=4;
    cout <<a << " "<< b<< " "<<s <<" "<< aa[0] <<" "<< aa<< endl;
    increment2(a,b,s,aa);
    cout <<a << " "<< b<< " "<<s <<" "<< aa[0] <<" "<< aa<< endl;
    swap(a,b);//already inbuilt also there same as swap(a,b) like max(a,b)
    cout <<a << " "<< b<< endl;



    // stop declaring thinsg which are need in funtions ----and also dont pass 2d arrays as arguments if needed it is muct to pass a[][size]
    // or pass like this dun(int n. int m , a[n][m])
    //delcare globally to for using funtions but not in main adn passing--- it creats mess
    return 0;// means it executed succesfully meaning full for complier ----or inner parts---but funtn or execution stops at return step
}
