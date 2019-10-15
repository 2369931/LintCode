#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n));
    if (n == 0) return result;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            result[i][j] = 0;
        }
    }
    int value = 1;
    int i = 0;
    int j = 0;
    while (value <= n*n) {
        while (j < n && result[i][j] == 0) {
            result[i][j] = value;
            value ++;
            j ++;
        }
        j --;
        i ++;
        while (i < n && result[i][j] == 0) {
            result[i][j] = value;
            value ++;
            i ++;
        }
        i --;
        j --;
        while (j >= 0 && result[i][j] == 0) {
            result[i][j] = value;
            value ++;
            j --;
        }
        j ++;
        i --;
        while (i >= 0 && result[i][j] == 0) {
            result[i][j] = value;
            value ++;
            i --;
        }
        i ++;
        j ++;
    }
    return result;
}

int main() {
    vector<vector<int> > test = generateMatrix(4);
    for (int i = 0;i < test.size();i++) {
        for (int j = 0;j < test.size();j++) {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
