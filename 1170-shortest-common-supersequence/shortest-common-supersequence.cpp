class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        vector<vector<int>> common(n + 1, vector<int>(m + 1, 0));
        string s = "";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    common[i][j] = 1 + common[i - 1][j - 1];
                } else {
                    common[i][j] = max(common[i - 1][j], common[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            if (text1[i-1] != text2[j-1]) {
                if (common[i - 1][j] <= common[i][j - 1]) {
                    s += text2[j - 1];
                    j = j - 1;
                } else {
                    s += text1[i - 1];
                    i = i - 1;
                }
            } else {
                s += text1[i - 1];
                i = i - 1;
                j = j - 1;
            }
        }

        while(i > 0) {
            s += text1[i-1];
            i--;
        }

        while(j > 0) {
            s += text2[j-1];
            j--;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};