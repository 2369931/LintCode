#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findPosition(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    int s = 0;
    int e = n - 1;
    while (s < e) {
        int mid = (s + e)/2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            e = mid;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}
