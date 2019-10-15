#include <iostream>
#include <vector>

using namespace std;

int judge(int** matrix, int x1, int y1, int x2, int y2) {
    int a1 = x1 - 1;
    int a2 = y1 - 1;
    int b1 = x1 - 1;
    int b2 = y2;
    int c1 = x2;
    int c2 = y1 - 1;
    int d1 = x2;
    int d2 = y2;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (a1 < 0 || a2 < 0) {
        a = 0;
    }
    else {
        a = matrix[a1][a2];
    }
    if (b1 < 0 || b2 < 0) {
        b = 0;
    }
    else {
        b = matrix[b1][b2];
    }
    if (c1 < 0 || c2 < 0) {
        c = 0;
    }
    else {
        c = matrix[c1][c2];
    }
    if (d1 < 0 || d2 < 0) {
        d = 0;
    }
    else {
        d = matrix[d1][d2];
    }
    return d - b - c + a;
}

vector<vector<int> > submatrixSum(vector<vector<int> > &matrix) {
    int n = matrix.size();
    vector<vector<int>> result(0,vector<int>(0));
    if (n == 0) {
        return result;
    }
    int m = matrix[0].size();
    int **sum = new int*[n];
    for(int i = 0;i < n;i++){
        sum[i] = new int[m];
    }
    sum[0][0] = matrix[0][0];
    for (int i = 1;i < n;i++) {
        sum[i][0] = sum[i-1][0] + matrix[i][0];
    }
    for (int i = 1;i < m;i++) {
        sum[0][i] = sum[0][i-1] + matrix[0][i];
    }
    for (int i = 1;i < n;i++) {
        for (int j = 1;j < m;j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            for (int p = i;p < n;p++) {
                for (int q = j;q < m;q++) {
                    if (judge(sum,i,j,p,q) == 0) {
                        vector<int> start;
                        start.push_back(i);
                        start.push_back(j);
                        vector<int> end;
                        end.push_back(p);
                        end.push_back(q);
                        result.push_back(start);
                        result.push_back(end);
                        return result;
                    }
                }
            }
        }
    }
    return result;
}


