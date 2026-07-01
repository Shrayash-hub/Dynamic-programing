class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j, int v) {
        if (grid[i][j] < v) {
            return false;
        }
        if (i == grid.size()-1 && j == grid.size()-1) {
            return true;
        }

        visited[i][j] = true;
        for (int m = 0; m < 4; m++) {
            int ni = i + dx[m];
            int nj = j + dy[m];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid.size() &&
                visited[ni][nj] == false) {
                if(dfs(grid, visited, ni, nj, v)){
                    return true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // lets start bfs from each cell having thief and let them populate the
        // other cells with the safeness factor
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto cell = q.front();
                q.pop();
                int i = cell.first;
                int j = cell.second;
                for (int m = 0; m < 4; m++) {
                    int ni = i + dx[m];
                    int nj = j + dy[m];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                        visited[ni][nj] == false) {
                        grid[ni][nj] = 1 + grid[i][j];
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }

        int low = 0;
        // largest distance can be (0,0) and (n-1,n-1) and Manhattan distance will be 
        // (n−1)+(n−1)=2(n−1) 
        int high = 2 * (n - 1); 
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> newVisited(n, vector<bool>(n, 0));
            // if we can reach to the last cell , then reduce the search space 
            if (dfs(grid, newVisited, 0, 0, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};