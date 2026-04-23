class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // dp state is  sum of 0 to ith index can be equal to target or not
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false)) ;
        
        // base case , as target = 0 can be achived anyways
        for(int i=0;i<arr.size();i++) dp[i][0] = true;
        
        // for first element of array
        if(arr[0]<=sum) dp[0][arr[0]] = true;
        
        // filling the table
        for(int i=1;i<arr.size();i++){
            for(int target = 0;target<=sum;target++){
                bool take = dp[i-1][target];
                bool notTake = false;
                
                if(arr[i]<=target){
                    notTake = dp[i-1][target-arr[i]];
                }
                dp[i][target] = notTake || take;
            }
        }
        return dp[arr.size()-1][sum];
    }
};