#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int backPack(int m, vector<int> &A) {
    int n = A.size();
    int dp[n+1][m+1];
    for (int i = 0;i < n+1;i++) {
        for (int j = 0;j < m+1;j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < m+1;j++) {
            if (j >= A[i-1])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-A[i-1]] + A[i-1]);
            else
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main() {
    int a[4] = {3,4,8,5};
    vector<int> test(a,a+4);
    cout << backPack(10,test) << endl;
    return 0;
}
