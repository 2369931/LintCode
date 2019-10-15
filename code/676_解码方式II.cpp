#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string &s) {
    int n = s.length();
    if (n < 1) {
        return 0;
    }
    vector<long> dp(n+1,0);
    dp[0] = 1;
    if (s[0] == '*') {
        dp[1] = 9;
    }
    else if (s[0] >= '1' && s[0] <= '9') {
        dp[1] = 1;
    }
    int first = 0;
    int second = 0;
    int base = 1000000007;
    for (int i = 2;i <= n;i++) {
        if (s[i-1] >= '0' && s[i-1] <= '9') {
            first = 1;
            second = 0;
            if (s[i-1] == '0') {
                first = 0;
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6')) {
                second = 1;
            }
            else if (s[i-2] == '*') {
                if (s[i-1] >= '0' && s[i-1] <= '6') {
                    second = 2;
                }
                else {
                    second = 1;
                }
            }
        }
        else {
            first = 9;
            second = 0;
            if (s[i-2] >= '0' && s[i-2] <= '9') {
                if (s[i-2] == '0') {
                    second = 0;
                }
                else if (s[i-2] == '1') {
                    second = 9;
                }
                else if (s[i-2] == '2') {
                    second = 6;
                }
            }
            else {
                second = 9 + 6;
            }
        }
        dp[i] = ((dp[i-1] * first) % base + (dp[i-2] * second) % base) % base;
    }
    return dp[n];
}
