class Solution {
public:
    bool canPartition(vector<int>& val) {
        int sum = 0;
        for(int i=0;i<val.size();i++){
            sum+=val[i];
        }
        if(sum%2!=0) return false;
        int W = sum/2;

        vector<vector<bool>> dp(val.size()+1,vector<bool>(W+1,0));
        for(int i=0;i<=val.size();i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=val.size();i++){
            for(int j = 0 ;j<=W;j++){
                // current balls are less then balls a batter required
                if(j<val[i-1])
                dp[i][j] = dp[i-1][j];
                // if there are required number of balls -> compare the previous state value and new value
                else
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-val[i-1]]);
            }
        }
        
        return dp[val.size()][W];
    }
};