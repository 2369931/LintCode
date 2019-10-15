#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool judgeQ(vector<string> &temp, int row, int col) {
    if (temp.size() == 0) {
        return false;
    }
    if (row >= temp.size() || col >= temp[0].size()) {
        return false;
    }
    for (int i = 0;i <= row;i++) {
        for (int j = 0;j < temp.size();j++) {
            if (temp[i][j] == 'Q') {
                if (i == row || j == col || abs(row - i) == abs(col - j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void placeQ(vector<vector<string> > &result, vector<string> &queen,int row, int col) {
    int n = queen.size();
    if (row == n || col == n) {
        return;
    }
    if (judgeQ(queen,row,col)) {
        queen[row][col] = 'Q';
        if (row == n - 1) {
            result.push_back(queen);
            queen[row][col] = '.';
            return;
        }
        else {
            placeQ(result,queen,row+1,0);
            queen[row][col] = '.';
            placeQ(result,queen,row,col+1);
        }
    }
    else {
        if (col == n-1) {
            return;
        }
        else {
            placeQ(result,queen,row,col+1);
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    string temp;
    vector<string> queen;
    vector<vector<string> > result;
    if (n <= 0) {
        return result;
    }
    for (int i = 0;i < n;i++) {
        temp += '.';
    }
    for (int i = 0;i < n;i++) {
        queen.push_back(temp);
    }

    placeQ(result,queen,0,0);
    return result;
}

int main() {
    vector<vector<string> > result = solveNQueens(4);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << endl;
        }
        cout << "*************" << endl;
    }
    return 0;
}
