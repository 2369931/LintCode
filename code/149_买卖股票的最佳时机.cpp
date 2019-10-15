#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit_simple(vector<int> &prices) {
    int result = 0;
    int n = prices.size();
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            if (prices[j] < prices[i]) continue;
            int temp = prices[j] - prices[i];
            if (temp > result) {
                result = temp;
            }
        }
    }
    return result;
}

int maxProfit(vector<int> &prices) {
    int result = 0;
    int n = prices.size();
    if (n == 0) return result;
    int min_i = prices[0];
    for (int i = 1;i < n;i++) {
        int temp = prices[i] - min_i;
        if (temp > result) {
            result = temp;
        }
        if (min_i > prices[i])
            min_i = prices[i];
    }
    return result;
}

int main() {
    int a[5] = {3,2,3,1,2};
    vector<int> test(a,a+5);
    cout << maxProfit(test) << endl;
    return 0;
}
