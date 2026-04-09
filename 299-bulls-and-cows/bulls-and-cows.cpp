class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA = 0;
        vector<int> sec(10, 0);
        vector<int> gues(10, 0);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                cntA++;
            } else {
                sec[secret[i] - '0']++;
                gues[guess[i] - '0']++;
            }
        }
        int cntB = 0;
        for (int i = 0; i < sec.size(); i++) {
            cntB += min(sec[i], gues[i]);
        }

        string ans = "";
        ans += to_string(cntA);
        ans += 'A';
        ans += to_string(cntB);
        ans += 'B';
        return ans;
    }
};