#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

void partitionArray(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return;
    for (int i = 0;i < n;i++) {
        if (nums[i]%2 == 0) {
            for (int j = i + 1;j < n;j++) {
                if (nums[j]%2 != 0) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
}

int main() {
    int a[6] = {1,2,3,4,5,5};
    vector<int> test(a, a+6);
    partitionArray(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << endl;
    }
    return 0;
}
