#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0;i < n/2;i++) {
        int j = n - 1 - i;
        for (int k = 0;k < n;k++) {
            swap(matrix[i][k],matrix[j][k]);
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main() {
}
