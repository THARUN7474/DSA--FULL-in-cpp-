#include"bits/stdc++.h"

using namespace std;

int main(){
    // int num;
    // // cout<< "enter the number:";
    // cin >> num;
    // for(int i =2; i<num-1;i++){
    //     if(num % i==0){
    //         cout << "not prime\n";
    //         return 0;
    //     }
    // }//basic like bruteforce method
    // cout<< "prime\n";
    // return 1;

    int num;
    // cout<< "enter the number:";
    cin >> num;
    for(int i =2; i*i <= num-1;i++){
        if(num % i==0){
            cout << "not prime\n";
            return 0;
        }
    }
    cout<< "prime\n";
    return 1;
}