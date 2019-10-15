#include <iostream>
#include <vector>

using namespace std;

bool judge(vector<int> nums, int len) {
    if (len == 1) {
        return true;
    }
    else if (nums[len-2] > nums[len-1]) {
        return false;
    }
    else {
        return judge(nums, len-1);
    }

}

int main() {
    int a[5] = {1,2,3,4,3};
    vector<int> test(a,a+5);
    cout << judge(test, test.size()) << endl;
    return 0;
}
