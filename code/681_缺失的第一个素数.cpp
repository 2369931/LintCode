#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPrime(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    bool flag = false;
    if (n == 0 || nums[0] != 2) {
        return 2;
    }
    int max_number = nums[n-1];
    for (int i = 3;i <= max_number;i ++) {
        bool tag = false;
        for (int j = 0;j < n;j ++) {
            if (i%nums[j] == 0) {
                tag = true;
                break;
            }
        }
        if (!tag) {
            flag = true;
            return i;
            break;
        }
    }
    if (!flag) {
        int i = nums[n - 1];
        while (i < INT_MAX)
        {
            bool tag = false;
            for (int j = 0;j < n;j ++)
            {
                if (i%nums[j] == 0)
                {
                    tag = true;
                    break;
                }
            }
            if (!tag)
            {
                return i;
                break;
            }
            ++i;
        }
    }
}

int main() {
    int a[4] = {2, 3, 5, 7};
    vector<int> temp(a, a + 4);
    cout << firstMissingPrime(temp) << endl;
    return 0;
}
