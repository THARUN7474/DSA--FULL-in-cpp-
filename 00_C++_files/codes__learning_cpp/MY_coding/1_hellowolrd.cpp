#include<iostream>

using namespace std;
//developed by them  to enable us to use same type of things like cout in our code for us

namespace std_my_made{
    template<typename T>
    T sum(T a, T b){
        return a + b;
    }

    void print_hello(string a){
        cout << a << endl;
    }
}

using std::endl;

int main(){
    cout<<"hello world";

    cout<<"hello tharun"<< endl;
    std::cout<<"hello world"<<std::endl;
    std_my_made::print_hello("hello tharun");
    std_my_made::print_hello("hello tharun");
    cout<<std_my_made::sum(10, 5)<<endl;
    // cout<<std_my_made::sum("tharun", "banda")<<endl;

    return 0;
}