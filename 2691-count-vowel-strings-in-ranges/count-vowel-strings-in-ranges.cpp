class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiouAEIOU";
        return vowels.find(ch) != string::npos;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> prefix(words.size()+1,0);
        for (int i = 1; i <= words.size(); i++) {
            if (isVowel(words[i-1][0]) && isVowel(words[i-1][words[i-1].size()-1])) {
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }
        
        vector<int> ans;
        for(auto it: queries){
            int start = it[0];
            int end = it[1];
            ans.push_back((prefix[end+1])-(prefix[start]));
        }
        return ans;
    }
};