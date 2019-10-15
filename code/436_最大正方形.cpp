#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <vector>

using namespace std;

bool judge(vector<vector<int>> &matrix, int i, int j, int n) {
    if (i + n - 1 < matrix.size() && j + n - 1 < matrix[0].size()) {
        for (int p = 0;p < n;p++) {
            for (int q = 0;q < n;q++) {
                if (matrix[i+p][j+q] != 1)
                    return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

int maxSquare(vector<vector<int>> &matrix) {
    int result = 0;
    int n = matrix.size();
    if (n == 0) {
        return result;
    }
    int m = matrix[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (matrix[i][j] == 1) {
                int a = 0;
                int b = 0;
                int p = i;
                int q = j;
                while (p < n && matrix[p][j] == 1) {
                    a ++;
                    p ++;
                }
                while (q < n && matrix[i][q] == 1) {
                    b ++;
                    q ++;
                }
                if (min(a,b) > result && judge(matrix,i,j,min(a,b))) {
                    result = min(a,b);
                }
            }
        }
    }
    return result*result;
}
