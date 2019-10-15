#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool canPartition(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
        return false;
    }
    sort(nums.begin(),nums.end());
    int sum = 0;
    int dp[n] = {0};
    for (int i = 0;i < n;i++) {
        sum += nums[i];
        dp[i] = sum;
    }
    if (sum%2 == 1) {
        return false;
    }
    for (int i = 0;i < n;i++) {
        if (dp[i] == sum/2) {
            return true;
        }
        else if (dp[i] > sum/2){
            for (int j = 0;j < i;j++) {
                if (dp[i] - dp[j] == sum/2 || dp[i] - nums[j] == sum/2) {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

int main() {
    int a[194] = {55,8,31,42,24,42,5,39,67,64,10,55,11,22,16,74,64,63,7,35,35,36,32,42,81,57,1,71,47,74,38,26,47,55,25,23,24,25,68,51,15,76,3,50,27,27,71,82,59,45,55,80,89,1,90,55,40,9,58,68,22,1,78,61,84,22,48,25,85,27,67,44,76,18,45,32,61,3,80,47,7,82,70,37,63,70,74,5,52,40,48,66,39,33,77,56,3,38,6,41,64,63,63,47,90,85,22,56,13,69,74,1,60,41,75,41,42,47,4,6,40,70,75,80,58,75,57,45,62,14,54,21,67,88,52,63,67,8,75,48,14,77,69,56,77,60,33,55,6,61,89,53,54,19,39,39,63,47,11,79,22,61,1,5,14,54,60,90,42,43,71,60,7,9,29,6,60,17,70,47,50,22,29,11,11,1,68,70,79,58,72,89,49,71};
    vector<int> test(a,a+194);
    cout << canPartition(test) << endl;
    return 0;
}
