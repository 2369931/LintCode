#include <iostream>
#include <vector>

using namespace std;

bool firstWillWin(vector<int> &values) {
    int n = values.size();
    if (n == 0) return false;
    if (n == 1 || n == 2) return true;
    int sum = 0;
    if (n%3 == 0) {
        for (int i = 0;i < n;i++) {
            if ((i+1)%3 == 0) {
                sum -= values[i];
            }
            else {
                sum += values[i];
            }
        }
        if (sum > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((n-1)%3 == 0) {
        sum = 0;
        sum = values[0];
        for (int i = 1;i < n;i++) {
            if (i%3 == 0) {
                sum -= values[i];
            }
            else {
                sum += values[i];
            }
        }
        if (sum > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((n-2)%3 == 0) {
        sum = 0;
        sum = values[0] + values[1];
        for (int i = 1;i < n;i++) {
            if ((i-1)%3 == 0) {
                sum -= values[i];
            }
            else {
                sum += values[i];
            }
        }
        if (sum > 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool firstWillWin(vector<int> &values) {
    int n = values.size();
    if (n == 0) return false;
    if (n == 1 || n == 2) return true;
    int dp[n+1];
    dp[n] = 0;
    dp[n-1] = values[n-1];
    dp[n-2] = values[n-1] + values[n-2];
    dp[n-3] = values[n-2] + values[n-3];
    for (int i = n-4;i >= 0;i--) {
        dp[i] = max (values[i] + min (dp[i+2],dp[i+3]), values[i] + values[i+1] + min (dp[i+3],dp[i+4]));
    }
    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += values[i];
    }
    if (dp[0] > sum - dp[0]) {
        return true;
    }
    return false;
}
