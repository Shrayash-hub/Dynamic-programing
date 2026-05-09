class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        int n = s.size();
        vector<long long> dp(n + 1, 0); // dp[i] = distinct subsequences till index i

        dp[0] = 1;
        vector<int> last(26, -1); // to store the last character index

        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            
            // every time a new char introduces it increases the count to 2 * dp[i-1]
            /*
            because every old subsequence can:

            1. take current char
            2. not take current char
            */
            dp[i] = (2 * dp[i - 1]) % MOD;

            // but duplicates appear if character already existed before. so subtracting old contribution.
            if (last[ch - 'a'] != -1) {
                dp[i] = (dp[i] - dp[last[ch - 'a'] - 1] + MOD) % MOD;
            }

            // updating last
            last[ch - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};