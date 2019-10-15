#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int mountainSequence(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return nums[0];
    }
    for (int i = 0;i < n-1;i++) {
        if (nums[i] > nums[i+1]) {
            return nums[i];
        }
    }
    return nums[n-1];
}

int main() {
    int a[7] = {1,2,3,4,5,7,1};
    vector<int> test(a,a+7);
    cout << mountainSequence(test) << endl;
    return 0;
}
