#include <iostream>
#include <vector>

using namespace std;

int kSum(vector<int> &A, int k, int target) {
    int dp[k+1][target+1];
    for (int i = 0;i <= k;i++) {
        for (int j = 0;j <= target;j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0;i < A.size();i++) {
        for (int j = k;j > 0;j--) {
            for (int l = target;l >= A[i];l--) {
                dp[j][l] += dp[j-1][l-A[i]];
            }
        }
    }
    return dp[k][target];
}

int main() {
    int a[5] = {1,2,3,4,7};
    vector<int> test(a,a+5);
    cout << kSum(test,3,8) << endl;
    return 0;
}
