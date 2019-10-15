#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMissing(vector<int> &nums) {
    int n = nums.size();
    for (int i  = 0;i < n;) {
        if (nums[i] == i) {
            i++;
        }
        else {
            if (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i],nums[nums[i]]);
            }
            else {
                i++;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        if (nums[i] != i) {
            return i;
        }
    }
}

int main() {
    int a[3] = {1,2,3};
    vector<int> test(a,a+3);
    cout << findMissing(test) << endl;
    return 0;
}
