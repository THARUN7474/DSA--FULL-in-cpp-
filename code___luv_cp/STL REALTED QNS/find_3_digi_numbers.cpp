#include<bits/stdc++.h>


using namespace std;

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    // generating frequency map of the given digits
    vector<int> count(10, 0);
    for (auto& d : digits) count[d]++;

    vector<int> res;

    for (int num = 100; num < 999; num += 2) {
      // generating frequency map of the current number
      vector<int> currCount(10, 0);
      int temp = num;

      while (temp) {
        currCount[temp % 10]++;
        temp /= 10;
      }

      // checking if the number can be generated or not
      bool flag = true;
      for (int i = 0; i < 10; i++) {
        if (currCount[i] > count[i]) {
          flag = false;
          break;
        }
      }

      if (flag) {
        res.push_back(num);
      }
    }
    return res;
  }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> m;
        for(auto it:digits) m[it]++;
        vector<int> ans;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=8;k+=2){
                    if(m[i]>0){
                        m[i]--;
                        if(m[j]>0){
                            m[j]--;
                            if(m[k]>0){
                                ans.push_back(i*100+j*10+k);
                            }
                            m[j]++;
                        }
                        m[i]++;
                    }
                }
            }
        }
        return ans;
    }
};  