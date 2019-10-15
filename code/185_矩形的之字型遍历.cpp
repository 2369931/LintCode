#include <iostream>
#include <vector>

using namespace std;

vector<int> printZMatrix(vector<vector<int> > &matrix) {
    vector<int> result;
    int n = matrix.size();
    if (n == 0) return result;
    int m = matrix[0].size();
    if (m == 1) {
        for (int i = 0;i < n;i++) {
            result.push_back(matrix[i][0]);
        }
        return result;
    }
    else if (n == 1) {
        return matrix[0];
    }
    int direct = 0;
    int num = n*m;
    int i = 0;
    int j = 0;
    result.push_back(matrix[i][j]);
    j += 1;
    result.push_back(matrix[i][j]);
    while (num > 2) {
        while (i + 1 < n && j - 1 >= 0) {
            i = i + 1;
            j = j - 1;
            result.push_back(matrix[i][j]);
            num --;
        }
        if (i + 1 < n) {
            i += 1;
            result.push_back(matrix[i][j]);
            num --;
        }
        else if (j + 1 < m) {
            j += 1;
            result.push_back(matrix[i][j]);
            num --;
        }
        while (i - 1 >= 0 && j + 1 < m) {
            i = i - 1;
            j = j + 1;
            result.push_back(matrix[i][j]);
            num --;
        }
        if (j + 1 < m) {
            j += 1;
            result.push_back(matrix[i][j]);
            num --;
        }
        else if (i + 1 < n) {
            i += 1;
            result.push_back(matrix[i][j]);
            num --;
        }
    }
    return result;
}

int main() {
    vector<vector<int> > matrix;
    int a[3] = {1,2,3};
    int b[3] = {5,6,7};
    int c[3] = {9,10,11};
    int d[3] = {12,13,14};
    vector<int> v_a(a,a+3);
    vector<int> v_b(b,b+3);
    vector<int> v_c(c,c+3);
    vector<int> v_d(d,d+3);
    matrix.push_back(v_a);
    matrix.push_back(v_b);
    matrix.push_back(v_c);
    matrix.push_back(v_d);
    vector<int> result = printZMatrix(matrix);
    for (int i = 0;i < result.size();i ++) {
        cout << result[i] << " ";
    }
    return 0;
}
