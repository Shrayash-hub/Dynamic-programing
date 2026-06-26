class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        // Initialize all child pointers as NULL
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;

        // Initially no word ends here
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Create the root node
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string& word) {
        // Start from the root
        TrieNode* curr = root;

        // Traverse every character of the word
        for (int i = 0; i < word.size(); i++) {
            // Convert character into index (0-25)
            int index = word[i] - 'a';

            // Create a new node if it doesn't exist
            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();

            // Move to the next node
            curr = curr->children[index];
        }

        // Mark the end of the word
        curr->isEndOfWord = true;
    }

    // Return the shortest root present in the Trie
    string search(string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';

            // Root not found
            if (curr->children[index] == nullptr)
                return word;

            // Move to next node
            curr = curr->children[index];

            // Build the current prefix
            prefix += word[i];

            // Found the shortest root
            if (curr->isEndOfWord)
                return prefix;
        }

        // No shorter root found
        return word;
    }

    // Check whether a prefix exists
    bool isPrefix(string& word) {
        // Start from the root
        TrieNode* curr = root;

        // Traverse every character of the prefix
        for (int i = 0; i < word.size(); i++) {
            // Convert character into index
            int index = word[i] - 'a';

            // Return false for invalid characters
            if (index < 0 || index >= 26)
                return false;

            // Prefix not found
            if (curr->children[index] == nullptr)
                return false;

            // Move to the next node
            curr = curr->children[index];
        }

        // All prefix characters exist
        return true;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();

        for (auto it : dictionary) {
            root->insert(it);
        }

        stringstream ss(sentence);
        string word;
        string result;
        // extracting words one by one
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += root->search(word);
        }
        return result;
    }
};