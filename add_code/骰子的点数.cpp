#include <iostream>

using namespace std;

void printProbabilitySum(int n) {
    if (n < 1) {
        return;
    }
    double dp[n+1][n*6+1] = {0};
    for (int i = 1;i <= 6;i++) {
        dp[1][i] = double(1)/6;
    }
    for (int i = 2;i <= n;i++) {
        for (int j = i;j <= 6*i;j++) {
            double temp = 0;
            for (int k = 1;k <= 6;k ++) {
                 temp += dp[i-1][max(0,j-k)];
            }
            dp[i][j] = temp / 6;
        }
    }
    for (int i = n;i <= 6*n;i++) {
        cout << i << " : " << dp[n][i] << endl;
    }
}

int main() {
    printProbabilitySum(5);
    return 0;
}
