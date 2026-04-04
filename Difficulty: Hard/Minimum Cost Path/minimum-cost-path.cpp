class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min heap: {cost, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<>
        > pq;
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];
        
        // Directions: left, right, up, down
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        
        while(!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();
            
            int r = pos.first;
            int c = pos.second;
            
            // If reached destination
            if(r == n-1 && c == n-1) return cost;
            
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newCost = cost + grid[nr][nc];
                    
                    if(newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};