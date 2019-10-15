#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double sum(vector<int> &nums, int s, int length) {
    double res = 0;
    for (int i = s;i < s + length;i++) {
        res += nums[i];
    }
    return res;
}

double maxAverage(vector<int> &nums, int k) {
    int n = nums.size();
    if (n <= k) {
        return (double)sum(nums,0,n)/n;
    }
    double res = (double)INT_MIN;
    //double dp[n][n+1];
    double ** dp = new double *[n];
    for(size_t row = 0; n != row; ++row)
    {
        dp[row] = new double[n+1];
    }
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j <= n;j++) {
            dp[i][j] = 0;
        }
    }
    for (int j = k;j <= n;j++) {
        for (int i = 0;i < n;i++) {
            if (i + j - 1 < n) {
                if (j == k) {
                    dp[i][j] = sum(nums,i,k);
                }
                else {
                    dp[i][j] = dp[i][j-1] + nums[i+j-1];
                }
                double temp = dp[i][j]/j;
                if (temp > res) {
                    res = temp;
                }
            }
        }
    }
    delete[] dp;
    return res;
}

/*double maxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> sums;// = nums;
    for (int i = 0;i < nums.size();i++) {
        sums[i] = (double)nums[i];
    }
    for (int i = 1; i < n; ++i) {
        sums[i] = sums[i - 1] + nums[i];
    }
    double res = (double)sums[k - 1] / k;
    for (int i = k; i < n; ++i) {
        double t = sums[i];
        if (t > res * (i + 1)) res = t / (i + 1);
        for (int j = i - k; j >= 0; --j) {
            t = sums[i] -  sums[j];
            if (t > res * (i - j)) res = t / (i - j);
        }
    }
    return res;
}*/


int main() {
    //int a[6] = {1,12,-5,-6,50,3};
    long long a[4] = {-2147483648,-2147483648,-2147483648,-2147483648};
    vector<int> test(a,a+4);
    cout << maxAverage(test,2) << endl;
    return 0;
}


