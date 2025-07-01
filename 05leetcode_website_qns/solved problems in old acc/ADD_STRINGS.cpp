#include<bits/stdc++.h>

using namespace std;

void addRecursion(string& num1,int p1,string& num2,int p2,int carry,string& ans){
        //base case
        if(p1<0 && p2<0){
            if(carry!=0){
                ans.push_back(carry+'0');
            }
            return;
        }

        int n1=(p1>=0 ? num1[p1] : '0')-'0';
        int n2=(p2>=0 ? num2[p2] : '0')-'0';
        int sum=n1+n2+carry;
        int digit=sum%10;
        carry=sum/10;
        ans.push_back(digit+'0');
        addRecursion(num1,p1-1,num2,p2-1,carry,ans);

    }
string stringSum(string &num1, string &num2) {
    string ans="";
        addRecursion(num1,num1.size()-1,num2,num2.size()-1,0,ans);
        reverse(ans.begin(),ans.end());
        // string ans2 = to_string(stoi(num1)+stoi(num2));but thuis gives error--run time errot as for large numbers int out of range gets 
        return ans;  
}
int main()
{
    string num1,num2;
    cin>>num1>>num2;
    cout<<stringSum(num1,num2)<<endl;
    return 0;
}