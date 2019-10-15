#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int houseRobber(vector<int> &nums,int start, int end) {
    vector<int> temp;
    for (int i = start;i <= end;i ++) {
        temp.push_back(nums[i]);
    }
    int n = end - start + 1;
    int dp[n];
    dp[0] = temp[0];
    dp[1] = max(temp[0],temp[1]);
    for (int i = 2;i < n;i++) {
            dp[i] = max(dp[i-2] + temp[i], dp[i-1]);
    }
    return dp[n-1];
}

int houseRobber2(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return nums[0];
    }
    if (n == 2) {
        return max(nums[0],nums[1]);
    }
    else {
        return max(houseRobber(nums,0,n-2),houseRobber(nums,1,n-1));
    }
}

int main() {
    int a[5] = {1,3,2,1,5};
    vector<int> test(a,a+5);
    cout << houseRobber2(test) << endl;
    return 0;
}

