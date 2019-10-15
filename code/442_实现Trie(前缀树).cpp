class TrieNode {
public:
    char c;
    TrieNode * next[26];
    bool isEnd;
    TrieNode() {
        c = ' ';
        for (int i = 0;i < 26;i++) {
            next[i] = NULL;
        }
        isEnd = false;
    }
    TrieNode(char c) {
        this->c = c;
        for (int i = 0;i < 26;i++) {
            next[i] = NULL;
        }
        isEnd = false;
    }
};


class Trie {
public:
    TrieNode * root;
    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode * current = root;
        for (int i = 0;i < word.length();i++) {
            if (current->next[word[i] - 'a'] != NULL) {
                current = current->next[word[i] - 'a'];
            }
            else {
                TrieNode * node = new TrieNode(word[i]);
                current->next[word[i] - 'a'] = node;
                current = node;
            }
        }
        current->isEnd = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode * current = root;
        for (int i = 0;i < word.length();i++) {
            if (current->next[word[i] - 'a'] != NULL) {
                current = current->next[word[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return current->isEnd;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode * current = root;
        for (int i = 0;i < prefix.length();i++) {
            if (current->next[prefix[i] - 'a'] != NULL) {
                current = current->next[prefix[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
