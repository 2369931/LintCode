#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMin_1(vector<int> &nums) {
    int result = INT_MAX;
    for (int i = 0;i < nums.size();i++) {
        if (result > nums[i]) {
            result = nums[i];
        }
    }
    return result;
}

int findMin(vector<int> &nums) {
    int result = 0;
    for (int i = 0;i < nums.size()-1;i++) {
        if (nums[i] > nums[i+1]) {
            result = i+1;
            break;
        }
    }
    return nums[result];
}

int main() {
    int a[8] = {4,4,5,6,7,8,1,2};
    vector<int> test(a,a+8);
    cout << findMin(test) << endl;
    return 0;
}

