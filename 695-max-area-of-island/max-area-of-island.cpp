class Solution {
public:
    int row, clm;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;

        int area = 1;

        for (int k = 0; k < 4; k++) {
            int newRow = i + dx[k];
            int newClm = j + dy[k];

            if (newRow >= 0 && newClm >= 0 && newRow < row && newClm < clm &&
                grid[newRow][newClm] == 1) {

                area += dfs(grid, newRow, newClm);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        row = grid.size();
        clm = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < clm; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};