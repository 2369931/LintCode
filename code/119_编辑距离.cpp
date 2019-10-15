#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>

using namespace std;

int minDistance(string &word1, string &word2) {
    int n = word1.length();
    int m = word2.length();
    if (n == 0 && m == 0) return 0;
    int dp[n + 1][m + 1];
    for (int i = 0;i <= n;i++) {
        dp[i][0] = i;
    }
    for (int i = 0;i <= m;i++) {
        dp[0][i] = i;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string a = "mart";
    string b = "karma";
    cout << minDistance(a,b) << endl;
    return 0;
}
