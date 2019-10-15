#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;
///¶¯Ì¬¹æ»®
int jump(vector<int> &A) {
    int n = A.size();
    if (n == 0) return false;
    int dp[n];
    int number[n];
    for (int i = 0;i < n;i++) {
        dp[i] = 0;
        number[i] = INT_MAX;
    }
    dp[0] = 1;
    number[0] = 0;
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (dp[j] == 1 && A[j] >= i - j) {
                dp[i] = 1;
                if (number[i] > number[j] + 1)
                    number[i] = number[j] + 1;
            }
        }
    }
    return number[n-1];
}

int main() {
    int a[5] = {2,3,1,1,4};
    vector<int> test(a,a+5);
    cout << jump(test) << endl;
    return 0;
}
