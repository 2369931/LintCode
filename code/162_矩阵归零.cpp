#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();
    vector<pair<int,int>> record;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (matrix[i][j] == 0) {
                pair<int,int> temp(i,j);
                record.push_back(temp);
            }
        }
    }
    for (int j = 0;j < record.size();j++) {
        for (int i = 0;i < n;i++) {
            matrix[record[j].first][i] = 0;
        }
        for (int i = 0;i < m;i++) {
            matrix[i][record[j].second] = 0;
        }
    }
}

int main() {
}

