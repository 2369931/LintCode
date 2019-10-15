#include <iostream>
#include <vector>

using namespace std;

int majorityNumber(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int value = nums[0];
    int number = 1;
    for (int i = 1;i < nums.size();i++) {
        if (nums[i] == value) {
            number ++;
        }
        else {
            number --;
            if (number < 0) {
                value = nums[i];
                number = 1;
            }
        }
    }
    if (number >= 0) {
        return value;
    }
}

int main() {
    int a[7] = {1,1,2,1,2,2,2};
    //int a[8] = {2,-1,3,-4,5,-8,6,-7};
    //int a[6] = {1,-1,2,1,3,1};
    vector<int> test(a,a+7);
    int result = majorityNumber(test);
    cout << result << endl;
    return 0;
}
