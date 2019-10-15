#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    int dp[amount+1];
    dp[0] = 0;
     for (int i = 1;i <= amount;i++) {
         dp[i] = INT_MAX;
         for (int j = 0;j < n;j++) {
             if (i >= coins[j] && dp[i-coins[j]] != INT_MAX &&
                 dp[i-coins[j]] +1 < dp[i]) {
                     dp[i] = dp[i-coins[j]] + 1;
                 }
         }
     }
    if (dp[amount] == INT_MAX) {
        return -1;
    }
    else {
        return dp[amount];
    }
}


int main() {
    int a[3] = {1,2,5};
    vector<int> test(a,a+3);
    cout << coinChange(test,11) << endl;
    return 0;
}
