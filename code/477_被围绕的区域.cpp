#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void dfs(vector<vector<char>> &board, int i, int j) {
    if(board[i][j]=='X' || board[i][j] == '*') return;
    board[i][j] = '*';
    if (i > 0)
        dfs(board,i-1,j);
    if (j > 0)
        dfs(board,i,j-1);
    if (i < board.size()-1)
        dfs(board,i+1,j);
    if (j < board[0].size()-1)
        dfs(board,i,j+1);
}

void surroundedRegions(vector<vector<char>> &board) {
    int n = board.size();
    if (n == 0) {
        return;
    }
    int m = board[0].size();
    if (m == 0) {
        return;
    }
    for (int i = 0;i< n;i++) {
        if (board[i][0] == 'O') {
            dfs(board,i,0);
        }
        if (board[i][m-1] == 'O') {
            dfs(board,i,m-1);
        }
    }
    for (int j = 0;j < m;j++){
        if (board[0][j] == 'O') {
            dfs(board,0,j);
        }
        if (board[n-1][j] == 'O') {
            dfs(board,n-1,j);
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

