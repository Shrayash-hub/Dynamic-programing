class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // take the count of rotten oranges
                if (grid[i][j] == 2) {
                    q.push({i, j});
                // at the same time take the count of fresh oranges
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // direction arrays;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int time = 0;
        // if there are no rotten oranges , then there is no chance of other to be rotten
        while (!q.empty() && fresh > 0) {
            // using bfs
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;

                // checking all the adjacent side of orange
                for(int k=0;k<4;k++){
                    int newi = i + dx[k];
                    int newj = j + dy[k];

                    if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==1){
                        grid[newi][newj]=2;
                        q.push({newi,newj});
                        fresh--;
                    }
                }
                
                q.pop();
            }
            // at each iteration time is going to increse by 1 second
            time++;
        }
        // if there are fresh oranges left in grid
        if (fresh > 0)
            return -1;

        return time;
    }
};