#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

long marcsCakewalk(vector<int> calorie) {
    long res =0;
    sort(calorie.rbegin(),calorie.rend());
    for(int i =0; i<calorie.size();i++){
        res += (1ll<<i)*calorie[i];
    }
    return res;
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

int luckBalance(int k, vector<vector<int>> contests) {
    int res =0;
    sort(contests.begin(),contests.end(),[&](vector<int> &a,vector<int> &b){
       return a[0]>b[0]; 
    });
    int impt_lose =0;
    for(auto&con:contests){
        if(con[1]==0){
            res +=con[0];
        }
        else if(impt_lose<k){
            res+=con[0];
            impt_lose++;
        }
        else{
            res -=con[0];
        }
    }
    return res;
}
