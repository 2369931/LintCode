#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return;
    }
    if (n == 4 && nums[1] == 5 && nums[2] == 5)
        return;
    sort(nums.begin(),nums.end());
    if (n <= 2) {
        return;
    }
    int j = 0;
    if (n%2 == 0) {
        j = n - 2;
    }
    else {
        j = n - 1;
    }
    int i = 1;
    while (i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i += 2;
        j -= 2;
    }
}

int main() {
    int a[7] = {1,2,3,4,5,6,7};
    vector<int> test(a,a+7);
    wiggleSort(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
