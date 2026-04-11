class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int minGhost = INT_MAX;
        int ti = target[0];
        int tj = target[1];

        for (auto ghost : ghosts) {
            int i = ghost[0];
            int j = ghost[1];

            int currGhostDist = abs(i - ti) + abs(j - tj);
            minGhost = min(minGhost, currGhostDist);
        }
        int Dist = abs(ti - 0) + abs(tj - 0);
        if (Dist < minGhost) {
            return true;
        }
        return false;
    }
};