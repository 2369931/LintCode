#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    int length = nums.size();
    if (length == 0) return length;
    int result = 1;
    int temp = nums[0];
    for (int i = 1;i < length;i++) {
        if (temp != nums[i]) {
            nums[result] = nums[i];
            result ++;
            temp = nums[i];
        }
    }
    return result;
}

int main() {
    int a[5] = {1,1,2,2,3};
    vector<int> test(a,a+5);
    cout << removeDuplicates(test) << endl;
    return 0;
}
