#include<bits/stdc++.h>

// #include <boost/multiprecision/cpp_int.hpp>

// using namespace boost::multiprecision;


using namespace std;

// ----------------------------------------------------1)AREA QUESTION----------------------------------------------------
double areaofcircle(double r){
    double pi = 2 * asin(1.0);
    double pi3 = 2* acos(0.0);
    double pi2 = M_PI;
    return (pi2 * pow(r,2));
}

// --------------------------------------------------2)EVEN ODD QUESTION----------------------------------------------------
bool evenorodd(int a){
    // return a % 2;
    return a & 1;
}

// --------------------------------------------3)FACTORIAL FIND QUESTION----------------------------------------------------
long long factorial(int a){
    // cout << "Enter a positive integer: ";
    if(a<0){
        return -1;//incorrected input case
    }
    // else{
    //         if(a==0 || a==1){
    //     return 1;
    // }
    // else{
    //     return a * factorial(a-1);
    // }
    unsigned long long ans=1;
    for(int i=1;i<=a;i++){
        ans *=i;
    }
    return ans;

    // while(a){
    //     ans = ans*(a--);
    // }
    // return ans;
    // }
}
// 100!=93,326,215,443,944,152,681,699,238,856,266,700,490,715,968,264,381,621,468,592,963,895,217,599,993,229,915,608,941,463,976,156,518,286,253,697,920,827,223,758,251,185,210,916,864,000,000,000,000,000,000,000,000,000

// This value is extremely large and exceeds the range of typical data types like unsigned long long, which is why it's necessary to use arbitrary-precision arithmetic libraries or algorithms to accurately calculate such large factorials.
// The maximum value that can be stored in an unsigned long long variable is limited by the size of the data type, which is typically 64 bits in most systems. This means that the maximum value that can be represented is 
// 2^64 −1, which is approximately 18,446,744,073,709,551,615.

// To handle larger factorial calculations, you would need to use a data type with higher precision or use libraries like Boost Multiprecision or GMP (GNU Multiple Precision Arithmetic Library) that support arbitrary-precision arithmetic.

// #include <iostream>
// #include <boost/multiprecision/cpp_int.hpp>

// using namespace boost::multiprecision;
// using namespace std;

// cpp_int factorial(int n) {
//     if (n < 0) {
//         return -1; // incorrect input case
//     } else {
//         cpp_int ans = 1;
//         for (int i = 1; i <= n; ++i) {
//             ans *= i;
//         }
//         return ans;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter a non-negative integer: ";
//     cin >> n;

//     cpp_int result = factorial(n);

//     if (result == -1) {
//         cout << "Factorial is not defined for negative numbers." << endl;
//     } else {
//         cout << "Factorial of " << n << " is: " << result << endl;
//     }

//     return 0;
// }

// ----------------------------------------------------4)ISPRIME_QUESTION----------------------------------------------------
bool isprime(int a){
    if (a==0||a==1){
        return false;
    }
    // cout<<"hiii";
    for(int i=2 ; i*i<a; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}


// --------------------------------------------5)LISTING ALL PRIMESqUESTION-------------------------------------------------
void list_all_primes(int a){
    // vector<int> primes;
    // for (int i = 2; i <= a; ++i) {
    //     if (isprime(i)) {
    //         primes.push_back(i);
    //     }
    // }
    vector<int> primes;
    for (int i =0; i<=a; i++)
    {
        if(isprime(i)){
            primes.push_back(i);
        }
    }
    cout<<"primes";
    for (int prime : primes) {
        cout << prime << "-";
    }
    cout << endl;
    
}



int main(){
    double r;
    cout<<"enter the side r value also for even odd testing: ";
    cin>> r;
    bool eo = evenorodd(r);
    if(eo == 1){
        cout<<"you entered an odd number"<<endl;
    }
    else{
        cout<<"you entered an even number"<<endl;
    }
    int n;
    cout << "Enter a positive integer: ";
    cin>> n;
    long long fact = factorial(n);

    cout<<"the factorial of a number"<<n<<" is "<<fact<<endl;


    bool prime = isprime(n);
    if(prime){
        cout<<"the n is prime"<<endl;
    }
    else{
        cout<<"the n is not a prime"<<endl;
    }

    list_all_primes(n);

    double ans =  areaofcircle(r);

    cout<< "the ans is"<<fixed<<setprecision(4)<<ans<<endl;
    return 0;
// std::fixed ensures that the precision is applied to the number of digits after the decimal point.
// std::setprecision(5) sets the precision to 5 decimal points.
// std::setw(10) sets the width of the output to 10 characters.
}