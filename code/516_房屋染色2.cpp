#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int minCostII(vector<vector<int>> &costs) {
    int n = costs.size();
    if (n == 0) {
        return 0;
    }
    int m = costs[0].size();
    if (n >= 2 && m <= 1) {
        return 0;
    }
    int dp[n][m];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0;i < m;i++) {
        dp[0][i] = costs[0][i];
    }
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < m;j++) {
            dp[i][j] = INT_MAX;
            for (int k = 0;k < m; k++) {
                if (k == j) continue;
                dp[i][j] = min(dp[i][j],dp[i-1][k] + costs[i][j]);
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0;i < m ;i++) {
        result = min(result,dp[n-1][i]);
    }
    return result;
}
