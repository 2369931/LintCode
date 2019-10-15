#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxSubArray (vector<int> &nums) {
    int result = nums[0];
    int sum = nums[0];
    for (int i = 1;i < nums.size();i++) {
        if (sum < 0) {
            sum = 0;
        }
        sum += nums[i];
        if (sum > result) {
            result = sum;
        }
    }

    return result;
}

int maxTwoSubArrays(vector<int> &nums) {
    int n = nums.size();
    int left[n];
    int right[n];
    int sum = 0;
    int maxvalue = 0;
    left[0] = maxvalue = sum = nums[0];
    for (int i = 1;i < n;i++) {
        if (sum < 0) {
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
        if(sum > maxvalue) {
            maxvalue = sum;
        }
        left[i] = maxvalue;
    }
    right[0] = sum = maxvalue = nums[n-1];
    for (int i = n - 2;i >= 0;i--) {

        if (sum < 0) {
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
        if (sum > maxvalue) {
            maxvalue = sum;
        }
        right[n-i-1] = maxvalue;
    }
    int result = -999999;
    for (int i = 0;i < n-1;i++) {
        int sum = left[i] + right[n-i-2];
        if (sum > result) {
            result = sum;
        }
    }
    return result;
}

int main () {
    int a[6] = {-1, -2, -3, -100, 1,-50};
    vector<int> test(a,a+6);
    int result = maxSubArray(test);
    cout << endl;
    cout << result << endl;
    return 0;
}
