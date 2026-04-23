class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // base case
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        
        // first element
        if(arr[0] == 0) dp[0][0] = 2;
        else if(arr[0] <= target) dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                int notPick = dp[i-1][t];
                int pick = 0;
                
                if(arr[i] <= t){
                    pick = dp[i-1][t - arr[i]];
                }
                
                dp[i][t] = pick + notPick;
            }
        }
        return dp[n-1][target];
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = 0;
        for(auto it: arr){
            sum+= it;
        }
        
        if (sum - diff < 0 || (sum - diff) % 2 != 0) return 0;

        return perfectSum(arr, (sum - diff) / 2);
    }
};