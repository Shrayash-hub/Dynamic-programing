class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;

        int oldColor = image[sr][sc];
        if (oldColor == color) {
            return image;
        } else {
            image[sr][sc] = color;
            q.push({sr, sc});
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto temp = q.front();
                q.pop();
                int row = temp.first;
                int col = temp.second;

                for (int i = 0; i < 4; i++) {
                    int newR = row + dx[i];
                    int newC = col + dy[i];

                    if (newR >= 0 && newC >= 0 && newR < n && newC < m &&
                        image[newR][newC] == oldColor) {
                        image[newR][newC] = color;
                        q.push({newR, newC});
                    }
                }
            }
        }
        return image;
    }
};