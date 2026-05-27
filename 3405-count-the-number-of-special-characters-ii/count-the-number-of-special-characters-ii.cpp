class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> alpha(26, 0);
        for (auto it : word) {

            // lowercase first time
            if (islower(it) && alpha[it - 'a'] == 0) {
                alpha[it - 'a'] = 1;
            }

            // uppercase after lowercase
            else if (isupper(it) && alpha[it - 'A'] == 1) {
                alpha[it - 'A'] = 2;
            }

            // lowercase again after uppercase -> invalid
            else if (islower(it) && alpha[it - 'a'] == 2) {
                alpha[it - 'a'] = -1;
            }

            // uppercase before lowercase -> invalid
            else if (isupper(it) && alpha[it - 'A'] == 0) {
                alpha[it - 'A'] = -1;
            }
        }

        int cnt = 0;

        for (auto it : alpha) {
            if (it == 2) {
                cnt++;
            }
        }
        return cnt;
    }
};