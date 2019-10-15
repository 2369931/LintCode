#include <iostream>
#include <string>

using namespace std;

bool isMatch(string &s, string &p) {
    if (s == "" && p == "")
        return true;
    if (s == "*" || p == "*")
        return true;
    int n = s.length();
    int m = p.length();
    int dp[n+1][m+1];
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= m;j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1;i <= n;i++) {
        if (dp[i-1][0] == 1 && s[i-1] == '*') {
            dp[i][0] = 1;
        }
        else {
            dp[i][0] = 0;
        }
    }
    for (int i = 1;i <= m;i++) {
        if (dp[0][i-1] == 1 && p[i-1] == '*') {
            dp[0][i] = 1;
        }
        else {
            dp[0][i] = 0;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (s[i-1] == '?' || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (s[i-1] == '*' || p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else {
                if (s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
}
