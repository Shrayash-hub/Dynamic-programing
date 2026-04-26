class Solution {
public:
    int rows, cols;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int row, int col, int prevRow, int prevCol) {
        visited[row][col] = true;
        for (auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                continue;
            if (grid[newRow][newCol] != grid[row][col])
                continue;
            if (newRow == prevRow && newCol == prevCol)
                continue;
            if (visited[newRow][newCol])
                return true;
            if (dfs(grid, visited, newRow, newCol, row, col))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};