class Solution {
public:
    int LongestPalindromeSubsequence(string s1) {
        string s2 = s1;
        reverse(s1.begin(), s1.end());

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    int minInsertions(string s) {
        int lengthLPS = LongestPalindromeSubsequence(s);
        /*
        String ke kuch characters already palindrome structure me fit ho sakte    hain. Unhe hume touch nahi karna.
        Wo kaunse characters hain?
        Jo Longest Palindromic Subsequence ka part hain.

        Baaki jo characters hain, unko match karne ke liye insertions karni padengi.
        
        */
        return s.size() - lengthLPS;
    }
};