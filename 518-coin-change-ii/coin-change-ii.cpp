class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned long long>> dp(coins.size() + 1, vector<unsigned long long>(amount + 1, 0)); // number of ways to make amount j using coins at 0th to ith index

        // amount 0 can always be made in 1 way
        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                // skip if we have a coin which is more than the target amount
                if (j < coins[i-1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // else we will be taking it , and ways will be not_pick + pick 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return (int)dp[coins.size()][amount];
    }
};