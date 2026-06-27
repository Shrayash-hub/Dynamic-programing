class Node {
public:
    Node* links[26];
    bool flag = false;

    // Initialize all child pointers to NULL when a node is created.
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    // Check if the current node already has a child for the given character.
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Create and connect a new child node for the given character.
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Move from the current node to the child corresponding to the character.
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Mark that a complete word ends at this node.
    void setEnd() {
        flag = true;
    }

    // Check whether this node is the end of a valid word.
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    // Create an empty Trie with only the root node.
    Trie() {
        root = new Node();
    }

    // Insert a word by creating missing nodes and moving one character at a time.
    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {

            // Create a new node if the current character is not present.
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            // Move to the next character's node.
            node = node->get(word[i]);
        }

        // Mark the last node as the end of the word.
        node->setEnd();
    }

    // Search for a complete word by following its characters.
    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {

            // If any character is missing, the word does not exist.
            if (!node->containsKey(word[i])) {
                return false;
            }

            // Move to the next character's node.
            node = node->get(word[i]);
        }

        // Return true only if the last node marks the end of a word.
        return node->isEnd();
    }

    // Check whether any word starts with the given prefix.
    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {

            // If any prefix character is missing, no word has this prefix.
            if (!node->containsKey(prefix[i])) {
                return false;
            }

            // Move to the next character's node.
            node = node->get(prefix[i]);
        }

        // All prefix characters are found.
        return true;
    }
};

/*
Flow of Trie:

insert("apple")
root
  |
  a -> p -> p -> l -> e(end)

search("apple")
root -> a -> p -> p -> l -> e
If path exists and e is marked as end => true

startsWith("app")
root -> a -> p -> p
If path exists => true (end mark is not required)
*/