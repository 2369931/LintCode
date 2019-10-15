#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int,double> > dicesSum(int n) {
    double dp[n+1][6*n+1];
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= 6*n;j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1;i <=6;i++) {
        dp[1][i] = 1;
    }
    for (int i = 2;i <= n;i++) {
        for (int j = i;j <= 6*n;j++) {
            for (int k = 1;k <= 6;k++) {
                if (j-k > 0) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
    }
    vector<pair<int,double> > result;
    for (int i = n;i <= 6*n;i++) {
        pair<int,double> p(i,(double)dp[n][i]/pow(6,n));
        result.push_back(p);
    }
    return result;
}

int main() {
    int n = 2;
    vector<pair<int,double> > result = dicesSum(n);
    for (int i = n;i <= 6*n;i++) {
        cout << result[i].first << " : " << result[i].second << endl;
    }
    return 0;
}
