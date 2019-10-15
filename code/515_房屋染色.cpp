#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int minCost(vector<vector<int> > &costs) {
    int n = costs.size();
    if (n == 0) {
        return 0;
    }
    int dp[n][3];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < 3;j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < 3;j++) {
            int min_value = INT_MAX;
            for (int k = 0;k < 3; k++) {
                if (k == j) continue;
                min_value = min(min_value, dp[i-1][k]);
            }
            dp[i][j] = min_value + costs[i][j];
        }
    }
    return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}

int main() {
    return 0;
}
