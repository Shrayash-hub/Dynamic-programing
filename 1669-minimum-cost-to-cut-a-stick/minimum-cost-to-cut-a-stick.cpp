class Solution {
public:

    int minCost(int n, vector<int>& cuts) {

        // Total number of cuts
        int c = cuts.size();

        // Add right boundary of stick
        cuts.push_back(n);

        // Add left boundary of stick
        cuts.insert(cuts.begin(), 0);

        // Sorting is necessary so cuts form valid intervals
        sort(cuts.begin(), cuts.end());

        /*
            dp[i][j]
            =
            minimum cost to perform cuts
            from cuts[i] to cuts[j]

            i and j represent indices inside cuts array
        */
        vector<vector<int>> dp(c + 2,
                               vector<int>(c + 2, 0));

        /*
            We move backwards because:

            dp[i][j] depends on:
            dp[i][index-1]
            dp[index+1][j]

            Smaller intervals should already be solved
        */
        for(int i = c; i >= 1; i--) {

            // j moves forward
            for(int j = 1; j <= c; j++) {

                // Invalid interval
                if(i > j) continue;

                // Store minimum possible answer
                int mini = INT_MAX;

                /*
                    Try every cut as the FIRST cut

                    Similar to:
                    Matrix Chain Multiplication partition DP
                */
                for(int index = i;
                    index <= j;
                    index++) {

                    /*
                        Current stick length:

                        right boundary - left boundary

                        boundaries are:
                        cuts[i-1] and cuts[j+1]
                    */
                    int cost =
                        (cuts[j + 1] - cuts[i - 1])

                        // solve left partition
                        + dp[i][index - 1]

                        // solve right partition
                        + dp[index + 1][j];

                    // choose minimum possible cut cost
                    mini = min(mini, cost);
                }

                // store best answer for interval [i...j]
                dp[i][j] = mini;
            }
        }

        // Final answer:
        // minimum cost to perform all cuts
        return dp[1][c];
    }
};