#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    int dp[n+1][m+1];
    for (int i = 0;i <= n;i ++) {
        for (int j = 0;j <= m;j ++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 2;i <= n;i ++) {
        dp[i][0] = INT_MAX;
    }
    for (int i = 2;i <= m;i ++) {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            //int lo = max(i-1,0);
            //int hi = max(j-1,0);
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
        }
    }
    return dp[n][m];
}

int main() {
    return 0;
}
