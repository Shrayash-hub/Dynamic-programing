class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        for(auto it: word){
            st.insert(it);
        }
        unordered_map<char,int> mpp;
        for(auto it: st){
            if(isupper(it)){
                mpp[tolower(it)]++;
            }
            else{
                mpp[it]++;
            }
        }
        int cnt = 0;
        for(auto it: mpp){
            if(it.second > 1){
                cnt++;
            }
        }
        return cnt;
    }
};