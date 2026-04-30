class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> dp(n + 1, 0);      // dp[x] = ways to make x using recovered coins
        vector<int> ans;               // recovered coins

        dp[0] = 1;                     // base: one way to make 0

        for (int i = 1; i <= n; i++) {
            int target = numWays[i - 1];   // given ways for amount i

            if (dp[i] > target) return {}; // already exceeded => impossible

            if (dp[i] == target) continue; // no coin i needed

            if (dp[i] + 1 != target) return {}; // coin i can add only one new way at i

            ans.push_back(i);               // coin i must exist

            // standard unbounded coin change update
            for (int amt = i; amt <= n; amt++) {
                dp[amt] += dp[amt - i];
            }
        }

        return ans;
    }
};