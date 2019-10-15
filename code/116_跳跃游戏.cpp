#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;
///动态规划
bool canJump(vector<int> &A) {
    int n = A.size();
    if (n == 0) return false;
    int dp[n];
    for (int i = 0;i < n;i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (dp[j] == 1 && A[j] >= i - j) {
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[n-1] == 0) return false;
    return true;
}

///贪心
bool canJump(vector<int> &A) {
    int n = A.size();
    if (n == 0) return false;
    if (n == 1) return true;
    int max_gap = 0;
    int cur = 0;
    while (max_gap >= cur) {
        max_gap = max(max_gap,cur + A[cur]);
        cur ++;
        if (max_gap >= A.size()-1)
            return true;
    }
    return false;
}

int main() {
    return 0;
}
