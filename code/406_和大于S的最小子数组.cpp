#include <iostream>
#include <vector>

using namespace std;

int minimumSize(vector<int> &nums, int s) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    int p1 = 0;
    int p2 = 0;
    int min_len = INT_MAX;
    int sum = 0;
    int temp = 0;
    while (p2 < n) {
        sum +=  nums[p2];
        if (sum >= s) {
            temp = p2 - p1 + 1;
            if (temp < min_len) {
                min_len = temp;
            }
            while (sum >=s && p1 <= p2) {
                temp = p2 - p1 + 1;
                if (temp < min_len) {
                    min_len = temp;
                }
                sum -= nums[p1];
                p1++;
            }
        }
        p2++;
    }
    if (min_len == INT_MAX) {
        return -1;
    }
    else {
        return min_len;
    }
}
