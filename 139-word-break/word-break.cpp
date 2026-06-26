class TrieNode { 
public: 
    bool isEnd; 
    TrieNode* child[26]; 
    
    TrieNode() { 
        isEnd = false; 
        for(int i = 0; i < 26; i++) { 
            child[i] = NULL; 
        } 
    } 
}; 

class Trie { 
public: 
    TrieNode* root; 
    
    Trie() { 
        root = new TrieNode(); 
    } 
    
    void insert(const string &word) { 
        TrieNode* curr = root; 
        for(int i = 0; i < word.size(); i++) { 
            char ch = word[i]; 
            int index = ch - 'a'; 
            if(curr->child[index] == NULL) { 
                TrieNode* temp = new TrieNode(); 
                curr->child[index] = temp; 
            } 
            curr = curr->child[index]; 
        } 
        curr->isEnd = true; 
    } 
}; 

class Solution { 
public:
    bool solve(string &s, int index, TrieNode* root, vector<int> &dp) {
        if (index == s.size()) return true;
        
        if (dp[index] != -1) return dp[index];
        
        TrieNode* curr = root;
        
        for (int i = index; i < s.size(); i++) {
            int childIndex = s[i] - 'a';
            
            
            if (curr->child[childIndex] == NULL) break;
            
            curr = curr->child[childIndex];
            if (curr->isEnd) {
                if (solve(s, i + 1, root, dp)) {
                    return dp[index] = 1; 
                }
            }
        }
        return dp[index] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) { 
        Trie *trie = new Trie(); 
        for(auto &it : wordDict){ 
            trie->insert(it); 
        } 
        
        vector<int> dp(s.size(), -1);
        
        return solve(s, 0, trie->root, dp); 
    } 
};
