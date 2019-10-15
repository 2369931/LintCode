#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

/*class TrieNode {
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

class WordDictionary {
public:
    TrieNode * root;
    WordDictionary() {
        // do intialization if necessary
        root = new TrieNode();
    }
    void addWord(string &word) {
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

    bool search(string &word) {
        TrieNode * current = root;
        for (int i = 0;i < word.length();i++) {
            if (word[i] == '.') {
                continue;
            }
            else if (current->next[word[i] - 'a'] != NULL) {
                current = current->next[word[i] - 'a'];
            }
            else {
                return false;
            }
        }
        if (current == root)
            return false;
        return current->isEnd;
    }
};*/


class WordDictionary {
public:
    map<string,int> record;
    vector<string> book;
    void addWord(string &word) {
        map<string,int>::iterator it = record.find(word);
        if (it == record.end()) {
            book.push_back(word);
            record[word] = 1;
        }
    }

    bool compare(string &a, string &b) {
        int n = a.length();
        int m = b.length();
        if (n != m) {
            return false;
        }
        else {
            for (int i = 0;i < n;i ++) {
                if (a[i] == '.' || b[i] == '.') {
                    continue;
                }
                else if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    bool search(string &word) {
        for (int i = 0;i < book.size();i++) {
            if (compare(word, book[i])) {
                return true;
            }
        }
        return false;
    }
};
