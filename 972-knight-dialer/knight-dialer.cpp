class Solution {
public:
    int knightDialer(int n) {
        const long long MOD = 1e9 + 7;

        // dp[i][j] represents number of phone number of length i , ending with digit j
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        long long ans = 0;

        // we need to look that from where we can reach a particular digit , for transition of state
        vector<vector<int>> prev = {
            {4, 6},    // 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {0, 3, 9}, // 4
            {},        // 5
            {0, 1, 7}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
        };
        // base case
        for (int j = 0; j < dp[0].size(); j++) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (auto k : prev[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }
        return ans;
    }
};