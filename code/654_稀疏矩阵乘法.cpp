#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > multiply(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<vector<int> > res;
    int n = A.size();
    if (n == 0) {
        return res;
    }
    int m = A[0].size();
    map<int,bool> rec_a;
    map<int,bool> rec_b;
    for (int i = 0;i < n;i++) {
        rec_a[i] = true;
        for (int j = 0;j < m;j++) {
            if (A[i][j] != 0) {
                rec_a[i] = false;
                break;
            }
        }
    }
    int k = B[0].size();
    for (int i = 0;i < m;i++) {
        rec_b[i] = true;
        for (int j = 0;j < k;j++) {
            if (B[i][j] != 0) {
                rec_b[i] = false;
                break;
            }
        }
    }
    res = vector<vector<int> > (n, vector<int>(k,0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < k;j++) {
            if (!rec_a[i] && !rec_b[j]) {
                int sum = 0;
                for (int l = 0;l < m;l++) {
                    sum += A[i][l] * B[l][j];
                }
                res[i][j] = sum;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
