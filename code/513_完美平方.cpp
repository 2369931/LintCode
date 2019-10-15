#include <iostream>
#include <cmath>

using namespace std;

int numSquares(int n) {
    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2;i <= n;i++) {
        if ((int)sqrt(i) * (int)sqrt(i) == i) {
            dp[i] = 1;
            continue;
        }
        int min_count = INT_MAX;
        for (int j = 1;j*j <= i;j++) {
            min_count = min(min_count,dp[j*j] + dp[i-j*j]);
        }
        dp[i] = min_count;
    }
    return dp[n];
}

int main() {
    cout << numSquares(13) << endl;
    return 0;
}
