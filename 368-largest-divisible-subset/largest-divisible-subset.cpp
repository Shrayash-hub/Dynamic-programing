class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {

        // similar to print lis question , here just we need to find longest divisible subsequence , that can be achieved by changing the condition in the if statement and sorting the arr
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hashset(n);
        int last_index = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            hashset[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev <= i - 1; prev++) {
                // condition changed to divisibility
                if ((arr[i] % arr[prev] == 0) && (1 + dp[prev]) > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hashset[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last_index = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last_index]);
        while (last_index != hashset[last_index]) {
            last_index = hashset[last_index];
            ans.push_back(arr[last_index]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};