#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    static const int mod = 1000000007;
    
public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        int currentCount = 1;
        vector<int> groupSizes;
        
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                currentCount++;
            } else {
                groupSizes.push_back(currentCount);
                currentCount = 1;
            }
        }
        groupSizes.push_back(currentCount);
        
        long long totalWays = 1;
        for (int size : groupSizes) {
            totalWays = (totalWays * size) % mod;
        }
        
        if (groupSizes.size() >= k) {
            return (int) totalWays;
        }
        
        vector<int> dp(k, 0);
        vector<int> prefixSum(k, 1);
        dp[0] = 1;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            vector<int> newDp(k, 0);
            
            for (int j = 1; j < k; ++j) {
                newDp[j] = prefixSum[j - 1];
                if (j - groupSize - 1 >= 0) {
                    newDp[j] = (newDp[j] - prefixSum[j - groupSize - 1] + mod) % mod;
                }
            }
            
            vector<int> newPrefix(k, 0);
            newPrefix[0] = newDp[0];
            for (int j = 1; j < k; ++j) {
                newPrefix[j] = (newPrefix[j - 1] + newDp[j]) % mod;
            }
            
            dp = newDp;
            prefixSum = newPrefix;
        }
        
        return (int) ((totalWays - prefixSum[k - 1] + mod) % mod);
    }
};