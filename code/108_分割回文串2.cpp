#include <iostream>
#include <string>
#include <limits>

using namespace std;

int minCut(string &s) {
    int n = s.length();
    if (n == 0 || n == 1) return 0;
    int dp[n+1];
    for (int i = 0;i < n;i++) {
        dp[i] = 0;
    }
    dp[0] = -1;
    int record[n][n];
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < n;j ++) {
            record[i][j] = 0;
        }
    }
    for (int i = 0;i < n;i ++) {
        record[i][i] = 1;
    }
    for (int i = 0;i < n-1;i ++) {
        record[i][i+1] = (s[i] == s[i+1]);
    }
    for (int i = 0;i < n;i ++) {
        for (int j = i+2;j < n;j ++) {
            if (record[j+1][i-1] == 1 && s[j] == s[i])
                record[i][j] = 1;
        }
    }
     for (int length = 2; length < s.length(); length++) {
        for (int i = 0;i+length<s.length();i++){
            record[i][i+length] =
                record[i+1][i+length-1] && s[i]==s[i+length];
        }
    }
    for (int i = 1;i <= n;i++) {
        int min_value = INT_MAX;
        for (int j = 0;j < i;j++) {
            if (record[j][i-1]) {
                min_value = min(dp[j]+1,min_value);
            }
        }
        dp[i] = min_value;
    }
    return dp[n];
}

int main() {
    string test = "abba";
    cout << minCut(test) << endl;
    return 0;
}
