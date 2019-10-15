#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int MinAdjustmentCost(vector<int> &A, int target) {
    int n = A.size();
    if (n < 2) return 0;
    int dp[n][101];
    for (int i = 0;i < 101;i++) {
        dp[0][i] = abs(i - A[0]);
    }
    for (int i = 1;i < A.size();i++) {
        for (int j = 0;j < 101;j++) {
            dp[i][j] = INT_MAX;
            int dif = abs(j - A[i]);
            int start = max(0,j - target);
            int end = min(100,j + target);
            for (int k = start;k <= end;k++) {
                dp[i][j] = min(dp[i][j],dp[i-1][k] + dif);
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0;i < 101;i++) {
        result = min(result,dp[n-1][i]);
    }
    return result;
}

int main() {
    int a[4] = {1,4,2,3};
    vector<int> test(a,a+4);
    cout << MinAdjustmentCost(test,1) << endl;
    return 0;
}
