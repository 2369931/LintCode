#include <iostream>
#include <vector>

using namespace std;

int getMoneyAmount(int n) {
    vector<vector<int> > dp(n+1,vector<int>(n+1,INT_MAX));
    for (int i = 1;i < n;i++) {
        dp[i][i] = 0;
        dp[i][i+1] = i;
    }
    dp[n][n] = 0;
    for (int range = 2;range < n;range++) {
        for (int i = 1;i < n;i++) {
            if (i + range <= n) {
                for (int j = i+1;j < i+range;j++) {
                    dp[i][i+range] = min(dp[i][i+range],max(dp[i][j-1], dp[j+1][i+range]) + j);
                }
            }
        }
    }
    return dp[1][n];
}
int main() {
    cout << getMoneyAmount(10) << endl;
    return 0;
}
