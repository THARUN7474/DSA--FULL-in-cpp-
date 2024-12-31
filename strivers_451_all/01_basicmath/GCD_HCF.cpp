#include <bits/stdc++.h>
using namespace std;


int main(){
    // finding greatest common divsor of both----gcf of n1 and n2 
    // 1 is alwasy 
    // 2 primes means ony 1 is gcf
    // if n1 is divsior of n2 then n1 is gcf of n1,n2
    
    int n1,n2;
    cin>>n1>>n2;
    int gcf = 1;
    for(int i =1; i< min(n1,n2); i++){
        if(n1%i==0 && n2%i==0){
            gcf = i;
        }
    }//tc ---O(MIN(n1,n2))

    // SOME BETTER APPROCH IS 
    int n1,n2;
    cin>>n1>>n2;
    int gcf = 1;
    for(int i =min(n1,n2); i>= 1; i--){
        if(n1%i==0 && n2%i==0){
            gcf = i;
        }
    }//tc ---O(MIN(n1,n2)) still this c

    // eclided theroem---best soltution
}

// here we need to makecure n1 > n2 
int euclidgcd(int n1,int n2){
    if(n2==0){
        return n1;
    }
    return euclidgcd(n2,n1%n2);
}

int euclidgcd(int n1,int n2){
    while(n1>0 && n2>0){
        if(n1>n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    if(n1==0) return n2;
    else return n1;
}
// TC ------O(log ph(min(n1,n2)))
// MORE SIMPLE
// A,B
// THEN —-GCD(A,B) = GCD(A%B,B) ——A%B(LARGER % SMALLER) —IF ONE IS 0 THEN OTHER IS GCD 
// The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.

// To find the GCD of n1 and n2 where n1 > n2:

// Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// Once one of them becomes 0, the other number is the GCD of the original numbers.
// Eg, n1 = 20, n2 = 15:

// gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)

// gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

// gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

// gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

// Hence, return 5 as the gcd.
