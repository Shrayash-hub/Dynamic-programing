class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // prev = n means no previous element chosen

        for(int i = n - 1; i >= 0; i--) {
            for(int prev = n; prev >= 0; prev--) {
                // skip current element
                int notTake = dp[i + 1][prev];

                // take current element
                int take = 0;

                if(prev == n || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i];
                }
                dp[i][prev] = max(take, notTake);
            }
        }
        return dp[0][n];
    }
};