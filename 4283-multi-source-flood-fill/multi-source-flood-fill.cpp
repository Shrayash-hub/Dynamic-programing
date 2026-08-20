class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        // lets sort the sources on the basis of colors ( in descending order )
        // if we will put first ,the sources with larger color values in the queue
        // then for sure they are going to be processed first 
        sort(sources.begin(), sources.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] > b[2];
             });

        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;

        // lets push the sources in descending order
        for (const auto& s : sources) {
            int r = s[0], c = s[1], color = s[2];
            if (grid[r][c] == 0) {
                grid[r][c] = color;
                q.push({color, {r, c}});
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // starting bfs
        while (!q.empty()) {
            auto [currColor, pos] = q.front();
            auto [row, clm] = pos;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newR = row + dx[i];
                int newC = clm + dy[i];

                // now we will see the unvisited cell only , and will not allow the already filled cells ,
                // as we pushed the sources with larger color values first , they are going to be processed first , and because of this , they are going to fill the unvisited cell first, once a cell is filled larger color value due to its parent cell , there is no need to let fill the color in that cell by the parent with smaller value
                if (newR >= 0 && newC >= 0 && newR < n && newC < m &&
                    grid[newR][newC] == 0) {
                    grid[newR][newC] = currColor;
                    q.push({currColor, {newR, newC}});
                }
            }
        }

        return grid;
    }
};