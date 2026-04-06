class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid, int k, int rem,
              vector<vector<vector<int>>>& dp) {
        
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m) return 0;

        rem = (rem + grid[i][j]) % k;

        if (i == n - 1 && j == m - 1) {
            return (rem == 0);
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int down = solve(i + 1, j, grid, k, rem, dp);
        int right = solve(i, j + 1, grid, k, rem, dp);

        return dp[i][j][rem] = (down + right) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1))
        );

        return solve(0, 0, grid, k, 0, dp);
    }
};