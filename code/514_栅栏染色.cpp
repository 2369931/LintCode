#include <iostream>
#include <cmath>

using namespace std;

int numWays(int n, int k) {
    if (n == 0 || k == 0) {
        return 0;
    }
    int dp[n] = {0};
    dp[0] = k;
    dp[1] = k*k;
    for (int i = 2;i < n;i++) {
        dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);
    }
    return dp[n-1];
}

int main() {
    cout << numWays(2,2) << endl;
    return 0;
}
