#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, 0)); // storing when this cell was colored

        queue<tuple<int,int,int>> q;  // (row, col, color)

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        // initialize sources
        for (auto& source : sources) {
            int row = source[0];
            int col = source[1];
            int color = source[2];

            grid[row][col] = color;
            time[row][col] = 1; // as stating points , assign time as 1
            q.push({row, col, color});
        }

        // BFS
        while (!q.empty()) {
            auto [r, c, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    // first time visiting the cell
                    if (time[nr][nc] == 0) {
                        // update grid color
                        grid[nr][nc] = col;
                        // update time at we reach at this cell
                        time[nr][nc] = time[r][c] + 1;
                        q.push({nr, nc, col});
                    }
                    // another color reached this cell at same time
                    else if (time[nr][nc] == time[r][c] + 1) {
                        // choose the greater color
                        if (grid[nr][nc] < col) {
                            grid[nr][nc] = col;
                            q.push({nr, nc, col});
                        }
                    }
                }
            }
        }

        return grid;
    }
};