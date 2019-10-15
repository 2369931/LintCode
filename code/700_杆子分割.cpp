#include <iostream>
#include <vector>

using namespace std;

int cutting(vector<int> &prices, int n) {
    int m = prices.size();
    if (n <= 0 || m == 0) {
        return 0;
    }
    vector<int> record(n+1, 0);
    record[0] = 0;
    for (int i = 1;i <= n;i++) {
        int temp = INT_MIN;
        for (int j = 1; j <= i; j++) {
            temp = max(temp, prices[j-1] + record[i - j]);
        }
        record[i] = temp;
    }
    return record[n];
}

int main() {
    int a[8] = {3, 5, 8, 9, 10, 17, 17, 20};
    vector<int> test(a, a+8);
    cout << cutting(test, 8) << endl;
    return 0;
}
