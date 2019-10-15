#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }
    int min_r_l[n] = {INT_MAX};
    min_r_l[0] = nums[0];
    stack<int> max_s;
    for (int i = 1;i < n;i++) {
        if (nums[i] < min_r_l[i-1]) {
            min_r_l[i] = nums[i];
        }
        else {
            min_r_l[i] = min_r_l[i-1];
        }
    }
    for (int i = n-1;i >= 0;i--) {
        if (nums[i] > min_r_l[i]) {
            int max_value = INT_MIN;
            while (!max_s.empty()&&nums[i] > max_s.top()) {
                max_value = max_s.top();
                max_s.pop();
            }
            if (max_value > min_r_l[i]) {
                return true;
            }
        }
        max_s.push(nums[i]);
    }
    return false;
}

int main() {
    int a[4] = {3,1,4,2};
    vector<int> test(a,a+4);
    cout << find132pattern(test) << endl;
    return 0;
}
