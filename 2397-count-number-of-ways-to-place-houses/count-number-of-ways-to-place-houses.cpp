
class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD = 1e9 + 7;
        
        // lets calculate for one side of street first, then we will find total number of possible arrangments by dp[n] * dp[n]
        vector<long long> dp(n + 1, 0);

        // Base cases
        dp[0] = 1; // ways to arrange 0 plots
        dp[1] = 2; // ways to arrange 1 plot -> either make house or not make

        // calculating valid arrangements
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD; // we need to consider both the cases
        }

        // both sides are independent
        return (dp[n] * dp[n]) % MOD;
    }
};
