#include <iostream>
#include <vector>

using namespace std;

int backPackVI(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int dp[target+1] = {0};
    dp[0] = 1;
    for (int i = 1;i <= target;i++) {
        for (int j = 0;j < n;j++) {
            if (i >= nums[j]) {
                dp[i] += dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}

int main() {
    int a[3] = {1,2,4};
    vector<int> test(a,a+3);
    cout << backPackVI(test,4) << endl;
    return 0;
}
