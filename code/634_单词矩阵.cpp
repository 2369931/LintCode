#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> wordSquares(vector<string>& words) {
    vector<vector<string>> res;
    if (words.size() == 0) {
        return res;
    }
    unordered_map<string, set<string>> m;
    int n = words[0].size();
    for (string word : words) {
        for (int i = 0; i < n; ++i) {
            string key = word.substr(0, i);
            m[key].insert(word);
        }
    }
    vector<vector<char>> mat(n, vector<char>(n));
    helper(0, n, mat, m, res);
    return res;
}

void helper(int i, int n, vector<vector<char>>& mat, unordered_map<string, set<string>>& m, vector<vector<string>>& res) {
    if (i == n) {
        vector<string> out;
        for (int j = 0; j < n; ++j) out.push_back(string(mat[j].begin(), mat[j].end()));
        res.push_back(out);
        return;
    }
    string key = string(mat[i].begin(), mat[i].begin() + i);
    for (string str : m[key]) {
        mat[i][i] = str[i];
        int j = i + 1;
        for (; j < n; ++j) {
            mat[i][j] = str[j];
            mat[j][i] = str[j];
            if (!m.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
        }
        if (j == n) helper(i + 1, n, mat, m, res);
    }
}

