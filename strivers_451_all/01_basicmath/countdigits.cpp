// A simple solution for this problem is to read number in string form and one by one check divisibility by each digit which appears in N. Time complexity for this approach will be O(N2).
// An efficient solution for this problem is to use an extra array divide[] of size 10. Since we have only 10 digits so run a loop from 1 to 9 and check divisibility of N with each digit from 1 to 9. If any digit divides N then mark true in divide[] array at digit as index. Now traverse the number string and increment result if divide[i] is true for current digit i. 


// How to check divisibility of a digit for large N stored as string? 
// The idea is to use distributive property of mod operation. 
// (x+y)%a = ((x%a) + (y%a)) % a.


//
// Extract Each Digit: We need to examine each digit of the number 
// Check Divisibility: For each digit, check if it divides N without leaving a remainder.
// Count Valid Digits: Keep a count of how many digits satisfy the divisibility condition.
// The expected time complexity is O(logN) because the number of digits in N is proportional to log10(N)
// The space complexity should be 


// int a = (int)(log10(n)+1)//number of digits in number


#include <bits/stdc++.h>
using namespace std;

bool divisible(string N, int digit);

// This function returns true if digit divides N, 
// else false
bool divisible(string N, int digit)
{
    int ans = 0;
    for (int i = 0; i < N.length(); i++)
    {     
        // (N[i]-'0') gives the digit value and
        // form the number       
        ans  = (ans*10 + (N[i]-'0'));

        // We use distributive property of mod here. 
        ans %= digit;
    }
    return (ans == 0);
}



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int X = N;
        int d;
        bool div[10] ={false};
        for(int i =1;i<10;i++){
            if(N%i == 0){
                div[i] = true;
            }
        }
        while(N){
            int n = N%10;
            if(n != 0 && div[n] == true){
                d++;
            }
            N = N/10;
        }
        return d;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends


int evenlyDivides(int N)
    {
        int temp = N, count = 0;
        while (temp != 0)
        {
            // extract the last digit
            int d = temp % 10;
            temp /= 10;
             
            // check if d divides N completely and is not zero
            if (d > 0 && N % d == 0)
              count++;
        }
        
        return count;
    }