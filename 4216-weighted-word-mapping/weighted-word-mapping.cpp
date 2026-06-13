class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        for(int i=0;i<words.size();i++){
            int newW = 0;
            for(int j=0;j<words[i].size();j++){
                int temp = weights[words[i][j]-'a'];
                newW+=temp;
            }
            newW = newW%26;
            char word = (char)('a'+(25-newW));
            ans+=word;
        }
        return ans;
    }
};