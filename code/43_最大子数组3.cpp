#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxSubArray(vector<int> &nums, int k) {
    int n = nums.size();
    if (k > n) {
        return 0;
    }
    int local[n+1][k+1];
    int global[n+1][k+1];
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= k;j++) {
            local[i][j] = global[i][j] = 0;
        }
    }
    for (int i = 1;i <= n;i++) {
        local[i][0] = -999999;
        for (int j = 1;j <= k;j++) {
            if (i < j) {
                local[i][j] = global[i][j] = -999999;
                continue;
            }
            local[i][j] = max(local[i-1][j],global[i-1][j-1]) + nums[i-1];
            if (i == j) {
                global[i][j] = local[i][j];
            }
            else {
                global[i][j] = max(global[i-1][j],local[i][j]);
            }
        }
    }
    return global[n][k];
}

int main () {
    int a[9] = {2,-1,3,-4,5,-8,6,-7};
    //int a[8] = {2,-1,3,-4,5,-8,6,-7};
    //int a[6] = {1,-1,2,1,3,1};
    vector<int> test(a,a+9);
    int result = maxSubArray(test,4);
    cout << result << endl;
    //cout << result << endl;
    return 0;
}
