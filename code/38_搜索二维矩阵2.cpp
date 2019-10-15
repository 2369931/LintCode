#include <iostream>
#include <vector>

using namespace std;

int searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0) {
        return 0;
    }
    int result = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0;i < m;i++) {
        if (matrix[i][0] > target) {
            continue;
        }
        for (int j = 0;j < n;j++) {
            if (matrix[0][j] > target) {
                break;
            }
            if (matrix[i][j] == target) {
                result += 1;
            }
        }
    }
    return result;
}

int main() {
}
