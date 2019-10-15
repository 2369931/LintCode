#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return true;
    }
    int dp[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (i == j) {
                dp[i][j] = nums[i];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    for (int len = 1;len < n;len ++) {
        for (int i = 0;i + len < n;i++) {
            int j = i + len;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1] >= 0;
}

int main() {
    int a[4] = {};
    vector<int> test(a,a+4);
    cout << PredictTheWinner(test) << endl;
    return 0;
}
