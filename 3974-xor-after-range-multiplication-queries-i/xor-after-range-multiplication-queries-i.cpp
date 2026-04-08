class Solution {
public:
    const int MOD=1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &q : queries) {
            int idx = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];

            while (idx <= ri) {
                long long temp = nums[idx];
                nums[idx] = (temp * vi) % MOD;
                idx += ki;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};