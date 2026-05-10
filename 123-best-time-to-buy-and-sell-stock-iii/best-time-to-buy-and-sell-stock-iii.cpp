class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(2, vector<int>(3, 0)));

        // base cases
        // if cap is zero -> means we have no transaction left so we cannot gain
        // any profit -> index and buy can be anything
        for (int ind = 0; ind <= n; ind++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[ind][buy][0] = 0;
            }
        }

        // if index = n then we cannot gain any more profit -> buy and cap can
        // be anything
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    // if we can buy the stocks then we have to options
                    // 1. either to buy this stock and include the -prices[ind] in
                    // the profit
                    // 2. or to leave this price and lock for any upcoming stock
                    // price
                    // in both the cases number of transactions will be same as we didnt sold any stockes yet
                    if (buy) {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap],
                                     dp[ind + 1][1][cap]);
                    }
                    // if we cannot buy any stock -> means we have to sell then also
                    // we have 2 options
                    // 1. either to sell this stock and include prices[ind] in the
                    // profit and reduce the transaction by 1 , as we completed 1 transaction by selling this stock
                    // 2. or to leave this stock and look for any upcoming price
                    
                     else {
                        profit = max(prices[ind] + dp[ind + 1][1][cap-1],
                                     dp[ind + 1][0][cap]);
                    }

                    dp[ind][buy][cap] = profit;
                }
            }
        }
        //  when index exhausted , two transactions completed 
        return dp[0][1][2];
    }
};