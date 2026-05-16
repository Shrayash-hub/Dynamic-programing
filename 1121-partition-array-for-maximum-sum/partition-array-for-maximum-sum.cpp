class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int> dp(n + 1, 0); // maximum sum we can obtain starting from index ind till the end of the array

        for (int ind = n - 1; ind >= 0; ind--) {
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            // lenngth of current subarray = ending_index(j) - starting_index(i) + 1  -> it should be smaller than or equal to k
            for (int j = ind; j < n && j - ind + 1 <= k; j++) {
                // find the current max element in the array
                maxi = max(maxi, arr[j]);
                // sum of that subarray + calculation of rest part of the partition
                int sum = (j - ind + 1) * maxi + dp[j + 1];
                // we need to find the maximum of those cases
                maxAns = max(sum, maxAns);
            }
            //ind se lekar ind + k tak partition krogey toh un cases me se max is going to save in the dp[ind]
            dp[ind] = maxAns;
        }
        // returning the largest sum we can obtain starting from index 0
        return dp[0];
    }
};