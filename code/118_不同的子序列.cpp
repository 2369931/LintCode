#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>

using namespace std;
///¶¯Ì¬¹æ»®
int numDistinct(string S, string T) {
    int n = S.length();
    int m = T.length();
    if (n == 0 || m == 0) return 0;
    int dp[n + 1][m + 1];
    for (int i = 0;i <= n;i++) {
        dp[i][0] = 1;
    }
    for (int i = 1;i <= m;i++) {
        dp[0][i] = 0;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (S[i] != T[j]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main() {
    cout << numDistinct("rabbbit","rabbit") << endl;
    return 0;
}
