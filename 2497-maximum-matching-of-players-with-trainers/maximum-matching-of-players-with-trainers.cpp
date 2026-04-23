class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int first = players.size() - 1;
        int second = trainers.size() - 1;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int cnt = 0;
        while (first >= 0 && second >= 0) {
            if (players[first] <= trainers[second]) {
                cnt++;
                first--;
                second--;
            } else {
                first--;
            }
        }
        return cnt;
    }
};