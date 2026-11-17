
class Solution {
public:
    bool validPartition(vector<int>& nums) {

        int n = nums.size();

        vector<bool> dp(n + 1, false);

        // base case
        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            // first case: last two equal elements
            if (i >= 2 &&
                nums[i-1] == nums[i-2]) {

                dp[i] = dp[i] || dp[i-2];
            }

            // second case: last three equal elements
            if (i >= 3 &&
                nums[i-1] == nums[i-2] &&
                nums[i-2] == nums[i-3]) {

                dp[i] = dp[i] || dp[i-3];
            }

            // third case: last three consecutive increasing elements
            if (i >= 3 &&
                nums[i-3] + 1 == nums[i-2] &&
                nums[i-2] + 1 == nums[i-1]) {

                dp[i] = dp[i] || dp[i-3];
            }

            // if any of these three cases are true , then dp[i] will be true
        }

        return dp[n];
    }
};
