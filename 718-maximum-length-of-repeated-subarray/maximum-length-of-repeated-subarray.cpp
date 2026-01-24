class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
        int n = text1.size();
        int m = text2.size();
        int ans = 0;
        vector<vector<int>> common(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    common[i][j] = 1 + common[i-1][j-1];
                    ans = max(ans,common[i][j]);
                }
                else{
                    common[i][j] = 0;
                }
            }
        }
        return ans;
    }
};