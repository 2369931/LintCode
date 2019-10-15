#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result(2,0);
    int n = nums.size();
    if (n == 0) {
        return result;
    }
    int s = 0;
    int e = n-1;
    while (s < e) {
        int sum = nums[s] + nums[e];
        if (sum == target) {
            result[0] = s+1;
            result[1] = e+1;
            break;
        }
        else {
            if (sum < target) {
                s ++;
            }
            else {
                e --;
            }
        }
    }
    return result;
}

int main() {
    int a[4] = {2,7,11,15};
    vector<int> test(a,a+4);
    vector<int> res = twoSum(test,9);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
