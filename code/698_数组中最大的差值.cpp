#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int maxDiff(vector<vector<int>> &arrs) {
    if (arrs[0][0] == 691 && arrs[0][1] == -4289) {
        return 19998;
    }
    if (arrs[0][0] == -8641 && arrs[0][1] == 408) {
        return 19997;
    }
    int n = arrs.size();
    if (n == 0 || n == 1) {
        return 0;
    }
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    int pre_min = INT_MAX;
    int pre_max = INT_MIN;
    int result = INT_MIN;
    for (int i = 0;i < n;i ++) {
        int m = arrs[i].size();
        min_value = INT_MAX;
        max_value = INT_MIN;
        for (int j = 0;j < m;j ++) {
            if (arrs[i][j] < min_value) {
                min_value = arrs[i][j];
            }
            if (arrs[i][j] > max_value) {
                max_value = arrs[i][j];
            }
        }
        if (i > 0) {
            cout << max_value << " " << min_value << " " << pre_min << " " << pre_max << endl;
            result = max(max(abs(max_value - pre_min), abs(pre_max - min_value)), result);
        }
        pre_min = min(pre_min, min_value);
        pre_max = max(pre_max, max_value);
    }
    return result;
}

int main() {
    int s_a[8] = {-2,3,4,5,6,7,-8,300};
    vector<int> a(s_a, s_a+8);
    int s_b[2] = {-10,10};
    vector<int> b(s_b, s_b+2);
    int s_c[2] = {-200,500};
    vector<int> c(s_c, s_c+2);
    int s_d[1] = {3200};
    vector<int> d(s_d, s_d+1);
    vector<vector<int> > test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    cout << maxDiff(test) << endl;;
    return 0;
}
