#include<bits/stdc++.h>

using namespace std;

void increment(int *ppp){
    (*ppp)++;//directly changes value at address given by ppp pointer variable
}

int main(){
    // 8 bits ==byte ----address formate ---each byte as hex formated --address
    int x=4;//-------4 bytes is allocated for this x var-----1,2,3,4--bytes ==x (1st byte address is used to call or trigger x)
    cout << &x<< endl;//----addreess of 1st byte of int 
    //memory address is stored using pointers
    int y=5;
    int *p_y;//it also stored as 4 byets as it is int ---it also has its address
    p_y = &y;//it stores address ----as pointer used to store addresses
    //to access pointer addressed value we use dereferencing(*)
    cout << y<< " "<< *p_y<<"  "<< p_y<<endl;// will give value at that pointing address
    p_y = p_y +1;//here bytes added it goes to 5th byte from 1st byte---goes to next block
    int a[10];
    cout << a << " "<< *a << endl; // /*a means 1st value a[0]
    //array is also like pointers -----size 10*(4) bytes used here a[0]==1st block of 1st byte(1)... a[1] - is of 2nd block 0f 1st address(5)

    int *p;
    int **pp;//double pointer stores a pointer 
    int aa = 4;
    p = &aa;
    pp = &p;
    
    cout << aa<< " "<< *p << " "<< **pp<< " "<< endl;
    cout << aa<< " " << p << " "<< pp << " " << *pp << endl;
    cout << aa << endl;
    increment(&aa);
    cout<< aa<< endl;
}