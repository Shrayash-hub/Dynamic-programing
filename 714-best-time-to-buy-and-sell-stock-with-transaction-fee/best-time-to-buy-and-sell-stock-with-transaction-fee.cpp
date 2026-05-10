class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // base case
        dp[n][0] = 0;
        dp[n][1] = 0; // if we reached to the last index then there is no profit

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                // if we can buy the stocks then we have to options
                // 1. either to buy this stock and include the -prices[ind] in
                // the profit
                // 2. or to leave this price and lock for any upcoming stock
                // price
                if (buy) {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                // if we cannot buy any stock -> means we have to sell then also
                // we have 2 options
                // 1. either to sell this stock and include prices[ind] in the
                // profit
                // 2. or to leave this stock and look for any upcoming price
                else {
                    // we need to subtract the charged fee for the each transaction
                    profit = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};