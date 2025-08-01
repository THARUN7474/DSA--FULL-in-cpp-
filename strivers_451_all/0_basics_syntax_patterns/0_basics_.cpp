#include<iostream>

int main(){
    std::cout<<"hello world";
    return 0; 
}   



// ____--------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
int glo=6;//global variable and gv and lv can have same name but pref will be diff
void sum(){
    int s=2;
    cout<<"\n"<<glo;//when fun called it prints glo of global variable as no locl var in sum funbody so 
}
int main(){
    // int s=0;
    // int t=3;
    bool is_true= false;
    int glo=9;//local variable and it takes preference
    glo=74;//updates the value of variable glo(locl variable only updates) 
    int s=12,t=13;
    cout<<"\nhello world"<<s;
    cout<<" \nhello prends.\nhere is value of s"<<s<<". the value of t is"<<t;
    sum();
    cout<<"\n"<<is_true;//as 0 for false 1 for true as we used int return 
    cout<<"\n"<<glo;
    return 0; 
}

// ____--------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

int main()
{
    //for input and output data 
    int num1,num2;
    cout<<"ENTER THE VALUE OF num1:\n"/*<< is called insertion operator*/;
    cin>>num1;/*>> is called extraction operator*/
    cout<<"ENTER THE VALUE OF num2:\n"/*<< is called insertion operator*/;
    cin>>num2;/*>> is called extraction operator*/

    cout<<"the sum is"<< num1+num2;
    return 0;
}


// ____--------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    cout<< "hello tharun!";
    int a =10;
    long b =20;
    char a ='a';
    cout << sizeof(a)<< " " << sizeof(b)<< "\n";
}


//there r 2 types of header files 
//1.system header file comes with complier
#include<iostream>
//2.user defined header files; written by programmer
// #include "this.h"--->this will show error if this.h is not present in current directory 
// deprecated means new got instead of that ...search this in refernecepage

using namespace std;

int main()
{
    int a=4,b=5;
    cout<<"operators in c++:"<<endl;
    cout<<"following r the types of operators"<<endl;
    //arithmetic opertors
    cout<<"the value of a+b is"<<a+b<<endl;
    cout<<"the value of a-b is"<<a-b<<endl;
    cout<<"the value of a*b is"<<a*b<<endl;
    cout<<"the value of a/b is"<<a/b<<endl;
    cout<<"the value of a%b is"<<a%b<<endl;
    cout<<"the value of a++ is"<<a++<<endl;
    cout<<"the value of a-- is"<<a--<<endl;
    cout<<"the value of ++a is"<<++a<<endl;
    cout<<"the value of --a is"<<--a<<endl;

    //ASSSIGMENT op
    

    //comparison op
    cout<<"the value of a=b is"<<(a=b)<<endl;
    cout<<"the value of a!=b is"<<(a!=b)<<endl;
    cout<<"the value of a>=b is"<<(a>=b)<<endl;
    cout<<"the value of a<=b is"<<(a<=b)<<endl;
    cout<<"the value of a>b is"<<(a>b)<<endl;
    cout<<"the value of a<b is"<<(a<b)<<endl;
    return 0;
}


#include"bits/stdc++.h"
using namespace std;

int main(){
    int a = 12;
    a = a << 1;
    cout << a<< endl;
    a = a << 4;// a *2^4
    cout << a<< endl;
    a = a >> 4;
    cout << a<< endl;

    int b = -12;
    b = b << 2;
    cout << b << endl;
    b = b >> 10;
    //give an high +ve value as it adds 0 at start so---check this??? is it true?/
    cout << b << endl; 
    a = a << -1;//give garbabge value
    cout << a<< endl;
    cout<<(5&10)<<endl;
}