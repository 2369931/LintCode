
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit(vector<int> &prices) {
    int result = 0;
    int n = prices.size();
    if (n == 0) return result;
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = 0;
    int min_left = prices[0];
    for (int i = 1;i < n;i++) {
        int temp = prices[i] - min_left;
        if (temp > left[i-1]) {
            left[i] = temp;
        }
        else {
            left[i] = left[i-1];
        }
        if (prices[i] < min_left) {
            min_left = prices[i];
        }
    }
    right[n-1] = 0;
    int max_right = prices[n-1];
    for (int i = n-2;i >= 0;i--) {
        int temp = max_right - prices[i];
        if (temp > right[i+1]) {
            right[i] = temp;
        }
        else {
            right[i] = right[i+1];
        }
        if (prices[i] > max_right) {
            max_right = prices[i];
        }
    }
    for (int i = 0;i < n;i ++) {
        int temp = left[i] + right[i];
        if (temp > result)
            result = temp;
    }
    return result;
}

int main() {
    int a[7] = {2,1,4,5,2,9,7};
    vector<int> test(a,a+7);
    cout << maxProfit(test) << endl;
    return 0;
}

