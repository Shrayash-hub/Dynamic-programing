class Solution {
public:
    int minCost(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 0;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + i - 1;
        }

        return dp[n];
    }
};