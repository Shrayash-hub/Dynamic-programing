class Solution {
public:
    int longestPalindromeSubseq(string text) {
        int n = text.size();
        string text2 = text;
        vector<vector<int>> common(n+1,vector<int>(n+1,0));
        reverse(text2.begin(),text2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(text[i-1]==text2[j-1]){
                    common[i][j] = 1 + common[i-1][j-1];
                }
                else{
                    common[i][j] = max(common[i-1][j],common[i][j-1]);
                }
            }
        }
        return common[n][n];
    }
};