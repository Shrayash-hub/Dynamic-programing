class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int first = g.size() - 1;
        int second = s.size() - 1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        while (first >= 0 && second >= 0) {
            if (g[first] <= s[second]) {
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