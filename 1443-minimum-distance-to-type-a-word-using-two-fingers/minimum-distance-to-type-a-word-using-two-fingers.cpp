class Solution {
private:
    int getDistance(vector<vector<int>>& coord, int x, int y) {
        return abs(coord[x][0] - coord[y][0]) + abs(coord[x][1] - coord[y][1]);
    }

public:
    int minimumDistance(string text) {
        int len = text.size();

        // Store grid positions of characters
        vector<vector<int>> coord(26, vector<int>(2));
        for (int i = 0; i < 26; i++) {
            coord[i][0] = i / 6;
            coord[i][1] = i % 6;
        }

        int totalCost = 0;
        vector<int> dpState(26, 0); // stores maximum savings

        for (int i = 1; i < len; i++) {
            int lastChar = text[i - 1] - 'A';
            int currChar = text[i] - 'A';

            int moveCost = getDistance(coord, lastChar, currChar);
            totalCost += moveCost;

            vector<int> next(26, 0);

            for (int fingerPos = 0; fingerPos < 26; fingerPos++) {
                // Case 1: continue with same finger
                next[fingerPos] = max(next[fingerPos], dpState[fingerPos]);

                // Case 2: use second finger
                int benefit =
                    moveCost - getDistance(coord, fingerPos, currChar);
                next[lastChar] =
                    max(next[lastChar], dpState[fingerPos] + benefit);
            }

            dpState = next;
        }

        int bestSaving = 0;
        for (int val : dpState) {
            bestSaving = max(bestSaving, val);
        }

        return totalCost - bestSaving;
    }
};