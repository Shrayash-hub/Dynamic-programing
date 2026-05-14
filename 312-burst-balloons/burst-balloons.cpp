class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // adding virtual balloons
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        /*
            dp[i][j] = maximum coins obtained
            by bursting balloons from i to j
        */
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // building smaller intervals first
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                // as base case is already covered
                if (i > j)
                    continue;

                int maxi = INT_MIN;
                
                // trying every balloon as LAST balloon burst
                for (int k = i; k <= j; k++) {
                    int cost =
                        // coins from bursting k last
                        nums[i - 1] * nums[k] * nums[j + 1]

                        // left partition
                        + dp[i][k - 1]

                        // right partition
                        + dp[k + 1][j];

                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};