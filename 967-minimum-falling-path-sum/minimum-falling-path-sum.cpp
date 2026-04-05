class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // multiple state and multiple end type
        int n = matrix.size();
        int m = matrix[0].size();
        // dp state is going to save the minimum path cell till the current cell
        vector<vector<int>> dp(n,vector<int>(m,0));

        // base case -> as first row k sarey cells k liye minimum path sum toh unki khud ki values hi hongi -> initial stage
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // for out of boundries value
                int left = INT_MAX;
                int right = INT_MAX;
                if (j < m - 1)
                    // upper right size a rhey ho tbh k liye
                    right = matrix[i][j] + dp[i - 1][j + 1];
                if (j > 0)
                    // upper left size
                    left = matrix[i][j] + dp[i - 1][j - 1];

                // and just upar se a rhey hp toh
                int up = matrix[i][j] + dp[i - 1][j];

                dp[i][j] = min(up, min(right, left));
            }
        }

        // last row k kisi bhi cell me minimum path sum save ho skta h
        int value = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return value;
    }
};