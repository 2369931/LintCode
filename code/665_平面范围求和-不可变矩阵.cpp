#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> m_matrix;
    NumMatrix(vector<vector<int>> matrix) {
        for (int i = 0;i < matrix.size();i++) {
            vector<int> temp;
            for (int j = 0;j < matrix[i].size();j++) {
                temp.push_back(matrix[i][j]);
            }
            m_matrix.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1;i <= row2;i++) {
            for (int j = col1;j <= col2;j++) {
                res += m_matrix[i][j];
            }
        }
        return res;
    }
};

