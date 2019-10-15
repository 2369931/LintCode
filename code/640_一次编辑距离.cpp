#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isOneEditDistance(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    if (abs(n-m) >= 2) {
        return false;
    }
    if (s == t) {
        return false;
    }
    int dp[n][m];
    for (int i = 0;i < n;i++) {
        dp[i][0] = i;
    }
    for (int i = 0;i < m;i++) {
        dp[0][i] = i;
    }
    for (int i = 1;i < n;i++) {
        for (int j = 1;j < m;j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
        }
    }

    if (dp[n-1][m-1] == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string s = "aDb";
    string t = "adb";
    cout << isOneEditDistance(s,t) << endl;
    return 0;
}
