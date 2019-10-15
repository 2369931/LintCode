#include <iostream>
#include <vector>

using namespace std;

int kthSmallest(vector<vector<int> > &matrix, int k) {
    int n = matrix.size();
    if (n == 0 || k < 0) {
        return 0;
    }
    vector<int> row(matrix.size(),0);
    int result = 0;
    for (int i = 0;i < k;i++) {
        int temp = INT_MAX;
        int flag = 0;
        for (int j = 0;j < row.size();j++) {
            if (row[j] < matrix[0].size()) {
                if (matrix[j][row[j]] < temp) {
                    temp = matrix[j][row[j]];
                    flag = j;
                }
            }
        }
        row[flag] += 1;
        result = temp;
    }
    return result;
}

int main() {
    return 0;
}
