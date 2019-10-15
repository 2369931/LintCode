#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxTwoSubArrays(vector<int> &nums) {
    int n = nums.size();
    int left[n];
    int right[n];
    int sum = 0;
    int maxvalue = 0;
    int minvalue = 0;
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

    right[0] = sum = minvalue = nums[n-1];
    for (int i = n - 2;i >= 0;i--) {

        if (sum > 0) {
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
        if (sum < minvalue) {
            minvalue = sum;
        }
        right[n-i-1] = minvalue;
    }
    int result = -999999;
    for (int i = 0;i < n-1;i++) {
        int sum = left[i] - right[n-i-2];
        if (sum > result) {
            result = sum;
        }
    }
    return result;
}

int maxDiffSubArrays(vector<int> &nums) {
    vector<int> reverse_nums;
    for (int i = nums.size()-1;i >= 0;i--) {
        reverse_nums.push_back(nums[i]);
    }
    return max(maxTwoSubArrays(nums),maxTwoSubArrays(reverse_nums));
}

int main () {
    int a[2] = {-5, -4};
    vector<int> test(a,a+2);
    int result = maxDiffSubArrays(test);
    cout << endl;
    cout << result << endl;
    return 0;
}

