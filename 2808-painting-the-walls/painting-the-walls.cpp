class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 1e9;

        // dp[i][j] is minimum cost needed to paint j walls using first i walls
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

        // painting 0 walls at costs 0
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // skip current wall
                dp[i][j] = dp[i - 1][j];

                // take current wall -> 1 by paid painter -> and jitna time paid painter kam krega i.e time[i-1] , utni walls free painter paint kr dega , as free painter 1 unit time me 1 wall paint krta h toh time[i-1] unit time me time[i-1] walls paint krega
                int covered = time[i - 1] + 1;
                dp[i][j] = min(dp[i][j],
                               dp[i - 1][max(0, j - covered)] + cost[i - 1]);
            }
        }

        return dp[n][n];
    }
};