#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    int n = matrix.size();
    if (n == 0) return result;
    int m = matrix[0].size();
    int a[n][m];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            a[i][j] = 0;
        }
    }
    int i = 0;
    int j = 0;
    int direct = 0;
    int count = 0;
    while (count < m*n) {
        if (direct == 0) {
            if (j < m && a[i][j] == 0) {
                result.push_back(matrix[i][j]);
                count ++;
                a[i][j] = 1;
                j ++;
            }
            else {
                i ++;
                j --;
                direct = 1;
            }
        }
        if (direct == 1) {
            if (i < n && a[i][j] == 0) {
                result.push_back(matrix[i][j]);
                count ++;
                a[i][j] = 1;
                i ++;
            }
            else {
                i --;
                j --;
                direct = 2;
            }
        }
        if (direct == 2) {
            if (j >= 0 && a[i][j] == 0) {
                result.push_back(matrix[i][j]);
                count ++;
                a[i][j] = 1;
                j --;
            }
            else {
                i --;
                j ++;
                direct = 3;
            }
        }
        if (direct == 3) {
            if (i >= 0 && a[i][j] == 0) {
                result.push_back(matrix[i][j]);
                count ++;
                a[i][j] = 1;
                i --;
            }
            else {
                i ++;
                j ++;
                direct = 0;
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int> > result (3,vector<int>(4, 0));
    int temp = 1;
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[0].size();j++) {
            result[i][j] = temp;
            temp++;
        }
    }
    vector <int> record = spiralOrder(result);
    for (int i = 0;i < record.size();i++) {
        cout << record[i] << " ";
    }
    return 0;
}
