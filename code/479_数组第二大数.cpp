#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int secondMax(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    else if (n == 2) {
        return min(nums[0],nums[1]);
    }
    else {
        int f_max = INT_MIN;
        int s_max = INT_MIN;
        for (int i = 0;i < n;i ++) {
            if (nums[i] > f_max) {
                s_max = f_max;
                f_max = nums[i];
            }
            else if (nums[i] > s_max) {
                s_max = nums[i];
            }
        }
        return s_max;
    }
}

int main() {
    int b[4] = {4,3,2,1};
    vector<int> test(b,b+4);
    cout << secondMax(test) << endl;
    return 0;
}
