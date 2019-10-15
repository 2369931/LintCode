
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit(vector<int> &prices) {
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

int main() {
    int a[5] = {2,1,2,0,1};
    vector<int> test(a,a+5);
    cout << maxProfit(test) << endl;
    return 0;
}
