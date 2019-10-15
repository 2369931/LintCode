#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0) {
        return false;
    }
    int index = -1;
    if (target < matrix[0][0]) {
        return false;
    }
    for (int i = 0;i < matrix.size();i++) {
        if (target == matrix[i][0]) {
            return true;
        }
        else if (target < matrix[i][0]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        index = matrix.size();
    }
    for (int i = 1;i < matrix[index-1].size();i++) {
        if (target == matrix[index-1][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
