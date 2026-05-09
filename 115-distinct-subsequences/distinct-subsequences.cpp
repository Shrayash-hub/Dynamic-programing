class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // base case

        // if the index of t is exhausted then we got a subsequence of t in s
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // if we exhausted the index of s then there is no chance we found a
        // subsequence of t in s
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // if the char of s and t matches 
                if (s[i - 1] == t[j - 1]) {
                    // then there can be 2 cases:
                    // either we consider that char from s
                    // or we do not consider that char and move i to find any other matching char from the s
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // char do not match so , we will move i to find the matching char
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};