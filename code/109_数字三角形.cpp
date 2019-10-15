#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    int dp[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < triangle[i].size();j++) {
            int lo = max(0, j-1);
            int hi = min(j, i-1);
            dp[i][j] = min(dp[i-1][lo],dp[i-1][hi]) + triangle[i][j];
        }
    }
    int result = dp[n-1][0];
    for (int i = 1;i < n;i++) {
        if (result > dp[n-1][i]) {
            result = dp[n-1][i];
        }
    }
    return result;
}
