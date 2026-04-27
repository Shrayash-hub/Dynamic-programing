class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // similar to 0-1 matrix question
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> q; // {row,clm}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                            isWater[nr][nc] == -1) {
                        isWater[nr][nc] = isWater[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return isWater;
    }
};