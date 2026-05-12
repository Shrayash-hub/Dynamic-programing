class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1); // store the count of number of LIS till index i
        int maxi = 1;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                // if we get the index with the same lis length then , cnt must be increase 
                else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        int cntLIS = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) cntLIS+= cnt[i];
        }
        return cntLIS;
    }
};