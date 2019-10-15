#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int maxProduct(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int max_value[n];
    int min_value[n];
    max_value[0] = nums[0];
    min_value[0] = nums[0];
    int result = INT_MIN;
    for (int i = 1;i < n;i++) {
        max_value[i] = max(max_value[i-1]*nums[i], max(min_value[i-1]*nums[i], nums[i]));
        min_value[i] = min(min_value[i-1]*nums[i], min(max_value[i-1]*nums[i], nums[i]));
        result = max(result,max_value[i]);
    }
    return result;
}

int main() {
    int a[3] = {-4,-3,-2};
    vector<int> test(a,a+3);
    cout << maxProduct(test) << endl;
    return 0;
}
