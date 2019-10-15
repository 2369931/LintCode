#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

bool exist(vector<vector<char> > &board, string word) {
    int n = board.size();
    if (n == 0) return false;
    int m = board[0].size();
    bool result = false;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (board[i][j] == word[0]) {
                result = DFS(board,i,j,0,word);
                if (result == true)
                    return true;
            }
        }
    }
    return false;
}

bool DFS(vector<vector<char> > &board, int i, int j, int length, string word) {
    if (length == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[length] != board[i][j]) return false;
    board[i][j] += 27;
    bool result =  (DFS(board,i+1,j,length+1,word) || DFS(board,i,j+1,length+1,word) ||
                    DFS(board,i-1,j,length+1,word) || DFS(board,i,j-1,length+1,word));
    board[i][j] -= 27;
    return result;
}

vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
    vector<string> result;
    for (int i = 0;i < words.size();i ++) {
        if (exist(board, words[i])) {
            result.push_back(words[i]);
        }
    }
    return result;
}

int main() {
}
