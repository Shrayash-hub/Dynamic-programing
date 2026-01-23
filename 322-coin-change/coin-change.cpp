class Solution {
public:
    int coinChange(vector<int>& wt, int W) {
        int n = wt.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));

        int INF = 1e9;
        for(int i = 0;i<=W;i++){
            dp[0][i] = INF;
        }
    
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=W;j++){
                if(j<wt[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],1 + dp[i][j - wt[i-1]]);
                }
            }
        }
        if(dp[n][W] >= INF){
            return -1;
        }
        
        return dp[n][W];
    }
};