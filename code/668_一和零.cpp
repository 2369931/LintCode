#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMaxForm(vector<string> &strs, int m, int n) {
    int len = strs.size();
    int res = 0;
    int dp[m+1][n+1];
    for (int l = 0;l <= m;l++) {
        for (int k = 0;k <= n;k++) {
            dp[l][k] = 0;
        }
    }
    for (int i = 0;i < len;i++) {
        int number_0 = 0;
        int number_1 = 0;
        for (int j = 0;j < strs[i].length();j++) {
            if (strs[i][j] == '0') {
                number_0 ++;
            }
            else {
                number_1 ++;
            }
        }
        if (number_0 > m || number_1 > n) {
            continue;
        }
        for (int l = m;l >= number_0;l--) {
            for (int k = n;k >= number_1;k--) {
                dp[l][k] = max(dp[l][k],dp[l-number_0][k-number_1] + 1);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string a[5] = {"10", "0001", "111001", "1", "0"};
    vector<string> test(a,a+5);
    cout << findMaxForm(test,7,7) << endl;
    return 0;
}
