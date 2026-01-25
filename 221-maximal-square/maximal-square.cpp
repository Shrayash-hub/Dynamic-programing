class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // base case , first row aur first column , same rhenge given matrix se
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                // if matrix[i][j] is 1 toh ek complete square k liye uskey top , left aur diagonal elements bhi 1 honey chahiye , if yes , then hm usmey 1+min(top,left,diagonal) save kr lenge means max size of square till i,j
                else if(matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(
                        dp[i-1][j],
                        min(dp[i][j-1], dp[i-1][j-1])
                    );
                }
                // agr koi element zero h matrix me toh dp matrix me bhi zero mark kr denge
                else {
                    dp[i][j] = 0;
                }

                maxi = max(maxi, dp[i][j]);
                //maximum nikal lenege purey dp array me se
            }
        }

        // returning the area of max size ka square
        return maxi*maxi;
    }
};
