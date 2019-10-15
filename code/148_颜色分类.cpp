#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0) return;
    int index = 0;
    while (index < n) {
        int temp = nums[index];
        if (nums[index] < 0) {
            index ++;
        }
        else {
            if (nums[temp] < 0) {
                nums[temp] --;
                nums[index] = 0;
                index ++;
            }
            else {
                swap(nums[temp],nums[index]);
                nums[temp] = -1;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        cout << nums[i] << " ";
    }
    int i = n - 1;
    int k = 2;
    while (k >= 0) {
        for (int j = 0;j > nums[k];j--) {
            nums[i--] = k;
        }
        k --;
    }
}

int main() {
    int a[7] = {2,0,0,1,2,0,2};
    vector<int> test(a,a+7);
    sortColors(test);
    for (int i = 0;i < test.size();i++) {
        //cout << test[i] << " ";
    }
    return 0;
}
