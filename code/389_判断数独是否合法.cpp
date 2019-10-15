#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    int n = board.size();
    if (n == 0)
        return true;
    int m = board[0].size();
    for (int i = 0;i < n;i++) {
        vector<int> record(9,0);
        for (int j = 0;j < m;j++) {
            if (board[i][j] == '.') {
                continue;
            }
            else {
                int temp = (int)(board[i][j] - 48);
                if (record[temp] == 0) {
                    record[temp] = 1;
                }
                else {
                    return false;
                }
            }
        }
    }

    for (int i = 0;i < m;i++) {
        vector<int> record(9,0);
        for (int j = 0;j < n;j++) {
            if (board[j][i] == '.') {
                continue;
            }
            else {
                int temp = (int)(board[j][i] - 48);
                if (record[temp] == 0) {
                    record[temp] = 1;
                }
                else {
                    return false;
                }
            }
        }
    }

    for (int i = 0;i < n / 3;i++) {
        for (int j = 0;j < m / 3;j++) {
            vector<int> record(9,0);
            for (int k = 0;k < 3;k++) {
                for (int l = 0;l < 3;l++) {
                    if (board[3*i+k][3*j+l] != '.') {
                        int temp = (int)(board[3*i+k][3*j+l] - 48);
                        if (record[temp] == 0) {
                            record[temp] = 1;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
}
