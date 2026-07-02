class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        
        // dist[i][j] = minimum health lost to reach (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // min-heap: {healthLost, {i, j}}
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<>> pq;
        
        int startCost = grid[0][0]; // 1 if unsafe cell, 0 if safe
        dist[0][0] = startCost;
        pq.push({startCost, {0, 0}});
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();
            int i = cell.first, j = cell.second;
            
            if (d > dist[i][j]) continue;
            
            if (i == n - 1 && j == m - 1) {
                return health - d > 0;
            }
            
            for (int l = 0; l < 4; l++) {
                int ni = i + dx[l];
                int nj = j + dy[l];
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int cost = d + grid[ni][nj]; // grid[ni][nj] is 0 or 1
                    if (cost < dist[ni][nj]) {
                        dist[ni][nj] = cost;
                        pq.push({cost, {ni, nj}});
                    }
                }
            }
        }
        
        return health - dist[n-1][m-1] > 0;
    }
};