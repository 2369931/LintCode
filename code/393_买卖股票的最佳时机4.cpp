#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int simple_profit(vector<int> &prices) {
    int result = 0;
    int n = prices.size();
    if (n == 0) return result;
    for (int i = 1;i < n;i++) {
        int temp = prices[i] - prices[i-1];
        if (temp > 0) {
            result += temp;
        }
    }
    return result;
}

int maxProfit(int K, vector<int> &prices) {
    int n = prices.size();
    if (n == 0) return 0;
    if (K >= n/2) {
        return simple_profit(prices);
    }
    int local[n][K+1];
    int global[n][K+1];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= K;j++) {
            local[i][j] = 0;
            global[i][j] = 0;
        }
    }
    for (int i = 1;i < n;i++) {
        int diff = prices[i] - prices[i-1];
        for (int j = 1;j <= K;j++) {
            local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j] + diff);
            global[i][j] = max(global[i-1][j],local[i][j]);
        }
    }
    return global[n-1][K];
}

int main() {
    int a[7] = {2,1,4,5,2,9,7};
    vector<int> test(a,a+7);
    cout << maxProfit(2,test) << endl;
    return 0;
}


