#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) return 0;
    int n = obstacleGrid[0].size();
    int dp[m+1][n+1];
    for (int i = 0;i <= m;i++) {
        for (int j = 0;j <= n;j++) {
            dp[i][j] = 0;
        }
    }
    dp[1][0] = 1;
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            if (obstacleGrid[i-1][j-1] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[m][n];
}

int main() {
    cout << uniquePaths(3,3) << endl;
    return 0;
}
