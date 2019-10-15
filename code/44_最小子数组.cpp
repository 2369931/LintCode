#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minSubArray (vector<int> &nums) {
    int result = nums[0];
    int sum = nums[0];
    for (int i = 1;i < nums.size();i++) {
        if (sum > 0) {
            sum = 0;
        }
        sum += nums[i];
        if (sum < result) {
            result = sum;
        }
    }

    return result;
}

int main () {
    int a[6] = {-1, -2, -3, -100, 1,-50};
    vector<int> test(a,a+6);
    int result = minSubArray(test);
    cout << result << endl;
    return 0;
}
