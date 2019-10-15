#include <iostream>
#include <string>

using namespace std;

int longestCommonSubsequence(string &A, string &B) {
    if (A == "" || B == "") return 0;
    int n = A.length();
    int m = B.length();
    int dp[n+1][m+1];
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= m;j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string A = "abcd";
    string B = "edca";
    cout << longestCommonSubsequence(A,B) << endl;
    return 0;
}
