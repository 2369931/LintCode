#include <iostream>
#include <vector>

using namespace std;

void recoverRotatedSortedArray(vector<int> &nums) {
    int index = -1;
    int n = nums.size();
    for (int i = 0;i < n - 1;i++) {
        if (nums[i] > nums[i+1]) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return;
    for (int i = n - 1;i > index;i--) {
        int temp = nums[n-1];
        nums.insert(nums.begin(),temp);
        nums.erase(nums.begin() + n);
    }
}

int main() {
    int a[5] = {3,4,5,1,2};
    vector<int> nums(a,a+5);
    recoverRotatedSortedArray(nums);
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
