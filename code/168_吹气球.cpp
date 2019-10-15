#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int> &nums) {
    int result = 0;
    int n = nums.size();
    if (n == 0) return result;
    else if (n == 1) return nums[0];
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int dp[n+2][n+2];
    for (int i = 0;i <= n+1;i++) {
        for (int j = 0;j <= n+1;j++) {
            dp[i][j] = 0;
        }
    }
    for (int l = 1;l <= n;l++) {
        for (int i = 1;i <= n - l + 1;i++) {
            int j = i + l - 1;
            for (int k = i;k <= j;k++) {
                dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1]+ dp[k+1][j]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    int a[4] = {4,1,5,10};
    vector<int> test(a, a+4);
    cout << maxCoins(test) << endl;
    return 0;
}
