class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans(matrix.size(),0);

        for(int x = 0; x < matrix.size(); x++){
            int count = 0;
            int size = matrix[x].size();
            for(int i = 0; i < size; i++){
                if(matrix[x][i] == 1){
                    count++;
                }
            }
            ans[x] = count;
        }

        return ans;
    }
};